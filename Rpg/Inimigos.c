#ifndef inimigosHEADER_H
#define inimigosHEADER_H
#include "armas.c"
#include "itens.c"
typedef struct{
    char *nome;
    int vida;
    int energia;
    int wings;
    int nivel;
    struct{
        int forca;
        int dextreza;
        int constituicao;
    }atributo;
    arma *melee;
    arma *reserva;
    item *cantil;
}persona;
	persona oponente;
	persona esqueleto={ 	.nome = "Esqueleto",   			.vida = 150,	.energia = 100,	.melee=&pa,				.cantil=&cantil_p,.atributo.forca = 10, .atributo.dextreza = 10};
    persona e_parrudo={  	.nome = "Esqueleto Parrudo", 	.vida = 300,	.energia = 100,	.melee=&porrete,		.cantil=&cantil_p,.atributo.forca = 10, .atributo.dextreza = 10};
    persona e_pirata={		.nome = "Esqueleto Pirata",		.vida = 300,	.energia = 100, .melee=&cimitarra,		.cantil=&cantil_p,.atributo.forca = 10, .atributo.dextreza = 10};
	persona e_barbaro={  	.nome = "Esqueleto Barbaro", 	.vida = 600,	.energia = 100,	.melee=&machado,		.cantil=&cantil_p,.atributo.forca = 10, .atributo.dextreza = 10};
    persona e_lanceiro={  	.nome = "Esqueleto Lanceiro", 	.vida = 450,	.energia = 100,	.melee=&lanca,			.cantil=&cantil_p,.atributo.forca = 10, .atributo.dextreza = 10};
    persona e_combete={  	.nome = "Esquelto de Combate", 	.vida = 900,	.energia = 100,	.melee=&espada_longa,	.cantil=&cantil_p,.atributo.forca = 10, .atributo.dextreza = 10};
    persona e_minerador={  	.nome = "Esqueleto Minerador", 	.vida = 600,	.energia = 100,	.melee=&picareta,		.cantil=&cantil_p,.atributo.forca = 10, .atributo.dextreza = 10};
    persona mineiror={  	.nome = "Mineiror", 			.vida = 1200,	.energia = 100,	.melee=&picareta,		.cantil=&cantil_p,.atributo.forca = 10, .atributo.dextreza = 10};
    persona thomas = { 		.nome = "thomas", 				.vida = 500, 	.energia = 100, .melee = &esp_madeira,	.cantil=&cantil_p,.atributo.forca = 100,.atributo.dextreza = 100};
#endif
