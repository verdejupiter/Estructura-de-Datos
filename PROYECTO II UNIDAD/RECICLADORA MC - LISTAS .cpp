#include <iostream>
#include <conio.h>
#include <string.h>
#include "TITULO.h"
#include "I-PRINCIPAL.h"
#include "I-SECUNDARIA.h"

using namespace std ;
void interfaz_secundaria ();

//MENÚ DOMICILIARIOS
    void 	menu_principal_domiciliarios () ;
	int 	numero_dni, elegir, regresar, i, opc, posicion, numero_recicladores = 0;
	char	deter ;
	
struct info_datos {
	char 	calle [30] ;
	int  	numero ;
	char 	urbanizacion [30] ;	
} ;

struct info_desechos {
	int	 	cantidad_kg ;
	float  	precio_venta_kg ;
	float   precio_total ;
};

struct desechos {
	string	desechos ;
};

struct recicladores{
    int   	dni ;
	char   	nombres [30] ;
	char   	apellidos [30] ;
	struct 	info_datos direccion ;
	struct 	info_desechos P ; 
	struct  desechos D ;
	struct 	recicladores *anterior ;
	struct 	recicladores *siguiente ;
						
}*primero;

string desechos [6] = { "EN GENERAL (GRIS)", "ORGANICOS (MORADO)",	"VIDRIOS (VERDE)", 
						"PLASTICOS Y ENVASES METALICOS (AMARILLO)",	"PAPEL (AZUL)", "PELIGROSOS (ROJO)"};

void titulo_a ()
{
	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS DOMICILIARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
	cout << "\t\t\t     || REGISTRAR DATOS PERSONALES Y TIPO DE DESECHO DEL RECICLADOR || \n\n" ;
}

void titulo_b ()
{
	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS DOMICILIARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
	cout << "\t\t\t\t\t\t|| AGREGAR NUEVO RECICLADOR AL REGISTRO || \n\n" ;
}

void retorna_principal ()//Regresa al menú domiciliario
{
    cout << "\n\n\n\t\t\t      Digite | 1 | para regresar al "<<char(174)<<"| MENé RESIDUOS DOMICILIARIOS |"<<char(175)<<" \n\n" ;
    cout << "\n\t\t\t\t\t        Digite | 0 | para "<<char(174)<<"| SALIR |"<<char(175) ;
    do
    {
	cout <<" \n\n\t\t\t\t\t\t\t "<<char(174)<<char(175)<<" " ;
	cin  >> regresar ; 	
	} while ( regresar != 1 && regresar != 0 );		
	system ( "CLS" ) ;
	
	if ( regresar == 1 ) 
		{
		SOLO_TITULO();//Pertenece a la libreria TITULO.h
		menu_principal_domiciliarios () ;
		}
}

void regis_recicladores ( int n_c )//Función que registra recicladores
{
	for ( int i = 0; i < n_c; i = i + 1 ) // n_c=numero de recicladores
    {    	
    recicladores *nuevo = new recicladores ();
	recicladores *nuevo_1 = new recicladores();
	
	SOLO_TITULO();//Pertenece a la libreria TITULO.h
	titulo_a ();
	
    cout << "\n\t\t\t\t\t      | REGISTRO DE RECICLADORES | \n" ;
	cout << "\n\t\t\t\t\t       ---  RECICLADOR N"<<char(167)<<" " << i+1 << "  --- \n\n" ; 	fflush(stdin);
	cout << "\n\t\t\t\t|- Datos Personales -| \n\n" ; 
	do {
	cout << "\t\t\t\t~~ Digite el n\xA3mero de DNI del reciclador: "; 							fflush(stdin);
	cin  >> nuevo -> dni;	
	} while ( nuevo -> dni < 10000000 || nuevo -> dni > 99999999 ) ;				 
	cout << "\t\t\t\t~~ Digite los nombres del reciclador     : ";								fflush(stdin);
	cin.getline ( nuevo -> nombres,30,'\n' ) ;		
	cout << "\t\t\t\t~~ Digite los apellidos del reciclador   : ";								fflush(stdin);
	cin.getline ( nuevo -> apellidos,30,'\n' ) ; 			
	cout << "\n\n\t\t\t\t|- Direcci\xA2n de la vivienda -| \n\n"; 											
	cout << "\t\t\t\t~~ Digite el nombre de la calle          : ";								fflush(stdin);
	cin.getline ( nuevo -> direccion.calle,30,'\n' ) ;   	
	cout << "\t\t\t\t~~ Digite el n\xA3mero de la casa           : ";							fflush(stdin);
	cin  >> nuevo -> direccion.numero ; 				  		
	cout << "\t\t\t\t~~ Digite la urbanizaci\xA2n o distrito     : "; 							fflush(stdin);
	cin.getline ( nuevo -> direccion.urbanizacion,30,'\n');
			
	system ("CLS");
	SOLO_TITULO();
	titulo_a ();
	
	cout << "\n\t\t\t\t| REGISTRO DE TIPO DE DESECHOS RECICLADOS DE "<< nuevo -> nombres <<" "<< nuevo -> apellidos <<" | \n\n\n" ;
	cout << "\t\t\t\t\t  1. DESECHOS EN GENERAL (GRIS) \n\n" ;
    cout << "\t\t\t\t\t  2. ORG"<<char(181)<<"NICOS (MORADO) \n\n" ;
    cout << "\t\t\t\t\t  3. VIDRIOS (VERDE) \n\n";
    cout << "\t\t\t\t\t  4. PL"<<char(181)<<"STICOS Y ENVASES MET"<<char(181)<<"LICOS (AMARILLO) \n\n" ;
    cout << "\t\t\t\t\t  5. PAPEL (AZUL) \n\n";
    cout << "\t\t\t\t\t  6. DESECHOS PELIGROSOS (ROJO) \n\n";
    cout << "\n\t\t\t\t  "<<char(175)<<char(175)<<" Digite una opci\xA2n : ";
    do{
	cin  >> opc;
	} while ( opc < 1 && opc > 6 );
	    
    system ( "CLS" );    
	
	switch  ( opc )
		{
		case 1:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_a ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 8);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [0] <<" DE "<< nuevo -> nombres<<" "<<nuevo -> apellidos<<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			nuevo -> D.desechos = "\n\n\t\t\t\t\t  - DESECHOS EN GENERAL (GRIS) \n";
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;				fflush(stdin);
			cin  >> nuevo -> P.cantidad_kg ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;				fflush(stdin);
			cin  >> nuevo -> P.precio_venta_kg ;
						
			nuevo -> P.precio_total = nuevo -> P.cantidad_kg * nuevo -> P.precio_venta_kg ;	
					
			system ( "CLS" ) ;			
   			break ;
   		case 2:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_a ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 5);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [1] <<" DE "<< nuevo -> nombres<<" "<<nuevo -> apellidos<<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			nuevo -> D.desechos = "\n\n\t\t\t\t\t  - DESECHOS ORGANICOS (MORADO) \n" ;
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;				fflush(stdin);
			cin  >> nuevo -> P.cantidad_kg ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;				fflush(stdin);
			cin  >> nuevo -> P.precio_venta_kg ;
						
			nuevo -> P.precio_total = nuevo -> P.cantidad_kg * nuevo -> P.precio_venta_kg ;	
					
			system ( "CLS" ) ;			
   			break ;
		case 3:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_a ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 2);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [2] <<" DE "<< nuevo -> nombres<<" "<<nuevo -> apellidos<<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			nuevo -> D.desechos = "\n\n\t\t\t\t\t  - DESECHOS VIDRIOS (VERDE) \n";
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;				fflush(stdin);
			cin  >> nuevo -> P.cantidad_kg ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;				fflush(stdin);
			cin  >> nuevo -> P.precio_venta_kg ;
						
			nuevo -> P.precio_total = nuevo -> P.cantidad_kg * nuevo -> P.precio_venta_kg ;	
					
			system ( "CLS" ) ;			
   			break ;
		case 4:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_a ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 6);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [3] <<" DE "<< nuevo -> nombres<<" "<<nuevo -> apellidos<<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			nuevo -> D.desechos = "\n\n\t\t\t\t\t  - DESECHOS PLASTICOS Y ENVASES METALICOS (AMARILLO)\n" ;
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;				fflush(stdin);
			cin  >> nuevo -> P.cantidad_kg ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;				fflush(stdin);
			cin  >> nuevo -> P.precio_venta_kg ;
						
			nuevo -> P.precio_total = nuevo -> P.cantidad_kg * nuevo -> P.precio_venta_kg ;	
					
			system ( "CLS" ) ;			
   			break ;
		case 5:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_a ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 1);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [4] <<" DE "<< nuevo -> nombres<<" "<<nuevo -> apellidos<<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			nuevo -> D.desechos = "\n\n\t\t\t\t\t  - DESECHOS PAPEL (AZUL)\n";
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;				fflush(stdin);
			cin  >> nuevo -> P.cantidad_kg ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;				fflush(stdin);
			cin  >> nuevo -> P.precio_venta_kg ;
						
			nuevo -> P.precio_total = nuevo -> P.cantidad_kg * nuevo -> P.precio_venta_kg ;	
					
			system ( "CLS" ) ;			
   			break ; 
		case 6:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_a ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 4);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [5] <<" DE "<< nuevo -> nombres<<" "<<nuevo -> apellidos<<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			nuevo -> D.desechos = "\n\n\t\t\t\t\t  - DESECHOS PELIGROSOS (ROJO)\n";
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;				fflush(stdin);
			cin  >> nuevo -> P.cantidad_kg ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;				fflush(stdin);
			cin  >> nuevo -> P.precio_venta_kg ;
						
			nuevo -> P.precio_total = nuevo -> P.cantidad_kg * nuevo -> P.precio_venta_kg ;	
					
			system ( "CLS" ) ;			
   			break ;    		
   		}
				   				
		// actualizar reciclador
		nuevo -> siguiente = NULL ; 
			
		if (primero != NULL)
		{
			nuevo_1 = primero;
			while (nuevo_1->siguiente != NULL)
			{
				nuevo_1 = nuevo_1->siguiente;
			}
			nuevo_1->siguiente = nuevo;
			nuevo->anterior = nuevo_1;			
		}	
		else
		{
			primero = nuevo;
			nuevo->anterior = NULL;	
		}
	}
}

void ver_recicladores ( int numero_recicladores ) // ver recicladores de Inicio a Fin
{
   	recicladores *ver_r = new recicladores();
	
	float precio_global = 0, Kg_global = 0;
	ver_r = primero;	
			
    for ( int i = 0 ; i < numero_recicladores ; i = i + 1 ) 
    	{
			cout <<"\n\n\t\t\t\t -| DATOS PERSONALES DEL RECICLADOR " << i+1 << " |- \n";	
			cout <<"\n\t\t\t	    Nombres y apellidos : " << ver_r -> nombres<<" "<<ver_r -> apellidos ;
        	cout <<"\n\t\t\t	    N"<<char(167)<<" DNI              : " <<ver_r -> dni ;
			cout <<"\n\t\t\t	    Direcci\xA2n           : " << ver_r -> direccion.calle<<" "<<ver_r -> direccion.numero<<" "<<ver_r->direccion.urbanizacion ;
			
			cout << ver_r -> D.desechos;
			
			cout << "\n\t\t\t\t	    CANTIDAD (Kg.)\t  PRECIO - VENTA(S/.)\t  TOTAL(S/.)\n " ;
			cout << "\n\t\t\t\t\t	    "<< ver_r -> P.cantidad_kg <<"\t\t\t  " ;
    		cout << ver_r -> P.precio_venta_kg	<<" \t\t     " ;
    		cout << ver_r -> P.precio_total	;
			
			Kg_global = Kg_global +	ver_r -> P.cantidad_kg ;
			precio_global = precio_global +	ver_r -> P.precio_total ;
			
			ver_r = ver_r -> siguiente ;      
        }
	cout << "\n\n\t\t\t\t __________________________________________________________________________ \n" ;
	cout << "\n\n\t\t\t\t -| RESULTADOS FINALES DE LOS "<< numero_recicladores <<" RECICLADORES |- \n";
	cout << "\n\t\t\t\t	    CANTIDAD GLOBAL (Kg.) \t\t\t TOTAL GLOBAL (S/.)" ;
	cout << "\n\n\t\t\t\t\t	    "<< Kg_global << " \t\t\t\t\t\t"<< precio_global ;
}

void ver_recicladores_fi () // ver recicladores de Fin a Inicio
{
	recicladores *a = new recicladores () ;
	float precio_global = 0, Kg_global = 0;
    
	a = primero ;
    while ( a -> siguiente != NULL )
        a = a -> siguiente ;
    while ( a != NULL )
    {
	    for ( int i = 0 ; i < numero_recicladores ; i = i + 1 ) 
    	{
   		cout <<"\n\n\t\t\t\t -| DATOS PERSONALES DEL RECICLADOR " << numero_recicladores - i << " |- \n";
	    cout <<"\n\t\t\t	    Nombres y apellidos : " << a -> nombres<<" "<<a -> apellidos ;
        cout <<"\n\t\t\t	    N"<<char(167)<<" DNI              : " <<a -> dni ;
		cout <<"\n\t\t\t	    Direcci\xA2n           : " << a -> direccion.calle<<" "<<a -> direccion.numero<<" "<<a->direccion.urbanizacion ;
			
		cout << a -> D.desechos;
			
		cout << "\n\t\t\t\t	    CANTIDAD (Kg.)\t  PRECIO - VENTA(S/.)\t  TOTAL(S/.)\n " ;
		cout << "\n\t\t\t\t\t	    "<< a -> P.cantidad_kg <<"\t\t\t  " ;
    	cout << a -> P.precio_venta_kg	<<" \t\t     " ;
    	cout << a -> P.precio_total	;
			
		Kg_global = Kg_global +	a -> P.cantidad_kg ;
		precio_global = precio_global +	a -> P.precio_total ;
				        
        a = a -> anterior ;        	
		}
		cout << "\n\n\t\t\t\t __________________________________________________________________________ \n" ;
		cout << "\n\n\t\t\t\t -| RESULTADOS FINALES DE LOS "<< numero_recicladores <<" RECICLADORES |- \n";
		cout << "\n\t\t\t\t	    CANTIDAD GLOBAL (Kg.) \t\t\t TOTAL GLOBAL (S/.)" ;
		cout << "\n\n\t\t\t\t\t	    "<< Kg_global << " \t\t\t\t\t\t"<< precio_global ;		
    }
}   	

void dni_un_reciclador ( int num_dni_recicla )// Muestra el registro de un reciclador y desecho según dni.
{
		int i=1, k=0;//k=bandera i=iterador		 
		
		recicladores *dni_r = new recicladores();
		dni_r = primero;
		
		SOLO_TITULO();
		cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS DOMICILIARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
		cout << "\t\t\t\t|| REGISTRO ESPEC"<<char(214)<<"FICO DE UN RECICLADOR Y TIPO DE DESECHO || \n\n\n" ;
		
		if(primero != NULL)
		{
			do
			{
				if(dni_r->dni == num_dni_recicla)// evalua la igualdad entre el dni ingresado con los registrados.
				{
				cout <<"\n\t\t\t\t -| DATOS PERSONALES DEL RECICLADOR " << i << " |- \n";
        		cout <<"\n\t\t\t	    Nombres y apellidos : " << dni_r -> nombres<<" "<<dni_r -> apellidos ;
        		cout <<"\n\t\t\t	    N"<<char(167)<<" DNI              : " << dni_r -> dni ;
				cout <<"\n\t\t\t	    Direcci\xA2n           : " << dni_r -> direccion.calle<<" "<< dni_r -> direccion.numero<<" "<< dni_r->direccion.urbanizacion ;
			
				cout << dni_r  -> D.desechos;
			
				cout << "\n\t\t\t\t	    CANTIDAD (Kg.)\t  PRECIO - VENTA(S/.)\t  TOTAL(S/.)\n " ;
				cout << "\n\t\t\t\t\t	    "<< dni_r -> P.cantidad_kg <<"\t\t\t  " ;
    			cout << dni_r  -> P.precio_venta_kg	<<" \t\t     " ;
    			cout << dni_r  -> P.precio_total	;
    			k=1;
				}
			dni_r = dni_r->siguiente;//actualiza al siguiente nodo
			i=i+1;	
			}
			while((dni_r != NULL) && (k==0));
			
			if(k==0)//evalua si no existe ningun dni igual al ingresado en el registro.
			{
			cout<<"\n El reciclador no fue encontrado."<<endl;
			}					
		}			 
}

