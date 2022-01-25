#ifndef EVENTS_BOOKEVENTS_HPP
#define EVENTS_BOOKEVENTS_HPP


#include "Events/Event.hpp"


class BookAddedEvent : public Event 
{
public:
    BookAddedEvent(std::size_t Id, const std::string& Title, const std::string& Author, int Published) :
        id(Id), title(Title), author(Author), published(Published)
        {}

    std::size_t id;
    std::string title;
    std::string author;
    int published;
    
    EVENT_CLASS_TYPE(BookAddedEvent);

};

class BookRemovedEvent : public Event 
{
public:
    BookRemovedEvent(std::size_t Id) :
        id(Id)
        {}

    std::size_t id;
    
    EVENT_CLASS_TYPE(BookRemovedEvent);

};



#endif