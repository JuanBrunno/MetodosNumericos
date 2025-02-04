// M�todo Das Steffensen para encontrar ra�zes de fun��es.
// Juan Brunno Gomes de Lima
// C�digo feito em c++

#include <iostream>
#include <cmath>

using namespace std;

// Fun��o para a qual queremos encontrar a raiz
double func(double x) {
    return x * x * x - x * x + 2;
}

// Implementa��o do m�todo de Steffensen
void steffensen(double x0) {
    const double tolerance = 1e-6; // Toler�ncia para o erro
    const int maxIterations = 1000; // N�mero m�ximo de itera��es
    double x1, x2;
    int iteration = 0;

    while (iteration < maxIterations) {
        double fx0 = func(x0);
        double fx1 = func(x0 + fx0);
        double fx2 = func(x0 + 2 * fx0);

        // Calcula a pr�xima aproxima��o usando a f�rmula de Steffensen
        x1 = x0 - (fx0 * fx0) / (fx2 - 2 * fx1 + fx0);

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
    double x0 = -20; // Ponto inicial
    steffensen(x0);
    return 0;
}
