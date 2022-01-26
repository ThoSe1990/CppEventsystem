#ifndef BOOKSTORE_STOCK_HPP
#define BOOKSTORE_STOCK_HPP

#include "Events/Event.hpp"
#include "Events/BookEvents.hpp"

class Stock 
{
public:
    void OnEvent(Event& event);
private:
    void onBookAdded(BookAddedEvent& bookAddedEvent);
    void onBookRemoved(BookRemovedEvent& bookRemovedEvent);
};

#endif