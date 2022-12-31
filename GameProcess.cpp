#include "GameProcess.h"
#include <synchapi.h>
#include <utility>

std::shared_ptr<GameProcess> GameProcess::gameProcess = NULL;

std::shared_ptr<GameProcess> GameProcess::getGameProcess(){
    if(gameProcess == NULL) gameProcess = std::shared_ptr<GameProcess>(new GameProcess());
    return gameProcess;
}

void GameProcess::playerMove(const int MOVE_Y, const int MOVE_X){
    std::pair<int, int> playerCoords = thePlayer->getPlayer();
    int targetY = playerCoords.first + MOVE_Y, targetX = playerCoords.second + MOVE_X;
    if(theWorld.getObject(targetY, targetX).getLook() == ' '){
        std::swap(theWorld.getObject(playerCoords.first, playerCoords.second), theWorld.getObject(targetY, targetX));
        thePlayer = std::static_pointer_cast<Player>(theWorld.getObjectPtr(targetY, targetX));
        thePlayer->setPlayer(targetY,targetX);
    }
}

void GameProcess::gameLogic(){
    int inertiaForceY{0};
    bool lookAnimationCounter = true;
    while (true) {  
        print();
        if(kbhit()) {  
            switch (getch()) {
                case 'd': case 77 : { thePlayer->nextFrameAnimation(); playerMove(0, 1);  } break;        // d, стрелка вправо
                case 'a': case 75 : { thePlayer->nextFrameAnimation(); playerMove(0, -1); } break;       // a, стрелка влево
                case 32 : case 'w': case 72: {                                                                          // пробел, w, стрелка вверх
                    if(theWorld.getObject(thePlayer->getPlayer().first + 1, thePlayer->getPlayer().second).getLook() != ' '){
                        playerMove(-1, 0);
                        inertiaForceY = 5;
                    }
                }
            }    
        }
        if(inertiaForceY != 0){
            sleep(200);
            if(inertiaForceY > 3) playerMove(-1, 0);
            --inertiaForceY;
        } 
        if(theWorld.getObject(thePlayer->getPlayer().first + 1, thePlayer->getPlayer().second).getLook() == ' ' && !inertiaForceY){ 
            sleep(200); 
            playerMove(1, 0);
        }     
    }
}