#pragma once

#include <iostream>

namespace Ray
{
    template <typename T>
    class ray
    {
        T vector[3];              // vector size
        unsigned char brightness; // vector brightness

    public:
        ray(T x, T y, T z, unsigned char brightness)
        {
            vector[0] = x;
            vector[1] = y;
            vector[2] = z;
            brightness = b;
        }

        friend ostream &operator<<(ostream &os, const ray &r)
        {
            return os << "(" << r.vector[0] << " " << r.vector[1] << " " << r.vector[2] << ") " << +brightness << "%" << endl;
        }
    };

    
} // namespace Ray