void mayor_venta ( int numero_recicladores ) //Función que muestra la mayor venta
{
		int i=1, k=0;//k=bandera
		
		float mayor;
						 
		recicladores *may_venta_r = new recicladores();
		recicladores *may_venta_reciclador = new recicladores();
		
		may_venta_r = primero;
		may_venta_reciclador = primero;
		
		mayor=may_venta_r  -> P.precio_total;
		
		for (int i=0; i<numero_recicladores; i=i+1)
    	{		
			if (may_venta_r  -> P.precio_total > mayor)
			{
			mayor=may_venta_r  -> P.precio_total;
			}
			may_venta_r  = may_venta_r->siguiente;//actualiza al siguiente nodo
		}
				
		if(primero != NULL)
		{
			do
			{
				if(may_venta_reciclador->P.precio_total == mayor)//busca el precio total y muestra datos
				{
				cout <<"\n\t\t\t\t -| DATOS PERSONALES DEL RECICLADOR " << i << " |- \n";
        		cout <<"\n\t\t\t	    Nombres y apellidos : " << may_venta_reciclador -> nombres<<" "<<may_venta_reciclador -> apellidos ;
        		cout <<"\n\t\t\t	    N"<<char(167)<<" DNI              : " << may_venta_reciclador -> dni ;
				cout <<"\n\t\t\t	    Direcci\xA2n           : " << may_venta_reciclador -> direccion.calle<<" "<< may_venta_reciclador -> direccion.numero<<" "<< may_venta_reciclador->direccion.urbanizacion ;
			
				cout << may_venta_reciclador  -> D.desechos;
			
				cout << "\n\t\t\t\t	    CANTIDAD (Kg.)\t  PRECIO - VENTA(S/.)\t  TOTAL(S/.)\n " ;
				cout << "\n\t\t\t\t\t	    "<< may_venta_reciclador -> P.cantidad_kg <<"\t\t\t  " ;
    			cout << may_venta_reciclador  -> P.precio_venta_kg	<<" \t\t     " ;
    			cout << may_venta_reciclador  -> P.precio_total	;
    			cout << "\n\n\t\t\t\t\t     | ~ MAYOR VENTA (S/.) ~ | ---------------------| "<<mayor<<" |";
    		 	k=1;
				}
			may_venta_reciclador = may_venta_reciclador->siguiente;//actualiza al siguiente nodo
			i=i+1;	
			}
			while((may_venta_reciclador != NULL) && (k==0));					
		}			 
}

void menor_venta ( int numero_recicladores ) //Función que muestra la menor venta
{
		int i=1, k=0;//k=bandera i=iterador
		
		float menor;
						 
		recicladores *men_venta_r = new recicladores();
		recicladores *men_venta_reciclador = new recicladores();
		
		men_venta_r = primero;
		men_venta_reciclador = primero;
		
		menor=men_venta_r  -> P.precio_total;
		
		for (int i=0; i<numero_recicladores; i=i+1)
    	{		
			if (men_venta_r  -> P.precio_total < menor)
			{
			menor = men_venta_r  -> P.precio_total;
			}
			men_venta_r  = men_venta_r->siguiente;
		}
				
		if(primero != NULL)
		{
			do
			{
				if(men_venta_reciclador->P.precio_total == menor)//busca el precio total y muestra datos
				{
				cout <<"\n\t\t\t\t -| DATOS PERSONALES DEL RECICLADOR " << i << " |- \n";
        		cout <<"\n\t\t\t	    Nombres y apellidos : " << men_venta_reciclador -> nombres<<" "<<men_venta_reciclador -> apellidos ;
        		cout <<"\n\t\t\t	    N"<<char(167)<<" DNI              : " << men_venta_reciclador -> dni ;
				cout <<"\n\t\t\t	    Direcci\xA2n           : " << men_venta_reciclador -> direccion.calle<<" "<< men_venta_reciclador -> direccion.numero<<" "<< men_venta_reciclador->direccion.urbanizacion ;
			
				cout << men_venta_reciclador  -> D.desechos;
			
				cout << "\n\t\t\t\t	    CANTIDAD (Kg.)\t  PRECIO - VENTA(S/.)\t  TOTAL(S/.)\n " ;
				cout << "\n\t\t\t\t\t	    "<< men_venta_reciclador -> P.cantidad_kg <<"\t\t\t  " ;
    			cout << men_venta_reciclador  -> P.precio_venta_kg	<<" \t\t     " ;
    			cout << men_venta_reciclador  -> P.precio_total	;
    			cout << "\n\n\t\t\t\t\t     | ~ MENOR VENTA (S/.) ~ | ---------------------| "<<menor<<" |";
    		 	k=1;
				}
			men_venta_reciclador = men_venta_reciclador->siguiente;//actualiza al siguiente nodo
			i=i+1;	
			}
			while((men_venta_reciclador != NULL) && (k==0));					
		}			 
}

void anadir_nuevo_reciclador ( int pos ) //Función que añade un reciclador más (antes o después)
{
	recicladores *q = new recicladores () ;	
    recicladores *t = new recicladores () ;
		
	cout << "\n\n\t\t\t\t   ~ Digite 'D', si agregara - DESPUES - de la posici\xA2n | " << pos << " |" ;
	cout << "\n\n\t\t\t\t   ~ Digite 'A', si agregara - ANTES - de la posici\xA2n | " << pos << " | " ;
	do {
		cout << "\n\n\t\t\t\t\t\t\t"<<char(174)<<char(175)<< " " ;
		cin  >> deter ;
	} while ( deter != 'A' &&  deter != 'a' && deter != 'D' && deter != 'd' ) ;
	
	system ("CLS");
	SOLO_TITULO();
	titulo_b ();
    cout << "\n\t\t\t\t|- Datos Personales -| \n\n" ; 
	do {
	cout << "\t\t\t\t~~ Digite el n\xA3mero de DNI del reciclador: " ; 		fflush(stdin);
	cin  >> q -> dni;
	} while ( q -> dni < 10000000 || q -> dni > 99999999 ) ; 						 
	cout << "\t\t\t\t~~ Digite los nombres del reciclador     : " ;			fflush(stdin);
	cin.getline ( q -> nombres,30,'\n' ) ;		
	cout << "\t\t\t\t~~ Digite los apellidos del reciclador   : " ;			fflush(stdin);
	cin.getline ( q -> apellidos,30,'\n' ) ; 			
	cout << "\n\n\t\t\t\t|- Direcci\xA2n de la vivienda -| \n\n" ; 											
	cout << "\t\t\t\t~~ Digite el nombre de la calle          : " ;			fflush(stdin);
	cin.getline ( q -> direccion.calle,30,'\n' ) ;   	
	cout << "\t\t\t\t~~ Digite el n\xA3mero de la casa           : " ;		fflush(stdin);
	cin  >> q -> direccion.numero ; 				  		
	cout << "\t\t\t\t~~ Digite la urbanizaci\xA2n o distrito     : " ; 		fflush(stdin);
	cin.getline ( q -> direccion.urbanizacion,30,'\n') ;
			
	system ("CLS");
	SOLO_TITULO();
	titulo_b ();
	cout << "\n\t\t\t\t| REGISTRO DE TIPO DE DESECHOS RECICLADOS DE "<< q -> nombres <<" "<< q -> apellidos <<" | \n\n\n" ;
	cout << "\t\t\t\t\t  1. DESECHOS EN GENERAL (GRIS) \n\n" ;
    cout << "\t\t\t\t\t  2. ORG"<<char(181)<<"NICOS (MORADO) \n\n" ;
    cout << "\t\t\t\t\t  3. VIDRIOS (VERDE) \n\n";
    cout << "\t\t\t\t\t  4. PL"<<char(181)<<"STICOS Y ENVASES MET"<<char(181)<<"LICOS (AMARILLO) \n\n" ;
    cout << "\t\t\t\t\t  5. PAPEL (AZUL) \n\n";
    cout << "\t\t\t\t\t  6. DESECHOS PELIGROSOS (ROJO) \n\n";
    cout << "\n\t\t\t\t  "<<char(175)<<char(175)<<" Digite una opci\xA2n : ";
    cin  >> opc;
    
    system ( "CLS" );
    
	switch  ( opc )
		{
		case 1:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_b ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 8);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [0] <<" DE "<< q -> nombres<<" "<< q -> apellidos<<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			q -> D.desechos = "\n\n\t\t\t\t\t  - DESECHOS EN GENERAL (GRIS) \n";
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;				fflush(stdin);
			cin  >> q -> P.cantidad_kg ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;				fflush(stdin);
			cin  >> q -> P.precio_venta_kg ;
						
			q -> P.precio_total = q -> P.cantidad_kg * q -> P.precio_venta_kg ;	
					
			system ( "CLS" ) ;			
   			break ;
   		case 2:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_b ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 5);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [1] <<" DE "<< q -> nombres<<" "<< q -> apellidos<<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			q -> D.desechos = "\n\n\t\t\t\t\t  - DESECHOS ORGANICOS (MORADO) \n" ;
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;				fflush(stdin);
			cin  >> q -> P.cantidad_kg ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;				fflush(stdin);
			cin  >> q -> P.precio_venta_kg ;
						
			q -> P.precio_total = q -> P.cantidad_kg * q -> P.precio_venta_kg ;	
					
			system ( "CLS" ) ;			
   			break ;
		case 3:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_b ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 2);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [2] <<" DE "<< q -> nombres<<" "<< q -> apellidos<<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			q -> D.desechos = "\n\n\t\t\t\t\t  - DESECHOS VIDRIOS (VERDE) \n";
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;				fflush(stdin);
			cin  >> q -> P.cantidad_kg ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;				fflush(stdin);
			cin  >> q -> P.precio_venta_kg ;
						
			q -> P.precio_total = q -> P.cantidad_kg * q -> P.precio_venta_kg ;	
					
			system ( "CLS" ) ;			
   			break ;
		case 4:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_b ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 6);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [3] <<" DE "<< q -> nombres<<" "<< q -> apellidos<<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			q -> D.desechos = "\n\n\t\t\t\t\t  - DESECHOS PLASTICOS Y ENVASES METALICOS (AMARILLO)\n" ;
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;				fflush(stdin);
			cin  >> q -> P.cantidad_kg ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;				fflush(stdin);
			cin  >> q -> P.precio_venta_kg ;
						
			q -> P.precio_total = q -> P.cantidad_kg * q -> P.precio_venta_kg ;	
					
			system ( "CLS" ) ;			
   			break ;
		case 5:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_b ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 1);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [4] <<" DE "<< q -> nombres<<" "<< q -> apellidos<<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			q -> D.desechos = "\n\n\t\t\t\t\t  - DESECHOS PAPEL (AZUL)\n";
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;				fflush(stdin);
			cin  >> q -> P.cantidad_kg ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;				fflush(stdin);
			cin  >> q -> P.precio_venta_kg ;
						
			q -> P.precio_total = q -> P.cantidad_kg * q -> P.precio_venta_kg ;	
					
			system ( "CLS" ) ;			
   			break ; 
		case 6:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_b ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 4);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [5] <<" DE "<< q -> nombres<<" "<< q -> apellidos<<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			q -> D.desechos = "\n\n\t\t\t\t\t  - DESECHOS PELIGROSOS (ROJO)\n";
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;				fflush(stdin);
			cin  >> q -> P.cantidad_kg ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;				fflush(stdin);
			cin  >> q -> P.precio_venta_kg ;
						
			q -> P.precio_total = q -> P.cantidad_kg * q -> P.precio_venta_kg ;	
					
			system ( "CLS" ) ;			
   			break ;   		
   		}
   	SOLO_TITULO();
   	titulo_b () ;
	cout<<"\n\t\t\t\t\t"<<char(175)<<char(175)<<" El reciclador ha sido agregado al registro";

    //Actualización de la lista con los nuevos datos del reciclador ANTES o DESPUÉS de la posición indicada
    if ( ( pos > 0 ) && ( pos <= numero_recicladores + 1 ) )
   	{
		if ( ( ( deter == 'A') || ( deter == 'a' ) ) && ( pos == 1 ) ) //Añadir antes del primer reciclador
    	{
        	q -> siguiente = primero ;
        	q -> anterior = NULL ;
        	q -> siguiente -> anterior = q ;
        	primero = q ;
		}
    	else
    	{
        	if ( ( ( deter == 'D' ) || ( deter == 'd' ) ) && ( pos == 1 ) ) //Añadir después del primer reciclador
				{
				q -> siguiente = primero -> siguiente ;
        		q -> anterior = primero ;
        		q -> siguiente -> anterior = q ;
        		primero -> siguiente = q ;	
				}
			else 
				{
				t = primero ; 
 
        		for ( int i = 1 ; primero != NULL ; i = i + 1 )
            	{    
            		if ( ( ( deter == 'A') || ( deter == 'a' ) ) && ( i == pos - 1 ) ) // Para pos != del primero añade antes
					{			
						q -> siguiente = t -> siguiente;
						q -> anterior = t ;
           				q -> siguiente -> anterior = q ;
           				t -> siguiente = q ;
           				break ;
           			}
           			if ( ( ( deter == 'D') || ( deter == 'd' ) ) && ( i == pos ) ) // Para pos != del primero añade después
					{			
						q -> siguiente = t -> siguiente;
						q -> anterior = t ;
						if (q -> siguiente != NULL )
				       		q -> siguiente -> anterior = q ;
           				t -> siguiente = q ;       	
						break ;
           			}           			
           		t = t -> siguiente ;
           		}           		
           		}        
        }
        numero_recicladores = numero_recicladores + 1 ;
    }   
}

void eliminar_reciclador ( int num_dni_eliminar_recicla ) //Función que elimina un reciclador de la lista
{
		int i=1, k=0;//k=bandera i=iterador		 
		
		recicladores *eliminar_r = new recicladores();
		recicladores *eliminar_r_m = new recicladores();
		
		
		SOLO_TITULO();
		cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS DOMICILIARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
		cout << "\t\t\t\t   || ELIMINAR DATOS DE UN RECICLADOR EN ESPEC"<<char(214)<<"FICO || \n\n\n" ;
		
		if (primero != NULL)
		{
			eliminar_r  = primero;
			
			while(eliminar_r != NULL)
			{
				if(eliminar_r->dni == num_dni_eliminar_recicla)//busca el dni en la lista
				{
					if(eliminar_r == primero)	
						{
						primero = primero->siguiente;
						delete (eliminar_r);//elimina el nodo que contiene el dni
						eliminar_r = primero;
						k=1;					
						}
					else
						{
						eliminar_r ->anterior->siguiente = eliminar_r ->siguiente;
						if (eliminar_r ->siguiente!= NULL)
							eliminar_r ->siguiente->anterior = eliminar_r ->anterior;
						eliminar_r_m = eliminar_r ;
						eliminar_r  = eliminar_r ->siguiente;
						delete(eliminar_r_m);//elimina el nodo que contiene el dni
						k=1;
						}	
				}
				else
				{
				eliminar_r = eliminar_r->siguiente;//actualiza al siguiente nodo
				}								
			}
		}

		if(k==0)//evalua si no existe ningun dni igual al ingresado.
			{
			cout<<"\t\t\t\t  "<<char(175)<<char(175)<<"	El n\xA3mero de DNI del reciclador no fue encontrado."<<endl;
			}
		else
			{
			cout<<"\t\t\t\t  "<<char(175)<<char(175)<<"	El reciclador ha sido eliminado.";
			numero_recicladores	= numero_recicladores - 1; //actualiza # de recicladores
			}				
}

