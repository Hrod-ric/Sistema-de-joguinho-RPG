#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
typedef struct{
    char nome[21];
    int dano;
    int chance_critico;
    int tipo; //1- blunt , 2- slash , 3- piercing, 4- especial
    int custo;
    char ataque[21];
}arma;
typedef struct{
    char nome [20];
    int quantidade; //pontos que vão ser convertidos no tipo
    int capacidade;
    int tipo;   // 1-cura, 2-energia, 3-dano, 4-defesa...
    int custo;
}item;
typedef struct{
    item* estoque_itens[10];
    arma* estoque_armas[10];
}conjunto;
typedef struct{
    char *nome;
    int vida;
    int energia;
    int wingslompsor;
    int nivel;
    struct{
        int forca;
        int dextreza;
        int constituicao;
    }atributo;
    arma *melee;
    arma *reserva;
    item *cantil;
    
}persona; //jogador
//------------------------------------------------------------------------------
void clrscr(){
    system("@cls||clear");
}
//------------------------------------------------------------------------------
int tipo_ataque(int tipo, int base, int forca, int dextreza){
    int dano;
    switch(tipo){
        case 1:
            //Blunt
            dano=(base*forca)/10;
        break;
        case 2:
            //Slash
            dano=(base*(dextreza+forca)/2)/10;
        break;
        case 3:
            //piercing
            dano=(base*dextreza)/10;
        break;
    }
}
//------------------------------------------------------------------------------
int ataque(persona atacante, persona* vitima){
    char ataque[10];
    int critico=rand()%100;
    int dano;
    dano=tipo_ataque(atacante.melee->tipo,atacante.melee->dano,atacante.atributo.forca,atacante.atributo.dextreza);
    if(vitima->vida!=0){
        vitima->vida-=dano;
        printf("%s deu uma %s ", atacante.nome, atacante.melee->ataque);
        if(critico<=atacante.melee->chance_critico){
            printf("fenomenal ");
            dano*=2;
        }
        printf("em %s, que recebe %d de dano\n", vitima->nome, dano);
        if(vitima->vida==0){
            printf("o %s está morto", vitima->nome);
        }
        return 0;
    }
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
//------------------------------------------------------------------------------
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
//------------------------------------------------------------------------------
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
//------------------------------------------------------------------------------
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
    if(escolha!=0 && escolha<11){
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
    }else{
            clrscr();
            printf("Operação cancelada");
    }
    return dinheiro;
}
//------------------------------------------------------------------------------
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
    if(escolha!=0 && escolha<11){
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
    }else{
            clrscr();
            printf("Operação cancelada");
    }
    return dinheiro;
}
//------------------------------------------------------------------------------
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
                reposicionar_armas(inventario->estoque_armas);
            }while(equipar!=0 && escolha_alt!=1);
        break;
        default:
            clrscr();
            printf("\n\nOperação Cancelada\n\n");
        break;
    }
    return dinheiro;
}
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
        printf("\nnivel: %d\nwings: %d\ncusto: %d\tTotal:%d", nivel, jogador->wingslompsor, custo, custo_real);
        printf("\n------------------\n");
        printf("Força:\t\t%d\nDextreza:\t%d\nConstituição:\t%d", forca, dextreza, constituicao);
        printf("\n------------------\n");
        int dano1=tipo_ataque(jogador->melee->tipo,jogador->melee->dano,jogador->atributo.forca,jogador->atributo.dextreza);
        int dano2=tipo_ataque(jogador->melee->tipo,jogador->melee->dano,forca,dextreza);
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
                        if(jogador->wingslompsor<custo_real){
                            printf("voce nao tem wingslompsor");
                        }else{
                            jogador->wingslompsor-=custo_real;
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
//------------------------------------------------------------------------------
conjunto oferta(arma* pacote_armas[], item* pacote_itens[], int onda){
    conjunto loja;
    int escolha;
    if(onda<5){
        //pre boss
        escolha=rand()%3;
        if(escolha==0){
                conjunto loja={ .estoque_armas={pacote_armas[1],pacote_armas[2]},  .estoque_itens={pacote_itens[0],pacote_itens[1]}};
        }else if(escolha==1){
                conjunto loja={ .estoque_armas={pacote_armas[1],pacote_armas[2]},  .estoque_itens={pacote_itens[1],pacote_itens[0]}};
        }else if(escolha==2){
                conjunto loja={ .estoque_armas={pacote_armas[1],pacote_armas[2]},  .estoque_itens={pacote_itens[0],pacote_itens[1]}};
        }else if(escolha==3){
                conjunto loja={ .estoque_armas={pacote_armas[1],pacote_armas[2]},  .estoque_itens={pacote_itens[1],pacote_itens[0]}};
        }
    }else if(onda==5){
        //boss
        escolha=rand()%3;
        if(escolha==0){
                conjunto loja={ .estoque_armas={pacote_armas[1],pacote_armas[2]},  .estoque_itens={pacote_itens[0],pacote_itens[1],pacote_itens[2]}};
        }else if(escolha==1){
                conjunto loja={ .estoque_armas={pacote_armas[1],pacote_armas[2]},  .estoque_itens={pacote_itens[0],pacote_itens[1],pacote_itens[2]}};
        }else if(escolha==2){
                conjunto loja={ .estoque_armas={pacote_armas[1],pacote_armas[2]},  .estoque_itens={pacote_itens[0],pacote_itens[1],pacote_itens[2]}};
        }else if(escolha==3){
                conjunto loja={ .estoque_armas={pacote_armas[1],pacote_armas[2]},  .estoque_itens={pacote_itens[0],pacote_itens[1],pacote_itens[2]}};
        }
    }else if(onda<10){
        //pre boss
        escolha=rand()%3;
        if(escolha==0){
                conjunto loja={ .estoque_armas={pacote_armas[1],pacote_armas[2]},  .estoque_itens={pacote_itens[0],pacote_itens[1],pacote_itens[2]}};
        }else if(escolha==1){
                conjunto loja={ .estoque_armas={pacote_armas[1],pacote_armas[2]},  .estoque_itens={pacote_itens[0],pacote_itens[1],pacote_itens[2]}};
        }else if(escolha==2){
                conjunto loja={ .estoque_armas={pacote_armas[1],pacote_armas[2]},  .estoque_itens={pacote_itens[0],pacote_itens[1],pacote_itens[2]}};
        }else if(escolha==3){
                conjunto loja={ .estoque_armas={pacote_armas[1],pacote_armas[2]},  .estoque_itens={pacote_itens[0],pacote_itens[1],pacote_itens[2]}};
        }
    }else if(onda==10){
        //boss
        escolha=rand()%3;
        if(escolha==0){
                conjunto loja={ .estoque_armas={pacote_armas[1],pacote_armas[2]},  .estoque_itens={pacote_itens[0],pacote_itens[1],pacote_itens[2]}};
        }else if(escolha==1){
                conjunto loja={ .estoque_armas={pacote_armas[1],pacote_armas[2]},  .estoque_itens={pacote_itens[0],pacote_itens[1],pacote_itens[2]}};
        }else if(escolha==2){
                conjunto loja={ .estoque_armas={pacote_armas[1],pacote_armas[2]},  .estoque_itens={pacote_itens[0],pacote_itens[1],pacote_itens[2]}};
        }else if(escolha==3){
                conjunto loja={ .estoque_armas={pacote_armas[1],pacote_armas[2]},  .estoque_itens={pacote_itens[0],pacote_itens[1],pacote_itens[2]}};
        }
    }else if(onda<15){
        //pre boss
        escolha=rand()%3;
        if(escolha==0){
                conjunto loja={ .estoque_armas={pacote_armas[1],pacote_armas[2]},  .estoque_itens={pacote_itens[0],pacote_itens[1],pacote_itens[2]}};
        }else if(escolha==1){
                conjunto loja={ .estoque_armas={pacote_armas[1],pacote_armas[2]},  .estoque_itens={pacote_itens[0],pacote_itens[1],pacote_itens[2]}};
        }else if(escolha==2){
                conjunto loja={ .estoque_armas={pacote_armas[1],pacote_armas[2]},  .estoque_itens={pacote_itens[0],pacote_itens[1],pacote_itens[2]}};
        }else if(escolha==3){
                conjunto loja={ .estoque_armas={pacote_armas[1],pacote_armas[2]},  .estoque_itens={pacote_itens[0],pacote_itens[1],pacote_itens[2]}};
        }
    }else{
        //boss
        escolha=rand()%3;
        if(escolha==0){
                conjunto loja={ .estoque_armas={pacote_armas[1],pacote_armas[2]},  .estoque_itens={pacote_itens[0],pacote_itens[1],pacote_itens[2]}};
        }else if(escolha==1){
                conjunto loja={ .estoque_armas={pacote_armas[1],pacote_armas[2]},  .estoque_itens={pacote_itens[0],pacote_itens[1],pacote_itens[2]}};
        }else if(escolha==2){
                conjunto loja={ .estoque_armas={pacote_armas[1],pacote_armas[2]},  .estoque_itens={pacote_itens[0],pacote_itens[1],pacote_itens[2]}};
        }else if(escolha==3){
                conjunto loja={ .estoque_armas={pacote_armas[1],pacote_armas[2]},  .estoque_itens={pacote_itens[0],pacote_itens[1],pacote_itens[2]}};
        }
    }
    return loja;
}
//------------------------------------------------------------------------------
persona decidir_oponente(arma* pacote_armas[], item* pacote_itens[], int onda, conjunto* recompensa){
    persona oponente;
    if(onda<5){
        //pre boss
        persona oponente={ .nome = "Esqueleto",   .vida = 150, .energia = 100, .melee=pacote_armas[2], .atributo.forca = 10, .atributo.dextreza = 10, .atributo.constituicao = 10 };
        //conjunto recompensa = { .estoque_armas[0]=loot.estoque_armas[0], .estoque_itens[0]=loot.estoque_itens[0]};
        recompensa->estoque_armas[0]=pacote_armas[2];
        recompensa->estoque_itens[0]=pacote_itens[0];
    }else if(onda==5){
        //boss
        persona oponente={  .nome = "Esqueleto Parrudo", .vida = 300, .energia = 100, .melee=pacote_armas[3], .atributo.forca = 10, .atributo.dextreza = 10, .atributo.constituicao = 10 };
        recompensa->estoque_armas[0]=pacote_armas[3];
        recompensa->estoque_itens[0]=pacote_itens[0];
    }else if(onda<10){
        //pre boss
        persona oponente={  .nome = "Esqueleto Ladrão", .vida = 300, .energia = 100, .melee=pacote_armas[4], .atributo.forca = 10, .atributo.dextreza = 10, .atributo.constituicao = 10 };
        recompensa->estoque_armas[0]=pacote_armas[4];
        recompensa->estoque_itens[0]=pacote_itens[0];
    }else if(onda==10){
        //boss
        persona oponente={  .nome = "Esqueleto Barbaro", .vida = 600, .energia = 100, .melee=pacote_armas[5], .atributo.forca = 10, .atributo.dextreza = 10, .atributo.constituicao = 10 };
        recompensa->estoque_armas[0]=pacote_armas[5];
        recompensa->estoque_itens[0]=pacote_itens[0];
    }else if(onda<15){
        //pre boss
        persona oponente={  .nome = "Esqueleto Agil", .vida = 450, .energia = 100, .melee=pacote_armas[11], .atributo.forca = 10, .atributo.dextreza = 10, .atributo.constituicao = 10 };
        recompensa->estoque_armas[0]=pacote_armas[11];
        recompensa->estoque_itens[0]=pacote_itens[0];
    }else{
        //boss
        persona oponente={  .nome = "Minerador", .vida = 900, .energia = 100, .melee=pacote_armas[12], .atributo.forca = 10, .atributo.dextreza = 10, .atributo.constituicao = 10 };
        recompensa->estoque_armas[0]=pacote_armas[12];
        recompensa->estoque_itens[0]=pacote_itens[0];
    }

    return oponente;
}
//------------------------------------------------------------------------------
int main(){
	setlocale(LC_ALL, "portuguese");
    int slot = -1, ciclo, escolha = 0, escolha_alt = 0, escolha_aux = 0, alternador = 0, equipar = 0, onda = 1;
    arma* address;
    //Personagens
    int vida_maxima, energia_maxima, dinheiro = 500, dano1, dano2, quantidade;
    persona jogador={   .nome = "lucas", .vida = 250, .energia = 150, .wingslompsor = 0, .atributo.forca = 10, .atributo.dextreza = 10, .atributo.constituicao = 10 };
    //Armas / tipo:
        //1 - Blunt
        arma pa={           .nome = "Pá",       .dano = 40, .chance_critico = 50,   .tipo = 1,  .custo = 40,    .ataque="pázada" };
        arma porrete={      .nome = "Porrete",  .dano = 70, .chance_critico = 40,   .tipo = 1,  .custo = 60,    .ataque="paulada" };
        arma marreta={      .nome = "Marreta",  .dano = 70, .chance_critico = 60,   .tipo = 1,  .custo = 100,   .ataque="marretada" };
        //2 - Slash
        arma adaga={        .nome = "Adaga",            .dano = 30, .chance_critico = 70,   .tipo = 2, .custo = 40,     .ataque="esfaqueda" };
        arma machado={      .nome = "Machado",          .dano = 65, .chance_critico = 40,   .tipo = 2, .custo = 70,     .ataque="machadada" };
        arma espada_longa={ .nome = "Espada longa",     .dano = 60, .chance_critico = 50,   .tipo = 2, .custo = 80,     .ataque="esfolada" };
        arma cimitarra={    .nome = "Cimitarra",        .dano = 55, .chance_critico = 60,   .tipo = 2, .custo = 100,    .ataque="lapada" };
        arma foice={        .nome = "Foice",            .dano = 50, .chance_critico = 50,   .tipo = 2, .custo = 100,    .ataque="foiçada" };
        arma shotel={       .nome = "Shotel",           .dano = 60, .chance_critico = 60,   .tipo = 2, .custo = 100,    .ataque="shotada" };
        //3 - Piercing
        arma rapier={       .nome = "Rapier",   .dano = 45, .chance_critico = 70,   .tipo = 3, .custo = 70,     .ataque="catucada" };
        arma lanca={        .nome = "Lança",    .dano = 50, .chance_critico = 60,   .tipo = 3, .custo = 100,    .ataque="empalada" };
        arma picareta={     .nome = "Picareta", .dano = 55, .chance_critico = 50,   .tipo = 3, .custo = 150,    .ataque="picaretada" };
        arma alabarda={     .nome = "Alabarda", .dano = 50, .chance_critico = 65,   .tipo = 3, .custo = 150,    .ataque="espetada" };
        //4 - Especial
        arma desarmado={    .nome = "Desarmado",        .dano = 10, .chance_critico = 10,   .tipo = 4, .custo = 0,      .ataque="porradona" };
        arma esp_madeira={  .nome = "Espada de madeira",.dano = 40, .chance_critico = 20,   .tipo = 1, .custo = 0,      .ataque="espadada" };
        arma tocha={        .nome = "Tocha",            .dano = 50, .chance_critico = 50,   .tipo = 4, .custo = 100,    .ataque="queimada" };
        arma tesoura={      .nome = "Tesoura",          .dano = 40, .chance_critico = 100,  .tipo = 4, .custo = 100,    .ataque="circuncidada" };
        arma maquina={      .nome = "Maquina de Barbear",   .dano = 40, .chance_critico = 50,   .tipo = 4, .custo = 100,    .ataque="calvada de cria" };
    //itens / tipo:
        //1 - Cantil
        item vazio={            .nome = "vazio",            .tipo = 1,  .quantidade = 0,    .capacidade = 0,   .custo = 0 };
        item cantil_pequeno={   .nome = "Cantil pequeno",   .tipo = 1,  .quantidade = 125,  .capacidade = 125,  .custo = 50 };
        item cantil_medio={     .nome = "Cantil medio",     .tipo = 1,  .quantidade = 250,  .capacidade = 250,  .custo = 75 };
        item cantil_grande={    .nome = "Cantil grande",    .tipo = 1,  .quantidade = 375,  .capacidade = 375,  .custo = 100 };
        item cantil_maximo={    .nome = "Cantil maximo",    .tipo = 1,  .quantidade = 500,  .capacidade = 500,  .custo = 125 };
        //2 - energia
        item energia={     .nome = "energia pequena", .quantidade = 50,   .tipo = 2, .custo = 100 };
    //Estoque
    conjunto loja;
    arma* pacote_armas[50]= {&desarmado, &pa, &porrete, &marreta, &adaga, &machado, &espada_longa, &cimitarra, &foice, &shotel, &rapier, &lanca, &picareta, &alabarda, &tocha, &tesoura, &maquina};
    item* pacote_itens[50]= {&energia,&cantil_pequeno};
    //conjunto pacote={ .estoque_armas = {&desarmado, &pa, &porrete, &marreta, &adaga, &machado, &espada_longa, &cimitarra, &foice, &shotel, &rapier, &lanca, &picareta, &alabarda, &tocha, &tesoura, &maquina}, .estoque_itens = {&cura_pequena,&1_pequena,&cura_media,&cura_grande}};
    loja=oferta(pacote_armas, pacote_itens, onda);
    conjunto inventario={   .estoque_armas[0] = &esp_madeira, .estoque_itens[0] = &energia };
    conjunto recompensa;
    conjunto mochila;
    jogador.melee=&desarmado;
    jogador.reserva=&desarmado;
    jogador.cantil=&vazio;
    //programa
    //printf("Qual o nome? ");
    //scanf("%s",jogador.nome);
    do{
        dano1=tipo_ataque(jogador.melee->tipo,jogador.melee->dano,jogador.atributo.forca,jogador.atributo.dextreza);
        dano2=tipo_ataque(jogador.reserva->tipo,jogador.reserva->dano,jogador.atributo.forca,jogador.atributo.dextreza);
        vida_maxima=jogador.atributo.constituicao*25;
        energia_maxima=jogador.atributo.constituicao*15;
        jogador.nivel = jogador.atributo.forca + jogador.atributo.dextreza + jogador.atributo.constituicao - 29;
        printf("\n---------------------------------------------------------------------");
        printf("\nNome: %s", jogador.nome);
        printf("\nVida: %-10d\t\t\tEnergia: %-3d\tDinheiro: %d", jogador.vida, jogador.energia, dinheiro);
        if(jogador.cantil==&vazio){
            printf("\nCantil:\t\tNão possui");
        }else{
            printf("\nCantil:\t\t%-20.20s\tQtd: %d \tCapacidade: %d", jogador.cantil->nome,jogador.cantil->quantidade, jogador.cantil->capacidade);
        }
        printf("\nArma Principal:\t%-20.20s\tDano: %-5d\tChance de critico: %d", jogador.melee->nome,dano1,jogador.melee->chance_critico);
        printf("\nArma Reserva:\t%-20.20s\tDano: %-5d\tChance de critico: %d", jogador.reserva->nome,dano2,jogador.reserva->chance_critico);
        printf("\nOnda: %-3d\t4|Desequipar\t\t5|Alternar\t6|Descansar", onda);
        printf("\n---------------------------------------------------------------------");
        printf("\n1: Iniciar \n2: Loja \n3: Armazem \n10: Sair");
        printf("\nEscolha uma das opçoes: ");
        scanf("%d",&escolha);
        switch(escolha){
            case 1:
                //inicio
                clrscr();
                if(jogador.melee==&desarmado){ //se a arma não está equipada
                    printf("Equipe uma arma primeiro");
                }else{
                    printf("Get ready for the next battle");
                    persona oponente = { .nome = "thomas", .vida = 500, .energia = 100, .melee = &rapier, .atributo.forca = 10, .atributo.dextreza = 10, .atributo.constituicao = 10};
                    oponente=decidir_oponente(pacote_armas,pacote_itens,onda,&recompensa);
                    do{
                        reposicionar_armas(inventario.estoque_armas);
                        printf("\nOnda: %d", onda);
                        printf("\n-------------------------------------------------------------\n");
                        printf("%-20.20s \t\t\t\t|\t %s",jogador.nome, oponente.nome);
                        printf("\nPV: %-20d\tMP: %-10d\t|\t PV: %-15d\tMP: %-10d", jogador.vida, jogador.energia, oponente.vida, oponente.energia);
                        printf("\nArma: %-20.20s\tD: %-3d\tC: %-3d \t|\t %-20.20s\tD: %-3d\tC: %d", jogador.melee->nome,jogador.melee->dano, jogador.melee->chance_critico, oponente.melee->nome,oponente.melee->dano, oponente.melee->chance_critico);
                        if(jogador.cantil==&vazio){
                            printf("\nCantil: Não possui");
                        }else{
                            printf("\nCantil: %s\tQuantidade: %d \tCapacidade: %d", jogador.cantil->nome,jogador.cantil->quantidade, jogador.cantil->capacidade);
                        }
                        printf("\n1: Atacar \n2: Alternar equipamento \n3: Beber poção \n4: Fugir");
                        printf("\nEscolha uma ação: ");
                        scanf("%d",&escolha_alt);
                        switch(escolha_alt){
                            case 1:
                                //Ataque !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                                clrscr();
                                ataque(jogador, &oponente);
                                if(oponente.vida<=0){
                                    clrscr();
                                    printf("Voce venceu!\n");
                                    printf("\n-----------------------------------------------\n");
                                    dinheiro += 50;
                                    jogador.vida +=100;
                                    if(jogador.vida>vida_maxima){
                                        jogador.vida=vida_maxima;
                                    }
                                    jogador.wingslompsor+=onda;
                                    onda++;
                                    printf("Recompensa: \n. %s\n. %s",recompensa.estoque_armas[0]->nome,recompensa.estoque_itens[0]->nome);
                                    printf("\ndeseja guardar os itens? ");
                                    scanf("%d",&escolha_aux);
                                    clrscr();
                                    switch(escolha_aux){
                                        case 1:
                                            slot = checar_armas(inventario.estoque_armas);
                                            if(!(slot==-1)){
                                                inventario.estoque_armas[slot]=recompensa.estoque_armas[0];
                                            }else{
                                                printf("sem espaço para a arma, voce recebe o dinheiro convertido");
                                                dinheiro+=(recompensa.estoque_armas[0]->custo/2);
                                            }
                                            //--
                                            slot = checar_itens(inventario.estoque_itens);
                                            if(!(slot==-1)){
                                                inventario.estoque_itens[slot]=recompensa.estoque_itens[0];
                                            }else{
                                                printf("sem espaço para o item, voce recebe o dinheiro convertido");
                                                dinheiro+=(recompensa.estoque_itens[0]->custo/2);
                                            }
                                        break;
                                        default:
                                            dinheiro += 50;
                                        break;
                                    }
                                }else{
                                    ataque(oponente, &jogador);
                                    if(jogador.vida<=0){
                                        clrscr();
                                        printf("\ngame over\n");
                                    }
                                }
                                //Ataque !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                            break;
                            case 2:
                                //Alternar
                                clrscr();
                                address=jogador.melee;
                                jogador.melee=jogador.reserva;
                                jogador.reserva=address;
                            break;
                            case 3:
                                //beber poção
                                if(jogador.cantil==&vazio){
                                    clrscr();
                                    printf("voce nao possui um cantil");
                                }else{
                                    clrscr();
                                    quantidade = vida_maxima-jogador.vida;
                                    if(jogador.cantil->quantidade>quantidade){
                                        jogador.cantil->quantidade-=quantidade;
                                        jogador.vida+=quantidade;
                                    }else{
                                        quantidade=jogador.cantil->quantidade;
                                        jogador.cantil->quantidade=0;
                                        jogador.vida+=quantidade;
                                    }
                                }
                            break;
                            case 4:
                                //Fugir
                                clrscr();
                                printf("Fugiu");
                                onda-=5;
                                if(onda<1)onda=1;
                            break;
                            default:
                                clrscr();
                                printf("Escolha invalida");
                            break;
                        }
                    }while(escolha_alt!=4&&jogador.vida>0&&oponente.vida>0);
                }
            break;
            case 2:
                //loja
                clrscr();
                printf("\n1:Armas \n2:Itens \nVoltar\n");
                printf("\nEscolha uma das opçoes: ");
                scanf("%d",&alternador);
                switch(alternador){
                    case 1:
                        //Armas
                        clrscr();
                        slot = checar_armas(inventario.estoque_armas);
                        if(slot == -1){
                                clrscr();
                                printf("\nNão há espaço\n");
                            }else{
                                dinheiro=comprar_armas(dinheiro, loja, &inventario, slot);
                            }
                    break;
                    case 2:
                        //Itens
                        clrscr();
                        slot = checar_itens(inventario.estoque_itens);
                        if(slot == -1){
                                clrscr();
                                printf("\nNão há espaço\n");
                            }else{
                                dinheiro=comprar_itens(dinheiro, loja, &inventario, slot);
                            }
                    break;
                    default:
                        clrscr();
                        printf("\n\nOperação Cancelada\n\n");
                    break;
                }
            break;
            case 3:
                //inventario
                dinheiro=inventory(&inventario, &jogador, &desarmado, &vazio, dinheiro);
            break;
            case 0:
                //subir de subir de nivel
                clrscr();
                subir_nivel(&jogador);
            break;
            case 4:
                //desarmar
                clrscr();
                if(!(jogador.cantil==&vazio)){
                    slot = checar_itens(inventario.estoque_itens);
                    inventario.estoque_itens[slot]=jogador.cantil;
                    jogador.cantil=&vazio;
                }
                if(!(jogador.melee==&desarmado)){
                    slot = checar_armas(inventario.estoque_armas);
                    inventario.estoque_armas[slot]=jogador.melee;
                    jogador.melee=&desarmado;
                }else{
                    printf("nenhuma arma equipada");
                }
            break;
            case 5:
                //alternar
                clrscr();
                address=jogador.melee;
                jogador.melee=jogador.reserva;
                jogador.reserva=address;
            break;
            case 6:
                //reset/Descanso
                clrscr();
                onda=1;
                jogador.vida=vida_maxima;
            break;
            case 10:
                //sair
                clrscr();
                printf("Ele  estava cansando demais para continuar");
            break;
            default:
                //falha
                clrscr();
                printf("\n\nEscolha invalida.\n");
            break;
        }
        
    }while(escolha!=10&&jogador.vida>0);
    
    return 0;
}

