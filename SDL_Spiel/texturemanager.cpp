#include "texturemanager.h"

Texturemanager::Texturemanager()
{

}

SDL_Texture *Texturemanager::loadTexture(const char *filename, SDL_Renderer *rend)
{
    SDL_Surface *tmpSrf = IMG_Load(filename);
    SDL_Texture *gameobject = SDL_CreateTextureFromSurface(rend,tmpSrf);
    SDL_FreeSurface(tmpSrf);
    return gameobject;
}
