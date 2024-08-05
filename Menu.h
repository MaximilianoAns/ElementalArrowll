#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "GameConfig.h"
#include "GameLoop.h"
#include "ArchivoPuntos.h"

class Menu {
public:
    void menuPrincipal();
    void GameOver();
    void SaveScore();
    void ListScore();
};

void Menu::menuPrincipal(){

  Text *vecMenu_jugar = new Text[4]{Text("--- Elemental Arrow ---", 24,{255,215,0,255},renderer, (width-600)/2, 100, 150,600),
                              Text("-> Jugar!", 16,{255,215,0,255},renderer, (width-150)/2, 370, 75, 150),
                              Text("Puntajes", 16,{255,215,0,255},renderer, (width-150)/2, 470, 75, 150),
                              Text("Salir", 24,{255,215,0,255},renderer, (width-100)/2, 570, 75, 100)};

  Text *vecMenu_puntaje = new Text[4]{Text("--- Elemental Arrow ---", 24,{255,215,0,255},renderer, (width-600)/2, 100, 150,600),
                              Text("Jugar!", 16,{255,215,0,255},renderer, (width-100)/2, 370, 75, 100),
                              Text("-> Puntajes", 16,{255,215,0,255},renderer, (width-200)/2, 470, 75, 200),
                              Text("Salir", 24,{255,215,0,255},renderer, (width-100)/2, 570, 75, 100)};

  Text *vecMenu_salir = new Text[4]{Text("--- Elemental Arrow ---", 24,{255,215,0,255},renderer, (width-600)/2, 100, 150,600),
                              Text("Jugar!", 16,{255,215,0,255},renderer, (width-100)/2, 370, 75, 100),
                              Text("Puntajes", 16,{255,215,0,255},renderer, (width-150)/2, 470, 75, 150),
                              Text("-> Salir", 24,{255,215,0,255},renderer, (width-150)/2, 570, 75, 150)};

  while(!endGame && currentGameState == MENU){

    /// Control de velocidad de juego.
    frameStart = SDL_GetTicks();
    frameTime = SDL_GetTicks() - frameStart;

    if(frameDelay > frameTime){
      SDL_Delay(frameDelay - frameTime);
    }

  /// Manejo del menu con teclas.
  SDL_Event e; // <- Var de tipo SDL Evento. Encargada de registrar los eventos del sistema. (Teclado, mouse, etc)

  if (SDL_PollEvent(&e)){ // <- Valida si ocurrio un evento.

    switch(e.type){ // <- Switch para verificar que tipo de evento ocurrio.

      ///Control de cierre de juego
      case SDL_QUIT: // <- Verifica si se cierra el juego desde la "X" de cerrar
        endGame = true; // <- Si se cumple el case, cambioa el estado de "endGame" y cierra el juego.
        break;

      case SDL_KEYDOWN:           // <- Verifica si se PRESIONO una tecla.
        switch(e.key.keysym.sym){ // <- Verifica: el evento.tecla.tecla de sys.tecla especifica.

        ///Cierre del juego con "Esc"
          case SDLK_ESCAPE:       // <- Verifica si se presiono la tecla "ESC".
          endGame = true;         // <- Si se cumple el case, cambioa el estado de "endGame" y cierra el juego.
          break;
        ///Control de movimiento del menu.
          case SDLK_UP:
            opc_menu = (opc_menu > 1) ? opc_menu - 1 : 3;
          break;
          case SDLK_DOWN:
            opc_menu = (opc_menu < 3) ? opc_menu + 1 : 1;
          break;

          case SDLK_RETURN:
            switch (opc_menu) {
            case 1:
              currentGameState = GAME;
              return;
            break;
            case 2:
              currentGameState = VIEW_SCORE;
            break;
            case 3:
              endGame = true;
            break;
          }
          break;
      }
    }
  }
  // Limpiar pantalla antes de renderizar
  SDL_RenderClear(renderer);

  // Renderizar el menú correspondiente
  switch (opc_menu) {
      case 1:
          for (int i = 0; i < 4; ++i) {
              vecMenu_jugar[i].render();
          }
          break;
      case 2:
          for (int i = 0; i < 4; ++i) {
              vecMenu_puntaje[i].render();
          }
          break;
      case 3:
          for (int i = 0; i < 4; ++i) {
              vecMenu_salir[i].render();
          }
          break;
  }

  SDL_RenderPresent(renderer); // Dibuja en la ventana lo que tiene pendiente el RENDER.

}
  delete[] vecMenu_jugar;
  delete[] vecMenu_puntaje;
  delete[] vecMenu_salir;
}