void contribucion_reciclador ( int contribucion_dni_reciclador )//Función que muestra la contribución de un reciclador según dni
{
		int i=1, k=0;//k=bandera i=iterador		 
		
		recicladores *contribucion_r = new recicladores();
		contribucion_r = primero;
		
		SOLO_TITULO();//Pertenece a la libreria TITULO.h
		cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS DOMICILIARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
		cout << "\t\t\t || CONTRIBUCI"<<char(224)<<"N AL MEDIO AMBIENTE DE UN RECICLADOR EN ESPEC"<<char(214)<<"FICO || \n\n" ;
		
		if(primero != NULL)
		{
			do
			{
				if(contribucion_r->dni == contribucion_dni_reciclador)//busca el dni en la lista
				{
				cout <<"\n\n\t\t\t\t -| DATOS PERSONALES DEL RECICLADOR " << i << " |- \n";
        		cout <<"\n\t\t\t	    Nombres y apellidos : " << contribucion_r -> nombres<<" "<<contribucion_r -> apellidos ;
        		cout <<"\n\t\t\t	    N"<<char(167)<<" DNI              : " << contribucion_r -> dni ;
				cout <<"\n\t\t\t	    Direcci\xA2n           : " << contribucion_r -> direccion.calle<<" "<< contribucion_r -> direccion.numero<<" "<< contribucion_r->direccion.urbanizacion ;
			
				cout << contribucion_r  -> D.desechos;
			
				cout << "\n\t\t\t\t	    CANTIDAD (Kg.)\t  PRECIO - VENTA(S/.)\t  TOTAL(S/.)\n " ;
				cout << "\n\t\t\t\t\t	    "<< contribucion_r -> P.cantidad_kg <<"\t\t\t  " ;
    			cout << contribucion_r  -> P.precio_venta_kg	<<" \t\t     " ;
    			cout << contribucion_r  -> P.precio_total	;
    			
    			cout << "\n\n\t\t\t\t  | CONTRIBUCION AL MEDIO AMBIENTE DE "<<contribucion_r -> nombres<<" "<<contribucion_r -> apellidos<<" |"  ;
    			if ( contribucion_r  -> P.precio_total > 0 )
				{ 
				cout << "\n\n\t\t\t\t\t\t   Contribuci\xA2n POSITIVA" ;
				cout << "\n\n\t\t\t            Usted pertenece al 3% de los Peruanos que RECICLA." ; 
				cout << "\n\t\t\t Gracias por apoyar LA REDUCCI"<<char(224)<<"N DE LA CONTAMINACION del Pa"<<char(161)<<"s y del Planeta. " ;
				}
				else
				{
				cout << "\n\n\t\t\t\t\t\t   Contribuci\xA2n NEGATIVA" ;
				cout << "\n\n\t\t\t            Usted pertenece al % de Peruanos que NO RECICLA." ;
				cout << "\n\t\t\t\t Reciclar no es una obligaci\xA2n, es una responsabilidad. \n\t\t\t LA REDUCCI"<<char(224)<<"N DE LA CONTAMINACION del Pa"<<char(161)<<"s y del Planeta depende de ti. " ;	
				}
    			k=1;
				}
			contribucion_r = contribucion_r->siguiente;//actualiza al siguiente nodo
			i=i+1;	
			}
			while((contribucion_r != NULL) && (k==0));
			if(k==0)//evalua si no existe ningun dni igual al ingresado.
			{
			cout<<"\n El reciclador no fue encontrado."<<endl;
			}					
		}			 
}
	
void menu_principal_domiciliarios ()
{
	do {
	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS DOMICILIARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
    cout << "\t\t\t 1. REGISTRAR DATOS PERSONALES Y TIPO DE DESECHO DEL RECICLADOR\n\n" ;
    cout << "\t\t\t 2. REGISTRO TOTAL DE LOS RECICLADORES Y TIPO DE DESECHO - DE INICIO A FIN  \n\n" ;
    cout << "\t\t\t 3. REGISTRO TOTAL DE LOS RECICLADORES Y TIPO DE DESECHO - DE FIN A INICIO  \n\n" ;
    cout << "\t\t\t 4. REGISTRO ESPEC"<<char(214)<<"FICO DE UN RECICLADOR Y TIPO DE DESECHO \n\n" ;
    cout << "\t\t\t 5. RECICLADOR CON MAYOR VENTA									\n\n" ;
	cout << "\t\t\t 6. RECICLADOR CON MENOR VENTA									\n\n" ;
	cout << "\t\t\t 7. AGREGAR NUEVO RECICLADOR AL REGISTRO						\n\n" ;
	cout << "\t\t\t 8. ELIMINAR DATOS DE UN RECICLADOR EN ESPEC"<<char(214)<<"FICO\n\n" ;  
	cout << "\t\t\t 9. CONTRIBUCI"<<char(224)<<"N AL MEDIO AMBIENTE DE UN RECICLADOR EN ESPEC"<<char(214)<<"FICO	\n\n" ;
	cout << "\t\t\t10. ATR"<<char(181)<<"S                                    	\n\n" ;
    cout << "\t\t\t11. SALIR                                    					\n\n" ;
    cout << "\t\t	 "<<char(175)<<char(175)<<" Digite una opci\xA2n : " ;
    cin  >> elegir ;														
	system ( "CLS" ) ;
   
	switch ( elegir )
    {
        case 1: // Registrar recicladores
        	SOLO_TITULO();//Pertenece a la libreria TITULO.h
            do { 
            titulo_a () ;
			cout << "\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de recicladores que registrar\xA0: ";
			cin  >> numero_recicladores ;
			system ( "CLS" ) ;
			} while ( numero_recicladores < 1 ) ;			
			regis_recicladores ( numero_recicladores ) ;//Función que registra recicladores
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
            titulo_a ();
			retorna_principal () ;//Regresa al menú domiciliario
            break;
        case 2: // Registro total - INICIO A FIN  
        	SOLO_TITULO();//Pertenece a la libreria TITULO.h
            cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS DOMICILIARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t|| REGISTRO TOTAL DE LOS RECICLADORES Y TIPO DE DESECHO - DE INICIO A FIN || \n\n" ;
			ver_recicladores ( numero_recicladores ) ;//Función que muestra recicladores
            retorna_principal () ;//Regresa al menú domiciliario
			break;
		case 3: // Registro total - FIN A INICIO
        	SOLO_TITULO();//Pertenece a la libreria TITULO.h
            cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS DOMICILIARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t|| REGISTRO TOTAL DE LOS RECICLADORES Y TIPO DE DESECHO - DE FIN A INICIO || \n\n" ;
			ver_recicladores_fi () ;//Función que muestra recicladores	   
            retorna_principal () ;//Regresa al menú domiciliario
			break;
		case 4: // Registro especifico de un reciclador según dni
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
        	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS DOMICILIARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t|| REGISTRO ESPEC"<<char(214)<<"FICO DE UN RECICLADOR Y TIPO DE DESECHO || \n\n\n" ;
            cout << "\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de DNI del reciclador a buscar: ";					fflush(stdin);
            do {
			cin  >> numero_dni ;
			} while ( numero_dni < 10000000 || numero_dni > 99999999 ) ;									
			system ( "CLS" ) ;
            dni_un_reciclador ( numero_dni ) ;//Función que muestra un reciclador segun dni		          
			retorna_principal () ;//Regresa al menú domiciliario
            break;
		case 5: // Reciclador con mayor venta 
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
        	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS DOMICILIARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t\t     || RECICLADOR CON MAYOR VENTA || \n\n\n" ;
			mayor_venta ( numero_recicladores ) ;//Función que muestra la mayor venta
			retorna_principal () ;//Regresa al menú domiciliario
			break;
		case 6:	// Reciclador con menor venta   
      		SOLO_TITULO();//Pertenece a la libreria TITULO.h
        	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS DOMICILIARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t\t     || RECICLADOR CON MENOR VENTA || \n\n\n" ;
			menor_venta ( numero_recicladores ) ;//Función que muestra la menor venta
			retorna_principal () ;//Regresa al menú domiciliario
			break;	  
        case 7: // Añadir otro reciclador a la lista
        	SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_b ();
			cout << "\t\t\t\t "<<char(175)<<char(175)<<" Digite el n\xA3mero de la posici\xA2n del reciclador que agregar\xA0: " ;
			do { cin  >>  posicion ; 
			} while ( ( posicion < 1 ) && ( posicion > numero_recicladores ) ) ;
			anadir_nuevo_reciclador ( posicion ) ;//Función que añade un reciclador más
			retorna_principal () ;//Regresa al menú domiciliario
            break; 	
		case 8: // Eliminar un reciclador según dni
        	SOLO_TITULO();//Pertenece a la libreria TITULO.h
        	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS DOMICILIARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t   || ELIMINAR DATOS DE UN RECICLADOR EN ESPEC"<<char(214)<<"FICO || \n\n\n" ;
			cout << "\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de DNI del reciclador a eliminar: ";					fflush(stdin);
            do {
            cin  >> numero_dni ;
			} while ( numero_dni < 10000000 || numero_dni > 99999999 ) ;									
			system ( "CLS" ) ;
			eliminar_reciclador ( numero_dni ) ;//Función que elimina un reciclador de la lista
			retorna_principal () ;//Regresa al menú domiciliario
			break;
		case 9: // Contribución
        	SOLO_TITULO();//Pertenece a la libreria TITULO.h
            cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS DOMICILIARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t	      || CONTRIBUCI"<<char(224)<<"N AL MEDIO AMBIENTE DE UN RECICLADOR EN ESPEC"<<char(214)<<"FICO || \n\n\n" ;
			cout << "\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de DNI de un reciclador: ";					fflush(stdin);
            do {
            cin  >> numero_dni;	
			} while ( numero_dni < 10000000 || numero_dni > 99999999 ) ;								
			system ( "CLS" ) ;
            contribucion_reciclador ( numero_dni );	//Función que muestra la contribución de un reciclador según dni	          
			retorna_principal () ;//Regresa al menú domiciliario
            break;
        case 10: // Atrás
        	interfaz_secundaria ();
        	break;
    }
    } while ( (elegir <1) || ( elegir > 10 ) );
}

void RES_DOMICILIOS()
{
	menu_principal_domiciliarios () ;
}
//------------------------------------------------------- fin menú domiciliarios-----------------------------------------------------------------
//MENÚ MUNICIPALES
    void 	menu_principal_municipalidades () ;
	int 	numero_codigo_m, elegir_m, regresar_m, opc_m, posicion_m, numero_municipalidades = 0;
	char	deter_m ;
	
struct info_ubicacion {
	char 	distrito [30] ;
	char  	provincia [30] ;
	char 	departamento [30] ;	
} ;

struct info_desechos_m {
	int	 	cantidad_kg ;
	float  	precio_venta_kg ;
	float   precio_total ;
};

struct desechos_m {
	string	desechos ;
};

struct municipalidades{
    int   	codigo ;
	char   	denominacion [50] ;
	struct 	info_ubicacion ubicacion ;
	struct 	info_desechos_m P ; 
	struct  desechos_m D ;
	struct 	municipalidades *anterior_m ;
	struct 	municipalidades *siguiente_m ;						
}*primero_m;

string desechos_m [6] = { "EN GENERAL (GRIS)", "ORGANICOS (MORADO)",	"VIDRIOS (VERDE)", 
						"PLASTICOS Y ENVASES METALICOS (AMARILLO)",	"PAPEL (AZUL)", "PELIGROSOS (ROJO)"};

void titulo_a_m ()
{
	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS MUNICIPALES "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
	cout << "\t\t\t\t     || REGISTRAR DATOS Y TIPO DE DESECHO DE LA MUNICIPALIDAD || \n\n" ;
}

void titulo_b_m ()
{
	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS MUNICIPALES "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
	cout << "\t\t\t	|| AGREGAR NUEVA MUNICIPALIDAD AL REGISTRO || \n\n" ;
}

void retorna_principal_m ()//Regresa al menú domiciliario
{
    cout << "\n\n\n\t\t\t      Digite | 1 | para regresar al "<<char(174)<<"| MENé RESIDUOS MUNICIPALES |"<<char(175)<<" \n\n" ;
    cout << "\n\t\t\t\t\t        Digite | 0 | para "<<char(174)<<"| SALIR |"<<char(175) ;
    do
    {
	cout <<" \n\n\t\t\t\t\t\t\t "<<char(174)<<char(175)<<" " ;
	cin  >> regresar_m ; 	
	} while ( regresar_m != 1 && regresar_m != 0 );		
	system ( "CLS" ) ;
	
	if ( regresar_m == 1 ) 
		{
		SOLO_TITULO();//Pertenece a la libreria TITULO.h
		menu_principal_municipalidades () ;
		}
}

void regis_recicladores_m ( int n_c )//Función que registra recicladores
{
	for ( int i = 0; i < n_c; i = i + 1 ) // n_c=numero de recicladores
    {    	
    municipalidades *nuevo = new municipalidades ();
	municipalidades *nuevo_1 = new municipalidades ();
	
	SOLO_TITULO();//Pertenece a la libreria TITULO.h
	titulo_a_m ();
	
    cout << "\n\t\t\t\t\t      | REGISTRO DE MUNICIPALIDADES | \n" ;
	cout << "\n\t\t\t\t\t       ---  MUNICIPALIDAD N"<<char(167)<<" " << i+1 << "  --- \n\n" ; 	fflush(stdin);
	cout << "\n\t\t\t\t|- Datos Municipales -| \n\n" ; 
	do {
	cout << "\t\t\t\t~~ Digite el n\xA3mero del CODIGO de la Municipalidad: "; 					fflush(stdin);
	cin  >> nuevo -> codigo;	
	} while ( nuevo -> codigo < 100000 || nuevo -> codigo > 999999 ) ;				 
	cout << "\t\t\t\t~~ Digite la Denominaci\xA2n de la Municipalidad : ";						fflush(stdin);
	cin.getline ( nuevo -> denominacion,50,'\n' ) ;
	cout << "\n\n\t\t\t\t|- Ubicaci\xA2n de la Municipalidad -| \n\n"; 											
	cout << "\t\t\t\t~~ Digite el distrito al que pertenece    : ";								fflush(stdin);
	cin.getline ( nuevo -> ubicacion.distrito,30,'\n' ) ;   	
	cout << "\t\t\t\t~~ Digite la provincia al que pertenece   : ";							    fflush(stdin);
	cin.getline (nuevo -> ubicacion.provincia,30,'\n' ) ; 				  		
	cout << "\t\t\t\t~~ Digite el departamento al que pertenece: "; 							fflush(stdin);
	cin.getline ( nuevo -> ubicacion.departamento,30,'\n');
			
	system ("CLS");
	SOLO_TITULO();
	titulo_a_m ();
	
	cout << "\n\t\t\t\t| REGISTRO DE TIPO DE DESECHOS RECICLADOS DE LA "<< nuevo -> denominacion <<" | \n\n\n" ;
	cout << "\t\t\t\t\t  1. DESECHOS EN GENERAL (GRIS) \n\n" ;
    cout << "\t\t\t\t\t  2. ORG"<<char(181)<<"NICOS (MORADO) \n\n" ;
    cout << "\t\t\t\t\t  3. VIDRIOS (VERDE) \n\n";
    cout << "\t\t\t\t\t  4. PL"<<char(181)<<"STICOS Y ENVASES MET"<<char(181)<<"LICOS (AMARILLO) \n\n" ;
    cout << "\t\t\t\t\t  5. PAPEL (AZUL) \n\n";
    cout << "\t\t\t\t\t  6. DESECHOS PELIGROSOS (ROJO) \n\n";
    cout << "\n\t\t\t\t  "<<char(175)<<char(175)<<" Digite una opci\xA2n : ";
    do{
	cin  >> opc_m;
	} while ( opc_m < 1 && opc_m > 6 );
	    
    system ( "CLS" );    
	
	switch  ( opc_m )
		{
		case 1:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_a_m ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 8);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [0] <<" DE LA "<< nuevo -> denominacion <<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			nuevo -> D.desechos = "\n\n\t\t\t\t\t  - DESECHOS EN GENERAL (GRIS) \n";
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;				fflush(stdin);
			cin  >> nuevo -> P.cantidad_kg ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;				fflush(stdin);
			cin  >> nuevo -> P.precio_venta_kg ;
						
			nuevo -> P.precio_total = nuevo -> P.cantidad_kg * nuevo -> P.precio_venta_kg ;	
					
			system ( "CLS" ) ;			
   			break ;
   		case 2:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_a_m ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 5);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [1] <<" DE LA "<< nuevo -> denominacion <<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			nuevo -> D.desechos = "\n\n\t\t\t\t\t  - DESECHOS ORGANICOS (MORADO) \n" ;
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;				fflush(stdin);
			cin  >> nuevo -> P.cantidad_kg ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;				fflush(stdin);
			cin  >> nuevo -> P.precio_venta_kg ;
						
			nuevo -> P.precio_total = nuevo -> P.cantidad_kg * nuevo -> P.precio_venta_kg ;	
					
			system ( "CLS" ) ;			
   			break ;
		case 3:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_a_m ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 2);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [2] <<" DE LA "<< nuevo -> denominacion <<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			nuevo -> D.desechos = "\n\n\t\t\t\t\t  - DESECHOS VIDRIOS (VERDE) \n";
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;				fflush(stdin);
			cin  >> nuevo -> P.cantidad_kg ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;				fflush(stdin);
			cin  >> nuevo -> P.precio_venta_kg ;
						
			nuevo -> P.precio_total = nuevo -> P.cantidad_kg * nuevo -> P.precio_venta_kg ;	
					
			system ( "CLS" ) ;			
   			break ;
		case 4:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_a_m ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 6);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [3] <<" DE LA "<< nuevo -> denominacion <<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			nuevo -> D.desechos = "\n\n\t\t\t\t\t  - DESECHOS PLASTICOS Y ENVASES METALICOS (AMARILLO)\n" ;
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;				fflush(stdin);
			cin  >> nuevo -> P.cantidad_kg ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;				fflush(stdin);
			cin  >> nuevo -> P.precio_venta_kg ;
						
			nuevo -> P.precio_total = nuevo -> P.cantidad_kg * nuevo -> P.precio_venta_kg ;	
					
			system ( "CLS" ) ;			
   			break ;
		case 5:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_a_m ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 1);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [4] <<" DE LA "<< nuevo -> denominacion <<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			nuevo -> D.desechos = "\n\n\t\t\t\t\t  - DESECHOS PAPEL (AZUL)\n";
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;				fflush(stdin);
			cin  >> nuevo -> P.cantidad_kg ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;				fflush(stdin);
			cin  >> nuevo -> P.precio_venta_kg ;
						
			nuevo -> P.precio_total = nuevo -> P.cantidad_kg * nuevo -> P.precio_venta_kg ;	
					
			system ( "CLS" ) ;			
   			break ; 
		case 6:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_a_m ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 4);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [5] <<" DE LA "<< nuevo -> denominacion <<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			nuevo -> D.desechos = "\n\n\t\t\t\t\t  - DESECHOS PELIGROSOS (ROJO)\n";
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;				fflush(stdin);
			cin  >> nuevo -> P.cantidad_kg ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;				fflush(stdin);
			cin  >> nuevo -> P.precio_venta_kg ;
						
			nuevo -> P.precio_total = nuevo -> P.cantidad_kg * nuevo -> P.precio_venta_kg ;	
					
			system ( "CLS" ) ;			
   			break ;    		
   		}
				   				
		// actualizar reciclador
		nuevo -> siguiente_m = NULL ; 
			
		if (primero_m != NULL)
		{
			nuevo_1 = primero_m;
			while (nuevo_1->siguiente_m != NULL)
			{
				nuevo_1 = nuevo_1->siguiente_m;
			}
			nuevo_1->siguiente_m = nuevo;
			nuevo->anterior_m = nuevo_1;			
		}	
		else
		{
			primero_m = nuevo;
			nuevo->anterior_m = NULL;	
		}
	}
}

