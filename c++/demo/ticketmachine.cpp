#include "ticketmachine.h"
#include <iostream>


using namespace std ;
TicketMachine::TicketMachine() : price(0) {
	 // ToDo Auto -generated constructor stub 
}

TicketMachine::~TicketMachine() {

}

void TicketMachine::showPrompt() {
	cout << "Something" ;

}
void TicketMachine::insertMoney(int money){
	balance += money ;
}

void TicketMachine::showBalance() {
	cout << balance ;
}

