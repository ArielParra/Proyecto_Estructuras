
#include "Nivel.cpp"
//#define DEBUG_LINUX //debug para imprimir en Klotski solucionador

#include "Klotski.cpp"

/* 
// Implicitos dentro de Klotski.cpp
// si se incluyen da el error de: error: redefinition of...
#include "compatibilidad.h"
#include "TiposDeDatos.h"
#include "FuncionesAuxiliares.h"
#include "Bloque.cpp"
#include "Tabla.cpp"
*/



inline void logouaa(){
const int altura_grafico=16,ancho_grafico=43;
int x=(getmaxX()/4)-(ancho_grafico/2),y=(getmaxY()/2)-(altura_grafico/2);
gotoxy(x, y);  cout<<FG_BLUE<<"█▒  "<< FG_CYAN<<"██████       "<<FG_CYAN<<"██████ "<<FG_BLUE<<"▒▒█████▒▒▒        "; 
gotoxy(x, y++);cout<<FG_BLUE<<"███  "<<FG_CYAN<<"███████   "<<FG_CYAN<<"███████ "<<FG_BLUE<<"▒█████████████     "; 
gotoxy(x, y++);cout<<FG_BLUE<<"███▒ "<<FG_CYAN<<"███████                      "<<FG_BLUE<<"█████   "; 
gotoxy(x, y++);cout<<FG_BLUE<<"███▒ "<<FG_CYAN<<"███████               "<<FG_CYAN<<"███████  "<<FG_BLUE<<"▒███▒ ";
gotoxy(x, y++);cout<<FG_BLUE<<"███▒ "<<FG_CYAN<<"███████        "<<FG_YELLOW<<"██      "<<FG_CYAN<<"████████ "<<FG_BLUE<<"▒███▒"; 
gotoxy(x, y++);cout<<FG_BLUE<<"███▒ "<<FG_CYAN<<"███████       "<<FG_YELLOW<<"████ "<<FG_RED<<"█    "<<FG_CYAN<<"████████ "<<FG_BLUE<<"▒███";
gotoxy(x, y++);cout<<FG_BLUE<<"███▒ "<<FG_CYAN<<"███████      "<<FG_YELLOW<<"████ "<<FG_RED<<"███    "<<FG_CYAN<<"███████ "<<FG_BLUE<<"▒███";
gotoxy(x, y++);cout<<FG_BLUE<<"███▒ "<<FG_CYAN<<"███████     "<<FG_YELLOW<<"████ "<<FG_RED<<"█████   "<<FG_CYAN<<"███████ "<<FG_BLUE<<"▒███"; 
gotoxy(x, y++);cout<<FG_BLUE<<"███▒ "<<FG_CYAN<<"███████    "<<FG_YELLOW<<"████ "<<FG_RED<<"██████   "<<FG_CYAN<<"███████ "<<FG_BLUE<<"▒███";
gotoxy(x, y++);cout<<FG_BLUE<<"███▒ "<<FG_CYAN<<"███████    "<<FG_YELLOW<<"███ "<<FG_RED<<"██████    "<<FG_CYAN<<"███████ "<<FG_BLUE<<"▒███";
gotoxy(x, y++);cout<<FG_BLUE<<"███▒ "<<FG_CYAN<<"███████    "<<FG_YELLOW<<"██ "<<FG_RED<<"█████      "<<FG_CYAN<<"███████ "<<FG_BLUE<<"▒███";
gotoxy(x, y++);cout<<FG_BLUE<<"████ "<<FG_CYAN<<"████████      "<<FG_RED<<"████       "<<FG_CYAN<<"███████ "<<FG_BLUE<<"▒███"; 
gotoxy(x, y++);cout<<FG_BLUE<<" ███▒ "<<FG_CYAN<<"████████      "<<FG_RED<<"██        "<<FG_CYAN<<"███████ "<<FG_BLUE<<"▒███";
gotoxy(x, y++);cout<<FG_BLUE<<" ▒████  "<<FG_CYAN<<"███████               ███████ "<<FG_BLUE<<"▒███"; 
gotoxy(x, y++);cout<<FG_BLUE<<"   █████                      "<<FG_CYAN<<"███████ "<<FG_BLUE<<"▒███";
gotoxy(x, y++);cout<<FG_BLUE<<"     ▒████████████▒ "<<FG_CYAN<<"████████   ███████ "<<FG_BLUE<<"███"<<RESET_COLOR;
fflush(stdout);
}


