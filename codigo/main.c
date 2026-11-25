#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "fila.h"

int main() {
    setlocale(LC_ALL, "Portuguese");

    Fila filaNormal, filaPreferencial, filaUrgente;
    int opcao;


    inicializarFila(&filaNormal);
    inicializarFila(&filaPreferencial);
    inicializarFila(&filaUrgente);

    do {
        opcao = exibirMenu();

        switch (opcao) {
            case 1:
                emitirSenha(&filaNormal, 'N', "Normal");
                break;
            case 2:
                emitirSenha(&filaPreferencial, 'P', "Preferencial");
                break;
            case 3:
                emitirSenha(&filaUrgente, 'U', "Urgente");
                break;
            case 4:
                chamarProximaSenha(&filaUrgente, &filaPreferencial, &filaNormal);
                break;
            case 5:
                consultarFilas(filaUrgente, filaPreferencial, filaNormal);
                break;
            case 6:
                mostrarQuantidade(filaUrgente, filaPreferencial, filaNormal);
                break;
            case 0:
                printf("\nEncerrando o sistema da Tia Karla Soluções...\n");
                break;
            default:
                printf("\n[ERRO] Opção inválida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
