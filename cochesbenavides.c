// TRABAJO DE INFORMATICA 2019 


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
//system("cls"); -> Lo usaremos para borrar la pantalla
typedef struct{
	char marca[30];
	char modelo[30];
	int year;
	float precio;
	float kmrecorridos;//Si son 0 se le dara la categoria de nuevo.
	char matricula[8];//Las matriculas constan de 4 numeros y de tres letras.
	int vendido;// Valdra 1 si se ha vendido, valdra 0 si no se ha vendido.
}coches;

typedef struct{
	char nombre[30];
	int password;
}usuario;
 

//Funciones que se van a usar
int registracoche( );
int muestrainventario();
int cuentalineas();//funcion clave que usaremos durante el programa para saber el numero de coches.
int buscamarca();
int buscanuevos();
int ordenaprecio();
int ordenakilometros();
int buscamatricula();
int cuentalineasusuario();
int compracoches();

//FUNCION PRINCIAL
int main()
{
	int i=0,N=cuentalineasusuario(),posicion,pass,control1=0,control2=0;//posición servirá para anotar la línea en la que esta el usuario y así comparar su contraseña
	usuario empleados[N];
	char empleado[50];
	FILE *pusuarios;
	pusuarios = fopen("usuarios.txt", "r");
	if (pusuarios == NULL)
	{
		printf("Error al abrir el fichero.\n");
		return -1;
	}
	while (feof(pusuarios) == 0) //Primero leemos los datos 
		{
			fscanf(pusuarios, "%[^;]; %d; ",empleados[i].nombre,&empleados[i].password);//significa [^;] que lo leemos hasta que haya un punto y coma
			i++;
		}
	fclose(pusuarios);
	do{
	
	printf("Introduzca su nombre de usuario en mayusculas:\n");
	scanf("%s",empleado);
	
	for(i=0;i<N;i++)
	{
		if(strcmp(empleado,empleados[i].nombre)==0)
		{
			printf("Usuario correcto\n");
			control1=1;
			printf("Introduzca su password:\n");
			scanf("%d",&pass);
			if (empleados[i].password == pass)
			{
				printf("Password correcta\n");
				control2=1;
			}
		}
	}
}while(control1!=1||control2!=1);

system("cls");//borramos el control de usuario

	int a,b,c; //para los switch-case
	printf("\n*****BIENVENIDO A COCHES BENAVIDES %c, su concesionatio de confianza*****\n",169);
	do
	{	
		printf("\nQue desea hacer: \n1:Registrar coche \n2:Mostrar listado de coches \n3:Buscar coches \n4:Ordenar por caracteristica \n5:Comprar coches \n6:Salir\n");
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
					printf("\n1:Por marca \n2:Por matricula  \n3:busca coches nuevos \n4:Volver\n");
					scanf("%i",&b);
					switch(b)
					{
						case 1:
							//funcion para buscar por marca	
							buscamarca();
						break;
						
						case 2:
							
							buscamatricula();
							
						break;
						case 3:
							buscanuevos();
						
						case 4:
							printf("\nHas vuelto al inicio.\n");
						break;
					}	
				} while(b!=4);
			break;
			
			case 4:// para las funciones de ordenar
				do
				{
					printf("\n1:Por kilometros \n2:Por precio \n3:Volver\n");
					scanf("%i",&c);
					switch(c)
					{
						case 1:
							ordenakilometros();
						break;
						
						case 2:
							ordenaprecio();
						break;
							
						case 3:
							printf("\nHas vuelto al inicio.\n");
						break;
					}	
				} while(c!=3);
			break;
			
			case 5:
			 compracoche();
			
			case 6:
				printf("\nSaliendo de Coches Benavides %c, su concesionario de confianza.\n",169);
				return 0;
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
		scanf("%[^\n]", cochenuevo.marca);// El [^\n] es para leer todo hasta el salto de linea,tambien se podria poner %s
		fprintf(pcoches, "%s; ", cochenuevo.marca);
		
		fflush(stdin);
		printf("\nModelo del coche:\n");
		scanf("%[^\n]", cochenuevo.modelo);
		fprintf(pcoches, "%s; ", cochenuevo.modelo);
		
		printf("\nA%co de fabricacion del coche:\n", 164);
		scanf("%d",&cochenuevo.year);
		if(cochenuevo.year<0) 
		{
			printf("\nA%co no valido\n",164);
			return -1;
		}
		else
		fprintf(pcoches, "%d; ", cochenuevo.year);
		
		printf("\nPrecio del coche:\n");
		scanf("%f",&cochenuevo.precio);
		if(cochenuevo.precio<0) 
		{
			printf("\nEl precio no puede ser negativo, esto no es una ONG\n");
			return -1;
		}
		else
			fprintf(pcoches, "%.2f; ", cochenuevo.precio);
		
		printf("\nKilometros recorridos por el coche:\n");
		scanf("%f",&cochenuevo.kmrecorridos);
		if(cochenuevo.kmrecorridos<0) 
		{
			printf("\nVa hacia atras el coche?\n");
			return -1;
		}
		else
			fprintf(pcoches, "%.2f; ", cochenuevo.kmrecorridos);
		
		printf("\nIntroduzca la matricula del coche(4 numeros y 3 letras ):\n");
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
		printf("[Marca] [Modelo] [Year] [Precio]  [Km recorridos]  [Matricula] [Estado]\n");
		while (feof(pcoches) == 0) // Leemos el fichero y mostramos los coches
		{  
		fscanf(pcoches, "%[^;]; %[^;]; %d; %f; %f; %[^;]; %d; ", cochenuevo.marca,cochenuevo.modelo,&cochenuevo.year,&cochenuevo.precio,&cochenuevo.kmrecorridos,&cochenuevo.matricula,&cochenuevo.vendido);
	
			printf("--------------------------------------------------------------------------\n");
			if (cochenuevo.vendido==0)
			{
				printf("%s %s %d %.2f  %.2f %s %s %s\n",cochenuevo.marca,cochenuevo.modelo,cochenuevo.year,cochenuevo.precio,cochenuevo.kmrecorridos,cochenuevo.matricula,"En venta");
			}
			else if(cochenuevo.vendido==1)
			{
				printf("%s %s %d %.2f  %.2f %s %s %s\n",cochenuevo.marca,cochenuevo.modelo,cochenuevo.year,cochenuevo.precio,cochenuevo.kmrecorridos,cochenuevo.matricula,"Vendido");
			}
		}
	}
	fclose(pcoches); 
	return 0;
}
int compracoche()
	{
	int i=0, marcaexiste=0,marcaexiste2=0,N=cuentalineas(),linea;//Línea tendrá el valor de la línea en la que esta
	float presupuesto;
	coches cochenuevo[N];
	char matricula[8];// Matrícula del coche deseado
	FILE *pcoches;
	pcoches=fopen("Concesionario.txt","r");//Abro el fichero para leer y apuntar
	fflush(stdin);
	printf("Introduzca presupuesto para ver que coches hay en el catalogo que no esten vendidos:\n");
	scanf("%f",&presupuesto);
	
	while (feof(pcoches) == 0) //Primero leemos los datos
		{
			fscanf(pcoches, "%[^;]; %[^;]; %d; %f; %f; %[^;]; %d; ",cochenuevo[i].marca,cochenuevo[i].modelo,&cochenuevo[i].year,&cochenuevo[i].precio,&cochenuevo[i].kmrecorridos,&cochenuevo[i].matricula,&cochenuevo[i].vendido);
			i++;
		}
	for(i=0;i<N;i++)
	{
		if((presupuesto>=cochenuevo[i].precio)&&(cochenuevo[i].vendido==0))
		{
	
			printf("%s %s %d %.2f %.2f %s\n",cochenuevo[i].marca,cochenuevo[i].modelo,cochenuevo[i].year,cochenuevo[i].precio,cochenuevo[i].kmrecorridos,cochenuevo[i].matricula);
			marcaexiste=1;
	
		}
	}
	
	if (marcaexiste<1)
	{
		printf("No hay coches por ese precio, estirese un poco");
	}
	
	else
	{
		fflush(stdin);
		printf("Introduzca matrícula del coche que desea:\n");
		scanf("%s",matricula);
		for(i=0;i<N;i++)
		{
			if (strcmp(matricula,cochenuevo[i].matricula)==0)//Busco el coche que quiero comprar, es decir el cual quiero cambiar de 1 a 0
			{
				printf("Efectuando su compra, demasiado tarde para arrepentirse\n");
				linea=i;
				cochenuevo[linea].vendido=1;
				marcaexiste2=1;   	
			}
		}
		if (marcaexiste2<1)
		{
			printf("No existe ningun coche asi en nuestro inventario\n");
		}
	}
	fclose(pcoches);
	pcoches=fopen("Concesionario.txt","w");//Abro el fichero esta vez para apuntar los cambios realizados
	for(i=0;i<N;i++)
	{
		fprintf(pcoches, "%s; %s; %d; %.2f; %.2f; %s; %d; \n",cochenuevo[i].marca,cochenuevo[i].modelo,cochenuevo[i].year,cochenuevo[i].precio,cochenuevo[i].kmrecorridos,cochenuevo[i].matricula,cochenuevo[i].vendido);
	}
	fclose(pcoches);
	return 0;
}

