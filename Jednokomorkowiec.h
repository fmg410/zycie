#pragma once
#include "Istota.h"
#include <vector>
#include <memory>

template <typename T>
class Jednokomorkowiec : public Istota
{
protected:
	float rozmiar;
	std::vector<unsigned char> genom;

	virtual void mutuj()
    {
        int i = 0;
        for (auto&& g : genom)
        {
            if (i % 10 == 1)
                g = g * 3 % 4;
            i++;
        }
    }

public:
	friend std::vector<T> operator*(const T& j, const int ilosc)
    {
        std::vector<T> potomstwo(ilosc, j);
        for (auto&& p : potomstwo)
        {
            p.mutuj();
        }
        return potomstwo;
    }

public:
    virtual ~Jednokomorkowiec() {}
};

