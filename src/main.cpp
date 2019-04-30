#include <iostream>
#include "ray.h"
using namespace std;

int main() {
	Ray::vector<float> a(1, 2, 3);
	Ray::vector<float> b(4, 3, 2);
	cout << a * b << endl;

	return 0;
}