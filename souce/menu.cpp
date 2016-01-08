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
	cout<<"1. 계좌개설"<<endl;
	cout<<"2. 입 금"<<endl;
	cout<<"3. 출 금"<<endl;
	cout<<"4. 계좌정보 전체 출력"<<endl;
	cout<<"5. 프로그램 종료"<<endl;
	cout<<"선택: ";
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
	
	cout<<"[계좌개설]"<<endl;
	cout<<"계좌ID: ";	cin>>id;
	cout<<"이 름: ";	cin>>name;
	cout<<"입금액: ";	cin>>balance;
	cout<<endl;
	
	accArr[Account::accNum++] = new Account(id, balance, name);
}

void DepositMoney(void)
{
	int money;
	int id;
	
	cout<<"[입 금]"<<endl;
	cout<<"계좌ID: ";	cin>>id;
	for(int i=0; i<Account::accNum; i++)
	{
		if(id == accArr[i]->GetAccId())
		{
			cout<<"입금액: ";	cin>>money; 
			accArr[i]->Deposit(money);
			cout<<"입금완료. 잔액: "<<accArr[i]->GetBalance()<<endl<<endl;
			return;
		}
	}
	cout<<"유효하지 않은 ID입니다."<<endl<<endl; 
}
	 
void WithdrawMoney(void)
{
	int money;
	int id;
	
	cout<<"[출 금]"<<endl;
	cout<<"계좌ID: ";	cin>>id;
	for(int i=0; i<Account::accNum; i++)
	{
		if(id == accArr[i]->GetAccId())
		{
			cout<<"출금액: ";	cin>>money; 
			if(accArr[i]->Withdraw(money) == 0)
			{
				cout<<"잔액부족"<<endl;
				return;
			}
			cout<<"출금완료. 잔액: "<<accArr[i]->GetBalance()<<endl<<endl;
			
			return; 
		}
	}
	cout<<"유효하지 않은 ID입니다."<<endl<<endl; 
}

void ShowAllAccInfo(void)
{
	for(int i=0; i<Account::accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout<<endl;
	}
}
