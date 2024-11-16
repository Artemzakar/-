#ifndef MEMORYRESOURCE_H
#define MEMORYRESOURCE_H

#include <memory_resource>
#include <map>
#include <cstddef>
#include <stdexcept>

class FixedBlockMemoryResource : public std::pmr::memory_resource {
private:
    void* memoryBlock;
    size_t blockSize;
    size_t offset;
    std::map<void*, size_t> allocatedBlocks;

    bool is_within_block(void* p) const {
        return p >= memoryBlock && p < static_cast<char*>(memoryBlock) + blockSize;
    }

protected:
    void* do_allocate(size_t bytes, size_t alignment) override {
        size_t alignedOffset = (offset + alignment - 1) & ~(alignment - 1);
        if (alignedOffset + bytes > blockSize)
            throw std::bad_alloc();
        void* ptr = static_cast<char*>(memoryBlock) + alignedOffset;
        allocatedBlocks[ptr] = bytes;
        offset = alignedOffset + bytes;
        return ptr;
    }

    void do_deallocate(void* p, size_t bytes, size_t alignment) override {
        if (is_within_block(p)) {
            allocatedBlocks.erase(p);
        }
    }

    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override {
        return this == &other;
    }

public:
    FixedBlockMemoryResource(size_t size)
        : memoryBlock(::operator new(size)), blockSize(size), offset(0) {}

    ~FixedBlockMemoryResource() override {
        ::operator delete(memoryBlock);
    }
};

#endif // MEMORYRESOURCE_H
