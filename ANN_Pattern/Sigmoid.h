#pragma once
#include "Neuron.h"
struct Sigmoid : public Neuron
{
public:
	virtual float calc(float input)
	{
		return 1.0f / (1.0f + powf((float)mE, -input));
	}

	virtual void addConnectionFromL(Connection* left) { connectionsFromL.push_back(left); }
	virtual void addConnectionToR(Connection* right) { connectionsToR.push_back(right); }

	virtual std::vector<Connection*> getConnectionsFromL() { return connectionsFromL; }
	virtual std::vector<Connection*> getConnectionsToR() { return connectionsToR; }
private:
	std::vector<Connection*> connectionsFromL;
	std::vector<Connection*> connectionsToR;
};

