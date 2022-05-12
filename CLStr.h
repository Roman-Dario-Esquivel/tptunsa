#ifndef CLSTR_H
#define CLSTR_H

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

char* clean(char* s);
void getElem(char**s, char**aux);

#endif
