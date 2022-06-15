
#include <iostream>
#include <string>
#include <cstdlib>
#include <windows.h>
#include "klient.h"
#include "Data.h"
#include "zamowienie.h"
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;
const int cena = 25; // zmienna typu const przechowuje cene ktora jest uzywana
					 // w calym programie i nie zmienia sie

ostream& operator <<(ostream& ekran, klient& w)
{
	ekran << "Klient\n";
	cout << "ID ";
	ekran << w.get_id();
	cout << "\nImie ";
	ekran << w.get_imie();
	cout << "\nNazwisko ";
	ekran << w.get_nazwisko();
	cout << "\n\n";
	return ekran;
}

ostream& operator <<(ostream& ekran2, Data& w2)
{
	ekran2 << w2.get_dzien();
	cout << "-";
	ekran2 << w2.get_miesiac();
	cout << "-";
	ekran2 << w2.get_rok();
	cout << "\n";
	return ekran2;
}

void czekaj(HANDLE y) //funckja symulujaca migracje danych
{
	cout << "0%         100%\n";
	for (int h = 0; h < 15; h++)
	{
		cout << "#";
		Sleep(150);
	}
	SetConsoleTextAttribute(y, FOREGROUND_GREEN);
	cout << "\nOPERACJA ZAKONCZONA POMYSLNIE\n";
	SetConsoleTextAttribute(y, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	system("pause");
}

int main()
{
	fstream plik;
	string linia;
	time_t t = time(0);
	tm* now = localtime(&t);	//zmienne potrzebne do uzyskanania czasu lokalnego
	int dzien = now->tm_mday;
	int miesiac = (now->tm_mon + 1);
	int rok = now->tm_year + 1900;

	klient klienci[10];
	Data daty[10];
	Data data_dzis;
	data_dzis.ustaw(dzien, miesiac, rok);
	bool gotowe = true;

	zamowienie* TAB;
	TAB = new zamowienie[10];      //program przyjmuje maksymalnie 10 zamowien oraz do 10 klientow

	int ilosc_kl = 0;
	int ilosc_zam = 0;
	int sztuki = 0;
	int id_k = -1;
	int x = 0;
	char y = ' ';
	char z;
	HANDLE hOut; //stworzenie uchwytu pozwoli na zmiane koloru czcionki
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//ponizej zmienne potrzebne do wczytywania danych z pliku
	int nr_linii = 1;
	int i = 0;
	int licz = 0;
	int id_zam;
	klient kl;
	int d;
	int m;
	int r;
	int d2;
	int m2;
	int r2;
	Data data_z_n;
	Data data_r_n;
	int ilosc_n;
	int gotow;

	int id_klienta = 0;  // zmienne potrzebne wprowadzania danych z standardowego wejscia
	char imie_n[20];
	char nazwisko_n[20];

	do
	{
		system("cls");  // struktura case ktora dobrze sprawuje sie jako menu
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
		cout << "        MENU\n";
		cout << "=====================\n";
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		cout << "1 - dodac zamowienie\n";
		cout << "2 - dodac klienta\n";
		cout << "3 - wyswietl zamowienia\n";
		cout << "4 - wyswietl klienta\n";
		cout << "5 - oznacz zamowienie jako gotowe\n";
		cout << "6 - filtrowanie zamowien\n";
		cout << "7 - wyswietl klientow\n";
		cout << "8 - zapisz baze\n";
		cout << "9 - wczytaj baze\n";
		cout << "\nq - wyjsc\n";
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
		cout << "=====================\n";
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		z = getchar();
		switch (z)
		{
		case '1':
			cout << "\nDODAWANIE NOWEGO ZAMOWIENIA";
			cout << "                        q - wroc\n";
			cout << "podaj ID klienta\n";
			cin >> id_k;
			if (id_k != 0)
			{
				cout << "podaj ilosc\n";
				cin >> sztuki;
				TAB[ilosc_zam].TWORZ_ZAMOWIENIE(ilosc_zam + 1, klienci[id_k - 1], data_dzis, data_dzis, sztuki);
				ilosc_zam++;
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
				cout << "=====================\n";
				cout << "DODANO POMYSLNIE\n";
				cout << "=====================\n";
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				system("pause");
				id_k = 0;
			}
			cin.clear();  //wywolanie tych funckji jest potrzebne, poniewaz znaki
			cin.ignore(); //zostawaly w buforze standardowego wejscia i program 
			break;        //niekontrolowanie wywolywal kolejne instrukje case
		case '2':
		{
			cout << "\n ";
			cout << "DODAWANIE NOWEGO KLIENTA)";
			cout << "                        q - wroc\n";
			cout << "Podaj imie\n";
			char imie[20];
			cin >> imie;
			if (imie[0] != 'q')
			{
				cout << "Podaj nazwisko\n";
				char nazwisko[20];
				cin >> nazwisko;
				klienci[ilosc_kl].wpisz(ilosc_kl + 1, imie, nazwisko);
				ilosc_kl++;
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN); //zmiana koloruna zielony,
				cout << "=====================\n";				//a nastepnie na pierwotny
				cout << "DODANO POMYSLNIE\n";
				cout << "=====================\n";
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				system("pause");
			}
			break;
		}
		case '3':
			system("cls");
			cout << "\nWYSWIETL ZAMOWIENIA\n";
			cout << "====================\n\n";
			if (ilosc_zam > 0)
			{


				for (int i = 0; i < ilosc_zam; i++)
				{
					cout << "====================\n";
					cout << "ID zamowienia " << (TAB + i)->get_id_z();
					cout << endl << endl;
					(TAB + i)->get_klient_z().wypisz();
					cout << "\nData zamowienia: ";
					(TAB + i)->wypisz_date_z();
					cout << "\nData realizacji: ";
					(TAB + i)->wypisz_date_r();
					cout << "\nilosc: ";
					cout << (TAB + i)->get_ilosc();
					cout << "\nwartosc: ";
					cout << ((TAB + i)->get_ilosc()) * cena;
					cout << "\nstatus: ";
					if ((TAB + i)->get_czy_gotowe() == true)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
						cout << "GOTOWE\n";
						SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					}
					else
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						cout << "NIEGOTOWE\n";
						SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					}
					cout << "====================\n\n\n";
				}
			}
			else
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout << "BRAK ZAMOWIEN\n";
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			}
			system("pause");
			break;


		case '4':
			cout << "\nWYSWIETL KLIENTA\n";
			cout << "Podaj ID klienta\n";
			cin >> x;
			if ((x == 0) || (x > ilosc_kl))
			{
				cin.clear();
				cin.ignore();
				cout << "Podano nieprawidlowy znak!";
				Sleep(1000);
				break;
			}
			system("cls");
			cout << "\nID klienta: " << x << endl;
			klienci[x - 1].wypisz();

			for (int i = 0; i < ilosc_zam; i++)
			{
				if ((TAB + i)->get_klient_z().get_id() == x)
				{
					cout << "\nID zamowienia " << (TAB + i)->get_id_z();
					cout << endl;
					cout << "\nData zamowienia: ";
					(TAB + i)->wypisz_date_z();
					cout << "\nData realizacji: ";
					(TAB + i)->wypisz_date_r();
					cout << "\nilosc: ";
					cout << (TAB + i)->get_ilosc();
					cout << "\nwartosc: ";
					cout << ((TAB + i)->get_ilosc()) * cena;
					cout << "\nstatus: ";
					if ((TAB + i)->get_czy_gotowe() == true)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
						cout << "GOTOWE\n\n";
						SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					}
					else
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						cout << "NIEGOTOWE\n\n";
						SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					}
					cout << "\n====================\n";
				}
			}

			system("pause");
			break;

		case '5':
			cout << "\nOZNACZANIE JAKO GOTOWE";
			cout << "                        q - wroc\n";
			cout << "Podaj ID zamowienia\n";
			cin >> x;
			if ((x != 0) && (x <=ilosc_zam))
			{
				(TAB + x - 1)->gotowe_f();
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
				cout << "\nZMIENIONO STATUS ZAMOWIENIA NUMER " << (TAB + x - 1)->get_id_z() << "  NA GOTOWE\n";
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				system("pause");
			}
			else
			{
				cin.clear();
				cin.ignore();
				cout << "Podano nieprawodlowy znak!";
				Sleep(1000);
			}
			break;

		case '6':
			cout << "\nFILTROWANIE ZAMOWIEN";
			cout << "                        q - wroc\n";
			cout << "GOTOWE ZAMOWIENIA wcisnij G\n";
			cout << "GOTOWE ZAMOWIENIA wcisnij N\n";
			cin >> y;
			if ((y == 'G') || (y == 'g'))
			{
				system("cls");
				cout << "\nWYSWIETL ZAMOWIENIA GOTOWE\n";
				cout << "====================\n";
				for (int i = 0; i < ilosc_zam; i++)
				{
					if ((TAB + i)->get_czy_gotowe() == true)
					{
						cout << "ID zamowienia " << (TAB + i)->get_id_z();
						cout << endl << endl;
						(TAB + i)->get_klient_z().wypisz();
						cout << "\nData zamowienia: ";
						(TAB + i)->wypisz_date_z();
						cout << "\nData realizacji: ";
						(TAB + i)->wypisz_date_r();
						cout << "\nilosc: ";
						cout << (TAB + i)->get_ilosc();
						cout << "\nwartosc: ";
						cout << ((TAB + i)->get_ilosc()) * cena;
						cout << "\nstatus: ";
						if ((TAB + i)->get_czy_gotowe() == true)
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
							cout << "GOTOWE\n\n";
							SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						}
						else
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << "NIEGOTOWE\n\n";
							SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						}
						cout << "\n====================\n";
					}
				}
			}
			else if ((y == 'N') || (y == 'n'))
			{
				system("cls");
				cout << "\nWYSWIETL ZAMOWIENIA NIEGOTOWE\n";
				cout << "====================\n";
				for (int i = 0; i < ilosc_zam; i++)
				{
					if ((TAB + i)->get_czy_gotowe() == false)
					{
						cout << "ID zamowienia " << (TAB + i)->get_id_z();
						cout << endl << endl;
						(TAB + i)->get_klient_z().wypisz();
						cout << "\nData zamowienia: ";
						(TAB + i)->wypisz_date_z();
						cout << "\nData realizacji: ";
						(TAB + i)->wypisz_date_r();
						cout << "\nilosc: ";
						cout << (TAB + i)->get_ilosc();
						cout << "\nwartosc: ";
						cout << ((TAB + i)->get_ilosc()) * cena;
						cout << "\nstatus: ";
						if ((TAB + i)->get_czy_gotowe() == true)
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
							cout << "GOTOWE\n\n";
							SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						}
						else
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << "NIEGOTOWE\n\n";
							SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						}
						cout << "\n====================\n";
					}
				}
			}
			else if (y == 'q') break;
			else
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				cout << "PODANO NIEPRAWIDLOWY ZNAK\n";
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "NASTAPI PRZEKIEROWANIE DO MENU\n";
			}
			system("pause");
			break;

		case '7':
			system("cls");
			cout << "\nWYSWIETL KLIENTOW\n";
			if (ilosc_kl > 0)
			{

				for (int i = 0; i < ilosc_kl; i++)
				{
					cout << "\n==================";
					cout << "\nID klienta: " << (klienci + i)->get_id() << endl;
					(klienci + i)->wypisz();
					cout << "==================\n";
				}
			}
			else
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout << "NIE MA KLIENTOW DO WYSWIETLENIA\n";
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			}
			system("pause");
			break;

		case '8':
			cout << "\nZAPISYWANIE\n";
			plik.open("baza_zamowienia.txt", ios::out);

			if (ilosc_zam > 0)
			{
				// zapisywanie danych z programu do pliku
				for (int i = 0; i < ilosc_zam; i++)
				{

					plik << (TAB + i)->get_id_z() << endl;
					plik << (TAB + i)->get_klient_z().get_id() << endl;
					plik << (TAB + i)->get_klient_z().get_imie() << endl;
					plik << (TAB + i)->get_klient_z().get_nazwisko() << endl;
					plik << (TAB + i)->get_data_z().get_dzien() << endl;
					plik << (TAB + i)->get_data_z().get_miesiac() << endl;
					plik << (TAB + i)->get_data_z().get_rok() << endl;
					plik << (TAB + i)->get_data_r().get_dzien() << endl;
					plik << (TAB + i)->get_data_r().get_miesiac() << endl;
					plik << (TAB + i)->get_data_r().get_rok() << endl;
					plik << (TAB + i)->get_ilosc() << endl;
					if ((TAB + i)->get_czy_gotowe() == true)
					{
						plik << 1 << endl;
					}
					else
					{
						plik << 0 << endl;
					}
				}
				plik.close();
				czekaj(hOut);
			}
			break;

		case '9':							//wczytywanie danych z pliku do programu
			cout << "\nwczytywanie\n";
			plik.open("baza_zamowienia.txt", ios::in);
			if (plik.good() == false)
			{
				cout << "plik nie istnieje";
				exit(0);
			}

			while (getline(plik, linia))
			{

				switch (nr_linii)
				{
				case 1:
					id_zam = atoi(linia.c_str());
					break;
				case 2:
					id_klienta = atoi(linia.c_str());
					break;
				case 3:
					strcpy(imie_n, linia.c_str());
					break;
				case 4:
					strcpy(nazwisko_n, linia.c_str());
					kl.set_id(id_klienta);
					kl.set_imie(imie_n);
					kl.set_nazwisko(nazwisko_n);
					break;
				case 5:
					d = atoi(linia.c_str()); // funkcja konwerujaca string na integer
					break;
				case 6:
					m = atoi(linia.c_str());
					break;
				case 7:
					r = atoi(linia.c_str());
					data_z_n.ustaw(d, m, r);
					break;
				case 8:
					d2 = atoi(linia.c_str());
					break;
				case 9:
					m2 = atoi(linia.c_str());
					break;
				case 10:
					r2 = atoi(linia.c_str());
					data_r_n.ustaw(d2, m2, r2);
					break;
				case 11:
					ilosc_n = atoi(linia.c_str());
					break;
				case 12: // po wczytaniu danych z pliku zostaje wywolana funckja tworzaca zamowienie
					TAB[ilosc_zam].TWORZ_ZAMOWIENIE(id_zam, kl, data_z_n, data_r_n, ilosc_n);
					ilosc_zam++;
					gotow = atoi(linia.c_str());
					if (gotow == 1)
					{
						TAB[ilosc_zam - 1].gotowe_f();
					}
					break;
				}
				if (nr_linii == 12) nr_linii = 0; //kasowanie licznika i wczytywanie danych donastepnego zamowienia
				nr_linii++;
				i++;

			}
			plik.close();
			czekaj(hOut);
			break;

		case 'q':
			system("cls");
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
			cout << "\n\n\n==============================\n";
			cout << "   KONIEC DZIALANIA PROGRAMU";
			cout << "\n==============================\n\n\n";
			SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			system("pause");
			return 0;
		}
	} while (1);
	delete[] TAB; //zwolnienie pamieci
}

