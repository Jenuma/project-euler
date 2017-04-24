#include <string>

class LatticeNode
{
	private:
		int row;
		int col;
	public:
		LatticeNode(int, int);
		bool operator==(const LatticeNode&) const;
		int getRow() const;
		int getCol() const;
};
