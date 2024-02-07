/**
 * \file Matriz.hpp
 * \brief Implementaci&oacute;n de una matriz con memoria dinamica.
 * \author Amado Rosas Archiveque & Orlando Lopez Roque
 * \date 2024-02-06
*/

#ifndef MATRIZ_HPP_INCLUDED
#define MATRIZ_HPP_INCLUDED

#include <iostream>

class Matrix {

    /**
     * \brief Operador de inserci&oacute;n de flujo.
     * \param out Flujo de salida.
     * \param A Matriz que se imprimir&aacute; en el flujo de salida.
     * \return Flujo de salida.
    */
    friend std::ostream& operator<<(std::ostream& out, const Matrix& A); // Operador de flujo de salida  

    /**
     * \brief Operador de extracci&oacute;n de flujo.
     * \param in Flujo de entrada.
     * \param A Matriz que se leer&aacute; del flujo de entrada.
     * \return Flujo de entrada.
    */
    friend std::istream& operator>>(std::istream& in, Matrix& A); // Operador de flujo de entrada
    
    /**
     * \brief Operador de multiplicaci&oacute;n de escalar por matriz.
     * \param scalar Escalar por el que se multiplicar&aacute; la matriz.
     * \param mat Matriz que se multiplicar&aacute; por el escalar.
     * \return Matriz resultante de la multiplicaci&oacute;n.
    */
    friend Matrix operator*(int scalar, const Matrix& mat); // Operador de multiplicación por un escalar

public:
    
    /**
     * \brief Constructor de la clase Matriz.
     * \param rows N&uacute;mero de renglones.
     * \param columns N&uacute;mero de columnas.
    */
    explicit Matrix(unsigned int rows = 1, unsigned int columns = 1); // Constructor de la clase Matriz
    
    /**
     * \brief Destructor de la clase Matriz.
    */
    ~Matrix(); // Destructor para liberar la memoria
    
    /**
     * \brief Constructor de copias.
     * \param A Matriz a copiar.
    */
    Matrix(const Matrix& A); // Constructor de copias
    
    /**
     * \brief Obtener el numero de renglones.
     * \return N&uacute;mero de renglones.
    */
    unsigned int getNumRows() const; // Obtener el numero de renglones
    
    /**
     * \brief Obtener el numero de columnas.
     * \return N&uacute;mero de columnas.
    */
    unsigned int getNumColumns() const; // Obtener el numero de columnas
    
    /**
     * \brief Impresi&oacute;n de la matriz.
     * \return void
    */
    void printMatrix() const; // Método para imprimir la matriz
    
    /**
     * \brief Operador de asignaci&oacute;n.
     * \param A Matriz a asignar.
     * \return Matriz resultante de la asignaci&oacute;n.
    */
    Matrix& operator=(const Matrix& A); // Operador de asignación
    
    /**
     * \brief Operador de suma.
     * \param A Matriz a sumar.
     * \return Matriz resultante de la suma.
    */
    Matrix operator+(const Matrix& A) const; // Operador de suma
    
    /**
     * \brief Operador de resta.
     * \param A Matriz a restar.
     * \return Matriz resultante de la resta.
    */
    Matrix operator-(const Matrix& A) const; // Operador de resta
    
    /**
     * \brief Operador producto de matrices.
     * \param A Matriz a multiplicar.
     * \return Matriz resultante del producto.
    */
    Matrix operator*(const Matrix& A) const; // Operador producto de matrices
    
    /**
     * \brief Operador de multiplicaci&oacute;n por un escalar.
     * \param scalar Escalar por el que se multiplicar&aacute; la matriz.
     * \return Matriz resultante de la multiplicaci&oacute;n.
    */
    Matrix operator*(int scalar) const; // Operador de multiplicación por un escalar
    
    /**
     * \brief Transpuesta de la matriz.
     * \return Matriz transpuesta.
    */
    Matrix transpose() const; // Transpuesta de la matriz
    
    /**
     * \brief Redimensionar la matriz.
     * \param rows N&uacute;mero de renglones.
     * \param columns N&uacute;mero de columnas.
     * \return void
    */
    void resize(unsigned int rows, unsigned int columns); // Redimensionar la matriz

    /**
     * \brief Obtener la inversa de la matriz.
     * \return Matriz inversa.
    */
    Matrix inverse() const; // Método para obtener la inversa de la matriz
private:
    
    /**
     * \brief N&uacute;mero de renglones.
    */
    unsigned int numRows;
    
    /**
     * \brief N&uacute;mero de columnas.
    */
    unsigned int numColumns;
    
    /**
     * \brief Puntero a la matriz.
    */
    int** matriz;

    /**
     * \brief Obtener el determinante de la matriz.
     * \return Determinante de la matriz.
    */
    double determinant() const; // Método para obtener el determinante de la matriz

};

#endif // MATRIZ_HPP