
#include <iostream>

typedef struct _tagArr
{
    int* pInt;       // �����͸� ���� ��ų ���� �ּ�
    int     iCount;     // ������ ����
    int     maxcount;   // iCount�� maxcount�� ���������� �޸𸮸� �÷�����Ѵ�.
} tArr;

void InitArr(tArr* _pArr);              //�ּҸ� �Ѱ���� �ش� �޸𸮿� ���� ���� �� ���� ����
void ReleaseArr(tArr* _pArr);           // ����
void PushBack(tArr* _pArr, int _iData);  // ������ �߰��ϴ� �Լ�
void ReallocArr(tArr* _pArr);           // ���Ҵ��ϴ� �Լ