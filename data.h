#ifndef DATA_H
#define DATA_H

#include <iostream>

using namespace std;

class Data{

private:
	int dia;
	int mes;
	int ano;

public:

	Data(int, int, int); //metodo construtor 
	
	void setDia(int);
	void setMes(int);
	void setAno(int);

	int getDia() { return dia; };
	int getMes() { return mes; };
	int getAno() { return ano; };

	void avancarDia();
};

void Data::avancarDia(){

	int d;
	int m;

	d = getDia();
	m = getMes();

	if(m == 2){ //checa se o mes é fevereiro
		if(d < 28){
			setDia(d + 1);
		}else{ 
			setMes(m + 1);
			setDia(1);
		}
	}else if(m == 4 || m == 6 || m == 9 || m == 11 ){ // verifica se o mes é de 31 dias
		if(d < 31){
			setDia((d + 1));
		}else{
			setMes(m + 1);
			setDia(1);
		}
	}else{
		setDia(d + 1);
	}
	if(m == 12  && d == 31){
		setDia(1);
		setMes(1);
		setAno(getAno() + 1);
	}
}

Data::Data(int d, int m, int a){ //metodo construtor 
	
	setAno(a);
	setMes(m);
	setDia(d);

	if(m == 2){
		if(dia <= 28){
			setDia(d);
		}

		if(m == 4 || m == 6 || m == 9 || m == 11){ //checa os meses com 30 dias;
			if(dia <= 30){
				setDia(d);
			}
		}
	}
}

void Data::setDia(int d){
	if(d <= 31 && d >= 1){
		dia = d;
	}else{
		cout << "Dia invalido" << endl;
	}
}

void Data::setMes(int m){
	if(m <= 12 && m >= 1){
		mes = m;
	}else{
		cout << "Mes invalido" << endl;
	}
}

void Data::setAno(int a){
	ano = a;
}

#endif