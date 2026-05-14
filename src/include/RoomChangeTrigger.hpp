#pragma once
#include "Trigger.hpp"
#include "Room.hpp"
#include "./GlobalRefs.hpp"

class RoomChangeTrigger : public Trigger{
    public:
        RoomChangeTrigger();
        RoomChangeTrigger(int direction, string message);
        virtual void activate();
        void reload();
    private:
        int direction;
        string message;

};