
#include <iostream>

#include "BookStore/Stock.hpp"

void Stock::OnEvent(Event& event)
{
    Dispatcher dispatcher(event);
    dispatcher.Dispatch<BookAddedEvent>(BIND_MEMBERFUNC_WITH_EVENT(Stock::onBookAdded));
    dispatcher.Dispatch<BookRemovedEvent>(BIND_MEMBERFUNC_WITH_EVENT(Stock::onBookRemoved));
}

void Stock::onBookAdded(BookAddedEvent& bookAddedEvent) 
{
    std::cout << "Book added event: " << bookAddedEvent.GetName() << 
    "\n    Id: " << bookAddedEvent.id << 
    "\n    Title: " << bookAddedEvent.title << 
    "\n    Author: " << bookAddedEvent.author << 
    "\n    Published: " << bookAddedEvent.published << 
    '\n';
}
void Stock::onBookRemoved(BookRemovedEvent& bookRemovedEvent)
{
    std::cout << "Book removed event: " << bookRemovedEvent.GetName() << 
    "\n    Id: " << bookRemovedEvent.id << 
    '\n';
}
