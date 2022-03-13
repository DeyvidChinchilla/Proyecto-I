/*
Estructura para la ejecucion
de un archivo para almacernar 
una lista de alumnos
*/

/*Declaramos las librerias a utilizar*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <iomanip>

using namespace std;

struct Alumno{/*Estructura alumano (datos a almacenar)*/
	char nombre[20];
	int carnet;
	char correo[40];
	char seccion[20];
	int cicloescolar;
	char promedio[20];
	char estado[20];
};

void AgregarAlumno();// Funcion agregar alumno al listado
void BuscarAlumno();// Funcion buscar alumno
void ModificarAlumno();// Funcion modificar el estado y promedio

int main()
{
	int opcion;
	char opc = 's';
	while (opc == 's')//Ciclo while para la ejecucion del menu de entrada
	{
        system("cls");
	cout << "\n";
        cout << "\n ==Menu Datos de Alumnos UMG==";
        cout <<"\n\n                                          ";
     	cout << "\n\n 1. Agregar Alumno";
        cout << "\n\n 2. Buscar Alumnos";
        cout << "\n\n 3. Modificar los datos del alumno ";
        cout << "\n\n 4. Salir";
        cout << "\n\n";
        cout << "\n\n\n Seleccione una opcion del menu :=> ";
        cin>>opcion;
        if(opcion>4 && opcion <= 0)//Definimos la variable a utilizar
	    {
            cout<<"\n\n Opcion no valida!"<<endl;
            cout<<"\n\n Ingrese la que se encuentra en el menu: ";
            cin>>opcion;
        }
        switch(opcion)//Utilizamos switch para la identificacion de la accion 
        {
        	case 1: 
         		AgregarAlumno();
         		break;
         	case 2:
         		BuscarAlumno();
         		break;
            case 3: 
         		ModificarAlumno();
         		break;
         	case 4: 
                    cout<<"\n\n";
         	 		cout<<"Desea Volver al menu de datos s/n ?\n"<<endl;
                    fflush(stdin);//Utilizamos el parametro fflush para editar el buffer. 
				cin>>opc;
				break;
       } 
        
	}
		system("Pause()");
}		

void AgregarAlumno()
{
	system("cls");	
	FILE *F;
	Alumno a1;
	/*Definimos los datos 
	del alumno con los parametros
	fflush(stdin)*/
	char caracter[50];
	fflush(stdin);
	cout<<"ingrese el Nombre del Alumno:";
	fflush(stdin);
	cin>>a1.nombre;
	
	do{
	FILE *H;
	Alumno a1;
	int carnet;
	// cargando la clave a buscar;
	cout<<"Ingrese Numero de Carnet:";
	cin>>carnet;getchar();
	fflush(stdin);
	//abriendo; Leyendo ;cargando la estructura //
	H = fopen("infoAlumno.txt","a+");
	//consistencia de la apertura del archivo;
	if (H == NULL)
	{
		cout<<"No se Puede abrir el Archivo"<<endl;
		exit(1);
		
	}
	fread(&a1, sizeof(a1),1,/* se guarda un elemento por uno*/H); // H es donde se guardan los elementos donde se direcciona al puntero;
    while (!feof(H))
    {
    	if (a1.carnet == carnet)
    	{
    		cout<<"El carnet ya fue ingresado"<<endl;
    	}	
    		
	
		fread(&a1,sizeof(a1),1,H);
	};
	//cerrando el archivo;
	fclose(H);
	
	}while(a1.carnet != a1.carnet);
	cout<<"ingrese de nuevo el carnet:";
	fflush(stdin);
	cin>>a1.carnet;
	
	fflush(stdin);
	cout<<"ingrese el Correo Electronico:";
	fflush(stdin);
	cin>>a1.correo;
	fflush(stdin);
	cout<<"ingrese la seccion :";
	cin>>a1.seccion;
	cout<<"Ciclo escolar:";
	fflush(stdin);
	cin>>a1.cicloescolar;
	cout<<"ingrese Promedio:";
	fflush(stdin);
	cin>>a1.promedio;
	cout<<"ingrese el Estado:";
	fflush(stdin);
	cin>>a1.estado;
	
	if(a1.estado >="A"){// Utilizamos el ciclo if para identificar el estado del alumno
		strcpy(caracter,"Aprobado");
	}
	else if(a1.estado <="R"){
		strcpy(caracter,"Reprobado");
	}
	else{
		strcpy(caracter,"Estado no Valido");
	}
	
	cout<<"\n\nDatos del Alumno: "<<endl;
	cout<<"Nombre:" <<a1.nombre<<endl;
	cout<<"Carnet:" <<a1.carnet<<endl;
	cout<<"Correo:" <<a1.correo<<endl;
	cout<<"Seccion:" <<a1.seccion<<endl;
	cout<<"Ciclo escolar:" <<a1.cicloescolar<<endl;
	cout<<"Promedio:" <<a1.promedio<<endl;
	cout<<"Estado:" <<caracter<<endl;
	cout << "\n\n";
	
	F = fopen("infoAlumno.txt","a+");//Declaramos el archivo
	
	if(F == NULL)//Descartamos que halla un error de ejecucion
	{
		cout<<"No se puede abrir el archivo"<<endl;
		exit(1);
	}
	
	fwrite(&a1,sizeof(a1),1,F);
	fclose(F);
	cout<<"Datos de Alumno en el Archivo"<<endl;
	system("Pause()");
	
}

