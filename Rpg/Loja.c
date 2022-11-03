#ifndef lojaHEADER_H
#define lojaHEADER_H
#include "armas.c"
#include "itens.c"
typedef struct{
    item* estoque_itens[10];
    arma* estoque_armas[10];
}conjunto;
    //loja
    conjunto loja;
	conjunto predefinido1={ .estoque_armas={&pa},  .estoque_itens={&cantil_p}};
	conjunto predefinido2={ .estoque_armas={&adaga},  .estoque_itens={&cantil_p}};
	conjunto predefinido3={ .estoque_armas={&pa},  .estoque_itens={&cantil_p}};
	conjunto predefinido4={ .estoque_armas={&adaga},  .estoque_itens={&cantil_p}};
	conjunto predefinido5={ .estoque_armas={&porrete},  .estoque_itens={&cantil_m}};
#endif
