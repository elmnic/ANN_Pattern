#pragma once
#include "Neuron.h"
struct Sigmoid : public Neuron
{
public:
	virtual float activation(float input)
	{
		return 1.0f / (1.0f + powf(M_E, -input));
	}
};

