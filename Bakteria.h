#pragma once
#include "Jednokomorkowiec.h"

class Bakteria : public Jednokomorkowiec<Bakteria>
{
public:
	virtual void iteruj() override;
	virtual ~Bakteria() {}
	Bakteria() = default;
	Bakteria(const Bakteria& b);
	Bakteria& operator=(const Bakteria& b) = delete;
};

