#include <iostream>
#include <fstream>
#include <stdexcept>

int divide(int a, int b) {
    if (b == 0) {
        throw std::runtime_error("Division by zero!");
    }
    return a / b;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>\n";
        return 1;
    }

    std::ifstream input(argv[1]);
    if (!input) {
        std::cerr << "Error: Cannot open file " << argv[1] << "\n";
        return 1;
    }

    int a, b;
    while (input >> a >> b) {
        try {
            std::cout << a << " / " << b << " = " << divide(a, b) << "\n";
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }

    return 0;
}