inline void flecha_derecha() {
  const int altura_grafico=9, ancho_grafico=14;
  int x=getmaxX()-ancho_grafico,y=getmaxY()-altura_grafico;
  cout<<FG_BLUE;
  gotoxy(x, y++); cout << "   ▒▒▒▒▒▒▒▒    ";
  gotoxy(x, y++); cout << "  ▒        ▒   "; 
  gotoxy(x, y++); cout << " ▒      ▒   ▒  "; 
  gotoxy(x, y++); cout << "▒        ▒   ▒ "; 
  gotoxy(x, y++); cout << "▒  ▒▒▒▒▒▒▒▒  ▒ "; 
  gotoxy(x, y++); cout << "▒        ▒   ▒ ";  
  gotoxy(x, y++); cout << " ▒      ▒   ▒  ";  
  gotoxy(x, y++); cout << "  ▒        ▒   ";  
  gotoxy(x, y++); cout << "   ▒▒▒▒▒▒▒▒    "<<RESET_COLOR;
  fflush(stdout);

}

inline void flecha_izquierda() {
  const int altura_grafico=9;
  int x=1,y=getmaxY()-altura_grafico;
  cout<<FG_BLUE;
  gotoxy(x, y++); cout << "   ▒▒▒▒▒▒▒▒    ";
  gotoxy(x, y++); cout << "  ▒        ▒   ";  
  gotoxy(x, y++); cout << " ▒   ▒      ▒  ";  
  gotoxy(x, y++); cout << "▒   ▒        ▒ ";  
  gotoxy(x, y++); cout << "▒  ▒▒▒▒▒▒▒▒  ▒ ";  
  gotoxy(x, y++); cout << "▒   ▒        ▒ "; 
  gotoxy(x, y++); cout << " ▒   ▒      ▒  "; 
  gotoxy(x, y++); cout << "  ▒        ▒   "; 
  gotoxy(x, y++); cout << "   ▒▒▒▒▒▒▒▒    "<<RESET_COLOR;
  fflush(stdout);
}

void primer_pantalla() {
  /*Primer Pantalla*/
  clrscr();
  flecha_derecha();
  const unsigned int altura_grafico = 16, ancho_grafico = 43;
  const unsigned int x = (getmaxX() / 3) + (ancho_grafico / 3);
  unsigned int y = (getmaxY() / 2) - (altura_grafico / 3);
  logouaa();
  gotoxy(x, y++);

  fflush(stdout);
}
void segunda_pantalla() {
  /*segunda Pantalla*/
  clrscr();
  flecha_izquierda();
  flecha_derecha();
  const int ancho_grafico = 93,altura_grafico=12;

  int x = (getmaxX() / 2) - (ancho_grafico / 2),y = (getmaxY() / 2) - (altura_grafico/2);
  gotoxy(x, y++); cout<<"░██████╗░█████╗░██╗░░░░░██╗░░░██╗░█████╗░██╗░█████╗░███╗░░██╗░█████╗░██████╗░░█████╗░██████╗░";
  gotoxy(x, y++); cout<<"██╔════╝██╔══██╗██║░░░░░██║░░░██║██╔══██╗██║██╔══██╗████╗░██║██╔══██╗██╔══██╗██╔══██╗██╔══██╗";
  gotoxy(x, y++); cout<<"╚█████╗░██║░░██║██║░░░░░██║░░░██║██║░░╚═╝██║██║░░██║██╔██╗██║███████║██║░░██║██║░░██║██████╔╝";
  gotoxy(x, y++); cout<<"░╚═══██╗██║░░██║██║░░░░░██║░░░██║██║░░██╗██║██║░░██║██║╚████║██╔══██║██║░░██║██║░░██║██╔══██╗";
  gotoxy(x, y++); cout<<"██████╔╝╚█████╔╝███████╗╚██████╔╝╚█████╔╝██║╚█████╔╝██║░╚███║██║░░██║██████╔╝╚█████╔╝██║░░██║";
  gotoxy(x, y++); cout<<"╚═════╝░░╚════╝░╚══════╝░╚═════╝░░╚════╝░╚═╝░╚════╝░╚═╝░░╚══╝╚═╝░░╚═╝╚═════╝░░╚════╝░╚═╝░░╚═╝";
  gotoxy(x, y++); cout<<"██████╗░███████╗  ██╗░░██╗██╗░░░░░░█████╗░████████╗░██████╗██╗░░██╗██╗";
  gotoxy(x, y++); cout<<"██╔══██╗██╔════╝  ██║░██╔╝██║░░░░░██╔══██╗╚══██╔══╝██╔════╝██║░██╔╝██║";
  gotoxy(x, y++); cout<<"██║░░██║█████╗░░  █████═╝░██║░░░░░██║░░██║░░░██║░░░╚█████╗░█████═╝░██║";
  gotoxy(x, y++); cout<<"██║░░██║██╔══╝░░  ██╔═██╗░██║░░░░░██║░░██║░░░██║░░░░╚═══██╗██╔═██╗░██║";
  gotoxy(x, y++); cout<<"██████╔╝███████╗  ██║░╚██╗███████╗╚█████╔╝░░░██║░░░██████╔╝██║░╚██╗██║";
  gotoxy(x, y++); cout<<"╚═════╝░╚══════╝  ╚═╝░░╚═╝╚══════╝░╚════╝░░░░╚═╝░░░╚═════╝░╚═╝░░╚═╝╚═╝";
  fflush(stdout);
}

