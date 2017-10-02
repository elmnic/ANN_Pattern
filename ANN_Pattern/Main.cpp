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
		network.setPattern(i % 2);
		//if (i > EPOCH / 2)
		//{
		//	// Broken X
		//	network.setPattern(2);
		//}
	}

	// Pattern O
	network.setPattern(1);
	for (int i = 0; i < EPOCH; i++)
	{
		network.feedForward();
		network.backpropagate();
		network.setPattern(i % 2 + 2);
		//if (i > EPOCH / 2)
		//{
		//	// Broken O
		//	network.setPattern(3);
		//}
	}

	std::cout << "Pattern X broken:" << std::endl;
	std::cout << "Target:\n1.0\n0.0" << std::endl;
	network.setPattern(4);
	network.feedForward();
	network.printOutput();

	std::cout << "\nPattern O broken:" << std::endl;
	std::cout << "Target:\n0.0\n1.0" << std::endl;
	network.setPattern(5);
	network.feedForward();
	network.printOutput();

	system("pause");
	return 0;
}