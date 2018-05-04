#include <math.h>

#define EXPORT extern "C" __declspec(dllexport)

EXPORT int gcd(int x, int y);
EXPORT int in_mandel(double x0, double y0, int n);
EXPORT int divide(int a, int b, int *remainder);
EXPORT double avg(double *a, int n);


// �ִ� ����� ���
int gcd(int x, int y) {
    int g = y;
    while (x > 0) {
        g = x;
        x = y % x;
        y = g;
    }
    return g;
}

// (x0, y0)�� �ǵ���Ʈ ����(Mandelbrot set)���� Ȯ���Ѵ�.
int in_mandel(double x0, double y0, int n) {
    double x = 0, y = 0, xtemp;
    while (n > 0) {
        xtemp = x*x - y*y + x0;
        y = 2*x*y + y0;
        x = xtemp;
        n -= 1;
        if (x*x + y*y > 4) return 0;
    }
    return 1;
}

// �� ���� ����
int divide(int a, int b, int *remainder) {
    int quot = a / b;
    *remainder = a % b;
    return quot;
}

// �迭 �� ���� ���
double avg(double *a, int n) {
    int i;
    double total = 0.0;
    for (i = 0; i < n; i++) {
        total += a[i];
    }
    return total / n;
}
