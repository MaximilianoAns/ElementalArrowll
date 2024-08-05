#ifndef SDL_ENGINE_H_INCLUDED
#define SDL_ENGINE_H_INCLUDED

#include "GameConfig.h"

/// Inicializar el engine.(Crear la ventana y el renderer).
void init_engine(){

  if(SDL_Init(SDL_INIT_EVERYTHING)<0){ // <- Inicio de los modulos de SDL
    cout << "Error al iniciar SDL " << SDL_GetError() << endl;
  }

  if(TTF_Init()<0){ // <- Inicio de los modulos de TTF
    cout << "Error al iniciar TTF " << SDL_GetError() << endl;
  }

  if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        cout << "Error al inicializar SDL: " << SDL_GetError() << std::endl;
    }

  // Inicializar SDL_Mixer
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        cout << "Error al inicializar SDL_Mixer: " << Mix_GetError() << std::endl;
  }

}

#endif // SDL_ENGINE_H_INCLUDED
