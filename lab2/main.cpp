#include <iostream>
#include "include/Eleven.h"

int main() {
    try {
        Eleven num1("A12"); // 10*11^2 + 1*11^1 + 2 = 1234 в десятичной системе
        Eleven num2("B9");  // 11*11^1 + 9*11^0 = 128 в десятичной системе

        std::cout << "Первое число: " << num1 << std::endl;
        std::cout << "Второе число: " << num2 << std::endl;

        Eleven sum = num1 + num2;
        Eleven diff = num1 - num2;

        std::cout << "Сумма: " << sum << std::endl; 
        std::cout << "Разность: " << diff << std::endl; 

        if (num1 > num2) {
            std::cout << num1 << " больше, чем " << num2 << std::endl;
        } else {
            std::cout << num1 << " не больше, чем " << num2 << std::endl;
        }
        
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl; // Обработка ошибок
    }

    return 0;
}