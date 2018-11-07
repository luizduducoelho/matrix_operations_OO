#include <iostream>
#include "matriz.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	Matriz X(6,6,1), A(1,7,1), C(3,5,4.);
	Matriz Y(A);

	cout << X << endl;
	
// Dúvidas: sobrecarga ~; A(i,j) = 10; throw.
   
/*	Funcoes testadas:
	void get();
	void unit();
	void zeros();
	void ones();
	Matriz operator+(const Matriz&); -------------------- 
	Matriz operator-(const Matriz&); -------------------- 
	Matriz operator*(const Matriz&); -------------------- 
	Matriz& operator+=(const Matriz&);	
	Matriz& operator-=(const Matriz&);
	Matriz& operator*=(const Matriz&);
	Matriz& operator*=(const double);
	bool operator==(const double);
	bool operator!=(const double);
	friend std::ostream& operator<<(std::ostream&, const Matriz&); 
*/

	return 0;
}
