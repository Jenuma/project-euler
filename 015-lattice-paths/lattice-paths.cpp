/*
* Starting in the top left corner of a 2x2 grid, and only being able to move ot the right and down,
* there are exaclty 6 routes to the bottom right corner.
* 
* RRDD RDRD RDDR
* DRRD DRDR DDRR
* 
* How many such routes are there through a 20x20x grid?
*
* Author: Clifton Roberts
* Date: 24 April 2017
*/

#include <iostream>
#include <string>
#include "latticegraph.h"

using namespace std;

// Function Prototypes
void findPath(LatticeNode);

// Global Variables
unsigned long long pathCount = 0;
list<list<LatticeNode>> someNodes;

int main()
{
	int graphSize = 0;

	cout << "What is the size of the grid? (i.e. 20 for 20x20 grid)" << endl;
	cin >> graphSize;

	LatticeGraph aGraph = LatticeGraph(graphSize);

	someNodes = aGraph.getNodes();

	// Brute force solution below - could take up to 2 weeks to finish running!
	//findPath(someNodes.front().front());

	// Combinatorics solution - based on noticing the number of paths correlate to entries
	// in Pascal's Triangle.
	unsigned long long k = graphSize;
	unsigned long long n = k * 2;
	long double paths = 1.0L;

	for (int i = 1; i <= k; i++)
	{
		paths *= (n - k + i);
		paths /= i;
	}

	cout << fixed << "Number of paths: " << paths << endl;
	cin.ignore(256, '\n');
	cin.get();
	return 0;
}

void findPath(LatticeNode node)
{
	for (list<list<LatticeNode>>::iterator i = someNodes.begin(); i != someNodes.end(); i++)
	{
		if (i->front() == node)
		{
			if (i->size() > 1)
			{
				for (list<LatticeNode>::iterator j = next(i->begin()); j != i->end(); j++)
				{
					findPath(*j);
				}
			}
			else
			{
				pathCount++;
				return;
			}
		}
	}
}
