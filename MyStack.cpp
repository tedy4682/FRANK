#include "MyStack.h"


MyStack::MyStack()         // ���� ������
{
	m_pHead = NULL;
	m_Size = 0;
}


MyStack::~MyStack()
{
	while(m_pHead)        // ��尡 NULL�� �� ������
	{
		AddrNode* p = m_pHead;   // p�� ��� �� �ʱ�ȭ
		AddrNode* temp = p->GetNext();
		if(!temp)          // �� ���� ����� p�� ������ ��忴�ٸ�
		{
			delete p;      // p �����Ҵ� ����
			m_pHead = NULL; // ��� ������ �η� �ʱ�ȭ
		}
		else               // ���� ��� p�� ������ ��尡 �ƴ϶��
		{
			delete p;      // p�� ��� �����Ҵ� ����
			m_pHead = temp;// ��忡 temp �ʱ�ȭ
		}
	}
	m_Size = 0;          // ��� ��尡 ������� ũ�� ���� 0���� �ʱ�ȭ
}

void MyStack::SetSize(int Size)      // ���� ũ�� �ʱ�ȭ
{
	m_Size = Size;
}

bool MyStack::Push(AddrNode *pAddrNode)
{
	if(!m_pHead){			      // ��尡 �������� ������
		m_pHead = pAddrNode;      // ��带 �Էµ� ���� �ʱ�ȭ
		return true;
	}

	if(IsFull())                  // ���ÿ� ��尡 ��������
	{
		AddrNode* p = m_pHead;
		AddrNode* temp = m_pHead;
		while(p->GetNext())       // p�� ���� ��尡 �� ���� �� ������ ��� �̵�
		{
			temp = p;             // temp�� p�� ���������� �ʱ�ȭ
			p = p->GetNext();     // p�� ���� ���� �ʱ�ȭ
		}
		temp->SetNext(NULL);      // �� ���� �Ǳ� ������ p�� ������ temp�� ���� ��� �����͸� �η� �ʱ�ȭ 
		delete p;                 // p�� �����Ҵ� ����

		pAddrNode->SetNext(m_pHead);  // �ش� ����� ���� pop�� ���� ���� ��尡 ����Ű�� ���� �ʱ�ȭ
		m_pHead=pAddrNode;            // ��带 push ���� ���� �ʱ�ȭ
		return true;
	}

	pAddrNode->SetNext(m_pHead);  // �ش� ����� ���� pop�� ���� ���� ��尡 ����Ű�� ���� �ʱ�ȭ
	m_pHead=pAddrNode;            // ��带 push ���� ���� �ʱ�ȭ
	return true;
}

AddrNode* MyStack::Pop()
{
	if(IsEmpty()) return NULL;  // ������ ������� pop�� ��带 NULL ����Ŵ

	AddrNode* p=m_pHead;     // POP�� �ֱ� ����

	if(!(p->GetNext()))  // POP�� ������ ������ �Ѱ� ���Ҵٸ�
	{
		m_pHead=NULL;    // ���� ��带 NULL�� �ʱ�ȭ�ϸ� ����·� ����
		return p;
	}

	m_pHead = m_pHead->GetNext();  // ���� ���� ����� ���� ���� �ʱ�ȭ
	return p;
}

bool MyStack::IsFull()
{
	AddrNode* p = m_pHead;
	int count = 0;

	while(p)                 // ��� �����ͺ��� ��带 ��� �̵��Ͽ� ���� �Ǳ� ������ �̵�
	{
		count++;
		if(count==5) return true;       // 5�� �̻� ���� true ��ȯ
		p= p->GetNext();
	}
	return false;           // �� ���� while Ż���ϸ� false ��ȯ
}

bool MyStack::IsEmpty()
{
	if(!m_pHead) return true;   // ��� �����Ͱ� ���̸� true ��ȯ
	else		 return false;  // ���� �ƴϸ� false ��ȯ
}

AddrNode* MyStack::PrintHead()  // ��� �������� ��� �ּҸ� ��ȯ
{
	return m_pHead;
}
