// Trabajo de Hugo Rivera, Miguel �ngel Rodrigo y Javier Benavides Q-103
#include<stdio.h>


int main()
{
	int a,b,c; //para los switch-case
	printf("\n*****BIENVENIDO A COCHES BENAVIDES %c, su concesionatio de confianza*****\n",169);
	//Funci�n para identificar al empleado que usa el programa, constar� de nombre y contrase�a
	do
	{	
		printf("\nQue desea hacer: \n1:Registrar venta \n2:Mostrar listado de ventas \n3:Buscar \n4:Mostrar por orden especifico \n5:Salir\n");
		scanf("%i",&a);
		
		switch (a)
		{
			case 1:
				//Funci�n para registrar coche que se ha vendidio
			break;
				
			case 2:
				//Funci�n para mostrar inventario
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
							//funcion para buscar por kil�metros
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
	} while(a!=5);
	return 0;
}
