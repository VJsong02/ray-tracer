#include "ray.h"
#include <iostream>

int main()
{
	Ray::vector<float> a(1, 2, 3);
	Ray::vector<float> b(4, 3, 2);
	Ray::vector<float> sum = a + b;
	std::cout << sum << std::endl;

	return 0;
}
