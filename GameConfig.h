#ifndef GAMECONFIG_H_INCLUDED
#define GAMECONFIG_H_INCLUDED

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <SDL2\SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

using namespace std;

/// VARIABLES GLOBALES //

  enum GameState {
    MENU,
    GAME,
    GAME_OVER,
    SAVE_SCORE,
    VIEW_SCORE
  };

  extern GameState currentGameState;

  // Dimensiones de pantalla.
  const int width = 800;
  const int heig = 980;
  //----------------

  // Control del ciclo de juego.
  bool endGame = false;
  //----------------

  // Opcion del menu.
  int opc_menu = 1;
  int opc_gameOver = 1;
  //----------------

  // Variables de jugabilidad.
  int tipoFlechaActivo = 0;

  int puntos = 0; // Cantidad de puntos.
  string puntos_string = to_string(puntos); // Cantidad de puntos en str para ttf.

  int game_time = 99; // Tiempo de juego
  string game_time_string = to_string(game_time); // Tiempo de juego en str para ttf.
  //----------------

  // Control de FPS.
  const int FPS = 60;
  const int frameDelay = 1000 / FPS;  // Calcula el tiempo que debería durar cada fotograma.

  Uint32 frameStart;  // Registra el tiempo el que emoieza el nuevo fotograma.
  Uint32 lastTime = 0; // Variable para registrar el último tiempo registrado.
  int frameTime; // Calcula el tiempo que ha tardado en procesarse el fotograma actual.
  //---------------


    ///Creamos la ventana del juego con sus parametros.
  SDL_Window *window = SDL_CreateWindow("Elemental Arrow", // <- Nombre de la venta
                            SDL_WINDOWPOS_CENTERED, // <- Posicion X del monitor donde creo la ventana. (SDL_WINDOWPOS_CENTERED - Le dice que la centre en el monitor).
                            SDL_WINDOWPOS_CENTERED, // <- Posicion Y del monitor donde creo la ventana. (SDL_WINDOWPOS_CENTERED - Le dice que la centre en el monitor).
                            width, // <- Ancho en pixel de la pantalla.
                            heig, // <- Alto en pixel de la panatalla.
                            false); // <- Parametro para definir si se abre en pantalla completa o no.


  ///Creamos la variable render (encargado de volcar las imagenes en la venta).
  SDL_Renderer *renderer = SDL_CreateRenderer(window, // <- Variable tipo ventana de juego.
                                -1, // <- Siempre va asi.
                                SDL_RENDERER_ACCELERATED); // <- Siempre va asi (define de que manera se procesa el juego, si por hardware o software).

#endif // GAMECONFIG_H_INCLUDED
