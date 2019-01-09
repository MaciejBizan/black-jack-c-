#include <iostream>
#include <time.h>

using namespace std;
//todo
//inercja-czasy oczekiwania
//otwarcie okna jako zaklocenie

class CKarta
{

public:
	friend class CTalia;
	CKarta();
	//CKarta(CKarta &karta);
	~CKarta();
	void drukujKarte();
	int dajWartosc();

private:
	int wartosc;
	char kolor;
	char symbol;
};
CKarta::CKarta()
{
}

CKarta::~CKarta()
{
}
void CKarta::drukujKarte()
{
	cout << wartosc << endl;
	
}
int CKarta::dajWartosc()
{
	return wartosc;
}


class CTalia
{
public:
	friend class CGracz;
	friend class CGraczCzlowiek;
	CTalia();
	~CTalia();
	CKarta **_ptrTabKart;
	//CKarta *_ptrTabKart[52];
	void tasuj();
	CKarta *dajKarte();
	void drukujTalie();
	void inkrementujIloscZabranych();
private:
	int ileKartZabrano;

};
CTalia::CTalia()
{
	ileKartZabrano = 0;

	//stworzenie talii
	_ptrTabKart = new CKarta*[52];
	//*_ptrTabKart = new CKarta[52];
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 10; i++)
		{
			_ptrTabKart[i + j * 10] = new CKarta;
			_ptrTabKart[i + j * 10]->wartosc = i+2;
			_ptrTabKart[i + j * 10]->symbol = _ptrTabKart[i + j * 10]->wartosc + '0';
			switch (j)
			{
			case 0:
				_ptrTabKart[i + j * 10]->kolor = 'p';
				break;
			case 1:
				_ptrTabKart[i + j * 10]->kolor = 't';
				break;
			case 2:
				_ptrTabKart[i + j * 10]->kolor = 'k';
				break;
			case 3:
				_ptrTabKart[i + j * 10]->kolor = 's';
				break;
			}
		}

	}
	for (int j = 40; j < 44; j++)
	{
		
			_ptrTabKart[j] = new CKarta;
			_ptrTabKart[j]->wartosc = j-38;
			if (_ptrTabKart[j]->wartosc == 2)
			{
				_ptrTabKart[j]->symbol = 'w';
			}
			if (_ptrTabKart[j]->wartosc == 3)
			{
				_ptrTabKart[j]->symbol = 'd';
			}
			if (_ptrTabKart[j]->wartosc == 4)
			{
				_ptrTabKart[j]->symbol = 'k';
			}
			
			_ptrTabKart[j]->kolor = 'p';	
	}
	for (int j = 43; j < 47; j++)
	{

		_ptrTabKart[j] = new CKarta;
		_ptrTabKart[j]->wartosc = j - 41;

		_ptrTabKart[j]->kolor = 'k';
		if (_ptrTabKart[j]->wartosc == 2)
		{
			_ptrTabKart[j]->symbol = 'w';
		}
		if (_ptrTabKart[j]->wartosc == 3)
		{
			_ptrTabKart[j]->symbol = 'd';
		}
		if (_ptrTabKart[j]->wartosc == 4)
		{
			_ptrTabKart[j]->symbol = 'k';
		}
	}
	for (int j = 46; j < 50; j++)
	{

		_ptrTabKart[j] = new CKarta;
		_ptrTabKart[j]->wartosc = j - 44;

		_ptrTabKart[j]->kolor = 't';
		if (_ptrTabKart[j]->wartosc == 2)
		{
			_ptrTabKart[j]->symbol = 'w';
		}
		if (_ptrTabKart[j]->wartosc == 3)
		{
			_ptrTabKart[j]->symbol = 'd';
		}
		if (_ptrTabKart[j]->wartosc == 4)
		{
			_ptrTabKart[j]->symbol = 'k';
		}
	}
	for (int j = 49; j < 52; j++)
	{

		_ptrTabKart[j] = new CKarta;
		_ptrTabKart[j]->wartosc = j - 47;

		_ptrTabKart[j]->kolor = 's';
		if (_ptrTabKart[j]->wartosc == 2)
		{
			_ptrTabKart[j]->symbol = 'w';
		}
		if (_ptrTabKart[j]->wartosc == 3)
		{
			_ptrTabKart[j]->symbol = 'd';
		}
		if (_ptrTabKart[j]->wartosc == 4)
		{
			_ptrTabKart[j]->symbol = 'k';
		}
	}
	//koniec tworzenia talii
	tasuj();

}
CTalia::~CTalia()
{
	for (int i = 0; i<51; i++)
	{
		cout << "";
		delete _ptrTabKart[i];
		//delete _ptrTabKart;
	}
	delete[] _ptrTabKart;
	cout << endl;
}
void CTalia::tasuj()
{
	//CKarta tymczasowa;
	CKarta *tymczasowa;
	int r;

	for (int i = 0; i<50; i++)
	{
		do {
			r = rand() % 52;
			tymczasowa = _ptrTabKart[r];
		} while (i == r);

		_ptrTabKart[r] = _ptrTabKart[i];
		_ptrTabKart[i] = tymczasowa;


	}
	cout << endl;

}
CKarta *CTalia::dajKarte()
{

	
	inkrementujIloscZabranych();
	return _ptrTabKart[51 - ileKartZabrano+1];
	


	/*
		CKarta *tymczasowa;
	//tymczasowa = new CKarta(;int i = 51;
	while (_ptrTabKart[i] == nullptr)
	{
		//tymczasowa = _ptrTabKart[i];
		tymczasowa = new CKarta(*_ptrTabKart[i]);
		i--;
	}// tu tez

	delete _ptrTabKart[i];//zrobic ten sam myk, co poprzednim oczku nowy wskaznik na to gowno, zeby bylo _ptrTab+i
	_ptrTabKart[i] = nullptr;
	return tymczasowa;
	*/
}

