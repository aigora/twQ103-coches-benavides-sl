// Trabajo de Hugo Rivera, Miguel Angel Rodrigo y Javier Benavides Q-103
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
//system("cls"); -> Para borrar la pantalla
typedef struct{
	char marca[30];
	char modelo[30];
	int year;
	float precio;
	float kmrecorridos;//Si son 0 se le dar? la categor?a de nuevo
	char matricula[8];//Las matr?culas constan de 4 n?meros y de tres letras
	int vendido;// Valdr? 1 si se ha vendido, valdr? 0 si no se ha vendido
}coches;

typedef struct{
	char nombre[30];
	int password;
}usuario;
/*int main(){
	usuario trabajador;
	int comparacion;
	char pass[50]="coches1999";//contraseña para poder acceder al programa
		do{
	
	printf("introduzca el nombre de empleado :\n");
    gets(trabajador.nombre);
	fflush(stdin);
	comparacion
		
		
		
		
	}
        }while (comparacion !=0);
        return 0;
    }
    */


//Funciones que se van a necesitar

int registracoche( );
int muestrainventario();

int main()
{
	int a,b,c; //para los switch-case
	printf("\n*****BIENVENIDO A COCHES BENAVIDES %c, su concesionatio de confianza*****\n",169);
	//Funci?n para identificar al empleado que usa el programa, constar? de nombre y contrase?a
	do
	{	
		printf("\nQue desea hacer: \n1:Registrar coche \n2:Mostrar listado de coches \n3:Buscar \n4:Mostrar por orden especifico \n5:Salir\n");
		scanf("%i",&a);
		
		switch (a)
		{
			case 1:
				registracoche( );
			break;
				
			case 2:
				muestrainventario();
			break;
		
			case 3:// para las funciones de buscar
				do
				{
					printf("\n1:Por marca \n2:Por matricula \n3:Volver\n");
					scanf("%i",&b);
					switch(b)
					{
						case 1:
							//funcion para buscar por marca	
						break;
						
						case 2:
							//funcion para buscar por matricula
						break;
						
						case 3:
							printf("\nHas vuelto al inicio.\n");
						break;
					}	
				} while(b!=3);
			break;
			
			case 4:// para las funciones de ordenar
				do
				{
					printf("\n1:Por kilometros \n2:Por marca \n3:Por precio \n4:Volver\n");
					scanf("%i",&c);
					switch(c)
					{
						case 1:
							//funcion para buscar por kil?metros
						break;
						
						case 2:
							//funcion para buscar por marca
						break;
						
						case 3:
							//funcion para buscar por precio
						break;
							
						case 4:
							printf("\nHas vuelto al inicio.\n");
						break;
					}	
				} while(c!=4);
			break;
			
			case 5:
				printf("\nSaliendo de Coches Benavides %c, su concesionario de confianza.\n",169);
			break;		
			
			default:
				printf("\nOpcion no disponible.\n");
			break;
		}
		//system("cls");
	} while(a!=5);
	return 0;
}

int registracoche( ) 
{
	coches cochenuevo;
	FILE *pcoches;
	pcoches=fopen("Concesionario.txt","a");
	
	if (pcoches == NULL)
	{
		printf("Error al abrir el fichero.\n");
		return -1;
	}
	
	else
	{	
		fflush(stdin);
		printf("\nMarca del coche:\n");
		scanf("%[^\n]", cochenuevo.marca);
		fprintf(pcoches, "%s; ", cochenuevo.marca);
		
		fflush(stdin);
		printf("\nModelo del coche:\n");
		scanf("%[^\n]", cochenuevo.modelo);
		fprintf(pcoches, "%s; ", cochenuevo.modelo);
		
		printf("\nA%co de fabricacion del coche:\n", 164);
		scanf("%d",&cochenuevo.year);
		if(cochenuevo.year<0) //control errores
		{
			printf("\nA%co no valido\n",164);
			return -1;
		}
		else
		fprintf(pcoches, "%d; ", cochenuevo.year);
		
		printf("\nPrecio del coche:\n");
		scanf("%f",&cochenuevo.precio);
		if(cochenuevo.precio<0) //control errores
		{
			printf("\nEl precio no puede ser negativo, esto no es una ONG\n");
			return -1;
		}
		else
			fprintf(pcoches, "%.2f; ", cochenuevo.precio);
		
		printf("\nKilometros recorridos por el coche:\n");
		scanf("%f",&cochenuevo.kmrecorridos);
		if(cochenuevo.kmrecorridos<0) //control errores
		{
			printf("\nVa hacia atras el coche?\n");
			return -1;
		}
		else
			fprintf(pcoches, "%.2f; ", cochenuevo.kmrecorridos);
		
		printf("\nIntroduzca la matricula del coche:\n");
		fflush(stdin);
		scanf("%[^\n]", cochenuevo.matricula);
		fprintf(pcoches, "%s; ", cochenuevo.matricula);
		
		cochenuevo.vendido=0;
		fprintf(pcoches,"%d; \n",cochenuevo.vendido);
		
		printf("\nCoche registrado correctamente.\n");
	}
	fclose(pcoches);
	return 0;
}

int muestrainventario( )
{
	coches cochenuevo;
	FILE *pcoches;
	pcoches=fopen("Concesionario.txt","r");
	
	if (pcoches == NULL)
	{
		printf("Error al abrir el fichero.\n");
		return -1;
	}
	else
	{
		//printf("\nMarca\t\t\tModelo\t\t\tA%co\t\t\tPrecio\t\t\tKilometros recorridos\t\t\tMatricula\n\n",164);
		while (feof(pcoches) == 0) // Leemos el fichero y mostramos los coches
		{  
			fscanf(pcoches, "%[^;]; %[^;]; %d; %f; %f; %s; %d;\n", cochenuevo.marca,cochenuevo.modelo,&cochenuevo.year,&cochenuevo.precio,&cochenuevo.kmrecorridos,&cochenuevo.matricula,&cochenuevo.vendido);
			printf("%s %s %d %.2f %.2f %s\n",cochenuevo.marca,cochenuevo.modelo,cochenuevo.year,cochenuevo.precio,cochenuevo.kmrecorridos,cochenuevo.matricula);
		}
	}
	fclose(pcoches); 
	return 0;
}
