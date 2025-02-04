// Método De Newton-Raphson para encontrar raízes de funções.
// Juan Brunno Gomes de Lima
// Código feito em c++

#include <iostream>
#include <cmath>

using namespace std;

// Função para a qual queremos encontrar a raiz
double func(double x) {
    return x * x * x - x * x + 2;
}

// Derivada da função
double derivFunc(double x) {
    return 3 * x * x - 2 * x;
}

// Implementação do método de Newton-Raphson
void newtonRaphson(double x) {
    const double tolerance = 1e-6; // Tolerância para o erro
    double h = func(x) / derivFunc(x);

    while (abs(h) >= tolerance) {
        h = func(x) / derivFunc(x);

        // Atualiza a aproximação
        x = x - h;
    }

    cout << "A raiz da função é: " << x << endl;
}

int main() {
    double x0 = -20; // Ponto inicial
    newtonRaphson(x0);
    return 0;
}