void Menu::GameOver(){

  Text *vecGameOver_si = new Text[4]{Text("--- GAME OVER! ---", 24,{255,215,0,255},renderer, (width-600)/2, 100, 150,600),
                              Text("¿Desea guardar puntaje?", 16,{255,215,0,255},renderer, (width-400)/2, 370, 75, 400),
                              Text("-> Si", 16,{255,215,0,255},renderer, (width-100)/2, 470, 75, 100),
                              Text("No", 24,{255,215,0,255},renderer, (width-50)/2, 570, 75, 50)};

  Text *vecGameOver_no = new Text[4]{Text("--- GAME OVER! ---", 24,{255,215,0,255},renderer, (width-600)/2, 100, 150,600),
                              Text("¿Desea guardar puntaje?", 16,{255,215,0,255},renderer, (width-400)/2, 370, 75, 400),
                              Text("Si", 16,{255,215,0,255},renderer, (width-50)/2, 470, 75, 50),
                              Text("-> No", 24,{255,215,0,255},renderer, (width-100)/2, 570, 75, 100)};

  while(!endGame && currentGameState == GAME_OVER){

    /// Control de velocidad de juego.
    frameStart = SDL_GetTicks();
    frameTime = SDL_GetTicks() - frameStart;

    if(frameDelay > frameTime){
      SDL_Delay(frameDelay - frameTime);
    }

  /// Manejo del menu con teclas.
  SDL_Event e; // <- Var de tipo SDL Evento. Encargada de registrar los eventos del sistema. (Teclado, mouse, etc)

  if (SDL_PollEvent(&e)){ // <- Valida si ocurrio un evento.

    switch(e.type){ // <- Switch para verificar que tipo de evento ocurrio.

      ///Control de cierre de juego
      case SDL_QUIT: // <- Verifica si se cierra el juego desde la "X" de cerrar
        endGame = true; // <- Si se cumple el case, cambioa el estado de "endGame" y cierra el juego.
        break;

      case SDL_KEYDOWN:           // <- Verifica si se PRESIONO una tecla.
        switch(e.key.keysym.sym){ // <- Verifica: el evento.tecla.tecla de sys.tecla especifica.

        ///Vuelve al menu con "Esc"
          case SDLK_ESCAPE:       // <- Verifica si se presiono la tecla "ESC".
          currentGameState = MENU;
          break;

        ///Control de movimiento del menu.
          case SDLK_UP:
            opc_gameOver = (opc_gameOver > 1) ? opc_gameOver - 1 : 2;
          break;
          case SDLK_DOWN:
            opc_gameOver = (opc_gameOver < 2) ? opc_gameOver + 1 : 1;
          break;


          case SDLK_RETURN:
            switch (opc_gameOver) {
            case 1:
              currentGameState = SAVE_SCORE;
            break;
            case 2:
              currentGameState = MENU;
            break;
          }
          break;
      }
    }
  }
  // Limpiar pantalla antes de renderizar
  SDL_RenderClear(renderer);

  // Renderizar el menú correspondiente
  switch (opc_gameOver) {
      case 1:
          for (int i = 0; i < 4; ++i) {
              vecGameOver_si[i].render();
          }
          break;
      case 2:
          for (int i = 0; i < 4; ++i) {
              vecGameOver_no[i].render();
          }
          break;
  }

  SDL_RenderPresent(renderer); // Dibuja en la ventana lo que tiene pendiente el RENDER.

}
  delete[] vecGameOver_si;
  delete[] vecGameOver_no;
}

