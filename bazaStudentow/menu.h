#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using std::string;
class Student;

class Menu {
private:
	std::fstream plik;
	std::vector <Student> lista_studentow;
public:
	void linia(void) {
		for (int i = 0; i < 40; i++)
			std::cout << "-";
		std::cout << std::endl;
	}
	void otworz_plik(std::fstream& plik_fun);
	void rozpocznij_program();
	void dodaj_studenta();
	void wypisz_studenta(); // tutaj moga byc juz nawet private
	void DodajDoPliku(string& im, string& nazw, unsigned int& nr_leg, int& o_fizyka, int& o_analiza, int& o_informatyka, int& o_algebra, int& o_angielski);
	void ZaladujDoProgramu();
	void ZamienDaneWPliku(unsigned int key, int i);
	void pomin_wyraz();
	void pomin_znaki();
	void wypisz_znalezione_dane(std::vector <Student>& lista_studentow, int i);
	int szukajNazwisko(string& szukaj);
	int szukajLegitymacje(unsigned int& szukaj);
	void zmien_oceny(std::vector <Student>& lista_studentow, int i);
	bool SprawdzPoprawnoscDanych();

};