#include "World.h"
#include <memory>
#include <minwindef.h>
#include <utility>
#include "conio.h"

#ifdef _WIN32
        #include "windows.h"
        #else
        #include <unistd.h>
        #endif

class GameProcess{
    World theWorld;
    std::shared_ptr<Player> thePlayer;
    static std::shared_ptr<GameProcess> gameProcess;

    GameProcess() : theWorld(
    "|-------------|\n"
    "|+            |\n" 
    "|             |\n"
    "|             |\n"
    "|      -      |\n"
    "|-            |\n"
    "|             |\n"
    "|          -  |\n"
    "|  -          |\n"
    "|             |\n"
    "|             |\n"
    "|-------------|"), 
    thePlayer{std::dynamic_pointer_cast<Player>(theWorld.getObjectPtr(theWorld.findObject('+')))}
    {
        thePlayer->setPlayer(theWorld.findObject('+'));
    }

    inline void clear(){
        #ifdef _WIN32
        std::system("cls");
        #else
        std::system ("clear");
        #endif
    }

    inline void sleep(const int TIME){
        #ifdef _WIN32
        Sleep(TIME);
        #else
        sleep(TIME);
        #endif
    }


    inline void print(){ clear(); std::cout << theWorld; }
    
    void playerMove(const int MOVE_Y, const int MOVE_X);

    void gameLogic();

    public:

    void test(){
        gameLogic();
    }
    static std::shared_ptr<GameProcess> getGameProcess();
};