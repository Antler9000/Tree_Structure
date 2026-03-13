//디버그 출력문들을 활성화하기 위한 전처리 상수 정의
//#define TREE_LOG	
//#define TREE_ERROR
//#define TREE_WARNING

#include "BST_using_while.h"	//정의한 이진 탐색 트리를 테스팅함

int main()
{
	BST testBST =  BST();
	testBST.Insert(5, 1515);
	testBST.Insert(7, 2727);
	testBST.Insert(3, 1313);
	testBST.Insert(4, 2424);
	testBST.Insert(6, 3636);
	testBST.Insert(1, 5151);
	testBST.Insert(8, 5858);
	testBST.PreorderPrint();
	cout << endl;

	cout << "copy test" << endl;
	BST copied_test_BST = BST();
	copied_test_BST.CopyTree(testBST);
	copied_test_BST.PreorderPrint();
	cout << endl;

	testBST.Remove(7);
	testBST.PreorderPrint();
	cout << endl;

	testBST.Remove(3);
	testBST.PreorderPrint();
	cout << endl;

	testBST.Remove(5);
	testBST.PreorderPrint();
	cout << endl;

	testBST.Remove(4);
	testBST.PreorderPrint();
	cout << endl;

	testBST.Remove(6);
	testBST.PreorderPrint();
	cout << endl;

	testBST.Remove(1);
	testBST.PreorderPrint();
	cout << endl;

	testBST.Remove(8);
	testBST.PreorderPrint();
	cout << endl;

	cout << "copy test" << endl;
	copied_test_BST.PreorderPrint();

	return 0;
}