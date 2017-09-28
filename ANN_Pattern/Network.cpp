#include "Network.h"

Network::Network(int inputs, int nrOfLayers, int layerSize, int outputs) :
	connections()
{
	// Add Neurons to each individual layer vector
	input.resize(inputs, new Identity());
	input.push_back(new Bias());
	
	hiddenLayers.resize(nrOfLayers, std::vector<Neuron*>(layerSize, new Sigmoid()));
	for (int i = 0; i < hiddenLayers.size(); i++)
		hiddenLayers[i].push_back(new Bias());

	output.resize(outputs, new Sigmoid());

	// Push all layers into one layer vector
	layers.push_back(input);
	for (int i = 0; i < nrOfLayers; i++)
		layers.push_back(hiddenLayers[i]);
	layers.push_back(output);

	// Loop through layer vector and connect i with i+1
	for (int i = 0; i < layers.size() - 1; i++)
		connectLayer(layers[i], layers[i + 1]);
}

Network::~Network()
{
}

void Network::printNetwork()
{
	for (int i = 0; i < layers.size(); i++)
	{
		std::cout << "L" << i << ": " << std::endl;
		for (int j = 0; j < layers[i].size(); j++)
		{
			std::cout << "N" << j << ": ";// << layers[i][j]->getConnectionsFromL().size();
			for each (Connection *c in layers[i][j]->getConnectionsToR())
			{
				std::cout << c->weight << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
}

void Network::connectLayer(std::vector<Neuron*> leftL, std::vector<Neuron*> rightL)
{
	for (int i = 0; i < leftL.size(); i++)
	{
		for (int j = 0; j < rightL.size(); j++)
		{
			Connection* c = new Connection(leftL[i], rightL[j]);
			c->weight = j;
			leftL[i]->addConnectionToR(c);
			rightL[j]->addConnectionFromL(c);
			connections.push_back(c); // Kommer jag behövas?
		}
	}
}

void Network::setupConnections()
{

}
