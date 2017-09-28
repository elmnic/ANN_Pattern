#pragma once
struct Connection
{
public:
	Connection(Neuron *l, Neuron *r)
	{
		left = l;
		right = r;
	}
	Neuron *left;
	Neuron *right;
	float weight = 0;
};

