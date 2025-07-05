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

#endif  // Hash.hpp
