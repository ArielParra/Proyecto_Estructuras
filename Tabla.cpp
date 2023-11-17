#include "Tabla.h"
#include <iostream>

using std::cout;
using std::endl;

/*Public*/

Tabla::Tabla() : ancho(0), altura(0) {} // constructor vacio

Tabla::Tabla(unsigned int ancho, unsigned int altura)
    : ancho(ancho), altura(altura) { // constructor
  matriz.resize(altura, string(ancho, ' ')); // Inicializa la matriz con strings vacíos
}

Tabla::Tabla(const vector<string>& matriz) { // constructor con matriz
    // Asigna la matriz proporcionada
    this->matriz = matriz;

    // Establece la altura y el ancho basándose en la matriz
    this->altura = matriz.size();
    this->ancho =  matriz[0].size();
}

/*Metodos get*/
unsigned int Tabla::getAncho() const { return this->ancho; }

unsigned int Tabla::getAltura() const { return this->altura; }

void Tabla::mostrarTabla() {
  for (unsigned int i = 0; i < Tabla::getAltura(); i++) {
    cout << matriz[i] << "| Fila " << i + 1 << endl;
  }
}

const vector<string>& Tabla::getMatriz() const {
  return this->matriz;
}

/*Metodos set*/
void Tabla::cargarFila(unsigned int fila, const string &datos) {
  this->matriz[fila] = datos.substr(0, ancho);
}