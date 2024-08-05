#include "Wall.h"

Wall::Wall(SDL_Renderer *renderer): GameObject( 0, 900, 80, 800, "",renderer){
  texture = IMG_LoadTexture(renderer, "src/img/wall.png");
  hp = 5;
}

void Wall::actualizar_vida(Wall &wall, UI_hp &ui_vida){
  wall.setHp( wall.getHp() - 1);
  ui_vida.UI_actualizarHP(wall.getHp());
}
