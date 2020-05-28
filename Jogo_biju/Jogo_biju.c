/*

        02/10/2013 20:28:17 
        Autor: JOSE LOHAME CAPINGA
        Autor: THIAGO PONCE
       
        UFSCAR - SOROCA CURSO:CIÊNCIAS DA COMPUTAÇÃO
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ALTURA 8
#define LARGURA 8
#define PEDRAS 7
#define SEED time(NULL)

int procuraTrinca(int tab[ALTURA][LARGURA]);
void exibirTabuleiro(int tab[ALTURA][LARGURA]);
void preencherTabuleiro(int tab[ALTURA][LARGURA]);
void trocarVertical(int tab[ALTURA][LARGURA], int i, int j);
void trocarHorizontal(int tab[ALTURA][LARGURA], int i, int j);
void jogar(int tab[ALTURA][LARGURA]);

void mover(int tab[ALTURA][LARGURA], int i0, int j0, int i1, int j1);


int main(int argc, char *argv[]) {
	int i;
	
	int tabuleiro[ALTURA][LARGURA];
	preencherTabuleiro(tabuleiro);
	
	jogar(tabuleiro);
}

void jogar(int tab[ALTURA][LARGURA]){
	int opc = -1;
	int pontos = 0;
	int troca;
	int trocaX;
	int trocaY;
	int trinca;
	
	int x = -1;
	int y = -1;
	printf("\n\n\n");
	printf(" Jose Lohame Capinga\n ");
	printf("Tiago Ponce\n ");



	
	printf("\n\nBem vindo ao BEJEWELED !!!\n\n");
	
	exibirTabuleiro(tab);
	while(opc != 0){	
		do{
			printf("\nOpções:\n1 - Mover\n0 - Sair\n> ");
			scanf("%d", &opc);
		} while(opc != 0 && opc != 1);
		
		if(opc){
			do{
				printf("\nDê as coordenadas (1 ≤ x ≤ 8) (1 ≤ y ≤ 8)\n> ");
				scanf("%d %d", &x, &y);
			} while( x < 1 || x > 8 || y < 1 || y > 8 );
			
			// MOVER
			printf("Trocar com...\n\n");
			if( x != 1 ){
				if(y != 1){
					printf("   ");
				}
				printf("[1]   \n");
			}
			
			if( y != 1 ){
				printf("[2]");
			}
			
			printf("[x]");
			
			if( y != 8 ){
				printf("[3]");
			}
			printf("\n");
			
			if( x != 8 ){
				if(y != 1){
					printf("   ");
				}
				printf("[4]   ");
			}
			
			do{
				do{
					printf("\n> ");
					scanf("%d", &troca);
				}while(troca < 1 && troca > 4);
				
				if(troca == 1){
					trocaX = x - 1;
					trocaY = y;
				}else if(troca == 2){
					trocaX = x;
					trocaY = y - 1;
				}else if(troca == 3){
					trocaX = x;
					trocaY = y + 1;
				}else{ // troca == 4
					trocaX = x + 1;
					trocaY = y;
				}
			}while(trocaX < 1 ||trocaX > 8 || trocaY < 1 || trocaY > 8);
			
			mover(tab, x-1, y-1, trocaX-1, trocaY-1);
			/*
			printf("Movido\n");
			exibirTabuleiro(tab);
			*/
			
			trinca = procuraTrinca(tab);
			
			if(trinca == 0){
				printf("Não deu trinca!");
				mover(tab, trocaX-1, trocaY-1, x-1, y-1);
			}else{
				/*
				x = abs(trinca) / LARGURA;
				y = abs(trinca) % LARGURA;
				printf("Trinca = %d %d %c\n", x, y, (trinca>0?'v':'h'));
				exibirTabuleiro(tab);
				if(trinca > 0){ // vertical
					trocarVertical(tab, x, y);
				}else{ // horizontal
					trocarHorizontal(tab, x, y);
				}
				*/
				while(trinca != 0){
					pontos++;
					x = abs(trinca) / LARGURA;
					y = abs(trinca) % LARGURA;
					printf("Trinca! = %d %d %c\n", x+1, y+1, (trinca>0?'v':'h'));
					exibirTabuleiro(tab);
					if(trinca > 0){ // vertical
						trocarVertical(tab, x, y);
					}else{ // horizontal
						trocarHorizontal(tab, x, y);
					}
					trinca = procuraTrinca(tab);
				}
			}
			
			printf("\nPontos = %d\n", pontos);
			exibirTabuleiro(tab);
			
			x = y = troca = -1;
		}
	}
}

