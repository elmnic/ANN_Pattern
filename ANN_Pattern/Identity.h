#pragma once
#include "Neuron.h"
struct Identity : public Neuron
{
public:
	virtual float activation(float input)
	{
		return input;
	}
};

