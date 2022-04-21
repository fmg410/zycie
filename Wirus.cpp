#include "Wirus.h"
#include "AnimalPool.h"
#include "Istota.h"

void Wirus::iteruj()
{
	koordynaty.move();
	if (!nosiciel)
	{
		std::vector<Byt*> pasujace = AnimalPool::bytyWZasiegu(Koordynaty{ koordynaty.x - 1, koordynaty.y - 1 }, Koordynaty{ koordynaty.x + 1, koordynaty.y + 1 });
		for (int i = 0; i < pasujace.size(); i++)
		{
			int r = rand() % pasujace.size();
			if (dynamic_cast<Istota*>(pasujace.at(r)) && dynamic_cast<Istota*>(pasujace.at(r))->getCzyZyje())
			{
				nosiciel = pasujace.at(r);
				break;
			}

		}
	}
	if (nosiciel)
	{
		if (czasReprodukcji > 0)
			czasReprodukcji--;
		else if(czasReprodukcji == 0 && (dynamic_cast<Istota*>(nosiciel) && dynamic_cast<Istota*>(nosiciel)->getCzyZyje()))
		{
			dynamic_cast<Istota*>(nosiciel)->zabij();
			for (int i = 0; i < 4; i++)
			{
				std::unique_ptr<Byt> w = std::make_unique<Wirus>();
				(*w).koordynaty.x = nosiciel->koordynaty.x;
				(*w).koordynaty.y = nosiciel->koordynaty.y;
				AnimalPool::dodaj(std::move(w));
			}
		}
	}
}
