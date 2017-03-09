#include "data.h"

int main(){

	int dia, mes, ano;

	cout << "Digite uma data (dia,mes,ano): ";
	cin >> dia >> mes >> ano;
	
	Data(dia, mes, ano);

	Data dataTest(dia, mes, ano);

	cout << dataTest.getDia() << "/" << dataTest.getMes() << "/" << dataTest.getAno() << endl; 

	dataTest.avancarDia();
	cout << "O proximo dia é:" << endl;
	cout << dataTest.getDia() << "/" << dataTest.getMes() << "/" << dataTest.getAno() << endl; 

	return 0;
}