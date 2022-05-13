#include "CLStr.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//quita primer y �ltimo caracter de la cadena
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

int dato_conjunto_lista(char* s){
int salida;
if(s[0]=='[')
  salida=LIST;
else 
  if(s[0]=='{')
    salida=SET;
  else salida=STR;
}

struct dataType  crear_nodo(int selec,char**s){
 struct dataType=malloc(sizeof(struct dataType));
char** aux;
  struct dataType.nodeType=selec;
  if(selec=str){
    getElem(s,aux);
    struct union.*dataStr=aux;
  }
  else {crear_nodo(,s);

}
/*
#define STR 1
#define SET 2
#define LIST 3

struct dataType{
	int nodeType;
	union{
		char *dataStr;
		struct{
			struct dataType *data;
			struct dataType *next; 
		};
	};
};
*/