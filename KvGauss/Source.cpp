#include <iostream>
#include <cmath>

using namespace std;


double integrateUsingGaussianQuadrature(double (*func)(double), int n) {
    double integral = 0.0;
    double a = 1.0; 
    double b = 2.0; 

    double xi[3];
    double wi[3];

    if (n == 2) {
        xi[0] = -0.5773502691896257;
        xi[1] = 0.5773502691896257;
        wi[0] = 1.0;
        wi[1] = 1.0;
    }
    else if (n == 3) {
        xi[0] = -0.7745966692414834;
        xi[1] = 0.0;
        xi[2] = 0.7745966692414834;
        wi[0] = 0.5555555555555556;
        wi[1] = 0.8888888888888888;
        wi[2] = 0.5555555555555556;
    }
    else if (n == 4) {
        xi[0] = -0.8611361153836263;
        xi[1] = -0.3399810435848563;
        xi[2] = 0.3399810435848563;
        xi[3] = 0.8611361153836263;
        wi[0] = 0.3478548451374538;
        wi[1] = 0.6521451548625461;
        wi[2] = 0.6521451548625461;
        wi[3] = 0.3478548451374538;
    }
    else {
        cout << "Выбрано неподдерживаемое n." << endl;
        return 0.0;
    }

    for (int i = 0; i < n; i++) {
        double x = 0.5 * ((b - a) * xi[i] + a + b);
        integral += wi[i] * func(x);
    }
    integral *= 0.5 * (b - a);

    return integral;
}

int main() {

    setlocale(LC_ALL, "Russian");
    auto func1 = [](double x) {
        return sin(1.0 / (x * x));
    };

    auto func2 = [](double x) {
        return x * sin(1.0 / (x * x * x));
    };

    int n = 2;
    double integral1 = integrateUsingGaussianQuadrature(func1, n);
    double integral2 = integrateUsingGaussianQuadrature(func2, n);

    cout << "Значение интеграла для первой функции: " << integral1 << endl;
    cout << "Значение интеграла для второй функции: " << integral2 << endl;

    return 0;
}
