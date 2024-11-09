/*
HPC
aula3.cpp
Pedro Miranda
2024-10-30

Um exemplo de soma integral para cálculo de áreas

Compilar: 
	nvc++ aula3.cpp -fopenmp -o aula3
*/

#include <iostream>
#include <omp.h>
//#include <unistd.h>
#include "f.h"

double soma_integral(double a, double b, int N, 
					 double (*f)(double))
{
	double s = 0.0;
	double dx = (b-a) / N;

	for(int k = 0; k < N; k++){
		s += f(a+k*dx) * dx;
	}
	return s;
}

int main() {
	std::cout << "Hello World!"
	<< std::endl;

	double a = 0;
	double b = 1.0;

	int N = 5000000;

	double s = soma_integral(a,b,N, f_pi);

	double pi = 4 * s;

	std::cout << "soma = " << s << std::endl;
    std::cout << "pi calculado = " << pi << std::endl;

	// for(int k = 0; k < 10; k++){
	//	std::cout << k << std::endl;
	//}

	#pragma omp parallel
	{
		int thread_id = omp_get_thread_num();
		//sleep(1);
		for(int n = 0; n<5; n++)
			double s = soma_integral(a,b,N, f_pi);
		std::cout << thread_id << std::endl;
	}
    	
	return 0;
}
