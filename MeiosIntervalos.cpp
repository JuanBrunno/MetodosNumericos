#include <iostream>
#include <cmath>

using namespace std;

// Função para a qual queremos encontrar a raiz
double func(double x) {
    return x * x * x - x * x + 2;
}

// Implementação do método dos meios intervalos
void bisection(double a, double b) {
    const double tolerance = 1e-6; // Tolerância para o erro
    double c = a;

    if (func(a) * func(b) >= 0) {
        cout << "Você não forneceu um intervalo válido." << endl;
        return;
    }

    while ((b - a) >= tolerance) {
        // Encontra o ponto médio
        c = (a + b) / 2;

        // Verifica se o ponto médio é a raiz
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

    cout << "A raiz da função é: " << c << endl;
}

int main() {
    double a = -200, b = 300; // Intervalo inicial
    bisection(a, b);
    return 0;
}
