#include "SDL_engine.h"
#include "GameConfig.h"
#include "Menu.h"
#include "Sound.h"

using namespace std;

GameState currentGameState = MENU;

int main(int argc, char* args[]){

  /// Llamado a la funcion que inicia el engine.
  init_engine();

  /// Carga de la musica.
  Music musicaMenu("src/sound/menu_music.mp3");
  Music musicaGame("src/sound/game_music.mp3");

  // Init del menu.
  Menu menu;

  while(!endGame){
    switch(currentGameState){
    case MENU:
      musicaMenu.play(-1);
      menu.menuPrincipal();
      break;
    case GAME:
      musicaMenu.halt();
      musicaGame.play(-1);
      GameLoop();
      break;
    case GAME_OVER:
      musicaGame.halt();
      menu.GameOver();
      break;
    case SAVE_SCORE:
      menu.SaveScore();
      break;
    case VIEW_SCORE:
      menu.ListScore();
      break;
    }
  }

  return 0;
}
