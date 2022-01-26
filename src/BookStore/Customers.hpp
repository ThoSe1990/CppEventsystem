#ifndef BOOKSTORE_CUSTOMERS_HPP
#define BOOKSTORE_CUSTOMERS_HPP


#include "Events/Event.hpp"
#include "Events/CustomerEvents.hpp"

class Customers 
{
public:
    void OnEvent(Event& event);
private:
    void onNewCustomer(NewCustomerEvent& newCustomerEvent);
    void onCustomerDeleted(DeleteCustomerEvent& deleteCustomerEvent);
};



#endif