void BuscarAlumno()
{
	system("cls");
	FILE *H;
	Alumno a1;
	int carnet;
	// cargando la clave a buscar;
	cout<<"Carnet a Buscar ---> ";
	cin>>carnet;getchar();
	//abriendo; Leyendo ;cargando la estructura //
	H = fopen("InfoAlumno.txt","a+");
	//consistencia de la apertura del archivo;
	if (H == NULL)
	{
		cout<<"No se Puede abrir el Archivo"<<endl;
		exit(1);
		
	}
	// aqui siempre debe empezar el ciclo de lectura
    // y fread() regresa siempre cuantas estructuras leyoñ{ñ-
    cout<<"========================================\n"<<endl;
    cout<<"Carnet\tNombre\tcorreo                   \tSeccion   \tCiclo Escolar\tPromedio\tEstado"<<endl;
    cout<<"-----------------------------------------------------------------------------\n"<<endl;
    
    fread(&a1, sizeof(a1),1,/* se guarda un elemento por uno*/H); // H es donde se guardan los elementos donde se direcciona al puntero;
    
    // Desplegando el registro// lectura;
    while (!feof(H))
    {
    	if (a1.carnet == carnet)
    	{
    		cout<<a1.carnet;
    		cout<<"\t"<<a1.nombre;
    		cout<<"\t"<<a1.correo;
    		cout<<setw(10)<<a1.seccion;
    		cout<<setw(16)<<a1.cicloescolar;
    		cout<<"\t\t"<<a1.promedio;
    		cout<<"\t\t"<<a1.estado;
    		cout<<"\n"<<endl;
    		
		}
		fread(&a1,sizeof(a1),1,H);
	};
	//cerrando el archivo;
	fclose(H);
	system("Pause()");
	
}
void ModificarAlumno()
{
	system("cls");
	FILE *FF; //  variable Puntero para Abrir  el archivo existente;
	FILE *GG;// variable Puntero para crear un archivo temporal;
	Alumno a1;
	int encontrado = 0;
	int removido;
	int modificado;
	int carnet;
	//cargando clave para buscar;
	cout<<"Carnet a Modificar ---> ";
	cin>>carnet;getchar(); // getchar solo te va capturar el primer caracter;
	//Abriendo, leyendo,cargando estructura;//
	FF = fopen("InfoAlumno.txt","r+"); //  r == abre un fichero para lectura. Si el fichero no existe devuelve error. 
	                             // + == símbolo utilizado para abrir el fichero para lectura y escritura.
    // consistencia de la apertura del archivo;
    
    if (FF == NULL)
    {
    	cout<<"No se puede abrir el archivo\n "<<endl;
    	exit(1);
	}
	GG = fopen("Tempt.txt","a+");
	// consistencia del archivo;
	if (GG == NULL)
	{
		cout<<"No se puede abrir el Archivo\n";
		exit(1);
	}
	// aqui siempre debe empezar el ciclo de lectura
    // y fread() regresa siempre cuantas estructuras leyo
     cout<<"========================================\n"<<endl;
     cout<<"Carnet\tEstado\tPromedio"<<endl;
     cout<<"----------------------------------------\n"<<endl;
	
     fread(&a1,sizeof(a1),1,FF);
	//proceso de  reescritura;	
	while(!feof(FF))
	{
		if (a1.carnet == carnet)
		{
			cout<<"Nuevo Estado---> ";
			gets(a1.estado);
			cout<<"Nuevo Promedio ---> ";
			gets(a1.promedio);
			fwrite(&a1, sizeof(a1), 1, GG); // fwrite (direcc_dato, tamaño_dato, numero_datos, punt_fichero);
			encontrado = 1;
		}
		else
		{
			fwrite(&a1,sizeof(a1),1,GG);
		}
		   fread(&a1,sizeof(a1),1,FF);
		
	};// termina el while;
	// cerrando archivos;
	fclose(FF);
	fclose(GG);
	
	 //Removiendo y eliminando
    //Recordar que los nombres Directorios/carpetas y Archivos de datos no
    // pueden tener mas de 8.3  caracteres
    removido = remove("InfoAlumno.txt");
    cout<<"REMOVIDO"<<"  "<<removido;
    modificado = rename("Tempt.txt","InfoAlumno.txt");
    cout<<"RENOMBRADO"<<"  "<<modificado;
    // avisando;
    if ( encontrado == 0)
    	cout<<"No existe este Carnet \n\n";
	else
		cout<<"Alumno Actualizado"<<endl;
	system("Pause()");
	
}
