#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Koordynaty
{
	float x = 0;
	float y = 0;
	void move() { x += ((rand() % 100) - 50 ) / 100.0; y += ((rand() % 100) - 50) / 100.0; }
};

