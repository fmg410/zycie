#pragma once
#include <vector>
#include <memory>
#include "Byt.h"

class AnimalPool
{
private:
public:
	static std::vector<std::unique_ptr<Byt>> pool; // publiczne dla debuggowania w main, normalnie prywatne
	static std::vector<Byt*> bytyWZasiegu(Koordynaty k1, Koordynaty k2);
	static void dodaj(std::unique_ptr<Byt> p);
	static void iteracja();
};

