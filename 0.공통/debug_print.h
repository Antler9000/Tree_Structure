#ifndef DEBUG_PRINT_H
#define DEBUG_PRINT_H

#include <iostream>		//로그, 경고, 에러 등의 콘솔 출력을 위한 매크로를 사용함
using namespace std;

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

#endif //DEBUG_PRINT_H