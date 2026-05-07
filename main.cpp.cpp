#include <iostream>
#include <vector>

using namespace std;

// Questão 2.9 (b) - Regra de Horner O(n)
double horner(const vector<double>& a, int n, double x) {
    double res = 0;
    for (int i = n - 1; i >= 0; i--) {
        res = res * x + a[i];
    }
    return res;
}

// Questão 2.9 (a) - Simples O(n^2)
double simples(const vector<double>& a, int n, double x) {
    double res = 0;
    for (int i = 0; i < n; i++) {
        double p = 1;
        for (int j = 0; j < i; j++) p *= x;
        res += a[i] * p;
    }
    return res;
}

int main() {
    int n;
    double x;

    cout << "--- Atividade 2.9 ---" << endl;
    cout << "Digite a quantidade de coeficientes (n): ";
    cin >> n;

    vector<double> a(n);
    for (int i = 0; i < n; i++) {
        cout << "Digite o coeficiente a" << i << ": ";
        cin >> a[i];
    }

    cout << "Digite o valor de x: ";
    cin >> x;

    cout << "\nResultado O(n^2): " << simples(a, n, x) << endl;
    cout << "Resultado O(n): " << horner(a, n, x) << endl;

    return 0;
}