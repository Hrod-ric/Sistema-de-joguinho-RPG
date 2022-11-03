#include "inimigos.c"
void decidir_op(int onda){
    if(onda<5){
        //pre boss
        oponente=esqueleto;
    }else if(onda==5){
        //boss
        oponente=e_parrudo;
    }else if(onda<10){
        //pre boss
        oponente=e_pirata;
    }else if(onda==10){
        //pre boss
        oponente=e_barbaro;
    }else if(onda<15){
        //boss
        oponente=e_lanceiro;
    }else if(onda==15){
        //pre boss
        oponente=e_combete;
    }else if(onda<20){
        //boss
        oponente=e_minerador;
    }else if(onda==20){
        //pós
        oponente=mineiror;
    }else{
        oponente=thomas;
    }
}