void tercer_pantalla(int seleccion) {
  /*tercer Pantalla*/
  clrscr();
  flecha_izquierda();
  fflush(stdout);
  const char *colores[] = {FG_CYAN, FG_MAGENTA, FG_BLUE, FG_YELLOW};
  const char *opciones1[] = {"█▀▀ ▄▀█ █▀█ █▀▀ ▄▀█ █▀█",  "▀█▀ ▄▀█ █▄▄ █   █▀▀ █▀█ █▀█","█▀ █▀█ █   █ █ █▀▀ █ █▀█ █▄ █","█▀ ▄▀█ █   █ █▀█"};
  const char *opciones2[] = {"█▄▄ █▀█ █▀▄ █▄█ █▀█ █▀▄",  " █  █▀█ █▄█ █▄▄ ██▄ █▀▄ █▄█","▄█ █▄█ █▄▄ █▄█ █▄▄ █ █▄█ █ ▀█","▄█ █▀█ █▄▄ █ █▀▄"};

  const int altura_grafico = 10, ancho_grafico = 58;
  int x = (getmaxX() / 2) - (ancho_grafico / 2),y = (getmaxY() / 2) - (altura_grafico/2);
 
  for (int i = 0; i < 4; i++) {
    cout<<colores[i];
    if (i == seleccion) {
      gotoxy(x,y++);cout << "    ▀▄  " << opciones1[i];
      gotoxy(x,y++);cout << "▀▀▀▀▀█▀ " << opciones2[i];
      gotoxy(x,y++);cout << "    ▀   " <<RESET_COLOR;
      gotoxy(x,y++);
    } else {
      gotoxy(x,y++);cout << "        " << opciones1[i]; 
      gotoxy(x,y++);cout << "        " <<opciones2[i];
      gotoxy(x,y++);cout << "        " <<RESET_COLOR;
      gotoxy(x,y++);
    }
  }
  fflush(stdout);

}

void pantalla_Tabla(unsigned int numNivel){
  clrscr();
   Nivel nivel(numNivel);
  if(!nivel.cargarNivel()){
    const string errorArchivo="Error: No se pudo abrir '" + nivel.getNombreArchivo() +"'";
    gotoxy(getmaxX()/2 - errorArchivo.size()/2, getmaxY()/2 + 1);
    cout<<FG_RED<<errorArchivo;fflush(stdout);
    recuadro();
    delay(2000);
    clrscr();
  }else{
vector<string> matriz = nivel.getTableroNivel();
    Tabla tablaSolucion = Tabla(matriz);
    tablaSolucion.printTabla();
    gotoxy(getmaxX()/2 - nivel.getNombreNivel().size()/2, getmaxY()/2 - tablaSolucion.getAltoTablero()/2 - 2);
    cout<<nivel.getNombreNivel();
 
    gotoxy(getmaxX()/2 - tablaSolucion.getAnchoTablero()/2, getmaxY()/2 + tablaSolucion.getAltoTablero()/2 + 2);
    cout<<"Alto : "<< nivel.getAltoNivel();
    gotoxy(getmaxX()/2 - tablaSolucion.getAnchoTablero()/2, getmaxY()/2 + tablaSolucion.getAltoTablero()/2 + 3);
    cout<<"Ancho: "<< nivel.getAnchoNivel();
    const string errorArchivo="Presione Cualquier tecla para salir";
    gotoxy(getmaxX()/2 - errorArchivo.size()/2, getmaxY()/2 + tablaSolucion.getAltoTablero()/2 + 5 );
    cout<<FG_BLUE<<errorArchivo<<RESET_COLOR;fflush(stdout);

 
    getch();  
    
    }//nivel cargado

}

