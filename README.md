# Autores
Fabio de Melo Peixoto Filho - fdemelopeixotofilho@gmail.com
Marcel Setubal costa - marcelsetubal15@gmail.com

# Contextualização
Este programa é uma implementação em linguagem C++ de um sistema para gerenciamento de um catálogo de elementos, cada um com um inteiro identificador, nome,
categoria e valor numérico. Para isso, utilizamos a estrutura de dados de tabela hash com chave única e encadeamento externo para tratamento de colisões.
A proposta consistia na construção deste catálogo de modo a permitir operações de inserção, busca, remoção, edição e listagem dos elementos presentes.
A estrutura de dados escolhida, a tabela hash, foi implementada a partir da utilização de um vetor de ponteiros para listas encadeadas. Cada posição do vetor
representa uma chave da tabela, e colisões foram tratadas com o uso de listas simplesmente encadeadas, de modo que os nós armazenam os elementos cujas chaves
geram o mesmo índice por meio da função hash. A função hash que escolhemos se baseia no cálculo do resto da divisão pelo tamanho da tabela. Escolhemos o valor
199 para o tamanho da tabela, permitindo um catálogo de tamanho satisfatório e sendo um número primo para otimizar a função hash, melhorando a dispersão dos
dados.

# Descrição das funções implementadas e modularização do código
O arquivo hash.hpp é o arquivo header que contém a definição das estruturas utilizadas (a tabela hash e a struct para cada um dos nós encadeados). 
O arquivo hash.cpp contém a implementação das funções a serem utilizadas no programa, enquanto o main.cpp organiza a interação com o usuário, a exibição 
do menu de opções e utiliza as funções para as finalidades escolhidas.

## Principais funções:
int hash: recebe como argumento o id do elemento, e retorna a chave a partir do cálculo da função hash.
void inicializarTabela: inicializa a tabela hash com ponteiros nulos.
void inserirElemento: insere um novo elemento no catálogo, fazendo uso de encadeamento externo. O índice é calculado a pratir da função hash.
Node* buscarElemento: percorre o catálogo em busca de um elemento de determinado id, passado como argumento da função.
bool removerElemento: remove o nó de um determinado elemento a partir de seu id. Retorna true caso haja sucesso na remoção.
bool editarElemento: edita o nó com os dados de determinado elemento, com exceção do id, que não é alterado. Retorna true caso haja sucesso na edição.
void listarElementos: exibe o catálogo inteiro, com as informações de cada elemento.
void liberarTabela: percorre a tabela hash, deletando os nós e liberando a memória.

# Dificuldades encontradas
As dificuldades encontradas em relação a este projeto foram mais da ordem de dúvidas teóricas sobre a estruturação da tabela hash e a definição de uma 
função hash adequada, bem como na escolha da melhor forma para estruturar o encadeamento externo. A partir das exposições de aula e de nossos 
estudos, essas dúvidas foram sanadas e a implementação do projeto foi relativamente tranquila.

# Como foi organizada a divisão de tarefas entre os membros
Em dupla, chegamos a um consenso sobre a arquitetura inicial do programa, sobre como usar as estruturas e quais as funções que seriam implementadas. A partir
deste consenso, Marcel implementou e testou o código, enquanto Fábio ficou responsável pela escrita do relatório. Ao final, tudo foi revisado em dupla, com a 
finalização do projeto.

# Conclusão 
O projeto foi tranquilo, tendo sido excelente para aplicação prática dos conceitos aprendidos em sala de aula, relacionados ao uso de tabelas hash e listas
encadeadas. Conseguimos implementar com sucesso as funções solicitadas, e também conseguimos implementar o contador de colisões, sugerido pelo professor como
um bônus. Concluímos que essa experiência contribuiu para aprimorar nossos conhecimentos em estruturas de dados, lógica de programação e o funcionamento das
estruturas escolhidas.

# Referências
- Material da disciplina (Slides de aula)
- ZIVIANI, Nivio. Projeto de algoritmos: com implementação em Java e C++. São Paulo: Cengage Learning Thomson, 2007. 621 p. ISBN: 8522105251.
