#pragma once
#include "Byt.h"

class Wirus : public Byt
{
protected:
	int czasReprodukcji = 10;
	Byt* nosiciel = nullptr;
	
public:
	void iteruj() override;
	virtual ~Wirus() {}
};
