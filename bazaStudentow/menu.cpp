#include "student.h"
#include "menu.h"
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

void Menu::otworz_plik(std::fstream& plik_fun) {
	//cout << "Podaj nazwe pliku: ";
	string nazwa;
	//std::cin >> nazwa;
	plik_fun.open("bazaStudentow.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	if (!plik_fun.is_open()) {
		cout << "Nie mozna otworzyc pliku! Przerywam program" << endl;
		exit(EXIT_FAILURE);
	}
	//cin.get(); // pobierz entera
}
void Menu::pomin_wyraz() {
	char ch;
	while ((ch = plik.get()) != ' ')
		continue;
}

void Menu::pomin_znaki() {
	char ch;
	while ((ch = plik.get()) != ':')
		continue;
	plik.get();

}

void Menu::ZamienDaneWPliku(unsigned int key, int i) {
	string imie{};
	unsigned int numer_legitymacji{};
	string nazwisko{};
	int ocena_fizyka{};
	int ocena_analiza{};
	int ocena_informatyka{};
	int ocena_algebra{};
	int ocena_angielski{};
	char ch{};
	plik.close();
	plik.open("bazaStudentow.txt", std::fstream::in | std::fstream::out);
	if (!plik.is_open()) {
		cout << "Nie mozna otworzyc pliku! Przerywam program" << endl;
		exit(EXIT_FAILURE);
	} // nie moge uzyc app(upgrade pliku) bo wtedy nie bedzie nadpisywal ;p
	size_t odleglosc{};
	while (!plik.eof()) {
		pomin_wyraz();
		plik >> imie;
		plik.get(); // pomin spacje
		pomin_wyraz();
		plik >> nazwisko;
		plik.get(); // pomin entera
		pomin_znaki();
		plik >> numer_legitymacji;
		plik.get(); // pomin entera
		if (numer_legitymacji == key) {
			odleglosc = plik.tellg();
			plik.close();
			break;
		}
		pomin_znaki();
		plik >> ocena_fizyka;
		plik.get(); // pomin entera
		pomin_znaki();
		plik >> ocena_analiza;
		plik.get(); // pomin entera
		pomin_znaki();
		plik >> ocena_informatyka;
		plik.get(); // pomin entera
		pomin_znaki();
		plik >> ocena_algebra;
		plik.get(); // pomin entera
		pomin_znaki();
		plik >> ocena_angielski;
		ch = plik.get(); // pomin entera
		ch = plik.get(); // pobierz nowa linie
		ch = plik.get(); // pobierz EOF
	}
	if (odleglosc) {
		plik.open("bazaStudentow.txt", std::fstream::in | std::fstream::out);
		if (!plik.is_open()) {
			cout << "Nie mozna otworzyc pliku! Przerywam program" << endl;
			exit(EXIT_FAILURE);
		} 
		plik.seekg(odleglosc, std::ios::cur);
		plik << "Ocena z fizyki: " << lista_studentow[i].ocena_fizyka << endl;
		plik << "Ocena z analizy: " << lista_studentow[i].ocena_analiza << endl;
		plik << "Ocena z informatyki: " << lista_studentow[i].ocena_informatyka << endl;
		plik << "Ocena z algebry: " << lista_studentow[i].ocena_algebra << endl;
		plik << "Ocena z angielskiego: " << lista_studentow[i].ocena_angielski << endl;
	}
	plik.close();
	otworz_plik(plik); // ponownie go otwieram 
}

void Menu::ZaladujDoProgramu() {
	string imie{};
	unsigned int numer_legitymacji{};
	string nazwisko{};
	int ocena_fizyka{};
	int ocena_analiza{};
	int ocena_informatyka{};
	int ocena_algebra{};
	int ocena_angielski{};
	char ch{};
	cout << "Program zawiera jakies nieprawidlowe informacje. Nic nie robie w takim przypadku...";
	plik.seekg(0, std::ios::end);
	int length = (int)plik.tellg(); // sprawdzam rozmiar pliku
	if (length == 0)
		return; // wtedy nic nie czytam w pliku!!!
	plik.seekg(0, std::ios::beg); /// wracamy na poczatek
	while (!plik.eof()) {
		pomin_wyraz();
		plik >> imie;
		plik.get(); // pomin spacje
		pomin_wyraz();
		plik >> nazwisko;
		plik.get(); // pomin entera
		pomin_znaki();
		plik >> numer_legitymacji;
		plik.get(); // pomin entera
		pomin_znaki();
		plik >> ocena_fizyka;
		plik.get(); // pomin entera
		pomin_znaki();
		plik >> ocena_analiza;
		plik.get(); // pomin entera
		pomin_znaki();
		plik >> ocena_informatyka;
		plik.get(); // pomin entera
		pomin_znaki();
		plik >> ocena_algebra;
		plik.get(); // pomin entera
		pomin_znaki();
		plik >> ocena_angielski;
		ch = plik.get(); // pomin entera
		ch = plik.get(); // pobierz nowa linie
		ch = plik.get(); // pobierz EOF
		lista_studentow.push_back(Student(imie, nazwisko, numer_legitymacji, ocena_fizyka, ocena_analiza, ocena_informatyka, ocena_algebra, ocena_angielski));
	}
	plik.close();
}

