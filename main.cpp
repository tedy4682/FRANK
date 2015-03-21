#include "AddrManagement.h"

void main()
{
	AddrManagement* Addr = new AddrManagement;   // 주소록 클래스 동적할당
	char Ftext [20] = {0, };     // 주소록 txt 파일명 받을 변수
	int sel = 0;              // select 변수
	bool check = 0;           // check 변수
	char name[20] = {0,};   // 이름 변수
	char phone[20] = {0,};  // 전화번호 변수
	char group[20] = {0,};  // 그룹명 변수
	char mail[30] = {0,};   // 메일 변수
	char addr[40] = {0,};   // 주소 변수
	char birth[20] = {0,};  // 생년월일 변수
	int  age = 0;           // 나이 변수

	cout<<"1.LoadFile   2.InsertAddr   3.DeleteAddr  4.EditGroup"<<endl;
	cout<<"5.EditAddr   6.UpdateList   7.UndoDelete  8.PrintAll"<<endl;
	cout<<"9.PrintName 10.PrintGroup  11.SaveFile   12.EXIT"<<endl;
	cout<<"----------------------------------------------------"<<endl;

	while(1)
	{
		check=0;
		cout<<"Select case : ";
		cin>>sel;
		if(sel==1)                // LoadFile  즉, 주소록을 불러올 때
		{
			fflush(stdin);
			cout<<"Input text name : ";    // 텍스트 파일명 읽어옴
			cin>>Ftext;

			check = Addr->LoadFile(Ftext);      // 해당 텍스트 파일명으로 주소록을 불러옴
			if(check) cout<<"LoadFile Success"<<endl;   // 성공했을 때
			else cout<<"LoadFile Fail"<<endl;           // 실패했을 때
		}
		else if(sel==2)           // InsertAddr    즉, 주소록에 노드 하나만 추가할 때
		{
			fflush(stdin);
			AddrNode* pNew = new AddrNode;  // 노드 추가 동적할당 

			cout<<"Input Name : ";
			cin.getline(name, 20);   // 이름 변수 초기화
			pNew->SetName(name);     // 노드의 이름 멤버변수에 초기화
			fflush(stdin);

			cout<<"Input Phone number : ";
			cin.getline(phone, 20);  // 전화번호 변수 초기화
			pNew->SetPhone(phone);   // 노드의 전화번호 멤버변수에 초기화
			fflush(stdin);

			cout<<"Input Group : ";
			cin.getline(group, 20);  // 그룹명 변수 초기화
			pNew->SetGroup(group);   // 노드의 그룹명 멤버변수에 초기화
			fflush(stdin);

			cout<<"Input E-mail : ";
			cin.getline(mail, 30);   // 메일 변수 초기화
			pNew->SetMail(mail);     // 노드의 메일 멤버변수에 초기화
			fflush(stdin);

			cout<<"Input Address : ";
			cin.getline(addr, 40);   // 주소 변수 초기화
			pNew->SetAddr(addr);     // 노드의 주소 멤버변수에 초기화
			fflush(stdin);

			cout<<"Input Birth : ";
			cin.getline(birth, 20);  // 생년월일 변수 초기화
			pNew->SetBirth(birth);   // 노드의 생년월일 멤버변수에 초기화
			fflush(stdin);

			cout<<"Input Age : ";
			cin>>age;                // 나이 변수 초기화
			pNew->SetAge(age);       // 노드의 나이 멤버변수에 초기화
			fflush(stdin);

			check = Addr->InsertAddr(pNew);   // 입력받은 새로운 노드 주소록 클래스에 노드 추가
			
			if(check) cout<<"InsertAddr Success"<<endl;   // 노드가 성공적으로 추가되었을 때 

		}
		else if(sel==3)          // DeleteAddr      즉, 노드 하나를 리스트에서 제거할 때
		{
			fflush(stdin);
			cout<<"Input Name : ";
			cin.getline(name, 20);     // 이름 변수 초기화
			check = Addr->DeleteAddr(name);  // 리스트 멤버함수인 DeleteAddr 함수 수행 (매개변수 : 이름)

			if(check) cout<<"DeleteAddr Success"<<endl;  // 노드가 리스트에서 성공적으로 제거되었을 때
			else      cout<<"DeleteAddr Fail"<<endl;     // 실패하였을 때
		}
		else if(sel==4)			// EditGroup         즉, 노드들의 그룹 명 변경 혹은 제거할 때
		{
			fflush(stdin);
			cout<<"Input Group : ";    
			cin.getline(group, 20);   // 그룹 변수 초기화
			check = Addr->EditGroup(group);   // 입력받은 그룹 값을 매개변수로하여 그룹명 변경 및 제거함수 시행

			if(check) cout<<"EditGroup Success"<<endl;  // 성공 시
			else      cout<<"EditGroup Fail"<<endl;     // 실패 시
		}
		else if(sel==5)			// EditAddr      노드 수정할 때
		{
			fflush(stdin);
			cout<<"Input name : ";
			cin.getline(name, 20);      // 검색할 노드의 이름 이름 변수에 초기화
			check = Addr->EditAddr(name);    // 검색한 이름으로 노드를 찾아 원하는 부분을 수정

			if(check) cout<<"EditAddr Success"<<endl;  // 성공 시
			else      cout<<"EditAddr Fail"<<endl;     // 실패 시
		}
		else if(sel==6)			// UpdateList   , 다른 주소록을 추가로 넣을 때
		{
			fflush(stdin);
			cout<<"Input text name : ";
			cin>>Ftext;                    // 다른 주소록 txt파일 입력

			check = Addr->UpdateList(Ftext);     // 입력한 텍스트 파일을 주소록에 추가

			if(check) cout<<"UpdateList Success"<<endl;   // 성공 시
			else      cout<<"UpdateList Fail"<<endl;      // 실패 시
		}
		else if(sel==7)			// UndoDelete   , 삭제 취소하고 싶을 때
		{
			check = Addr->UndoDelete();   // 삭제 취소 실행

			if(check) cout<<"UndoDelete Success"<<endl; // 성공 시
			else      cout<<"UndoDelete Fail"<<endl;    // 실패 시
		}
		else if(sel==8)			// PrintAll   , 모든 노드의 데이터 출력하고 싶을 때
		{
			check = Addr->PrintAddr();   // 모든 노드 데이터 출력

			if(check) cout<<"PrintAll Success"<<endl;  // 성공 시
			else      cout<<"PrintAll Fail"<<endl;     // 실패 시
		}
		else if(sel==9)			// PrintName  , 특정 이름의 노드 데이터만 출력하고 싶을 때
		{
			fflush(stdin);
			cout<<"Input name : ";
			cin.getline(name, 20);   // 이름 변수 초기화
			
			check = Addr->PrintAddr(name);   // 특정 이름을 매개변수로 한 출력함수 실행

			if(check) cout<<"PrintName Success"<<endl;   // 성공 시
			else      cout<<"PrintName Fail"<<endl;      // 실패 시
		}
		else if(sel==10)			// PrintGroup  , 특정 그룹명의 노드 데이터만 출력하고 싶을 때
		{
			fflush(stdin);
			cout<<"Input group : ";
			cin.getline(group, 20);    // 그룹명 변수 초기화
			
			check = Addr->PrintGroup(group);    // 특정 그룹명을 매개변수로 한 출력함수 실행

			if(check) cout<<"PrintGroup Success"<<endl;   // 성공 시
			else      cout<<"PrintGroup Fail"<<endl;      // 실패 시
		}
		else if(sel==11)			// SaveFile   , 주소록의 모든 데이터를 텍스트에 저장하고 싶을 때
		{
			fflush(stdin);
			cout<<"Input text name : ";
			cin>>Ftext;           // 텍스트 파일명 초기화
			
			check = Addr->SaveFile(Ftext);    // 해당 텍스트 파일명에 데이터 초기화 실행
			
			if(check) cout<<"SaveFile Success"<<endl;   // 성공 시
			else      cout<<"SaveFile Fail"<<endl;      // 실패 시
		}
		else if(sel==12)			// 종료
		{
			cout<<"Quit program"<<endl;
			Addr->~AddrManagement();
			delete Addr;
			return ;
		}
		else                    // 잘못된 입력일 때
		{
			cout << " Input error " << endl;
			system("pause");
		}
		fflush(stdin);
	}
	return ;

	
}