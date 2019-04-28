#include <iostream>
#include "ray.h"
using namespace std;

int main() {
    ray<float> a(1, 1, 1, 100);
    cout << a << endl;

    return 0;
}