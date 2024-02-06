/**
 * \file Matriz.hpp
 * \brief Implementaci&oacute;n de una matriz con memoria dinamica.
 * \author Amado Rosas Archiveque & Orlando
 * \date 2013-02-06
*/

#ifndef MATRIZ_HPP_INCLUDED
#define MATRIZ_HPP_INCLUDED

#include <iostream>

class Matrix {

    friend std::ostream& operator<<(std::ostream& out, const Matrix& A); // Operador de flujo de salida    
    friend std::istream& operator>>(std::istream& in, Matrix& A); // Operador de flujo de entrada
    friend Matrix operator*(int scalar, const Matrix& mat); // Operador de multiplicación por un escalar

public:
    
    explicit Matrix(unsigned int rows = 1, unsigned int columns = 1); // Constructor de la clase Matriz
    ~Matrix(); // Destructor para liberar la memoria
    Matrix(const Matrix& A); // Constructor de copias
    unsigned int getNumRows() const; // Obtener el numero de renglones
    unsigned int getNumColumns() const; // Obtener el numero de columnas
    void printMatrix() const; // Método para imprimir la matriz
    Matrix& operator=(const Matrix& A); // Operador de asignación
    Matrix operator+(const Matrix& A) const; // Operador de suma
    Matrix operator-(const Matrix& A) const; // Operador de resta
    Matrix operator*(const Matrix& A) const; // Operador producto de matrices
    Matrix operator*(int scalar) const; // Operador de multiplicación por un escalar
    Matrix transpose() const; // Transpuesta de la matriz
    void resize(unsigned int rows, unsigned int columns); // Redimensionar la matriz

private:
    unsigned int numRows;
    unsigned int numColumns;
    int** matriz;
};

#endif // MATRIZ_HPP