#include "TADCadena.h"
#define TAM_MAX 1000

void leeCad(char *cadena, int tam){
	int j, m;
	/*obtener el primer caracter del stdin*/
	m=getchar();
	/*ANALIZAR EL PRIMER CARACTER LEÍDO*/
	if (m!=EOF) { /*si el primer caracter no es fin de archivo*/
		/*inicializacion del índice que maneja el vector de char*/
		j=0;
		/*si el primer caracter leido no es un enter, se lo guarda en la cadena*/
		if (m!='\n'){ 
			cadena[j]=m; 
			j++;
		}
		/*LEER DEL SEGUNDO CARACTER EN ADELANTE*/
		/*leer el resto de los caractaeres y ponerlos en el vector de char*/
		m=getchar();
		while (j<tam-1 && m!=EOF && m!='\n') {
			cadena[j]=m;
			m=getchar();
			j++;
		}
		/*agregar marca de fin de cadena*/
		cadena[j]='\0';
		
		/*vaciar la pila*/
		while(m!=EOF && m!='\n')
			m=getchar();
		} 
	else {
		/*si se lee el fin del archivo en el primer caracter, no hay cadena*/
		/*solo poner la marca de fin de cadena*/
	cadena[0]='\0';
	}

}
		
void LeeCad(char *Cadena){
	leeCad(char Cadena, int tam);
}
