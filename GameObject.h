#ifndef GAMEOBJECT_H_INCLUDED
#define GAMEOBJECT_H_INCLUDED

#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "random"

using namespace std;

class GameObject {

protected:

  int X, Y; // Posicion inicial del elemento en la pantalla.
  int tamAlto, tamAncho; // Tamaño del elemento en la pantalla.
  SDL_Rect rect; // Rect del elemento.
  SDL_Texture* texture; // Textura del elemento.
  SDL_Renderer* renderer; // Renderer asociado al elemento.

public:

  ///Init & Destroyer
  GameObject(int X, int Y, int tamAlto, int tamAncho, const string &rutaTextura, SDL_Renderer* renderer);

 ~GameObject();

  ///Set's
  void setX(int _X){X = _X;}
  void setY(int _Y){Y = _Y;}
  void setTamAlto(int _tamAlto){tamAlto = _tamAlto;}
  void setTamAncho(int _tamAncho){tamAncho = _tamAncho;}
  void setRect(SDL_Rect _rect);
  void setTexture(SDL_Texture *_texture){texture = _texture;}

  ///Get's
  int getX(){return X;}
  int getY(){return Y;}
  int getTamAlto(){return tamAlto;}
  int getTamAncho(){return tamAncho;}
  int getXRect(){return rect.x;}
  int getYRect(){return rect.y;}
  int getWRect(){return rect.w;}
  int getHRect(){return rect.h;}
  SDL_Rect getRect(){return rect;}
  SDL_Rect* getRefRect(){return &rect;} // <- Get que obtiene la referencia del Rectangulo apra poder renderizarlo.
  SDL_Texture* getTexture(){return texture;}


  ///Funciones
  void render();

};

#endif // GAMEOBJECT_H_INCLUDED
