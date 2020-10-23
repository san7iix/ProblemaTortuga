#include <stdlib.h>
#include <stdio.h>


char tablero[20][20];
void LlenarMatriz(char matriz[][20], int size);
void ImprimirMatriz(char matriz[20][20], int size, int posTortuga[2]);
void Girar(int banderaDireccion, int giro);
void Moverse(char direccion[4], int banderaPluma, int banderaDireccion, int posTortuga[2], int cantidadMovimiento, int posTortugaAnterior[2], char tablero[20][20]);
bool ModoPluma (int banderaPluma);
char direccion[4] = {'U', 'R', 'D', 'L'};
int posTortuga[2] = {0,0};
int posTortugaAnterior[2];
int banderaDireccion = 1;
int banderaPluma = 1;

int main() {
	int comandos[15] = {2,5,11,3,5,12,3,5,11,3,5,12,1,6,9};

	
	for(int i=0;i<=15;i++){
		switch(comandos[i]){
			case 1:
				banderaPluma = 1;
				break;
			case 2:
				banderaPluma = 2;
				break;
			case 3: 
				if(banderaDireccion==3) {
					banderaDireccion = 0;
				} else {
					banderaDireccion++;
				}
				break;					
			case 4:
				if(banderaDireccion==0) {
					banderaDireccion = 4;
				} else {
					banderaDireccion--;
				}
				break;
			case 5:
				i++;				
				Moverse(direccion,banderaPluma,banderaDireccion,posTortuga,comandos[i], posTortugaAnterior,tablero);
//				ImprimirMatriz(tablero,20,posTortuga);
				break;
			case 6:
				ImprimirMatriz(tablero,20,posTortuga);
				break;
			case 9:
				break;	
			default:
				printf("\nNo existe una accion asociada\n");
				getchar();
		}
		if(comandos[i]==9)break;
	}

}


void LlenarMatriz(char matriz[20][20],int size) {
	for(int i=0; i<size; i++) {
		for(int j=0; j<size; j++) {
			matriz[i][j] = '*';
		}
	}
}

void ImprimirMatriz(char matriz[20][20], int size, int posTortuga[2]) {
	system("cls");
	for(int i=0; i<size; i++) {
		for(int j=0; j<size; j++) {
			if(posTortuga[0]==i && posTortuga[1]==j){
				printf("[T]", matriz[i][j]);
			}else{
				printf("[%c]", matriz[i][j]);
			}
		}
		printf("\n");
	}
	getchar();
}


void Girar(int banderaDireccion, int giro) {
	
	if(giro==3){
		if(banderaDireccion==4) {
			banderaDireccion = 0;
		} else {
			banderaDireccion++;
		}		
	}else{
		if(banderaDireccion==0) {
			banderaDireccion = 4;
		} else {
			banderaDireccion--;
		}
	}


}

bool ModoPluma (int banderaPluma) {
	if(banderaPluma==1){
		return false;
	}
	return true;
}

void Moverse(char direccion[4], int banderaPluma, int banderaDireccion, int posTortuga[2], int cantidadMovimiento, int posTortugaAnterior[2], char tablero[20][20]) {

	switch(direccion[banderaDireccion]) {
		case 'U':
			if(posTortuga[0] - cantidadMovimiento < 0) {
				printf("No se puede ejecutar el movimiento\n");
				getchar();
			} else {
				posTortugaAnterior[0] = posTortuga[0];
				posTortuga[0] -= cantidadMovimiento;
				if(ModoPluma(banderaPluma)){
					for(int i=posTortugaAnterior[0];i>=posTortuga[0];i--){
						tablero[i][posTortuga[1]] = '*';
					}
				}				
			}
			break;
		case 'R':
			if(posTortuga[1] + cantidadMovimiento > 19) {
				printf("No se puede ejecutar el movimiento\n");
				getchar();
			} else {
				posTortugaAnterior[1] = posTortuga[1];
				posTortuga[1] += cantidadMovimiento;
				if(ModoPluma(banderaPluma)){
					for(int i=posTortugaAnterior[1];i<=posTortuga[1];i++){
						tablero[posTortuga[0]][i] = '*';
					}
				}				
			}
			break;
		case 'D':
			if(posTortuga[0] + cantidadMovimiento > 19) {
				printf("No se puede ejecutar el movimiento\n");
				getchar();
			} else {
				posTortugaAnterior[0] = posTortuga[0];
				posTortuga[0] += cantidadMovimiento;
				if(ModoPluma(banderaPluma)){
					for(int i=posTortugaAnterior[0];i<=posTortuga[0];i++){
						tablero[i][posTortuga[1]] = '*';
					}
				}
				
			}
			break;
		case 'L':
			if(posTortuga[1] - cantidadMovimiento < 0) {
				printf("No se puede ejecutar el movimiento\n");
				getchar();
			} else {
				posTortugaAnterior[1] = posTortuga[1];
				posTortuga[1] -= cantidadMovimiento;
				if(ModoPluma(banderaPluma)){
					for(int i=posTortugaAnterior[1];i>=posTortuga[1];i--){
						tablero[posTortuga[0]][i] = '*';
					}
				}
				
			}
			break;
		default:
			getchar();
			printf("Movimiento inválido\n");
	}
}
