#ifndef EVENTS_CUSTOMEREVENTS_HPP
#define EVENTS_CUSTOMEREVENTS_HPP


#include "Events/Event.hpp"

class NewCustomerEvent : public Event 
{
public:
    NewCustomerEvent(std::size_t Id, const std::string& Name, const std::string& Address) :
        id(Id), name(Name), address(Address) 
        {}

    std::size_t id;
    std::string name;
    std::string address;

    EVENT_CLASS_TYPE(NewCustomerEvent);

};

class DeleteCustomerEvent : public Event 
{
public:
    DeleteCustomerEvent(std::size_t Id) :
        id(Id)
        {}

    std::size_t id;

    EVENT_CLASS_TYPE(DeleteCustomerEvent);

};


#endif