#include "matriz.h"
#include <iostream>

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
	
	
	
}

Matriz::~Matriz(void){
	for (int i = 0; i < rows; ++i){
    	delete [] data[i];
	}
    delete [] data;
    //std::cout << "Destroid matrix" << std::endl;
}

int Matriz::get_rows() const {
	return rows;
}

int Matriz::get_cols() const {
	return cols;
}

