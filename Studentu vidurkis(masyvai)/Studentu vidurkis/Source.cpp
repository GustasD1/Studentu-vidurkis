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
	double vidurkis = 0;
	double mediana = 0;
	double rezultatas = 0;
	double rezultatasm = 0;

};
void skaitymas(data& temp, int & n);
void isvedimas(data& temp, int n);
void apskaiciavimas(data& temp, int n);
int main() {
	data* mas = new data[2];
	int n;
	for (data* a = mas; a < mas + 2; a++) {
		skaitymas(*a,n);
		apskaiciavimas(*a, n);
	}










	cout << std::setw(20) << "vardas" << std::setw(20) << "pavarde" << std::setw(20) << "Galutinis (Vid.)" << std::setw(20)<<"Galutinis(Med.)"<< endl;
	for (data* a = mas; a < mas + 2; a++) {
		isvedimas(*a,n);
	}
	delete[] mas;


}
void skaitymas(data& temp, int & n) {
	
	cout << "Iveskite studento varda" << endl;
	cin >> temp.vardas;
	cout << "Iveskite studento pavarde" << endl;
	cin >> temp.pavarde;
	cout << "Kiek studentas turi pazymiu" << endl; cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Iveskite " << i + 1 << " -a(i) pazymi";
		cin >> temp.paz[i];

	}
	cout << "Iveskite egzamino pazymi: ";
	cin >> temp.egz;

}
void isvedimas(data& temp, int n) {

	cout << std::setw(20) << temp.vardas << std::setw(20) << temp.pavarde;
	cout << std::setw(20)<< std::fixed<<std::setprecision(2)<< temp.rezultatas <<std::setw(20)<<temp.rezultatasm<< endl;


}
void apskaiciavimas(data& temp, int n) {
	for (int i = 0; i < n; i++) {              //Galutinio balo skaiciavimas pagal vidurki
		temp.vidurkis = temp.vidurkis + temp.paz[i];
	}
	temp.rezultatas = (temp.vidurkis / n) * 0.4 + 0.6 * temp.egz;


	//Galutinio balo skaiciavimas pagal mediana
	int sk=0;
	int laik = n;
	if (n % 2 == 0) {
		sk = 1; //patikrinam ar skaiciu imtis yra lygine ar nelygine, jei sk=1 tai lygine jei sk=0 tai nelygine
	}
	else sk = 0;
		if (sk == 1) {
			laik = laik / 2;
			temp.mediana = (temp.paz[laik] + temp.paz[laik + 1]) / 2;
			temp.rezultatasm = temp.mediana * 0.4 + 0.6 * temp.egz;

		}
		else {
			laik = laik / 2 + 1 ;
			
			temp.rezultatasm = temp.paz[laik] * 0.4 + 0.6 * temp.egz;


		}
}