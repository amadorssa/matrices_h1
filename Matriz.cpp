#include "Matriz.hpp"

Matrix::Matrix(unsigned int rows, unsigned int columns): numRows(rows), numColumns(columns) { // Constructor con dimensiones especificadas
    
    try {
        matriz = new int*[numRows];
        for (unsigned int i = 0; i < numRows; ++i) {
            matriz[i] = new int[numColumns];
        }
    }
    catch(const std::bad_alloc& ) {
        std::cerr << "No es posible construir la matriz" << '\n';
    }
}


Matrix::Matrix(const Matrix& A) : matriz(nullptr), numRows(0), numColumns(0) { // Constructor de copias
    *this = A;
}


Matrix::~Matrix() { // Destructor
    if(matriz == nullptr) return;
    for (unsigned int i = 0; i < numRows; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;
}


unsigned int Matrix::getNumRows() const { // Método para obtener el número de renglones
    return numRows;
}


unsigned int Matrix::getNumColumns() const { // Método para obtener el número de columnas
    return numColumns;
}


void Matrix::printMatrix() const { // Método para imprimir una matriz
    for (unsigned int i = 0; i < numRows; ++i) {
        for (unsigned int j = 0; j < numColumns; ++j) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


Matrix& Matrix::operator=(const Matrix& A) { // Operador de asignación
    if (this != &A) { // Evitar autoasignación
        
        try {
            for (unsigned int i = 0; i < numRows; ++i) { // Liberar la memoria
                delete[] matriz[i];
            }
            delete[] matriz;

            // Copiar las dimensiones de la matriz
            numRows = A.numRows;
            numColumns = A.numColumns;

            // Asignar nueva memoria
            matriz = new int*[numRows];
            for (unsigned int i = 0; i < numRows; ++i) {
                matriz[i] = new int[numColumns];
                for (unsigned int j = 0; j < numColumns; ++j) {
                    matriz[i][j] = A.matriz[i][j];
                }
            }    
        } catch(const std::bad_alloc&) {
            throw std::string("No es posible asignar la matriz");
        }
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix& A) const { // Operador de suma
    if (numRows != A.numRows || numColumns != A.numColumns) {
        throw std::string("Dimensiones incompatibles");
    }

    Matrix resultSum(numRows, numColumns);
    for (unsigned int i = 0; i < numRows; ++i) {
        for (unsigned int j = 0; j < numColumns; ++j) {
            resultSum.matriz[i][j] = matriz[i][j] + A.matriz[i][j];
        }
    }
    return resultSum;
}


Matrix Matrix::operator-(const Matrix& A) const { // Operador de resta
    if (numRows != A.numRows || numColumns != A.numColumns) {
        throw std::string("Dimensiones incompatibles");
    }

    Matrix resultSub(numRows, numColumns);
    for (unsigned int i = 0; i < numRows; ++i) {
        for (unsigned int j = 0; j < numColumns; ++j) {
            resultSub.matriz[i][j] = matriz[i][j] - A.matriz[i][j];
        }
    }
    return resultSub;
}


Matrix Matrix::operator*(const Matrix& A) const { // Operador producto de matrices
    if (numColumns != A.numRows) {
        throw std::string("Dimensiones incompatibles");
    }

    Matrix resultProduct(numRows, A.numColumns);
    for (unsigned int i = 0; i < numRows; ++i) {
        for (unsigned int j = 0; j < A.numColumns; ++j) {
            resultProduct.matriz[i][j] = 0;
            for (unsigned int k = 0; k < numColumns; ++k) {
                resultProduct.matriz[i][j] += matriz[i][k] * A.matriz[k][j];
            }
        }
    }
    return resultProduct;
}


Matrix Matrix::operator*(int scalar) const { // Operador de multiplicación por un escalar
    Matrix resultScalar(numRows, numColumns);
    for (unsigned int i = 0; i < numRows; ++i) {
        for (unsigned int j = 0; j < numColumns; ++j) {
            resultScalar.matriz[i][j] = matriz[i][j] * scalar;
        }
    }
    return resultScalar;
}


Matrix Matrix::transpose() const { // Metodo para obtener la transpuesta
    Matrix resultTranspose(numColumns, numRows);
    for (unsigned int i = 0; i < numRows; ++i) {
        for (unsigned int j = 0; j < numColumns; ++j) {
            resultTranspose.matriz[j][i] = matriz[i][j];
        }
    }
    return resultTranspose;
}


void Matrix::resize(unsigned int rows, unsigned int columns) { // Redimensionar la matriz

    for (unsigned int i = 0; i < numRows; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;

    numRows = rows;
    numColumns = columns;

    matriz = new int*[numRows];
    for (unsigned int i = 0; i < numRows; ++i) {
        matriz[i] = new int[numColumns];
    }
}


std::ostream& operator<<(std::ostream& out, const Matrix& A) { // Operador de flujo de salida
    for (unsigned int i = 0; i < A.numRows; ++i) {
        for (unsigned int j = 0; j < A.numColumns; ++j) {
            out << A.matriz[i][j] << " ";
        }
        out << std::endl;
    }
    return out;
}


std::istream& operator>>(std::istream& in, Matrix& A) { // Operador de flujo de entrada
    for (unsigned int i = 0; i < A.numRows; ++i) {
        for (unsigned int j = 0; j < A.numColumns; ++j) {
            in >> A.matriz[i][j];
        }
    }
    return in;
}


Matrix operator*(int scalar, const Matrix& mat) { // Operador de multiplicación por un escalar
    return mat * scalar;
}


Matrix Matrix::inverse() const { // Método para obtener la inversa
    if (numRows != numColumns) {
        throw std::string("La matriz no es cuadrada");
    }

    double det = 0;
    Matrix adj(numRows, numColumns);
    for (unsigned int i = 0; i < numRows; ++i) {
        for (unsigned int j = 0; j < numColumns; ++j) {
            
            int sign = ((i + j) % 2 == 0) ? 1 : -1; // Signo del cofactor

            
            Matrix subMatrix(numRows - 1, numColumns - 1);
            for (unsigned int k = 0, row = 0; k < numRows; ++k) { 
                if (k != i) {
                    for (unsigned int l = 0, col = 0; l < numColumns; ++l) {
                        if (l != j) {
                            subMatrix.matriz[row][col] = matriz[k][l];
                            ++col;
                        }
                    }
                    ++row;
                }
            }
            double subDet = subMatrix.determinant();

            adj.matriz[j][i] = sign * subDet; // Calcular el cofactor

            // Acumular el determinante
            if (i == 0) {
                det += matriz[0][j] * adj.matriz[j][i];
            }
        }
    }

    if (det == 0) {
        throw std::string("La matriz no tiene inversa");
    }

    // Calcular la matriz inversa
    adj = adj.transpose();
    adj = adj * (1 / det);
    return adj;
}

/***************************************************************************/

double Matrix::determinant() const { // Método para obtener el determinante
    if (numRows != numColumns) {
        throw std::string("La matriz no es cuadrada");
    }

    if (numRows == 1) {
        return matriz[0][0];
    }

    if (numRows == 2) {
        return matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
    }

    double det = 0;
    for (unsigned int i = 0; i < numRows; ++i) {
        Matrix subMatrix(numRows - 1, numColumns - 1);
        for (unsigned int j = 1; j < numRows; ++j) {
            for (unsigned int k = 0; k < numColumns; ++k) {
                if (k < i) {
                    subMatrix.matriz[j - 1][k] = matriz[j][k];
                } else if (k > i) {
                    subMatrix.matriz[j - 1][k - 1] = matriz[j][k];
                }
            }
        }
        det += matriz[0][i] * (i % 2 == 0 ? 1 : -1) * subMatrix.determinant();
    }
    return det;
}



