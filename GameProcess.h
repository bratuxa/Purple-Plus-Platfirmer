#include "World.h"
#include "Player.h"
#include <memory>

class GameProcess{
    World theWorld;
    Player thePlayer;
    static std::shared_ptr<GameProcess> gameProcess;

    GameProcess() : theWorld("|             |\n" 
                                         "|+            |\n"
                                        "|-------------|"), 
    thePlayer()
    {
        std::pair<int, int> pait = theWorld.findObject('+');
        thePlayer = Player(pait.first,pait.second);
    }

    void gameCycle(){

    }

    public:

    void test(){
        std::cout << *theWorld.getObjectPtr(1, 1);
    }
    static std::shared_ptr<GameProcess> getGameProcess();
};