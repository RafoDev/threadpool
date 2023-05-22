#include <iostream>
#include "../include/timer.hpp"
#include "../include/threadpool.hpp"
using namespace std;

void waste_cycles(uint64_t num_cycles)
{
	volatile uint64_t counter = 0;
	for (uint64_t i = 0; i < num_cycles; i++)
		counter++;
}
void traverse(uint64_t node, uint64_t num_nodes)
{
	if (node < num_nodes)
	{
		// do some work
		waste_cycles(1 << 15);

		// visit your children more often!
		traverse(2 * node + 1, num_nodes);
		traverse(2 * node + 2, num_nodes);
	}
}

int main()
{

	TIMERSTART(traverse)
	traverse(0, 1 << 20);
	TIMERSTOP(traverse)
}