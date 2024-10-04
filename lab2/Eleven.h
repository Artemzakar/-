#ifndef ELEVEN_H
#define ELEVEN_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <initializer_list>
#include <string>

class Eleven {
private:
    std::vector<unsigned char> digits;  // Вектор для хранения цифр
    void trimLeadingZeros();  // Удаление незначащих нулей

public:
    // Конструкторы
    Eleven();
    Eleven(const std::string& numStr);  // Конструктор от строки
    Eleven(const std::initializer_list<unsigned char>& list);  // Конструктор от списка
    Eleven(const Eleven& other);  // Конструктор копирования
    Eleven(Eleven&& other) noexcept;  // Конструктор перемещения
    ~Eleven() noexcept = default;

    // Операторы присваивания
    Eleven& operator=(const Eleven& other);  // Копирующий оператор присваивания
    Eleven& operator=(Eleven&& other) noexcept;  // Перемещающий оператор присваивания

    // Арифметические операции
    Eleven operator+(const Eleven& other) const;
    Eleven operator-(const Eleven& other) const;
    Eleven& operator+=(const Eleven& other);
    Eleven& operator-=(const Eleven& other);

    // Операции сравнения
    bool operator==(const Eleven& other) const;
    bool operator!=(const Eleven& other) const;
    bool operator<(const Eleven& other) const;
    bool operator>(const Eleven& other) const;
    bool operator<=(const Eleven& other) const;
    bool operator>=(const Eleven& other) const;

    // Вывод в поток
    friend std::ostream& operator<<(std::ostream& os, const Eleven& obj);

    // Прочие методы
    size_t size() const;
};

#endif 