void ver_recicladores_m ( int numero_municipalidades ) // ver municipalidades de Inicio a Fin
{
   	municipalidades *ver_r = new municipalidades();
	
	float precio_global = 0, Kg_global = 0;
	ver_r = primero_m;	
			
    for ( int i = 0 ; i < numero_municipalidades ; i = i + 1 ) 
    	{
			cout <<"\n\n\t\t\t\t -| DATOS DE LA MUNICIPALIDAD " << i+1 << " |- \n";	
			cout <<"\n\t\t\t	    Denominaci\xA2n: " << ver_r -> denominacion ;
        	cout <<"\n\t\t\t	    N"<<char(167)<<" CODIGO   : " <<ver_r -> codigo ;
			cout <<"\n\t\t\t	    Ubicaci\xA2n   : " << ver_r -> ubicacion.distrito <<" "<<ver_r -> ubicacion.provincia <<" "<< ver_r -> ubicacion.departamento ;
			
			cout << ver_r -> D.desechos;
			
			cout << "\n\t\t\t\t	    CANTIDAD (Kg.)\t  PRECIO - VENTA(S/.)\t  TOTAL(S/.)\n " ;
			cout << "\n\t\t\t\t\t	    "<< ver_r -> P.cantidad_kg <<"\t\t\t  " ;
    		cout << ver_r -> P.precio_venta_kg	<<" \t\t     " ;
    		cout << ver_r -> P.precio_total	;
			
			Kg_global = Kg_global +	ver_r -> P.cantidad_kg ;
			precio_global = precio_global +	ver_r -> P.precio_total ;
			
			ver_r = ver_r -> siguiente_m ;      
        }
	cout << "\n\n\t\t\t\t __________________________________________________________________________ \n" ;
	cout << "\n\n\t\t\t\t -| RESULTADOS FINALES DE LAS "<< numero_municipalidades <<" MUNICIPALIDADES |- \n";
	cout << "\n\t\t\t\t	    CANTIDAD GLOBAL (Kg.) \t\t\t TOTAL GLOBAL (S/.)" ;
	cout << "\n\n\t\t\t\t\t	    "<< Kg_global << " \t\t\t\t\t\t"<< precio_global ;
}

void ver_recicladores_fi_m () // ver municipalidades de Fin a Inicio
{
	municipalidades *a = new municipalidades () ;
	float precio_global = 0, Kg_global = 0;
    
	a = primero_m ;
    while ( a -> siguiente_m != NULL )
        a = a -> siguiente_m ;
    while ( a != NULL )
    {
	    for ( int i = 0 ; i < numero_municipalidades ; i = i + 1 ) 
    	{
   		cout <<"\n\n\t\t\t\t -| DATOS DE LA MUNICIPALIDAD " << numero_municipalidades - i << " |- \n";	
		cout <<"\n\t\t\t	    Denominaci\xA2n : " << a -> denominacion ;
        cout <<"\n\t\t\t	    N"<<char(167)<<" CODIGO   : " << a -> codigo ;
		cout <<"\n\t\t\t	    Ubicaci\xA2n   : " << a -> ubicacion.distrito <<" "<<a -> ubicacion.provincia <<" "<< a -> ubicacion.departamento ;
					
		cout << a -> D.desechos;
			
		cout << "\n\t\t\t\t	    CANTIDAD (Kg.)\t  PRECIO - VENTA(S/.)\t  TOTAL(S/.)\n " ;
		cout << "\n\t\t\t\t\t	    "<< a -> P.cantidad_kg <<"\t\t\t  " ;
    	cout << a -> P.precio_venta_kg	<<" \t\t     " ;
    	cout << a -> P.precio_total	;
			
		Kg_global = Kg_global +	a -> P.cantidad_kg ;
		precio_global = precio_global +	a -> P.precio_total ;
				        
        a = a -> anterior_m ;        	
		}
		cout << "\n\n\t\t\t\t __________________________________________________________________________ \n" ;
		cout << "\n\n\t\t\t\t -| RESULTADOS FINALES DE LAS "<< numero_municipalidades <<" MUNICIPALIDADES |- \n";
		cout << "\n\t\t\t\t	    CANTIDAD GLOBAL (Kg.) \t\t\t TOTAL GLOBAL (S/.)" ;
		cout << "\n\n\t\t\t\t\t	    "<< Kg_global << " \t\t\t\t\t\t"<< precio_global ;		
    }
}   	

void codigo_un_reciclador_m ( int num_codigo_recicla )// Muestra el registro de un reciclador y desecho según codigo.
{
		int i=1, k=0;//k=bandera i=iterador		 
		
		municipalidades *codigo_r = new municipalidades();
		codigo_r = primero_m;
		
		SOLO_TITULO();
		cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS MUNICIPALES "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
		cout << "\t\t\t\t|| REGISTRO ESPEC"<<char(214)<<"FICO DE UA MUNICIPALIDAD Y TIPO DE DESECHO || \n\n\n" ;
		
		if(primero_m != NULL)
		{
			do
			{
				if(codigo_r->codigo == num_codigo_recicla)// evalua la igualdad entre el codigo ingresado con los registrados.
				{
				cout <<"\n\t\t\t\t -| DATOS DE LA MUNICIPALIDAD " << i << " |- \n";	
				cout <<"\n\t\t\t	    Denominaci\xA2n : " << codigo_r -> denominacion ;
        		cout <<"\n\t\t\t	    N"<<char(167)<<" CODIGO   : " <<codigo_r -> codigo ;
				cout <<"\n\t\t\t	    Ubicaci\xA2n   : " << codigo_r -> ubicacion.distrito <<" "<<codigo_r-> ubicacion.provincia <<" "<< codigo_r -> ubicacion.departamento ;
			
				cout << codigo_r  -> D.desechos;
			
				cout << "\n\t\t\t\t	    CANTIDAD (Kg.)\t  PRECIO - VENTA(S/.)\t  TOTAL(S/.)\n " ;
				cout << "\n\t\t\t\t\t	    "<< codigo_r -> P.cantidad_kg <<"\t\t\t  " ;
    			cout << codigo_r  -> P.precio_venta_kg	<<" \t\t     " ;
    			cout << codigo_r  -> P.precio_total	;
    			k=1;
				}
			codigo_r = codigo_r->siguiente_m;//actualiza al siguiente nodo
			i=i+1;	
			} while((codigo_r != NULL) && (k==0));
			
			if(k==0)//evalua si no existe ningun codigo igual al ingresado en el registro.
			{
			cout<<"\n\t\t\t\t\t"<<char(175)<<char(175)<<" La municipalidad no fue encontrada."<<endl;
			}					
		}			 
}

void mayor_venta_m ( int numero_municipalidades ) //Función que muestra la mayor venta
{
		int i=1, k=0;//k=bandera
		
		float mayor;
						 
		municipalidades *may_venta_r = new municipalidades();
		municipalidades *may_venta_reciclador = new municipalidades();
		
		may_venta_r = primero_m ;
		may_venta_reciclador = primero_m ;
		
		mayor=may_venta_r  -> P.precio_total;
		
		for (int i=0; i<numero_municipalidades; i=i+1)
    	{		
			if (may_venta_r  -> P.precio_total > mayor)
			{
			mayor=may_venta_r  -> P.precio_total;
			}
			may_venta_r  = may_venta_r->siguiente_m;//actualiza al siguiente nodo
		}
				
		if(primero_m != NULL)
		{
			do
			{
				if(may_venta_reciclador->P.precio_total == mayor)//busca el precio total y muestra datos
				{
				cout <<"\n\t\t\t\t -| DATOS DE LA MUNICIPALIDAD " << i << " |- \n";	
				cout <<"\n\t\t\t	    Denominaci\xA2n: " << may_venta_reciclador -> denominacion ;
        		cout <<"\n\t\t\t	    N"<<char(167)<<" CODIGO   : " << may_venta_reciclador -> codigo ;
				cout <<"\n\t\t\t	    Ubicaci\xA2n   : " << may_venta_reciclador -> ubicacion.distrito <<" "<< may_venta_reciclador-> ubicacion.provincia <<" "<< may_venta_reciclador -> ubicacion.departamento ;
						
				cout << may_venta_reciclador  -> D.desechos;
			
				cout << "\n\t\t\t\t	    CANTIDAD (Kg.)\t  PRECIO - VENTA(S/.)\t  TOTAL(S/.)\n " ;
				cout << "\n\t\t\t\t\t	    "<< may_venta_reciclador -> P.cantidad_kg <<"\t\t\t  " ;
    			cout << may_venta_reciclador  -> P.precio_venta_kg	<<" \t\t     " ;
    			cout << may_venta_reciclador  -> P.precio_total	;
    			cout << "\n\n\t\t\t\t\t     | ~ MAYOR VENTA (S/.) ~ | ---------------------| "<<mayor<<" |";
    		 	k=1;
				}
			may_venta_reciclador = may_venta_reciclador->siguiente_m;//actualiza al siguiente nodo
			i=i+1;	
			}
			while((may_venta_reciclador != NULL) && (k==0));					
		}			 
}

void menor_venta_m ( int numero_municipalidades ) //Función que muestra la menor venta
{
		int i=1, k=0;//k=bandera i=iterador
		
		float menor;
						 
		municipalidades *men_venta_r = new municipalidades();
		municipalidades *men_venta_reciclador = new municipalidades();
		
		men_venta_r = primero_m;
		men_venta_reciclador = primero_m;
		
		menor=men_venta_r  -> P.precio_total;
		
		for (int i=0; i<numero_municipalidades; i=i+1)
    	{		
			if (men_venta_r  -> P.precio_total < menor)
			{
			menor = men_venta_r  -> P.precio_total;
			}
			men_venta_r  = men_venta_r->siguiente_m;
		}
				
		if(primero_m != NULL)
		{
			do
			{
				if(men_venta_reciclador->P.precio_total == menor)//busca el precio total y muestra datos
				{
				cout <<"\n\t\t\t\t -| DATOS DE LA MUNICIPALIDAD " << i << " |- \n";	
				cout <<"\n\t\t\t	    Denominaci\xA2n: " << men_venta_reciclador -> denominacion ;
        		cout <<"\n\t\t\t	    N"<<char(167)<<" CODIGO   : " << men_venta_reciclador -> codigo ;
				cout <<"\n\t\t\t	    Ubicaci\xA2n   : " << men_venta_reciclador -> ubicacion.distrito <<" "<< men_venta_reciclador-> ubicacion.provincia <<" "<< men_venta_reciclador -> ubicacion.departamento ;
			
				cout << men_venta_reciclador  -> D.desechos;
			
				cout << "\n\t\t\t\t	    CANTIDAD (Kg.)\t  PRECIO - VENTA(S/.)\t  TOTAL(S/.)\n " ;
				cout << "\n\t\t\t\t\t	    "<< men_venta_reciclador -> P.cantidad_kg <<"\t\t\t  " ;
    			cout << men_venta_reciclador  -> P.precio_venta_kg	<<" \t\t     " ;
    			cout << men_venta_reciclador  -> P.precio_total	;
    			cout << "\n\n\t\t\t\t\t     | ~ MENOR VENTA (S/.) ~ | ---------------------| "<<menor<<" |";
    		 	k=1;
				}
			men_venta_reciclador = men_venta_reciclador->siguiente_m;//actualiza al siguiente nodo
			i=i+1;	
			}
			while((men_venta_reciclador != NULL) && (k==0));					
		}			 
}

