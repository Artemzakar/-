#ifndef FIGUREARRAY_H
#define FIGUREARRAY_H

#include <iostream>
#include <memory>

template<typename T>
class FigureArray {
private:
    std::shared_ptr<T[]> array;
    size_t currentSize;
    size_t currentCapacity;

    void resize(size_t newCapacity) {
        if (newCapacity <= currentCapacity) return;

        std::shared_ptr<T[]> newArray(new T[newCapacity]);
        for (size_t i = 0; i < currentSize; ++i) {
            newArray[i] = std::move(array[i]);
        }
        array = std::move(newArray);
        currentCapacity = newCapacity;
    }

public:
    explicit FigureArray(size_t capacity)
        : currentSize(0), currentCapacity(capacity), array(std::shared_ptr<T[]>(new T[capacity])) {}

    void append(T element) {
        if (currentSize >= currentCapacity) resize(currentCapacity * 2);
        array[currentSize++] = std::move(element);
    }

    void set(size_t index, T element) {
        if (index >= currentSize) throw std::out_of_range("Index out of range");
        array[index] = std::move(element);
    }

    T get(size_t index) const {
        if (index >= currentSize) throw std::out_of_range("Index out of range");
        return array[index];
    }

    int size() const {
        return currentSize;
    }

    void printCoordinates(std::ostream& os) const {
        for (size_t i = 0; i < currentSize; ++i) {
            if constexpr (std::is_pointer_v<T>) {
                if (array[i]) array[i]->print(os);
            } else {
                array[i].print(os);
            }
            os << "\n";
        }
    }

    double getTotalArea() const {
        double totalArea = 0.0;
        for (size_t i = 0; i < currentSize; ++i) {
            if constexpr (std::is_pointer_v<T>) {
                if (array[i]) totalArea += static_cast<double>(*(array[i]));
            } else {
                totalArea += static_cast<double>(array[i]);
            }
        }
        return totalArea;
    }

    void remove(int index) {
        if (index < 0 || index >= currentSize) {
            throw std::out_of_range("Index out of range");
        }

        if constexpr (std::is_pointer<T>::value) {
            delete array[index];
            array[index] = nullptr;
        } else {
            array[index] = T();
        }

        for (int i = index; i < currentSize - 1; ++i) {
            array[i] = std::move(array[i + 1]);
        }

        --currentSize;
    }

    ~FigureArray() = default;
};

#endif
