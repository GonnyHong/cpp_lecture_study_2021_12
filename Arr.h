
#include <iostream>

typedef struct _tagArr
{
    int* pInt;       // 데이터를 저장 시킬 시작 주소
    int     iCount;     // 데이터 갯수
    int     maxcount;   // iCount가 maxcount에 도달했을때 메모리를 늘려줘야한다.
} tArr;

void InitArr(tArr* _pArr);              //주소를 넘겨줘야 해당 메모리에 대한 접근 후 수정 가능
void ReleaseArr(tArr* _pArr);           // 해제
void PushBack(tArr* _pArr, int _iData);  // 데이터 추가하는 함수
void ReallocArr(tArr* _pArr);           // 재할당하는 함수