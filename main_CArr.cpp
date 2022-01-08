#include "CArr.h"
#include "Arr.h"

class CTest
{

};

int main()
{
    // 구조체 --> 클래스
    
    // 객체지향 언어 특징
    // 1. 캡슐화
    // 기능을 수행하기 위해 필요한 멤버 선언, 묶음, 은닉성
    // 멤버 함수들

    // 2. 상속

    // 3. 다형서
    
    // 4. 추상화

    // 구조체 버전 가변배열 --> 클래스 버전

    // C++ 동적할당 new, delete
    // C의 동적할당
    // 공간을 할당하고 어떻게 사용하느냐는 유저가 정의하여 사용하는 형태
    // 처음 만들때 여기는 int만 들어올 수 있다 이런 것은 없음

    // C++의 동적할당
    // size가 아니고 자료형을 받아옴
    // 생성자와 소멸자 호출에 무리가 없게 
    CTest* pTest = new CTest;
    delete pTest;


    //CArr 예시
    tArr arr = {};
    InitArr(&arr);

    PushBack(&arr, 10);
    PushBack(&arr, 20);
    PushBack(&arr, 30);

    ReleaseArr(&arr);

    CArr carr; //만들면서 초기화 까지 완료
    carr.push_back(10);
    carr.push_back(20);
    carr.push_back(30); // return 0를 하면서 release 동작까지 완료


    int iData = carr[1]; // 말도 안되는 경우지만 만들고 싶다...??? operator 처리 
    
#if 0 
    {
        carr[1] = 200; // 이건 안됨... 다른 얘기임, 반환 타입을 int 이기때문에
                    // 원본 자체를 바꾸고 싶다면 포인터 형태로 구현이 되어야함
        //operator[]의 반환 타입을 int*로 구현하고 아래의 방법으로 이용
        int* p = carr[1]; // 주소를 받아오고
        *carr[1] = 100; // 주소의 값을 수정, 그러나 원래 알고 잇는 문법과 동떨어져 더 헷갈리지 않을까
    }

    // --> 이런것을 모두 해결하려면 reference를 사용하면 됨
    int iData = carr[1];
    carr[1] = 200;

#endif


    return 0;



}