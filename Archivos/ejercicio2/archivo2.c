#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
Realizar un programa en el cual se ingresen los siguientes datos
Nombre, Apellido y DNI
a) Crear un menu donde se ingresen los datos y los guarde en un
archivo
b) Otro �tem donde se pueda realizar una b�squeda por DNI y
devuelva los datos de Nombre y apellido
c) Salir del mismo


Modificar el programa anterior de manera que se puedan realizar
b�squedas por Apellido y por nombre a la vez.
*/
int main(){
	int opcion,dni;
	char nombre[20],apellido[20],nombre_leido[20],apellido_leido[20];
	
	FILE *fp;
	fp= fopen("fichero2.txt","a+");
	
	if(fp==NULL)
	{
		printf("No esta creado el fichero.");
	}
	
	do{
		
		printf("\t\t\tPrograma Marco\n");
		printf("1)Ingresar nombre,apellido y dni\n");
		printf("2)Busqueda por nombre y apellido\n");
		printf("3)Salir\n");
		scanf("%d",&opcion);
		
		switch(opcion){
			case 1:
				printf("\nIngrese Nombre: ");
                scanf("%s",&nombre);
                fputs(nombre,fp);
                printf("Ingrese Apellido: ");
                scanf("%s",&apellido);
                fputs(" ",fp);
				fputs(apellido,fp);
                printf("Ingrese DNI: ");
                scanf("%d",&dni);
                fprintf(fp," %d\n",dni);
                  
                printf("Datos guardados correctamente.\n");
				
				break;
			case 2:
				
				printf("\nIngrese nombre a buscar ");
                scanf("%s", &nombre);
                printf("\nIngrese apellido a buscar ");
                scanf("%s", &apellido);
                fseek(fp, 0, SEEK_SET);  // Movemos el puntero al inicio del archivo

                while (fscanf(fp, "%s %s %d", &nombre_leido, &apellido_leido, &dni) != EOF) {
                    if (strcmp(nombre, nombre_leido) == 0) {
                    	if(strcmp(apellido, apellido_leido) == 0){
                    	printf("Nombre: %s\nApellido: %s\nDNI: %d\n", nombre, apellido, dni);
                        break;  // Detenemos la b�squeda una vez que encontramos el DNI
						}
                    	
                        
                    }
                }

                if (feof(fp)) {
                    printf("Persona no encontrada.\n");
                }

				break;
			case 3:
				break;
		}
		
	}while(opcion!=3);
	fclose(fp);
	

	
	
	
}

