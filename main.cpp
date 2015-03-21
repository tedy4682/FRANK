#include "AddrManagement.h"

void main()
{
	AddrManagement* Addr = new AddrManagement;   // �ּҷ� Ŭ���� �����Ҵ�
	char Ftext [20] = {0, };     // �ּҷ� txt ���ϸ� ���� ����
	int sel = 0;              // select ����
	bool check = 0;           // check ����
	char name[20] = {0,};   // �̸� ����
	char phone[20] = {0,};  // ��ȭ��ȣ ����
	char group[20] = {0,};  // �׷�� ����
	char mail[30] = {0,};   // ���� ����
	char addr[40] = {0,};   // �ּ� ����
	char birth[20] = {0,};  // ������� ����
	int  age = 0;           // ���� ����

	cout<<"1.LoadFile   2.InsertAddr   3.DeleteAddr  4.EditGroup"<<endl;
	cout<<"5.EditAddr   6.UpdateList   7.UndoDelete  8.PrintAll"<<endl;
	cout<<"9.PrintName 10.PrintGroup  11.SaveFile   12.EXIT"<<endl;
	cout<<"----------------------------------------------------"<<endl;

	while(1)
	{
		check=0;
		cout<<"Select case : ";
		cin>>sel;
		if(sel==1)                // LoadFile  ��, �ּҷ��� �ҷ��� ��
		{
			fflush(stdin);
			cout<<"Input text name : ";    // �ؽ�Ʈ ���ϸ� �о��
			cin>>Ftext;

			check = Addr->LoadFile(Ftext);      // �ش� �ؽ�Ʈ ���ϸ����� �ּҷ��� �ҷ���
			if(check) cout<<"LoadFile Success"<<endl;   // �������� ��
			else cout<<"LoadFile Fail"<<endl;           // �������� ��
		}
		else if(sel==2)           // InsertAddr    ��, �ּҷϿ� ��� �ϳ��� �߰��� ��
		{
			fflush(stdin);
			AddrNode* pNew = new AddrNode;  // ��� �߰� �����Ҵ� 

			cout<<"Input Name : ";
			cin.getline(name, 20);   // �̸� ���� �ʱ�ȭ
			pNew->SetName(name);     // ����� �̸� ��������� �ʱ�ȭ
			fflush(stdin);

			cout<<"Input Phone number : ";
			cin.getline(phone, 20);  // ��ȭ��ȣ ���� �ʱ�ȭ
			pNew->SetPhone(phone);   // ����� ��ȭ��ȣ ��������� �ʱ�ȭ
			fflush(stdin);

			cout<<"Input Group : ";
			cin.getline(group, 20);  // �׷�� ���� �ʱ�ȭ
			pNew->SetGroup(group);   // ����� �׷�� ��������� �ʱ�ȭ
			fflush(stdin);

			cout<<"Input E-mail : ";
			cin.getline(mail, 30);   // ���� ���� �ʱ�ȭ
			pNew->SetMail(mail);     // ����� ���� ��������� �ʱ�ȭ
			fflush(stdin);

			cout<<"Input Address : ";
			cin.getline(addr, 40);   // �ּ� ���� �ʱ�ȭ
			pNew->SetAddr(addr);     // ����� �ּ� ��������� �ʱ�ȭ
			fflush(stdin);

			cout<<"Input Birth : ";
			cin.getline(birth, 20);  // ������� ���� �ʱ�ȭ
			pNew->SetBirth(birth);   // ����� ������� ��������� �ʱ�ȭ
			fflush(stdin);

			cout<<"Input Age : ";
			cin>>age;                // ���� ���� �ʱ�ȭ
			pNew->SetAge(age);       // ����� ���� ��������� �ʱ�ȭ
			fflush(stdin);

			check = Addr->InsertAddr(pNew);   // �Է¹��� ���ο� ��� �ּҷ� Ŭ������ ��� �߰�
			
			if(check) cout<<"InsertAddr Success"<<endl;   // ��尡 ���������� �߰��Ǿ��� �� 

		}
		else if(sel==3)          // DeleteAddr      ��, ��� �ϳ��� ����Ʈ���� ������ ��
		{
			fflush(stdin);
			cout<<"Input Name : ";
			cin.getline(name, 20);     // �̸� ���� �ʱ�ȭ
			check = Addr->DeleteAddr(name);  // ����Ʈ ����Լ��� DeleteAddr �Լ� ���� (�Ű����� : �̸�)

			if(check) cout<<"DeleteAddr Success"<<endl;  // ��尡 ����Ʈ���� ���������� ���ŵǾ��� ��
			else      cout<<"DeleteAddr Fail"<<endl;     // �����Ͽ��� ��
		}
		else if(sel==4)			// EditGroup         ��, ������ �׷� �� ���� Ȥ�� ������ ��
		{
			fflush(stdin);
			cout<<"Input Group : ";    
			cin.getline(group, 20);   // �׷� ���� �ʱ�ȭ
			check = Addr->EditGroup(group);   // �Է¹��� �׷� ���� �Ű��������Ͽ� �׷�� ���� �� �����Լ� ����

			if(check) cout<<"EditGroup Success"<<endl;  // ���� ��
			else      cout<<"EditGroup Fail"<<endl;     // ���� ��
		}
		else if(sel==5)			// EditAddr      ��� ������ ��
		{
			fflush(stdin);
			cout<<"Input name : ";
			cin.getline(name, 20);      // �˻��� ����� �̸� �̸� ������ �ʱ�ȭ
			check = Addr->EditAddr(name);    // �˻��� �̸����� ��带 ã�� ���ϴ� �κ��� ����

			if(check) cout<<"EditAddr Success"<<endl;  // ���� ��
			else      cout<<"EditAddr Fail"<<endl;     // ���� ��
		}
		else if(sel==6)			// UpdateList   , �ٸ� �ּҷ��� �߰��� ���� ��
		{
			fflush(stdin);
			cout<<"Input text name : ";
			cin>>Ftext;                    // �ٸ� �ּҷ� txt���� �Է�

			check = Addr->UpdateList(Ftext);     // �Է��� �ؽ�Ʈ ������ �ּҷϿ� �߰�

			if(check) cout<<"UpdateList Success"<<endl;   // ���� ��
			else      cout<<"UpdateList Fail"<<endl;      // ���� ��
		}
		else if(sel==7)			// UndoDelete   , ���� ����ϰ� ���� ��
		{
			check = Addr->UndoDelete();   // ���� ��� ����

			if(check) cout<<"UndoDelete Success"<<endl; // ���� ��
			else      cout<<"UndoDelete Fail"<<endl;    // ���� ��
		}
		else if(sel==8)			// PrintAll   , ��� ����� ������ ����ϰ� ���� ��
		{
			check = Addr->PrintAddr();   // ��� ��� ������ ���

			if(check) cout<<"PrintAll Success"<<endl;  // ���� ��
			else      cout<<"PrintAll Fail"<<endl;     // ���� ��
		}
		else if(sel==9)			// PrintName  , Ư�� �̸��� ��� �����͸� ����ϰ� ���� ��
		{
			fflush(stdin);
			cout<<"Input name : ";
			cin.getline(name, 20);   // �̸� ���� �ʱ�ȭ
			
			check = Addr->PrintAddr(name);   // Ư�� �̸��� �Ű������� �� ����Լ� ����

			if(check) cout<<"PrintName Success"<<endl;   // ���� ��
			else      cout<<"PrintName Fail"<<endl;      // ���� ��
		}
		else if(sel==10)			// PrintGroup  , Ư�� �׷���� ��� �����͸� ����ϰ� ���� ��
		{
			fflush(stdin);
			cout<<"Input group : ";
			cin.getline(group, 20);    // �׷�� ���� �ʱ�ȭ
			
			check = Addr->PrintGroup(group);    // Ư�� �׷���� �Ű������� �� ����Լ� ����

			if(check) cout<<"PrintGroup Success"<<endl;   // ���� ��
			else      cout<<"PrintGroup Fail"<<endl;      // ���� ��
		}
		else if(sel==11)			// SaveFile   , �ּҷ��� ��� �����͸� �ؽ�Ʈ�� �����ϰ� ���� ��
		{
			fflush(stdin);
			cout<<"Input text name : ";
			cin>>Ftext;           // �ؽ�Ʈ ���ϸ� �ʱ�ȭ
			
			check = Addr->SaveFile(Ftext);    // �ش� �ؽ�Ʈ ���ϸ� ������ �ʱ�ȭ ����
			
			if(check) cout<<"SaveFile Success"<<endl;   // ���� ��
			else      cout<<"SaveFile Fail"<<endl;      // ���� ��
		}
		else if(sel==12)			// ����
		{
			cout<<"Quit program"<<endl;
			Addr->~AddrManagement();
			delete Addr;
			return ;
		}
		else                    // �߸��� �Է��� ��
		{
			cout << " Input error " << endl;
			system("pause");
		}
		fflush(stdin);
	}
	return ;

	
}