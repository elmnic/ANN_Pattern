#include <iostream>
#include "Network.h"

static int EPOCH = 1000;

int main() 
{
	Network network(16, 0, 0, 2);
	//network.printNetwork();

	// Pattern X
	for (int i = 0; i < EPOCH; i++)
	{
		network.feedForward();
		network.backpropagate();
		network.setPattern(i % 2); // Switch between pattern X and pattern X broken
	}

	// Pattern O
	network.setPattern(1);
	for (int i = 0; i < EPOCH; i++)
	{
		network.feedForward();
		network.backpropagate();
		network.setPattern(i % 2 + 2); // Switch between pattern O and pattern O broken
	}

	std::cout << "Pattern X broken:" << std::endl;
	std::cout << "Target:\n1.0\n0.0" << std::endl;
	network.setPattern(4); // Unused pattern during training
	network.feedForward();
	network.printOutput();

	std::cout << "\nPattern O broken:" << std::endl;
	std::cout << "Target:\n0.0\n1.0" << std::endl;
	network.setPattern(5); // Unused pattern during training
	network.feedForward();
	network.printOutput();

	system("pause");
	return 0;
}