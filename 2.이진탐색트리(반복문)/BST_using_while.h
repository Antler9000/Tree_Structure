#ifndef BST_USING_WHILE_H
#define BST_USING_WHILE_H

#include "../0.°øÅë/BST_using_while_template.h"

class BST_Node
{
private:
	friend class BST_Template<BST_Node>;

	int m_key;
	int m_data;
	BST_Node* m_pLeftChild;
	BST_Node* m_pRightChild;

	BST_Node(int newKey, const int& newData)
		: m_key(newKey), m_data(newData), m_pLeftChild(NULL), m_pRightChild(NULL)
	{
		
	}

	BST_Node(int newKey, int&& newData)
		: m_key(newKey), m_data(move(newData)), m_pLeftChild(NULL), m_pRightChild(NULL)
	{

	}
};

class BST : public BST_Template<BST_Node>
{
public:
	BST() : BST_Template() {}	
};

#endif //BST_USING_WHILE_H