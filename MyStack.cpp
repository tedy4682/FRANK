#include "MyStack.h"


MyStack::MyStack()         // 스택 생성자
{
	m_pHead = NULL;
	m_Size = 0;
}


MyStack::~MyStack()
{
	while(m_pHead)        // 헤드가 NULL이 될 때까지
	{
		AddrNode* p = m_pHead;   // p에 헤드 값 초기화
		AddrNode* temp = p->GetNext();
		if(!temp)          // 즉 이전 노드인 p가 마지막 노드였다면
		{
			delete p;      // p 동적할당 해제
			m_pHead = NULL; // 헤드 포인터 널로 초기화
		}
		else               // 이전 노드 p가 마지막 노드가 아니라면
		{
			delete p;      // p를 계속 동적할당 해제
			m_pHead = temp;// 헤드에 temp 초기화
		}
	}
	m_Size = 0;          // 모든 노드가 사라지면 크기 변수 0으로 초기화
}

void MyStack::SetSize(int Size)      // 스택 크기 초기화
{
	m_Size = Size;
}

bool MyStack::Push(AddrNode *pAddrNode)
{
	if(!m_pHead){			      // 노드가 존재하지 않으면
		m_pHead = pAddrNode;      // 헤드를 입력된 노드로 초기화
		return true;
	}

	if(IsFull())                  // 스택에 노드가 가득차면
	{
		AddrNode* p = m_pHead;
		AddrNode* temp = m_pHead;
		while(p->GetNext())       // p의 다음 노드가 널 값이 될 때까지 노드 이동
		{
			temp = p;             // temp는 p의 이전값으로 초기화
			p = p->GetNext();     // p는 다음 노드로 초기화
		}
		temp->SetNext(NULL);      // 널 값이 되기 직전의 p의 전값인 temp의 다음 노드 포인터를 널로 초기화 
		delete p;                 // p를 동적할당 해제

		pAddrNode->SetNext(m_pHead);  // 해당 노드의 다음 pop될 노드는 이전 헤드가 가리키는 노드로 초기화
		m_pHead=pAddrNode;            // 헤드를 push 받은 노드로 초기화
		return true;
	}

	pAddrNode->SetNext(m_pHead);  // 해당 노드의 다음 pop될 노드는 이전 헤드가 가리키는 노드로 초기화
	m_pHead=pAddrNode;            // 헤드를 push 받은 노드로 초기화
	return true;
}

AddrNode* MyStack::Pop()
{
	if(IsEmpty()) return NULL;  // 스택이 비었으면 pop할 노드를 NULL 가리킴

	AddrNode* p=m_pHead;     // POP할 최근 변수

	if(!(p->GetNext()))  // POP할 변수가 마지막 한개 남았다면
	{
		m_pHead=NULL;    // 다음 헤드를 NULL로 초기화하면 빈상태로 만듬
		return p;
	}

	m_pHead = m_pHead->GetNext();  // 헤드는 팝할 노드의 다음 노드로 초기화
	return p;
}

bool MyStack::IsFull()
{
	AddrNode* p = m_pHead;
	int count = 0;

	while(p)                 // 헤드 포인터부터 노드를 계속 이동하여 널이 되기 전까지 이동
	{
		count++;
		if(count==5) return true;       // 5번 이상 돌면 true 반환
		p= p->GetNext();
	}
	return false;           // 그 전에 while 탈출하면 false 반환
}

bool MyStack::IsEmpty()
{
	if(!m_pHead) return true;   // 헤드 포인터가 널이면 true 반환
	else		 return false;  // 널이 아니면 false 반환
}

AddrNode* MyStack::PrintHead()  // 헤드 포인터의 노드 주소를 반환
{
	return m_pHead;
}
