#include "World.h"
#include <memory>
#include <minwindef.h>
#include <string>
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
    int moneyCounter;
    bool isGameEnd;
    
    inline bool endGame(const std::string& STR){
        clear();
        std::cout << STR << " Your score: "<< moneyCounter << std::endl;
        getch();
        return true;
    }

    GameProcess() : theWorld(
    "|-------------|\n"
    "|+            |\n" 
    "|        @    |\n"
    "|      $      |\n"
    "| @   ---     |\n"
    "|---          |\n"
    "|          $  |\n"
    "|         --- |\n"
    "| ---@        |\n"
    "|           @ |\n"
    "|F        $   |\n"
    "|-----===--^^^|"), 
    thePlayer{std::dynamic_pointer_cast<Player>(theWorld.getObjectPtr(theWorld.findObject('+')))}, 
    isGameEnd{false}, moneyCounter(0)
    {
        thePlayer->setObject(theWorld.findObject('+'));
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

    void moveObjects(){
        for (std::pair<std::shared_ptr<MovebleObject>, char>& objectMoveble : theWorld.getObjectsMoveble()) {
            int objectCoorY = objectMoveble.first->getObject().first, objectCoorX = objectMoveble.first->getObject().second;
            int modX = 0, modY = 0;
            switch (objectMoveble.second) {
                case 'r': {
                    const char lookObject = theWorld.getObject(objectCoorY,objectCoorX + 1).getLook();
                    if(lookObject == ' ') modX = 1;
                    else if(lookObject == thePlayer->getLook()) isGameEnd = endGame("You are lose.");
                    else objectMoveble.second = 'l';
                } 
                break;
                case 'l': {
                    const char lookObject = theWorld.getObject(objectCoorY,objectCoorX - 1).getLook();
                    if(lookObject == ' ') modX = -1;
                    else if(lookObject == thePlayer->getLook()) isGameEnd =endGame("You are lose.");
                    else objectMoveble.second = 'r';
                } 
                break;
            }
            if(!isGameEnd){
            std::swap(theWorld.getObject(objectCoorY , objectCoorX), theWorld.getObject(objectCoorY + modY,objectCoorX + modX));
            objectMoveble.first = std::make_shared<MovebleObject>(*std::dynamic_pointer_cast<Object>(theWorld.getObjectPtr(objectCoorY + modY,objectCoorX + modX)));
            theWorld.getObjectPtr(objectCoorY + modY,objectCoorX + modX) = std::dynamic_pointer_cast<Object>(objectMoveble.first);
            objectMoveble.first->setObject(objectCoorY + modY,objectCoorX + modX); 
            }
        }
    }
};