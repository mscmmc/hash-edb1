#include <iostream>
#include <string>
#include "hash.hpp"

int main() {
  Node* tabela[TAM_TABELA];
  inicializarTabela(tabela);  ///< Inicia a tabela com ponteiros nulos

  int opcaoEscolhida;
  do {
    std::cout << "\n---------- OPÇÕES ----------\n"
              << "1. Inserir novo elemento\n"
              << "2. Buscar elemento por ID\n"
              << "3. Remover elemento por ID\n"
              << "4. Editar elemento\n"
              << "5. Listar todos os elementos\n"
              << "6. Ver número de colisões no catálogo\n"
              << "0. Sair\n";
    std::cin >> opcaoEscolhida;
    std::cin.ignore();

    switch (opcaoEscolhida) {
    case 1: {  ///< Usuário deseja inserir um novo elemento no catálogo
      std::string nome, categoria;
      float valor;
      std::cout << "Digite o nome do item: ";
      std::getline(std::cin, nome);
      std::cout << "Digite a categoria para o item: ";
      std::getline(std::cin, categoria);
      std::cout << "Digite o valor: ";
      std::cin >> valor;
      inserirElemento(tabela, nome, categoria, valor);
      break;
    }

    case 2: {  ///< Usuário deseja buscar elemento a partir de um ID
      int id;
      std::cout << "Digite o ID do elemento: ";
      std::cin >> id;
      Node* encontrado = buscarElemento(tabela, id);
      if (encontrado != nullptr) {  ///< Houve match e elemento foi encontrado
        std::cout << "ID: " << encontrado->elemento.id << '\n';
        std::cout << "Nome: " << encontrado->elemento.nome << '\n';
        std::cout << "Categoria: " << encontrado->elemento.categoria << '\n';
        std::cout << "Valor: " << encontrado->elemento.valor << '\n';
      } else {  ///< Elemento daquele ID não foi encontrado
        std::cout << "Elemento não encontrado.\n";
      }
      break;
    }

    case 3: {  ///< Usuário deseja remover elemento de determinado ID
      int id;
      std::cout << "Digite o ID do elemento a remover: ";
      std::cin >> id;
      if (removerElemento(tabela, id)) {  ///< Função booleana
        std::cout << "Elemento removido com sucesso!\n";
      } else {
        std::cout << "Elemento não encontrado.\n";
      }
      break;
    }

    case 4: {  ///< Usuário deseja editar elemento (exceto ID)
      int id;
      std::string novoNome, novaCategoria;
      float novoValor;
      std::cout << "Digite o ID do elemento a ser editado: ";
      std::cin >> id;
      std::cin.ignore();
      std::cout << "Digite o novo nome: ";
      std::getline(std::cin, novoNome);
      std::cout << "Digite a nova categoria: ";
      std::getline(std::cin, novaCategoria);
      std::cout << "Digite o novo valor: ";
      std::cin >> novoValor;

      if (editarElemento(tabela, id, novoNome, novaCategoria, novoValor)) {  ///< Função booleana
        std::cout << "Elemento editado com sucesso.\n";
      } else {
        std::cout << "Elemento não encontrado!\n";
      }
      break;
    }

    case 5: {  ///< Usuário quer ver a lista dos elementos do catálogo
      listarElementos(tabela);
      break;
    }

    case 6: {  ///< Usuário quer ver as colisões de hash
      std::cout << "Total de colisões: " << totalColisoes << '\n';
      break;
    }

    case 0: {  ///< Encerrar o programa
      std::cout << "Programa encerrado.\n";
      break;
    }

    default:
      std::cout << "Opção inválida, por favor escolher número de 0 a 6 conforme menu.\n";
    }
  } while (opcaoEscolhida != 0);

  liberarTabela(tabela);
  return 0;
}
