#ifndef __MENU_H__
#define __MENU_H__

#include "Account.h"
extern Account * accArr[];

int ShowMenu(void);		// �޴���� 
void MakeAccount(void);		// ���� ���� 
void DepositMoney(void);	// �Ա� 
void WithdrawMoney(void);	// ��� 
void ShowAllAccInfo(void);	// �ܾ���ȸ

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

#endif 