void Menu::rozpocznij_program() {
	otworz_plik(plik);
	ZaladujDoProgramu();
	otworz_plik(plik); // musze otworzyc ponownie plik po eof
	system("cls");
	// tutaj bede zapisywal studentow!
	char wybor{};
	string szukaj_nazwisko = "";
	unsigned int szukaj_legitymacja = 0;
	int znaleziony_indeks = 0;

	while (1) {
		cout << "1. Dodaj studenta i jego oceny" << endl;
		cout << "2. Modyfikowanie danych studenta" << endl;      //menu
		cout << "3. Lista studentow" << endl;
		cout << "4. Informacja o studencie" << endl;
		cout << "5. Zakonczenie programu" << endl;
		cout << "6. Sprawdz poprawnosc danych (indeksow studentow)*" << endl;
		cout << "7. Wyczysc ekran" << endl;
		wybor = cin.get();
		cin.get(); // pobierz entera
		switch (wybor) {
		case '1':
			system("cls");
			dodaj_studenta();
			system("cls");
			cout << "Dodano stundeta!" << endl << endl;
			cin.get();//pobieram entera!
			break;
		case '2':
			system("cls");
		modyfikacja:
			cout << "1. Wpisz numer indeksu ucznia, ktorego oceny chcesz zmodyfikowac: " << endl;
			cout << "2. Powrot do wczesniejszego menu" << endl;
			cin >> wybor;
			cin.get();
			switch (wybor) {
			case '1':
				system("cls");
				cout << "Wpisz numer indeksu: ";
				while (!(cin >> szukaj_legitymacja));
				cin.get();
				while ((znaleziony_indeks = szukajLegitymacje(szukaj_legitymacja)) == -1)
					goto modyfikacja;
				zmien_oceny(lista_studentow, znaleziony_indeks);
				cin.get();
				break;
			case '2':
				system("cls");
				continue; // powrot do menu
			case '3':
			default:
				system("cls");
				cout << "Wybierz 1 lub 2 " << endl;
				goto modyfikacja;
			}
			break;
		case '3':
			system("cls");
			wypisz_studenta();
			break;
		case '4':
			system("cls");
		powrot:
			cout << "1. Wyszukaj po nazwisku: " << endl;
			cout << "2. Wyszukaj po legitymacji: " << endl;
			cout << "3. Wroc do poprzediego menu" << endl;
			cin >> wybor;
			cin.get();
			switch (wybor) {
			case '1':
				system("cls");
				cout << "Podaj nazwisko: ";
				getline(cin, szukaj_nazwisko);
				szukaj_nazwisko[0] = toupper(szukaj_nazwisko[0]);
				while ((znaleziony_indeks = szukajNazwisko(szukaj_nazwisko)) == -1)
					goto powrot;
				wypisz_znalezione_dane(lista_studentow, znaleziony_indeks);
				break;
			case '2':
				system("cls");
				cout << "Podaj numer legitymacji: ";
				cin >> szukaj_legitymacja;
				while ((znaleziony_indeks = szukajLegitymacje(szukaj_legitymacja)) == -1)
					goto powrot;
				wypisz_znalezione_dane(lista_studentow, znaleziony_indeks);
				cin.get();
				break;
			case '3':
				system("cls");
				continue; // powrot do gornego menu ;)
				break;//break niepotrzebny, ale dam do czytelnosci kodu
			default:
				cout << "Wybierz 1 albo 2, lub 3 by wrocic do poprzedniego menu" << endl;
				goto powrot;
			}
			break;
		case '5':
			system("cls");
			linia();
			plik.close();
			cout << "POMYSLNIE ZAKONCZYLEM PROGRAM, SPRAWDZ PLIK." << endl;
			exit(EXIT_SUCCESS);
		case '6':
			system("cls");
			if (SprawdzPoprawnoscDanych())
				cout << "Wszystkie dane sa poprawne! ;)" << endl;
			else
				cout << "NIEPOPRAWNE INDEKSY!!!!!!!!!!!!!!!" << endl;
			break;
		case '7':
			system("cls");
			break;
		default:
			exit(EXIT_FAILURE);
			break;
		}
	}
}