void cargueNivelPrimero(){
    clrscr();
    const string errorArchivo="Error: Cargue un Nivel primero";
    gotoxy(getmaxX()/2 - errorArchivo.size()/2, getmaxY()/2 + 1);
    cout<<FG_RED<<errorArchivo;fflush(stdout);
    recuadro();
    delay(2000);
}

void pantalla_Solucion(unsigned int numNivel){
    clrscr();
   Nivel nivel(numNivel);
  if(!nivel.cargarNivel()){
    const string errorArchivo="Error: No se pudo abrir '" + nivel.getNombreArchivo() +"'";
    gotoxy(getmaxX()/2 - errorArchivo.size()/2, getmaxY()/2 + 1);
    cout<<FG_RED<<errorArchivo;fflush(stdout);
    recuadro();
    delay(2000);
    clrscr();
  }else{
   vector<string> matriz = nivel.getTableroNivel();
    Tabla tablaSolucion = Tabla(matriz);
    
    //tablaSolucion.imprimirBloques();

    Klotski klotski = (tablaSolucion);
    unsigned int solucion = klotski.solucionador();
    string mensajeSolucion;
      clrscr();
      
      if(solucion==0){
        gotoxy(getmaxX()/2 - 15/2 ,getmaxY()/2 );
        mensajeSolucion="No Existe Solucion!";
        gotoxy(getmaxX()/2 - mensajeSolucion.size()/2, getmaxY()/2 );
        cout<<FG_RED<<mensajeSolucion;fflush(stdout);
        recuadro();
        delay(2000);
        clrscr();
      }else{
        mensajeSolucion="Solucion Encontrada!";
        gotoxy(getmaxX()/2 - mensajeSolucion.size()/2, getmaxY()/2 );
        cout<<FG_GREEN<<mensajeSolucion;fflush(stdout);
        recuadro();
        delay(2000);
        clrscr();
        klotski.printMovimientosSolucion(solucion,nivel.getNombreNivel());//pasos para la solucion
      }
  }
}
   

unsigned int elegirNivel(){
clrscr();
bool nivelCargado=false;//para el while
unsigned int N=validarEntradaInt();
  do{
  Nivel nivel(N);
  if(!nivel.cargarNivel()){
    const string errorArchivo="Error: No se pudo abrir '" + nivel.getNombreArchivo() +"'";
    gotoxy(getmaxX()/2 - errorArchivo.size()/2, getmaxY()/2 + 1);
    cout<<FG_RED<<errorArchivo;fflush(stdout);
    recuadro();
    delay(2000);
    clrscr();
    N=validarEntradaInt();
  }else{
    nivelCargado=true;
    }//nivel cargado
  }while(!nivelCargado);
  return N;
}

void menus(){
 int pantalla = 1, seleccion = 0;
 int numNivel=-1;
  bool salir = false;
  while (!salir) {

    switch (pantalla) {
    case 1:
      primer_pantalla();
      break;
    case 2:
      segunda_pantalla();
      break;
    case 3:
      tercer_pantalla(seleccion);
      break;
    }

    switch (getch()) {
      case KEY_LEFT:
        if (pantalla > 1) {
          pantalla--;
        }
        break;
      case KEY_RIGHT:
        if (pantalla < 3) {
          pantalla++;
        }
        break;
      case KEY_UP:
          if (pantalla == 3 && seleccion > 0) {
            seleccion--;
          }

          break;
      case KEY_DOWN:
          if (pantalla == 3 && seleccion < 3) {
            seleccion++;
          }
          break;
      case KEY_ENTER:
        if (pantalla == 3) {
          switch (seleccion) {
          case 0: //niveles
            numNivel=elegirNivel();
            break;
          case 1:
            if(numNivel!=-1){
              pantalla_Tabla(numNivel);
            }else{
              cargueNivelPrimero();
            }
              break;
          case 2:
          if(numNivel!=-1){
              pantalla_Solucion(numNivel);
          }else{
              cargueNivelPrimero();
            }
          break;
          case 3: //salir
            endCompat();
            exit(0);
            break;
        }
      break;
      }//if
    }// getch
  }//while
}


