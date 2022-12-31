#include "GameProcess.h"
#include <synchapi.h>
#include <utility>

std::shared_ptr<GameProcess> GameProcess::gameProcess = NULL;

std::shared_ptr<GameProcess> GameProcess::getGameProcess(){
    if(gameProcess == NULL) gameProcess = std::shared_ptr<GameProcess>(new GameProcess());
    return gameProcess;
}

void GameProcess::playerMove(const int MOVE_Y, const int MOVE_X){
    std::pair<int, int> playerCoords = thePlayer.getPlayer();
    int targetY = playerCoords.first + MOVE_Y, targetX = playerCoords.second + MOVE_X;
    std::swap(theWorld.getObject(playerCoords.first, playerCoords.second), theWorld.getObject(targetY, targetX));
    thePlayer.setPlayer(targetY,targetX);
}

void GameProcess::gameLogic(){
        while (true) {
            print();
            if(kbhit()) {
                //FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
                switch (getch()) {
                    case 'd': case 77 : playerMove(0, 1); break;
                }    
            }
            if(theWorld.getObject(thePlayer.getPlayer().first + 1, thePlayer.getPlayer().second).getLook() == ' '){ 
                sleep(500); 
                playerMove(1, 0);
            }  
        }
    }