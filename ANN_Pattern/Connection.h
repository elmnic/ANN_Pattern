#pragma once
#include "Neuron.h"
struct Connection
{
public:
	Neuron *left;
	Neuron *right;
	float weight;
};

