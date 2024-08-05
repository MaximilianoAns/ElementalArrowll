#include "Player.h"

Player::Player(int _imagenEstado, SDL_Renderer *renderer): GameObject( (800-64)/2, 980-64, 64, 64, "",renderer)
{
  texture = IMG_LoadTexture(renderer, "src/img/PlayerShot.png");
  imagenEstado = 0;
  velocidad = 15;
}

void Player::render(){ /// FUNCION PARA RENDELIZAR AL OBJ ENEMIGO EN PANTALLA
  GameObject::render();
}

void Player::moverPlayer(char dir){

  SDL_Rect currentRect = getRect(); // Obtenemos el rectángulo actual del enemigo
  int posX = currentRect.x; // Obtenemos la posición X actual del enemigo

  SDL_Texture* currentText = getTexture();
  int imgEstado = getImagenEstado();

  if (posX >= 0 && posX <= 800-64 ) { // Verificamos si la posición X es menor que el limite de la pantalla
    switch(dir){
      case 's':
        currentText = IMG_LoadTexture(renderer, "src/img/PlayerShot.png");
        setTexture(currentText);
      break;
      case 'd':
        posX += velocidad;
        if (posX >= 800-64){posX = 800-64;}
        if(imgEstado <= 0 || imgEstado == 2){
            setImagenEstado(1);
            currentText = IMG_LoadTexture(renderer, "src/img/PlayerRight_1.png");
            setTexture(currentText);
        } else if (imgEstado == 1){
            setImagenEstado(2);
            currentText = IMG_LoadTexture(renderer, "src/img/PlayerRight_2.png");
            setTexture(currentText);
        }
      break;
      case 'i':
        posX -= velocidad;
        if (posX < 0 ){posX = 0;}
        if(imgEstado >= 0 || imgEstado == -2){
            setImagenEstado(-1);
            currentText = IMG_LoadTexture(renderer, "src/img/PlayerLeft_1.png");
            setTexture(currentText);
        } else if (imgEstado == -1){
            setImagenEstado(-2);
            currentText = IMG_LoadTexture(renderer, "src/img/PlayerLeft_2.png");
            setTexture(currentText);
        }
      break;
    }
  }

  currentRect.x = posX; // Actualizamos la posición Y del rectángulo
  setRect(currentRect); // Llamamos a setRect para actualizar el rectángulo del player
}
