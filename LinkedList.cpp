#include "LinkedList.h"
#include <iostream>

void InitList(tLinkedList* _pList)
{
    _pList->pHeadNode = nullptr;
    _pList->iCount = 0;
}

void PushBack(tLinkedList* _pList, int _iData)
{
    // 데이터를 저장할 노드 생성
    // 데이터 복사
    tNode* pNode = (tNode*)malloc(sizeof(tNode));

    pNode->iData = _iData;
    pNode->pNextNode = nullptr;


    // 추가한 데이터가 처음인지 아닌지
    if (0 == _pList->iCount)
    {
        _pList->pHeadNode = pNode;
    }
    else
    {
        // 현재 가장 마지막 노드를 찾아서,
        // 해당 노드의 pNext 를 생성시킨 노드의 주소로 채움
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
    // 데이터를 저장할 노드 생성
    
    tNode* pNode = (tNode*)malloc(sizeof(tNode));

    pNode->iData = _iData;
    pNode->pNextNode = _pList->pHeadNode;

    // 리스트의 해드포인트 연결
    _pList->pHeadNode = pNode;

    // 데이터 카운트 증가.
    ++_pList->iCount;
}

void ReleaseList(tLinkedList* _pList)
{
    // 지우기 전에 next 주소만 받아두면 됨
    tNode* pDeleteNode = _pList->pHeadNode;

    while (pDeleteNode)
    {

        tNode* pNext = pDeleteNode->pNextNode;
        free(pDeleteNode);
        pDeleteNode = pNext;
    }
}
