#pragma once
#include "klient.h"
#include "Data.h"
#include <iostream>
class zamowienie
{
	int id_z;
	klient klient_z;
	Data data_z;
	Data data_r;
	int ilosc;
	bool gotowe;
public:
	int get_id_z() const;
	klient get_klient_z() const;
	Data get_data_z() const;
	Data get_data_r() const;
	void wypisz_date_z();
	void wypisz_date_r();
	int get_ilosc() const;
	bool get_czy_gotowe() const;
	void gotowe_f();
	zamowienie();
	zamowienie(int id_z, klient klient_n, Data data_z_n, Data data_r_n, int ilosc);
	void TWORZ_ZAMOWIENIE(int id_z, klient klient_n, Data data_z_n, Data data_r_n, int ilosc);
};

