#pragma once
#include "Trigger.hpp"
#include "Room.hpp"
#include "./GlobalRefs.hpp"

class RoomChangeTrigger : public Trigger{
    public:
        RoomChangeTrigger();
        RoomChangeTrigger(int direction, string message);
        virtual void activate();
    private:
        int direction;
        string message;

};