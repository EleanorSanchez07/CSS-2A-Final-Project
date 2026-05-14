#include "./include/RoomChangeTrigger.hpp"
#include <iostream>

RoomChangeTrigger::RoomChangeTrigger(){
    direction = 0;
    message = "trigger not set up";
}

RoomChangeTrigger::RoomChangeTrigger(int direction, string message){
    this->direction = direction;
    this->message = message;
}

void RoomChangeTrigger::activate(){
    switch (direction)
    {
    case 0: // right
        if(loc[0]+1<lWidth && demoLevel[loc[0]+1][loc[1]].Exists())
            loc[0]++;
        else
            raylib::DrawText(message, 0, 0, 24, {255, 255, 255, 255});
        break;
    case 1: // down
        if(lHeight-loc[1]>=0 && demoLevel[loc[0]][loc[1]-1].Exists())
            loc[1]--;
        else
            raylib::DrawText(message, 0, 0, 24, {255, 255, 255, 255});
        break;
    case 2: // left
        if(lWidth-loc[0]>=0 && demoLevel[loc[0]-1][loc[1]].Exists())
            loc[0]--;
        else
            raylib::DrawText(message, 0, 0, 24, {255, 255, 255, 255});
        break;
    case 3: // up
        if(loc[1]+1<lHeight && demoLevel[loc[0]][loc[1]+1].Exists())
            loc[1]++;
        else
            raylib::DrawText(message, 0, 0, 24, {255, 255, 255, 255});
        break;
    default:
        cout << "something went wrong with a room trigger";
        break;
    }
}