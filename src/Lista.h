// by ch

#include <fstream>
#include <iostream>
#include <string>
#include "Pessoa.h"
#include "Tempo.h"
using namespace std;

#ifndef LISTA_H
#define LISTA_H

class Lista {
 public:
  Lista();
  Lista(int i);
  Lista(const Lista& outro);  // construtor de cópias
  virtual ~Lista();

  // trabalhando com arquivos salvos '-'
  void loadLista();
  void saveLista();
  void criarLista();
  void criarListaRandom();

  void insert(Pessoa listaDePessoas);
  void shiftEnd();

  void remove(Pessoa claudio);
  void shiftFront(int index);

  void print();
  void search();
  void bsearch();
  void bubbleSort();
  void shift(Pessoa& p1, Pessoa& p2);

 private:
  int quant, tam;
  Pessoa* listaDePessoas;
};

#endif /* LISTA_H */
