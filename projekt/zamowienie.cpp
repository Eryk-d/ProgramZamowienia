#include <iostream>
#include "zamowienie.h"
#include "Data.h"
//Data dat;
//klient klio;
int zamowienie::get_id_z() const
{
	return id_z;
}

klient zamowienie::get_klient_z() const
{
	return klient_z;
}

Data zamowienie::get_data_z() const
{
	return data_z;
}

Data zamowienie::get_data_r() const
{
	return data_r;
}

void zamowienie::wypisz_date_z()
{
	data_z.wypisz();
}

void zamowienie::wypisz_date_r()
{
	data_r.wypisz();
}


int zamowienie::get_ilosc() const
{
	return ilosc;
}

bool zamowienie::get_czy_gotowe() const
{
	return gotowe;
}

void zamowienie::gotowe_f()
{
	gotowe = true;
}

zamowienie::zamowienie():klient_z(), data_z(),data_r()
{
	id_z = 0;
	ilosc = 0;
	gotowe = false;
}


zamowienie::zamowienie(int id_z, klient klient_n, Data data_z_n, Data data_r_n, int ilosc):klient_z(klient_n), data_z(data_z_n),data_r(data_r_n)
{
	this->id_z = id_z;
	this->ilosc = ilosc;
	gotowe = false;
}

void zamowienie::TWORZ_ZAMOWIENIE(int id_z, klient klient_n, Data data_z_n, Data data_r_n, int ilosc)
{
	klient_z = klient_n;
	this->id_z = id_z;
	this->ilosc = ilosc;
	gotowe = false;
	data_z = data_z_n;
	data_r.ustaw(data_z_n.get_dzien(), data_z_n.get_miesiac()+2, data_z_n.get_rok());
	data_r.Koryguj();
}


