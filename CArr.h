#pragma once
class CArr
{
private:        // 내부에 숨겨서 만들 예정

    int* m_pInt;
    int m_iCount;
    int m_iMaxCount;


public : 
    void push_back( int _Data ); // C 타입의 경우, void PushBack(tArr* _pArr, int _iData); 형태로 어떤 배열에 어떤 데이터를 넣어 줄것인가를 알려주지만
    // 클래스의 경우 호출하는 instance 자체를 포함하므로 입력되야 하는 값만 필요
    void resize(int _iResizeCount); //  사용자가 미리 늘릴 수 있게 public으로 설정

    //int operator[] (int idx);
    int& operator[] (int idx);


public :        // 생성자를  private로 만들면 애초에  instance 할당을 할수 없다.
    CArr();    
    ~CArr();

};

