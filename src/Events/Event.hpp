#ifndef EVENTS_EVENTS_HPP
#define EVENTS_EVENTS_HPP



#define BIND_MEMBERFUNC_WITH_EVENT(member_function) [this](auto&&... args) { return this->member_function(std::forward<decltype(args)>(args)...); }
#define BIND_MEMBERFUNC_WO_EVENT(member_function) [this]() { return this->member_function(); }
#define BIND_FUNC_WITH_EVENT(function) []() { return function(); }
#define BIND_FUNC_WO_EVENT(function) [](auto&&... args) { return function(std::forward<decltype(args)>(args)...); }


enum class EventType 
{
    none = 0,
    BookAddedEvent, BookRemovedEvent,
    NewCustomerEvent, DeleteCustomerEvent
};

class Event 
{
public:

    virtual ~Event() = default;

    virtual EventType GetType() const = 0;
    virtual const char* GetName() const = 0;
    bool Handled = false;
};


#define EVENT_CLASS_TYPE(type) static EventType GetConcreteType() { return EventType::type; }\
                                EventType GetType() const override { return GetConcreteType(); }\
                                const char* GetName() const override { return #type; }




class Dispatcher 
{
    Event& event;
public: 
    Dispatcher(Event& e ) : event(e) {}

    template<typename T, typename F> 
    void Dispatch(const F& function) 
    {
        if (event.GetType() == T::GetConcreteType())
        {
            function(static_cast<T&>(event));
            event.Handled = true;
        }
    }

    template<typename T, typename F> 
    void DispatchWithoutEvent(const F& function) 
    {
        if (event.GetType() == T::GetConcreteType())
        {
            function();
            event.Handled = true;
        }
    }
};



#endif