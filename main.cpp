#include <iostream>
#include "LinkedList.h"

// �ּ�
// ���� ����, �ڵ�� �ν����� ����

int main()
{
    // �ּ�
    // ���� ����, �ڵ�� �ν����� ����
    
    // int : �ڷ���
    // i : �ڷ����� ��ü�� ������ ����(instance)

    // �ڷ���(ũ�� ����, byte) , ��� ��ü�� ����, ��� ������ ũ�⳪ ���¸� �������ִ� �� 
    // ������ : char(1), short(2), int(4), long(4), long long(8)
    // �Ǽ��� : float(4), double(8)

    int i = 0;

    // �ڷ���
    unsigned char c = 0;    // 0 ~ 255 ���� ǥ�� ����
    c = 0;                  // 0, OK 
    c = 255;                // 255, OK, 0b11111111
    c = 266;                // 256 --> 0, ovelflow bit ó�� ���ϰ� 0���� ǥ����

    char c1 = 0;            // 1����Ʈ�� ���, ���� �Ѵ� ǥ��
    c1 = -1;                // 0b11111111
    c1 = 255;               // 0b11111111, 255 ������ 1byte signed char�� ǥ���� -1



    // ������ �ڷᱸ��
    tLinkedList list = {};
    InitList(&list);

    PushFront(&list, 100);
    PushFront(&list, 200);
    PushFront(&list, 300);
    

    ReleaseList(&list);


    int temp = 0;

    return 0;
}