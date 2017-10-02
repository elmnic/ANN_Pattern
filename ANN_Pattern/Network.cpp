#include "Network.h"

Network::Network(int inputs, int nrOfLayers, int layerSize, int outputs) :
	connections()
{
	currentPattern = patternX;
	currentTarget = targetX;
	srand(time(0));

	// Add Neurons to each individual layer vector
	// Input layer plus bias
	for (int i = 0; i < inputs; i++)
		input.push_back(new Identity());
	input.push_back(new Bias());
	
	// Hidden layers plus bias
	for (int i = 0; i < nrOfLayers; i++)
	{
		hiddenLayers.push_back(std::vector<Neuron*>());
		for (int j = 0; j < layerSize; j++)
		{
			hiddenLayers[i].push_back(new Sigmoid());
		}
		hiddenLayers[i].push_back(new Bias());
	}

	// Output layer
	for (int i = 0; i < outputs; i++)
		output.push_back(new Sigmoid());

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
	for (int i = 0; i < layers.size(); i++)
	{
		for (int j = 0; j < layers[i].size(); j++)
		{
			delete layers[i][j];
		}
	}
	layers.clear();

	while (!connections.empty())
	{
		delete connections.back();
		connections.pop_back();
	}

	input.clear();
	hiddenLayers.clear();
	output.clear();
}

void Network::setPattern(int i)
{
	switch (i)
	{
	case 0:
		currentPattern = patternX;
		currentTarget = targetX;
		break;
	case 1:
		currentPattern = patternO;
		currentTarget = targetO;
		break;
	case 2:
		currentPattern = patternXBroken;
		currentTarget = targetX;
		break;
	case 3:
		currentPattern = patternOBroken;
		currentTarget = targetO;
		break;
	case 4:
		currentPattern = patternXBrokenExtra;
		currentTarget = targetX;
		break;
	case 5:
		currentPattern = patternOBrokenExtra;
		currentTarget = targetO;
		break;
	default:
		break;
	}
}

void Network::printNetwork()
{
	for (int i = 0; i < layers.size(); i++)
	{
		std::cout << "Layer " << i << ": " << std::endl;
		for (int j = 0; j < layers[i].size(); j++)
		{
			std::cout << "Neuron " << j << ": ";
			for each (Connection *c in layers[i][j]->getConnectionsToR())
			{
				std::cout << c->weight << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
}

void Network::printOutput()
{
	for each (Neuron* neuron in layers.back())
	{
		std::cout << "Output: " << neuron->transfer() << std::endl;
	}
}

void Network::feedForward()
{
	// Activate identity neurons
	for (int i = 0; i < layers[0].size() - 1; i++)
	{
		layers[0][i]->activation((float)currentPattern[i]);
	}

	// Iterate through each layer beginning on the second
	for (int i = 1; i < layers.size(); i++)
	{
		// Iterate through each neuron
		for (int j = 0; j < layers[i].size(); j++)
		{
			// Transfer the summed outputs and weights from left layer 
			// to activation input of current layer
			float input = 0;
			for each (Connection* c in layers[i][j]->getConnectionsFromL())
			{
				input += c->left->transfer() * c->weight;
			}
			layers[i][j]->activation(input);
		}
	}

	/*for each (Neuron* neuron in layers.back())
	{
		std::cout << "Output: " << neuron->transfer() << std::endl;
	}*/
}

void Network::backpropagate()
{
	// Backpropagate output layers
	for (int i = 0; i < layers.back().size(); i++)
	{
		Neuron* neuron = layers.back()[i];
		float sum = 0;

		// Sum output*weight for each connection
		for each (Connection* con in neuron->getConnectionsFromL())
		{
			sum += con->left->transfer() * con->weight;
		}

		// Derivate sum and multiply by error to get delta
		float error = currentTarget[i] - neuron->transfer();
		float delta = derivative(sum) * error;
		neuron->setDelta(delta);
		
		// Store the new weight in connection. Apply later
		for each (Connection* con in neuron->getConnectionsFromL())
		{
			con->newWeight = con->weight - learningRate * con->left->transfer() * delta;
		}
	}
	
	/*****************************************/

	// Step backwards through network and calc deltas
	// Start from second to last layer
	for (int i = layers.size() - 2; i > 0; i--)
	{
		for (int j = 0; j < layers[i].size(); j++)
		{
			Neuron* neuron = layers[i][j];
			float rSum = 0;

			// Sum the weighted deltas from next layer
			for each (Connection* con in neuron->getConnectionsToR())
			{
				rSum += con->right->getDelta() * con->weight;
			}
			float delta = derivative(neuron->transfer()) * rSum;
			neuron->setDelta(delta);

			// Store new weight in left connection. Apply later
			for each (Connection* con in neuron->getConnectionsFromL())
			{
				con->newWeight = con->weight - learningRate * con->left->transfer() * delta;
			}
		}
	}


	// Loop through all connections and apply new weights
	for each (Connection* con in connections)
	{
		con->weight = con->newWeight;
	}

}

float Network::derivative(float output)
{
	return output * (1.0f - output);
}

void Network::connectLayer(std::vector<Neuron*> leftL, std::vector<Neuron*> rightL)
{
	for (int i = 0; i < leftL.size(); i++)
	{
		for (int j = 0; j < rightL.size(); j++)
		{
			float randomFloat = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			Connection* c = new Connection(leftL[i], rightL[j]);
			c->weight = randomFloat;
			leftL[i]->addConnectionToR(c);
			rightL[j]->addConnectionFromL(c);
			connections.push_back(c);
		}
	}
}
