/*
HPC
aula3.c
Ivo Vargas
2024-10-30

Compilar:
nvc++ integral_a.c -fopenmp -o integral_c.o

Exemplo de integral para calcular areas
*/
#include <stdio.h>
#include <math.h>
#include <omp.h>
// #include <unistd.h> biblioteca da função sleep()

// Função que devolve uma constante
double f1(double x)
{
    return 1.0;
}

double f2(double x)
{
    return x * x;
}

double f_pi(double x)
{
    return sqrt(1 - x * x);
}

double soma_integral(double a, double b, int N, double (*f)(double))
{
    double dx = (b - a) / N;
    double s = 0;

    for (int k = 0; k < N; k++)
    {
        s += f(a + k * dx) * dx;
    }
    return s;
}

int main()
{
    double a = 0.0;
    double b = 1.0;
    int N = 5000000;

    double s = soma_integral(a, b, N, f_pi);
    double pi = 4 * s;

    printf("Pi Calculado = %f\n", pi);

    /*for (int k = 0; k < 10; k++)
    {
        printf("k = %d\n", k);
    }*/

#pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        for (int i = 0; i < 100; i++)
        {
            double s = soma_integral(a, b, N, f_pi);
        }
        printf("thread_id = %d\n", thread_id);
    }

    return 0;
}