#pragma once
#include "Neuron.h"
struct Identity : public Neuron
{
public:
	virtual float activation(float input)
	{
		this->input = input;
		output = input;
		//std::cout << "Identity:\n" << "Input: " << input << " Output: " << output << std::endl;
		return output;
	}
	virtual float transfer() { return output; }
	virtual void setDelta(float newDelta) { delta = newDelta; }
	virtual float getDelta() { return delta; }
	virtual float getInput() { return this->input; }

	virtual void addConnectionFromL(Connection* left) { connectionsFromL.push_back(left); }
	virtual void addConnectionToR(Connection* right) { connectionsToR.push_back(right); }
	virtual std::vector<Connection*> getConnectionsFromL() { return connectionsFromL; }
	virtual std::vector<Connection*> getConnectionsToR() { return connectionsToR; }

private:
	float input = 0;
	float output = 0;
	float delta = 0;
	std::vector<Connection*> connectionsFromL;
	std::vector<Connection*> connectionsToR;
};

