#pragma once

#include "Sigmoid.h"
#include "Identity.h"
#include "Bias.h"
#include "Connection.h"

#include <vector>
#include <iostream>
#include <ctime>
#include <random>

class Network
{
public:
	Network(int inputs, int nrOfLayers, int layerSize, int outputs);
	~Network();
	void printNetwork();
	void feedForward();
private:
	void connectLayer(std::vector<Neuron*> leftL, std::vector<Neuron*> rightL);

	std::vector<Neuron*> input;
	std::vector<Neuron*> output;
	std::vector<std::vector<Neuron*>> hiddenLayers;
	std::vector<std::vector<Neuron*>> layers;

	std::vector<Connection*> connections;

	std::vector<int> patternX { 1, 0, 0, 1,
								0, 1, 1, 0,
								0, 1, 1, 0,
								1, 0, 0, 1 };

	std::vector<int> patternO { 0, 1, 1, 0,
								1, 0, 0, 1,
								1, 0, 0, 1,
								0, 1, 1, 0 };
};

