#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>

class Matriz{
private:
	int rows;
	int cols;
	double** data;
	
public:
	Matriz(int linhas=0, int colunas=0, const double &valor = 0); 
	~Matriz(); 				  // destrutor	
	Matriz(const Matriz &m);  // construtor de copia
	int get_rows() const;
	int get_cols() const;
	void unit();
	void zeros();
	void ones();
	Matriz operator+(const Matriz&);	
	Matriz operator-(const Matriz&);
	Matriz operator*(const Matriz&);	
	Matriz& operator+=(const Matriz&);	
	Matriz& operator-=(const Matriz&);
	Matriz& operator*=(const Matriz&);
	Matriz& operator*=(const double);
	friend std::ostream& operator<<(std::ostream&, const Matriz&);
};

#endif
