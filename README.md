# An Eventsystem In C++ without std::bind and std::function

This is an example for an eventsystem in C++. For more information see the corresponding [blog post](https://www.codingwiththomas.com/blog/an-eventsystem-without-std-bind-and-std-function)

## Usage
Create arbitrary events and share it in your code. This example is based on a bookstore which adds and removes books to the book stock and customers by calling the according `OnEvent` function. For illustration purpose I just printed the function calls.

````cpp
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
````

## Build And Run

Build this example with cmake and C++17

````
cmake -S . -B ./build
cmake --build ./build
./build/events

New customer event: NewCustomerEvent
    Id: 123
    Name: Thomas
    Address: Munich
Customer deleted event: DeleteCustomerEvent
    Id: 456
Book added event: BookAddedEvent
    Id: 753
    Title: A Cool Eventsystem
    Author: Thomas
    Published: 2022
Book removed event: BookRemovedEvent
    Id: 456
````





