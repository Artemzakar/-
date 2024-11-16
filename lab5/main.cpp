#include <iostream>
#include "include/MemoryResource.h"
#include "include/BidirectionalList.h"

struct ComplexType {
    int id;
    std::string name;

    ComplexType(int i, std::string n) : id(i), name(std::move(n)) {}
};

int main() {
    FixedBlockMemoryResource memoryResource(1024);

    std::pmr::polymorphic_allocator<int> intAllocator(&memoryResource);
    BidirectionalList<int> intList(&memoryResource);

    intList.push_back(1);
    intList.push_back(2);
    intList.push_back(3);

    for (int value : intList) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    BidirectionalList<ComplexType> complexList(&memoryResource);
    complexList.push_back({1, "First"});
    complexList.push_back({2, "Second"});

    for (const auto& item : complexList) {
        std::cout << item.id << ": " << item.name << std::endl;
    }

    return 0;
}
