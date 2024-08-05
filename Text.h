#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED

#include "GameObject.h"

class Text : public GameObject{
private:
  int tamFuente;
  SDL_Color colorFuente;
  TTF_Font * fuente;
  string texto;
public:

  //init
  Text();
  Text(string texto, int tamFuente, SDL_Color colorFuente, SDL_Renderer *renderer, int posX, int posY, int alto, int ancho);

  //set's
  void setTexto(string _texto){texto = _texto;}

  //get's
  string getTexto(){return texto;}

  void render();
  void cargarNombre();
};


#endif // TEXT_H_INCLUDED
