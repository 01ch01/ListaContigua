// by ch

#include "../include/Lista.h"
#include <fstream>
#include <iostream>
#include <string>
#include "../include/Tempo.h"

Lista::Lista() {  // o construtor irá iniciar perguntando o tamanho da lista
  this->tam = 0;
  this->quant = 0;
  this->criarLista();
}

Lista::Lista(int tam) {
  this->quant = 0;
  this->tam = tam;
  this->criarLista();
}

void Lista::criarLista() {
  if (this->tam > 0)
    this->listaDePessoas = new Pessoa[this->tam];
}

Lista::Lista(const Lista& outro) {}

Lista::~Lista() {}

void Lista::shiftFront(int index) {
  for (int i = index; i < this->quant; i++) {
    this->listaDePessoas[i].copy(listaDePessoas[i + 1]);
  }
}

void Lista::insert(Pessoa claudio) {
  if (this->quant < this->tam) {
    shiftEnd();
    listaDePessoas[0].copy(claudio);
    this->quant++;

  } else
    cout << "\n\tERRO! A lista está cheia\n";
}

void Lista::shiftEnd() {
  for (int i = this->quant; i >= 1; i--)
    this->listaDePessoas[i].copy(listaDePessoas[i - 1]);
}

void Lista::remove(Pessoa claudio) {
  string term;
  bool flag = false;

  cout << "\n\tQual é o nome da pessoa que deseja remover? ";
  cin >> term;

  if (this->quant != 0) {
    for (int i = 0; i < this->quant; i++) {
      if (listaDePessoas[i].getNome() == term) {
        flag = true;
        shiftFront(i);
        this->quant--;
        cout << "\n\tA pessoa [" << term
             << "] foi excluída com sucesso da lista.\n";
      }
    }
    if (flag == false)
      cout << "\n\tA busca não encontrou resultados para [" << term << "].\n";

  } else
    cout << "\n\t\t\tA LISTA ESTÁ VAZIA\n";
}

void Lista::print() {
  if (this->quant == 0) {
    cout << "\n\t\t\tA LISTA ESTÁ VAZIA\n";
  } else {
    for (int i = 0; i < this->quant; i++) {
      cout << "\t==========================================\n";
      this->listaDePessoas[i].print();
    }
  }
}

void Lista::search() {
  bool flag = false;
  int term;
  cout << "\n\tQual é o CPF da pessoa que deseja pesquisar? ";
  cin >> term;
  Tempo time;
  for (int i = 0; i < this->quant; i++) {
    if (this->listaDePessoas[i].getCpf() == term) {
      flag = true;
      cout << "\n\t==========================================\n";
      this->listaDePessoas[i].print();
    }
  }
  if (flag == false)
    cout << "\n\tA pessoa [" << term << "] não foi encontrada =(\n";

  cout << "\n\tTEMPO UTILIZADO PARA BUSCA - FORÇA BRUTA\n";
  time.stop();
}

void Lista::bsearch() {
  // ORDENANDO LISTA
  this->bubbleSort();

  int inicio, fim, meio, term;
  inicio = 0;
  fim = this->quant - 1;
  bool flag = false;

  cout << "\n\tQual é o CPF da pessoa que deseja pesquisar? ";
  cin >> term;
  Tempo time;
  while (inicio < fim) {
    meio = (inicio + fim) / 2;

    if (this->listaDePessoas[meio].getCpf() == term) {
      flag = true;
      this->listaDePessoas[meio].print();
      inicio = fim + 1;  // isso aqui é uma gambiarra do zé rui pra não usar o
                         // break que eu sei tá kkk

    } else if (term < this->listaDePessoas[meio].getCpf())
      fim = meio - 1;  // pega do meio pro começo
    else
      inicio = meio + 1;  // pega do meio pro final
  }
  if (flag == false)
    cout << "\n\tA busca binária não encontrou resultados para o CPF [" << term
         << "].\n";
  cout << "\n\tTEMPO UTILIZADO PARA BUSCA BINÁRIA";
  time.stop();
}

