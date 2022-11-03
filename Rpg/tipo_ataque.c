#ifndef tipo_ataqueHEADER_H
#define tipo_ataqueHEADER_H
#include <stdio.h>
#include "inimigos.c"
#include <time.h>
//------------------------------------------------------------------------------
int calcular_dano(persona* atacante, int forca, int dextreza){
	int dano = atacante->melee->dano;
    float str =   atacante->melee->str*forca;
    float dex =   atacante->melee->dex*dextreza;
    int dano_final = (dano+((dano/2)*(str/100))*((dano/2)*(dex/100)));
    return dano_final;
}
//------------------------------------------------------------------------------
int ataque(persona atacante, persona* vitima){
    if(vitima->vida!=0){
        int dano=calcular_dano(&atacante, atacante.atributo.forca, atacante.atributo.dextreza);
        int critico=rand()%100;
        if(critico<=atacante.melee->chance_critico){
            printf("%d ",critico);
            dano+=dano;
        }
        tipo_ataque(atacante, vitima);
        vitima->vida-=dano;
        printf("%d\n",dano);
        if(vitima->vida==0){
            printf("o %s está morto", vitima->nome);
        }
        return 0;
    }
}
//------------------------------------------------------------------------------
int tipo_ataque(persona atacante, persona* vitima){
	srand(time(NULL));
    int dano;
    int escolha;
    switch(atacante.melee->tipo){
        case 1:
            //Blunt
            escolha=rand()%8;
            if(escolha==0){
                printf("%s deu uma %s em %s\n",atacante.nome, atacante.melee->ataque,vitima->nome);
            }else if(escolha==1){
                printf("%s acerta a cabeça de %s com tanta força, que a cabeça de %s ficou parecendo a letra U\n",atacante.nome,vitima->nome,vitima->nome);
            }else if(escolha==2){
                printf("%s estragou o velorio de %s\n",atacante.nome,vitima->nome);
            }else if(escolha==3){
                printf("%s transformou %s, em top view\n",atacante.nome,vitima->nome);
            }else if(escolha==4){
                printf("%s tirou a meia de %s, com a força da %s\n",atacante.nome,vitima->nome, atacante.melee->ataque);
            }else if(escolha==5){
                printf("%s fez %s levitar com a porrada\n",atacante.nome,vitima->nome);
            }else if(escolha==6){
                printf("%s brincou de pinhata com %s\n",atacante.nome,vitima->nome);
            }else if(escolha==7){
                printf("%s rachou o coco de %s\n",atacante.nome,vitima->nome);
            }
        break;
        case 2:
            //Slash
            escolha=rand()%5;
            if(escolha==0){
                printf("%s deu uma %s em %s\n",atacante.nome, atacante.melee->ataque,vitima->nome);
            }else if(escolha==1){
                printf("%s fatiou %s com tanta precisão, que %s virou 2d\n",atacante.nome,vitima->nome,vitima->nome);
            }else if(escolha==2){
                printf("%s Apunhalou %s na maldade\n",atacante.nome, vitima->nome);
            }else if(escolha==3){
                printf("%s coloca lentamente a lamina de volta a bainha, %s virou picadinho\n",atacante.nome, vitima->nome);
            }else if(escolha==4){
                printf("%s fez %s de fruit ninja\n",atacante.nome, vitima->nome);
            }
        break;
        case 3:
            //piercing
            escolha=rand()%4;
            if(escolha==0){
                printf("%s deu uma %s em %s\n",atacante.nome, atacante.melee->ataque,vitima->nome);
            }else if(escolha==1){
                printf("%s deixou um oco inesquecivel em %s\n",atacante.nome,vitima->nome);
            }else if(escolha==2){
                printf("%s furou tão fundo que %s agora é um poço artesiano\n",atacante.nome, vitima->nome);
            }else if(escolha==3){
                printf("depois que %s atacou, %s virou pula pirata\n",atacante.nome, vitima->nome);
            }
        break;
        //especial
        case 4:
                printf("%s brande a sua espada de madeira e golpeia %s\n",atacante.nome, vitima->nome);
        break;
    }
}
#endif
