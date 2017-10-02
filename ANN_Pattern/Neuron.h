#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include <iostream>
class Connection;
struct Neuron
{
public:
	virtual float activation(float input) = 0;
	virtual float transfer() = 0;
	virtual void setDelta(float newDelta) = 0;
	virtual float getDelta() = 0;
	virtual float getInput() = 0;
	virtual void addConnectionFromL(Connection* left) = 0;
	virtual void addConnectionToR(Connection* right) = 0;
	virtual std::vector<Connection*> getConnectionsToR() = 0;
	virtual std::vector<Connection*> getConnectionsFromL() = 0;

protected:
	float mE = 2.718281828459045;
};

