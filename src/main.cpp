#include "ray.h" // Rays, planes and linear algebra functions

// #include <CImg.h>// Image library
#include <cmath>	// Trigonometric functions
#include <iostream> // Basic I/O

#define TRACE_INCREMENT 0.01

int main()
{
	Ray::vector<double> a(1, 2, 3);
	Ray::vector<double> b(2, 3, 4);
	Ray::vector<double> c = a + b;

	std::cout << c << std::endl;

	return 0;
}
