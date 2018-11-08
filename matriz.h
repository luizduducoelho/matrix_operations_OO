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
	
	double get(const int i, const int j) const {return data[i - 1][j - 1];}
	
	int get_rows() const {return rows;}
	int get_cols() const {return cols;}
	void unit();
	void zeros();
	void ones();
	
	Matriz operator+(const Matriz&);
	Matriz operator=(const Matriz&);	
	Matriz operator-(const Matriz&);
	Matriz operator*(const Matriz&);
	Matriz operator~();	
	Matriz& operator+=(const Matriz&);	
	Matriz& operator-=(const Matriz&);
	Matriz& operator*=(const Matriz&);
	Matriz& operator*=(const double);
	
	double& operator()(const int, const int);
	
	void operator=(const double);
	
	bool operator==(const Matriz&);
	bool operator!=(const Matriz&);
	
	friend std::ostream& operator<<(std::ostream&, const Matriz&);
	friend std::istream& operator>>(std::istream&, Matriz&);

};

#endif
