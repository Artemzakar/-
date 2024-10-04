#include "Eleven.h"

// Вспомогательная функция для удаления ведущих нулей
void Eleven::trimLeadingZeros() {
    while (digits.size() > 1 && digits.back() == 0) {
        digits.pop_back();  // Удаляем последний элемент (ведущий ноль)
    }
}

// Конструктор по умолчанию
Eleven::Eleven() : digits(1, 0) {}

// Конструктор от строки
Eleven::Eleven(const std::string& numStr) {
    for (auto it = numStr.rbegin(); it != numStr.rend(); ++it) {
        if (*it >= '0' && *it <= '9') {
            digits.push_back(*it - '0');
        } else if (*it == 'A' || *it == 'a') {
            digits.push_back(10);  // Одиннадцатиричная цифра "A" как 10
        } else {
            throw std::invalid_argument("Недопустимый символ в строке");
        }
    }
    trimLeadingZeros();
}

// Конструктор от списка инициализации
Eleven::Eleven(const std::initializer_list<unsigned char>& list) : digits(list) {
    trimLeadingZeros();
}

// Конструктор копирования
Eleven::Eleven(const Eleven& other) : digits(other.digits) {}

// Конструктор перемещения
Eleven::Eleven(Eleven&& other) noexcept : digits(std::move(other.digits)) {}

// Копирующий оператор присваивания
Eleven& Eleven::operator=(const Eleven& other) {
    if (this != &other) {
        digits = other.digits;  
    }
    return *this;
}

// Перемещающий оператор присваивания
Eleven& Eleven::operator=(Eleven&& other) noexcept {
    if (this != &other) {
        digits = std::move(other.digits);  
    }
    return *this;
}

// Арифметическая операция сложения
Eleven Eleven::operator+(const Eleven& other) const {
    Eleven result;
    size_t maxSize = std::max(digits.size(), other.digits.size());
    result.digits.resize(maxSize, 0);

    unsigned char carry = 0;
    for (size_t i = 0; i < maxSize; ++i) {
        unsigned char digit1 = (i < digits.size()) ? digits[i] : 0;
        unsigned char digit2 = (i < other.digits.size()) ? other.digits[i] : 0;

        unsigned char sum = digit1 + digit2 + carry;
        carry = sum / 11;
        result.digits[i] = sum % 11;
    }

    if (carry) {
        result.digits.push_back(carry);
    }

    result.trimLeadingZeros();
    return result;
}

// Арифметическая операция вычитания
Eleven Eleven::operator-(const Eleven& other) const {
    if (*this < other) {
        throw std::underflow_error("Результат вычитания не может быть отрицательным");
    }

    Eleven result;
    result.digits.resize(digits.size(), 0);

    unsigned char borrow = 0;
    for (size_t i = 0; i < digits.size(); ++i) {
        unsigned char digit1 = digits[i];
        unsigned char digit2 = (i < other.digits.size()) ? other.digits[i] : 0;

        if (digit1 < digit2 + borrow) {
            result.digits[i] = digit1 + 11 - digit2 - borrow;
            borrow = 1;
        } else {
            result.digits[i] = digit1 - digit2 - borrow;
            borrow = 0;
        }
    }

    result.trimLeadingZeros();
    return result;
}

// Арифметические операции с присваиванием
Eleven& Eleven::operator+=(const Eleven& other) {
    *this = *this + other;
    return *this;
}

Eleven& Eleven::operator-=(const Eleven& other) {
    *this = *this - other;
    return *this;
}

// Операции сравнения
bool Eleven::operator==(const Eleven& other) const {
    return digits == other.digits;
}

bool Eleven::operator!=(const Eleven& other) const {
    return !(*this == other);
}

bool Eleven::operator<(const Eleven& other) const {
    if (digits.size() != other.digits.size()) {
        return digits.size() < other.digits.size();
    }
    for (int i = digits.size() - 1; i >= 0; --i) {
        if (digits[i] != other.digits[i]) {
            return digits[i] < other.digits[i];
        }
    }
    return false;
}

bool Eleven::operator>(const Eleven& other) const {
    return other < *this;
}

bool Eleven::operator<=(const Eleven& other) const {
    return !(other < *this);
}

bool Eleven::operator>=(const Eleven& other) const {
    return !(*this < other);
}

// Вывод в поток
std::ostream& operator<<(std::ostream& os, const Eleven& obj) {
    for (auto it = obj.digits.rbegin(); it != obj.digits.rend(); ++it) {
        if (*it < 10) {
            os << static_cast<int>(*it);
        } else {
            os << 'A';  // 10 отображаем как 'A'
        }
    }
    return os;
}

// Получение размера числа
size_t Eleven::size() const {
    return digits.size();
}