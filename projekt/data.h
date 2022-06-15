#pragma once
class Data
{
	int dzien_z;
	int miesiac_z;
	int rok_z;
public:
	void ustaw(int d, int m, int r);
	int get_dzien() const;
	int get_miesiac() const;
	int get_rok() const;
	void wypisz() const;
	void wpisz();
	Data();
	void Koryguj();
};

