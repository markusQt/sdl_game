#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "game.h"


class Texturemanager
{
public:
    Texturemanager();
    ~Texturemanager();

    static SDL_Texture *loadTexture(const char * filename, SDL_Renderer * rend);
};

#endif // TEXTUREMANAGER_H
