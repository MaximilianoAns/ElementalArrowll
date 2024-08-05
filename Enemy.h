#ifndef ENEMYCLASS_H_INCLUDED
#define ENEMYCLASS_H_INCLUDED

#include "GameObject.h"

class Enemy : public GameObject{
private:
	int puntos, tipoEnemigo, velocidad;
	bool activo;

public:

	Enemy(int _tipoEnemigo, SDL_Renderer *renderer);

  ///Set's
	void setPuntos(int _puntos){puntos = _puntos;}
	void setTipoEnemigo(int _tipoEnemigo){tipoEnemigo = _tipoEnemigo;}
	void setVelocidad(int _velocidad){velocidad = _velocidad;}
	void setActivo(bool _activo){activo = _activo;}

  ///Get's
	int getPuntos(){return puntos;}
	int getVelocidad(){return velocidad;}
	int getTipoEnemigo(){return tipoEnemigo;}
	bool getActivo(){return activo;}

	void render();
	void avanzarEnemigo();
	void resetEnemigo();

};

#endif // ENEMYCLASS_H_INCLUDED
