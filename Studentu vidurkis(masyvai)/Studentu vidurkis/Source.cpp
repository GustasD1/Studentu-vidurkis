#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;


struct data {
	string vardas = "", pavarde = "";
	int paz[5] = { 0 }, egz = 0;
	double rezultatas = 0;

};
void skaitymas(data& temp);
void isvedimas(data& temp);
int main() {
	data* mas = new data[2];
	for (data* a = mas; a < mas + 2; a++) {
		skaitymas(*a);
	}










	cout << std::setw(20) << "vardas" << std::setw(20) << "pavarde" << endl;
	for (data* a = mas; a < mas + 2; a++) {
		isvedimas(*a);
	}
	delete[] mas;


}
void skaitymas(data& temp) {
	int n = 5;
	cout << "Iveskite studento varda" << endl;
	cin >> temp.vardas;
	cout << "Iveskite studento pavarde" << endl;
	cin >> temp.pavarde;
	for (int i = 0; i < n; i++) {
		cout << "Iveskite " << i + 1 << " -a(i) pazymi";
		cin >> temp.paz[i];

	}
	cout << "Iveskite egzamino pazymi: ";
	cin >> temp.egz;

}
void isvedimas(data& temp) {

	cout << std::setw(20) << temp.vardas << std::setw(20) << temp.pavarde;
	for (int i = 0; i < 5; i++)
	cout << std::setw(10) << temp.paz[i];
	
	cout << std::setw(10)<< temp.egz << endl;


}