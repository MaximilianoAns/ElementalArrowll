#include "Enemy.h"

Enemy::Enemy(int _tipoEnemigo, SDL_Renderer *renderer): GameObject( rand()%736+1, 0, 64, 64, "",renderer)
{
switch(_tipoEnemigo){
	case 1:
		texture = IMG_LoadTexture(renderer, "src/img/fuego.png"); ///CARGAMOS IMG DE LOS ENEMIGOS - PASO RUTA
		tipoEnemigo = 1;
		puntos = rand()%10;
		velocidad = 1;
		activo = true;
		break;
	case 2:
		texture = IMG_LoadTexture(renderer, "src/img/agua.png");
		tipoEnemigo = 2;
		puntos = rand()%10;
		velocidad = 2;
		activo = true;
		break;
	case 3:
		texture = IMG_LoadTexture(renderer, "src/img/aire.png");
		tipoEnemigo = 3;
		puntos = rand()%10;
		velocidad = 2;
		activo = true;
		break;
	case 4:
		texture = IMG_LoadTexture(renderer, "src/img/rayo.png");
		tipoEnemigo = 4;
		puntos = rand()%10;
		velocidad = 3;
		activo = true;
		break;
	case 5:
		texture = IMG_LoadTexture(renderer, "src/img/tierra.png");
		tipoEnemigo = 5;
		puntos = rand()%10;
		velocidad = 1;
		activo = true;
		break;
	default:
		break;
	}
}

void Enemy::render(){ /// FUNCION PARA RENDELIZAR AL OBJ ENEMIGO EN PANTALLA
    GameObject::render();
}

void Enemy::avanzarEnemigo() {

    SDL_Rect currentRect = getRect(); // Obtenemos el rectángulo actual del enemigo
    int posY = currentRect.y; // Obtenemos la posición Y actual del enemigo

    if(getActivo()){
      posY += velocidad;
      currentRect.y = posY;
      setRect(currentRect);
    }
}

void Enemy::resetEnemigo(){

  SDL_Rect currentRect = getRect();

  currentRect.y = 0;
  currentRect.x = rand()%736 + 1;

  setRect(currentRect);
}
