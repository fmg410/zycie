#include "Bakteria.h"
#include "AnimalPool.h"

void Bakteria::iteruj()
{
	if(getCzyZyje())
		koordynaty.move();
	if (wiek > 50)
		zabij();
	else
		wiek++;
	if (getCzyZyje() && (wiek == 20))
	{
			auto p = (*this) * 3;
			for (auto& a : p)
			{
				AnimalPool::dodaj(std::make_unique<Bakteria>(a));
			}
	}
}

Bakteria::Bakteria(const Bakteria& b)
{
	genom = b.genom;
	koordynaty = b.koordynaty;
	wiek = 0;
}
