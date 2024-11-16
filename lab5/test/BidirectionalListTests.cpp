#include <gtest/gtest.h>
#include "../include/BidirectionalList.h"
#include <string>
#include <memory_resource>

struct ComplexType {
    int id;
    std::string name;

    ComplexType(int i, const std::string& n) : id(i), name(n) {}

    bool operator==(const ComplexType& other) const {
        return id == other.id && name == other.name;
    }
};

class BidirectionalListTests : public ::testing::Test {
protected:
    std::pmr::monotonic_buffer_resource buffer;
    BidirectionalList<int> intList;
    BidirectionalList<ComplexType> complexList;

    BidirectionalListTests()
        : buffer(1024), intList(&buffer), complexList(&buffer) {}
};

// Тесты для пустого списка
TEST_F(BidirectionalListTests, EmptyList_SizeIsZero) {
    EXPECT_EQ(intList.get_size(), 0);
    EXPECT_EQ(intList.begin(), intList.end());
}

// Тесты на добавление элементов
TEST_F(BidirectionalListTests, PushBack_Integers) {
    intList.push_back(10);
    intList.push_back(20);
    intList.push_back(30);

    EXPECT_EQ(intList.get_size(), 3);

    auto it = intList.begin();
    EXPECT_EQ(*it, 10);
    ++it;
    EXPECT_EQ(*it, 20);
    ++it;
    EXPECT_EQ(*it, 30);
}

TEST_F(BidirectionalListTests, PushBack_ComplexType) {
    complexList.push_back(ComplexType(1, "Alice"));
    complexList.push_back(ComplexType(2, "Bob"));

    EXPECT_EQ(complexList.get_size(), 2);

    auto it = complexList.begin();
    EXPECT_EQ(*it, ComplexType(1, "Alice"));
    ++it;
    EXPECT_EQ(*it, ComplexType(2, "Bob"));
}

// Тесты на очистку
TEST_F(BidirectionalListTests, Clear_ListIsEmptyAfterClear) {
    intList.push_back(10);
    intList.push_back(20);
    intList.clear();

    EXPECT_EQ(intList.get_size(), 0);
    EXPECT_EQ(intList.begin(), intList.end());
}

// Тесты итератора
TEST_F(BidirectionalListTests, Iterator_Traversal) {
    intList.push_back(1);
    intList.push_back(2);
    intList.push_back(3);

    std::vector<int> result;
    for (auto it = intList.begin(); it != intList.end(); ++it) {
        result.push_back(*it);
    }

    EXPECT_EQ(result, std::vector<int>({1, 2, 3}));
}

TEST_F(BidirectionalListTests, Iterator_EmptyList) {
    auto it = intList.begin();
    EXPECT_EQ(it, intList.end());
}

// Тесты на совместимость со стандартными алгоритмами
TEST_F(BidirectionalListTests, StdAlgorithms_Find) {
    intList.push_back(5);
    intList.push_back(10);
    intList.push_back(15);

    auto it = std::find(intList.begin(), intList.end(), 10);
    EXPECT_NE(it, intList.end());
    EXPECT_EQ(*it, 10);

    it = std::find(intList.begin(), intList.end(), 100);
    EXPECT_EQ(it, intList.end());
}

// Тесты работы с полиморфным аллокатором
TEST_F(BidirectionalListTests, PolymorphicAllocator_ReuseMemory) {
    std::pmr::monotonic_buffer_resource localBuffer(512);
    BidirectionalList<int> localList(&localBuffer);

    localList.push_back(42);
    localList.push_back(24);

    EXPECT_EQ(localList.get_size(), 2);

    auto it = localList.begin();
    EXPECT_EQ(*it, 42);
    ++it;
    EXPECT_EQ(*it, 24);
}

// Тесты на пользовательские типы
TEST_F(BidirectionalListTests, CustomType_Equality) {
    complexList.push_back(ComplexType(1, "First"));
    complexList.push_back(ComplexType(2, "Second"));

    auto it = complexList.begin();
    EXPECT_EQ(*it, ComplexType(1, "First"));
    ++it;
    EXPECT_EQ(*it, ComplexType(2, "Second"));
}

// Тесты на производительность
TEST_F(BidirectionalListTests, StressTest_ManyElements) {
    const int numElements = 100000;
    for (int i = 0; i < numElements; ++i) {
        intList.push_back(i);
    }

    EXPECT_EQ(intList.get_size(), numElements);

    int counter = 0;
    for (auto it = intList.begin(); it != intList.end(); ++it) {
        EXPECT_EQ(*it, counter++);
    }
}