int cuentalineas()
{
		FILE *pcoches;
	int N=0;// numero de lineas
	char c;
	pcoches = fopen("Concesionario.txt", "r");
	
	if (pcoches == NULL)
	{
		printf("Error al abrir el fichero.\n");
		return -1;
	}
	else
	{
		while (fscanf(pcoches, "%c", &c) != EOF)//hasta que no llega al final y lee 0 no para 
		{
			if (c == '\n') // va aumentando el numero de lineas
				N++;
		}
		printf("\nHay %d coches.\n",N);
	}
	fclose(pcoches); 
	return N;//Devuelve un valor que es el número de saltos de línea contados
}

int buscamarca( )
{
	int i=0,presente=0;
	int N=cuentalineas( );//para saber el numero de coches
	char marca[50];
	coches cochenuevo[N];
	
	
	FILE *pcoches;
    pcoches=fopen("Concesionario.txt","r");	

	
	if (pcoches == NULL)
	{
		printf("Error al abrir el fichero.\n");
		return -1;
	}
	else
	{
		fflush(stdin); 	
    	printf("\nIntroduzca la marca que le interesa: \n");
		scanf("%s",marca);
		
		while (feof(pcoches) == 0) //Primero leemos los datos
		{
			fscanf(pcoches, "%[^;]; %[^;]; %d; %f; %f; %[^;]; %d; ",cochenuevo[i].marca,cochenuevo[i].modelo,&cochenuevo[i].year,&cochenuevo[i].precio,&cochenuevo[i].kmrecorridos,&cochenuevo[i].matricula,&cochenuevo[i].vendido);
			i++;
		}
				for(i=0;i<N;i++)//Recorremos el vector
		{
			if (strcmp(marca,cochenuevo[i].marca)==0)
			{
				printf("%s %s %d %.1f %.1f %s\n",cochenuevo[i].marca,cochenuevo[i].modelo,cochenuevo[i].year,cochenuevo[i].precio,cochenuevo[i].kmrecorridos,cochenuevo[i].matricula,cochenuevo[i].vendido);
				presente=1;     	
		    }
		}
		 if(presente<1)
		    {
		    	printf("No hay coches con esa marca\n");
			}
		printf("\n");
	}
	return 0;
	
	}
	
