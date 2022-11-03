#ifndef jogadorHEADER_H
#define jogadorHEADER_H
#include "inimigos.c"
#include "loja.c"
int vida_maxima, energia_maxima, dinheiro = 90;
persona jogador={.nome = "lucas", .vida = 250, .energia = 150, .wings = 0, .melee=&desarmado, .cantil=&vazio, .reserva=&desarmado, .atributo.forca = 10, .atributo.dextreza = 10, .atributo.constituicao = 10 };
conjunto inventario={   .estoque_armas[0] = &esp_madeira, .estoque_itens[0] = &energia };
conjunto mochila;
#endif