void anadir_nuevo_reciclador_m ( int pos ) //Función que añade un municipalidad más (antes o después)
{
	municipalidades *q = new municipalidades () ;	
    municipalidades *t = new municipalidades () ;
		
	cout << "\n\n\t\t\t\t   ~ Digite 'D', si agregara - DESPUES - de la posici\xA2n | " << pos << " |" ;
	cout << "\n\n\t\t\t\t   ~ Digite 'A', si agregara - ANTES - de la posici\xA2n | " << pos << " | " ;
	do {
		cout << "\n\n\t\t\t\t\t\t\t"<<char(174)<<char(175)<< " " ;
		cin  >> deter ;
	} while ( deter != 'A' &&  deter != 'a' && deter != 'D' && deter != 'd' ) ;
	
	system ("CLS");
	SOLO_TITULO();
	titulo_b_m ();
	
	cout << "\n\t\t\t\t|- Datos Municipales -| \n\n" ; 
	do {
	cout << "\t\t\t\t~~ Digite el n\xA3mero del CODIGO de la Municipalidad: "; 					fflush(stdin);
	cin  >> q -> codigo;	
	} while ( q -> codigo < 100000 || q -> codigo > 999999 ) ;				 
	cout << "\t\t\t\t~~ Digite la Denominaci\xA2n de la Municipalidad : ";						fflush(stdin);
	cin.getline ( q -> denominacion,50,'\n' ) ;
	cout << "\n\n\t\t\t\t|- Ubicaci\xA2n de la Municipalidad -| \n\n"; 											
	cout << "\t\t\t\t~~ Digite el distrito al que pertenece    : ";								fflush(stdin);
	cin.getline ( q -> ubicacion.distrito,30,'\n' ) ;   	
	cout << "\t\t\t\t~~ Digite la provincia al que pertenece   : ";							    fflush(stdin);
	cin.getline  ( q -> ubicacion.provincia,30,'\n' ) ; 				  		
	cout << "\t\t\t\t~~ Digite el departamento al que pertenece: "; 							fflush(stdin);
	cin.getline ( q -> ubicacion.departamento,30,'\n');
			
	system ("CLS");
	SOLO_TITULO();
	titulo_b_m ();
	cout << "\n\t\t\t\t| REGISTRO DE TIPO DE DESECHOS RECICLADOS DE LA "<< q -> denominacion <<" | \n\n\n" ;
	cout << "\t\t\t\t\t  1. DESECHOS EN GENERAL (GRIS) \n\n" ;
    cout << "\t\t\t\t\t  2. ORG"<<char(181)<<"NICOS (MORADO) \n\n" ;
    cout << "\t\t\t\t\t  3. VIDRIOS (VERDE) \n\n";
    cout << "\t\t\t\t\t  4. PL"<<char(181)<<"STICOS Y ENVASES MET"<<char(181)<<"LICOS (AMARILLO) \n\n" ;
    cout << "\t\t\t\t\t  5. PAPEL (AZUL) \n\n";
    cout << "\t\t\t\t\t  6. DESECHOS PELIGROSOS (ROJO) \n\n";
    cout << "\n\t\t\t\t  "<<char(175)<<char(175)<<" Digite una opci\xA2n : ";
    cin  >> opc_m;
    
    system ( "CLS" );
    
	switch  ( opc_m )
		{
		case 1:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_b_m ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 8);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [0] <<" DE LA "<< q -> denominacion <<" | \n\n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			q -> D.desechos = "\n\n\t\t\t\t\t  - DESECHOS EN GENERAL (GRIS) \n";
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;				fflush(stdin);
			cin  >> q -> P.cantidad_kg ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;				fflush(stdin);
			cin  >> q -> P.precio_venta_kg ;
						
			q -> P.precio_total = q -> P.cantidad_kg * q -> P.precio_venta_kg ;	
					
			system ( "CLS" ) ;			
   			break ;
   		case 2:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_b_m ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 5);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [1] <<" DE LA "<< q -> denominacion <<" | \n\n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			q -> D.desechos = "\n\n\t\t\t\t\t  - DESECHOS ORGANICOS (MORADO) \n" ;
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;				fflush(stdin);
			cin  >> q -> P.cantidad_kg ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;				fflush(stdin);
			cin  >> q -> P.precio_venta_kg ;
						
			q -> P.precio_total = q -> P.cantidad_kg * q -> P.precio_venta_kg ;	
					
			system ( "CLS" ) ;			
   			break ;
		case 3:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_b_m ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 2);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [2] <<" DE LA "<< q -> denominacion <<" | \n\n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			q -> D.desechos = "\n\n\t\t\t\t\t  - DESECHOS VIDRIOS (VERDE) \n";
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;				fflush(stdin);
			cin  >> q -> P.cantidad_kg ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;				fflush(stdin);
			cin  >> q -> P.precio_venta_kg ;
						
			q -> P.precio_total = q -> P.cantidad_kg * q -> P.precio_venta_kg ;	
					
			system ( "CLS" ) ;			
   			break ;
		case 4:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_b_m ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 6);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [3] <<" DE LA "<< q -> denominacion <<" | \n\n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			q -> D.desechos = "\n\n\t\t\t\t\t  - DESECHOS PLASTICOS Y ENVASES METALICOS (AMARILLO)\n" ;
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;				fflush(stdin);
			cin  >> q -> P.cantidad_kg ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;				fflush(stdin);
			cin  >> q -> P.precio_venta_kg ;
						
			q -> P.precio_total = q -> P.cantidad_kg * q -> P.precio_venta_kg ;	
					
			system ( "CLS" ) ;			
   			break ;
		case 5:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_b_m ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 1);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [4] <<" DE LA "<< q -> denominacion <<" | \n\n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			q -> D.desechos = "\n\n\t\t\t\t\t  - DESECHOS PAPEL (AZUL)\n";
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;				fflush(stdin);
			cin  >> q -> P.cantidad_kg ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;				fflush(stdin);
			cin  >> q -> P.precio_venta_kg ;
						
			q -> P.precio_total = q -> P.cantidad_kg * q -> P.precio_venta_kg ;	
					
			system ( "CLS" ) ;			
   			break ; 
		case 6:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_b_m ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 4);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [5] <<" DE LA "<< q -> denominacion <<" | \n\n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			q -> D.desechos = "\n\n\t\t\t\t\t  - DESECHOS PELIGROSOS (ROJO)\n";
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;				fflush(stdin);
			cin  >> q -> P.cantidad_kg ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;				fflush(stdin);
			cin  >> q -> P.precio_venta_kg ;
						
			q -> P.precio_total = q -> P.cantidad_kg * q -> P.precio_venta_kg ;	
					
			system ( "CLS" ) ;			
   			break ;   		
   		}
   	SOLO_TITULO();
   	titulo_b_m () ;
	cout<<"\n\t\t\t\t\t"<<char(175)<<char(175)<<" La municipalidad ha sido agregada al registro";

    //Actualización de la lista con los nuevos datos de la municipalidad ANTES o DESPUÉS de la posición indicada
    if ( ( pos > 0 ) && ( pos <= numero_municipalidades + 1 ) )
   	{
		if ( ( ( deter == 'A') || ( deter == 'a' ) ) && ( pos == 1 ) ) //Añadir antes de la primera municipalidad
    	{
        	q -> siguiente_m = primero_m ;
        	q -> anterior_m = NULL ;
        	q -> siguiente_m -> anterior_m = q ;
        	primero_m = q ;
		}
    	else
    	{
        	if ( ( ( deter == 'D' ) || ( deter == 'd' ) ) && ( pos == 1 ) ) //Añadir después de la primera municipalidad
				{
				q -> siguiente_m = primero_m -> siguiente_m ;
        		q -> anterior_m = primero_m ;
        		q -> siguiente_m -> anterior_m = q ;
        		primero_m -> siguiente_m = q ;	
				}
			else 
				{
				t = primero_m ; 
 
        		for ( int i = 1 ; primero_m != NULL ; i = i + 1 )
            	{    
            		if ( ( ( deter == 'A') || ( deter == 'a' ) ) && ( i == pos - 1 ) ) // Para pos != del primero añade antes
					{			
						q -> siguiente_m = t -> siguiente_m;
						q -> anterior_m = t ;
           				q -> siguiente_m -> anterior_m = q ;
           				t -> siguiente_m = q ;
           				break ;
           			}
           			if ( ( ( deter == 'D') || ( deter == 'd' ) ) && ( i == pos ) ) // Para pos != del primero añade después
					{			
						q -> siguiente_m = t -> siguiente_m;
						q -> anterior_m = t ;
						if (q -> siguiente_m != NULL )
				       		q -> siguiente_m -> anterior_m = q ;
           				t -> siguiente_m = q ;       	
						break ;
           			}           			
           		t = t -> siguiente_m ;
           		}           		
           		}        
        }
        numero_municipalidades = numero_municipalidades + 1 ;
    }   
}

void eliminar_reciclador_m ( int num_codigo_eliminar_recicla ) //Función que elimina un reciclador de la lista
{
		int i=1, k=0;//k=bandera i=iterador		 
		
		municipalidades *eliminar_r = new municipalidades();
		municipalidades *eliminar_r_m = new municipalidades();
		
		
		SOLO_TITULO();
		cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS MUNICIPALES "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
		cout << "\t\t\t\t|| ELIMINAR DATOS DE UNA MUNICIPALIDAD EN ESPEC"<<char(214)<<"FICO || \n\n\n" ;
		
		if (primero_m != NULL)
		{
			eliminar_r  = primero_m;
			
			while(eliminar_r != NULL)
			{
				if(eliminar_r->codigo == num_codigo_eliminar_recicla)//busca el dni en la lista
				{
					if(eliminar_r == primero_m)	
						{
						primero_m = primero_m->siguiente_m;
						delete (eliminar_r);//elimina el nodo que contiene el dni
						eliminar_r = primero_m;
						k=1;					
						}
					else
						{
						eliminar_r ->anterior_m->siguiente_m = eliminar_r ->siguiente_m;
						if (eliminar_r ->siguiente_m!= NULL)
							eliminar_r ->siguiente_m->anterior_m = eliminar_r ->anterior_m;
						eliminar_r_m = eliminar_r ;
						eliminar_r  = eliminar_r ->siguiente_m;
						delete(eliminar_r_m);//elimina el nodo que contiene el dni
						k=1;
						}	
				}
				else
				{
				eliminar_r = eliminar_r->siguiente_m;//actualiza al siguiente nodo
				}								
			}
		}

		if(k==0)//evalua si no existe ningun codigo igual al ingresado.
			{
			cout<<"\t\t\t\t  "<<char(175)<<char(175)<<"	El n\xA3mero del CODIGO de la municipalidad no fue encontrado."<<endl;
			}
		else
			{
			cout<<"\t\t\t\t  "<<char(175)<<char(175)<<"	La municipalidad ha sido eliminada.";
			numero_municipalidades	= numero_municipalidades - 1; //actualiza # de recicladores
			}				
}

void contribucion_reciclador_m ( int contribucion_codigo_reciclador )//Función que muestra la contribución de un reciclador según codigo
{
		int i=1, k=0;//k=bandera i=iterador		 
		
		municipalidades *contribucion_r = new municipalidades();
		contribucion_r = primero_m;
		
		SOLO_TITULO();//Pertenece a la libreria TITULO.h
		cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS MUNICIPALES "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
		cout << "\t\t\t || CONTRIBUCI"<<char(224)<<"N AL MEDIO AMBIENTE DE UNA MUNICIPALIDAD EN ESPEC"<<char(214)<<"FICO || \n\n" ;
		
		if(primero_m != NULL)
		{
			do
			{
				if(contribucion_r->codigo == contribucion_codigo_reciclador)//busca el codigo en la lista
				{
				cout <<"\n\n\t\t\t\t -| DATOS DE LA MUNICIPALIDAD " << i << " |- \n";	
				cout <<"\n\t\t\t	    Denominaci\xA2n: " << contribucion_r  -> denominacion ;
        		cout <<"\n\t\t\t	    N"<<char(167)<<" CODIGO   : " <<contribucion_r  -> codigo ;
				cout <<"\n\t\t\t	    Ubicaci\xA2n   : " << contribucion_r  -> ubicacion.distrito <<" "<<contribucion_r  -> ubicacion.provincia <<" "<< contribucion_r  -> ubicacion.departamento ;
			
				cout << contribucion_r  -> D.desechos;
			
				cout << "\n\t\t\t\t	    CANTIDAD (Kg.)\t  PRECIO - VENTA(S/.)\t  TOTAL(S/.)\n " ;
				cout << "\n\t\t\t\t\t	    "<< contribucion_r -> P.cantidad_kg <<"\t\t\t  " ;
    			cout << contribucion_r  -> P.precio_venta_kg	<<" \t\t     " ;
    			cout << contribucion_r  -> P.precio_total	;
    			
    			cout << "\n\n\t\t\t\t  | CONTRIBUCION AL MEDIO AMBIENTE DE LA "<<contribucion_r -> denominacion <<" |"  ;
    			if ( contribucion_r  -> P.precio_total > 0 )
				{ 
				cout << "\n\n\t\t\t\t\t\t   Contribuci\xA2n POSITIVA" ;
				cout << "\n\n\t\t\t            La Municipalidad Pertenece al 3% de los Peruanos que RECICLA." ; 
				cout << "\n\t\t\t Gracias por apoyar LA REDUCCI"<<char(224)<<"N DE LA CONTAMINACION del Pa"<<char(161)<<"s y del Planeta. " ;
				}
				else
				{
				cout << "\n\n\t\t\t\t\t\t   Contribuci\xA2n NEGATIVA" ;
				cout << "\n\n\t\t\t            La Municipalidad Pertenece al % de Peruanos que NO RECICLA." ;
				cout << "\n\t\t\t\t Reciclar no es una obligaci\xA2n, es una responsabilidad. \n\t\t\t LA REDUCCI"<<char(224)<<"N DE LA CONTAMINACION del Pa"<<char(161)<<"s y del Planeta depende de ti. " ;	
				}
    			k=1;
				}
			contribucion_r = contribucion_r->siguiente_m;//actualiza al siguiente nodo
			i=i+1;	
			}
			while((contribucion_r != NULL) && (k==0));
			if(k==0)//evalua si no existe ningun dni igual al ingresado.
			{
			cout<<"\n La municipalidad no fue encontrada."<<endl;
			}					
		}			 
}
	
void menu_principal_municipalidades ()
{
	do {
	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS MUNICIPALES "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
    cout << "\t\t\t 1. REGISTRAR DATOS Y TIPO DE DESECHO DE LA MUNICIPALIDAD\n\n" ;
    cout << "\t\t\t 2. REGISTRO TOTAL DE LAS MUNICIPALIDADES Y TIPO DE DESECHO - DE INICIO A FIN  \n\n" ;
    cout << "\t\t\t 3. REGISTRO TOTAL DE LAS MUNICIPALIDADES Y TIPO DE DESECHO - DE FIN A INICIO  \n\n" ;
    cout << "\t\t\t 4. REGISTRO ESPEC"<<char(214)<<"FICO DE UNA MUNICIPALIDAD Y TIPO DE DESECHO \n\n" ;
    cout << "\t\t\t 5. MUNICIPALIDAD CON MAYOR VENTA									\n\n" ;
	cout << "\t\t\t 6. MUNICIPALIDAD CON MENOR VENTA									\n\n" ;
	cout << "\t\t\t 7. AGREGAR NUEVA MUNICIPALIDAD AL REGISTRO						\n\n" ;
	cout << "\t\t\t 8. ELIMINAR DATOS UNA MUNICIPALIDAD EN ESPEC"<<char(214)<<"FICO\n\n" ;  
	cout << "\t\t\t 9. CONTRIBUCI"<<char(224)<<"N AL MEDIO AMBIENTE DE UNA MUNICIPALIDAD EN ESPEC"<<char(214)<<"FICO	\n\n" ;
	cout << "\t\t\t10. ATR"<<char(181)<<"S                                    	\n\n" ;
    cout << "\t\t\t11. SALIR                                    					\n\n" ;
    cout << "\t\t	 "<<char(175)<<char(175)<<" Digite una opci\xA2n : " ;
    cin  >> elegir_m ;														
	system ( "CLS" ) ;
   
	switch ( elegir_m )
    {
        case 1: // Registrar municipalidades
        	SOLO_TITULO();//Pertenece a la libreria TITULO.h
            do { 
            titulo_a_m () ;
			cout << "\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de municipalidades que registrar\xA0: ";
			cin  >> numero_municipalidades ;
			system ( "CLS" ) ;
			} while ( numero_municipalidades < 1 ) ;			
			regis_recicladores_m ( numero_municipalidades ) ;//Función que registra municipalidades
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
            titulo_a_m ();
			retorna_principal_m () ;//Regresa al menú municipalidades
            break;
        case 2: // Registro total - INICIO A FIN  
        	SOLO_TITULO();//Pertenece a la libreria TITULO.h
            cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS MUNICIPALES "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t|| REGISTRO TOTAL DE LAS MUNICIPALIDADES Y TIPO DE DESECHO - DE INICIO A FIN || \n\n" ;
			ver_recicladores_m ( numero_municipalidades ) ;//Función que muestra municipalidades
            retorna_principal_m () ;//Regresa al menú domiciliario
			break;
		case 3: // Registro total - FIN A INICIO
        	SOLO_TITULO();//Pertenece a la libreria TITULO.h
            cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS MUNICIPALES "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t|| REGISTRO TOTAL DE LAS MUNICIPALIDADES Y TIPO DE DESECHO - DE FIN A INICIO || \n\n" ;
			ver_recicladores_fi_m () ;//Función que muestra municipalidades	   
            retorna_principal_m () ;//Regresa al menú municipalidades
			break;
		case 4: // Registro especifico de una municipalidad según codigo
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
        	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS MUNICIPALES "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t|| REGISTRO ESPEC"<<char(214)<<"FICO DE UNA MUNICIPALIDAD Y TIPO DE DESECHO || \n\n\n" ;
            cout << "\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de CODIGO de la municipalidad a buscar: ";			fflush(stdin);
            do {
			cin  >> numero_codigo_m ;
			} while ( numero_codigo_m < 100000 || numero_codigo_m > 999999 ) ;									
			system ( "CLS" ) ;
            codigo_un_reciclador_m ( numero_codigo_m ) ;//Función que muestra una municipalidad según codigo		          
			retorna_principal_m () ;//Regresa al menú municipalidades
            break;
		case 5: // Municipalidad con mayor venta 
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
        	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS MUNICIPALES "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t\t   || MUNICIPALIDAD CON MAYOR VENTA || \n\n\n" ;
			mayor_venta_m ( numero_municipalidades ) ;//Función que muestra la mayor venta
			retorna_principal_m () ;//Regresa al menú municipalidades
			break;
		case 6:	// Municipalidad con menor venta   
      		SOLO_TITULO();//Pertenece a la libreria TITULO.h
        	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS MUNICIPALES "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t\t   || MUNICIPALIDAD CON MENOR VENTA || \n\n\n" ;
			menor_venta_m ( numero_municipalidades ) ;//Función que muestra la menor venta
			retorna_principal_m () ;//Regresa al menú municipalidades
			break;	  
        case 7: // Añadir otra municipalidad a la lista
        	SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_b_m ();
			cout << "\t\t\t\t "<<char(175)<<char(175)<<" Digite el n\xA3mero de la posici\xA2n de la municipalidad que agregar\xA0: " ;
			do { cin  >>  posicion_m ; 
			} while ( ( posicion_m < 1 ) && ( posicion_m > numero_municipalidades ) ) ;
			anadir_nuevo_reciclador_m ( posicion_m ) ;//Función que añade un reciclador más
			retorna_principal_m () ;//Regresa al menú municipalidades
            break; 	
		case 8: // Eliminar una municipalidad según codigo
        	SOLO_TITULO();//Pertenece a la libreria TITULO.h
        	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS MUNICIPALES "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t   || ELIMINAR DATOS DE UNA MUNICIPALIDAD EN ESPEC"<<char(214)<<"FICO || \n\n\n" ;
			cout << "\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de CODIGO de la municipalidad a eliminar: ";			fflush(stdin);
            do {
            cin  >> numero_codigo_m ;
			} while ( numero_codigo_m < 100000 || numero_codigo_m > 999999 ) ;									
			system ( "CLS" ) ;
			eliminar_reciclador_m ( numero_codigo_m ) ;//Función que elimina una municipalidad de la lista
			retorna_principal_m () ;//Regresa al menú municipalidades
			break;
		case 9: // Contribución
        	SOLO_TITULO();//Pertenece a la libreria TITULO.h
            cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS MUNICIPALES "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t	      || CONTRIBUCI"<<char(224)<<"N AL MEDIO AMBIENTE DE UNA MUNICIPALIDAD EN ESPEC"<<char(214)<<"FICO || \n\n\n" ;
			cout << "\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de CODIGO de una municipalidad: ";					fflush(stdin);
            do {
            cin  >> numero_codigo_m;	
			} while ( numero_codigo_m < 100000 || numero_codigo_m > 999999 ) ;								
			system ( "CLS" ) ;
            contribucion_reciclador_m ( numero_codigo_m );	//Función que muestra la contribución de una municipalidad según codigo	          
			retorna_principal_m () ;//Regresa al menú municipalidades
            break;
        case 10: // Atrás
        	interfaz_secundaria ();
        	break;
    }
    } while ( ( elegir_m < 1 ) || ( elegir_m > 10 ) );
}

