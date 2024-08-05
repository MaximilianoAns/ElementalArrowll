#include "Text.h"

Text::Text():GameObject(0, 0, 0, 0, "",nullptr){
}

Text::Text(string texto, int tamFuente, SDL_Color colorFuente, SDL_Renderer *renderer, int posX, int posY, int alto, int ancho)
                                                                            : GameObject( posX, posY, alto, ancho, "",renderer){

  TTF_Font *font = TTF_OpenFont("font_medieval.ttf", tamFuente);

  SDL_Surface* surfTemporal = TTF_RenderText_Solid(font, texto.c_str(), colorFuente);

  texture = SDL_CreateTextureFromSurface(renderer, surfTemporal);

  SDL_FreeSurface(surfTemporal);

  SDL_QueryTexture(texture,nullptr, nullptr, &tamAlto, &tamAncho);
}

void Text::cargarNombre(){

  bool ok = false;

  string textInput;

  SDL_StartTextInput();

    while(!ok){
     SDL_Event ev;
     while(SDL_PollEvent(&ev)){

      switch(ev.type){

        case SDL_QUIT:
          ok = true;
        break;

        case SDL_TEXTINPUT:
          if(textInput.length() < 10 ){
            textInput += ev.text.text;
          }
        break;

        case SDL_KEYDOWN:
          if(ev.key.keysym.sym == SDLK_BACKSPACE && textInput.length() > 0){
            textInput.pop_back();
          }
          if(ev.key.keysym.sym == SDLK_RETURN){
            ok = true;
          }
        break;

      }
      SDL_RenderClear(renderer);

      Text temp_nombre(textInput, 16,{255,215,0,255},renderer, 0, 400, 150, 800);
      temp_nombre.render();
      SDL_RenderPresent(renderer);
      texto = temp_nombre.getTexto();
     }
    }
  SDL_StopTextInput();

}

void Text::render(){ /// FUNCION PARA RENDELIZAR AL OBJ ENEMIGO EN PANTALLA
  GameObject::render();
}
