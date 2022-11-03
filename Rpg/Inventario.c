#ifndef inventarioHEADER_H
#define inventarioHEADER_H
#include <stdio.h>
#include <time.h>
#include "armas.c"
#include "itens.c"
#include "inimigos.c"
#include "loja.c"
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
int inventory(conjunto* inventario, persona* jogador, arma* desarmado, item* vazio, int dinheiro){
    clrscr();
    int alternador = 0, escolha_alt = 0, equipar =0;
    printf("\n1:Armas \n2:Itens \nVoltar\n");
    printf("\nEscolha uma das opçoes: ");
    scanf("%d",&alternador);
    switch(alternador){
        case 1:
            //Armas
            do{
                clrscr();
                mostrar_armas(inventario);
                printf("\nEscolha um slot: ");
                scanf("%d", &equipar);
                if(equipar==0){
                    clrscr();
                    printf("Escolha invalida");
                }else if(!(inventario->estoque_armas[equipar-1] == NULL)){
                    printf("\n----------------------------------------------");
                    printf("\nUso:%-10.20s\t|\tSelecionado:%-10.20s", jogador->melee->nome, inventario->estoque_armas[equipar-1]->nome);
                    printf("\nDano: %d\t|\tDano: %d", jogador->melee->dano, inventario->estoque_armas[equipar-1]->dano);
                    printf("\nCritico: %d\t|\tCritico: %d", jogador->melee->chance_critico, inventario->estoque_armas[equipar-1]->chance_critico);
                    printf("\n----------------------------------------------\n");
                    printf("\ntecle 1 para confirmar equipar");
                    printf("\ntecle 2 para confirmar vender\n");
                    scanf("%d",&escolha_alt);
                    switch(escolha_alt){
                        case 1:
                            clrscr();
                            printf("Equipado.\n");
                            if(jogador->melee==desarmado){
                                jogador->melee=inventario->estoque_armas[equipar-1];
                                inventario->estoque_armas[equipar-1]=NULL;
                            }else{
                                arma* address;
                                address=jogador->melee;
                                jogador->melee=inventario->estoque_armas[equipar-1];
                                inventario->estoque_armas[equipar-1]=address;
                            }
                        break;
                        case 2:
                            dinheiro+=(inventario->estoque_armas[equipar-1]->custo/2);
                            inventario->estoque_armas[equipar-1]=NULL;
                        break;
                        default:
                            clrscr();
                            printf("Cancelado\n\n");
                        break;
                    }
                }else{
                    clrscr();
                    printf("Não há nenhum item nesse slot.");
                }
                reposicionar_armas(inventario->estoque_armas);
            }while(equipar!=0 && escolha_alt!=1);
        break;
        case 2:
            //Itens
            clrscr();
            do{
                mostrar_itens(inventario);
                printf("\nEscolha um slot: ");
                scanf("%d", &equipar);
                if(equipar==0){
                    clrscr();
                    printf("Escolha invalida");
                }else if (equipar==11){
                    printf("deseja reencher o cantil? ");
                    scanf("%d",&escolha_alt);
                    switch(escolha_alt){
                        case 1:
                            if(jogador->cantil==vazio){
                                clrscr();
                                printf("\nvoce nao possui cantil\n");
                            }else{
                                int quantidade;
                                quantidade = jogador->cantil->capacidade - jogador->cantil->quantidade;
                                int custo;
                                custo = quantidade / 4;
                                if(dinheiro<custo){
                                	clrscr();
                                    printf("voce nao tem dinheiro");
                                }else{
                                    jogador->cantil->quantidade=jogador->cantil->capacidade;
                                    dinheiro-=custo;
                                    clrscr();
                                    printf("Operação efetuada\n");
                                }
                            }
                        break;
                        default:
                            clrscr();
                            printf("Cancelado\n");
                        break;
                    }
                }else if(!(inventario->estoque_itens[equipar-1] == NULL)){
                    if(inventario->estoque_itens[equipar-1]->tipo==1){
                        //cantil
                        printf("\n----------------------------------------------");
                        printf("\nUso: %d\t|\tSelecionado: %d", jogador->cantil->capacidade, inventario->estoque_itens[equipar-1]->capacidade);
                        printf("\n----------------------------------------------\n");
                        printf("\ntecle 1 para confirmar troca");
                        printf("\ntecle 2 para confirmar venda\n");
                        scanf("%d",&escolha_alt);
                        switch(escolha_alt){
                            case 1:
                                clrscr();
                                printf("Equipado.\n");
                                if(jogador->cantil==vazio){
                                    jogador->cantil=inventario->estoque_itens[equipar-1];
                                    inventario->estoque_itens[equipar-1]=NULL;
                                }else{
                                    item* address;
                                    address=jogador->cantil;
                                    jogador->cantil=inventario->estoque_itens[equipar-1];
                                    inventario->estoque_itens[equipar-1]=address;
                                }
                            break;
                            case 2:
                            	clrscr();
                                dinheiro+=(inventario->estoque_itens[equipar-1]->custo/2);
                                inventario->estoque_itens[equipar-1]=NULL;
                            break;
                            default:
                                clrscr();
                                printf("Cancelado\n\n");
                            break;
                        }
                    }else if(inventario->estoque_itens[equipar-1]->tipo==2){
                        //energia
                        if(jogador->energia<100){
                            jogador->energia += inventario->estoque_itens[equipar-1]->quantidade;
                        }else{
                            clrscr();
                            printf("Energia completa\n");
                        }
                    }
                    //-- adicionar novos tipos
                }else{
                    clrscr();
                    printf("Não há nenhum item nesse slot.\n");
                }
                reposicionar_itens(inventario->estoque_itens);
            }while(equipar!=0 && escolha_alt!=1);
        break;
        default:
            clrscr();
            printf("\n\nOperação Cancelada\n\n");
        break;
    }
    return dinheiro;
}
#endif
