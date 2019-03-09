#ifndef _TICKETMACHINE_H_
#define _TICKETMACHINE_H_

class TicketMachine {
public :
	TicketMachine() ;
	virtual ~TicketMachine() ;
	void showPrompt() ;
	void insertMoney(int money) ;
	void showBalance() ;
	void printTicket() ;
	void showTotal() ;
private :
	const int price ;
	int balance ;
	int total ;
} ;



#endif 