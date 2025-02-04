// Método Das Steffensen para encontrar raízes de funções.
// Juan Brunno Gomes de Lima
// Código feito em c++

#include <iostream>
#include <cmath>

using namespace std;

// Função para a qual queremos encontrar a raiz
double func(double x) {
    return x * x * x - x * x + 2;
}

// Implementação do método de Steffensen
void steffensen(double x0) {
    const double tolerance = 1e-6; // Tolerância para o erro
    const int maxIterations = 1000; // Número máximo de iterações
    double x1, x2;
    int iteration = 0;

    while (iteration < maxIterations) {
        double fx0 = func(x0);
        double fx1 = func(x0 + fx0);
        double fx2 = func(x0 + 2 * fx0);

        // Calcula a próxima aproximação usando a fórmula de Steffensen
        x1 = x0 - (fx0 * fx0) / (fx2 - 2 * fx1 + fx0);

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
    double x0 = -20; // Ponto inicial
    steffensen(x0);
    return 0;
}
