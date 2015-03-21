#include "AddrNode.h"

class MyStack
{
private:
	AddrNode* m_pHead;   // 스택의 헤더포인터
	int m_Size;          // 스택 크기 변수
public:
	MyStack();     // 생성자
	~MyStack();    // 소멸자
	void SetSize(int Size);  // 스택 크기 초기화
	bool Push(AddrNode* pAddrNode);   // 스택 PUSH
	AddrNode* Pop();     // 스택 POP
	bool IsFull();       // 스택이 가득 찼는지 확인하는 함수
	bool IsEmpty();      // 스택이 비었는지 확인하는 함수
	AddrNode* PrintHead();   // 헤드 주소값 반환
};

