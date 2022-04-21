#pragma once
#include "Byt.h"

class Istota : public Byt
{
private:
	bool czyZyje = true;

protected:

public:
	virtual void zabij() { czyZyje = false; };
	bool getCzyZyje() { return czyZyje; }
	virtual ~Istota() {}
};