int buscanuevos()
{
	int i=0, marcaexiste=0,N=cuentalineas();
	coches cochenuevo[N];
	
	FILE *pcoches;
	pcoches=fopen("Concesionario.txt","r");
		if (pcoches == NULL)
	{
		printf("Error al abrir el fichero.\n");
		return -1;
	}
	else{
	
	fflush(stdin);
	printf("Buscando coches nuevos en nuestro registro:\n");
	while (feof(pcoches) == 0) // Leemos el fichero 
	{  
		fscanf(pcoches, "%[^;]; %[^;]; %d; %f; %f; %[^;]; %d; ", cochenuevo[i].marca,cochenuevo[i].modelo,&cochenuevo[i].year,&cochenuevo[i].precio,&cochenuevo[i].kmrecorridos,&cochenuevo[i].matricula,&cochenuevo[i].vendido);
		i++;
	}
	for(i=0;i<N;i++)
	{
		if(0==cochenuevo[i].kmrecorridos)
		{
			printf("%s %s %d %.2f %.2f %s\n",cochenuevo[i].marca,cochenuevo[i].modelo,cochenuevo[i].year,cochenuevo[i].precio,cochenuevo[i].kmrecorridos,cochenuevo[i].matricula);
			marcaexiste=1;
		}
	}
	if (marcaexiste<1)
	{
		printf("No hay coches nuevos actualmente");
	}
   }
	fclose(pcoches);
	return 0;
}
int buscamatricula()
{
	int i=0,presente=0;
	int N=cuentalineas( );//para saber el numero de coches
	char matricula[8];
	coches cochenuevo[N];
	
	
	FILE *pcoches;
    pcoches=fopen("Concesionario.txt","r");	

	
	if (pcoches == NULL)
	{
		printf("Error al abrir el fichero.\n");
		return -1;
	}
	else
	{
		fflush(stdin); 	
    	printf("\nIntroduzca la matricula que desea buscar: \n");
		scanf("%s",matricula);
		
		while (feof(pcoches) == 0) //Primero leemos los datos
		{
			fscanf(pcoches, "%[^;]; %[^;]; %d; %f; %f; %[^;]; %d; ",cochenuevo[i].marca,cochenuevo[i].modelo,&cochenuevo[i].year,&cochenuevo[i].precio,&cochenuevo[i].kmrecorridos,&cochenuevo[i].matricula,&cochenuevo[i].vendido);
			i++;
		}
				for(i=0;i<N;i++)//Recorremos el vector
		{
			if (strcmp(matricula,cochenuevo[i].matricula)==0)
			{
				printf("%s %s %d %.1f %.1f %s\n",cochenuevo[i].marca,cochenuevo[i].modelo,cochenuevo[i].year,cochenuevo[i].precio,cochenuevo[i].kmrecorridos,cochenuevo[i].matricula,cochenuevo[i].vendido);
				presente=1;     	
		    }
		}
		 if(presente<1)
		    {
		    	printf("No se ha encontrado coches con esa matricula\n");
			}
		printf("\n");
	}
	return 0;
}

