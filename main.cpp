#include "Matriz.hpp"

using namespace std;

int main() {
    try {
        Matriz A(2, 3);
        Matriz B(3, 2);

        std::cout << "Ingrese la matriz A (2x3):\n";
        std::cin >> A;

        std::cout << "Ingrese la matriz B (3x2):\n";
        std::cin >> B;

        Matriz C = A + B;
        Matriz D = A - B;
        Matriz E = A * B;
        Matriz F = A * 2;

        std::cout << "Matriz A + B:\n" << C << '\n';
        std::cout << "Matriz A - B:\n" << D << '\n';
        std::cout << "Matriz A * B:\n" << E << '\n';
        std::cout << "Matriz A * 2:\n" << F << '\n';

        // Operador no miembro para el producto por escalar conmutativo
        Matriz G = 2 * A;
        std::cout << "2 * Matriz A:\n" << G << '\n';
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    return 0;
}