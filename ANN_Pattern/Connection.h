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
	float delta = 0;
	float newWeight = 0;
};

