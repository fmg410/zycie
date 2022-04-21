#pragma once
#include "Koordynaty.h"

class Byt
{
protected:
	int wiek = 0;
public:
	Koordynaty koordynaty = {0.f, 0.f};
	virtual void iteruj() = 0;
	virtual ~Byt() {}
};
