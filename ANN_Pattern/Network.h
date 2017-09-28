#pragma once

#include "Sigmoid.h"
#include "Identity.h"
#include "Bias.h"
#include "Connection.h"

#include <vector>
#include <iostream>

class Network
{
public:
	Network(int inputs, int nrOfLayers, int layerSize, int outputs);
	~Network();
	void printNetwork();
private:
	void connectLayer(std::vector<Neuron*> leftL, std::vector<Neuron*> rightL);
	void setupConnections();

	std::vector<Neuron*> input;
	std::vector<Neuron*> output;
	std::vector<std::vector<Neuron*>> hiddenLayers;

	std::vector<std::vector<Neuron*>> layers;

	std::vector<Connection*> connections;
};

