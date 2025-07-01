#include <iostream>
#include <stdexcept>  // Для std::invalid_argument

int divide(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero!");  // Генерация исключения
    }
    return a / b;
}

int main() {
    int x = 10;
    int y = 0;  // Умышленная ошибка

    try {
        std::cout << divide(x, y) << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;  // Возвращаем код ошибки
    }

    return 0;
}