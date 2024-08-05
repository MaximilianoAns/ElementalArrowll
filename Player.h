#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "GameObject.h"
#include "Flecha.h"

class Player : public GameObject{
private:

	int velocidad;
	int imagenEstado;

public:
  ///Init y destroyer.
	Player(int imagenEstado, SDL_Renderer *renderer);

  ///Set's
	void setVelocidad(int _velocidad){velocidad = _velocidad;}
	void setImagenEstado(int _imagenEstado){imagenEstado = _imagenEstado;}

  ///Get's
	int getVelocidad(){return velocidad;}
	int getImagenEstado(){return imagenEstado;}

  /// Generales
	void render();
	void moverPlayer(char dir);
};

#endif // PLAYER_H_INCLUDED
