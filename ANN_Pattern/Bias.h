#pragma once
#include "Neuron.h"
struct Bias : public Neuron
{
public:
	virtual float activation(float input)
	{
		this->input = input;
		//std::cout << "Bias:\n" << "Input: " << input << " Output: " << -1 << std::endl;
		return -1.0f;
	}
	virtual float transfer() { return -1.0f; }
	virtual void setDelta(float newDelta) { delta = newDelta; }
	virtual float getDelta() { return delta; }
	virtual float getInput() { return this->input; }

	virtual void addConnectionFromL(Connection* left) { connectionsFromL.push_back(left); }
	virtual void addConnectionToR(Connection* right) { connectionsToR.push_back(right); }
	virtual std::vector<Connection*> getConnectionsFromL() { return connectionsFromL; }
	virtual std::vector<Connection*> getConnectionsToR() { return connectionsToR; }
private:
	float input = 0;
	float delta = 0;
	std::vector<Connection*> connectionsFromL;
	std::vector<Connection*> connectionsToR;
};

