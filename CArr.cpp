#include "CArr.h"
#include <assert.h>

void CArr::push_back(int _Data)
{
    // 힙 영역에 할당한 공간이 다참
    //if (this->m_iMaxCount <= this->m_iCount)    // this란 부분은 생략가능
    if (m_iMaxCount <= m_iCount)
    {
        //재할당
        resize(m_iCount*2);
    }

    // 데이터 추가
    //this->m_pInt[this->m_iCount++] = _Data;
    m_pInt[m_iCount++] = _Data;

}

void CArr::resize(int _iResizeCount)
{
    // 현재 최대 수용량 보다 더 적은 수치로 확장하려는 경우
    if (m_iMaxCount >= _iResizeCount)
    {
        assert(nullptr);
    }
    
    // 더 큰 공간을 동적 할당
    int* pNew = new int[_iResizeCount];

    // 기존 공간에 있던 데이터들을 새호 할당한 공간으로 복사
    for (int i = 0; i < m_iCount; ++i)
    {
        pNew[i] = m_pInt[i];
    }

    // 기존 메모리 삭제
    delete[] m_pInt;

    // 메모리 새로 연결
    m_pInt = pNew;

    // 최대 값 변경
    m_iMaxCount = _iResizeCount;
}

#if 0 
int CArr::operator[](int idx)
{
    return m_pInt[idx];
}
#endif


int& CArr::operator[](int idx)
{
    return m_pInt[idx];
}

CArr::CArr()
    : m_pInt(nullptr)   // 초기화 변수를 선언한 순서 그대로 사용하는 것이 좋음
    , m_iCount(0)
    , m_iMaxCount(2)
{
    m_pInt = new int(2);    // c++ 스타일 동적 할당, int 타입 메모리 2개 생성
}

CArr::~CArr()
{
    delete[] m_pInt;    // 배열 형태의 메모리를 지울때는 [] 사용,m_pInt 타입의 메모리가 연속으로 구성되어 있음
    // 컴파일러 입장에서 어디서 끝나는지는 heap memory에 마킹용 패턴을 확인한다.
}
