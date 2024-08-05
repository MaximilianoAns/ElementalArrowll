#include "Sound.h"

Music::Music(const string &rutaMusica){
  musica = Mix_LoadMUS(rutaMusica.c_str());
}

void Music::play(int loops){
  Mix_PlayMusic(musica, loops); // -1 se reptie indefinidamente.
}

void Music::halt(){
  Mix_HaltMusic();
}

/*

  /// musica juego:
  Mix_Music* bgm_game = Mix_LoadMUS("src/sound/game_music.mp3");

  if(currentGameState == MENU){
    Mix_PlayMusic(bgm_menu, -1); // -1 para repetir la música indefinidamente
  }
*/
