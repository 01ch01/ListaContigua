
#include "../include/Tempo.h"

Tempo::Tempo() {
  this->inicio = clock();
  this->fim = clock();
  this->tDecorrido = 0.0;
}

Tempo::Tempo(const Tempo& orig) {
  this->inicio = orig.getInicio();
  this->fim = orig.getFim();
  this->tDecorrido = orig.getTDecorrido();
}

Tempo::~Tempo() {}

void Tempo::setTDecorrido(double tDecorrido) {
  this->tDecorrido = tDecorrido;
}

double Tempo::getTDecorrido() const {
  return tDecorrido;
}

void Tempo::setFim(clock_t fim) {
  this->fim = fim;
}

clock_t Tempo::getFim() const {
  return fim;
}

void Tempo::setInicio(clock_t inicio) {
  this->inicio = inicio;
}

clock_t Tempo::getInicio() const {
  return inicio;
}

void Tempo::restart() {
  this->inicio = clock();
  this->fim = clock();
  this->tDecorrido = 0.0;
}

void Tempo::stop() {
  this->fim = clock();
  this->tDecorrido = (double)(this->fim - this->inicio);
  cout << "\n\tTempo gasto: " << tDecorrido << " ms, " << tDecorrido / 1000
       << " s e " << tDecorrido / 60000 << " min.\n";
}
