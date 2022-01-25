

#include <iostream>
#include <string>

#include "Events/Event.hpp"
#include "Events/BookEvents.hpp"
#include "Events/CustomerEvents.hpp"

#include "BookStore/Stock.hpp"
#include "BookStore/Customers.hpp"

int main(int argc, char* argv[])
{
    // some classes in your code which handle customers and books
    Stock bookStock;
    Customers customers;

    // some events created by clients or any interface
    NewCustomerEvent newCustomer(123, "Thomas", "Munich");
    customers.OnEvent(newCustomer);

    DeleteCustomerEvent deleteCustomer(456);
    customers.OnEvent(deleteCustomer);
    
    BookAddedEvent addedBook(753, "A Cool Eventsystem", "Thomas", 2022);
    bookStock.OnEvent(addedBook);

    BookRemovedEvent removeBook(456);
    bookStock.OnEvent(removeBook);

    return 0;
}