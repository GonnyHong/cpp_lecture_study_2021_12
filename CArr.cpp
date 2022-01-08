#include "CArr.h"
#include <assert.h>

void CArr::push_back(int _Data)
{
    // �� ������ �Ҵ��� ������ ����
    //if (this->m_iMaxCount <= this->m_iCount)    // this�� �κ��� ��������
    if (m_iMaxCount <= m_iCount)
    {
        //���Ҵ�
        resize(m_iCount*2);
    }

    // ������ �߰�
    //this->m_pInt[this->m_iCount++] = _Data;
    m_pInt[m_iCount++] = _Data;

}

void CArr::resize(int _iResizeCount)
{
    // ���� �ִ� ���뷮 ���� �� ���� ��ġ�� Ȯ���Ϸ��� ���
    if (m_iMaxCount >= _iResizeCount)
    {
        assert(nullptr);
    }
    
    // �� ū ������ ���� �Ҵ�
    int* pNew = new int[_iResizeCount];

    // ���� ������ �ִ� �����͵��� ��ȣ �Ҵ��� �������� ����
    for (int i = 0; i < m_iCount; ++i)
    {
        pNew[i] = m_pInt[i];
    }

    // ���� �޸� ����
    delete[] m_pInt;

    // �޸� ���� ����
    m_pInt = pNew;

    // �ִ� �� ����
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
    : m_pInt(nullptr)   // �ʱ�ȭ ������ ������ ���� �״�� ����ϴ� ���� ����
    , m_iCount(0)
    , m_iMaxCount(2)
{
    m_pInt = new int(2);    // c++ ��Ÿ�� ���� �Ҵ�, int Ÿ�� �޸� 2�� ����
}

CArr::~CArr()
{
    delete[] m_pInt;    // �迭 ������ �޸𸮸� ���ﶧ�� [] ���,m_pInt Ÿ���� �޸𸮰� �������� �����Ǿ� ����
    // �����Ϸ� ���忡�� ��� ���������� heap memory�� ��ŷ�� ������ Ȯ���Ѵ�.
}
