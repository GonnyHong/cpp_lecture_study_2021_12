#include <iostream>
#include "LinkedList.h"

// 주석
// 설명 역할, 코드로 인식하지 않음

int main()
{
    // 주석
    // 설명 역할, 코드로 인식하지 않음
    
    // int : 자료형
    // i : 자료형이 객체로 구현된 형태(instance)

    // 자료형(크기 단위, byte) , 어떤할 실체도 없음, 어떤한 변수의 크기나 형태를 설명해주는 것 
    // 정수형 : char(1), short(2), int(4), long(4), long long(8)
    // 실수형 : float(4), double(8)

    int i = 0;

    // 자료형
    unsigned char c = 0;    // 0 ~ 255 까지 표현 가능
    c = 0;                  // 0, OK 
    c = 255;                // 255, OK, 0b11111111
    c = 266;                // 256 --> 0, ovelflow bit 처리 못하고 0으로 표현됨

    char c1 = 0;            // 1바이트로 양수, 음수 둘다 표현
    c1 = -1;                // 0b11111111
    c1 = 255;               // 0b11111111, 255 숫자의 1byte signed char로 표현은 -1



    // 연결형 자료구죠
    tLinkedList list = {};
    InitList(&list);

    PushFront(&list, 100);
    PushFront(&list, 200);
    PushFront(&list, 300);
    

    ReleaseList(&list);


    int temp = 0;

    return 0;
}