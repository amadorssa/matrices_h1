#include <iostream>

class Matriz {
private:
    unsigned int numRenglones;
    unsigned int numColumnas;
    int** elementos;

public:
    Matriz(unsigned int renglones = 1, unsigned int columnas = 1);
    ~Matriz();
    Matriz(const Matriz& otraMatriz);
    Matriz& operator=(const Matriz& otraMatriz);

    Matriz operator+(const Matriz& otraMatriz) const;
    Matriz operator-(const Matriz& otraMatriz) const;
    Matriz operator*(const Matriz& otraMatriz) const;
    Matriz operator*(int escalar) const;

    friend Matriz operator*(int escalar, const Matriz& matriz);

    friend std::ostream& operator<<(std::ostream& os, const Matriz& matriz);
    friend std::istream& operator>>(std::istream& is, Matriz& matriz);
};