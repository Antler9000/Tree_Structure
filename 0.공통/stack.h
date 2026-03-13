#ifndef STACK_H
#define STACK_H

#include "../0.공통/debug_print.h"	//로그, 경고, 에러 등의 콘솔 출력을 위한 매크로를 추후 도입할 예정
using namespace std;				//이동 시맨틱이 필요한지 판단 후 도입할 예정

template <class DataType>
class Stack;

template <class DataType>
class StackNode
{
private:
	friend class Stack<DataType>;

	DataType m_data;
	StackNode* m_pChild;

	StackNode(DataType newData) {
		this->m_data = newData;
		this->m_pChild = NULL;
	}
};

template <class DataType>
class Stack
{
private:
	StackNode<DataType>* m_pHead;

public:
	Stack()
	{
		m_pHead = NULL;
	}

	void Push(DataType data)
	{
		if (m_pHead == NULL)
		{
			m_pHead = new StackNode<DataType>(data);
		}
		else
		{
			StackNode<DataType>* pTraverse = m_pHead;
			while (pTraverse->m_pChild)
			{
				pTraverse = pTraverse->m_pChild;
			}
			pTraverse->m_pChild = new StackNode<DataType>(data);
		}
	}

	DataType Pop()
	{
		if (m_pHead == NULL)
		{
			return NULL;
		}

		if (m_pHead->m_pChild == NULL)
		{
			DataType temp = m_pHead->m_data;
			delete m_pHead;
			m_pHead = NULL;
			return temp;
		}
		else
		{
			StackNode<DataType>* pTraverse = m_pHead;
			while (pTraverse->m_pChild->m_pChild != NULL)
			{
				pTraverse = pTraverse->m_pChild;
			}
			DataType temp = pTraverse->m_pChild->m_data;
			delete pTraverse->m_pChild;
			pTraverse->m_pChild = NULL;
			return temp;
		}
	}

	DataType GetTop()
	{
		if (m_pHead == NULL)
		{
			return NULL;
		}

		if (m_pHead->m_pChild == NULL)
		{
			return m_pHead->m_data;
		}
		else
		{
			StackNode<DataType>* pTraverse = m_pHead;
			while (pTraverse->m_pChild->m_pChild)
			{
				pTraverse = pTraverse->m_pChild;
			}
			return pTraverse->m_pChild->m_data;
		}
	}

	bool IsEmpty()
	{
		if (m_pHead == NULL) return true;
		else return false;
	}
};

#endif //STACK_H