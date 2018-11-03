#include <iostream>
#include "matriz.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	Matriz Y;
	Matriz X(6,6,1), A(15,3,5.), C(3,5,4.);
	
	cout << X << endl;
	
	X = A * C;

      std::cout << X << std::endl << A << std::endl << C << std::endl;

   
   
/*	Funcoes testadas:
	void unit();
	void zeros();
	void ones();
	Matriz operator+(const Matriz&); -------------------- 
	Matriz operator-(const Matriz&); -------------------- 
	Matriz operator*(const Matriz&); -------------------- 
	Matriz& operator+=(const Matriz&);	
	Matriz& operator-=(const Matriz&);
	Matriz& operator*=(const Matriz&); ------------------- Rever implementacao
	Matriz& operator*=(const double);
	friend std::ostream& operator<<(std::ostream&, const Matriz&); 
*/

	
	return 0;
}
