// by ch
#include <iostream>
#include <string>
#include "../include/Lista.h"
#include "../include/Pessoa.h"
#include "../include/Tempo.h"
using namespace std;

void menu() {
  cout << "\n\t==========================================";
  cout << "\n\t\t\tMENU PRINCIPAL\n"
          "\n\t1 - Inserir pessoa na lista;"
          "\n\t2 - Busca por nome (Força Bruta);"
          "\n\t3 - Busca Binária;"
          "\n\t4 - Mostrar todos os contatos;"
          "\n\t5 - Preencher lista aleatória;"
          "\n\t6 - Salvar arquivo;"
          "\n\t7 - Excluir pessoa;"
          "\n\t8 - Carregar arquivo salvo;"
          "\n\tQ - Sair.";
  cout << "\n\t==========================================";
  cout << "\n\tINSIRA SUA OPÇÃO: ";
}

int main(int argc, char** argv) {
  // Lista cadastro;
  Pessoa claudio;
  int tam = 0;

  cout << "\n\tInforme aqui o tamanho da lista randômica: ";
  cin >> tam;

  Lista cadastro(tam);
  cadastro.criarListaRandom();
  cadastro.saveLista();
  cadastro.loadLista();
  cadastro.print();
  cadastro.bsearch();
  cadastro.search();

  char op;

  do {
    menu();
    cin >> op;

    // agr a parte chata -_-
    if (op == '1') {
      system("clear");
      cadastro.insert(claudio);

    } else if (op == '2') {
      system("clear");
      cadastro.search();

    } else if (op == '3') {
      system("clear");
      cadastro.bsearch();

    } else if (op == '4') {
      system("clear");
      cadastro.print();

    } else if (op == '5') {
      system("clear");
      cout << "\n\tInsira o tamanho da lista randômica: ";
      cin >> tam;
      Lista cadastro(tam);
      cadastro.criarListaRandom();

    } else if (op == '6') {
      system("clear");
      cadastro.saveLista();

    } else if (op == '7') {
      system("clear");
      cadastro.remove(claudio);

    } else if (op == '8') {
      cout << "\n\tEM MANUTENÇÃO\n";
      //            system("clear");
      //            cadastro.loadLista();

    } else if (op != '1' && op != '2' && op != '3' && op != '4' && op != '5' &&
               op != '6' && op != '7' && op != '8' && op != 'q' && op != 'Q')
      cout << "\n\tERRO! Opção inválida\n";

  } while (op != 'q' && op != 'Q');

  return 0;
}
