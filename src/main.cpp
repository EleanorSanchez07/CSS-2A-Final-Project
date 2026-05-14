#include "./include/raylib/raylib-cpp.hpp"
raylib::Window window(1280, 800, "Untitled Spooky Game");

#include "./include/GameObject.hpp"
#include "./include/PhysicalGameObject.hpp"
#include "./include/Room.hpp"
#include "./include/Trigger.hpp"
#include "./include/DisplayTextTrigger.hpp"
#include "./include/Player.hpp"
#include "./include/GlobalRefs.hpp"
#include "./include/Enemy.hpp"
#include "./include/Items.hpp"

#include <iostream>
#include <memory>

int loc[2] = {};
Room demoLevel[6][6] = {
    {Room(), Room(), Room(), Room(), Room(), Room()},
    {Room(), Room(), Room(), Room(), Room(), Room()},
    {Room(), Room(), Room(), Room(), Room(), Room()},
    {Room(), Room(), Room(worldEnemies, worldItems), Room(), Room(), Room()},
    {Room(), Room(), Room(), Room(), Room(), Room()},
    {Room(), Room(), Room(), Room(), Room(), Room()}
};

raylib::Texture2D TEX_NOTHING = raylib::Texture2D("resources/transparent.png");
raylib::Texture2D BG = raylib::Texture2D("resources/background.png");
raylib::Texture2D TEX_PLAYER = raylib::Texture2D("resources/playerSheet.png");
raylib::Texture2D TEX_DARKNESS = raylib::Texture2D("resources/darkness.png");
raylib::Texture2D TEX_ENEMY = raylib::Texture2D("resources/enemy.png");

std::vector<PhysicalGameObject> worldObstacles = std::vector<PhysicalGameObject>();

int numTriggersInWorld = 0;
Trigger* worldTriggers[maxTriggersInWorld] = {};
Trigger* _worldTriggers[maxTriggersInWorld];

std::vector<Item> worldItems = std::vector<Item>();
std::vector<Enemy> worldEnemies = std::vector<Enemy>();

Player player;


// void enterRoom(Room r);
// void leaveRoom(Room& r);

int main() {

    window.SetExitKey(0);
    
    player.setPosition(window.GetSize() / 2 - player.getSize() / 2);


    //PhysicalGameObject player = PhysicalGameObject(&TEX_PLAYER);
    //player.setPosition(raylib::Vector2(window.GetWidth() / 2 - player.getSize().x / 2, window.GetHeight() / 2 - player.getSize().y / 2));
    // worldTriggers[numTriggersInWorld] = new DisplayTextTrigger({0, 300}, {128, 128}, "Hello World");
    // numTriggersInWorld++;

    raylib::Color background = raylib::Color(0, 0, 0, 255);
    
    SetTargetFPS(60);

    loc[0]=3;
    loc[1]=3;
    
    Enemy testEnemy = Enemy(player.getPositionReference(), player);
    worldEnemies.push_back(testEnemy);

    PhysicalGameObject topBound = PhysicalGameObject(&TEX_NOTHING);
    topBound.setCollisionShape({0, 0, 1280, 100});

    PhysicalGameObject bottomBound = PhysicalGameObject(&TEX_NOTHING);
    bottomBound.setCollisionShape({0, 700, 1280, 100});

    PhysicalGameObject leftBound = PhysicalGameObject(&TEX_NOTHING);
    leftBound.setCollisionShape({0, 0, 100, 800});

    PhysicalGameObject rightBound = PhysicalGameObject(&TEX_NOTHING);
    rightBound.setCollisionShape({1180, 0, 100, 800});

    worldObstacles.push_back(topBound);
    worldObstacles.push_back(bottomBound);
    worldObstacles.push_back(leftBound);
    worldObstacles.push_back(rightBound);

    demoLevel[3][3] = Room(worldEnemies, worldItems);

    // Main game loop
    while (!window.ShouldClose()) {   //Check if close button pressed on window.
        BeginDrawing();
            { //empty scope between begin and end draw; makes code prettier :3
                BG.Draw();

                player.tick();
                demoLevel[loc[0]][loc[1]].tick();

                // for(int i = 0; i < worldObstacles.size(); i++) worldObstacles[i].getCollisionShape().Draw({255, 0, 0, 255});

                window.ClearBackground(background);
                demoLevel[loc[0]][loc[1]].tick();
            }
        EndDrawing();
    }
    
    for(int i = 0; i < numTriggersInWorld; i++) {
        delete _worldTriggers[i];
    }

    return 0;
}

/*
//no longer needed
void enterRoom(Room r){
    // pulls out the vectors
    worldObstacles = r.Obstacles();
    worldTriggers = r.Triggers();
    worldEnemies = r.Enemies();
}
void leaveRoom(Room& r){
    // unsure if this is neccesary
    // sets the vectors to empty vectors
    r.setEnemies(worldEnemies);
    worldObstacles = std::vector<PhysicalGameObject>();
    worldTriggers = std::vector<PhysicalGameObject>();
    worldEnemies = std::vector<PhysicalGameObject>();
}
*/
void reset() {
    for(int i = 0; i < numTriggersInWorld; i++) {
        delete _worldTriggers[i];
    }
    numTriggersInWorld = 0;

    player.setPosition(window.GetSize() / 2 - player.getSize() / 2);
    player.setHealth(10);
    worldObstacles = std::vector<PhysicalGameObject>();
    numTriggersInWorld = 0;
    worldItems = std::vector<Item>();
    worldEnemies = std::vector<Enemy>();
    
    // worldTriggers[numTriggersInWorld] = new DisplayTextTrigger({0, 300}, {128, 128}, "Hello World");
    // numTriggersInWorld++;
}
