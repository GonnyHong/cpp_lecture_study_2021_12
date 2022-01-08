#include "Arr.h"


void InitArr(tArr* _pArr) //주소를 넘겨줘야 해당 메모리에 대한 접근 후 수정 가능
{
    _pArr->pInt = (int*)malloc(sizeof(int) * 2); // 초기화로 2 byte 크기의 배열 생성
    _pArr->iCount = 0;      // 입력된 데이터 갯수는 당연히 0
    _pArr->maxcount = 2;    // 생성된 배열 크기 2 byte
}

void ReleaseArr(tArr* _pArr)
{
    free(_pArr->pInt);
    _pArr->iCount = 0;
    _pArr->maxcount = 0;
}

void PushBack(tArr* _pArr, int _iData)
{
    // 힙 영역에 할당한 공간이 다 찼으며 heap 영역을 재할당 해야됨
    if (_pArr->maxcount <= _pArr->iCount)
    {
        // 재할당
        ReallocArr(_pArr);
    }
    // 데이터 추가
    _pArr->pInt[_pArr->iCount++] = _iData;  //후위 연산자로 처리 증가 시키지 않고 데이터 넣고 인덱스 증가
}

void ReallocArr(tArr* _pArr)
{
    //1. 더 큰 공간을 할당, 예로 maxcount의 2배로
    int* pNew = (int*)malloc(_pArr->maxcount * 2 * sizeof(int));

    //2. 기존 공간에 있던 데이터를 새로 할당한 공간에 복사.
    for (int i = 0; i < _pArr->iCount; ++i)
    {
        pNew[i] = _pArr->pInt[i];
    }

    //3. 기존 공간의 메모리 해제
    free(_pArr->pInt);

    //4. 배열 새로 공간 연결, maxcount 변경 처리
    _pArr->pInt = pNew;
    _pArr->maxcount *= 2;
}