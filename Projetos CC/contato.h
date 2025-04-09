#ifndef CONTATO_H
#define CONTATO_H

#define MAX_contato 50

typedef struct {
    char nome[129];
    char telefone[16];
} Contato;

int CarregarCntt(Contato contatos[], const char *nomeArquivo);
void CadastrarCntt(Contato contatos[], int *totalCntt);
void BuscarCntt(Contato contatos[], int totalCntt);
int DeletarCntt(Contato contatos[], int totalCntt);
void SalvarCntt(Contato contatos[], int totalCntt, const char *nomeArquivo);
void ImprimirCntt(Contato contatos[], int totalCntt);

#endif