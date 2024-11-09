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
#include <cmath>
#include <omp.h>
// #include <unistd.h>
#include "f.h"
#include "heat_difusion.h"
#include "soma_integral.h"

int main()
{
	std::cout << "Hello World!"
			  << std::endl;

	double a = 0;
	double b = 1.0;

	int N = 5000000;

	double s = soma_integral(a, b, N, f_pi);

	double pi = 4 * s;

	std::cout << "soma = " << s << std::endl;
	std::cout << "pi calculado = " << pi << std::endl;

	// for(int k = 0; k < 10; k++){
	//	std::cout << k << std::endl;
	//}

// #pragma omp parallel
// 	{
// 		int thread_id = omp_get_thread_num();
// 		// sleep(1);
// 		for (int n = 0; n < 5; n++)
// 			double s = soma_integral(a, b, N, f_pi);
// 		std::cout << thread_id << std::endl;
// 	}

	heat_difusion();

	return 0;
}
