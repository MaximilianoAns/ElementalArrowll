#include "Collisions.h"

bool check_collisions(GameObject &rect_1, GameObject &rect_2){

    if (
    rect_1.getXRect() < rect_2.getXRect() + rect_2.getWRect() &&
    rect_1.getXRect() + rect_1.getWRect() > rect_2.getXRect() &&
    rect_1.getYRect() < rect_2.getYRect() + rect_2.getHRect() &&
    rect_1.getYRect() + rect_1.getHRect() > rect_2.getYRect()
    ){
      return true;
    }
    return false;
}
