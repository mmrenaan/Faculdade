#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no {
	int valor;
	struct no *proximo;
} No;

// inserir no inicio
void inserir_no_inicio(No **lista, int num) {
	No *novo = malloc(sizeof(No));

	if (novo) {
		novo->valor= num;
		novo->proximo= *lista;
		*lista= novo;
	}
	else
		printf("Erro ao alocar memoria!\n");
}

// inserir no fim
void inserir_no_fim(No **lista, int num) {
	No *aux, *novo = malloc(sizeof(No));

	if (novo) {
		novo->valor=num;
		novo->proximo=NULL;

		// e o primeiro?
		if(*lista==NULL) {
			*lista=novo;
		} else
			aux= *lista;
		while(aux->proximo)
			aux= aux->proximo;
		aux->proximo = novo;
	}
	else
		printf("Erro ao alocar memoria!\n");
}

// inserir no meio
void inserir_no_meio(No **lista, int num, int ant) {
	No *aux, *novo = malloc(sizeof(No));

	if(novo) {
		novo->valor = num;
		// e o primeiro?
		if(*lista==NULL) {
			novo->proximo = NULL;
			*lista=novo;
		}
		else {
			aux= *lista;
			while(aux->valor !=ant && aux->proximo)
				aux=aux->proximo;
			novo->proximo = aux->proximo;
			aux->proximo=novo;
		}
	}
	else
		printf("Erro ao alocar memoria!\n");
}

No *remover(No **lista, int num){
    No *aux, *remover = NULL;
    
    if(*lista){
        if((*lista)->valor==num){
            remover= *lista;
            *lista= remover->proximo;
        }
        else{
            aux= *lista;
            while(aux->proximo && aux->proximo->valor !=num)
                aux= aux->proximo;
            if(aux->proximo){
                remover= aux->proximo;
                aux->proximo= remover->proximo;
            }
        }
    }
    return remover;
}

No* buscar(No **lista, int num){
    No *aux, *no=NULL;
    
    aux= *lista;
    while(aux && aux->valor !=num)
        aux= aux->proximo;
    if(aux)
        no= aux;
    return no;
}

void imprimir(No *no) {
	printf("\n\tLista: ");
	while(no) {
		printf("%d ", no->valor);
		no=no->proximo;
	}
	printf("\n\n");
}

int main() {

	int opcao, valor, anterior;
	No *removido, *lista=NULL;

	do{
		printf("\n\t0 - Sair\n\t1 - Inserir no Inicio\n\t2 - Inserir no Fim\n\t3 - Inerir no Meio\n\t4 - Remover\n\t5 - Imprimir\n\t6 - Buscar");
		scanf("%d", &opcao);

		switch(opcao) {
		case 1:
			printf("Digite um valor: ");
			scanf("%d", &valor);
			inserir_no_inicio(&lista, valor);
			break;
		case 2:
			printf("Digite um valor: ");
			scanf("%d", &valor);
			inserir_no_fim(&lista, valor);
			break;
		case 3:
			printf("Digite um valor e um valor de referencia: ");
			scanf("%d%d", &valor, &anterior);
			inserir_no_meio(&lista, valor, anterior);
			break;
		case 4:
		    printf("Digite um valor a ser removido: ");
			scanf("%d", &valor);
			removido= remover(&lista, valor);
			if(removido){
			    printf("Elemento a ser removido: %d\n", removido->valor);
			    free(removido);
			}
			else
			    printf("Elemento inexistente!\n");
		    break;
		case 5:
			imprimir(lista);
			break;
		case 6:
		    printf("Digite um valor a ser buscado: ");
			scanf("%d", &valor);
			removido= buscar(&lista, valor);
			if(removido)
			    printf("Elemento encontrado: %d\n", removido->valor);
			else
			    printf("Elemento nao encontrado!\n");
			break;
		default:
			if(opcao!=0)
				printf("Opcao invalida!\n");
		}

	} while(opcao!=0);

	return 0;
}