#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <SDL2\SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

/// Enumeración para las direcciones del jugador
enum Direccion { QUIETO, IZQUIERDA, DERECHA };
Direccion direccion = QUIETO;
int img_num = 1;

// Variable para alternar entre sprites
bool alternarSprites = false;

/// Control de FPS.
const int FPS = 60;
const int frameDelay = 1000 / FPS;

Uint32 frameStart;
int frameTime;

/// Declaracion de variables generales para el uso del juego.
SDL_Window *window = NULL;
int width = 800;
int heig = 640;

// Creamos la variable render (encargado de volcar las imagenes en la venta).
SDL_Renderer *renderer = NULL;

// Función para disparar flecha.
void disparar(SDL_Renderer* renderer, SDL_Texture* texFlecha, int& xf, int& yf, bool& flechaDisparada);

// Función para chequear colisiones.
bool chequearColision(SDL_Rect rectFlecha, SDL_Rect rectEnemigo);

// Variable para controlar si la flecha ha sido disparada.
bool flechaDisparada = false;

// Variable para controlar si el enemigo está presente.
bool enemigoPresente = true;

int main(int argc, char* args[]) {
    /// Inicio de SDL.
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) { // Inicio de los modulos de SDL
        cout << "Error al iniciar SDL " << SDL_GetError() << endl;
    }

    /// Creamos la ventana del juego con sus parametros.
    window = SDL_CreateWindow("Elemental Arrow", // <- Nombre de la venta
                              SDL_WINDOWPOS_CENTERED, // <- Posicion X del monitor donde creo la ventana. (SDL_WINDOWPOS_CENTERED - Le dice que la centre en el monitor).
                              SDL_WINDOWPOS_CENTERED, // <- Posicion Y del monitor donde creo la ventana. (SDL_WINDOWPOS_CENTERED - Le dice que la centre en el monitor).
                              width, // <- Ancho en pixel de la pantalla.
                              heig, // <- Alto en pixel de la panatalla.
                              false); // <- Parametro para definir si se abre en pantalla completa o no.

    /// Creamos el dibujante.
    renderer = SDL_CreateRenderer(window, // <- Variable tipo ventana de juego.
                                  -1, // <- Siempre va asi.
                                  SDL_RENDERER_ACCELERATED); // <- Siempre va asi.

    /// Creacion de elementos para mostrar en pantalla: (Superficie y textura)
    // Creamos la superficie de la textura.
    // Cargar los sprites del jugador
    SDL_Surface* surfPlayerRight1 = IMG_Load("src/img/PlayerRight_1.png");
    SDL_Surface* surfPlayerRight2 = IMG_Load("src/img/PlayerRight_2.png");
    SDL_Surface* surfPlayerLeft1 = IMG_Load("src/img/PlayerLeft_1.png");
    SDL_Surface* surfPlayerLeft2 = IMG_Load("src/img/PlayerLeft_2.png");
    SDL_Surface* surfPlayerShot = IMG_Load("src/img/PlayerShot.png");

    // Creamos la textura.
    // Convertir las superficies a texturas
    SDL_Texture* texPlayerRight1 = SDL_CreateTextureFromSurface(renderer, surfPlayerRight1);
    SDL_Texture* texPlayerRight2 = SDL_CreateTextureFromSurface(renderer, surfPlayerRight2);
    SDL_Texture* texPlayerLeft1 = SDL_CreateTextureFromSurface(renderer, surfPlayerLeft1);
    SDL_Texture* texPlayerLeft2 = SDL_CreateTextureFromSurface(renderer, surfPlayerLeft2);
    SDL_Texture* texPlayerShot = SDL_CreateTextureFromSurface(renderer, surfPlayerShot);

    // Liberar las superficies
    SDL_FreeSurface(surfPlayerRight1);
    SDL_FreeSurface(surfPlayerRight2);
    SDL_FreeSurface(surfPlayerLeft1);
    SDL_FreeSurface(surfPlayerLeft2);
    SDL_FreeSurface(surfPlayerShot);

    // Variable de control de ejecucion del juego.
    bool endGame = false;

    /// Bloque para creacion del fondo.
    SDL_Surface* surfFondo = NULL;
    surfFondo = IMG_Load("src/img/nivel.png");

    SDL_Texture* texFondo = SDL_CreateTextureFromSurface(renderer, surfFondo);

    SDL_FreeSurface(surfFondo);

    /// Bloque para creacion del flecha.
    SDL_Surface* surfFlecha = NULL;
    surfFlecha = IMG_Load("src/img/f_agua.png");

    SDL_Texture* texFlecha = SDL_CreateTextureFromSurface(renderer, surfFlecha);

    SDL_FreeSurface(surfFlecha);

    /// Bloque de ejemplo para enemigo.
    SDL_Surface* surfEnemigo = NULL;
    surfEnemigo = IMG_Load("src/img/fuego.png");

    SDL_Texture* texEnemigo = SDL_CreateTextureFromSurface(renderer, surfEnemigo);

    SDL_FreeSurface(surfEnemigo);

    /// Variables de los elementos en pantalla.
    /// Variables DEL JUGADOR:
    int anchoJugador = 64;
    int altoJugador = 64;
    int posXJugador = width / 2;
    int posYJugador = heig - altoJugador - 10;

    /// Posicion del Enemigo.
    int xe = 500;
    int ye = 0;

    /// Posicion de la Flecha.
    int xf = posXJugador;
    int yf = posYJugador;

    /// Ciclo de ejecucion del juego.
    while (!endGame) {
        frameStart = SDL_GetTicks();
        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }

        SDL_Rect rectPlayer = {posXJugador, posYJugador, anchoJugador, altoJugador};
        SDL_Rect rectFondo = {0, 0, width, heig};

        SDL_RenderClear(renderer);

        // Renderiza el fondo
        SDL_RenderCopy(renderer, texFondo, NULL, &rectFondo);

        // Renderiza y mueve la flecha si ha sido disparada
        if (flechaDisparada) {
            SDL_Rect rectFlecha = {xf, yf, 64, 64};
            yf -= 5;
            if (yf < 0) {
                flechaDisparada = false;
            }
            SDL_RenderCopy(renderer, texFlecha, NULL, &rectFlecha);

            // Chequea colisiones con el enemigo
            if (enemigoPresente) {
                SDL_Rect rectEnemigo = {xe, ye, 64, 64};
                if (chequearColision(rectFlecha, rectEnemigo)) {
                    enemigoPresente = false; // Elimina al enemigo
                    flechaDisparada = false; // Elimina la flecha

                    // Reinicia la posición del enemigo
                    xe = rand() % (width - 64);
                    ye = 0;
                    enemigoPresente = true; // Marca que hay un nuevo enemigo
                }
            }
        }

        // Renderiza y mueve el enemigo si está presente
        if (enemigoPresente) {
            SDL_Rect rectEnemigo = {xe, ye, 64, 64};
            if (ye < 560 - 64) {
            ye += 2;
            } else {
                ye = 560 - 64;
            }
            SDL_RenderCopy(renderer, texEnemigo, NULL, &rectEnemigo);
        }

        // Renderiza al jugador
        SDL_Texture* currentTexture = NULL;
        if (direccion == DERECHA && img_num == 1) {
          currentTexture = texPlayerRight1;
        } else if (direccion == DERECHA && img_num == 2){
          currentTexture = texPlayerRight2;
        } else if (direccion == IZQUIERDA && img_num == 1) {
            currentTexture = texPlayerLeft1;
        } else if (direccion == IZQUIERDA && img_num == 2){
            currentTexture = texPlayerLeft2;
        } else{
            currentTexture = texPlayerShot;
        }

        SDL_RenderCopy(renderer, currentTexture, NULL, &rectPlayer);

        SDL_RenderPresent(renderer);

