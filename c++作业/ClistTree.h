#pragma once
#include <list>
#include "CTree.h"
class ClistTree{
public:
	list<CTree*> m_listTree;
	IMAGE m_trees;
	void InitAllTree();
	void ShowAllTree();
	void MoveAllTree(CBack&);
};

