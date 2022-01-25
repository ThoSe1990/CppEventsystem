#ifndef BOOKSTORE_CUSTOMERS_HPP
#define BOOKSTORE_CUSTOMERS_HPP


#include "Events/Event.hpp"
#include "Events/CustomerEvents.hpp"

class Customers
{
public:
    void OnEvent(Event& event)
    {
        Dispatcher dispatcher(event);
        dispatcher.Dispatch<NewCustomerEvent>(BIND_MEMBERFUNC_WITH_EVENT(Customers::onNewCustomer));
		dispatcher.Dispatch<DeleteCustomerEvent>(BIND_MEMBERFUNC_WITH_EVENT(Customers::onCustomerDeleted));
    }

private:

    void onNewCustomer(NewCustomerEvent& newCustomerEvent) 
    {
        std::cout << "New customer event: " << newCustomerEvent.GetName() << 
        "\n    Id: " << newCustomerEvent.id << 
        "\n    Name: " << newCustomerEvent.name << 
        "\n    Address: " << newCustomerEvent.address << 
        '\n';
    }
    void onCustomerDeleted(DeleteCustomerEvent& deleteCustomerEvent)
    {
        std::cout << "Customer deleted event: " << deleteCustomerEvent.GetName() << 
        "\n    Id: " << deleteCustomerEvent.id << 
        '\n';
    }

};

#endif