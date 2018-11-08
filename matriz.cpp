#include "matriz.h"
#include <iostream>
#include <stdexcept>

Matriz::Matriz(int linhas, int colunas, const double &valor){
	rows = linhas;
	cols = colunas;
	
	data = new double*[rows];
	for (int i = 0; i < rows; ++i){
    	data[i] = new double[cols];
    	for (int j = 0; j < cols; j++){
    		data[i][j] = valor;
    	}
	}
}

Matriz::Matriz(const Matriz &m){
	rows = m.rows;
	cols = m.cols;
	
	data = new double*[rows];
	for (int i = 0; i < rows; ++i){
    	data[i] = new double[cols];
    	for (int j = 0; j < cols; j++){
    		data[i][j] = m.data[i][j];
    	}
	}
}		

Matriz::~Matriz(void){
	for (int i = 0; i < rows; ++i){
    	delete [] data[i];
	}
    delete [] data;
    //cout << "Destroid matrix" << endl;
}

std::ostream& operator << (std::ostream& op, const Matriz& M){
	op << "Linhas:  " << M.rows << std::endl << "Colunas: " << M.cols << std::endl;
	for(int i = 0; i < M.rows; i++){
		for(int j = 0; j < M.cols; j++){
			op << M.data[i][j] << "\t";
		}
		op << std::endl;
	}
	return op;
}

std::istream& operator >> (std::istream& op, Matriz& M){
	std::cout << "Insira #linhas: ";
	op >> M.rows;
	std::cout << "Insira #colunas: ";
	op >> M.cols;

	for (int i = 0; i < M.rows; ++i){
    	delete [] M.data[i];
	}
    delete [] M.data;
	
	M.data = new double*[M.rows];
	std::cout << "Insira os valores da Matriz: ";
	for (int i = 0; i < M.rows; ++i){
    	M.data[i] = new double[M.cols];
    	for (int j = 0; j < M.cols; j++){
    		op >> M.data[i][j];
    	}
	}
	std::cout << std::endl;
	return op;
}

void Matriz::unit(){
	for (int i = 0; i < rows; ++i){
    	for (int j = 0; j < cols; j++){
    		if(i == j)
    		data[i][j] = 1.;
    		else
    		data[i][j] = 0.;
    	}
	}
}

void Matriz::zeros(){
	for (int i = 0; i < rows; ++i){
    	for (int j = 0; j < cols; j++){
    		data[i][j] = 0.;
    	}
	}
}

void Matriz::ones(){
	for (int i = 0; i < rows; ++i){
    	for (int j = 0; j < cols; j++){
    		data[i][j] = 1.;
    	}
	}
}

Matriz	Matriz::operator+(const Matriz& B){
	if(rows != B.rows || cols != B.cols){
		throw std::invalid_argument("Erro! Dimensoes incompativeis!");
	}
	
	int l, c;
	l = get_rows();
	c = get_cols();
	Matriz aux(l, c);
	
	for (int i = 0; i < rows; ++i){
    	for (int j = 0; j < cols; j++){
    		aux.data[i][j] = data[i][j] + B.data[i][j];
    	}
	}
	return aux;
}


Matriz	Matriz::operator=(const Matriz& B){
	if(this == &B)
		return *this;
	
	for (int i = 0; i < rows; ++i){
    	delete [] data[i];
	}
    delete [] data;

	rows = B.rows;
	cols = B.cols;
	
	data = new double*[rows];
	for (int i = 0; i < rows; ++i){
    	data[i] = new double[cols];
    	for (int j=0; j < cols; j++){
    		data[i][j] = B.data[i][j];
    	}
	}
	return *this;
}

Matriz	Matriz::operator-(const Matriz& B){	
	if(rows != B.rows || cols != B.cols){
		throw std::invalid_argument("Erro! Dimensoes incompativeis!");
	}
	
	int l, c;
	l = get_rows();
	c = get_cols();
	Matriz aux(l, c);
	
	for (int i = 0; i < rows; ++i){
    	for (int j = 0; j < cols; j++){
    		aux.data[i][j] = data[i][j] - B.data[i][j];
    	}
	}
	return aux;
}

Matriz	Matriz::operator*(const Matriz& B){	
	if(cols != B.rows){
		throw std::invalid_argument("Erro! Dimensoes incompativeis!");
	}
	
	int l, c;
	l = get_rows();
	c = B.get_cols();
	Matriz aux(l, c);
	
	for (int i = 0; i < rows; ++i){
    	for (int j = 0; j < B.cols; j++){
    		for(int k = 0; k < cols; k++){
	    		aux.data[i][j] = aux.data[i][j] + (data[i][k] * B.data[k][j]);
    		}
		}
	}
	return aux;
}

Matriz&	Matriz::operator+=(const Matriz& B){	
	if(rows != B.rows || cols != B.cols){
		throw std::invalid_argument("Erro! Dimensoes incompativeis!");
	}
	
	Matriz aux = (*this) + B;
	(*this) = aux;	
	
	return *this;
}

Matriz&	Matriz::operator-=(const Matriz& B){	
	if(rows != B.rows || cols != B.cols){
		throw std::invalid_argument("Erro! Dimensoes incompativeis!");
	}
	
	Matriz aux = (*this) - B;
	(*this) = aux;	
	
	return *this;
}

Matriz&	Matriz::operator*=(const Matriz& B){	
	if(cols != B.rows){
		throw std::invalid_argument("Erro! Dimensoes incompativeis!");
	}	

	Matriz aux = (*this) * B;
	(*this) = aux;		
	
	return *this;
}

Matriz&	Matriz::operator*=(double x){		
	for (int i = 0; i < rows; ++i){
    	for (int j = 0; j < cols; j++){
    		data[i][j] = data[i][j] * x;
    	}
	}
	return *this;
}

bool Matriz::operator==(const Matriz& B){
	if(rows != B.rows || cols != B.cols)
		return false;
		
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(data[i][j] != B.data[i][j])
				return false;
		}
	}
	return true;		
}

bool Matriz::operator!=(const Matriz& B){
	if(rows != B.rows || cols != B.cols)
		return true;
		
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(data[i][j] != B.data[i][j])
				return true;
		}
	}
	return false;		
}

double&	Matriz::operator()(const int i, const int j){	
	return	data[i - 1][j - 1];
}

void Matriz::operator=(const double x){
	(*this) = x;
}

Matriz	Matriz::operator~(){
	Matriz A(cols, rows);
	
	for(int i = 0; i < cols; i++){
		for(int j = 0; j < rows; j++){
			A.data[i][j] = data[j][i];
		}
	}
	return A;
}