void RES_MUNICIPALIDADES()
{
	menu_principal_municipalidades () ;
}
//------------------------------------------------------- fin menú municipalidades-------------------------------------------------------------

//MENÚ HOSPITALARIOS
    void 	menu_principal_hospitalarios () ;
	int 	numero_codigo_unico, elegir_h, regresar_h, opc_h, posicion_h, numero_hospitales = 0 ; 
	char	deter_h ;
	
struct info_datos_h {
	char 	distrito_h [30] ;
	char 	provincia_h [30] ;
	char 	departamento_h [30] ;	
} ;

struct info_desechos_h {
	int	 	cantidad_kg_h ;
	float  	precio_venta_kg_h ;
	float   precio_total_h ;
};

struct desechos_h {
	string	desechos_h ;
};

struct hospitales{
    int   	codigo_unico ;
	char   	nombres [30] ;
	char   	modelo_h [30] ;
	struct 	info_datos_h direccion ;
	struct 	info_desechos_h P ; 
	struct  desechos_h D ;
	struct 	hospitales *anterior_h ;
	struct 	hospitales *siguiente_h ;
						
}*primero_h;

string desechos_h [6] = { "EN GENERAL (GRIS)", "ORGANICOS (MORADO)",	"VIDRIOS (VERDE)", 
						"PLASTICOS Y ENVASES METALICOS (AMARILLO)",	"PAPEL (AZUL)", "PELIGROSOS (ROJO)"};

void titulo_a_h ()
{
	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS HOSPITALARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
	cout << "\t\t\t     || REGISTRAR DATOS PERSONALES Y TIPO DE DESECHO DEL HOSPITAL || \n\n" ;
}

void titulo_b_h ()
{
	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS HOSPITALARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
	cout << "\t\t\t\t\t || AGREGAR NUEVO HOSPITAL AL REGISTRO || \n\n" ;
}

void retorna_principal_h ()//Regresa al menú hospitalario
{
    cout << "\n\n\n\t\t\t      Digite | 1 | para regresar al "<<char(174)<<"| MENé RESIDUOS HOSPITALARIOS |"<<char(175)<<" \n\n" ;
    cout << "\n\t\t\t\t\t        Digite | 0 | para "<<char(174)<<"| SALIR |"<<char(175) ;
    do
    {
	cout <<" \n\n\t\t\t\t\t\t\t "<<char(174)<<char(175)<<" " ;
	cin  >> regresar_h ; 	
	} while ( regresar_h != 1 && regresar_h != 0 );		
	system ( "CLS" ) ;
	
	if ( regresar_h == 1 ) 
		{
		SOLO_TITULO();//Pertenece a la libreria TITULO.h
		menu_principal_hospitalarios () ;
		}
}

void regis_hospitales ( int n_h )//Función que registra hospitales
{
	for ( int i = 0; i < n_h; i = i + 1 ) // n_c=numero de recicladores
    {    	
    hospitales *nuevo_h = new hospitales ();
	hospitales *nuevo_1_h = new hospitales();
	
	SOLO_TITULO();//Pertenece a la libreria TITULO.h
	titulo_a_h ();
	
    cout << "\n\t\t\t\t\t      | REGISTRO DE HOSPITALES | \n" ;
	cout << "\n\t\t\t\t\t       ---  HOSPITAL N"<<char(167)<<" " << i+1 << "  --- \n\n" ; 		fflush(stdin);
	cout << "\n\t\t\t\t|- Datos Hospitalarios -| \n\n" ; 
	do {
	cout << "\t\t\t\t~~ Digite el n\xA3mero de CODIGO UNICO del hospital: "; 				    fflush(stdin);
	cin  >> nuevo_h -> codigo_unico;	
	} while ( nuevo_h -> codigo_unico < 1000 || nuevo_h -> codigo_unico > 9999 ) ;				 
	cout << "\t\t\t\t~~ Digite el nombre del hospital     : ";									fflush(stdin);
	cin.getline ( nuevo_h -> nombres,30,'\n' ) ;		
	cout << "\t\t\t\t~~ Digite el modelo al que pertenece el hospital: ";						fflush(stdin);
	cin.getline ( nuevo_h -> modelo_h,30,'\n' ) ; 			
	cout << "\n\n\t\t\t\t|- Ubicaci\xA2n del Hospital -| \n\n"; 											
	cout << "\t\t\t\t~~ Digite el nombre del distrito    : " ;									fflush(stdin);
	cin.getline ( nuevo_h -> direccion.distrito_h,30,'\n' ) ;   	
	cout << "\t\t\t\t~~ Digite el nombre de la provincia : " ;									fflush(stdin);
	cin.getline ( nuevo_h -> direccion.provincia_h,30,'\n' ) ;  				  		
	cout << "\t\t\t\t~~ Digite el nombre del departamento: " ; 									fflush(stdin);
	cin.getline ( nuevo_h -> direccion.departamento_h,30,'\n' ) ; 
			
	system ("CLS");
	SOLO_TITULO();
	titulo_a_h ();
	
	cout << "\n\t\t\t\t| REGISTRO DE TIPO DE DESECHOS RECICLADOS DE "<< nuevo_h -> nombres <<" "<< nuevo_h -> modelo_h <<" | \n\n\n" ;
	cout << "\t\t\t\t\t  1. DESECHOS EN GENERAL (GRIS) \n\n" ;
    cout << "\t\t\t\t\t  2. ORG"<<char(181)<<"NICOS (MORADO) \n\n" ;
    cout << "\t\t\t\t\t  3. VIDRIOS (VERDE) \n\n";
    cout << "\t\t\t\t\t  4. PL"<<char(181)<<"STICOS Y ENVASES MET"<<char(181)<<"LICOS (AMARILLO) \n\n" ;
    cout << "\t\t\t\t\t  5. PAPEL (AZUL) \n\n";
    cout << "\t\t\t\t\t  6. DESECHOS PELIGROSOS (ROJO) \n\n";
    cout << "\n\t\t\t\t  "<<char(175)<<char(175)<<" Digite una opci\xA2n : ";
    do{
	cin  >> opc_h;
	} while ( opc_h < 1 && opc_h > 6 );
	    
    system ( "CLS" );    
	
	switch  ( opc_h )
		{
		case 1:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_a_h ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 8);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos_h [0] <<" DE "<< nuevo_h -> nombres<<" "<<nuevo_h -> modelo_h<<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			nuevo_h -> D.desechos_h = "\n\n\t\t\t\t\t  - DESECHOS EN GENERAL (GRIS) \n";
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;				fflush(stdin);
			cin  >> nuevo_h -> P.cantidad_kg_h ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;				fflush(stdin);
			cin  >> nuevo_h -> P.precio_venta_kg_h ;
						
			nuevo_h -> P.precio_total_h = nuevo_h -> P.cantidad_kg_h * nuevo_h -> P.precio_venta_kg_h ;	
					
			system ( "CLS" ) ;			
   			break ;
   		case 2:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_a_h ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 5);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos_h [1] <<" DE "<< nuevo_h -> nombres<<" "<<nuevo_h -> modelo_h<<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			nuevo_h -> D.desechos_h = "\n\n\t\t\t\t\t  - DESECHOS ORGANICOS (MORADO) \n" ;
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;				fflush(stdin);
			cin  >> nuevo_h -> P.cantidad_kg_h ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;				fflush(stdin);
			cin  >> nuevo_h -> P.precio_venta_kg_h ;
						
			nuevo_h -> P.precio_total_h = nuevo_h -> P.cantidad_kg_h * nuevo_h -> P.precio_venta_kg_h ;	
					
			system ( "CLS" ) ;			
   			break ;
		case 3:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_a_h ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 2);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos_h [2] <<" DE "<< nuevo_h -> nombres<<" "<<nuevo_h -> modelo_h<<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			nuevo_h -> D.desechos_h = "\n\n\t\t\t\t\t  - DESECHOS VIDRIOS (VERDE) \n";
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;				fflush(stdin);
			cin  >> nuevo_h -> P.cantidad_kg_h ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;				fflush(stdin);
			cin  >> nuevo_h -> P.precio_venta_kg_h ;
						
			nuevo_h -> P.precio_total_h = nuevo_h -> P.cantidad_kg_h * nuevo_h -> P.precio_venta_kg_h ;	
					
			system ( "CLS" ) ;			
   			break ;
		case 4:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_a_h ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 6);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos_h [2] <<" DE "<< nuevo_h -> nombres<<" "<<nuevo_h -> modelo_h<<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			nuevo_h -> D.desechos_h = "\n\n\t\t\t\t\t  - DESECHOS PLASTICOS Y ENVASES METALICOS (AMARILLO)\n" ;
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;				fflush(stdin);
			cin  >> nuevo_h -> P.cantidad_kg_h ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;				fflush(stdin);
			cin  >> nuevo_h -> P.precio_venta_kg_h ;
						
			nuevo_h -> P.precio_total_h = nuevo_h -> P.cantidad_kg_h * nuevo_h -> P.precio_venta_kg_h ;	
					
			system ( "CLS" ) ;			
   			break ;
		case 5:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_a_h ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 1);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos_h [2] <<" DE "<< nuevo_h -> nombres<<" "<<nuevo_h -> modelo_h<<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			nuevo_h -> D.desechos_h = "\n\n\t\t\t\t\t  - DESECHOS PAPEL (AZUL)\n";
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;				fflush(stdin);
			cin  >> nuevo_h -> P.cantidad_kg_h ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;				fflush(stdin);
			cin  >> nuevo_h -> P.precio_venta_kg_h ;
						
			nuevo_h -> P.precio_total_h = nuevo_h -> P.cantidad_kg_h * nuevo_h -> P.precio_venta_kg_h ;	
					
			system ( "CLS" ) ;			
   			break ; 
		case 6:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_a_h ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 4);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [5] <<" DE "<< nuevo_h -> nombres<<" "<<nuevo_h -> modelo_h<<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			nuevo_h -> D.desechos_h = "\n\n\t\t\t\t\t  - DESECHOS PELIGROSOS (ROJO)\n";
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;				fflush(stdin);
			cin  >> nuevo_h -> P.cantidad_kg_h ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;				fflush(stdin);
			cin  >> nuevo_h -> P.precio_venta_kg_h ;
						
			nuevo_h -> P.precio_total_h = nuevo_h -> P.cantidad_kg_h * nuevo_h -> P.precio_venta_kg_h ;	
					
			system ( "CLS" ) ;			
   			break ;    		
   		}
				   				
		// actualizar hospital
		nuevo_h -> siguiente_h = NULL ; 
			
		if (primero_h != NULL)
		{
			nuevo_1_h = primero_h;
			while (nuevo_1_h->siguiente_h != NULL)
			{
				nuevo_1_h = nuevo_1_h->siguiente_h;
			}
			nuevo_1_h->siguiente_h = nuevo_h;
			nuevo_h->anterior_h = nuevo_1_h;			
		}	
		else
		{
			primero_h = nuevo_h;
			nuevo_h->anterior_h = NULL;	
		}
	}
}

void ver_hospitales ( int numero_hospitales ) // ver hospitales de Inicio a Fin
{
   	hospitales *ver_r = new hospitales();
	
	float precio_global = 0, Kg_global = 0;
	ver_r = primero_h;	
			
    for ( int i = 0 ; i < numero_hospitales ; i = i + 1 ) 
    	{
			cout <<"\n\n\t\t\t\t -| DATOS PERSONALES DEL HOPSITAL " << i+1 << " |- \n";	
			cout <<"\n\t\t\t	    Nombre y modelo : " << ver_r -> nombres<<" "<<ver_r -> modelo_h ;
        	cout <<"\n\t\t\t	    N"<<char(167)<<" CODIGO UNICO : " <<ver_r -> codigo_unico ;
			cout <<"\n\t\t\t	    Ubicaci\xA2n       : " << ver_r -> direccion.distrito_h<<" "<<ver_r -> direccion.provincia_h<<" "<<ver_r->direccion.departamento_h ;
			
			cout << ver_r -> D.desechos_h;
			
			cout << "\n\t\t\t\t	    CANTIDAD (Kg.)\t  PRECIO - VENTA(S/.)\t  TOTAL(S/.)\n " ;
			cout << "\n\t\t\t\t\t	    "<< ver_r -> P.cantidad_kg_h <<"\t\t\t  " ;
    		cout << ver_r -> P.precio_venta_kg_h	<<" \t\t     " ;
    		cout << ver_r -> P.precio_total_h	;
			
			Kg_global = Kg_global +	ver_r -> P.cantidad_kg_h ;
			precio_global = precio_global +	ver_r -> P.precio_total_h ;
			
			ver_r = ver_r -> siguiente_h ;      
        }
	cout << "\n\n\t\t\t\t __________________________________________________________________________ \n" ;
	cout << "\n\n\t\t\t\t -| RESULTADOS FINALES DE LOS "<< numero_hospitales <<" HOSPITALES |- \n";
	cout << "\n\t\t\t\t	    CANTIDAD GLOBAL (Kg.) \t\t\t TOTAL GLOBAL (S/.)" ;
	cout << "\n\n\t\t\t\t\t	    "<< Kg_global << " \t\t\t\t\t\t"<< precio_global ;
}

void ver_hospitales_fi () // ver hospitales de Fin a Inicio
{
	hospitales *a = new hospitales () ;
	float precio_global = 0, Kg_global = 0;
    
	a = primero_h ;
    while ( a -> siguiente_h != NULL )
        a = a -> siguiente_h ;
    while ( a != NULL )
    {
	    for ( int i = 0 ; i < numero_hospitales ; i = i + 1 ) 
    	{
   		cout <<"\n\n\t\t\t\t -| DATOS PERSONALES DEL HOSPITAL " << numero_hospitales - i << " |- \n";
	    cout <<"\n\t\t\t	    Nombre y modelo : " << a -> nombres<<" "<<a -> modelo_h ;
        cout <<"\n\t\t\t	    N"<<char(167)<<" CODIGO UNICO : " <<a -> codigo_unico ;
		cout <<"\n\t\t\t	    Ubicaci\xA2n       : " << a -> direccion.distrito_h<<" "<<a -> direccion.provincia_h<<" "<<a->direccion.departamento_h ;
			
		cout << a -> D.desechos_h;
			
		cout << "\n\t\t\t\t	    CANTIDAD (Kg.)\t  PRECIO - VENTA(S/.)\t  TOTAL(S/.)\n " ;
		cout << "\n\t\t\t\t\t	    "<< a -> P.cantidad_kg_h <<"\t\t\t  " ;
    	cout << a -> P.precio_venta_kg_h	<<" \t\t     " ;
    	cout << a -> P.precio_total_h	;
			
		Kg_global = Kg_global +	a -> P.cantidad_kg_h ;
		precio_global = precio_global +	a -> P.precio_total_h ;
				        
        a = a -> anterior_h ;        	
		}
		cout << "\n\n\t\t\t\t __________________________________________________________________________ \n" ;
		cout << "\n\n\t\t\t\t -| RESULTADOS FINALES DE LOS "<< numero_hospitales <<" HOSPITALES |- \n";
		cout << "\n\t\t\t\t	    CANTIDAD GLOBAL (Kg.) \t\t\t TOTAL GLOBAL (S/.)" ;
		cout << "\n\n\t\t\t\t\t	    "<< Kg_global << " \t\t\t\t\t\t"<< precio_global ;		
    }
}   	

