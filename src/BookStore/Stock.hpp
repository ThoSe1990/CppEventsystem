#ifndef BOOKSTORE_STOCK_HPP
#define BOOKSTORE_STOCK_HPP

#include "Events/Event.hpp"
#include "Events/BookEvents.hpp"

class Stock 
{
public:
    void OnEvent(Event& event)
    {
        Dispatcher dispatcher(event);
        dispatcher.Dispatch<BookAddedEvent>(BIND_MEMBERFUNC_WITH_EVENT(Stock::onBookAdded));
		dispatcher.Dispatch<BookRemovedEvent>(BIND_MEMBERFUNC_WITH_EVENT(Stock::onBookRemoved));
    }

private:

    void onBookAdded(BookAddedEvent& bookAddedEvent) 
    {
        std::cout << "Book added event: " << bookAddedEvent.GetName() << 
        "\n    Id: " << bookAddedEvent.id << 
        "\n    Title: " << bookAddedEvent.title << 
        "\n    Author: " << bookAddedEvent.author << 
        "\n    Published: " << bookAddedEvent.published << 
        '\n';
    }
    void onBookRemoved(BookRemovedEvent& bookRemovedEvent)
    {
        std::cout << "Book removed event: " << bookRemovedEvent.GetName() << 
        "\n    Id: " << bookRemovedEvent.id << 
        '\n';
    }

};

#endif