int ordenaprecio()
{
	int i=0,j;
	int N=cuentalineas();
	coches cochenuevo[N],aux;
	FILE *pcoches;
	pcoches=fopen("Concesionario.txt","r");
	
	if (pcoches == NULL)
     	{
		printf("Error al abrir el fichero.\n");
		return -1;
     	}
    else {
	 
	while (feof(pcoches) == 0) //Primero leemos los datos
		{
			fscanf(pcoches, "%[^;]; %[^;]; %d; %f; %f; %[^;]; %d; ",cochenuevo[i].marca,cochenuevo[i].modelo,&cochenuevo[i].year,&cochenuevo[i].precio,&cochenuevo[i].kmrecorridos,&cochenuevo[i].matricula,&cochenuevo[i].vendido);
			i++;
		}


		//METODO BURBUJA:
	for (i=0; i<N; i++) {
		for (j=i+1; j<N; j++) { //bucle anidado
			if (cochenuevo[i].precio>cochenuevo[j].precio){
				aux=cochenuevo[i];
				cochenuevo[i]=cochenuevo[j];
				cochenuevo[j]=aux;
			}
		}
	}
	
	//Imprimir forma ascendente:
	printf ("\n Coches ordenados de menor a mayor segun su precio:\n");
	printf("[Marca] [Modelo] [Year] [Precio]  [Km recorridos]  [Matricula]\n");
	for (i=0;i<N;i++){
		printf("--------------------------------------------------------------------------\n");
			printf("%s %s %d %.2f %.2f %s\n",cochenuevo[i].marca,cochenuevo[i].modelo,cochenuevo[i].year,cochenuevo[i].precio,cochenuevo[i].kmrecorridos,cochenuevo[i].matricula);
                    }
       }

fclose(pcoches);
return 0;
}

int cuentalineasusuario()
{
		FILE *pusuarios;
	int N=0;// numero de lineas
	char c;
	pusuarios = fopen("usuarios.txt", "r");
	
	if (pusuarios == NULL)
	{
		printf("Error al abrir el fichero.\n");
		return -1;
	}
	else
	{
		while (fscanf(pusuarios, "%c", &c) != EOF)
		{
			if (c == '\n') // va aumentando el numero de lineas
				N++;
		}
		printf("\nHay %d usuarios.\n",N);
	}
	fclose(pusuarios); 
	return N;//Devuelve un valor que es el número de saltos de línea contados
}
int ordenakilometros()
{
	int i=0,j;
	int N=cuentalineas();
	coches cochenuevo[N],aux;
	FILE *pcoches;
	pcoches=fopen("Concesionario.txt","r");
	
	if (pcoches == NULL)
     	{
		printf("Error al abrir el fichero.\n");
		return -1;
     	}
    else {
	 
	while (feof(pcoches) == 0) //Primero leemos los datos
		{
			fscanf(pcoches, "%[^;]; %[^;]; %d; %f; %f; %[^;]; %d; ",cochenuevo[i].marca,cochenuevo[i].modelo,&cochenuevo[i].year,&cochenuevo[i].precio,&cochenuevo[i].kmrecorridos,&cochenuevo[i].matricula,&cochenuevo[i].vendido);
			i++;
		}


		//METODO BURBUJA:
	for (i=0; i<N; i++) {
		for (j=i+1; j<N; j++) { //bucle anidado
			if (cochenuevo[i].kmrecorridos>cochenuevo[j].kmrecorridos){
				aux=cochenuevo[i];
				cochenuevo[i]=cochenuevo[j];
				cochenuevo[j]=aux;
			}
		}
	}
	
	//Imprimir forma ascendente:
	printf ("\n Coches ordenados de menor a mayor segun la distancia que han recorrido:\n");
	printf("[Marca] [Modelo] [Year] [Precio]  [Km recorridos]  [Matricula]\n");
	for (i=0;i<N;i++){
		    printf("--------------------------------------------------------------------------\n");
			printf("%s %s %d %.2f %.2f %s\n",cochenuevo[i].marca,cochenuevo[i].modelo,cochenuevo[i].year,cochenuevo[i].precio,cochenuevo[i].kmrecorridos,cochenuevo[i].matricula);
                    }
        }
fclose(pcoches);
return 0;
}
