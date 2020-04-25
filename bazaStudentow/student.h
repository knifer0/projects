#pragma once
#include <iostream>
#include <fstream>
#include <string>
using std::string;

class Student {
	friend class Menu; 
private:
	static int counter_elements;
	string imie;
	unsigned int numer_legitymacji;
	string nazwisko;
	int ocena_fizyka;
	int ocena_analiza;
	int ocena_informatyka;
	int ocena_algebra;
	int ocena_angielski;
	Student& operator=(const Student& q) { return *this; } // atrapa
public:
	Student(const Student& s);
	int NumberOfElements();
	Student(string im = "", string nazw = "", unsigned int nr_leg = 0, int o_fizyka = 0, int o_analiza = 0, int o_informatyka = 0, int o_algebra = 0, int o_angielski = 0);
	~Student();

};

void bufor(void);