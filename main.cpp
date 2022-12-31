#include "GameProcess.h"

int main(int, char**) {
    printf("\e[?25l"); // очищает курсор
    GameProcess::getGameProcess()->test();
}
