#include "Matriz.hpp"

Matriz::Matriz(unsigned int renglones, unsigned int columnas)
    : numRenglones(renglones), numColumnas(columnas) {
    if (renglones <= 0 || columnas <= 0) {
        throw std::invalid_argument("Las dimensiones de la matriz deben ser números positivos.");
    }

    elementos = new int*[numRenglones];
    for (unsigned int i = 0; i < numRenglones; ++i) {
        elementos[i] = new int[numColumnas];
    }
}

Matriz::~Matriz() {
    for (unsigned int i = 0; i < numRenglones; ++i) {
        delete[] elementos[i];
    }
    delete[] elementos;
}

Matriz::Matriz(const Matriz& otraMatriz)
    : numRenglones(otraMatriz.numRenglones), numColumnas(otraMatriz.numColumnas) {
    elementos = new int*[numRenglones];
    for (unsigned int i = 0; i < numRenglones; ++i) {
        elementos[i] = new int[numColumnas];
        for (unsigned int j = 0; j < numColumnas; ++j) {
            elementos[i][j] = otraMatriz.elementos[i][j];
        }
    }
}

Matriz& Matriz::operator=(const Matriz& otraMatriz) {
    if (this != &otraMatriz) {
        for (unsigned int i = 0; i < numRenglones; ++i) {
            delete[] elementos[i];
        }
        delete[] elementos;

        numRenglones = otraMatriz.numRenglones;
        numColumnas = otraMatriz.numColumnas;

        elementos = new int*[numRenglones];
        for (unsigned int i = 0; i < numRenglones; ++i) {
            elementos[i] = new int[numColumnas];
            for (unsigned int j = 0; j < numColumnas; ++j) {
                elementos[i][j] = otraMatriz.elementos[i][j];
            }
        }
    }
    return *this;
}

Matriz Matriz::operator+(const Matriz& otraMatriz) const {
    if (numRenglones != otraMatriz.numRenglones || numColumnas != otraMatriz.numColumnas) {
        throw std::invalid_argument("Las matrices deben tener las mismas dimensiones para la suma.");
    }

    Matriz resultado(numRenglones, numColumnas);
    for (unsigned int i = 0; i < numRenglones; ++i) {
        for (unsigned int j = 0; j < numColumnas; ++j) {
            resultado.elementos[i][j] = elementos[i][j] + otraMatriz.elementos[i][j];
        }
    }
    return resultado;
}

Matriz Matriz::operator-(const Matriz& otraMatriz) const {
    if (numRenglones != otraMatriz.numRenglones || numColumnas != otraMatriz.numColumnas) {
        throw std::invalid_argument("Las matrices deben tener las mismas dimensiones para la resta.");
    }

    Matriz resultado(numRenglones, numColumnas);
    for (unsigned int i = 0; i < numRenglones; ++i) {
        for (unsigned int j = 0; j < numColumnas; ++j) {
            resultado.elementos[i][j] = elementos[i][j] - otraMatriz.elementos[i][j];
        }
    }
    return resultado;
}

Matriz Matriz::operator*(const Matriz& otraMatriz) const {
    if (numColumnas != otraMatriz.numRenglones) {
        throw std::invalid_argument("El número de columnas de la primera matriz debe ser igual al número de renglones de la segunda matriz para la multiplicación.");
    }

    Matriz resultado(numRenglones, otraMatriz.numColumnas);
    for (unsigned int i = 0; i < numRenglones; ++i) {
        for (unsigned int j = 0; j < otraMatriz.numColumnas; ++j) {
            resultado.elementos[i][j] = 0;
            for (unsigned int k = 0; k < numColumnas; ++k) {
                resultado.elementos[i][j] += elementos[i][k] * otraMatriz.elementos[k][j];
            }
        }
    }
    return resultado;
}

Matriz Matriz::operator*(int escalar) const {
    Matriz resultado(numRenglones, numColumnas);
    for (unsigned int i = 0; i < numRenglones; ++i) {
        for (unsigned int j = 0; j < numColumnas; ++j) {
            resultado.elementos[i][j] = elementos[i][j] * escalar;
        }
    }
    return resultado;
}

Matriz operator*(int escalar, const Matriz& matriz) {
    return matriz * escalar;
}

std::ostream& operator<<(std::ostream& os, const Matriz& matriz) {
    for (unsigned int i = 0; i < matriz.numRenglones; ++i) {
        for (unsigned int j = 0; j < matriz.numColumnas; ++j) {
            os << matriz.elementos[i][j] << ' ';
        }
        os << '\n';
    }
    return os;
}

std::istream& operator>>(std::istream& is, Matriz& matriz) {
    for (unsigned int i = 0; i < matriz.numRenglones; ++i) {
        for (unsigned int j = 0; j < matriz.numColumnas; ++j) {
            is >> matriz.elementos[i][j];
        }
    }
    return is;
}
