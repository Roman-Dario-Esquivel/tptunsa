#include "CLStr.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//quita primer y último caracter de la cadena
//asume que inicia y termina con {} o con []
char* clean(char* s){
	int i=1;
	char* aux;
	aux=(char*) malloc(sizeof(char)*255); 
	while (s[i]!='\0'){
		aux[i-1]=s[i];
		i++;
	}
	aux[i-2]='\0';
	return aux;
}

//de la cadena s extrae el primer elemento de la estructura
//asume llaves y corchetes balanceados
void getElem(char**s, char**aux){
	char* s_aux;
	int i=0;
	int cont_abre_l=0;
	int cont_cierra_l=0;
	int cont_abre_c=0;
	int cont_cierra_c=0;
	int j,salir;
		
	*aux=(char*) malloc(sizeof(char)*255); 
	s_aux=(char*) malloc(sizeof(char)*255);
	if ((*s)[0]!='{' && (*s)[0]!='[') {
		while ((*s)[i]!='\0' && (*s)[i]!=',') {
			(*aux)[i]=(*s)[i];
			i++;
		}
		(*aux)[i]='\0';
	} else {
		salir=0;
		while ((*s)[i]!='\0' && !salir) {
			(*aux)[i]=(*s)[i];
			switch ((*s)[i]) {
			case '{':
				cont_abre_l++;
				break;
			case '[':
				cont_abre_c++;
				break;	
			case '}':
				cont_cierra_l++;
				break;
			case ']':
				cont_cierra_c++;
				break;
			}
			if (cont_abre_l-cont_cierra_l==0 && cont_abre_c-cont_cierra_c==0) 
				salir=1;
			i++;
		}
		(*aux)[i]='\0';
	}
	i++;
	if (i<strlen(*s)) {
		j=0;
		while ((*s)[i]!='\0'){
			s_aux[j]=(*s)[i];
			j++;
			i++;
		}
		s_aux[j]='\0';
		*s=s_aux;
	} else *s=NULL;
}
