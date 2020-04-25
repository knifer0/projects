#include "student.h"
#include "menu.h"
#include <fstream>

int Student::counter_elements = 0;
Student::Student(string im, string nazw, unsigned int nr_leg, int o_fizyka, int o_analiza, int o_informatyka, int o_algebra, int o_angielski) {
	imie = im;
	nazwisko = nazw;
	numer_legitymacji = nr_leg;
	ocena_fizyka = o_fizyka;
	ocena_analiza = o_analiza;
	ocena_informatyka = o_informatyka;
	ocena_algebra = o_algebra;
	ocena_angielski = o_angielski;
	counter_elements++;
}

Student::Student(const Student& s) {
	imie = s.imie;
	nazwisko = s.nazwisko;
	numer_legitymacji = s.numer_legitymacji;
	ocena_fizyka = s.ocena_fizyka;
	ocena_analiza = s.ocena_analiza;
	ocena_informatyka = s.ocena_informatyka;
	ocena_algebra = s.ocena_algebra;
	ocena_angielski = s.ocena_angielski;
}

Student::~Student() {
	counter_elements--;
}

int Student::NumberOfElements() {
	return counter_elements;
}

void bufor(void) {
	std::cin.clear();
	while (std::cin.get() != '\n')
		continue;
}
