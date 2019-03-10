#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class Game
{
public:
    Game();
    ~Game();
    bool gameIsRunning = true;
     void createTheDisplay(const char* title, int xPos, int yPos, int width,  int height, bool fullscreen);
     void run();
private:
    void clearAll_SDL();
    void handleEvents();
    void update();
    void render();
    int count = 0;
    SDL_Window *mWindow;
    SDL_Texture *mPlayerTex;
    SDL_Renderer *mRenderer;
    SDL_Rect mSrcRect,mDestRect;
};

#endif // GAME_H
