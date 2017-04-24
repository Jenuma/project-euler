#include "latticegraph.h"

// Constructor
LatticeGraph::LatticeGraph(int size)
{
	this->size = size;

	std::list<LatticeNode> tempNodes;

	for (int i = 0; i <= size; i++)
	{
		for (int j = 0; j <= size; j++)
		{
			// Create nodes
			LatticeNode tempNode = LatticeNode(i, j);
			tempNodes.push_back(tempNode);
		}
	}

	for (std::list<LatticeNode>::iterator i = tempNodes.begin(); i != tempNodes.end(); i++)
	{
		std::list<LatticeNode> subList;
		subList.push_back(*i);

		// Node has neighbor to the right and bottom:
		if (i->getRow() < size && i->getCol() < size)
		{
			for (std::list<LatticeNode>::iterator j = tempNodes.begin(); j != tempNodes.end(); j++)
			{
				if ((j->getRow() == i->getRow() + 1 && j->getCol() == i->getCol()) ||
					(j->getCol() == i->getCol() + 1 && j->getRow() == i->getRow()))
				{
					subList.push_back(*j);
				}
			}
		}
		// Node has neighbor to the right:
		else if (i->getRow() == size && i->getCol() < size)
		{
			for (std::list<LatticeNode>::iterator j = tempNodes.begin(); j != tempNodes.end(); j++)
			{
				if (j->getCol() == i->getCol() + 1 && j->getRow() == i->getRow())
				{
					subList.push_back(*j);
				}
			}
		}
		// Node has neighbor to the bottom:
		else if (i->getCol() == size && i->getRow() < size)
		{
			for (std::list<LatticeNode>::iterator j = tempNodes.begin(); j != tempNodes.end(); j++)
			{
				if (j->getRow() == i->getRow() + 1 && j->getCol() == i->getCol())
				{
					subList.push_back(*j);
				}
			}
		}

		this->nodes.push_back(subList);
	}
}

std::list<std::list<LatticeNode>> LatticeGraph::getNodes()
{
	return this->nodes;
}
