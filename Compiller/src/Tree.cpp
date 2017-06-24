#include "Tree.h"

CNode::CNode()
{ }

CNode::CNode(std::string prop):
	_item(prop)
{ }

CTree::CTree()
{ }

CTree::CTree(CNode* node):
	_root(*node)
{ }

CTree::~CTree()
{ }