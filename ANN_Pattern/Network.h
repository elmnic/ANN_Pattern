#pragma once

#include "Sigmoid.h"
#include "Identity.h"
#include "Bias.h"
#include "Connection.h"

#include <vector>
#include <iostream>
#include <ctime>
#include <random>
#include <cmath>

class Network
{
public:
	Network(int inputs, int nrOfLayers, int layerSize, int outputs);
	~Network();
	void printNetwork();
	void printOutput();
	void feedForward(); 
	void backpropagate(); 
	void setPattern(int i);
private:
	void connectLayer(std::vector<Neuron*> leftL, std::vector<Neuron*> rightL);
	float derivative(float output);

	float learningRate = 0.001f;

	std::vector<Neuron*> input;
	std::vector<Neuron*> output;
	std::vector<std::vector<Neuron*>> hiddenLayers;
	std::vector<std::vector<Neuron*>> layers;

	std::vector<Connection*> connections;

	std::vector<int> currentPattern;
	std::vector<int> patternX { 1, 0, 0, 1,
								0, 1, 1, 0,
								0, 1, 1, 0,
								1, 0, 0, 1 };

	std::vector<int> patternXBroken { 1, 0, 0, 0,
									  0, 1, 1, 1,
									  0, 1, 1, 0,
									  1, 0, 0, 1 };

	std::vector<int> patternXBrokenExtra { 1, 0, 0, 1,
										   0, 1, 1, 0,
										   0, 1, 1, 0,
										   1, 0, 1, 0 };

	std::vector<int> patternO { 0, 1, 1, 0,
								1, 0, 0, 1,
								1, 0, 0, 1,
								0, 1, 1, 0 };

	std::vector<int> patternOBroken { 0, 1, 1, 0,
									  1, 0, 0, 1,
									  1, 1, 0, 1,
									  0, 0, 1, 0 };

	std::vector<int> patternOBrokenExtra { 0, 1, 0, 0,
										   1, 0, 1, 1,
										   1, 0, 0, 1,
										   0, 1, 1, 0 };


	std::vector<float> currentTarget;
	std::vector<float> targetX { 1.0f, 0.0f };
	std::vector<float> targetO { 0.0f, 1.0f };
};

