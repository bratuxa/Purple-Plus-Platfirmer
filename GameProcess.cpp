#include "GameProcess.h"
#include <memory>

std::shared_ptr<GameProcess> GameProcess::gameProcess = NULL;

std::shared_ptr<GameProcess> GameProcess::getGameProcess(){
    if(gameProcess == NULL) gameProcess = std::shared_ptr<GameProcess>(new GameProcess());
    return gameProcess;
}
