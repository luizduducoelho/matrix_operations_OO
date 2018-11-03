#include <iostream>
#include "matriz.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	Matriz Y;
	Matriz X(3,3,2.), A(3,3,5.), C(3,3, 4.4);
	
	Y = X;

/*	Funcoes testadas:
	void unit();
	void zeros();
	void ones();
	Matriz operator+(const Matriz&); -------------------- Problemas de incompatibilidade, valor se perde quando as matrizes nao sao compativeis
	Matriz operator-(const Matriz&); -------------------- Problemas de incompatibilidade, valor se perde quando as matrizes nao sao compativeis
	Matriz operator*(const Matriz&); -------------------- Problemas de incompatibilidade, valor se perde quando as matrizes nao sao compativeis	
	Matriz& operator+=(const Matriz&);	
	Matriz& operator-=(const Matriz&);
	Matriz& operator*=(const Matriz&); ------------------- Rever implementacao
	Matriz& operator*=(const double);
	friend std::ostream& operator<<(std::ostream&, const Matriz&); 
*/
	
	std::cout << std::endl << Y << std::endl;
	
	return 0;
}
