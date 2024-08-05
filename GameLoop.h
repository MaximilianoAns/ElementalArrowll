#ifndef GAMELOOP_H_INCLUDED
#define GAMELOOP_H_INCLUDED

#include "GameConfig.h"

#include "Enemy.h"
#include "Player.h"
#include "Flecha.h"
#include "UI.h"
#include "Collisions.h"

class Menu;

void GameLoop(){

/// Creacion de objetos para mostrar en pantalla: (Collider y texturas)

  puntos = 0;
  game_time = 99;
  puntos_string = to_string(puntos);

  UI_FondoNivel fondoNivel(renderer);

  Wall wall(renderer);

  Player jugador(0,renderer);

  UI_hp vida(5, renderer);
  UI_IconoPuntos ui_moneda(renderer);
  UI_IconoTimer ui_reloj(renderer);
  UI_hud ui_hud(renderer);


  Text contador_puntos(puntos_string, 24,{255,215,0,255},renderer, 530 , 8, 50,50);

  Text reloj_juego(game_time_string, 24,{255,215,0,255},renderer, 380 , 8, 50,50);

  Enemy *vecEnemy = new Enemy[5]{ Enemy(1, renderer),
                                  Enemy(2, renderer),
                                  Enemy(3, renderer),
                                  Enemy(4, renderer),
                                  Enemy(5, renderer)};

  Flecha *vecFlecha = new Flecha[5]{Flecha(1, renderer, 200, 1000),
                                    Flecha(2, renderer, 200, 1000),
                                    Flecha(3, renderer, 200, 1000),
                                    Flecha(4, renderer, 200, 1000),
                                    Flecha(5, renderer, 200, 1000)};

///-----------------------------------------------------------------------------

///Ciclo de ejecucion del juego.
  while( !endGame && currentGameState == GAME && game_time > 1){

  if(wall.getHp() < 1){
    currentGameState = GAME_OVER;
    return;
  }

  if(game_time < 1){
    currentGameState = GAME_OVER;
    return;
  }


/// Control de velocidad de juego.
  frameStart = SDL_GetTicks();
  frameTime = SDL_GetTicks() - frameStart;

  if(frameDelay > frameTime){
    SDL_Delay(frameDelay - frameTime);
  }

///-----------------------------------------------------------------------------

///Control de eventos del juego (Todo lo que pasa con el teclado, mouse, etc.)

  SDL_Event e; // <- Var de tipo SDL Evento. Encargada de registrar los eventos del sistema. (Teclado, mouse, etc)

  if (SDL_PollEvent(&e)){ // <- Valida si ocurrio un evento.

    switch(e.type){ // <- Switch para verificar que tipo de evento ocurrio.

      ///Control de cierre de juego
      case SDL_QUIT: // <- Verifica si se cierra el juego desde la "X" de cerrar
        endGame = true; // <- Si se cumple el case, cambioa el estado de "endGame" y cierra el juego.
        break;

      case SDL_KEYDOWN:           // <- Verifica si se PRESIONO una tecla.
        switch(e.key.keysym.sym){ // <- Verifica: el evento.tecla.tecla de sys.tecla especifica.
          case SDLK_ESCAPE:       // <- Verifica si se presiono la tecla "ESC".
            currentGameState = MENU;
          break;

      ///Control de movimiento del jugador y selecion de flechas.
          case SDLK_RIGHT:
            jugador.moverPlayer('d');
            break;
          case SDLK_LEFT:
            jugador.moverPlayer('i');
            break;
          case SDLK_q:
            tipoFlechaActivo = 1;
            break;
          case SDLK_w:
            tipoFlechaActivo = 2;
            break;
          case SDLK_e:
            tipoFlechaActivo = 3;
            break;
          case SDLK_d:
            tipoFlechaActivo = 4;
            break;
          case SDLK_f:
            tipoFlechaActivo = 5;
            break;
          case SDLK_SPACE:
            switch(tipoFlechaActivo){
              case 1:
                if(vecFlecha[0].getActivo() == false){
                  vecFlecha[0].setActivo(true);
                  vecFlecha[0].disparar(jugador.getRect().x, jugador.getRect().y);
                  jugador.moverPlayer('s');
                }
              break;
              case 2:
                if(vecFlecha[1].getActivo() == false){
                  vecFlecha[1].setActivo(true);
                  vecFlecha[1].disparar(jugador.getRect().x, jugador.getRect().y);
                  jugador.moverPlayer('s');
                }
              break;
              case 3:
                if(vecFlecha[2].getActivo() == false){
                  vecFlecha[2].setActivo(true);
                  vecFlecha[2].disparar(jugador.getRect().x, jugador.getRect().y);
                  jugador.moverPlayer('s');
                }
              break;
              case 4:
                if(vecFlecha[3].getActivo() == false){
                  vecFlecha[3].setActivo(true);
                  vecFlecha[3].disparar(jugador.getRect().x, jugador.getRect().y);
                  jugador.moverPlayer('s');
                }
              break;
              case 5:
                if(vecFlecha[4].getActivo() == false){
                  vecFlecha[4].setActivo(true);
                  vecFlecha[4].disparar(jugador.getRect().x, jugador.getRect().y);
                  jugador.moverPlayer('s');
                }
              break;
            }
            break;
      }
    }
  }

///-------------------- Actualizacion de elementos en pantalla. ----------------


	/// MUESTRO EN PANTALLA (El orden en el cual se renderizan representan las capas en pantalla)

  fondoNivel.render();

  ui_hud.render();
  ui_reloj.render();
  ui_moneda.render();
  vida.render();

  wall.render();
  jugador.render();

  // Control de actualizacion del Reloj de juego.
    Uint32 currentTime = SDL_GetTicks();
    if (currentTime > lastTime + 1000) {
        game_time--;
        lastTime = currentTime;
    }
    game_time_string = to_string(game_time);
    Text reloj_juego(game_time_string, 24, {255, 215, 0, 255}, renderer, 400, 8, 50, 50);
    reloj_juego.render();

  /// Render de los elementos con movimiento (Jugador, enemigos, flechas).
  for(int i = 0; i < 5; ++i) {
    // Chek de la colision entre el enemigo y la muralla.
    if (check_collisions(wall, vecEnemy[i]))
    {
      wall.actualizar_vida(wall, vida);
      vecEnemy[i].resetEnemigo();
    }
    // Chek de la colision entre el enemigo y la flecha.
    else if (vecEnemy[i].getTipoEnemigo() == vecFlecha[i].getTipoFlecha() ){ // <- Se verifica que el tipo de enemigo se corresponda con el tipo de flecha que lo mata.
      if(check_collisions(vecFlecha[i], vecEnemy[i])) // <- Verifica la colision entre la flecha y el enemigo.
      {
        vecFlecha[i].setActivo(false);
        vecFlecha[i].resetPos();
        vecEnemy[i].resetEnemigo();


        // Sumamos puntos a la variable de puntos y la convertimos en string para la funcion de la clase texto.
        puntos += vecEnemy[i].getPuntos();
        puntos_string = to_string(puntos);
      }
    }

    // Instanciamos el obj de contador de manera constante con el valor nuevo de puntos_string, para que se adapte al tamaño del rect.
    Text contador_puntos(puntos_string, 12,{255,215,0,255},renderer, 530 , 8, 50,50);
    contador_puntos.render();

    // Valida si el enemigo esta activo para hacerlo avanzar y renderizarlo.
    if (vecEnemy[i].getActivo()){
      vecEnemy[i].avanzarEnemigo();
      vecEnemy[i].render();
    }
    // Valida si la flecha esta activa para hacerlo avanzar y renderizarlo.
    if (vecFlecha[i].getActivo()){
      vecFlecha[i].avanzarFlecha();
      vecFlecha[i].render();
    }

  }

  SDL_RenderPresent(renderer); /// <- Dibuja en la ventana lo que tiene pendiente el RENDER.
  SDL_RenderClear(renderer);  /// <- Limpia la ventana.

 }
}
#endif // GAMELOOP_H_INCLUDED
