#include "CImg.h" // Image manipulation
#include "ray.h"  // Rays, planes and linear algebra functions

#include <cmath>	// Trigonometric functions
#include <iostream> // Basic I/O
#include <omp.h>

int main()
{
	Ray::ray<float>[256][256] rays;							  // Camera with 65536 greyscale rays
	cimg_library::CImg<unsigned char> canvas(256, 256, 1, 1); // Canvas to draw traced rays on

	omp_set_num_threads(omp_get_num_procs());

	// Generate all camera rays with initial brightness of 100
	for (short y = 0; y < 256; ++y)
		for (short x = 0; x < 256; ++x)
			rays[x][y] = Ray::ray<float>(1, 256 * sin(x), 256 * sin(y), 100);

			// Trace rays for 1000 iterations
#pragma omp parallel for schedule(dynamic)
	for (int i = 0; i < 1000; ++i)
	{
		for (short y = 0; y < 256; ++y)
		{
			for (short x = 0; x < 256; ++x)
			{
				if (rays[x][y].trace())
				{
					if (rays[x][y].y() < 0)
						canvas(x, y, 1) =
				}
			}
		}
	}

	return 0;
}
