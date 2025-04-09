#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contato.h"

int CarregarCntt(Contato contatos[], const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (!arquivo) return 0;

    int total = 0;
    char linha[150];
    char *token;

    while (fgets(linha, sizeof(linha), arquivo) && total < MAX_contato){
        token = strtok(linha, ",");
        if (token) strncpy(contatos[total].nome, token, 128);

        token = strtok(NULL, "\n");
        if (token) strncpy(contatos[total].telefone, token, 15);

        total++;
    }

    fclose(arquivo);
    return total;
}

void CadastrarCntt(Contato contatos[], int *totalContt){
    if (*totalContt >= MAX_contato) {
        printf("Agenda cheia. Não é possível cadastrar contato!\n");
        return;
    }

    printf("Nome para cadastro: ");
    scanf(" %128[^\n]", contatos[*totalContt].nome);
    printf("Telefone (ex: 63 99999-9999): ");
    scanf(" %15[^\n]", contatos[*totalContt].telefone);
    printf("Contato adicionado com sucesso!\n");
    (*totalContt)++;
}

void BuscarCntt(Contato contatos[], int totalContt){
    char nomeBusca[128];
    int encontrado = 0;

    printf("Nome do contato que deseja buscar: ");
    scanf(" %128[^\n]", nomeBusca);

    for (int i = 0; i < totalContt; i++) {
        if (strcmp(contatos[i].nome, nomeBusca) == 0) {
            printf("Contato encontrado: %s - %s\n", contatos[i].nome, contatos[i].telefone);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Contato não encontrado.\n");
    }
}

void ImprimirCntt(Contato contatos[], int totalCntt){
    printf("=-=-=-=-=-=-=-=-=-= Lista de Contatos =-=-=-=-=-=-=-=-==\n");
    if (totalCntt == 0) {
        printf("Nenhum contato cadastrado.\n");
    }else{
        for (int i = 0; i < totalCntt; i++) {
            printf("%d - Nome: %s | Telefone: %s\n", i + 1, contatos[i].nome, contatos[i].telefone);
        }
    }
}

int DeletarCntt(Contato contatos[], int totalCntt){
    int numero;
    ImprimirCntt(contatos, totalCntt);

    printf("Digite o número do contato a ser deletado: ");
    scanf("%d", &numero);

    if (numero < 1 || numero > totalCntt) {
        printf("Índice inválido.\n");
        return totalCntt;
    }

    for (int i = numero - 1; i < totalCntt - 1; i++) {
        contatos[i] = contatos[i + 1];
    }

    printf("Contato deletado com sucesso.\n");
    return totalCntt - 1;
}

void SalvarCntt(Contato contatos[], int totalCntt, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo para salvar.\n");
        return;
    }

    for (int i = 0; i < totalCntt; i++) {
        fprintf(arquivo, "%s,%s\n", contatos[i].nome, contatos[i].telefone);
    }

    fclose(arquivo);
    printf("Contatos salvos em '%s'.\n", nomeArquivo);
}
