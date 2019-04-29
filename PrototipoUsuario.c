//Conseguir crear una función de login
//Hugo Rivera Rodríguez Q-103

#include<stdio.h>
#include<string.h>
#define USUARIO "admin"
#define PASSW "12345678"
typedef struct{
	char nombre[50];
	int password;
}usuario;

int main()
{
	printf("Introduzca nombre de usuario: \n");
	scanf("")
	
	FILE*pusuarios
	
	int a,b,verifica=0;//Valor que guardar en el strcmp y valor para sali del bucle
	char usuario[50],pass[50];
	do{
		printf("Introduzca su nombre de usuario:\n");
		gets(usuario);
		printf("Introduzca su password de 8 caracteres:\n");
		gets(pass);
		a=strcmp(usuario,USUARIO);
		b=strcmp(pass,PASSW);
		if(a==1||a==-1)
		{
			printf("Usuario no registrado\n");
			verifica=0;
		}
		else if (b==1||b==-1)
		{
			printf("Password incorrecto\n");
			verifica=0;
		}
		else if (a==0&&b==0)
		{
			printf("Usuario y password correcto\n");
			verifica=1;
		}
	}while(verifica==0);
}
