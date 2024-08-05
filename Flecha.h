#ifndef FLECHA_H_INCLUDED
#define FLECHA_H_INCLUDED

#include "GameObject.h"

class Flecha : public GameObject{
private:
	int velocidad, tipoFlecha;
	bool activo;

public:
  ///Init and Destroy.
  Flecha(int tipoFlecha, SDL_Renderer *renderer, int x, int y);

  ///Set's
	void setTipoFlecha(int _tipoFlecha){tipoFlecha = _tipoFlecha;}
	void setVelocidad(int _velocidad){velocidad = _velocidad;}
  void setActivo(bool _activo){activo = _activo;}

  ///Get's
	int getTipoFlecha(){return tipoFlecha;}
	int getVelocidad(){return velocidad;}
	bool getActivo(){return activo;}

  ///Generales.
	void render();
  void avanzarFlecha();
  void resetPos();

  void disparar(int x, int y);

};

#endif // FLECHA_H_INCLUDED
