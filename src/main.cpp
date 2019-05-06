#include "ray.h" // Rays, planes and linear algebra functions

#include <CImg.h>   // Image library
#include <cmath>	// Trigonometric functions
#include <iostream> // Basic I/O
#include <omp.h>	// Multithreading

#define TRACE_INCREMENT 0.01

int main()
{
	// 	Ray::ray<double> rays[256][256]; 						  // Ray container
	// 	cimg_library::CImg<unsigned char> canvas(256, 256, 1, 1); // Canvas

	// 	omp_set_num_threads(omp_get_num_procs());

	// 	// Spawm all camera rays with initial brightness of 100
	// 	for (short y = 0; y < 256; ++y)
	// 		for (short x = 0; x < 256; ++x)
	// 			rays[x][y] = Ray::ray<double>(1, 128 * sin(x), 128 * sin(y), 100);

	// 	// Trace rays for 1000 iterations
	// #pragma omp parallel for schedule(dynamic)
	// 	for (int i = 0; i < 1000; ++i)
	// 	{
	// 		for (short y = 0; y < 256; ++y)
	// 		{
	// 			for (short x = 0; x < 256; ++x)
	// 			{
	// 				if (rays[x][y].trace(TRACE_INCREMENT))
	// 				{
	// 					if (rays[x][y].y() < 0)
	// 						canvas(x, y) = 1;
	// 					else canvas(x, y) = 0;
	// 				}
	// 			}
	// 		}
	// 	}

	std::cout << Ray::reflect(Ray::ray<float>(1, 1, 1, 100), Ray::vector<float>(1, 0, 0)) << std::endl;

	return 0;
}
