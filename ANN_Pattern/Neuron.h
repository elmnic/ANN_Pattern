#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
struct Neuron
{
public:
	virtual float activation(float input) = 0;
};