void Lista::criarListaRandom() {
  Pessoa claudio;
  Tempo time;

  for (int i = 0; i < this->tam; i++) {
    claudio.fillRandom(i);
    this->insert(claudio);
  }
  cout << "\n\tTEMPO UTILIZADO PARA CRIAR LISTA RANDÔMICA";
  time.stop();
}

/*
 * agora eu irei definir o modo de como os meus arquivos serão salvos.
 * é muito importante que eu me lembre como esses arquivos estarão dispostos,
 * para quaisquer alterações futuras
 *"GUARDAR PARA EVENTUAIS CONSULTAS"
 */

void Lista::saveLista() {
  string nomeDoArquivo = "../assets/dados.txt";
  ofstream arquivoSalvo;
  arquivoSalvo.open(nomeDoArquivo.c_str());
  Tempo time;

  // agora vou definir como os arquivos de texto serão salvos

  arquivoSalvo << "Quant: " << quant << "\tTam: " << tam << "\n";
  arquivoSalvo << "\tCPF\t\tNome\t\tTel\t\tAno\tEmail\t\t\tSexo\n";

  for (int i = 0; i < quant; i++) {
    arquivoSalvo << "\t" << this->listaDePessoas[i].getCpf() << "\t"
                 << this->listaDePessoas[i].getNome() << "\t"
                 << this->listaDePessoas[i].getTel() << "\t"
                 << this->listaDePessoas[i].getData_nasc() << "\t"
                 << this->listaDePessoas[i].getEmail() << "\t"
                 << this->listaDePessoas[i].getSexo() << "\n";
  }

  system("clear");
  cout << "\n\tTEMPO UTILIZADO PARA SALVAR ARQUIVOS DA LISTA\n";
  time.stop();
  arquivoSalvo.close();
}

void Lista::bubbleSort() {
  int indexFinal = this->quant - 1;
  while (indexFinal > 0) {
    for (int i = 0; i < indexFinal; i++) {
      if (listaDePessoas[i].getCpf() > listaDePessoas[i + 1].getCpf())
        shift(listaDePessoas[i], listaDePessoas[i + 1]);
    }
    indexFinal--;
  }
}

void Lista::shift(Pessoa& p1, Pessoa& p2) {
  Pessoa aux;
  aux.copy(p1);
  p1.copy(p2);
  p2.copy(aux);
}

void Lista::loadLista() {
  Tempo time;
  string nomeDoArquivo = "../assets/dados.txt";
  ifstream arquivoLido;

  arquivoLido.open(nomeDoArquivo.c_str());
  int q;
  arquivoLido >> q;
  arquivoLido >> tam;
  this->listaDePessoas = new Pessoa[this->tam];

  string nome, tel, data_nasc, email, sexo;
  int cpf;
  Pessoa claudio;

  // agora vou ler os arquivos salvos de acordo com o meu BD.txt
  for (int i = 0; i < q; i++) {
    // isso são os "getters" do txt
    arquivoLido >> cpf;
    arquivoLido >> nome;
    arquivoLido >> tel;
    arquivoLido >> data_nasc;
    arquivoLido >> email;
    arquivoLido >> sexo;

    // e agora vou volocá-los na Pessoa claudio criada na linha [203]
    claudio.setCpf(cpf);
    claudio.setNome(nome);
    claudio.setTel(tel);
    claudio.setData_nasc(data_nasc);
    claudio.setEmail(email);
    claudio.setSexo(sexo);

    // e agora vou colocar esses atributos da Pessoa claudio dentro da lista que
    // foi criada na linha [208]
    this->insert(claudio);
  }

  arquivoLido.close();
  system("clear");
  cout << "\n\tTEMPO UTILIZADO PARA CARREGAR ARQUIVOS DA LISTA\n";
  time.stop();
}
