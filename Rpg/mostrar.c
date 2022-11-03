#ifndef mostrarHEADER_H
#define mostrarHEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "loja.c"
void clrscr(){
    system("@cls||clear");
}
//------------------------------------------------------------------------------
int mostrar_itens(conjunto* vetor)
{
    int i=0, contador = 0;
    for (i=0; i<10; i++){
        if(!(vetor->estoque_itens[i]->nome == NULL)){
            contador++;
            printf ("slot %d: %s\n", i+1, vetor->estoque_itens[i]->nome);
        }
    }
    printf("\nEstoque:%d/10", contador);
    return 0;
}
int mostrar_armas(conjunto* vetor)
{
    int i=0, contador = 0;
    for (i=0; i<10; i++){
        if(!(vetor->estoque_armas[i]->nome == NULL)){
            contador++;
            printf ("slot %d: %s\n", i+1, vetor->estoque_armas[i]->nome);
        }
    }
    printf("\nEstoque:%d/10", contador);
    return 0;
}
//------------------------------------------------------------------------------
int checar_itens(item* vetor[])
{
    int slot=-1;
    int i=0;
    for (i=0; i<10; i++){
        if(vetor[i] == NULL){
            slot=i;
            break;
        }
    }
    return slot;
}
int checar_armas(arma* vetor[])
{
    int slot=-1;
    int i=0;
    for (i=0; i<10; i++){
        if(vetor[i] == NULL){
            slot=i;
            break;
        }
    }
    return slot;
}
//------------------------------------------------------------------------------
int reposicionar_itens(item* vetor[])
{
    int a=0, b=0;
    item* address;
    for(a=0;a<10;a++){
        if (vetor[a]==NULL){
            b=a;
            for(b=a;b<10;b++){
                if(!(vetor[b]==NULL)){
                    address = vetor[b];
                    vetor[a]=address;
                    vetor[b]=NULL;
                    a=0;
                    break;
                }
            }
        }
    }
    return 0;
}
int reposicionar_armas(arma* vetor[]){
    int a=0, b=0;
    arma* address;
    for(a=0;a<10;a++){
        if (vetor[a]==NULL){
            b=a;
            for(b=a;b<10;b++){
                if(!(vetor[b]==NULL)){
                    address = vetor[b];
                    vetor[a]=address;
                    vetor[b]=NULL;
                    a=0;
                    break;
                }
            }
        }
    }
    return 0;
}
//------------------------------------------------------------------------------
#endif
