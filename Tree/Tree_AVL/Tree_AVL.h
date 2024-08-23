#ifndef ARV_H_INCLUDED
#define ARV_H_INCLUDED

// Definição da estrutura da árvore
typedef struct no* Tarvore;

// Função para criar um nó
void criar(Tarvore *T);

// Função para verificar se o nó está vazio
int vazia (Tarvore *T);

// Função para calcular a altura e o fator de balanceamento de um nó
void alt_fb(Tarvore *p);

// Função para recalcular a altura e o fator de balanceamento de todos os nós de uma subárvore com raiz em p
void recalcula_h(Tarvore *p);

// Função para realizar a rotação à esquerda de um nó
void rotacao_esq(Tarvore *p);

// Função para realizar a rotação à direita de um nó
void rotacao_dir(Tarvore *p);

// Função para realizar o rebalanceamento de um nó
void rebalanceamento(Tarvore *p);

// Função para inserir um elemento na árvore
void inserir (int x, Tarvore *p);

// Função para mostrar a árvore
void mostrar(Tarvore p);

// Função para remover um nó folha
void remove_folha(Tarvore *p);

// Função para remover um nó com filho à esquerda
void remove_no_com_filho_esq(Tarvore *p);

// Função para remover um nó com filho à direita
void remove_no_com_filho_dir(Tarvore *p);

// Função para encontrar o sucessor de um nó
Tarvore encontra_sucessor(Tarvore *p);

// Função para remover um elemento da árvore
int remover(int x, Tarvore *p);

// Função para remover um nó com dois filhos
void remove_no_com_2filhos(Tarvore *p);

#endif // ARV_H_INCLUDED