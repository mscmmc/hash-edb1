#ifndef HASH_HPP
#define HASH_HPP

#include <string>

const int TAM_TABELA = 199;  ///< O número primo facilita a criação da função hash

/// Struct para representar um elemento do catálogo
struct Elemento {
  int id;
  std::string nome;
  std::string categoria;
  float valor;
};

/// Nó para encadeamento externo
struct Node {
  Elemento elemento;
  Node* next;
};

/// Função hash
int hash(int id);

/// Inicializar a tabela hash
void inicializarTabela(Node* tabela[]);

/// Inserir um novo elemento, gerando o ID automaticamente
void inserirElemento(Node* tabela[],
                     const std::string& nome,
                     const std::string& categoria,
                     float valor);

/// Buscar um elemento pelo ID
bool removerElemento(Node* tabela[], int id);

/// Editar um elemento da tabela
bool editarElemento(Node* tabela[],
                    int id,
                    const std::string& novoNome,
                    const std::string& novaCategoria,
                    float novoValor);

/// Listar os elementos por ordem de índice
void listarElementos(Node* tabela[]);

/// Liberar a memória
void liberarTabela(Node* tabela[]);

/// Contador de colisões
extern int totalColisoes;

#endif  // Hash.hpp
