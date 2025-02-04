// Método Das Aproximações Sucessivas para encontrar raízes de funções.
// Juan Brunno Gomes de Lima
// Código feito em c++

#include <iostream>
#include <cmath>

using namespace std;

// Função g(x) derivada da equação f(x) = 0, tal que x = g(x)
double g(double x) {
    return cos(x); // Exemplo: g(x) = cos(x)
}

// Implementação do método das aproximações sucessivas
void fixedPointIteration(double x0) {
    const double tolerance = 1e-6; // Tolerância para o erro
    const int maxIterations = 1000; // Número máximo de iterações
    double x1;
    int iteration = 0;

    while (iteration < maxIterations) {
        x1 = g(x0);

        if (abs(x1 - x0) < tolerance) {
            cout << "A raiz da função é: " << x1 << endl;
            return;
        }

        x0 = x1;
        iteration++;
    }

    cout << "O método não convergiu após " << maxIterations << " iterações." << endl;
}

int main() {
    double x0 = 0.5; // Ponto inicial
    fixedPointIteration(x0);
    return 0;
}
