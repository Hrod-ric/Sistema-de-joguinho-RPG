#ifndef comprasHEADER_H
#define comprasHEADER_H
#include <stdio.h>
#include <time.h>
#include "armas.c"
#include "itens.c"
#include "inimigos.c"
#include "loja.c"

//------------------------------------------------------------------------------
int comprar_armas(int dinheiro, conjunto loja, conjunto* inventario, int slot)
{
    int escolha = 0, escolha_alt = 0;
    int i=0;
    for(i=0;i<10;i++){
        if(!(loja.estoque_armas[i]->nome == NULL)){
            printf ("Possibilidade de compra %d: %s $%d\n", i+1, loja.estoque_armas[i]->nome, loja.estoque_armas[i]->custo);
        }
    }
    printf("escolha um item: ");
    scanf("%d",&escolha);
    if(escolha<1 || escolha>10){
    	clrscr();
        printf("Operação cancelada");
    }else{
		if(loja.estoque_armas[escolha-1]==NULL){
    		clrscr();
    		printf("Escolha invalida.\n\n");
		}else{
	        printf("\n\n%s selecionado", loja.estoque_armas[escolha-1]->nome);
	        printf("\nDano: %d | Critico: %d", loja.estoque_armas[escolha-1]->dano, loja.estoque_armas[escolha-1]->chance_critico);
	        printf("\ntecle 1 para confirmar\n");
	        scanf("%d",&escolha_alt);
	        switch(escolha_alt){
	            case 1:
	                if(dinheiro>=loja.estoque_armas[escolha-1]->custo){
	                    inventario->estoque_armas[slot]=loja.estoque_armas[escolha-1];
	                    clrscr();
	                    printf("Compra efetuada com sucesso\n");
	                    dinheiro-=loja.estoque_armas[escolha-1]->custo;
	                    printf("-%d dinheiros",loja.estoque_armas[escolha-1]->custo);
	                }else{
	                    clrscr();
	                    printf("Voce nao possui dinheiro o suficiente");
	                }
	            break;
	            default:
	                clrscr();
	                printf("Escolha invalida.\n\n");
	            break;
	        }
	    }
    }
    return dinheiro;
}
int comprar_itens(int dinheiro, conjunto loja, conjunto* inventario, int slot){
    int escolha = 0, escolha_alt = 0;
    int i=0;
    for(i=0;i<10;i++){
        if(!(loja.estoque_itens[i]->nome == NULL)){
            printf ("Possibilidade de compra %d: %s $%d\n", i+1, loja.estoque_itens[i]->nome, loja.estoque_itens[i]->custo);
        }
    }
    printf("escolha um item: ");
    scanf("%d",&escolha);
    if(escolha<1 || escolha>10){
    	clrscr();
        printf("Operação cancelada");
    }else{
		if(loja.estoque_itens[escolha-1]==NULL){
    		clrscr();
    		printf("Escolha invalida.\n\n");
		}else{
	        printf("\n\n%s selecionado", loja.estoque_itens[escolha-1]->nome);
	        //printf("\nDano: %d | Critico: %d", loja.estoque_itens[escolha-1]->dano, loja.estoque_itens[escolha-1]->chance_critico);
	        printf("\ntecle 1 para confirmar\n");
	        scanf("%d",&escolha_alt);
	        switch(escolha_alt){
	            case 1:
	                if(dinheiro>=loja.estoque_itens[escolha-1]->custo){
	                    inventario->estoque_itens[slot]=loja.estoque_itens[escolha-1];
	                    clrscr();
	                    printf("Compra efetuada com sucesso\n");
	                    dinheiro-=loja.estoque_itens[escolha-1]->custo;
	                    printf("-%d dinheiros",loja.estoque_itens[escolha-1]->custo);
	                }else{
	                    clrscr();
	                    printf("Voce nao possui dinheiro o suficiente");
	                }
	            break;
	            default:
	                clrscr();
	                printf("Escolha invalida.\n\n");
	            break;
	        }
	    }
    }
    return dinheiro;
}
#endif
