#pragma once
class CArr
{
private:        // ���ο� ���ܼ� ���� ����

    int* m_pInt;
    int m_iCount;
    int m_iMaxCount;


public : 
    void push_back( int _Data ); // C Ÿ���� ���, void PushBack(tArr* _pArr, int _iData); ���·� � �迭�� � �����͸� �־� �ٰ��ΰ��� �˷�������
    // Ŭ������ ��� ȣ���ϴ� instance ��ü�� �����ϹǷ� �ԷµǾ� �ϴ� ���� �ʿ�
    void resize(int _iResizeCount); //  ����ڰ� �̸� �ø� �� �ְ� public���� ����

    //int operator[] (int idx);
    int& operator[] (int idx);


public :        // �����ڸ�  private�� ����� ���ʿ�  instance �Ҵ��� �Ҽ� ����.
    CArr();    
    ~CArr();

};

