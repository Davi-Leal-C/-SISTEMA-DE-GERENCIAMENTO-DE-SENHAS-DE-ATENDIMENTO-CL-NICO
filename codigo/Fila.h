#ifndef FILA_H
#define FILA_H

#define MAX 100 // Capacidade máxima de senhas por fila

typedef struct {
    int senhas[MAX];
    int inicio;
    int fim;
    int totalEmitidas;
} Fila;

void inicializarFila(Fila *f);
int exibirMenu();
void emitirSenha(Fila *f, char prefixo, const char *nomeFila);
void chamarProximaSenha(Fila *urgente, Fila *preferencial, Fila *normal);
void consultarFilas(Fila urgente, Fila preferencial, Fila normal);
void imprimirFilaIndividual(Fila f, char prefixo, const char *nomeFila);
void mostrarQuantidade(Fila urgente, Fila preferencial, Fila normal);

#endif
