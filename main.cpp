#include <iostream>
#include "LinkedList.h"

int main()
{
    tLinkedList list = {};
    InitList(&list);

    PushFront(&list, 100);
    PushFront(&list, 200);
    PushFront(&list, 300);
    

    ReleaseList(&list);


    int temp = 0;

}