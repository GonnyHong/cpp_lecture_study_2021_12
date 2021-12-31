#include "LinkedList.h"
#include <iostream>

void InitList(tLinkedList* _pList)
{
    _pList->pHeadNode = nullptr;
    _pList->iCount = 0;
}

void PushBack(tLinkedList* _pList, int _iData)
{
    // �����͸� ������ ��� ����
    // ������ ����
    tNode* pNode = (tNode*)malloc(sizeof(tNode));

    pNode->iData = _iData;
    pNode->pNextNode = nullptr;


    // �߰��� �����Ͱ� ó������ �ƴ���
    if (0 == _pList->iCount)
    {
        _pList->pHeadNode = pNode;
    }
    else
    {
        // ���� ���� ������ ��带 ã�Ƽ�,
        // �ش� ����� pNext �� ������Ų ����� �ּҷ� ä��
        tNode* pCurFinalNode = _pList->pHeadNode;
#if 0
        while (true)
        {
            if (nullptr == pCurFinalNode->pNextNode)
            {
                break;
            }

            pCurFinalNode = pCurFinalNode->pNextNode;
        }

#else
        while (pCurFinalNode->pNextNode)
        {
            pCurFinalNode = pCurFinalNode->pNextNode;
        }
#endif

        pCurFinalNode->pNextNode = pNode;

    }

    ++_pList->iCount;
}

void PushFront(tLinkedList* _pList, int _iData)
{
    // �����͸� ������ ��� ����
    
    tNode* pNode = (tNode*)malloc(sizeof(tNode));

    pNode->iData = _iData;
    pNode->pNextNode = _pList->pHeadNode;

    // ����Ʈ�� �ص�����Ʈ ����
    _pList->pHeadNode = pNode;

    // ������ ī��Ʈ ����.
    ++_pList->iCount;
}

void ReleaseList(tLinkedList* _pList)
{
    // ����� ���� next �ּҸ� �޾Ƶθ� ��
    tNode* pDeleteNode = _pList->pHeadNode;

    while (pDeleteNode)
    {

        tNode* pNext = pDeleteNode->pNextNode;
        free(pDeleteNode);
        pDeleteNode = pNext;
    }
}