void Menu::wypisz_znalezione_dane(std::vector <Student>& lista_stundetow, int i) {
	cout << "Imie: " << lista_studentow[i].imie << " Nazwisko: " << lista_studentow[i].imie << endl;
	cout << "Numer legitymacji: " << lista_studentow[i].numer_legitymacji << endl;
	cout << "Ocena z fizyki: " << lista_studentow[i].ocena_fizyka << endl;
	cout << "Ocena z analizy: " << lista_studentow[i].ocena_analiza << endl;
	cout << "Ocena z informatyki: " << lista_studentow[i].ocena_informatyka << endl;
	cout << "Ocena z algebry: " << lista_studentow[i].ocena_algebra << endl;
	cout << "Ocena z angielskiego: " << lista_studentow[i].ocena_angielski << endl;
}

int Menu::szukajNazwisko(string& szukaj) {
	size_t capacity = lista_studentow.size();
	for (int i = 0; i < capacity; i++)
		if (lista_studentow[i].nazwisko == szukaj)
			return i;
	system("cls");
	cout << "Nie ma takiego studenta!!!" << endl;
	return -1;
}

int Menu::szukajLegitymacje(unsigned int& szukaj) {
	size_t capacity = lista_studentow.size();
	for (int i = 0; i < capacity; i++)
		if (lista_studentow[i].numer_legitymacji == szukaj)
			return i;
	system("cls");
	cout << "Nie ma w dzienniku studenta o takim numerze !!!" << endl;
	return -1;
}

void Menu::zmien_oceny(std::vector <Student>& lista_studentow, int i) {
	cout << "Wprowadz ocene z fizyki: " << endl;
	while (!(cin >> lista_studentow[i].ocena_fizyka) || lista_studentow[i].ocena_fizyka < 1 || lista_studentow[i].ocena_fizyka >6) {
		bufor();
		cout << "Wprowadz ocene ponownie: ";
	}
	cout << "Wprowadz ocene z analizy: " << endl;
	while (!(cin >> lista_studentow[i].ocena_analiza) || lista_studentow[i].ocena_analiza < 1 || lista_studentow[i].ocena_analiza>6) {
		bufor();
		cout << "Wprowadz ocene ponownie: ";
	}
	cout << "Wprowadz ocene z informatyki: " << endl;
	while (!(cin >> lista_studentow[i].ocena_informatyka) || lista_studentow[i].ocena_informatyka < 1 || lista_studentow[i].ocena_informatyka>6) {
		bufor();
		cout << "Wprowadz ocene ponownie: ";
	}
	cout << "Wprowadz ocene z algebry: " << endl;
	while (!(cin >> lista_studentow[i].ocena_algebra) || lista_studentow[i].ocena_algebra < 1 || lista_studentow[i].ocena_algebra>6) {
		bufor();
		cout << "Wprowadz ocene ponownie: ";
	}
	cout << "Wprowadz ocene z angielskiego: " << endl;
	while (!(cin >> lista_studentow[i].ocena_angielski) || lista_studentow[i].ocena_angielski < 1 || lista_studentow[i].ocena_angielski>6) {
		bufor();
		cout << "Wprowadz ocene ponownie: ";
	}
	ZamienDaneWPliku(lista_studentow[i].numer_legitymacji, i);
}

