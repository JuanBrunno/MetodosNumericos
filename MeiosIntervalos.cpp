#include <iostream>
#include <cmath>

using namespace std;

// Fun��o para a qual queremos encontrar a raiz
double func(double x) {
    return x * x * x - x * x + 2;
}

// Implementa��o do m�todo dos meios intervalos
void bisection(double a, double b) {
    const double tolerance = 1e-6; // Toler�ncia para o erro
    double c = a;

    if (func(a) * func(b) >= 0) {
        cout << "Voc� n�o forneceu um intervalo v�lido." << endl;
        return;
    }

    while ((b - a) >= tolerance) {
        // Encontra o ponto m�dio
        c = (a + b) / 2;

        // Verifica se o ponto m�dio � a raiz
        if (func(c) == 0.0) {
            break;
        }
        // Decide o lado para continuar a busca
        else if (func(c) * func(a) < 0) {
            b = c;
        }
        else {
            a = c;
        }
    }

    cout << "A raiz da fun��o �: " << c << endl;
}

int main() {
    double a = -200, b = 300; // Intervalo inicial
    bisection(a, b);
    return 0;
}
