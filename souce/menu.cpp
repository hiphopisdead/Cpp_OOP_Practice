#include <iostream>
#include "menu.h"
#define NAME_LEN 20
using std::cout;
using std::endl;
using std::cin;

int ShowMenu(void)
{
	int select;
	cout<<"----Menu-----"<<endl;
	cout<<"1. ���°���"<<endl;
	cout<<"2. �� ��"<<endl;
	cout<<"3. �� ��"<<endl;
	cout<<"4. �������� ��ü ���"<<endl;
	cout<<"5. ���α׷� ����"<<endl;
	cout<<"����: ";
	cin>>select;
	cout<<endl; 
	
	switch(select)
	{
		case MAKE:
			return MAKE;
		case DEPOSIT:
			return DEPOSIT;
		case WITHDRAW:
			return WITHDRAW;
		case INQUIRE:
			return INQUIRE;
		case EXIT:
			return EXIT;
		default:
			cout<<"Illegal selection.."<<endl;
			return 0;
	}		
}

void MakeAccount(void) 
{
	int id;
	char name[NAME_LEN];
	int balance;
	
	cout<<"[���°���]"<<endl;
	cout<<"����ID: ";	cin>>id;
	cout<<"�� ��: ";	cin>>name;
	cout<<"�Աݾ�: ";	cin>>balance;
	cout<<endl;
	
	accArr[Account::accNum++] = new Account(id, balance, name);
}

void DepositMoney(void)
{
	int money;
	int id;
	
	cout<<"[�� ��]"<<endl;
	cout<<"����ID: ";	cin>>id;
	for(int i=0; i<Account::accNum; i++)
	{
		if(id == accArr[i]->GetAccId())
		{
			cout<<"�Աݾ�: ";	cin>>money; 
			accArr[i]->Deposit(money);
			cout<<"�ԱݿϷ�. �ܾ�: "<<accArr[i]->GetBalance()<<endl<<endl;
			return;
		}
	}
	cout<<"��ȿ���� ���� ID�Դϴ�."<<endl<<endl; 
}
	 
void WithdrawMoney(void)
{
	int money;
	int id;
	
	cout<<"[�� ��]"<<endl;
	cout<<"����ID: ";	cin>>id;
	for(int i=0; i<Account::accNum; i++)
	{
		if(id == accArr[i]->GetAccId())
		{
			cout<<"��ݾ�: ";	cin>>money; 
			if(accArr[i]->Withdraw(money) == 0)
			{
				cout<<"�ܾ׺���"<<endl;
				return;
			}
			cout<<"��ݿϷ�. �ܾ�: "<<accArr[i]->GetBalance()<<endl<<endl;
			
			return; 
		}
	}
	cout<<"��ȿ���� ���� ID�Դϴ�."<<endl<<endl; 
}

void ShowAllAccInfo(void)
{
	for(int i=0; i<Account::accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout<<endl;
	}
}
