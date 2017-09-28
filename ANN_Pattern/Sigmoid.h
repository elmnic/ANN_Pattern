#pragma once
#include "Neuron.h"
struct Sigmoid : public Neuron
{
public:
	virtual float activation(float input)
	{
		output = 1.0f / (1.0f + powf((float)mE, -input));
		std::cout << "Sigmoid:\n" << "Input: " << input << " Output: " <<  output << std::endl;
		return output;
	}
	virtual float transfer()
	{
		return output;
	}

	virtual void addConnectionFromL(Connection* left) { connectionsFromL.push_back(left); }
	virtual void addConnectionToR(Connection* right) { connectionsToR.push_back(right); }
	virtual std::vector<Connection*> getConnectionsFromL() { return connectionsFromL; }
	virtual std::vector<Connection*> getConnectionsToR() { return connectionsToR; }

private:
	float output = 0;
	std::vector<Connection*> connectionsFromL;
	std::vector<Connection*> connectionsToR;
};

