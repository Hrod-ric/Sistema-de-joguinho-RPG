#ifndef ofertaHEADER_H
#define ofertaHEADER_H
#include <time.h>
#include "loja.c"
void oferta(int onda){
	srand(time(NULL));
    int escolha;
    if(onda<5){
        //pre boss
        escolha=rand()%4;
        if(escolha==0){
            loja = predefinido1;
        }else if(escolha==1){
            loja = predefinido2;
        }else if(escolha==2){
            loja = predefinido3;
        }else if(escolha==3){
            loja = predefinido4;
        }
    }else if(onda==5){
        //boss
        escolha=rand()%4;
        if(escolha==0){
            loja = predefinido5;
        }else if(escolha==1){
            loja = predefinido5;
        }else if(escolha==2){
            loja = predefinido5;
        }else if(escolha==3){
            loja = predefinido5;
        }
    }else if(onda<10){
        //pre boss
        escolha=rand()%4;
        if(escolha==0){
            loja = predefinido1;
        }else if(escolha==1){
            loja = predefinido2;
        }else if(escolha==2){
            loja = predefinido3;
        }else if(escolha==3){
            loja = predefinido4;
        }
    }else if(onda==10){
        //boss
        escolha=rand()%4;
        if(escolha==0){
            loja = predefinido1;
        }else if(escolha==1){
            loja = predefinido2;
        }else if(escolha==2){
            loja = predefinido3;
        }else if(escolha==3){
            loja = predefinido4;
        }
    }else if(onda<15){
        //pre boss
        escolha=rand()%4;
        if(escolha==0){
            loja = predefinido1;
        }else if(escolha==1){
            loja = predefinido2;
        }else if(escolha==2){
            loja = predefinido3;
        }else if(escolha==3){
            loja = predefinido4;
        }
    }else if(onda==20){
        //boss
        escolha=rand()%4;
        if(escolha==0){
            loja = predefinido1;
        }else if(escolha==1){
            loja = predefinido2;
        }else if(escolha==2){
            loja = predefinido3;
        }else if(escolha==3){
            loja = predefinido4;
        }
    }else if(onda>20){
        //boss
        escolha=rand()%4;
        if(escolha==0){
            loja = predefinido1;
        }else if(escolha==1){
            loja = predefinido2;
        }else if(escolha==2){
            loja = predefinido3;
        }else if(escolha==3){
            loja = predefinido4;
        }
    }
}
#endif
