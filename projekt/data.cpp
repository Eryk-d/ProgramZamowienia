#include "Data.h"
#include <iostream>
using namespace std;

void Data::ustaw(int d, int m, int r)
{
	dzien_z = d;
	miesiac_z = m;
	rok_z = r;
}

int Data::get_dzien() const
{
	return dzien_z;
}

int Data::get_miesiac() const
{
	return miesiac_z;
}

int Data::get_rok() const
{
	return rok_z;
}

void Data::wypisz() const
{
	cout << dzien_z << "-" << miesiac_z << "-" << rok_z;
}

void Data::wpisz()
{
	cout << "Podaj dzien: ";
	cin >> dzien_z;
	cout << "Podaj miesiac: ";
	cin >> miesiac_z;
	cout << "Podaj rok: ";
	cin >> rok_z;

}

Data::Data()
{
	dzien_z = 1;
	miesiac_z = 1;
	rok_z = 2020;
}

void Data::Koryguj()
{
	/*if (miesiac_z == 13)
	{
		miesiac_z = 1;
		rok_z++;
	}
	else if (miesiac_z == 14);
	{
		miesiac_z = 2;
		rok_z++;
	}*/

	switch (miesiac_z)
	{
	case 2:
		if (dzien_z >28)
		{
			dzien_z = 1;
			miesiac_z++;
		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (dzien_z > 30)
		{
			dzien_z = 1;
			miesiac_z++;
		}
		break;
	case 13:
		miesiac_z = 1;
		rok_z++;
		Koryguj();
		break;
	case 14:
		miesiac_z = 2;
		rok_z++;
		Koryguj();
		break;
	}

}