/*
 * ejemploP4.c
 *
 *  Created on: 19/11/2014
 *      Author: dani95rico
 */
#include <stdio.h>
#include <string.h>
#define TCAD 20+1
#define TPILA 10
#define TNOM 4

typedef char tCadena[TCAD];

typedef struct{
	tCadena pila[TPILA];
	int top;
} tPila;

	void inicioPila(tPila *p);
	int pilaLlena(tPila p);
	int pilaVacia(tPila p);
	void apilar(tPila *p,const tCadena c);
	void desapilar(tPila *p,tCadena c);
	void copiarNombres(char *argv[],tCadena nombres[]);
	void apilarPorLote(tPila *p,tCadena nombre[],int n);
	void escribirPila(tPila p);

int main(int argc,char *argv[])
{
	tCadena nombres[TNOM];
	tPila p;
	int correcto;
	int i;
	int num;
	tCadena n;

	if(argc==5)
	{
		correcto=1;
		i=1;
		while((i<argc)&&correcto)
		{
			if(strlen(argv[i]>=TCAD))
			{
				correcto=0;
				i++;
			}
		}
		if(correcto)
		{
			copiarNombres(argv,nombres);
			printf("Teclee numero entre 1 y 4: ");
			fflush(stdout);
			scanf("%d",&num);
			if(num>=1 && num<=4)
			{
				apilarPorLote(&p,nombres,num);
				escribirPila(p);
				if(!pilaVacia(p))
				desapilar(&p,n);
				printf("El elmento desapilado es: %s",n);
				fflush(stdout);
			}
		}
	}


return 0;
}
void inicioPila(tPila *p)
	{
		p->top=0;
	}
int pilaLlena(tPila p)
	{
		int llena;
		llena=0;
		if(p.top==TPILA)
		{
			llena=1;
		}
		return llena;
	}
int pilaVacia(tPila p)
{
	int vacia;
	vacia=0;
	if(p.top==0)
	{
		vacia=1;
	}
return vacia;
}
void apilar(tPila *p, const tCadena c)
{
	strcpy(p->pila[p->top],c);
	p->top=p->top+1;
}
void desapilar(tPila *p,tCadena c)
{
p->top=p->top-1;
strcpy(c,p->pila[p->top]);
}
void copiarNombres(char *argv[],tCadena nombres[])
{
int i;
for(i=0;i<TNOM;i++)
{
strcpy(nombres[i],argv[i+1]);
}
}
void escrbirPila(tPila p)
{
	int i;
	for(i=0;i<p.top;i++)
	{
		printf("%s",p.pila[i]);
		fflush(stdout);
	}
}
void apilarPorLote(tPila *p,tCadena nombres[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(!pilaLlena(*p))
		{
			apilar(p,nombres[i]);
		}
	}
}
