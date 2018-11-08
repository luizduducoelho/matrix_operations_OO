#include <iostream>
#include "matriz.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	Matriz X(3,5,1), A(4,5,1), C(3,5,4.);
	Matriz B(5,1);

	X(1,1) = 5;
	
	X(2,2) = 10;
	
	cout << X << endl;

	B = ~A;

	cout << B << endl;

	return 0;
}
