#ifndef GAMEOVER_H_INCLUDED
#define GAMEOVER_H_INCLUDED

void GameOver(){

  Text *vecGameOver_si = new Text[4]{Text("--- GAME OVER! ---", 24,{255,215,0,255},renderer, (width-600)/2, 100, 150,600),
                              Text("¿Desea guardar puntaje?", 16,{255,215,0,255},renderer, (width-400)/2, 370, 75, 400),
                              Text("-> Si", 16,{255,215,0,255},renderer, (width-100)/2, 470, 75, 100),
                              Text("No", 24,{255,215,0,255},renderer, (width-50)/2, 570, 75, 50)};

  Text *vecGameOver_no = new Text[4]{Text("--- GAME OVER! ---", 24,{255,215,0,255},renderer, (width-600)/2, 100, 150,600),
                              Text("¿Desea guardar puntaje?", 16,{255,215,0,255},renderer, (width-400)/2, 370, 75, 400),
                              Text("Si", 16,{255,215,0,255},renderer, (width-50)/2, 470, 75, 50),
                              Text("-> No", 24,{255,215,0,255},renderer, (width-100)/2, 570, 75, 100)};

  while(!endGame){

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
            opc_gameOver = (opc_gameOver > 1) ? opc_gameOver - 1 : 2;
          break;
          case SDLK_DOWN:
            opc_gameOver = (opc_gameOver < 2) ? opc_gameOver + 1 : 1;
          break;

          case SDLK_SPACE:
            switch (opc_gameOver) {
            case 1:
              //funcion para guardar archivo;
            break;
            case 2:
              return;
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


#endif // GAMEOVER_H_INCLUDED
