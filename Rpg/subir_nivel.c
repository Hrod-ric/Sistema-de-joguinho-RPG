#ifndef subir_nivelHEADER_H
#define subir_nivelHEADER_H
#include <stdio.h>
#include <stdlib.h>
#include "mostrar.c"
#include "inimigos.c"
#include "jogador.c"
//------------------------------------------------------------------------------
int subir_nivel(persona* jogador){
    int escolha, escolha_alt, escolha_aux, custo = 0;
    int forca=jogador->atributo.forca;
    int dextreza=jogador->atributo.dextreza;
    int constituicao=jogador->atributo.constituicao;
    int custo_real=0;
    do{
        int nivel = forca + dextreza + constituicao - 29;
        custo=nivel*2;
        printf("\nnivel: %d\nwings: %d\ncusto: %d\tTotal:%d", nivel, jogador->wings, custo, custo_real);
        printf("\n------------------\n");
        printf("Força:\t\t%d\nDextreza:\t%d\nConstituição:\t%d", forca, dextreza, constituicao);
        printf("\n------------------\n");
        int dano1=calcular_dano(jogador,jogador->atributo.forca,jogador->atributo.dextreza);
        int dano2=calcular_dano(jogador,forca,dextreza);
        //int dano2=tipo_ataque(jogador->melee->tipo,jogador->melee->dano,forca,dextreza);
        printf("\nVida Atual: %d\tVida Após: %d", jogador->vida, constituicao*25);
        printf("\nDano Atual: %d\tDano Após: %d", dano1, dano2);
        printf("\nEscolha um atributo: ");
        scanf("%d",&escolha);
        switch(escolha){
            case 1:
                clrscr();
                forca++;
                custo_real+=custo;
            break;
            case 2:
                clrscr();
                dextreza++;
                custo_real+=custo;
            break;
            case 3:
                clrscr();
                constituicao++;
                custo_real+=custo;
            break;
            case 4:
                clrscr();
                printf("Reset");
                custo_real=0;
                forca=jogador->atributo.forca;
                dextreza=jogador->atributo.dextreza;
                constituicao=jogador->atributo.constituicao;
            break;
            case 5:
                printf("tecle 1 para confirmar a compra");
                scanf("%d",&escolha_alt);
                switch(escolha_alt){
                    case 1:
                        clrscr();
                        if(jogador->wings<custo_real){
                            printf("voce nao tem wingslompsor");
                        }else{
                            jogador->wings-=custo_real;
                            jogador->atributo.forca=forca;
                            jogador->atributo.dextreza=dextreza;
                            jogador->atributo.constituicao=constituicao;
                        }
                    break;
                    default:
                        clrscr();
                    break;
                }
            break;
            default:
                clrscr();
                printf("Arrivederci");
            break;
        }
    }while(escolha>0 && escolha<5);
    return 0;
}
#endif
