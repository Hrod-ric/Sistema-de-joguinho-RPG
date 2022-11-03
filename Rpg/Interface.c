#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <conio.h>
//COR DA LETRA
enum{BLACK,                 //0
   BLUE,                  //1
   GREEN,                 //2
   CYAN,                  //3
   RED,                   //4
   MAGENTA,               //5
   BROWN,                 //6
   LIGHTGRAY,             //7
   DARKGRAY,              //8
   LIGHTBLUE,             //9
   LIGHTGREEN,            //10
   LIGHTCYAN,             //11
   LIGHTRED,              //12
   LIGHTMAGENTA,          //13
   YELLOW,                //14
   WHITE                  //15

   };
//COR DO FUNDO
enum{_BLACK=0,                 //0
   _BLUE=16,                  //1
   _GREEN=32,                 //2
   _CYAN=48,                  //3
   _RED=64,                   //4
   _MAGENTA=80,               //5
   _BROWN=96,                 //6
   _LIGHTGRAY=112,             //7
   _DARKGRAY=128,              //8
   _LIGHTBLUE=144,             //9
   _LIGHTGREEN=160,            //10
   _LIGHTCYAN=176,             //11
   _LIGHTRED=192,              //12
   _LIGHTMAGENTA=208,          //13
   _YELLOW=224,                //14
   _WHITE=240                  //15
   };
void linhacol(int lin, int col){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){col-1,lin-1});
}
void textcolor(int letras, int fundo){
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),letras+fundo);
}
void box(int lin1, int col1, int lin2, int col2){
    int i,j,tamlin,tamcol;

    tamlin=lin2-lin1;
    tamcol=col2-col1;

    for(i=col1;i<=col2;i++){ //linhas
        linhacol(lin1,i);
        printf("%c",196);
        linhacol(lin2,i);
        printf("%c",196);
    }
    for(i=lin1;i<=lin2;i++){ //colunas
    	linhacol(i,col1);
    	printf("%c",179);
    	linhacol(i,col2);
    	printf("%c",179);
	}

    for(i=lin1+1;i<lin2;i++){
        for(j=col1+1;j<col2;j++){
            linhacol(i,j);
            printf(" ");
        }
    }
    //posição dos cantos
    linhacol(lin1,col1);
    printf("%c",218);
    linhacol(lin1,col2);
    printf("%c",191);
    linhacol(lin2,col1);
    printf("%c",192);
    linhacol(lin2,col2);
    printf("%c",217);
}
int menu(int lin1, int col1, int qtd, char lista[3][40]){
    int opc=1, lin2, col2, linha, i, tammaxitem, tecla;
    //calcula as coordenadas
    tammaxitem = strlen(lista[0]);
    //tamanho maximo do item
    for(i=1;i<qtd;i++){
        if(strlen(lista[i])>tammaxitem){
            tammaxitem = strlen(lista[i]);
        }
    }
    lin2 = lin1+(qtd*2+2);
    col2 = col1+tammaxitem+4;
    //monta a tela do menu
    textcolor(WHITE,_BLUE);
    setlocale(LC_ALL,"C");
    box(lin1,col1,lin2,col2);
    setlocale(LC_ALL,"");
    //laço das opções
    while(1){
    	linha = lin1+2;
    	for(i=0;i<qtd;i++){
			if(i+1==opc)textcolor(BLACK,_LIGHTGREEN);
			else textcolor(WHITE,_BLUE);
		linhacol(linha,col1+2);
		printf("%s",lista[1]);
		linha+=2;
		}
    	
    	//aguarda teclas
    	linhacol(1,1);
    	tecla=getch();
    	
    	printf("tecla: %d",tecla);
	}
	return opc;
}

int main(){
	int opc;
	char lista[3][40]={"pizza de frango","pizza portuguesa","pizza calabreza"};
	setlocale(LC_ALL,"");
	while(1){
		opc = menu(10,10,5,lista);
	}
    box(10,20,30,60);
    textcolor(WHITE,_BLACK);
    linha(24,1);
    printf("");
}

