#ifndef TREE_H
#define TREE_H

#include <string>
#include <vector>

class CNode
{
public:
	std::string _item;
	std::vector<CNode> _son;
public:
	CNode();
	CNode(std::string prop);
};

class CTree
{
private:
	CNode _root;
public:
	CTree();
	CTree(CNode* node);
	~CTree();
};

#endif //TREE_H