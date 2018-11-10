#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>

class Matriz{
private:
	int rows;
	int cols;
	double** data;
	
public:
	Matriz(int linhas = 0, int colunas = 0, const double &valor = 0); 
	~Matriz(); 				  
	Matriz(const Matriz &m);  
	
	int get_rows() const {return rows;}
	int get_cols() const {return cols;}
	void unit();
	void zeros();
	void ones();
	
	Matriz& operator=(const Matriz&);
	Matriz operator+(const Matriz&) const;	
	Matriz operator-(const Matriz&)  const;
	Matriz operator*(const Matriz&)  const;
	Matriz operator~() const;	
	Matriz& operator+=(const Matriz&);	
	Matriz& operator-=(const Matriz&);
	Matriz& operator*=(const Matriz&);
	Matriz& operator*=(double);
	
	double& operator()(int i, int j);
	double& operator=(double x){return (*this) = x;}
	
	bool operator==(const Matriz&) const;
	bool operator!=(const Matriz&) const;
	
	friend std::ostream& operator<<(std::ostream&, const Matriz&);
	friend std::istream& operator>>(std::istream&, Matriz&);

};

#endif
