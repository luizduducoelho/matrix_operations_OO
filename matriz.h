#ifndef MATRIZ_H
#define MATRIZ_H

class Matriz{
private:
	int rows;
	int cols;
	
public:
	int get_rows();
	int get_cols();
	Matriz(int linhas, int colunas, const double &valor = 0);

};

#endif
