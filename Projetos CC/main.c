#include <stdio.h>
#include "contato.h"

int main(){

    Contato contatos[MAX_contato];
    const char *nomeArquivo = "agenda.csv";
    int totalCntt = CarregarCntt(contatos, nomeArquivo);
    int opcao = 0;
    int alterado = 0;

    do{
        printf("\n------------------------------------Menu-----------------------------------\n");
        printf("[1] Cadastrar contato\n");
        printf("[2] Buscar contato\n");
        printf("[3] Deletar um contato\n");
        printf("[4] Salvar em arquivo \n");
        printf("[5] Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf ("----------------------------Cadastrar contato------------------------------\n");
                CadastrarCntt(contatos, &totalCntt);
                alterado = 1;
                break;
            case 2:
                printf ("----------------------------Buscar contato-----------------------------\n");
                BuscarCntt(contatos, totalCntt);
                break;
            case 3:
                printf ("-------------------------------Deletar contato--------------------------------\n");
                totalCntt = DeletarCntt(contatos, totalCntt);
                alterado = 1;
                break;
            case 4:
                printf ("--------------------------Entrega por escritório---------------------------\n");
                SalvarCntt(contatos, totalCntt, nomeArquivo);
                alterado = 0;
                break;
            case 5:
                if (alterado) {
                printf("Salvando alterações antes de sair...\n");
                SalvarCntt(contatos, totalCntt, nomeArquivo);
                }
                printf("Saindo...\n");
            break;
                break;
            default:
                printf("Opção inválida.\n");
        }

    } while (opcao != 5);
    
    return 0;   
} 
