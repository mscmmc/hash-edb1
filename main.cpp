#include <iostream>
#include <string>
#include "hash.hpp"

int main() {
  Node* tabela[TAM_TABELA];
  inicializarTabela(tabela);  ///< Inicia a tabela com ponteiros nulos

  int opcaoEscolhida;
  do {
  } while (opcaoEscolhida != 0);

  liberarTabela(tabela);
  return 0;
}
