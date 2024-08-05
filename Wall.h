#ifndef WALL_H_INCLUDED
#define WALL_H_INCLUDED

#include "GameObject.h"
#include "UI.h"

class Wall : public GameObject{

private :
  int hp;

public:
  /// Init & Destroy
  Wall(SDL_Renderer *renderer);

  /// Set's
    void setHp(int _hp){hp = _hp;}

  ///Get's
    int getHp(){return hp;}

  ///Func
    void actualizar_vida(Wall &wall, UI_hp &ui_vida);
};

#endif // WALL_H_INCLUDED
