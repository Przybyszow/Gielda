#ifndef GIELDA_OBIEKTY_TRANSAKCJI_H__
#define GIELDA_OBIEKTY_TRANSAKCJI_H__

struct Spolka
{
	enum class Typ {
		PRZEMYSL_BUDOWLANY    = 0xFF,
		PRZEMYSL_SPOZYWCZY    = 0xFE,
		PRZEMYSL_ENERGETYCZNY = 0xFD,
		BANKOWOSC             = 0xFC,
		UBEZPIECZENIA         = 0xFB
	} typ_spolki;

	const char* nazwa;
	unsigned int wartosc_akcji;
	unsigned int dostepne_akcje;
};

struct Waluta
{
	const char* nazwa;
	float wartosc;
};

#endif // GIELDA_OBIEKTY_TRANSAKCJI_H__
