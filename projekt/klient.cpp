#include "klient.h"
#include <iostream>
#include <string.h>
using namespace std;

int klient::get_id()
{
    return id;
}

const char* klient::get_imie() const
{
    return imie;
}

const char* klient::get_nazwisko() const
{
    return nazwisko;
}

void klient::set_id(int id)
{
    this->id = id;
}

void klient::set_imie(const char* im)
{
    strcpy(imie, im);
}

void klient::set_nazwisko(const char* nazw)
{
    strcpy(nazwisko, nazw);
}

void klient::wypisz() const
{
    cout << "Imie: "<< imie << "\nNazwisko: " << nazwisko<< endl;
}


void klient::wpisz(int n_id, const char* n_imie, const char* n_nazwisko)
{
    id = n_id;
    strcpy(imie, n_imie);
    strcpy(nazwisko, n_nazwisko);
}

klient::klient()
{
    id = 0;
    strcpy(imie, "Okaziciel");
    strcpy(nazwisko, "Okaziciel");
}

klient::klient(int  n_id, const char* n_imie, const char* n_nazwisko)
{
    id = n_id;
    strcpy(imie, n_imie);
    strcpy(nazwisko, n_nazwisko);
}