void codigo_un_hospital ( int num_codigo_hosp )// Muestra el registro de un hospital y desecho según codigo unico.
{
		int i=1, k=0;//k=bandera i=iterador		 
		
		hospitales *dni_r = new hospitales();
		dni_r = primero_h;
		
		SOLO_TITULO();
		cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS HOSPITALARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
		cout << "\t\t\t\t|| REGISTRO ESPEC"<<char(214)<<"FICO DE UN HOSPITAL Y TIPO DE DESECHO || \n\n\n" ;
		
		if(primero_h != NULL)
		{
			do
			{
				if(dni_r->codigo_unico == num_codigo_hosp)// evalua la igualdad entre el codigo-unico ingresado con los registrados.
				{
				cout <<"\n\t\t\t\t -| DATOS PERSONALES DEL HOSPITAL " << i << " |- \n";
        		cout <<"\n\t\t\t	    Nombre y modelo : " << dni_r -> nombres<<" "<<dni_r -> modelo_h ;
        		cout <<"\n\t\t\t	    N"<<char(167)<<" CODIGO UNICO : " << dni_r -> codigo_unico ;
				cout <<"\n\t\t\t	    Ubicaci\xA2n       : " << dni_r -> direccion.distrito_h<<" "<< dni_r -> direccion.provincia_h<<" "<< dni_r->direccion.departamento_h ;
			
				cout << dni_r  -> D.desechos_h;
			
				cout << "\n\t\t\t\t	    CANTIDAD (Kg.)\t  PRECIO - VENTA(S/.)\t  TOTAL(S/.)\n " ;
				cout << "\n\t\t\t\t\t	    "<< dni_r -> P.cantidad_kg_h <<"\t\t\t  " ;
    			cout << dni_r  -> P.precio_venta_kg_h	<<" \t\t     " ;
    			cout << dni_r  -> P.precio_total_h	;
    			k=1;
				}
			dni_r = dni_r->siguiente_h;//actualiza al siguiente nodo
			i=i+1;	
			}
			while((dni_r != NULL) && (k==0));
			
			if(k==0)//evalua si no existe ningun codigo-unico igual al ingresado en el registro.
			{
			cout<<"\n El hospital no fue encontrado."<<endl;
			}					
		}			 
}

void mayor_venta_h ( int numero_hospitales ) //Función que muestra la mayor venta
{
		int i=1, k=0;//k=bandera
		
		float mayor_h;
						 
		hospitales *may_venta_h = new hospitales();
		hospitales *may_venta_hospital = new hospitales();
		
		may_venta_h = primero_h;
		may_venta_hospital = primero_h;
		
		mayor_h=may_venta_h  -> P.precio_total_h;
		
		for (int i=0; i<numero_hospitales; i=i+1)
    	{		
			if (may_venta_h  -> P.precio_total_h > mayor_h)
			{
			mayor_h=may_venta_h  -> P.precio_total_h;
			}
			may_venta_h  = may_venta_h->siguiente_h;//actualiza al siguiente nodo
		}
				
		if(primero_h != NULL)
		{
			do
			{
				if(may_venta_hospital->P.precio_total_h == mayor_h)//busca el precio total y muestra datos
				{
				cout <<"\n\t\t\t\t -| DATOS PERSONALES DEL HOSPITAL " << i << " |- \n";
        		cout <<"\n\t\t\t	    Nombre y modelo : " << may_venta_hospital -> nombres<<" "<<may_venta_hospital -> modelo_h ;
        		cout <<"\n\t\t\t	    N"<<char(167)<<" CODIGO UNICO : " << may_venta_hospital -> codigo_unico ;
				cout <<"\n\t\t\t	    Ubicaci\xA2n       : " << may_venta_hospital -> direccion.distrito_h<<" "<< may_venta_hospital -> direccion.provincia_h<<" "<< may_venta_hospital -> direccion.departamento_h ;
			
				cout << may_venta_hospital  -> D.desechos_h;
			
				cout << "\n\t\t\t\t	    CANTIDAD (Kg.)\t  PRECIO - VENTA(S/.)\t  TOTAL(S/.)\n " ;
				cout << "\n\t\t\t\t\t	    "<< may_venta_hospital -> P.cantidad_kg_h <<"\t\t\t  " ;
    			cout << may_venta_hospital  -> P.precio_venta_kg_h	<<" \t\t     " ;
    			cout << may_venta_hospital  -> P.precio_total_h	;
    			cout << "\n\n\t\t\t\t\t     | ~ MAYOR VENTA (S/.) ~ | ---------------------| "<<mayor_h<<" |";
    		 	k=1;
				}
			may_venta_hospital = may_venta_hospital->siguiente_h;//actualiza al siguiente nodo
			i=i+1;	
			}
			while((may_venta_hospital != NULL) && (k==0));					
		}			 
}

void menor_venta_h ( int numero_hospitales ) //Función que muestra la menor venta
{
		int i=1, k=0;//k=bandera i=iterador
		
		float menor_h;
						 
		hospitales *men_venta_h = new hospitales();
		hospitales *men_venta_hospital = new hospitales();
		
		men_venta_h = primero_h;
		men_venta_hospital = primero_h;
		
		menor_h=men_venta_h  -> P.precio_total_h;
		
		for (int i=0; i<numero_hospitales; i=i+1)
    	{		
			if (men_venta_h  -> P.precio_total_h < menor_h)
			{
			menor_h = men_venta_h  -> P.precio_total_h;
			}
			men_venta_h  = men_venta_h->siguiente_h;
		}
				
		if(primero_h != NULL)
		{
			do
			{
				if(men_venta_hospital->P.precio_total_h == menor_h)//busca el precio total y muestra datos
				{
				cout <<"\n\t\t\t\t -| DATOS PERSONALES DEL HOSPITAL " << i << " |- \n";
        		cout <<"\n\t\t\t	    Nombre y modelo : " << men_venta_hospital -> nombres<<" "<<men_venta_hospital -> modelo_h ;
        		cout <<"\n\t\t\t	    N"<<char(167)<<" CODIGO UNICO : " << men_venta_hospital -> codigo_unico ;
				cout <<"\n\t\t\t	    Ubicaci\xA2n       : " << men_venta_hospital -> direccion.distrito_h<<" "<< men_venta_hospital -> direccion.provincia_h<<" "<< men_venta_hospital->direccion.departamento_h ;
			
				cout << men_venta_hospital  -> D.desechos_h;
			
				cout << "\n\t\t\t\t	    CANTIDAD (Kg.)\t  PRECIO - VENTA(S/.)\t  TOTAL(S/.)\n " ;
				cout << "\n\t\t\t\t\t	    "<< men_venta_hospital -> P.cantidad_kg_h <<"\t\t\t  " ;
    			cout << men_venta_hospital  -> P.precio_venta_kg_h	<<" \t\t     " ;
    			cout << men_venta_hospital  -> P.precio_total_h	;
    			cout << "\n\n\t\t\t\t\t     | ~ MENOR VENTA (S/.) ~ | ---------------------| "<<menor_h<<" |";
    		 	k=1;
				}
			men_venta_hospital = men_venta_hospital->siguiente_h;//actualiza al siguiente nodo
			i=i+1;	
			}
			while((men_venta_hospital != NULL) && (k==0));					
		}			 
}

void anadir_nuevo_hospital ( int pos_h ) //Función que añade un hospital más (antes o después)
{
	hospitales *q = new hospitales () ;	
    hospitales *t = new hospitales () ;
		
	cout << "\n\n\t\t\t\t   ~ Digite 'D', si agregar\xA0 - DESPU"<<char(144)<<"S - de la posici\xA2n | " << pos_h << " |" ;
	cout << "\n\n\t\t\t\t   ~ Digite 'A', si agregar\xA0 - ANTES - de la posici\xA2n | " << pos_h << " | " ;
	do {
		cout << "\n\n\t\t\t\t\t\t\t"<<char(174)<<char(175)<< " " ;
		cin  >> deter_h ;
	} while ( deter_h != 'A' &&  deter_h != 'a' && deter_h != 'D' && deter_h != 'd' ) ;
	
	system ("CLS");
	SOLO_TITULO();
	titulo_b_h ();
    cout << "\n\t\t\t\t|- Datos Hospitalarios -| \n\n" ; 
	do {
	cout << "\t\t\t\t~~ Digite el n\xA3mero de CODIGO UNICO del hospital: "; 				    fflush(stdin);
	cin  >> q -> codigo_unico;	
	} while ( q -> codigo_unico < 1000 || q -> codigo_unico > 9999 ) ;				 
	cout << "\t\t\t\t~~ Digite el nombre del hospital     : ";									fflush(stdin);
	cin.getline ( q -> nombres,30,'\n' ) ;		
	cout << "\t\t\t\t~~ Digite el modelo al que pertenece el hospital: ";						fflush(stdin);
	cin.getline ( q -> modelo_h,30,'\n' ) ; 			
	cout << "\n\n\t\t\t\t|- Ubicaci\xA2n del Hospital -| \n\n"; 											
	cout << "\t\t\t\t~~ Digite el nombre del distrito    : " ;									fflush(stdin);
	cin.getline ( q -> direccion.distrito_h,30,'\n' ) ;   	
	cout << "\t\t\t\t~~ Digite el nombre de la provincia : " ;									fflush(stdin);
	cin.getline ( q -> direccion.provincia_h,30,'\n' ) ;  				  		
	cout << "\t\t\t\t~~ Digite el nombre del departamento: " ; 									fflush(stdin);
	cin.getline ( q -> direccion.departamento_h,30,'\n' ) ; 
			
	system ("CLS");
	SOLO_TITULO();
	titulo_b_h ();
	cout << "\n\t\t\t\t| REGISTRO DE TIPO DE DESECHOS RECICLADOS DE "<< q -> nombres <<" "<< q -> modelo_h <<" | \n\n\n" ;
	cout << "\t\t\t\t\t  1. DESECHOS EN GENERAL (GRIS) \n\n" ;
    cout << "\t\t\t\t\t  2. ORG"<<char(181)<<"NICOS (MORADO) \n\n" ;
    cout << "\t\t\t\t\t  3. VIDRIOS (VERDE) \n\n";
    cout << "\t\t\t\t\t  4. PL"<<char(181)<<"STICOS Y ENVASES MET"<<char(181)<<"LICOS (AMARILLO) \n\n" ;
    cout << "\t\t\t\t\t  5. PAPEL (AZUL) \n\n";
    cout << "\t\t\t\t\t  6. DESECHOS PELIGROSOS (ROJO) \n\n";
    cout << "\n\t\t\t\t  "<<char(175)<<char(175)<<" Digite una opci\xA2n : ";
    cin  >> opc_h;
    
    system ( "CLS" );
    
	switch  ( opc_h )
		{
		case 1:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_a_h ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 8);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos_h [0] <<" DE "<< q -> nombres<<" "<<q -> modelo_h<<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			q -> D.desechos_h = "\n\n\t\t\t\t\t  - DESECHOS EN GENERAL (GRIS) \n";
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;				fflush(stdin);
			cin  >> q -> P.cantidad_kg_h ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;				fflush(stdin);
			cin  >> q -> P.precio_venta_kg_h ;
						
			q -> P.precio_total_h = q -> P.cantidad_kg_h * q -> P.precio_venta_kg_h ;	
					
			system ( "CLS" ) ;			
   			break ;
   		case 2:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_a_h ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 5);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos_h [1] <<" DE "<< q -> nombres<<" "<<q -> modelo_h<<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			q -> D.desechos_h = "\n\n\t\t\t\t\t  - DESECHOS ORGANICOS (MORADO) \n" ;
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;				fflush(stdin);
			cin  >> q -> P.cantidad_kg_h ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;				fflush(stdin);
			cin  >> q -> P.precio_venta_kg_h ;
						
			q -> P.precio_total_h = q -> P.cantidad_kg_h * q -> P.precio_venta_kg_h ;	
					
			system ( "CLS" ) ;			
   			break ;
		case 3:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_a_h ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 2);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos_h [2] <<" DE "<< q -> nombres<<" "<<q -> modelo_h<<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			q -> D.desechos_h = "\n\n\t\t\t\t\t  - DESECHOS VIDRIOS (VERDE) \n";
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;				fflush(stdin);
			cin  >> q -> P.cantidad_kg_h ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;				fflush(stdin);
			cin  >> q -> P.precio_venta_kg_h ;
						
			q -> P.precio_total_h = q -> P.cantidad_kg_h * q -> P.precio_venta_kg_h ;	
					
			system ( "CLS" ) ;			
   			break ;
		case 4:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_a_h ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 6);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos_h [2] <<" DE "<< q -> nombres<<" "<<q -> modelo_h<<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			q -> D.desechos_h = "\n\n\t\t\t\t\t  - DESECHOS PLASTICOS Y ENVASES METALICOS (AMARILLO)\n" ;
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;				fflush(stdin);
			cin  >> q -> P.cantidad_kg_h ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;				fflush(stdin);
			cin  >> q -> P.precio_venta_kg_h ;
						
			q -> P.precio_total_h = q -> P.cantidad_kg_h * q -> P.precio_venta_kg_h ;	
					
			system ( "CLS" ) ;			
   			break ;
		case 5:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_a_h ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 1);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos_h [2] <<" DE "<< q -> nombres<<" "<<q -> modelo_h<<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			q -> D.desechos_h = "\n\n\t\t\t\t\t  - DESECHOS PAPEL (AZUL)\n";
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;				fflush(stdin);
			cin  >> q -> P.cantidad_kg_h ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;				fflush(stdin);
			cin  >> q -> P.precio_venta_kg_h ;
						
			q -> P.precio_total_h = q -> P.cantidad_kg_h * q -> P.precio_venta_kg_h ;	
					
			system ( "CLS" ) ;			
   			break ; 
		case 6:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_a_h ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 4);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [5] <<" DE "<< q -> nombres<<" "<<q -> modelo_h<<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			q -> D.desechos_h = "\n\n\t\t\t\t\t  - DESECHOS PELIGROSOS (ROJO)\n";
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;				fflush(stdin);
			cin  >> q -> P.cantidad_kg_h ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;				fflush(stdin);
			cin  >> q -> P.precio_venta_kg_h ;
						
			q -> P.precio_total_h = q -> P.cantidad_kg_h * q -> P.precio_venta_kg_h ;	
					
			system ( "CLS" ) ;			
   			break ;    		
   		}
   	SOLO_TITULO();
   	titulo_b_h () ;
	cout<<"\n\t\t\t\t\t"<<char(175)<<char(175)<<" El hospital ha sido agregado al registro";

    //Actualización de la lista con los nuevos datos del hospital ANTES o DESPUÉS de la posición indicada
    if ( ( pos_h > 0 ) && ( pos_h <= numero_hospitales + 1 ) )
   	{
		if ( ( ( deter_h == 'A') || ( deter_h == 'a' ) ) && ( pos_h == 1 ) ) //Añadir antes del primer reciclador
    	{
        	q -> siguiente_h = primero_h ;
        	q -> anterior_h = NULL ;
        	q -> siguiente_h -> anterior_h = q ;
        	primero_h = q ;
		}
    	else
    	{
        	if ( ( ( deter_h == 'D' ) || ( deter_h == 'd' ) ) && ( pos_h == 1 ) ) //Añadir después del primer reciclador
				{
				q -> siguiente_h = primero_h -> siguiente_h ;
        		q -> anterior_h = primero_h ;
        		q -> siguiente_h -> anterior_h = q ;
        		primero_h -> siguiente_h = q ;	
				}
			else 
				{
				t = primero_h ; 
 
        		for ( int i = 1 ; primero_h != NULL ; i = i + 1 )
            	{    
            		if ( ( ( deter_h == 'A') || ( deter_h == 'a' ) ) && ( i == pos_h - 1 ) ) // Para pos != del primero añade antes
					{			
						q -> siguiente_h = t -> siguiente_h;
						q -> anterior_h = t ;
           				q -> siguiente_h -> anterior_h = q ;
           				t -> siguiente_h = q ;
           				break ;
           			}
           			if ( ( ( deter_h == 'D') || ( deter_h == 'd' ) ) && ( i == pos_h ) ) // Para pos != del primero añade después
					{			
						q -> siguiente_h = t -> siguiente_h;
						q -> anterior_h = t ;
						if (q -> siguiente_h != NULL )
				       		q -> siguiente_h -> anterior_h = q ;
           				t -> siguiente_h = q ;       	
						break ;
           			}           			
           		t = t -> siguiente_h ;
           		}           		
           		}        
        }
        numero_hospitales = numero_hospitales + 1 ;
    }   
}

