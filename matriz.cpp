#include "matriz.h"
#include <iostream>
#include <stdexcept>

Matriz::Matriz(int linhas, int colunas, const double &valor){
	if(linhas < 0 || colunas < 0){
		throw std::invalid_argument("Erro. O numero de linhas e colunas devem ser numeros naturais");
	}
	
	rows = linhas;
	cols = colunas;
	
	data = new double*[rows];
	for (int i = 0; i < rows; ++i){
    	data[i] = new double[cols];
    	for (int j = 0; j < cols; j++){
    		data[i][j] = valor;
    	}
	}
	std::cout << "Matrix criada: construtor padrao." << std::endl;
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
	std::cout << "Matrix criada: construtor de copia." << std::endl;
}		

Matriz::~Matriz(void){
	for (int i = 0; i < rows; ++i){
    	delete [] data[i];
	}
    delete [] data;
    std::cout << "Matrix destruida: destrutor" << std::endl;
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
	for (int i = 0; i < M.rows; ++i){
    	delete [] M.data[i];
	}
    delete [] M.data;

	std::cout << "Insira #linhas: ";	
	op >> M.rows;
	std::cout << "Insira #colunas: ";
	op >> M.cols;
	
	if(M.rows < 0 || M.cols < 0){
		throw std::invalid_argument("Erro. O numero de linhas e colunas devem ser numeros naturais");
	}	
	
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
	if(rows != cols){
		throw std::invalid_argument("Erro. A matrix deve ser quadrada.");
	}	

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

Matriz	Matriz::operator+(const Matriz& B) const{
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

Matriz&	Matriz::operator=(const Matriz& B){
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

Matriz	Matriz::operator-(const Matriz& B) const{	
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

Matriz	Matriz::operator*(const Matriz& B) const{	
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

bool Matriz::operator==(const Matriz& B) const{
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

bool Matriz::operator!=(const Matriz& B) const{
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

Matriz	Matriz::operator~() const{
	Matriz A(cols, rows);
	
	for(int i = 0; i < cols; i++){
		for(int j = 0; j < rows; j++){
			A.data[i][j] = data[j][i];
		}
	}
	return A;
}

double& Matriz::operator()(int i, int j){
	if(i <= 0 || i > rows || j <= 0 || j > cols){
		throw std::invalid_argument("Erro! Nao existe elemento para este indice!");
	}	
	return data[i - 1][j - 1];	
}
	
