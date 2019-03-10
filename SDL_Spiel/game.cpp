#include "game.h"
#include "texturemanager.h"

Game::Game()
{
    mWindow= nullptr;
    mRenderer=nullptr;
    if (SDL_Init(SDL_INIT_EVERYTHING)){
        std::cout << "SDL initialisiert"<<std::endl;
    }else{
        std::cout<< "SDL Fehler :" << SDL_GetError()<<std::endl;
    }
    mDestRect.w = 100;
    mDestRect.h = 100;

}

Game::~Game()
{
    std::cout << "calling destructor"<<std::endl;
}

void Game::clearAll_SDL()
{
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}

void Game::handleEvents()
{
    SDL_Event myEvent;

    while(SDL_PollEvent(&myEvent)){

        if(myEvent.type ==  SDL_QUIT ){
            gameIsRunning=false;
            break;
        }

        if(myEvent.type == SDL_KEYDOWN ){
            std::cout << myEvent.key.keysym.sym<<std::endl;
            if(myEvent.key.keysym.sym == SDLK_ESCAPE){
                gameIsRunning=false;
                break;
            }
            if(myEvent.key.state == SDLK_w){
               mDestRect.y += -speedH;
            }
            if(myEvent.key.keysym.sym == SDLK_s){
               mDestRect.y += speedH;
            }
            if(myEvent.key.keysym.sym == SDLK_a){
               mDestRect.x += -speedV;
            }
            if(myEvent.key.keysym.sym == SDLK_d){
               mDestRect.x += speedV;
            }

        }

        if(myEvent.type ==  SDL_KEYUP ){

            if(myEvent.key.keysym.sym == SDLK_w){
               mDestRect.y += 0;
            }
            if(myEvent.key.keysym.sym == SDLK_s){
               mDestRect.y += 0;
            }
            if(myEvent.key.keysym.sym == SDLK_a){
               mDestRect.x += 0;
            }

            if(myEvent.key.keysym.sym == SDLK_a){
               mDestRect.x += 0;
            }
            if(myEvent.key.keysym.sym == SDLK_d){
               mDestRect.x += 0;
            }

        }
    }
}

void Game::update()
{



}

void Game::render()
{
    mPlayerTex = Texturemanager::loadTexture("assets/shuttle.png",mRenderer);
    SDL_RenderClear(mRenderer);
    SDL_RenderCopy(mRenderer,mPlayerTex,NULL,&mDestRect);
    SDL_RenderPresent(mRenderer);


}



void Game::createTheDisplay(const char *title, int xPos, int yPos, int width, int height, bool fullscreen)
{
    Uint32 modus;
    if(fullscreen){
        modus = SDL_WINDOW_FULLSCREEN;
    }else{
        modus = SDL_WINDOW_SHOWN;
    }
    mWindow =  SDL_CreateWindow(title,xPos,yPos,width,height,modus);
    if(mWindow == NULL){
        std::cout << "error building window" << SDL_GetError()<<std::endl;
        return;
    }
    mRenderer= SDL_CreateRenderer(mWindow,-1,0);
    if(mRenderer == NULL){
        std::cout << "error building renderer" << SDL_GetError()<<std::endl;
        return;
     }else{
        SDL_SetRenderDrawColor(mRenderer,0,0,0,255);
     }

}

void Game::run()
{
    const int FPS = 100;
    const int frameDelay = 1000/FPS;
    Uint32 frameStart;
    int frameTime=0;

    while (gameIsRunning){
       frameStart = SDL_GetTicks();
       handleEvents();
       //update();
       render();
       frameTime = SDL_GetTicks()-frameStart;
       if(frameDelay > frameTime){
           SDL_Delay(frameDelay-frameTime);
       }
    }

    clearAll_SDL();
}
