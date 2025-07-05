#include "hash.hpp"
#include <iostream>

//!< Controle automático da ID
static int proximoID = 1;

//!< Inicializar o contador de colisões
int totalColisoes = 0;

/// Nossa função hash é o resto da divisão pelo tamanho da tabela
int hash(int id) { return id % TAM_TABELA; }

/// Inicializar a tabela com ponteiros nulos
void inicializarTabela(Node** tabela) {
  for (int i = 0; i < TAM_TABELA; ++i) {
    tabela[i] = nullptr;
  }
}

/// Inserir um novo elemento com encadeamento externo
void inserirElemento(Node** tabela,
                     const std::string& nome,
                     const std::string& categoria,
                     float valor) {
  Elemento novo;          ///< Novo elemento a ser inserido
  novo.id = ++proximoID;  ///< IDs sequenciais
  novo.nome = nome;
  novo.categoria = categoria;
  novo.valor = valor;

  int indice = hash(novo.id);  ///< Função hash é calculada a partir do novo id inserido

  /// Verificar se há colisao para incrementar o contador
  if (tabela[indice] != nullptr) {
    totalColisoes++;
  }

  /// Criação de novo nó
  Node* novoNo = new Node;
  novoNo->elemento = novo;
  novoNo->next = tabela[indice];  ///< Encadeamento externo
  tabela[indice] = novoNo;

  /// Confirmar para usuário
  std::cout << "Elemento inserido com sucesso! ID gerado: " << novo.id << '\n';
}

/// Buscar um elemento pelo ID
Node* buscarElemento(Node** tabela, int id) {
  int indice = hash(id);
  Node* atual = tabela[indice];

  while (atual != nullptr) {  ///< Percorrendo a tabela
    if (atual->elemento.id == id)
      return atual;  ///< Elemento encontrado
    atual = atual->next;
  }

  return nullptr;  ///< O elemento daquele ID não foi encontrado
}

/// Remover um elemento pelo ID
bool removerElemento(Node** tabela, int id) {
  int indice = hash(id);
  Node* atual = tabela[indice];  ///< Aponta para o primeiro nó naquele índice
  Node* anterior = nullptr;

  while (atual != nullptr) {  ///< Enquanto houver nós para verificar naquele índice
    if (atual->elemento.id == id) {
      if (anterior == nullptr) {  ///< o nó a ser removido é o primeiro da lista
        tabela[indice] = atual->next;
      } else {
        anterior->next = atual->next;  ///< Pula o nó atual
      }
      delete atual;
      std::cout << "Elemento deletado!\n";
      return true;
    }
    anterior = atual;  ///< Move os ponteiros para seguir buscando naquele índice
    atual = atual->next;
  }
  std::cout << "ERRO: ID não encontrado\n";
  return false;
}

/// Editar os dados de um elemento
bool editarElemento(Node** tabela,
                    int id,
                    const std::string& novoNome,
                    const std::string& novaCategoria,
                    float novoValor) {
  Node* node = buscarElemento(tabela, id);
  if (node != nullptr) {  //!< Nó existe, então atualizamos as informações
    node->elemento.nome = novoNome;
    node->elemento.categoria = novaCategoria;
    node->elemento.valor = novoValor;
    std::cout << "Informações atualizadas com sucesso.\n";
    return true;
  }
  std::cout << "Elemento não encontrado\n";
  return false;  ///< Nó não encontrado
}

/// Listar os elementos
void listarElementos(Node** tabela) {
  for (int i = 0; i < TAM_TABELA; ++i) {
    Node* atual = tabela[i];  ///< Para percorrer cada índice
    if (atual != nullptr) {
      std::cout << "Índice " << i << ":\n";
      while (atual != nullptr) {  ///< Para percorrer cada nó naquele índice
        std::cout << " ID: " << atual->elemento.id << ", Nome: " << atual->elemento.nome
                  << ", Categoria: " << atual->elemento.categoria
                  << ", Valor: " << atual->elemento.valor << '\n';
        atual = atual->next;  ///< Segue naquele índice
      }
    }
  }
}

/// Liberar a memória
void liberarTabela(Node** tabela) {
  for (int i = 0; i < TAM_TABELA; ++i) {
    Node* atual = tabela[i];
    while (atual != nullptr) {
      Node* temp = atual;   ///< Variável auxiliar
      atual = atual->next;  ///< Passa pro próximo daquele encadeamento
      delete temp;
    }
    tabela[i] = nullptr;
  }
}
