#ifndef BIDIRECTIONALLIST_H
#define BIDIRECTIONALLIST_H

#include <memory_resource>
#include <iterator>

template<typename T>
class BidirectionalList {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;

        Node(const T& value, Node* n = nullptr, Node* p = nullptr)
            : data(value), next(n), prev(p) {}
    };

    using Allocator = std::pmr::polymorphic_allocator<Node>;
    Allocator allocator;
    Node* head;
    Node* tail;
    size_t size;

public:
    class Iterator {
    private:
        Node* current;

    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        Iterator(Node* node) : current(node) {}

        T& operator*() const { return current->data; }
        T* operator->() const { return &current->data; }
        Iterator& operator++() {
            current = current->next;
            return *this;
        }
        Iterator operator++(int) {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }
        bool operator==(const Iterator& other) const { return current == other.current; }
        bool operator!=(const Iterator& other) const { return !(*this == other); }
    };

    BidirectionalList(std::pmr::memory_resource* resource = std::pmr::get_default_resource())
        : allocator(resource), head(nullptr), tail(nullptr), size(0) {}

    ~BidirectionalList() { clear(); }

    void push_back(const T& value) {
        Node* newNode = allocator.allocate(1);
        allocator.construct(newNode, value, nullptr, tail);
        if (tail)
            tail->next = newNode;
        tail = newNode;
        if (!head)
            head = newNode;
        ++size;
    }

    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            allocator.destroy(temp);
            allocator.deallocate(temp, 1);
        }
        tail = nullptr;
        size = 0;
    }

    size_t get_size() const { return size; }
    Iterator begin() const { return Iterator(head); }
    Iterator end() const { return Iterator(nullptr); }
};

#endif // BIDIRECTIONALLIST_H
