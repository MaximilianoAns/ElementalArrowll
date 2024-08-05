#ifndef ARCHIVOPUNTOS_H_INCLUDED
#define ARCHIVOPUNTOS_H_INCLUDED

#include "Text.h"

class Menu;

class RegPuntos{
  private:
    char nombre[10];
    int puntos;

  public:
    RegPuntos(){;}
    RegPuntos(int _puntos, const char *_nombre)
    {
      strcpy(nombre,_nombre);
      puntos = _puntos;
    }

    void setNombre(const char *_nombre){strcpy(nombre,_nombre);}
    void setPuntos(int _puntos){puntos = _puntos;}

    const char* getNombre(){return nombre;}
    int getPuntos(){return puntos;}

};

class ArchivoPuntos{
    private:
        char nombre[30];

    public:
    ArchivoPuntos(const char *n){
      strcpy(nombre,n);
    }

  bool grabarRegistro(RegPuntos reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        int escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
  }

  RegPuntos leerRegistro(int pos){
      RegPuntos reg;
      FILE *p=fopen(nombre,"rb");
      if(p==NULL){
          return reg;
      }
      fseek(p, pos * sizeof reg, 0);
      fread(&reg, sizeof reg, 1, p);
      fclose(p);
      return reg;
    }

  int contarRegistros(){
      FILE *p=fopen(nombre,"rb");
      if(p==NULL){
          return -1;
      }
      fseek(p, 0, 2);
      int cant=ftell(p)/sizeof(RegPuntos);
      fclose(p);
      return cant;
    }

  void puntajeValido(RegPuntos reg){

    int cantReg = contarRegistros();
    if (cantReg < 0){
      cantReg = 1;
    }

    RegPuntos *vecReg;
    vecReg = new RegPuntos[cantReg];

    RegPuntos *vecRegPts;
    vecRegPts = new RegPuntos[cantReg+1];

    // Ordenamos el vector de puntos;
    for(int i = 0; i < cantReg -1; i++){
      for(int j = 0; j < cantReg - i - 1; j++){
        if(vecReg[j].getPuntos() < vecReg[j+1].getPuntos()){
        RegPuntos temp = vecReg[j];
        vecReg[j] = vecReg[j + 1];
        vecReg[j+1] = temp;
        }
      }
    }

    // Capturamos el los extremos de los puntajes;
    int mayorpts = vecReg[0].getPuntos();
    int menorpts = vecReg[cantReg-1].getPuntos();

    if(cantReg < 10){
      grabarRegistro(reg);
      currentGameState = MENU;
    }
    else if (reg.getPuntos() < menorpts){
      currentGameState = MENU;
    }
    else if (reg.getPuntos() > mayorpts){
      vecRegPts[0] = reg;
      for(int i = 1; i < cantReg; i++ ){
        vecRegPts[i] = vecReg[i-1];
      }
      currentGameState = MENU;
    }
    else if (reg.getPuntos() < mayorpts && reg.getPuntos() >= menorpts){
      vecRegPts[cantReg-1] = reg;
      for(int i = 0; i < cantReg-1; i++ ){
        vecRegPts[i] = vecReg[i];
      }
      currentGameState = MENU;
    }
    currentGameState = MENU;
  }

/* // Func de Test de archivo.
  void mostar_test(){

  ArchivoPuntos arch("puntaje.dat");
  int cantReg = arch.contarRegistros();

  RegPuntos *vecregPts;
  vecregPts = new RegPuntos[cantReg];

  for(int i = 0; i < cantReg; i++){
    vecregPts[i] = arch.leerRegistro(i);
    vecregPts[i].mostrar();
  }

  }
*/
};


#endif // ARCHIVOPUNTOS_H_INCLUDED
