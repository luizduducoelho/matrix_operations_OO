#include <iostream>
#include "matriz.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	Matriz X(3,5,1), A(5,5,1), C(5,5,4.), D(1,1), E(1,1), F(1,1), G(1,1), H(1,1), I(1,1) , J(3,3);
	Matriz B(A);

	A *= 5;
	X(2,4) = 3;

	cout << A << endl << X;

	return 0;
}
