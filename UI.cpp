#include "UI.h"


UI_hud::UI_hud(SDL_Renderer *renderer) : GameObject(0, 0, 58, 800, "",renderer){

  texture = IMG_LoadTexture(renderer, "src/img/ui_hud.png");
  activo = true;
}

UI_FondoNivel::UI_FondoNivel(SDL_Renderer *renderer) : GameObject(0, 0, 980, 800, "",renderer){

  texture = IMG_LoadTexture(renderer, "src/img/mapa.png");
  activo = true;
}

UI_IconoPuntos::UI_IconoPuntos(SDL_Renderer* renderer) : GameObject(490, 10, 40, 40, "",renderer){
  texture = IMG_LoadTexture(renderer, "src/img/coin.png");
  activo = true;
}

UI_IconoTimer::UI_IconoTimer(SDL_Renderer* renderer): GameObject(355, 0, 55, 60, "",renderer){
  texture = IMG_LoadTexture(renderer, "src/img/reloj.png");
  activo = true;
}

UI_hp::UI_hp(int _cant_hp, SDL_Renderer *renderer) : GameObject(590, 10, 40, 200, "",renderer){
  texture = IMG_LoadTexture(renderer, "src/img/corazon_5.png");
  cant_hp = _cant_hp;
  activo = true;
}

void UI_hp::UI_actualizarHP(int _cant_hp){

  SDL_Rect currentRect = getRect();

  switch(_cant_hp){
  case 1:
    texture = IMG_LoadTexture(renderer, "src/img/corazon_1.png");
    currentRect.w = 40;
    currentRect.x = 750;
    setRect(currentRect);
  break;
  case 2:
    texture = IMG_LoadTexture(renderer, "src/img/corazon_2.png");
    currentRect.w = 80;
    currentRect.x = 710;
    setRect(currentRect);
  break;
    case 3:
    texture = IMG_LoadTexture(renderer, "src/img/corazon_3.png");
    currentRect.w = 120;
    currentRect.x = 680;
    setRect(currentRect);
  break;
    case 4:
    texture = IMG_LoadTexture(renderer, "src/img/corazon_4.png");
    currentRect.w = 160;
    currentRect.x = 640;
    setRect(currentRect);
  break;
  }
}
