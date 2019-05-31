#include <iostream>
using namespace std;

#ifndef TEMPO_H
#define TEMPO_H

#include <ctime>

class Tempo {
 public:
  Tempo();
  Tempo(const Tempo& orig);
  virtual ~Tempo();

  void setTDecorrido(double tDecorrido);
  double getTDecorrido() const;
  void setFim(clock_t fim);
  clock_t getFim() const;
  void setInicio(clock_t inicio);
  clock_t getInicio() const;

  void restart();
  void stop();

 private:
  clock_t inicio, fim;
  double tDecorrido;
};

#endif /* TEMPO_H */
