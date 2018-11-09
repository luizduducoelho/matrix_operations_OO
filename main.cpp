#include <iostream>
#include "matriz.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	Matriz X(5,5,1), A(4,5,1), C(5,5,4.), D, E, F, G, H, I , J;
	Matriz B(5,1);

	X(2,2) = 10;
	
	G = ~X;
	E = X + C;
	F = A * C;
	H = C;
	J = C;
	J.unit();
	
	cout << G << endl << E << endl << F << endl << H << endl << J << endl;

	return 0;
}