void eliminar_hospital ( int num_codigo_eliminar_hosp ) //Función que elimina un hospital de la lista
{
		int i=1, k=0;//k=bandera i=iterador		 
		
		hospitales *eliminar_r = new hospitales();
		hospitales *eliminar_r_m = new hospitales();
		
		
		SOLO_TITULO();
		cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS HOSPITALARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
		cout << "\t\t\t\t   || ELIMINAR DATOS DE UN HOSPITAL EN ESPEC"<<char(214)<<"FICO || \n\n\n" ;
		
		if (primero_h != NULL)
		{
			eliminar_r  = primero_h;
			
			while(eliminar_r != NULL)
			{
				if(eliminar_r->codigo_unico == num_codigo_eliminar_hosp)//busca el codigo-unico en la lista
				{
					if(eliminar_r == primero_h)	
						{
						primero_h = primero_h->siguiente_h;
						delete (eliminar_r);//elimina el nodo que contiene el codigo-unico
						eliminar_r = primero_h;
						k=1;					
						}
					else
						{
						eliminar_r ->anterior_h->siguiente_h = eliminar_r ->siguiente_h;
						if (eliminar_r ->siguiente_h!= NULL)
							eliminar_r ->siguiente_h->anterior_h = eliminar_r ->anterior_h;
						eliminar_r_m = eliminar_r ;
						eliminar_r  = eliminar_r ->siguiente_h;
						delete(eliminar_r_m);//elimina el nodo que contiene el codigo-unico
						k=1;
						}	
				}
				else
				{
				eliminar_r = eliminar_r->siguiente_h;//actualiza al siguiente nodo
				}								
			}
		}

		if(k==0)//evalua si no existe ningun codigo-unico igual al ingresado.
			{
			cout<<"\t\t\t\t  "<<char(175)<<char(175)<<"	El n\xA3mero de CODIGO UNICO del HOSPITAL no fue encontrado."<<endl;
			}
		else
			{
			cout<<"\t\t\t\t  "<<char(175)<<char(175)<<"	El hospital ha sido eliminado.";
			numero_hospitales = numero_hospitales - 1; //actualiza # de hospitales
			}				
}

void contribucion_hospital ( int contribucion_codigo_hosp )//Función que muestra la contribución de un reciclador según dni
{
		int i=1, k=0;//k=bandera i=iterador		 
		
		hospitales *contribucion_r = new hospitales();
		contribucion_r = primero_h;
		
		SOLO_TITULO();//Pertenece a la libreria TITULO.h
		cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS HOSPITALARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
		cout << "\t\t\t || CONTRIBUCI"<<char(224)<<"N AL MEDIO AMBIENTE DE UN HOSPITAL EN ESPEC"<<char(214)<<"FICO || \n\n" ;
		
		if(primero_h != NULL)
		{
			do
			{
				if(contribucion_r->codigo_unico == contribucion_codigo_hosp)//busca el codigo-unico en la lista
				{
				cout <<"\n\n\t\t\t\t -| DATOS PERSONALES DEL HOSPITAL " << i << " |- \n";
        		cout <<"\n\t\t\t	    Nombre y modelo : " << contribucion_r -> nombres<<" "<<contribucion_r -> modelo_h ;
        		cout <<"\n\t\t\t	    N"<<char(167)<<" CODIGO UNICO : " << contribucion_r -> codigo_unico ;
				cout <<"\n\t\t\t	    Ubicaci\xA2n       : " << contribucion_r -> direccion.distrito_h<<" "<< contribucion_r -> direccion.provincia_h<<" "<< contribucion_r->direccion.departamento_h ;
			
				cout << contribucion_r  -> D.desechos_h;
			
				cout << "\n\t\t\t\t	    CANTIDAD (Kg.)\t  PRECIO - VENTA(S/.)\t  TOTAL(S/.)\n " ;
				cout << "\n\t\t\t\t\t	    "<< contribucion_r -> P.cantidad_kg_h <<"\t\t\t  " ;
    			cout << contribucion_r  -> P.precio_venta_kg_h	<<" \t\t     " ;
    			cout << contribucion_r  -> P.precio_total_h	;
    			
    			cout << "\n\n\t\t\t\t  | CONTRIBUCION AL MEDIO AMBIENTE DE "<<contribucion_r -> nombres<<" "<<contribucion_r -> modelo_h<<" |"  ;
    			if ( contribucion_r  -> P.precio_total_h > 0 )
				{ 
				cout << "\n\n\t\t\t\t\t\t   Contribuci\xA2n POSITIVA" ;
				cout << "\n\n\t\t\t            Usted pertenece al 3% de los Peruanos que RECICLA." ; 
				cout << "\n\t\t\t Gracias por apoyar LA REDUCCI"<<char(224)<<"N DE LA CONTAMINACION del Pa"<<char(161)<<"s y del Planeta. " ;
				}
				else
				{
				cout << "\n\n\t\t\t\t\t\t   Contribuci\xA2n NEGATIVA" ;
				cout << "\n\n\t\t\t            Usted pertenece al % de Peruanos que NO RECICLA." ;
				cout << "\n\t\t\t\t Reciclar no es una obligaci\xA2n, es una responsabilidad. \n\t\t\t LA REDUCCI"<<char(224)<<"N DE LA CONTAMINACION del Pa"<<char(161)<<"s y del Planeta depende de ti. " ;	
				}
    			k=1;
				}
			contribucion_r = contribucion_r->siguiente_h;//actualiza al siguiente nodo
			i=i+1;	
			}
			while((contribucion_r != NULL) && (k==0));
			if(k==0)//evalua si no existe ningun dni igual al ingresado.
			{
			cout<<"\n El hospital no fue encontrado."<<endl;
			}					
		}			 
}
	
void menu_principal_hospitalarios ()
{
	do {
	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS HOSPITALARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
    cout << "\t\t\t 1. REGISTRAR DATOS PERSONALES Y TIPO DE DESECHO DEL HOSPITAL\n\n" ;
    cout << "\t\t\t 2. REGISTRO TOTAL DE LOS HOSPITALES Y TIPO DE DESECHO - DE INICIO A FIN  \n\n" ;
    cout << "\t\t\t 3. REGISTRO TOTAL DE LOS HOSPITALES Y TIPO DE DESECHO - DE FIN A INICIO  \n\n" ;
    cout << "\t\t\t 4. REGISTRO ESPEC"<<char(214)<<"FICO DE UN HOSPITAL Y TIPO DE DESECHO \n\n" ;
    cout << "\t\t\t 5. HOSPITAL CON MAYOR VENTA									\n\n" ;
	cout << "\t\t\t 6. HOSPITAL CON MENOR VENTA									\n\n" ;
	cout << "\t\t\t 7. AGREGAR NUEVO HOSPITAL AL REGISTRO						\n\n" ;
	cout << "\t\t\t 8. ELIMINAR DATOS DE UN HOSPITAL EN ESPEC"<<char(214)<<"FICO\n\n" ;  
	cout << "\t\t\t 9. CONTRIBUCI"<<char(224)<<"N AL MEDIO AMBIENTE DE UN HOSPITAL EN ESPEC"<<char(214)<<"FICO	\n\n" ;
	cout << "\t\t\t10. ATR"<<char(181)<<"S                                    	\n\n" ;
    cout << "\t\t\t11. SALIR                                    					\n\n" ;
    cout << "\t\t	 "<<char(175)<<char(175)<<" Digite una opci\xA2n : " ;
    cin  >> elegir_h ;														
	system ( "CLS" ) ;
   
	switch ( elegir_h )
    {
        case 1: // Registrar recicladores
        	SOLO_TITULO();//Pertenece a la libreria TITULO.h
            do { 
            titulo_a_h () ;
			cout << "\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de hospitales que registrar\xA0: ";
			cin  >> numero_hospitales ;
			system ( "CLS" ) ;
			} while ( numero_hospitales < 1 ) ;			
			regis_hospitales ( numero_hospitales ) ;//Función que registra hospitales
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
            titulo_a_h ();
			retorna_principal_h () ;//Regresa al menú hospitalario
            break;
        case 2: // Registro total - INICIO A FIN  
        	SOLO_TITULO();//Pertenece a la libreria TITULO.h
            cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS HOSPITALARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t|| REGISTRO TOTAL DE LOS HOSPITALES Y TIPO DE DESECHO - DE INICIO A FIN || \n\n" ;
			ver_hospitales ( numero_hospitales ) ;//Función que muestra hospitales
            retorna_principal_h () ;//Regresa al menú hospitalario
			break;
		case 3: // Registro total - FIN A INICIO
        	SOLO_TITULO();//Pertenece a la libreria TITULO.h
            cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS HOSPITALARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t|| REGISTRO TOTAL DE LOS HOSPITALES Y TIPO DE DESECHO - DE FIN A INICIO || \n\n" ;
			ver_hospitales_fi () ;//Función que muestra hospitales	   
            retorna_principal_h () ;//Regresa al menú hospitalario
			break;
		case 4: // Registro especifico de un reciclador según dni
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
        	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS HOSPITALARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t|| REGISTRO ESPEC"<<char(214)<<"FICO DE UN HOSPITAL Y TIPO DE DESECHO || \n\n\n" ;
            cout << "\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de CODIGO UNICO del hospital a buscar: ";					fflush(stdin);
            do {
			cin  >> numero_codigo_unico ;
			} while ( numero_codigo_unico < 1000 || numero_dni > 9999 ) ;									
			system ( "CLS" ) ;
            codigo_un_hospital ( numero_codigo_unico ) ;//Función que muestra un hospital segun CODIGO-UNICO		          
			retorna_principal_h () ;//Regresa al menú hospitalario
            break;
		case 5: // Reciclador con mayor venta 
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
        	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS HOSPITALARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t\t     || HOSPITAL CON MAYOR VENTA || \n\n\n" ;
			mayor_venta_h ( numero_hospitales ) ;//Función que muestra la mayor venta
			retorna_principal_h () ;//Regresa al menú hospitalario
			break;
		case 6:	// Reciclador con menor venta   
      		SOLO_TITULO();//Pertenece a la libreria TITULO.h
        	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS HOSPITALARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t\t     || HOSPITAL CON MENOR VENTA || \n\n\n" ;
			menor_venta_h ( numero_hospitales ) ;//Función que muestra la menor venta
			retorna_principal_h () ;//Regresa al menú hospitalario
			break;	  
        case 7: // Añadir otro hospital a la lista
        	SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_b_h ();
			cout << "\t\t\t\t "<<char(175)<<char(175)<<" Digite el n\xA3mero de la posici\xA2n del reciclador que agregar\xA0: " ;
			do { cin  >>  posicion_h ; 
			} while ( ( posicion_h < 1 ) && ( posicion_h > numero_hospitales ) ) ;
			anadir_nuevo_hospital ( posicion_h ) ;//Función que añade un hospital más
			retorna_principal_h () ;//Regresa al menú hospitalario
            break; 	
		case 8: // Eliminar un hospital según CODIGO-UNICO
        	SOLO_TITULO();//Pertenece a la libreria TITULO.h
        	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS HOSPITALARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t   || ELIMINAR DATOS DE UN HOSPITAL EN ESPEC"<<char(214)<<"FICO || \n\n\n" ;
			cout << "\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de CODIGO UNICO del hospital a eliminar: ";					fflush(stdin);
            do {
            cin  >> numero_codigo_unico ;
			} while ( numero_codigo_unico < 1000 || numero_codigo_unico > 9999 ) ;									
			system ( "CLS" ) ;
			eliminar_hospital ( numero_codigo_unico ) ;//Función que elimina un hospital de la lista
			retorna_principal_h () ;//Regresa al menú hospitalario
			break;
		case 9: // Contribución
        	SOLO_TITULO();//Pertenece a la libreria TITULO.h
            cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS HOSPITALARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t	      || CONTRIBUCI"<<char(224)<<"N AL MEDIO AMBIENTE DE UN HOSPITAL EN ESPEC"<<char(214)<<"FICO || \n\n\n" ;
			cout << "\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de CODIGO UNICO de un hospital: ";					fflush(stdin);
            do {
            cin  >> numero_codigo_unico;	
			} while ( numero_codigo_unico < 1000 || numero_codigo_unico > 9999 ) ;								
			system ( "CLS" ) ;
            contribucion_hospital ( numero_codigo_unico );	//Función que muestra la contribución de un hospital según codigo-unico	          
			retorna_principal_h () ;//Regresa al menú hospitalario
            break;
        case 10: // Atrás
        	interfaz_secundaria ();
        	break;
    }
    } while ( (elegir_h <1) || ( elegir_h > 10 ) );
}

void RES_HOSPITALARIOS()
{
	menu_principal_hospitalarios () ;
}
//------------------------------------------------------- fin menú hospitalarios-----------------------------------

//MENÚ PRINCIPAL
int opcion, opcion_menu;
void menu_principal();

void descripcion_somos ()
{
 	cout <<" \n\n\t\t  RECICLADORA MC, es una empresa de reciclaje privada trujillana que busca reducir " ;
	cout <<" \n\t\tla cantidad de residuos enviados a disposici\xA2n final favoreciendo la cadena entera " ;
	cout <<" \n\t\tde reciclaje: concientizaci\xA2n, separaci\xA2n, recolecci\xA2n, transformaci\xA2n y" ;
	cout <<" \n\t\tcomercializaci\xA2n." ;
	cout <<" \n\n\t\t  Es una empresa trujillana que brinda servicios en el manejo y tratamiento de la gesti\xA2n " ;
	cout <<" \n\t\tde residuos y ofrece los servicios de Recolecci\xA2n, Selecci\xA2n y Compra de diferentes tipos " ;
	cout <<" \n\t\tde residuos como: " ;
	cout <<" \n\n\t\t		- Residuos En General " ;
	cout <<" \n\t\t		- Residuos Org\xA0nicos " ; 
	cout <<" \n\t\t		- Residuos Vidrios " ;
	cout <<" \n\t\t		- Residuos Pl\xA0sticos Y Envases Met\xA0licos " ;
	cout <<" \n\t\t		- Residuos Papel " ;
	cout <<" \n\t\t		- Residuos Peligrosos " ;
	cout <<" \n\n\t\tLos invitamos a seguir nuestro desarrollo comercial a trav\x82s de las redes sociales. " ;
	cout <<" \n\n\t\t\t\tTel"<<char(130)<<"fonos: 997813670  -  983711234 " ;
	cout <<" \n\n\t\t  CREADORAS:" ;
	cout <<" \n\n\t\t		- Angely Mendez Cruz " ;
	cout <<" \n\t\t		- Ciara Mendez Cruz " ; 
}

void interfaz_secundaria ()// RECICLADORA MC + LOGOS DE R.DOM, R.HOSP, R.MUN
{	
	SOLO_TITULO();//Pertenece a la libreria TITULO.h
    I_SECUNDARIA();// Pertenece a la libreria I-SECUNDARIA.h
    cout << "\n\n\t\t\t\t\t\t\t ~ 4 ~ \n\t\t\t\t\t\t\t ATR"<<char(181)<<"S \n\n" ;
    
	do
	{
		cout << "\n\t\t\t\t\t	 "<<char(175)<<char(175)<<" Digite una opci\xA2n: " ;
    	cin  >> opcion_menu ;
	} while ( (opcion_menu <1) || (opcion_menu > 4) );
			
	system("CLS");
			
	switch (opcion_menu)
	{
		case 1://domiciliarios
				SOLO_TITULO();//Pertenece a la libreria TITULO.h
				RES_DOMICILIOS();
				break;
		case 2://municipales
				SOLO_TITULO();//Pertenece a la libreria TITULO.h
				RES_MUNICIPALIDADES ();
				break;
		case 3://hospitalarios
				SOLO_TITULO();//Pertenece a la libreria TITULO.h
				RES_HOSPITALARIOS ();
				break;
		case 4://atras		
				menu_principal();
				break;
	}
}

void menu_principal ()
{
	//Interfaz principal: MENU + QUIENES SOMOS + SALIR
	SOLO_TITULO () ; //Pertenece a la libreria TITULO.h
	I_PRINCIPAL () ; //Libreria I_PRINCIPAL.h : LOGOS DE MENU + QUIENES SOMOS + SALIR
	
	do{
		cout << "\n\n\t\t\t\t\t	 "<<char (175)<<char (175)<< " Digite una opci\xA2n: " ;
    	cin  >> opcion ;
	} while ( ( opcion < 1 ) || ( opcion > 3 ) );
	
	system("CLS");
	
	switch ( opcion )
    {
        case 1: //Menu
        	interfaz_secundaria () ;			
			break;
    	case 2: //Quienes somos
    		SOLO_TITULO() ;//Pertenece a la libreria TITULO.h
    		descripcion_somos () ;
			cout << "\n\n\n\n\n\t\t\t      Digite | 1 | para regresar al "<<char (174)<< "| MENé PRINCIPAL |"<<char (175)<< "\n\n" ;
    		cout << "\n\t\t\t\t\t    Digite | 0 | para "<<char (174)<<"| SALIR |"<<char (175)<< " \n\n\t\t\t\t\t\t "<<char (175)<<char (175);
    		cin  >> regresar ;
			 	
			system ( "CLS" ) ;
	
			if ( regresar == 1 )
			{
				SOLO_TITULO () ;//Pertenece a la libreria TITULO.h
				menu_principal() ;
			} 
        	break;
    }    	
}
//------------------------------------------------------- fin menú principal-----------------------------------
int main ()
{
	system ("mode con: cols=160 lines=65") ;
	
	//interfaz inicio: RECICLADORA MC + LOGO DE RECICLAJE
		I_TITULO(); //Pertenece a la libreria TITULO.h
		
		cout << "C A R G A N D O ..." ;
			Sleep ( 5000 ) ;
			
		system ( "CLS" ) ;
			
		menu_principal () ;
		
	getch();
}