// Control de eventos del juego
SDL_Event e;
if (SDL_PollEvent(&e)) {
    switch (e.type) {
        case SDL_QUIT:
            endGame = true;
            break;
        case SDL_KEYDOWN:
            switch (e.key.keysym.sym) {
                case SDLK_ESCAPE:
                    endGame = true;
                    break;
                case SDLK_RIGHT:
                    direccion = DERECHA;
                    posXJugador += 10;
                    if (img_num == 1){
                      img_num = 2;
                    } else {
                      img_num = 1;
                    }
                    break;
                case SDLK_LEFT:
                    direccion = IZQUIERDA;
                    posXJugador -= 10;
                    if (img_num == 1){
                      img_num = 2;
                    } else {
                      img_num = 1;
                    }
                    break;
                case SDLK_SPACE:
                    if (!flechaDisparada) {
                        yf = posYJugador;
                        xf = posXJugador;
                        flechaDisparada = true;
                        direccion = QUIETO;
                    }
                    break;
                }
                break;
            }
        }else {
    // Si no hay eventos, desactivar la alternancia
    alternarSprites = false;
    }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

// Función para disparar flecha.
void disparar(SDL_Renderer* renderer, SDL_Texture* texFlecha, int& xf, int& yf, bool& flechaDisparada) {
    if (flechaDisparada) {
        SDL_Rect rectFlecha = {xf, yf, 64, 64};
        yf -= 5;
        if (yf < 0) {
            flechaDisparada = false;
        }
        SDL_RenderCopy(renderer, texFlecha, NULL, &rectFlecha);
    }
}

// Función para chequear colisiones.
bool chequearColision(SDL_Rect rectFlecha, SDL_Rect rectEnemigo) {
    if (rectFlecha.x < rectEnemigo.x + rectEnemigo.w &&
        rectFlecha.x + rectFlecha.w > rectEnemigo.x &&
        rectFlecha.y < rectEnemigo.y + rectEnemigo.h &&
        rectFlecha.y + rectFlecha.h > rectEnemigo.y) {
        return true; // Hay colisión
    }
    return false; // No hay colisión
}
