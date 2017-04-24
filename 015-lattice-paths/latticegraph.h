#include <list>
#include "latticenode.h"

class LatticeGraph
{
	private:
		int size;
		std::list<std::list<LatticeNode>> nodes;
	public:
		LatticeGraph(int);
		std::list<std::list<LatticeNode>> getNodes();
};