void exibirTabuleiro(int tab[ALTURA][LARGURA]){
	int i;
	int j;
	for(i = 0; i < ALTURA; i++){
		for(j = 0; j < LARGURA; j++){
			printf("%d ", tab[i][j]);
		}
		printf("\n");
	}
}

void preencherTabuleiro(int tab[ALTURA][LARGURA]){
	
	srand(SEED);
	
	int i;
	int j;
	
	for(i = 0; i < ALTURA; i++){
		for(j = 0; j < LARGURA; j++){
			tab[i][j] = rand() % PEDRAS + 1;
		}
	}
	
	//exibirTabuleiro(tab);
	
	int trinca;
	
	while((trinca = procuraTrinca(tab)) != 0){
		
		i = abs(trinca) / LARGURA;
		j = abs(trinca) % LARGURA;
		
		/*
		if(trinca < 0){
			printf("Trinca horizontal em ");
		}else{
			printf("Trinca vertical em ");
		}
		printf("(%d, %d)\n", i+1, j+1);
		*/
		
		tab[i][j] = rand() % PEDRAS + 1;
	}
	
	//exibirTabuleiro(tab);
}

// retorna i * ALTURA + j ( vertical ), - (i * ALTURA + j) ( horizontal ) ou 0, não encontrado
/*
	Retorna o endereço de uma trinca, ou 0.
*/
int procuraTrinca(int tab[ALTURA][LARGURA]){
	int i;
	int j;
	
	// procura trinca vertical
	for(i = 0; i < ALTURA - 2; i++){
		for(j = 0; j < LARGURA; j++){
			if(tab[i][j] == tab[i+1][j] && tab[i][j] == tab[i+2][j]){
				// trinca vertical encabeçada em [i, j]
				return i * ALTURA + j;
				// !! pode ter formado quadra ou quina !!
			}
		}
	}
	
	// procura trinca horizontal
	for(i = 0; i < ALTURA; i++){
		for(j = 0; j < LARGURA - 2; j++){
			if(tab[i][j] == tab[i][j+1] && tab[i][j] == tab[i][j+2]){
				// trinca horizontal encabeçada em [i, j]
				return - (i * ALTURA + j);
				// !! pode ter formado quadra ou quina !!
			}
		}
	}
	
	return 0;
}


void trocarVertical(int tab[ALTURA][LARGURA], int i, int j){
	//printf("Troca vertical!\n");
	int basei = i + 2;
	//printf("Basei = %d\n", basei);
	while(basei > 2){
		//printf("Troca %d por %d\n", tab[basei][j], tab[basei-3][j]);
		tab[basei][j] = tab[basei-3][j];
		basei--;
	}
	
	tab[0][j] = rand() % PEDRAS + 1;
	tab[1][j] = rand() % PEDRAS + 1;
	tab[2][j] = rand() % PEDRAS + 1;
}

void trocarHorizontal(int tab[ALTURA][LARGURA], int i, int j){
	
	int basei = i;
	
	while(basei != 0){
		tab[basei][j] = tab[basei-1][j];
		tab[basei][j+1] = tab[basei-1][j+1];
		tab[basei][j+2] = tab[basei-1][j+2];
		basei--;
	}
	
	tab[0][j] = rand() % PEDRAS + 1;
	tab[0][j+1] = rand() % PEDRAS + 1;
	tab[0][j+2] = rand() % PEDRAS + 1;

}

void mover(int tab[ALTURA][LARGURA], int i0, int j0, int i1, int j1){
	int temp = tab[i0][j0];
	tab[i0][j0] = tab[i1][j1];
	tab[i1][j1] = temp;
}
