#include <iostream>
#include "game.h"

using namespace std;

int main()
{
    Game mGame;
    mGame.createTheDisplay("Testbild",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,false);
    mGame.run();
    cout << "Hello World!" << endl;
    return 0;
}