void Menu::dodaj_studenta() {
	string imie, nazwisko;
	unsigned int legitka = 0;
	int ocena_fizyka = 0, ocena_analiza, ocena_informatyka = 0, ocena_algebra = 0, ocena_angielski = 0;
	cout << "Wprowadz imie studenta" << endl;
	getline(cin, imie);
	cout << "Wprowadz nazwisko studenta" << endl;
	getline(cin, nazwisko);
	cout << "Wprowadz nr legitymacji studenta" << endl;
	while (!(cin >> legitka) || legitka < 100) {
		bufor();
		cout << "Wprowadz indeks ponownie: ";
	}
	cout << "Wprowadz ocene z fizyki: " << endl;
	while (!(cin >> ocena_fizyka) || ocena_fizyka < 1 || ocena_fizyka>6) {
		bufor();
		cout << "Wprowadz ocene ponownie: ";
	}
	cout << "Wprowadz ocene z analizy: " << endl;
	while (!(cin >> ocena_analiza) || ocena_analiza < 1 || ocena_analiza>6) {
		bufor();
		cout << "Wprowadz ocene ponownie: ";
	}
	cout << "Wprowadz ocene z informatyki: " << endl;
	while (!(cin >> ocena_informatyka) || ocena_informatyka < 1 || ocena_informatyka>6) {
		bufor();
		cout << "Wprowadz ocene ponownie: ";
	}
	cout << "Wprowadz ocene z algebry: " << endl;
	while (!(cin >> ocena_algebra) || ocena_algebra < 1 || ocena_algebra>6) {
		bufor();
		cout << "Wprowadz ocene ponownie: ";
	}
	cout << "Wprowadz ocene z angielskiego: " << endl;
	while (!(cin >> ocena_angielski) || ocena_angielski < 1 || ocena_angielski>6) {
		bufor();
		cout << "Wprowadz ocene ponownie: ";
	}
	imie[0] = toupper(imie[0]);
	nazwisko[0] = toupper(nazwisko[0]);
	lista_studentow.push_back(Student(imie, nazwisko, legitka, ocena_fizyka, ocena_analiza, ocena_informatyka, ocena_algebra, ocena_angielski));
	DodajDoPliku(imie, nazwisko, legitka, ocena_fizyka, ocena_analiza, ocena_informatyka, ocena_algebra, ocena_angielski);
}

void Menu::DodajDoPliku(string& im, string& nazw, unsigned int& nr_leg, int& o_fizyka, int& o_analiza, int& o_informatyka, int& o_algebra, int& o_angielski) {
	plik << "Imie: " << im << " Nazwisko: " << nazw << endl;
	plik << "Numer legitymacji: " << nr_leg << endl;
	plik << "Ocena z fizyki: " << o_fizyka << endl;
	plik << "Ocena z analizy: " << o_analiza << endl;
	plik << "Ocena z informatyki: " << o_informatyka << endl;
	plik << "Ocena z algebry: " << o_algebra << endl;
	plik << "Ocena z angielskiego: " << o_angielski << endl;
	plik << endl;
}

void Menu::wypisz_studenta() {
	linia();
	for (auto x : lista_studentow) {
		cout << "Imie: " << x.imie << " Nazwisko: " << x.nazwisko << endl;
		cout << "Numer legitymacji: " << x.numer_legitymacji << endl;
		cout << "Ocena z fizyki: " << x.ocena_fizyka << endl;
		cout << "Ocena z analizy: " << x.ocena_analiza << endl;
		cout << "Ocena z informatyki: " << x.ocena_informatyka << endl;
		cout << "Ocena z algebry: " << x.ocena_algebra << endl;
		cout << "Ocena z angielskiego: " << x.ocena_angielski << endl;
		cout << endl;
	}
	linia();
}

bool Menu::SprawdzPoprawnoscDanych() {
	std::vector <unsigned int> poprawne_dane;
	std::fstream plik2;
	otworz_plik(plik2);

	string imie{};
	unsigned int numer_legitymacji{};
	string nazwisko{};
	int ocena_fizyka{};
	int ocena_analiza{};
	int ocena_informatyka{};
	int ocena_algebra{};
	int ocena_angielski{};
	char ch{};

	while (!plik.eof()) {
		pomin_wyraz();
		plik >> imie;
		plik.get(); // pomin spacje
		pomin_wyraz();
		plik >> nazwisko;
		plik.get(); // pomin entera
		pomin_znaki();
		plik >> numer_legitymacji;
		poprawne_dane.push_back(numer_legitymacji);
		plik.get(); // pomin entera
		for (int i = 0; i<int(poprawne_dane.size()) - 1; i++) {
			if (poprawne_dane[i] == numer_legitymacji) {
				return false;
			}
		}
		pomin_znaki();
		plik >> ocena_fizyka;
		plik.get(); // pomin entera
		pomin_znaki();
		plik >> ocena_analiza;
		plik.get(); // pomin entera
		pomin_znaki();
		plik >> ocena_informatyka;
		plik.get(); // pomin entera
		pomin_znaki();
		plik >> ocena_algebra;
		plik.get(); // pomin entera
		pomin_znaki();
		plik >> ocena_angielski;
		ch = plik.get(); // pomin entera
		ch = plik.get(); // pobierz nowa linie
		ch = plik.get(); // pobierz EOF
	}
	plik2.close();
	return true;
}