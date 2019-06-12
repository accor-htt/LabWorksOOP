#include <iostream>
#include "string.h"
#include "Basic.h"

using namespace math;

int main() {

    try {

        const double arr1[] = {4.3, 3.2, 9.2, 1.2, 3.2, 4.5};
        const double arr2[] = {3.1, 5.6, 8.3, 11.0};
        const double arr3[] = {1.2, 5.2, 6.2, 8.2, 9.2, 1.5};

        Matrix a(2, 3, arr1);
        Matrix r(3, 2, arr3);
        Vector b(4, arr2);
        const Vector c(3, arr2);
        Matrix u(1,3, arr3); // check get rank on VECTOR


        //c[0] = 123;

        std::cout << a;

        std::cout << "========" << std::endl;
        std::cout << r;

        a *= r;

        std::cout << "========" << std::endl;

        std::cout << a;

        a = r;

        std::cout << "========" << std::endl;

        std::cout << a;

        //bool statusb = a.getRank();
        //bool statusu = b.getRank();

        //std::cout << statusb << std::endl;
        //std::cout << statusu << std::endl;

        //b *= u;
        //std::cout << b;


        //std::cout << a;
        //std::cout << b;

        //std::cout << std::endl;

        //std::cout << "max a : " << a.FindMax() << std::endl;
        //std::cout << "max b : " << b.FindMax() << std::endl;

        //std::cout << "max a : " << a.getSize() << std::endl;
        //std::cout << "max b : " << b.getSize() << std::endl;

        Matrix test1(2, 3, arr1);
        Vector test2(test1);

        Vector aa(4);
        Vector bb(3);
        bb.Transposition();

        aa = bb;
        //test2 = test1;


    } catch (const std::string &std) {
        std::cout << std << std::endl;
    }
    return 0;
}