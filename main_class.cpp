
class CMy
{
private:
    int m_i;
    float m_f;

public:
#if 0 // C 스타일로 구현 시 SetInt 함수를 호출해서 변수를 넣을 경우
    void SetInt(CMy* _this, int i)
    {
        _this->m_i = i;
    }
#endif
    // 이 class istance에 넣는다는 의미가 포함되어 있음
    void SetInt(int i)
    {
        this->m_f = i;  // standard type, this  = CMy* this
        m_i = i; // this-> 생략 가능해서 이렇게 쓸 수 있음
    }

    // 대입연산자 : 자동으로 만들어 지는 case(유저 생성 class 이지만...)
    CMy& operator = (const CMy& _Other)   // = 뒤의 변수가 인자됨 
                                          // 인자를 참조 받아서 오고 수정될이 없도록 const 처리
    // 참조를 전달하겠다... void가 아니고 reference를 반환값으로 쓰는 이유
#if 0 
    {
        int i1=5;
        int i2=10;
        int i3=20;

        i1 = i2 = i3;
        //1. i3를 i2에 넣고                         --> i2 가 operator=를 호출하여 i3를 i2에 넣음
        //2. i2에 있던 값을 i1에 넣는 개념 순서상   --> 1의 결과의 operator=의 반환값이 void라면 이경우 i2 = NULL로 setting 되는 case 
        //
    }
#endif
    {
        m_i = _Other.m_i;
        m_f = _Other.m_f;

        return *this;   // this는 포인터이므로 *를 부터 역참조하여 reference로 전달(결국 본인을 반환하는 것)
    }

public:
    // 생성자, 소멸자
    CMy()
        : m_i(100)
        , m_f(0.f)
    {

    }
    ~CMy()
    {

    }
};

int main()
{
    {
        //레퍼런스
        //자료형 * 변수명;    포인터 변수 선언
        //*포인터변수;        포인터 주소 역참조
        //&변수;              변수의 주소값
        //자료형 & 변수명;    레퍼선스 변수 선언

        //C++에 추가된 기능
        // 포인터와 유사
        // 원본을 참조한다.
        // 참조변수를 통해서 직접적으로 원본을 수정할 수 있다.
        //장점
        // 호출 자체의 방식 변화
        // 사용자 입장에서 주소 관련해서 실수할 여지가 줄어듬
        // 레퍼런스만 할 수 있는 동작들이 있음(?)

        int a = 10;
        int* p = &a;
        *p = 100;

        int& iRef = a;  // 레퍼런스와 포인터는 컴파일러 입장에서는 똑같음
        iRef = 100;     // 사용자 입장에서의 차이
        {
            int* const p = &a;  //  와 개념이 같음, 한번 가리킨 대상이 바뀔 수 없음
        }
        
        const int& iRefConst = a;   //a를 가리키면서 수정할 수 없는 상태
        const int* const p2 = &a;   // 와 개념이 같음
        //*p2 = 10; 원본을 수정 못함

        // 포인터를 쓰는 이유와 같이 전달할때 비용을 줄이기 위한 의도
        
    }   



    CMy c1, c2, c3;
    c1.SetInt(10); // c1의 멤버 변수에 10을 setting
    // c 스타일로 구현 했을 시, 핸들링하고자 하는 구조체의 주소와 값이 두개가 필요
    // SetInt(&c1, 10);
    c2.SetInt(20);
    c3.SetInt(30);

    c3 = c2;    //c3 가 호출한 operator= 로 해석함


}