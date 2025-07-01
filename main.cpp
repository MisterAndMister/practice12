#include <iostream>

int divide(int a, int b) {
    return a / b;  // Ошибка: если b = 0, будет SIGFPE (деление на ноль)
}

int main() {
    int x = 10;
    int y = 0;  // Умышленная ошибка
    std::cout << divide(x, y) << std::endl;
    return 0;
}