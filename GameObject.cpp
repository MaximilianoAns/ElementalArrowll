#include "GameObject.h"

using namespace std;

/// Init and Destroyer

GameObject::GameObject(int X, int Y, int tamAlto, int tamAncho, const string &rutaTextura, SDL_Renderer* renderer){

  SDL_Surface* surfTemporal = IMG_Load(rutaTextura.c_str()); // <- Creamos la superficie temporal para cargar la imagen
                                                             //    desde la ruta que se pasa en el constructor.

  texture = SDL_CreateTextureFromSurface(renderer, surfTemporal);  // <- Creamos la textura que almacenamos en el obj.
  this->renderer = renderer;  // <- Asiganmos al obj el renderer que utilizamos.

  SDL_FreeSurface(surfTemporal); // <- Liberamos la superficie temporal.

  rect = {X, Y, tamAncho, tamAlto}; // <- Inicializacion del rect para el objeto.

}

GameObject::~GameObject(){
  SDL_DestroyTexture(texture);
}


/// Set's

void GameObject::setRect(SDL_Rect _rect){

  rect = _rect;
  X = _rect.x;
  Y = _rect.y;
  tamAlto = _rect.h;
  tamAncho = _rect.w;
}


/// Funciones

void GameObject::render(){
  SDL_RenderCopy(renderer, texture, NULL, &rect); // <- Se hace el render copy para mostrar el obj.
}
