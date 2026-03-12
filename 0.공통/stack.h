#ifndef STACK_H
#define STACK_H

#ifdef TREE_LOG
#define LogPrint(statement) cout << "(Log : " << __func__ << ") " << statement << endl
#else
#define LogPrint(statement)
#endif

#ifdef TREE_ERROR
#define ErrorPrint(statement) cout << "(Error : " << __func__ << ") " << statement << endl
#else
#define ErrorPrint(statement)
#endif

#ifdef TREE_WARNING
#define WarningPrint(statement) cout << "(Warning : " << __func__ << ") " << statement << endl
#else
#define WarningPrint(statement)
#endif

#include <iostream>		//에러 출력 함수와 순회 출력 함수에서 cin, cout을 사용함
using namespace std;

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