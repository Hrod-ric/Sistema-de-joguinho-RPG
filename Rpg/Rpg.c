#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "mostrar.c"
#include "jogador.c"
#include "inimigos.c"
#include "loja.c"
#include "armas.c"
#include "itens.c"
#include "tipo_ataque.c"
#include "comprar.c"
#include "inventario.c"
#include "subir_nivel.c"
#include "oferta.c"
#include "decidir_oponente.c"
int main(void){
    srand(time(NULL));
	setlocale(LC_ALL, "portuguese");
    int slot = -1, escolha = 0, escolha_alt = 0, escolha_aux = 0, alternador = 0, equipar = 0, onda = 1;
    arma* address;
    int dano1, dano2, quantidade;
    loja=predefinido1;
    oponente=thomas;
    oferta(onda);
    conjunto recompensa;
    
    //programa
    do{
    	decidir_op(onda);
        dano1=calcular_dano(&jogador,jogador.atributo.forca,jogador.atributo.dextreza);
        dano2=calcular_dano(&oponente,oponente.atributo.forca,oponente.atributo.dextreza);
        vida_maxima=jogador.atributo.constituicao*25;
        energia_maxima=jogador.atributo.constituicao*15;
        jogador.nivel = jogador.atributo.forca + jogador.atributo.dextreza + jogador.atributo.constituicao - 29;
        printf("\n------------------------------------------------------------------------");
        printf("\nNome: %s", jogador.nome);
        printf("\nVida: %-10d\t\t\tEnergia: %-3d\tDinheiro: %d", jogador.vida, jogador.energia, dinheiro);
        printf("\nArma Principal:\t%-20.20s\tDano: %-5d\tC. de critico: %d", jogador.melee->nome,dano1,jogador.melee->chance_critico);
        printf("\nArma Reserva:\t%-20.20s", jogador.reserva->nome);
        if(jogador.cantil==&vazio){
            printf("\nCantil:\t\tNão possui");
        }else{
            printf("\nCantil:\t\t%-20.20s\tQtd: %d \tCapacidade: %d", jogador.cantil->nome,jogador.cantil->quantidade, jogador.cantil->capacidade);
        }
        printf("\n------------------------------------------------------------------------");
        printf("\nOnda: %-3d\t4|Desequipar\t\t5|Alternar\t6|Descansar", onda);
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
                    do{
                        reposicionar_armas(inventario.estoque_armas);
                        printf("\nOnda: %d", onda);
                        printf("\n-------------------------------------------------------------\n");
                        printf("%-20.20s \t\t\t\t|\t %s",jogador.nome, oponente.nome);
                        printf("\nPV: %-20d\tMP: %-10d\t|\t PV: %-15d\tMP: %-10d", jogador.vida, jogador.energia, oponente.vida, oponente.energia);
                        printf("\nArma: %-20.20s\tD: %-3d\tC: %-3d \t|\t %-20.20s\tD: %-3d\tC: %d", jogador.melee->nome,dano1, jogador.melee->chance_critico, oponente.melee->nome,dano2, oponente.melee->chance_critico);
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
                                    dinheiro += 50;
                                    jogador.vida +=100;
                                    if(jogador.vida>vida_maxima){
                                        jogador.vida=vida_maxima;
                                    }
                                    jogador.wings+=onda;
                                    onda++;
                                    oferta(onda);
                                    escolha_aux=rand()%5;
                                    if(escolha_aux==4){
                                    	printf("\n-----------------------------------------------\n");
                                        printf("Recompensa: \n. %s\n. %s",oponente.melee->nome,oponente.cantil->nome);
                                        printf("\ndeseja guardar os itens? ");
                                        scanf("%d",&escolha_aux);
                                        clrscr();
                                        switch(escolha_aux){
                                            case 1:
                                                slot = checar_armas(inventario.estoque_armas);
                                                if(!(slot==-1)){
                                                    inventario.estoque_armas[slot]=oponente.melee;
                                                }else{
                                                    printf("sem espaço para a arma, voce recebe o dinheiro convertido");
                                                    dinheiro+=(oponente.melee->custo/2);
                                                }
                                                //--
                                                slot = checar_itens(inventario.estoque_itens);
                                                if(!(slot==-1)){
                                                    inventario.estoque_itens[slot]=oponente.cantil;
                                                }else{
                                                    printf("sem espaço para o item, voce recebe o dinheiro convertido");
                                                    dinheiro+=(oponente.cantil->custo/2);
                                                }
                                            break;
                                            default:
                                                dinheiro += 50;
                                            break;
                                        }
                                    }
                                }else{
                                	srand(time(NULL));
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
                    if(slot==-1){
                    	printf("Não tem espaço");
					}else{
						inventario.estoque_itens[slot]=jogador.cantil;
                    	jogador.cantil=&vazio;
					}
                }
                if(!(jogador.melee==&desarmado)){
                    slot = checar_armas(inventario.estoque_armas);
                    if(slot==-1){
                    	printf("Não tem espaço");
					}else{
                    	inventario.estoque_armas[slot]=jogador.melee;
                    	jogador.melee=&desarmado;
                	}
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
