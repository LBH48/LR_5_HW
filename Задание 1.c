#include <stdio.h>
#include <math.h>

#define A 7.1e-9
#define C 2.0

double F(double x, double y)
{
    double numerator = pow(A, 5) + pow(sin(y - C), 4);
    double denominator = pow(sin(x + y), 3) + fabs(x - y);

    if (denominator == 0.0)
    {
        return NAN;
    }

    return numerator / denominator;
}

int main(void)
{
    double x, y;

    printf("Введите x и y: ");
    if (scanf("%lf %lf", &x, &y) != 2)
    {
        printf("Ошибка ввода.\n");
        return 1;
    }

    printf("F(%.6f, %.6f) = %.8e\n", x, y, F(x, y));

    printf("\nКонтрольные значения:\n");
    printf("F(-2.3, 0.1) = %.8e\n", F(-2.3, 0.1));
    printf("F(3.7e-5, -1) = %.8e\n", F(3.7e-5, -1.0));

    return 0;
}
