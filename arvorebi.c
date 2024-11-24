#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int conteudo;
    struct no *esquerda, *direita;
}No;

typedef struct{
    No *raiz;
}ArvB;

void inserirEsquerda(No *no, int valor){
    if(no->esquerda == NULL){
        No *novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        no->esquerda = novo;
    }
    else{
        if(valor < no->esquerda->conteudo)
            inserirEsquerda(no->esquerda, valor);
        if(valor > no->esquerda->conteudo)
            inserirDireita(no->esquerda, valor);
    }
}

void inserirDireita(No *no, int valor){
    if(no->direita == NULL){
        No *novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        no->direita = novo;
    }
    else{
        if(valor > no->direita->conteudo)
            inserirDireita(no->direita, valor);
        if(valor < no->direita->conteudo)
            inserirEsquerda(no->direita, valor);
    }
    
}

void inserir(ArvB *arv, int valor){
    if(arv->raiz == NULL){
        No *novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        arv->raiz = novo;
    }
    else{
        if(valor < arv->raiz->conteudo)
            inserirEsquerda(arv->raiz, valor);
        if(valor > arv->raiz->conteudo)
            inserirDireita(arv->raiz, valor);
    }
}

void imprimirEmOrdem(No *raiz){
    if(raiz != NULL){
        imprimirEmOrdem(raiz->esquerda);
        printf("%d ", raiz->conteudo);
        imprimirEmOrdem(raiz->direita);
    }
}

void imprimirPosOrdem(No *raiz){
    if(raiz != NULL){
        imprimirPosOrdem(raiz->esquerda);
        imprimirPosOrdem(raiz->direita);
        printf("%d ", raiz->conteudo);
        
    }
}

void imprimirPreOrdem(No *raiz){
    if(raiz != NULL){
        printf("%d ", raiz->conteudo);
        imprimirPreOrdem(raiz->esquerda);
        imprimirPreOrdem(raiz->direita);
    }
}

No* remover(No *raiz, int chave){
    if(raiz == NULL){
        printf("Valor nao encontrado!\n");
        return NULL;
    }
    else{
        if(raiz->conteudo == chave){
            // remove nós sem filhos
            if(raiz->esquerda == NULL && raiz->direita == NULL){
                free(raiz);
                return NULL;
            }
            else{
                // remove nós com um filho (esquerda ou direita)
                if(raiz->esquerda == NULL || raiz->direita == NULL){
                    No *aux;
                    if(raiz->esquerda != NULL )
                        aux = raiz->esquerda;
                    else
                        aux = raiz->direita;
                    free (raiz);
                    return aux;
                }
                else{
                    // remove nós com dois filhos
                    No *aux = raiz->esquerda;
                    while(aux->direita != NULL)
                        aux = aux->direita;
                    raiz->conteudo = aux->conteudo;
                    aux->conteudo = chave;
                    raiz->esquerda = remover(raiz->esquerda, chave);
                    return raiz;
                }
            }
        }
        else{
            if(chave < raiz->conteudo)
                raiz->esquerda = remover(raiz->esquerda, chave);
            else
                raiz->direita = remover(raiz->direita, chave);
            return raiz;
        }
    }
}

int main() {
    int op, valor;
    ArvB arv;
    arv.raiz = NULL;
    
    do{
        printf("\n0 - Sair\n1 - Incluir No\n2 - Remover No\n3 - Buscar Pos Ordem\n4 - Buscar Pre Ordem\n5 - Buscar Em Ordem\n");
        scanf("%d", &op);
        
        switch(op){
            case 0:
                printf("\nSaindo...\n");
                break;
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                inserir(&arv, valor);
                break;
            case 2:
                printf("Digite um valor a ser removido: ");
                scanf("%d", &valor);
                arv.raiz = remover(arv.raiz, valor);
                break;
            case 3:
                printf("\nImpressao da arvore binaria:\n");
                imprimirPosOrdem(arv.raiz);
                break;
            case 4:
                printf("\nImpressao da arvore binaria:\n");
                imprimirPreOrdem(arv.raiz);
                break;
            case 5:
                printf("\nImpressao da arvore binaria:\n");
                imprimirEmOrdem(arv.raiz);
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    }while(op != 0);
}