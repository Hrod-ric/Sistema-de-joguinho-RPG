#ifndef itensHEADER_H
#define itensHEADER_H
typedef struct{
    char nome [20];
    int quantidade; //pontos que vão ser convertidos no tipo
    int capacidade;
    int tipo;   // 1-cura, 2-energia, 3-dano, 4-defesa...
    int custo;
}item;

//itens / tipo:
        //1 - Cantil
        item vazio={            .nome = "vazio",            .tipo = 1,  .quantidade = 0,    .capacidade = 0,   .custo = 0 };
        item cantil_p={   .nome = "Cantil pequeno",   .tipo = 1,  .quantidade = 125,  .capacidade = 125,  .custo = 50 };
        item cantil_m={     .nome = "Cantil medio",     .tipo = 1,  .quantidade = 250,  .capacidade = 250,  .custo = 75 };
        item cantil_g={    .nome = "Cantil grande",    .tipo = 1,  .quantidade = 375,  .capacidade = 375,  .custo = 100 };
        item cantil_mx={    .nome = "Cantil maximo",    .tipo = 1,  .quantidade = 500,  .capacidade = 500,  .custo = 125 };
        //2 - energia
        item energia={     .nome = "energia pequena", .quantidade = 50,   .tipo = 2, .custo = 100 };
#endif
