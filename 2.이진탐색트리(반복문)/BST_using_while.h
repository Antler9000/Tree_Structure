#ifndef BST_USING_WHILE_H
#define BST_USING_WHILE_H

#include "../0.공통/BST_using_while_template.h"		//정의한 이진 탐색 트리 템플릿을 구체화해서 이진 탐색 트리를 정의함
using namespace std;								//생성자에서 std::move(..)를 사용함

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

	~BST_Node()
	{
		delete m_pLeftChild;
		delete m_pRightChild;
	}
};

class BST : public BST_Template<BST_Node>
{
public:
	BST() : BST_Template() {}	
};

#endif //BST_USING_WHILE_H