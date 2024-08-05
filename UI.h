#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED

#include "GameObject.h"
#include "Text.h"


class UI_hud : public GameObject{
private:
  bool activo;
public:
  UI_hud(SDL_Renderer *renderer);
};

class UI_FondoNivel : public GameObject{
private:
  bool activo;
public:
  UI_FondoNivel(SDL_Renderer *renderer);
};

class UI_IconoPuntos : public GameObject{
private:
  bool activo;
public:
  UI_IconoPuntos(SDL_Renderer* renderer);
};

class UI_IconoTimer : public GameObject{
private:
  bool activo;
public:
  UI_IconoTimer(SDL_Renderer* renderer);
};

class UI_hp : public GameObject{
private:
  int cant_hp;
  bool activo;
public:
  UI_hp(int _cant_hp, SDL_Renderer* renderer);

  void UI_actualizarHP(int _cant_hp);
};

#endif // UI_H_INCLUDED