void Menu::SaveScore(){

  Text *titulo = new Text[4]{Text("--- Elemental Arrow ---", 24,{255,215,0,255},renderer, (width-600)/2, 100, 150,600),
                            Text("Escribe tu nombre", 16,{255,215,0,255},renderer, (width-300)/2, 370, 75, 300),
                            Text("Puntaje: ", 16,{255,215,0,255},renderer, 200, 600, 75, 200),
                            Text(puntos_string, 24,{255,215,0,255},renderer, 450, 600, 75, 100)};


  Text nombre;

  bool ok = false;

  string textInput;

  SDL_StartTextInput();

    while(!ok && currentGameState == SAVE_SCORE){
     SDL_Event ev;
     while(SDL_PollEvent(&ev)){

      switch(ev.type){

        case SDL_QUIT:
          ok = true;
        break;

        case SDL_TEXTINPUT:
          if(textInput.length() <= 10 ){
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

      /// Render del texto estatico.
      for (int i = 0; i < 4; ++i) {
            titulo[i].render();
        }

      /// Render del texto que se ingresa por teclado.
      Text temp_nombre(textInput, 16,{255,215,0,255},renderer, (width-200)/2, 450, 75, 200);
      temp_nombre.render();
      SDL_RenderPresent(renderer);
     }
    }
  SDL_StopTextInput();

  char nombreChr[10];

  strncpy(nombreChr, textInput.c_str(), sizeof(nombreChr) - 1);
  textInput[sizeof(textInput) - 1] = '\0';

  RegPuntos puntaje(puntos, nombreChr);

  ArchivoPuntos archpts("puntaje.dat");
  archpts.puntajeValido(puntaje);

}

void Menu::ListScore(){

  bool escape = false;

  while(!escape && currentGameState == VIEW_SCORE){

  SDL_Event e; // <- Var de tipo SDL Evento. Encargada de registrar los eventos del sistema. (Teclado, mouse, etc)

  if (SDL_PollEvent(&e)){ // <- Valida si ocurrio un evento.

    switch(e.type){ // <- Switch para verificar que tipo de evento ocurrio.

      ///Control de cierre de juego
      case SDL_QUIT: // <- Verifica si se cierra el juego desde la "X" de cerrar
        endGame = true; // <- Si se cumple el case, cambioa el estado de "endGame" y cierra el juego.
        currentGameState = MENU;
        break;

      case SDL_KEYDOWN:           // <- Verifica si se PRESIONO una tecla.
        switch(e.key.keysym.sym){ // <- Verifica: el evento.tecla.tecla de sys.tecla especifica.

        ///Vuelve al menu con "Esc"
          case SDLK_ESCAPE:       // <- Verifica si se presiono la tecla "ESC".
          escape = true;
          currentGameState = MENU;
          break;}
        }
    }

  SDL_RenderClear(renderer);

  Text *vecMenu_score = new Text[2]{Text("--- Elemental Arrow ---", 24,{255,215,0,255},renderer, (width-600)/2, 100, 150,600),
                            Text("¡¡¡ Top 10 !!!", 16,{255,215,0,255},renderer, (width-300)/2, 370, 75, 300)};

  ArchivoPuntos archPts("puntaje.dat");
  RegPuntos reg;
  int cantRegPts = archPts.contarRegistros();

  // Render de los titulos
  for (int i = 0; i < 2; ++i) {
  vecMenu_score[i].render();
  }

  for(int i = 0; i < cantRegPts; i++ ){

  int pos = i+1;
  string puntajeCompleto = to_string(pos) + ") " + string(reg.getNombre()) + "  -  "+ to_string(reg.getPuntos());

  reg = archPts.leerRegistro(i);
  Text text_pts(puntajeCompleto, 16,{255,215,0,255},renderer, (width-400)/2, 450+(i*50), 25, 400);
  text_pts.render();

  }
  SDL_RenderPresent(renderer); // Dibuja en la ventana lo que tiene pendiente el RENDER.
  }
}

#endif // MENU_H_INCLUDED
