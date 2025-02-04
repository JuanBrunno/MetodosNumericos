// M�todo Das Aproxima��es Sucessivas para encontrar ra�zes de fun��es.
// Juan Brunno Gomes de Lima
// C�digo feito em c++

#include <iostream>
#include <cmath>

using namespace std;

// Fun��o g(x) derivada da equa��o f(x) = 0, tal que x = g(x)
double g(double x) {
    return cos(x); // Exemplo: g(x) = cos(x)
}

// Implementa��o do m�todo das aproxima��es sucessivas
void fixedPointIteration(double x0) {
    const double tolerance = 1e-6; // Toler�ncia para o erro
    const int maxIterations = 1000; // N�mero m�ximo de itera��es
    double x1;
    int iteration = 0;

    while (iteration < maxIterations) {
        x1 = g(x0);

        if (abs(x1 - x0) < tolerance) {
            cout << "A raiz da fun��o �: " << x1 << endl;
            return;
        }

        x0 = x1;
        iteration++;
    }

    cout << "O m�todo n�o convergiu ap�s " << maxIterations << " itera��es." << endl;
}

int main() {
    double x0 = 0.5; // Ponto inicial
    fixedPointIteration(x0);
    return 0;
}
