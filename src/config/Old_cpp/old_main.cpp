#include <stdio.h>
#include <iostream>
#include <SDL2\SDL.h>

using namespace std;

/*
  int main(){

  const int FPS = 60;
  const int frameDelay = 1000 / FPS;

  SDL_Window* window;

  Uint32 frameStart;
  int frameTime;

  while(true){

    frameStart = SDL_GetTicks();
    frameTime = SDL_GetTicks() - frameStart;

    if(frameDelay > frameTime){
      SDL_Delay(frameDelay - frameTime);
    }

  }

  return 0;
}
*/
/*

SDL_Texture* LoadTexture(const char* texture)
{
  SDL_Surface* tempSurface = IMG_Load(texture);
  SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
  SDL_FreeSurface(tempSurface);
  return tex;
}
*/
/*

/// Ventana
  SDL_Window* window = NULL;

  int width = 720;
  int height = 480;

/// Renderer
  SDL_Renderer* renderer = NULL;

  SDL_Surface* player = NULL;
  SDL_Surface* enemigoR = NULL;

/// Game
  bool endGame = false;

int main(int argc, char* args[]){

  if(SDL_Init(SDL_INIT_VIDEO)<0){ //Inicio de los modulos de SDL
    cout << "Error al iniciar SDL " << SDL_GetError() << endl;
  }
  else{
    window = SDL_CreateWindow("Elemental Arrow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
    if( window == NULL){
      cout << "Error al crear la ventana " << SDL_GetError();;
    }
  }


  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


  player = SDL_LoadBMP("src/img/mario.bmp");
  enemigoR = SDL_LoadBMP("src/img/rojo.bmp");

  SDL_Texture* texturePlayer = SDL_CreateTextureFromSurface(renderer, player);
  SDL_Texture* textureRojo = SDL_CreateTextureFromSurface(renderer, enemigoR);
  SDL_FreeSurface(player);
  SDL_FreeSurface(enemigoR);



  int x = 0;
  int y = 0;
  SDL_Rect rectPlayer = {x, y, 100, 100};
  SDL_Rect rectERojo = {200, 200, 100, 100};

  while(!endGame){
    SDL_Event e;
    if (SDL_PollEvent(&e)){
      switch(e.type){
        case SDL_QUIT:
          endGame = true;
          break;
        case SDL_KEYDOWN:
          switch(e.key.keysym.sym){
            case SDLK_UP:
              y -= 5;
              break;
            case SDLK_DOWN:
              y += 5;
              break;
            case SDLK_LEFT:
              x -= 5;
              break;
            case SDLK_RIGHT:
              x += 5;
              break;
          }
        break;
        case SDL_KEYUP:
          switch (e.key.keysym.sym){

          }
          break;
      }
    }
   if (y > 200){
    y = 200;
  }

   SDL_RenderCopy(renderer, texturePlayer, NULL, &rectPlayer);
   SDL_RenderCopy(renderer, textureRojo, NULL, &rectERojo);
   SDL_RenderPresent(renderer);

   SDL_RenderClear(renderer);
  }

  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyTexture(texturePlayer);
  SDL_DestroyTexture(textureRojo);
  return 0;

}
*/
