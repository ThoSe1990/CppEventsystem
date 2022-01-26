
#include <iostream>

#include "BookStore/Customers.hpp"

void Customers::OnEvent(Event& event) {
    Dispatcher dispatcher(event);
    dispatcher.Dispatch<NewCustomerEvent>(BIND_MEMBERFUNC_WITH_EVENT(Customers::onNewCustomer));
    dispatcher.Dispatch<DeleteCustomerEvent>(BIND_MEMBERFUNC_WITH_EVENT(Customers::onCustomerDeleted));
}

void Customers::onNewCustomer(NewCustomerEvent& newCustomerEvent) {
    std::cout << "New customer event: " << newCustomerEvent.GetName() << 
    "\n    Id: " << newCustomerEvent.id << 
    "\n    Name: " << newCustomerEvent.name << 
    "\n    Address: " << newCustomerEvent.address << 
    '\n';
}
void Customers::onCustomerDeleted(DeleteCustomerEvent& deleteCustomerEvent) {
    std::cout << "Customer deleted event: " << deleteCustomerEvent.GetName() << 
    "\n    Id: " << deleteCustomerEvent.id << 
    '\n';
}