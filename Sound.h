#ifndef SOUND_H_INCLUDED
#define SOUND_H_INCLUDED

#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <SDL2\SDL.h>
#include <SDL2/SDL_mixer.h>

using namespace std;

class Music{

private:
  Mix_Music* musica;
public:

  Music(const string &rutaMusica);
  ~Music(){Mix_FreeMusic(musica);}

  void play(int cant_rep);
  void halt();
};



#endif // SOUND_H_INCLUDED
