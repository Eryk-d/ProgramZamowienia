#pragma once
#include <string.h>
class klient
{
	int id;
	char imie[20];
	char nazwisko[20];
public:
	int get_id();
	const char* get_imie() const;
	const char* get_nazwisko() const;
	void set_id(int id);
	void set_imie(const char* im);
	void set_nazwisko(const char* nazw);
	void wypisz()const;
	void wpisz(int n_id, const char* n_imie, const char* n_nazwisko);
	klient();
	klient(int n_id, const char* n_imie, const char* n_nazwisko);


};

