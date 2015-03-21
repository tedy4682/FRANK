#include "AddrNode.h"

class MyStack
{
private:
	AddrNode* m_pHead;   // ������ ���������
	int m_Size;          // ���� ũ�� ����
public:
	MyStack();     // ������
	~MyStack();    // �Ҹ���
	void SetSize(int Size);  // ���� ũ�� �ʱ�ȭ
	bool Push(AddrNode* pAddrNode);   // ���� PUSH
	AddrNode* Pop();     // ���� POP
	bool IsFull();       // ������ ���� á���� Ȯ���ϴ� �Լ�
	bool IsEmpty();      // ������ ������� Ȯ���ϴ� �Լ�
	AddrNode* PrintHead();   // ��� �ּҰ� ��ȯ
};

