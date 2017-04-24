#include "latticenode.h"

LatticeNode::LatticeNode(int row, int col)
{
	this->row = row;
	this->col = col;
}

bool LatticeNode::operator==(const LatticeNode& node) const
{
	if (this->row == node.getRow() && this->col == node.getCol())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int LatticeNode::getRow() const
{
	return this->row;
}

int LatticeNode::getCol() const
{
	return this->col;
}
