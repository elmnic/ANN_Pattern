#pragma once
#include "Neuron.h"
struct Bias : public Neuron
{
public:
	virtual float activation(float input)
	{
		return -1.0f;
	}
};

