#include "Matriz.hpp"

int main() {
    // Ejemplo de uso de la clase Matriz
    Matrix matriz1; // Matriz por defecto de 1x1
    matriz1.printMatrix();

    Matrix matriz2(3, 4); // Matriz de 3x4
    matriz2.printMatrix();

    std::cout << "Número de renglones de matriz2: " << matriz2.getNumRenglones() << std::endl;
    std::cout << "Número de columnas de matriz2: " << matriz2.getNumColumnas() << std::endl;

    return 0;
}
