#ifndef armasHEADER_H
#define armasHEADER_H
typedef struct{
    char nome[21];
    int dano;
    int chance_critico;
    int tipo; //1- blunt , 2- slash , 3- piercing, 4- especial
    int str;
    int dex;
    int custo;
    char ataque[21];
}arma;


//Armas / tipo:
    //1 - Blunt
    arma pa={           .nome = "Pá",       .dano = 40, .chance_critico = 50,   .str = 3,    .dex = 1,    .tipo = 1,  .custo = 40,    .ataque="pázada" };
    arma picareta={     .nome = "Picareta", .dano = 55, .chance_critico = 50,   .str = 3,    .dex = 1,    .tipo = 3, .custo = 150,    .ataque="picaretada" };
    arma porrete={      .nome = "Porrete",  .dano = 70, .chance_critico = 40,   .str = 4,    .dex = 1,    .tipo = 1,  .custo = 60,    .ataque="paulada" };
    arma marreta={      .nome = "Marreta",  .dano = 70, .chance_critico = 60,   .str = 5,    .dex = 1,    .tipo = 1,  .custo = 100,   .ataque="marretada" };
    //2 - Slash
    arma adaga={        .nome = "Adaga",            .dano = 35, .chance_critico = 70,   .str = 1,    .dex = 4,    .tipo = 2, .custo = 40,     .ataque="esfaqueda" };
    arma machado={      .nome = "Machado",          .dano = 65, .chance_critico = 50,   .str = 3,    .dex = 2,    .tipo = 2, .custo = 70,     .ataque="machadada" };
    arma espada_longa={ .nome = "Espada longa",     .dano = 60, .chance_critico = 40,   .str = 3,    .dex = 3,    .tipo = 2, .custo = 80,     .ataque="esfolada" };
    arma cimitarra={    .nome = "Cimitarra",        .dano = 55, .chance_critico = 60,   .str = 2,    .dex = 4,    .tipo = 2, .custo = 150,    .ataque="lapada" };
    arma foice={        .nome = "Foice",            .dano = 50, .chance_critico = 50,   .str = 2,    .dex = 2,    .tipo = 2, .custo = 100,    .ataque="foiçada" };
    arma shotel={       .nome = "Shotel",           .dano = 60, .chance_critico = 60,   .str = 1,    .dex = 4,    .tipo = 2, .custo = 150,    .ataque="shotada" };
    //3 - Piercing
    arma rapier={       .nome = "Rapier",   .dano = 45, .chance_critico = 70,   .str = 2,    .dex = 4,    .tipo = 3, .custo = 70,     .ataque="catucada" };
    arma lanca={        .nome = "Lança",    .dano = 50, .chance_critico = 60,   .str = 2,    .dex = 4,    .tipo = 3, .custo = 100,    .ataque="empalada" };
    arma alabarda={     .nome = "Alabarda", .dano = 50, .chance_critico = 65,   .str = 2,    .dex = 2,    .tipo = 3, .custo = 150,    .ataque="espetada" };
    // - Especial
    arma desarmado={    .nome = "Desarmado",        .dano = 1, 	.chance_critico = 10,   .str = 4,    .dex = 4,    .tipo = 4, .custo = 0,      .ataque="porradona" };
    arma esp_madeira={  .nome = "Espada de madeira",.dano = 5, 	.chance_critico = 20,   .str = 3,    .dex = 5,    .tipo = 5, .custo = 0,      .ataque="espadada" };
    arma tocha={        .nome = "Tocha",            .dano = 50, .chance_critico = 50,   .str = 1,    .dex = 1,    .tipo = 6, .custo = 100,    .ataque="queimada" };
    arma tesoura={      .nome = "Tesoura",          .dano = 40, .chance_critico = 100,  .str = 1,    .dex = 4,    .tipo = 7, .custo = 100,    .ataque="circuncidada" };
    arma maquina={  .nome = "Maquina de Barbear",   .dano = 40, .chance_critico = 50,   .str = 1,    .dex = 4,    .tipo = 8, .custo = 100,    .ataque="calvada de cria" };
#endif
