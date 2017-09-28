#include <iostream>
#include "Network.h"

int main() 
{
	Network network(16, 2, 5, 2);
	//network.printNetwork();
	network.feedForward();

	system("pause");
	return 0;
}