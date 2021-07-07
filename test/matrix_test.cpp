#include "Matrix.h"
#include <iostream>

int main() {
    Matrix m(3);
    m.init({{1,2,3}, 
            {1,2,3}, 
            {1,2,3}});

    std::cout << m[0][0] << std::endl;
    return 0;
}