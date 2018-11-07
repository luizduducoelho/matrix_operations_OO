#include "matriz.h"
#include <iostream>

using namespace std;

Matriz::Matriz(int linhas, int colunas, const double &valor){
	rows = linhas;
	cols = colunas;
	
	data = new double*[rows];
	for (int i = 0; i < rows; ++i){
    	data[i] = new double[cols];
    	for (int j=0; j < cols; j++){
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
    	for (int j=0; j < cols; j++){
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

ostream& operator << (ostream& op, const Matriz& M){
	op << "Linhas:  " << M.rows << endl << "Colunas: " << M.cols << endl;
	for(int i = 0; i < M.rows; i++){
		for(int j = 0; j < M.cols; j++){
			op << M.data[i][j] << "\t";
		}
		op << endl;
	}
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
		cout << "Erro! Dimensoes incompativeis!" << endl;
		return 0;
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
		cout << "Erro! Dimensoes incompativeis!" << endl;
		return 0;
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
		cout << "Erro! Dimensoes incompativeis!" << endl;
		return 0;
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
		cout << "Erro! Dimensoes incompativeis!" << endl;
		return *this;
	}
	
	for (int i = 0; i < rows; ++i){
    	for (int j = 0; j < cols; j++){
    		data[i][j] = data[i][j] + B.data[i][j];
    	}
	}
	return *this;
}

Matriz&	Matriz::operator-=(const Matriz& B){	
	if(rows != B.rows || cols != B.cols){
		cout << "Erro! Dimensoes incompativeis!" << endl;
		return *this;
	}
	
	for (int i = 0; i < rows; ++i){
    	for (int j = 0; j < cols; j++){
    		data[i][j] = data[i][j] - B.data[i][j];
    	}
	}
	return *this;
}

Matriz&	Matriz::operator*=(const Matriz& B){	
	if(cols != B.rows){
		cout << "Erro! Dimensoes incompativeis!" << endl;
		return *this;
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
