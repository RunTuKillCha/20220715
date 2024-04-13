#include "ClistTree.h"

void ClistTree::InitAllTree(){
	srand(0x01);
	loadimage(&m_trees, L"res/maps/shu.png");
	for(int i = 1;i < 40 ; i++){
		CTree* pTree = new CTree;
		pTree->c_x = (rand() - BACK_WIDTH / 2) % BACK_WIDTH / 2;
		pTree->c_y = (rand() - BACK_HIGHT / 2) % BACK_HIGHT / 2;
		m_listTree.push_back(pTree);
	}
}

void ClistTree::ShowAllTree(){
	for (CTree* pTree : m_listTree) {
		//pTree->ShowTree(m_trees);
		putimagePNG(pTree->m_x, pTree->m_y, &m_trees);
	}
}

void ClistTree::MoveAllTree(CBack &back)
{
	for (CTree* pTree : m_listTree) {
		pTree->moveTree(back);
	}
}
