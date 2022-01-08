#include "Arr.h"


void InitArr(tArr* _pArr) //�ּҸ� �Ѱ���� �ش� �޸𸮿� ���� ���� �� ���� ����
{
    _pArr->pInt = (int*)malloc(sizeof(int) * 2); // �ʱ�ȭ�� 2 byte ũ���� �迭 ����
    _pArr->iCount = 0;      // �Էµ� ������ ������ �翬�� 0
    _pArr->maxcount = 2;    // ������ �迭 ũ�� 2 byte
}

void ReleaseArr(tArr* _pArr)
{
    free(_pArr->pInt);
    _pArr->iCount = 0;
    _pArr->maxcount = 0;
}

void PushBack(tArr* _pArr, int _iData)
{
    // �� ������ �Ҵ��� ������ �� á���� heap ������ ���Ҵ� �ؾߵ�
    if (_pArr->maxcount <= _pArr->iCount)
    {
        // ���Ҵ�
        ReallocArr(_pArr);
    }
    // ������ �߰�
    _pArr->pInt[_pArr->iCount++] = _iData;  //���� �����ڷ� ó�� ���� ��Ű�� �ʰ� ������ �ְ� �ε��� ����
}

void ReallocArr(tArr* _pArr)
{
    //1. �� ū ������ �Ҵ�, ���� maxcount�� 2���
    int* pNew = (int*)malloc(_pArr->maxcount * 2 * sizeof(int));

    //2. ���� ������ �ִ� �����͸� ���� �Ҵ��� ������ ����.
    for (int i = 0; i < _pArr->iCount; ++i)
    {
        pNew[i] = _pArr->pInt[i];
    }

    //3. ���� ������ �޸� ����
    free(_pArr->pInt);

    //4. �迭 ���� ���� ����, maxcount ���� ó��
    _pArr->pInt = pNew;
    _pArr->maxcount *= 2;
}