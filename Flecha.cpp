#include "Flecha.h"

Flecha::Flecha(int _tipoFlecha, SDL_Renderer *renderer,int x, int y): GameObject(x, y, 64, 64, "",renderer)
{
  switch (_tipoFlecha) {
        case 1:
            texture = IMG_LoadTexture(renderer, "src/img/f_agua.png");
            tipoFlecha = _tipoFlecha;
            break;
        case 2:
            texture = IMG_LoadTexture(renderer, "src/img/f_tierra.png");
            tipoFlecha = _tipoFlecha;
            break;
        case 3:
            texture = IMG_LoadTexture(renderer, "src/img/f_fuego.png");
            tipoFlecha = _tipoFlecha;
            break;
        case 4:
            texture = IMG_LoadTexture(renderer, "src/img/f_aire.png");
            tipoFlecha = _tipoFlecha;
            break;
        case 5:
            texture = IMG_LoadTexture(renderer, "src/img/f_rayo.png");
            tipoFlecha = _tipoFlecha;
            break;

        default:
            break;
    }
    velocidad = 5;
    activo = false;
}

void Flecha::render() {
    GameObject::render();
}

void Flecha::avanzarFlecha() {
    SDL_Rect currentRect = getRect();
    int posY = currentRect.y;

    if (posY >= 0) {
        posY -= velocidad;
        currentRect.y = posY;
        setRect(currentRect);
    } else {
        setActivo(false);
    }
}

void Flecha::disparar(int x, int y){
  SDL_Rect currentRect = getRect();

  int posX = x;
  int posY = y;

  currentRect.y = posY;
  currentRect.x = posX;

  setRect(currentRect);

}

void Flecha::resetPos(){

  SDL_Rect currentRect = getRect();

  currentRect.y = 1000;
  currentRect.x = 100;

  setRect(currentRect);
}
