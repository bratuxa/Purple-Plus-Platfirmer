#include "GameProcess.h"
#include <memory>
#include <synchapi.h>
#include <utility>

std::shared_ptr<GameProcess> GameProcess::gameProcess = NULL;

std::shared_ptr<GameProcess> GameProcess::getGameProcess(){
    if(gameProcess == NULL) gameProcess = std::shared_ptr<GameProcess>(new GameProcess());
    return gameProcess;
}

void GameProcess::playerMove(const int MOVE_Y, const int MOVE_X){
    std::pair<int, int> playerCoords = thePlayer->getObject();
    int targetY = playerCoords.first + MOVE_Y, targetX = playerCoords.second + MOVE_X;
    
    switch (theWorld.getObject(targetY, targetX).getLook()) {
        case ' ': case '$':{
            if (theWorld.getObject(targetY, targetX).getLook() == '$') {
                theWorld.getObjectPtr(targetY, targetX) = std::make_shared<Object>(' ');
                ++moneyCounter;
            }
            std::swap(theWorld.getObject(playerCoords.first, playerCoords.second), theWorld.getObject(targetY, targetX));
            thePlayer = std::make_shared<Player>(*std::dynamic_pointer_cast<Object>(theWorld.getObjectPtr(targetY, targetX)));
            theWorld.getObjectPtr(targetY,targetX) = std::dynamic_pointer_cast<Object>(thePlayer);
            thePlayer->setObject(targetY,targetX);    
        } 
        break; 
        case 'F':
            isGameEnd = endGame("You are win!!!");
        break;
    }
    
}

void GameProcess::gameLogic(){
    int inertiaForceY{0};
    bool lookAnimationCounter = true;
    int timer = 0;
    while (!isGameEnd) {  
        if(timer++ > 3) timer = 0;
        print();
        if(kbhit()) {  
            switch (getch()) {
                case 'd': case 77 : { thePlayer->nextFrameAnimation(); playerMove(0, 1);  } break;       // d, стрелка вправо
                case 'a': case 75 : { thePlayer->nextFrameAnimation(); playerMove(0, -1); } break;       // a, стрелка влево
                case 32 : case 'w': case 72: {                                                                          // пробел, w, стрелка вверх
                    if(theWorld.getObject(thePlayer->getObject().first + 1, thePlayer->getObject().second).getLook() != ' '){
                        playerMove(-1, 0);
                        inertiaForceY = 5;
                    }
                }
            }    
        }
        if(inertiaForceY != 0 && !isGameEnd){
            sleep(200);
            if(inertiaForceY > 3) playerMove(-1, 0);
            --inertiaForceY;
        }  
        switch (theWorld.getObject(thePlayer->getObject().first + 1, thePlayer->getObject().second).getLook()) {
            case '^': case '@':  isGameEnd = endGame("You are lose."); break;
            case 'F': isGameEnd = endGame("You are win!!!");
            case ' ': {
                if(!inertiaForceY && !isGameEnd){
                    sleep(200);
                    playerMove(1, 0);
                    if(theWorld.getObjectPtr(thePlayer->getObject().first + 1, thePlayer->getObject().second)->getLook() == '=') inertiaForceY = 8;
                    
                }
            }
        }
        if(!isGameEnd && timer == 3) moveObjects();
    }
}