void CTalia::drukujTalie()
{
	for (int i = 0; i<52; i++)
	{
		//_ptrTabKart[0]->drukujKarte();
		cout << i<<"\t";
		_ptrTabKart[i]->drukujKarte();
		cout << endl;
	}
}
void CTalia::inkrementujIloscZabranych()
{
	ileKartZabrano++;
	
}



class CGracz
{
public:
	
	CGracz(int ile=17,int wynik=0);
	~CGracz();
	
	int dajWynik();
	void dobierzKarte(CKarta *karta);
	void czyWynikWiekszy();
	bool czySpasowal();

	
protected:
	void aktualizujWynik(CKarta *karta);
	CKarta *ptrReka[10];
	int _grajIle;
	bool _czySpasowal;
	int _wynik;
};

CGracz::CGracz(int ile, int wynik):_grajIle(ile),_wynik(wynik)
{
	_czySpasowal = 0;
	//*ptrReka = new CKarta[10];
	for (int i = 0; i < 10; i++)
	{
		ptrReka[i] = nullptr;
	}
}
CGracz::~CGracz()
{
}
void CGracz::aktualizujWynik(CKarta *karta)
{
	_wynik+=karta->dajWartosc();

}
void CGracz::dobierzKarte(CKarta *karta)
{
	if (_czySpasowal == 0)
	{
		int i = 0;
		while (ptrReka[i] != nullptr)
		{
			i++;
		}

		if (ptrReka[i] == nullptr)
		{

			ptrReka[i] = karta;

		}
		aktualizujWynik(karta);
		cout << "";
	}
	
	
	
}
int CGracz::dajWynik()
{
	return _wynik;
}
void CGracz::czyWynikWiekszy()
{
	if (_wynik >= _grajIle)
	{
		_czySpasowal = 1;
	}
}
bool CGracz::czySpasowal()
{
	if (_czySpasowal == 0)
		return 0;
	else
		return 1;
}
class CGraczCzlowiek :public CGracz
{
public:
	CGraczCzlowiek();
	~CGraczCzlowiek();
	void pasuj(int p);
private:

};
CGraczCzlowiek::CGraczCzlowiek()
{
}
CGraczCzlowiek::~CGraczCzlowiek()
{
}
void CGraczCzlowiek::pasuj(int p)
{
	_czySpasowal =p;
}


class COczko
{
public:
	COczko();
	~COczko();
	void run();
private:
	CTalia *_talia;
	CGracz *_gracz;
	CGraczCzlowiek *_czlowiek;
};
COczko::COczko()
{

	_talia = new CTalia;
	_gracz = new CGracz;
	_czlowiek = new CGraczCzlowiek;
}
COczko::~COczko()
{
	cout << endl;
	delete _talia;
	cout << endl;
	delete _gracz;
	cout << endl;
	delete _czlowiek;
	cout << endl;
}
void COczko::run()
{
	int p = 0;
	cout << "witaj w oczku\n\n\n";
	do {

		if (_gracz->czySpasowal() != 1)
		{
			_gracz->dobierzKarte(_talia->dajKarte());
			_gracz->czyWynikWiekszy();
		}
		
		cout<<"\n\nwynik krupiera: "<<_gracz->dajWynik()<<endl;
		


		if (_czlowiek->czySpasowal() != 1)
		{
			_czlowiek->dobierzKarte(_talia->dajKarte());
			cout << "twoj wynik: " << _czlowiek->dajWynik() << endl;
			cout << "grasz dalej?(0)t/1)n)\n";
			cin >> p;
			_czlowiek->pasuj(p);
		}
		if (_czlowiek->dajWynik() > 21)
		{
			_czlowiek->pasuj(1);
		}
		
		
		


	} while (!(_gracz->czySpasowal() != 0 && _czlowiek->czySpasowal() != 0));
	if ((_czlowiek->dajWynik() <= 21) && (_gracz->dajWynik() <= 21)&&(_czlowiek->dajWynik() > _gracz->dajWynik()))
	{
		cout << "\n\nwynik krupiera: " << _gracz->dajWynik() << endl;
		cout << "twoj wynik: " << _czlowiek->dajWynik() << endl;
		cout << "wygrales!\n";
	}
	else if ((_czlowiek->dajWynik() <= 21) && (_gracz->dajWynik() > 21))
	{
		cout << "\n\nwynik krupiera: " << _gracz->dajWynik() << endl;
		cout << "twoj wynik: " << _czlowiek->dajWynik() << endl;
		cout << "wygrales!\n";
	}
	else if ((_czlowiek->dajWynik() > 21) && (_gracz->dajWynik() <= 21))
	{
		cout << "\n\nwynik krupiera: " << _gracz->dajWynik() << endl;
		cout << "twoj wynik: " << _czlowiek->dajWynik() << endl;
		cout << "wygral krupier\n";
	}
	else if ((_czlowiek->dajWynik() <= 21) && (_gracz->dajWynik() <= 21) && (_czlowiek->dajWynik() < _gracz->dajWynik()))
	{
		cout << "\n\nwynik krupiera: " << _gracz->dajWynik() << endl;
		cout << "twoj wynik: " << _czlowiek->dajWynik() << endl;
		cout << "wygral krupier\n";
	}

	else
	{
		cout << "remis\n";

	}

	
	
}

int main()
{
	srand(time(nullptr));
	COczko oczko;
	oczko.run();
	

	return 0;
}
