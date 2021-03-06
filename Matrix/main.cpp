#include "stdafx.h"
#include "Matrix.h"

using namespace Math;

int main()
{
	const double arr1[] = { 4.3, 3.2, 9.2, 1.2, 3.2, 4.5 };
	const double arr2[] = { 1.2, 5.2, 6.2, 8.2, 9.2, 1.5 };

	try {

		Matrix A(2, arr2);
		cout << A;
		
		Matrix B(2, 3, arr1);
		cout << B;

		Matrix C(B);
		cout << C;
	} catch (const string &std) {
		cout << std << endl;
	}


    return 0;
}

