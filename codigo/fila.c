#include <stdio.h>
#include "fila.h"


void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
    f->totalEmitidas = 0;
}


int exibirMenu() {
    int opcao;
    printf("\n=========================================\n");
    printf("   TIA KARLA SOLUÇÕES - PAINEL DE SENHAS\n");
    printf("=========================================\n");
    printf("1 - Emitir senha Normal\n");
    printf("2 - Emitir senha Preferencial\n");
    printf("3 - Emitir senha Urgente\n");
    printf("4 - Chamar próxima senha\n");
    printf("5 - Consultar filas\n");
    printf("6 - Mostrar quantidade de pessoas\n");
    printf("0 - Sair\n");
    printf("-----------------------------------------\n");
    printf("Escolha uma opção: ");
    
  
    if (scanf("%d", &opcao) != 1) {
        while (getchar() != '\n'); 
        return -1;
    }
    return opcao;
}


void emitirSenha(Fila *f, char prefixo, const char *nomeFila) {
    if (f->fim >= MAX) {
        printf("\n[AVISO] A fila %s atingiu o limite máximo de %d senhas!\n", nomeFila, MAX);
        return;
    }

    f->totalEmitidas++;
    f->senhas[f->fim] = f->totalEmitidas;
    f->fim++;

    printf("\n>> Senha emitida (%s): %c-%03d\n", nomeFila, prefixo, f->totalEmitidas);
}

void chamarProximaSenha(Fila *urgente, Fila *preferencial, Fila *normal) {
    printf("\n-----------------------------------------\n");
    if (urgente->inicio < urgente->fim) {
        printf("CHAMANDO SENHA URGENTE: U-%03d\n", urgente->senhas[urgente->inicio]);
        urgente->inicio++;
    } 
    else if (preferencial->inicio < preferencial->fim) {
        printf("CHAMANDO SENHA PREFERENCIAL: P-%03d\n", preferencial->senhas[preferencial->inicio]);
        preferencial->inicio++;
    } 
    else if (normal->inicio < normal->fim) {
        printf("CHAMANDO SENHA NORMAL: N-%03d\n", normal->senhas[normal->inicio]);
        normal->inicio++;
    } 
    else {
        printf("Nenhuma senha aguardando atendimento no momento.\n");
    }
    printf("-----------------------------------------\n");
}

void imprimirFilaIndividual(Fila f, char prefixo, const char *nomeFila) {
    printf("%-13s: ", nomeFila);
    if (f.inicio == f.fim) {
        printf("Vazia");
    } else {
        for (int i = f.inicio; i < f.fim; i++) {
            printf("[%c-%03d] ", prefixo, f.senhas[i]);
        }
    }
    printf("\n");
}

void consultarFilas(Fila urgente, Fila preferencial, Fila normal) {
    printf("\n=== FILAS DE ESPERA ATUAIS ===\n");
    imprimirFilaIndividual(urgente, 'U', "Urgente");
    imprimirFilaIndividual(preferencial, 'P', "Preferencial");
    imprimirFilaIndividual(normal, 'N', "Normal");
}

void mostrarQuantidade(Fila urgente, Fila preferencial, Fila normal) {
    int qtdUrgente = urgente.fim - urgente.inicio;
    int qtdPreferencial = preferencial.fim - preferencial.inicio;
    int qtdNormal = normal.fim - normal.inicio;
    int total = qtdUrgente + qtdPreferencial + qtdNormal;

    printf("\n=== QUANTIDADE DE PESSOAS AGUARDANDO ===\n");
    printf("Urgente      : %d\n", qtdUrgente);
    printf("Preferencial : %d\n", qtdPreferencial);
    printf("Normal       : %d\n", qtdNormal);
    printf("-----------------------------------------\n");
    printf("Total geral  : %d pessoa(s)\n", total);
}
