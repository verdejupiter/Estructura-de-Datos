#include <iostream>
#include <conio.h>
#include <string.h>
#include "TITULO.h"
#include "I-PRINCIPAL.h"
#include "I-SECUNDARIA.h"

using namespace std ;
void interfaz_secundaria ();
int regresar;

//MENÚ DOMICILIARIOS
/* Inicio arbol_domicialiarios ----------------------------------------------------------------------------------------------------------------------------------------------------*/
    void 	menu_principal_domiciliarios () ;
	int 	regresar_d, elegir_d, numero_recicladores = 0, opc_d, op_d, dni_d, codigo_elim_d;
	string 	a_d, b_d, c_d, d_d, nombres_d, apellidos_d, calle_d, urbanizacion_d;
	
struct info_ubicacion_d {
	string 	calle ;
	int  numero ;
	string 	urbanizacion ;	
};

struct info_desechos_d {
	int	 	cantidad_kg ;
	float  	precio_venta_kg ;
	float   precio_total ;
};

struct desechos_d {
	string	desechos ;
};

struct domiciliarios{
    int   	dni ;
	string 	nombres ;
	string  apellidos;
	struct 	info_ubicacion_d ubicacion ;
	struct 	info_desechos_d P ; 
	struct  desechos_d D ;
	struct 	domiciliarios *izquierda_d ;
	struct  domiciliarios *derecha_d ;						
};

domiciliarios *arbol = NULL;  //creación e inicialización del árbol ABB

string desechos [6] = { "EN GENERAL (GRIS)", "ORGANICOS (MORADO)",	"VIDRIOS (VERDE)", 
						"PLASTICOS Y ENVASES METALICOS (AMARILLO)",	"PAPEL (AZUL)", "PELIGROSOS (ROJO)"};

void titulo_a_d ()
{
	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS DOMICILIARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
	cout << "\t\t\t\t     || REGISTRAR DATOS Y TIPO DE DESECHO DEL RECICLADOR || \n\n" ;
}

void retorna_principal_d ()//Regresa al menú domiciliario
{
    cout << "\n\n\n\t\t\t      Digite | 1 | para regresar al "<<char(174)<<"| MENé RESIDUOS DOMICILIARIOS |"<<char(175)<<" \n\n" ;
    cout << "\n\t\t\t\t\t        Digite | 0 | para "<<char(174)<<"| SALIR |"<<char(175) ;
    do
    {
	cout <<" \n\n\t\t\t\t\t\t\t "<<char(174)<<char(175)<<" " ;
	cin  >> regresar_d ; 	
	} while ( regresar_d != 1 && regresar_d != 0 );		
	system ( "CLS" ) ;
	
	if ( regresar_d == 1 ) 
		{
		SOLO_TITULO();//Pertenece a la libreria TITULO.h
		menu_principal_domiciliarios () ;
		}
}

//Función para crear un nuevo nodo del arbol ABB
domiciliarios *crear_nodo(int d, string n, string a , string u_c, int u_n, string u_u, int p_cant, float p_precio, float p_precio_total, string des)
{
	domiciliarios *nuevo_nodo = new domiciliarios();
		
	nuevo_nodo-> dni = d;
	nuevo_nodo-> nombres = n;
	nuevo_nodo-> apellidos = a;
	nuevo_nodo-> ubicacion.calle = u_c;
	nuevo_nodo-> ubicacion.numero = u_n;
	nuevo_nodo-> ubicacion.urbanizacion = u_u;
	nuevo_nodo-> P.cantidad_kg = p_cant;	 
	nuevo_nodo-> P.precio_venta_kg = p_precio;
	nuevo_nodo-> P.precio_total = p_precio_total;
	nuevo_nodo-> D.desechos = des;
	nuevo_nodo-> izquierda_d = NULL;
	nuevo_nodo-> derecha_d = NULL;
		
	return nuevo_nodo;
}
	
//Funcion para insertar datos dentro del arbol	
void insertar_nodo_d (domiciliarios *&arbol, int d, string n, string a , string u_c, int u_n, string u_u, int p_cant, float p_precio, float p_precio_total, string des)
{
	if (arbol == NULL)
	{
			domiciliarios *n_nodo = crear_nodo (d, n, a , u_c, u_n, u_u, p_cant, p_precio, p_precio_total, des);
			arbol = n_nodo;
	}			
	else 
	{
		int raiz_d = arbol -> dni;
		
		if (d < raiz_d)
		{	//si el codigo es menor - izquierda d
			insertar_nodo_d (arbol->izquierda_d, d, n, a , u_c, u_n, u_u, p_cant, p_precio, p_precio_total, des);	
		}
		else
		{	//si el codigo es mayor - derecha d 
			insertar_nodo_d (arbol->derecha_d, d, n, a , u_c, u_n, u_u, p_cant, p_precio, p_precio_total, des);
		}				
	}						
}
	
//Función que registra domiciliarios	
void regis_recicladores_d ( int n_c ) // n_c=numero de recicladores
{
	int dni, numero;
	float precio_total_d, cantidad_kg_d, precio_venta_kg_d;
	string nombres, apellidos, calle, urbanizacion, D_desechos_d;	
	
	for ( int i = 0; i < n_c; i = i + 1 ) 
    {    	
    SOLO_TITULO();//Pertenece a la libreria TITULO.h
	if ( n_c != 1 )
	{
		titulo_a_d ();
		cout << "\n\t\t\t\t\t      | REGISTRO DE RECICLADORES | \n" ;
		cout << "\n\t\t\t\t\t       ---  RECICLADOR N"<<char(167)<<" " << i+1 << "  --- \n\n" ;
	}
	if ( n_c == 1 )
	{
	cout << "\n\n\n\n\n\n\n";
	} 
	cout << "\n\t\t\t\t|- Datos Personales -| \n\n" ; 
	do {
	cout << "\t\t\t\t~~ Digite el n\xA3mero de DNI del reciclador: "; 							fflush(stdin);
	cin  >> dni;	
	} while ( dni < 10000000 || dni > 99999999 ) ;				 
	cout << "\t\t\t\t~~ Digite los nombres del reciclador     : ";								fflush(stdin);
	getline (cin, nombres) ;		
	cout << "\t\t\t\t~~ Digite los apellidos del reciclador   : ";								fflush(stdin);
	getline ( cin,  apellidos) ; 			
	cout << "\n\n\t\t\t\t|- Direcci\xA2n de la vivienda -| \n\n"; 											
	cout << "\t\t\t\t~~ Digite el nombre de la calle          : ";								fflush(stdin);
	getline ( cin, calle) ;   	
	cout << "\t\t\t\t~~ Digite el n\xA3mero de la casa           : ";							fflush(stdin);
	cin  >> numero ; 				  		
	cout << "\t\t\t\t~~ Digite la urbanizaci\xA2n o distrito     : "; 							fflush(stdin);
	getline ( cin, urbanizacion);
		
	system ("CLS");
	SOLO_TITULO();
	
	if ( n_c != 1 )
		titulo_a_d ();
	else
	{   
		cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS DOMICILIARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
		cout << "\t\t\t\t\t  || AGREGAR NUEVO RECICLADOR AL REGISTRO || \n\n\n" ; 
	}
	
	cout << "\n\t\t\t\t| REGISTRO DE TIPO DE DESECHOS RECICLADOS DE "<< nombres << " "<< apellidos <<" | \n\n\n" ;
	cout << "\t\t\t\t\t  1. DESECHOS EN GENERAL (GRIS) \n\n" ;
    cout << "\t\t\t\t\t  2. ORG"<<char(181)<<"NICOS (MORADO) \n\n" ;
    cout << "\t\t\t\t\t  3. VIDRIOS (VERDE) \n\n";
    cout << "\t\t\t\t\t  4. PL"<<char(181)<<"STICOS Y ENVASES MET"<<char(181)<<"LICOS (AMARILLO) \n\n" ;
    cout << "\t\t\t\t\t  5. PAPEL (AZUL) \n\n";
    cout << "\t\t\t\t\t  6. DESECHOS PELIGROSOS (ROJO) \n\n";
    cout << "\n\t\t\t\t  "<<char(175)<<char(175)<<" Digite una opci\xA2n : ";
    do{
	cin  >> opc_d;
	} while ( opc_d < 1 && opc_d > 6 );
	    
    system ( "CLS" );    
	
	switch  ( opc_d )
		{
		case 1:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_a_d ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 8);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [0] <<" DE "<< nombres << " "<< apellidos <<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			D_desechos_d = "\n\n\t\t\t\t\t  - DESECHOS EN GENERAL (GRIS) \n";
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;	
			cin  >> cantidad_kg_d ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;	
			cin  >> precio_venta_kg_d ;
						
			precio_total_d = cantidad_kg_d * precio_venta_kg_d;	
					
			system ( "CLS" ) ;			
   			break ;
   		case 2:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_a_d ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 5);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [1] <<" DE "<< nombres << " "<< apellidos <<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			D_desechos_d = "\n\n\t\t\t\t\t  - DESECHOS ORGANICOS (MORADO) \n" ;
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;	
			cin  >> cantidad_kg_d ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;	
			cin  >> precio_venta_kg_d ;
						
			precio_total_d = cantidad_kg_d * precio_venta_kg_d;	
					
			system ( "CLS" ) ;			
   			break ;
		case 3:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_a_d ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 2);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [2] <<" DE "<< nombres << " "<< apellidos <<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			D_desechos_d = "\n\n\t\t\t\t\t  - DESECHOS VIDRIOS (VERDE) \n";
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;	
			cin  >> cantidad_kg_d ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;	
			cin  >> precio_venta_kg_d ;
						
			precio_total_d = cantidad_kg_d * precio_venta_kg_d;	
					
			system ( "CLS" ) ;			
   			break ;
		case 4:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_a_d ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 6);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [3] <<" DE "<< nombres << " "<< apellidos <<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			D_desechos_d = "\n\n\t\t\t\t\t  - DESECHOS PLASTICOS Y ENVASES METALICOS (AMARILLO)\n" ;
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;	
			cin  >> cantidad_kg_d ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;	
			cin  >> precio_venta_kg_d ;
						
			precio_total_d = cantidad_kg_d * precio_venta_kg_d;	
					
			system ( "CLS" ) ;			
   			break ;
		case 5:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_a_d ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 1);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [4] <<" DE "<< nombres << " "<< apellidos <<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			D_desechos_d = "\n\n\t\t\t\t\t  - DESECHOS PAPEL (AZUL)\n";
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;	
			cin  >> cantidad_kg_d ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;	
			cin  >> precio_venta_kg_d ;
						
			precio_total_d = cantidad_kg_d * precio_venta_kg_d;	
					
			system ( "CLS" ) ;			
   			break ;
		case 6:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_a_d ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 4);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [5] <<" DE "<< nombres << " "<< apellidos <<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			D_desechos_d = "\n\n\t\t\t\t\t  - DESECHOS PELIGROSOS (ROJO)\n";
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;	
			cin  >> cantidad_kg_d ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;	
			cin  >> precio_venta_kg_d ;
						
			precio_total_d = cantidad_kg_d * precio_venta_kg_d;	
					
			system ( "CLS" ) ;			
   			break ;
   		}
		   		
	insertar_nodo_d ( arbol, dni, nombres , apellidos, calle, numero, urbanizacion, cantidad_kg_d, precio_venta_kg_d, precio_total_d, D_desechos_d);		   				
	
	}
}

//Funcion que permite ver en forma de arbol el codigo de los recicladores domiciliarios
int X = 0;		
void ver_registro_arbol_d ( domiciliarios *arbol, int Y)//y=5
{  
    if ( arbol == NULL ) //evalúa si el arbol está vacio
      return;
    
  	X = X + 15;

    ver_registro_arbol_d ( arbol -> izquierda_d, Y + 5 );

    gotoxy( 30 + X - Y , 5 + Y );
	cout << "DNI:" << arbol -> dni << "	" <<endl;
	gotoxy( 30 + X - Y , 6 + Y );
	cout << arbol -> nombres << endl;
	gotoxy( 30 + X - Y , 7 + Y );
	cout << arbol -> apellidos << endl;
		
    ver_registro_arbol_d ( arbol -> derecha_d, Y + 5 );    
}

//Funcion que muestra datos del registro segun codigo, denominacion, distrito, provincia, departamento
void ver_buscar_recicladores_d ( domiciliarios *arbol)
{
	cout <<"\n\n\t\t\t\t -| DATOS PERSONALES DEL RECICLADOR |- \n";	
	cout <<"\n\t\t\t	    Nombres y apellidos : " << arbol -> nombres<<" "<<arbol -> apellidos ;
    cout <<"\n\t\t\t	    N"<<char(167)<<" DNI              : " <<arbol -> dni ;
	cout <<"\n\t\t\t	    Direcci\xA2n           : " << arbol -> ubicacion.calle<<" "<<arbol->ubicacion.numero<<" "<<arbol->ubicacion.urbanizacion ; 

	cout << arbol -> D.desechos;
			
	cout << "\n\t\t\t\t	    CANTIDAD (Kg.)\t  PRECIO - VENTA(S/.)\t  TOTAL(S/.)\n " ;
	cout << "\n\t\t\t\t\t	    "<< arbol -> P.cantidad_kg <<"\t\t\t  " ;
    cout << arbol -> P.precio_venta_kg	<<" \t\t     " ;
    cout << arbol -> P.precio_total	;
}

//Funcion que busca y muestra datos según 
bool buscar_arbol_d ( domiciliarios *arbol, int c, string d , string u_d, string u_p, string u_de, int valor)
{
  	if (valor == 1) //Funcion que busca según dni
  	{
  		if ( arbol == NULL )
    		return false ;
  		else
  		{
    		if ( arbol->dni == c )
    		{
    		ver_buscar_recicladores_d (arbol);
    		buscar_arbol_d ( arbol -> izquierda_d, c, d , u_d, u_p, u_de, valor);  
     		buscar_arbol_d ( arbol -> derecha_d, c, d , u_d, u_p, u_de, valor );
			return true;			   
  			}
  
 		buscar_arbol_d ( arbol -> izquierda_d, c, d , u_d, u_p, u_de, valor);
 		buscar_arbol_d ( arbol -> derecha_d, c, d , u_d, u_p, u_de, valor);   
  		}
	}
	if (valor == 2) //Funcion que busca según nombres
  	{
  		if ( arbol == NULL )
    		return false ;
  		else
  		{
    		if ( arbol->nombres == d )
    		{
    		ver_buscar_recicladores_d (arbol);
    		buscar_arbol_d ( arbol -> izquierda_d, c, d , u_d, u_p, u_de, valor);  
     		buscar_arbol_d ( arbol -> derecha_d, c, d , u_d, u_p, u_de, valor );
			return true;    
  			}
  
 		buscar_arbol_d ( arbol -> izquierda_d, c, d , u_d, u_p, u_de, valor);
 		buscar_arbol_d ( arbol -> derecha_d, c, d , u_d, u_p, u_de, valor);   
  		}
	}			
	if (valor == 3) //Funcion que busca según apellidos
  	{
  		if ( arbol == NULL )
    		return false ;
  		else
  		{
    		if ( arbol->apellidos == u_d )
    		{
    		ver_buscar_recicladores_d (arbol);
    		buscar_arbol_d ( arbol -> izquierda_d, c, d , u_d, u_p, u_de, valor);  
     		buscar_arbol_d ( arbol -> derecha_d, c, d , u_d, u_p, u_de, valor );
			return true;    
  			}
  
 		buscar_arbol_d ( arbol -> izquierda_d, c, d , u_d, u_p, u_de, valor);
 		buscar_arbol_d ( arbol -> derecha_d, c, d , u_d, u_p, u_de, valor);   
  		}
	}
	if (valor == 4) //Funcion que busca según calle
  	{
  		if ( arbol == NULL )
    		return false ;
  		else
  		{
    		if ( arbol->ubicacion.calle == u_p )
    		{
    		ver_buscar_recicladores_d (arbol);
    		buscar_arbol_d ( arbol -> izquierda_d, c, d , u_d, u_p, u_de, valor);  
     		buscar_arbol_d ( arbol -> derecha_d, c, d , u_d, u_p, u_de, valor );
			return true;    
  			}
  
 		buscar_arbol_d ( arbol -> izquierda_d, c, d , u_d, u_p, u_de, valor);
 		buscar_arbol_d ( arbol -> derecha_d, c, d , u_d, u_p, u_de, valor);   
  		}
	}
	if (valor == 5) //Funcion que busca según urbanizacion
  	{
  		if ( arbol == NULL )
    		return false ;
  		else
  		{
    		if ( arbol->ubicacion.urbanizacion == u_de )
    		{
    		ver_buscar_recicladores_d (arbol);
    		buscar_arbol_d ( arbol -> izquierda_d, c, d , u_d, u_p, u_de, valor);  
     		buscar_arbol_d ( arbol -> derecha_d, c, d , u_d, u_p, u_de, valor );
			return true;    
  			}
  
 		buscar_arbol_d ( arbol -> izquierda_d, c, d , u_d, u_p, u_de, valor);
 		buscar_arbol_d ( arbol -> derecha_d, c, d , u_d, u_p, u_de, valor);   
  		}
	}	
}

//Funcion que muestra datos del registro total
void ver_recicladores_d ( domiciliarios *arbol)
{
	if ( arbol == NULL)
		return ;

	ver_recicladores_d ( arbol -> izquierda_d);

	cout <<"\n\n\t\t\t\t -| DATOS PERSONALES DEL RECICLADOR |- \n";	
	cout <<"\n\t\t\t	    Nombres y apellidos : " << arbol -> nombres<<" "<<arbol -> apellidos ;
    cout <<"\n\t\t\t	    N"<<char(167)<<" DNI              : " <<arbol -> dni ;
	cout <<"\n\t\t\t	    Direcci\xA2n           : " << arbol -> ubicacion.calle<<" "<<arbol->ubicacion.numero<<" "<<arbol->ubicacion.urbanizacion ; 
			
	cout << arbol -> D.desechos;
			
	cout << "\n\t\t\t\t	    CANTIDAD (Kg.)\t  PRECIO - VENTA(S/.)\t  TOTAL(S/.)\n " ;
	cout << "\n\t\t\t\t\t	    "<< arbol -> P.cantidad_kg <<"\t\t\t  " ;
    cout << arbol -> P.precio_venta_kg	<<" \t\t     " ;
    cout << arbol -> P.precio_total	;
    
    ver_recicladores_d ( arbol -> derecha_d);
}

//Funcion que une nodos despues de eliminar
domiciliarios *union_arbol_d (domiciliarios *i, domiciliarios *d)
{
	if (i == NULL)
		return d;
		
	if (d == NULL)
		return i;
				
	domiciliarios *centro = new (struct domiciliarios);
										
	centro = union_arbol_d (i->derecha_d, d->izquierda_d);
		
	i->derecha_d = centro;
	d->izquierda_d = i;
		
	return d;
}

//Funcion que elimina un reciclador segun dni
void elimina_un_reciclador (domiciliarios *&arbol, int e)
{
	if (arbol == NULL)
		return;
						
	if (e < arbol->dni)
	{
		elimina_un_reciclador (arbol->izquierda_d, e);
	}						
	else 
	{
		if (e > arbol->dni)
		{
			elimina_un_reciclador (arbol->derecha_d, e);
		}
		else
		{
			domiciliarios *p = new (struct domiciliarios);	
			p = arbol;
			arbol = union_arbol_d (arbol->izquierda_d, arbol->derecha_d);				
			numero_recicladores = numero_recicladores - 1;
			delete p;				 
		}			
	}									
}

void menu_principal_domiciliarios ()
{
	do {
	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS DOMICILIARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
    cout << "\t\t\t 1. REGISTRAR DATOS Y TIPO DE DESECHO DEL RECICLADOR \n\n" ;
    cout << "\t\t\t 2. REGISTRO DE LOS RECICLADORES - FORMA ARBOL  \n\n" ;
    cout << "\t\t\t 3. REGISTRO TOTAL DE LOS RECICLADORES Y TIPO DE DESECHO \n\n" ;
    cout << "\t\t\t 4. BUSCAR RECICLADOR EN EL REGISTRO \n\n" ;    
	cout << "\t\t\t 5. AGREGAR NUEVO RECICLADOR AL REGISTRO				\n\n" ;
	cout << "\t\t\t 6. ELIMINAR DATOS DE UN RECICLADOR EN ESPEC"<<char(214)<<"FICO\n\n" ;
	cout << "\t\t\t 7. ELIMINAR TODO EL REGISTRO \n\n" ;
	cout << "\t\t\t 8. ATR"<<char(181)<<"S                                  \n\n" ;
    cout << "\t\t\t 9. SALIR                                    			\n\n" ;
    cout << "\t\t	 "<<char(175)<<char(175)<<" Digite una opci\xA2n : " ;
    cin  >> elegir_d ;														
	system ( "CLS" ) ;
   
	switch ( elegir_d )
    {
        case 1: // Registrar recicladores
        	SOLO_TITULO();//Pertenece a la libreria TITULO.h
            do { 
            titulo_a_d () ;
			cout << "\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de recicladores que registrar\xA0: ";
			cin  >> numero_recicladores ;
			system ( "CLS" ) ;
			} while ( numero_recicladores < 1 ) ;			
			regis_recicladores_d ( numero_recicladores ) ;//Función que registra municipalidades
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
            titulo_a_d ();
			retorna_principal_d () ;//Regresa al menú municipalidades
            break;
            
        case 2: // Registro - forma arbol 
        	//SOLO_TITULO();//Pertenece a la libreria TITULO.h
            cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS DOMICILIARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t    || REGISTRO DE LOS RECICLADORES - FORMA ARBOL || \n\n" ;
			ver_registro_arbol_d ( arbol, 5 ) ;//Funcion que permite ver en forma de arbol el codigo de las municipalidades
			cout << "\n\n\n\n\n\n";			
			retorna_principal_d () ;//Regresa al menú municipalidades
			break;
			
        case 3: // Registro total de recicladores
        	SOLO_TITULO();//Pertenece a la libreria TITULO.h
            cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS DOMICILIARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t    || REGISTRO TOTAL DE LOS RECICLADORES Y TIPO DE DESECHO || \n\n" ;
			if ( arbol == NULL )
				cout << "\t\t\t\t    "<<char(175)<<"No hay Datos en el REGISTRO!";
			else
				ver_recicladores_d ( arbol );	
			retorna_principal_d () ;//Regresa al menú domiciliarios
			break;
			
		case 4: // Busqueda  de recicladores
        	SOLO_TITULO();//Pertenece a la libreria TITULO.h
            cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS DOMICILIARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t\t    || BUSCAR RECICLADOR EN EL REGISTRO || \n\n" ;
			cout << "\t\t\t\t\t      1. DNI \n\n" ;
    		cout << "\t\t\t\t\t      2. NOMBRES  \n\n" ;
    		cout << "\t\t\t\t\t      3. APELLIDOS \n\n" ;
			cout << "\t\t\t\t\t      4. CALLE \n\n" ;    
			cout << "\t\t\t\t\t      5. URBANIZACION	\n\n" ;
			cout << "\t\t\t\t\t    "<<char(175)<<char(175)<<" Digite una opci\xA2n : " ;
			cin  >> op_d ;
			system ( "CLS" ) ;
			switch (op_d)
			{
				case 1:
					SOLO_TITULO();//Pertenece a la libreria TITULO.h
            		cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS DOMICILIARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
					cout << "\t\t\t\t\t  || BUSCAR RECICLADOR EN EL REGISTRO || \n\n\n" ;
					cout << "\t\t\t\t || BUSQUEDA POR DNI EN EL REGISTRO || \n\n" ;
					cout << "\t\t\t\t "<<char(175)<<char(175)<<" Digite el n\xA3mero de DNI del reciclador a buscar: "; fflush(stdin);
					cin  >> dni_d ;
					buscar_arbol_d ( arbol, dni_d, a_d , b_d, c_d, d_d, 1 );
					retorna_principal_d () ;//Regresa al menú domiciliarios
            		break;	
				case 2:
					SOLO_TITULO();//Pertenece a la libreria TITULO.h
            		cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS DOMICILIARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
					cout << "\t\t\t\t\t  || BUSCAR RECICLADOR EN EL REGISTRO || \n\n\n" ;
					cout << "\t\t\t\t || BUSQUEDA POR NOMBRES EN EL REGISTRO || \n\n" ;
					cout << "\t\t\t\t "<<char(175)<<char(175)<<" Digite los NOMBRES del reciclador a buscar: "; fflush(stdin);
					getline ( cin,  nombres_d );
					buscar_arbol_d ( arbol, 0, nombres_d , b_d, c_d, d_d, 2 );
					retorna_principal_d () ;//Regresa al menú domiciliarios
            		break;
				case 3:
					SOLO_TITULO();//Pertenece a la libreria TITULO.h
            		cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS DOMICILIARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
					cout << "\t\t\t\t\t  || BUSCAR RECICLADOR EN EL REGISTRO || \n\n\n" ;
					cout << "\t\t\t\t || BUSQUEDA POR APELLIDOS DISTRITO EN EL REGISTRO || \n\n" ;
					cout << "\t\t\t\t "<<char(175)<<char(175)<<" Digite los APELLIDOS del reciclador a buscar: "; fflush(stdin);
					getline ( cin,  apellidos_d) ;
					buscar_arbol_d ( arbol, 0, a_d , apellidos_d, c_d, d_d, 3 );
					retorna_principal_d () ;//Regresa al menú domiciliarios
            		break;
				case 4:
					SOLO_TITULO();//Pertenece a la libreria TITULO.h
            		cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS DOMICILIARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
					cout << "\t\t\t\t\t  || BUSCAR RECICLADOR EN EL REGISTRO || \n\n\n" ;
					cout << "\t\t\t\t || BUSQUEDA POR CALLE EN EL REGISTRO || \n\n" ;
					cout << "\t\t\t\t "<<char(175)<<char(175)<<" Digite la CALLE del reciclador a buscar: "; fflush(stdin);
					getline ( cin,  calle_d );
					buscar_arbol_d ( arbol, 0, a_d , b_d, calle_d, d_d, 4 );
					retorna_principal_d () ;//Regresa al menú domiciliarios
            		break;
				case 5:	
					SOLO_TITULO();//Pertenece a la libreria TITULO.h
            		cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS DOMICILIARIOS  "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
					cout << "\t\t\t\t\t  || BUSCAR RECICLADOR EN EL REGISTRO || \n\n\n" ;
					cout << "\t\t\t\t || BUSQUEDA POR URBANIZACION EN EL REGISTRO || \n\n" ;
					cout << "\t\t\t\t "<<char(175)<<char(175)<<" Digite la URBANIZACION del reciclador a buscar: "; fflush(stdin);
					getline ( cin,  urbanizacion_d) ;
					buscar_arbol_d ( arbol, 0, a_d , b_d, c_d, urbanizacion_d, 5 );					
					retorna_principal_d () ;//Regresa al menú domiciliarios
            		break;
			}			
			break;
		case 5: //Agregar un neuvo reciclador al registro 
        	SOLO_TITULO();//Pertenece a la libreria TITULO.h
            cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS DOMICILIARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t\t  || AGREGAR NUEVO RECICLADOR AL REGISTRO || \n\n\n\n" ;        	
			regis_recicladores_d ( 1 ) ;//Función que registra municipalidades
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
            cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS DOMICILIARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t\t  || AGREGAR NUEVO RECICLADOR AL REGISTRO || \n\n\n" ; 
            cout << "\t\t\t\t  "<<char(175)<<"La MUNICIPALIDAD ha sido REGISTRADA con EXITO!! ";
			retorna_principal_d () ;//Regresa al menú municipalidades
			break;
		case 6: // Registro especifico de una municipalidad según codigo
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
        	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS DOMICILIARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t || ELIMINAR DATOS DE UN RECICLADOR EN ESPEC"<<char(214)<<"FICO"<<" || \n\n\n" ;
            cout << "\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de DNI del reciclador a eliminar: ";
            do {
			cin  >> codigo_elim_d ;
			} while ( codigo_elim_d < 10000000 || codigo_elim_d > 99999999 ) ;									
			system ( "CLS" ) ; 
			elimina_un_reciclador (arbol, codigo_elim_d );
			cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS DOMICILIARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t || ELIMINAR DATOS DE UN RECICLADOR EN ESPEC"<<char(214)<<"FICO"<<" || \n\n\n" ;
			cout << "\t\t\t\t\t  "<<char(175)<<"El RECICLADOR ha sido ELIMINADO con EXITO!! ";      
			retorna_principal_d () ;//Regresa al menú municipalidades
            break;
        case 7: // Elimina todo el registro
        	SOLO_TITULO();//Pertenece a la libreria TITULO.h
        	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS DOMICILIARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t\t\t || ELIMINAR TODO EL REGISTRO"<<" || \n\n\n" ;
			if ( arbol != NULL)
      		{
        		arbol = NULL;
        		cout << "\t\t\t\t\t  "<<char(175)<<"TODO el REGISTRO ha sido ELIMINADO con EXITO!! ";     
      		}
      		else
        		cout << "\t\t\t\t\t  "<<char(175)<<"El REGISTRO esta vacio!! ";
          	retorna_principal_d () ;//Regresa al menú municipalidades            
        	break;
		case 8: // Atrás
        	interfaz_secundaria ();
        	break;
    }
    } while ( ( elegir_d < 1 ) || ( elegir_d > 9 ) );
}

int RES_DOMICILIOS()
{
	menu_principal_domiciliarios () ;	
}
//------------------------------------------------------- fin menú domiciliarios-------------------------------------------------------------

//MENÚ MUNICIPALIDADES
/* Inicio arbol_municipalidades ----------------------------------------------------------------------------------------------------------------------------------------------------*/
    void 	menu_principal_municipalidades () ;
	int 	regresar_m, elegir_m, numero_municipalidades = 0, opc_m, op_m, cod_m, codigo_elim_m;
	string 	a, b, c, d, denom_m, distrito_m, provincia_m, departamento_m;
	
struct info_ubicacion {
	string 	distrito ;
	string  provincia ;
	string 	departamento ;	
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
	string 	denominacion ;
	struct 	info_ubicacion ubicacion ;
	struct 	info_desechos_m P ; 
	struct  desechos_m D ;
	struct 	municipalidades *izquierda_m ;
	struct 	municipalidades *derecha_m ;						
};

municipalidades *arbol_m = NULL;  //creación e inicialización del árbol ABB

string desechos_m [6] = { "EN GENERAL (GRIS)", "ORGANICOS (MORADO)",	"VIDRIOS (VERDE)", 
						"PLASTICOS Y ENVASES METALICOS (AMARILLO)",	"PAPEL (AZUL)", "PELIGROSOS (ROJO)"};

void titulo_a_m ()
{
	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS MUNICIPALES "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
	cout << "\t\t\t\t     || REGISTRAR DATOS Y TIPO DE DESECHO DE LA MUNICIPALIDAD || \n\n" ;
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

//Función para crear un nuevo nodo del arbol ABB
municipalidades *crear_nodo(int c, string d , string u_d, string u_p, string u_de, int p_cant, int p_precio, int p_precio_total, string des)
	{
		municipalidades *nuevo_nodo = new municipalidades();
		
		nuevo_nodo-> codigo = c;
		nuevo_nodo-> denominacion = d;
		nuevo_nodo-> ubicacion.distrito = u_d;
		nuevo_nodo-> ubicacion.provincia = u_p;
		nuevo_nodo-> ubicacion.departamento = u_de;
		nuevo_nodo-> P.cantidad_kg = p_cant;	 
		nuevo_nodo-> P.precio_venta_kg = p_precio;
		nuevo_nodo-> P.precio_total = p_precio_total;
		nuevo_nodo-> D.desechos = des;
		nuevo_nodo-> izquierda_m = NULL;
		nuevo_nodo-> derecha_m = NULL;
		
		return nuevo_nodo;
	}
	
//Funcion para insertar datos dentro del arbol	
void insertar_nodo_muni (municipalidades *&arbol_m, int c, string d , string u_d, string u_p, string u_de, int p_cant, int p_precio, int p_precio_total, string des)
	{
		if (arbol_m == NULL)
		{
			municipalidades *n_nodo = crear_nodo (c, d , u_d, u_p, u_de, p_cant, p_precio, p_precio_total, des);
			arbol_m = n_nodo;
		}			
		else 
		{
			int raiz_muni = arbol_m->codigo;
			if (c < raiz_muni)
			{	//si el codigo es menor - izquierda m
				insertar_nodo_muni (arbol_m->izquierda_m, c, d , u_d, u_p, u_de, p_cant, p_precio, p_precio_total, des);	
			}
			else
			{	//si el codigo es mayor - derecha m 
				insertar_nodo_muni (arbol_m->derecha_m, c, d, u_d, u_p, u_de, p_cant, p_precio, p_precio_total, des);
			}				
		}						
	}
	
//Función que registra municipalidades	
void regis_recicladores_m ( int n_c ) // n_c=numero de municipalidades
{
	int codigo_m, precio_total_m, cantidad_kg_m, precio_venta_kg_m;
	string denominacion_m, distrito_m, provincia_m, departamento_m, D_desechos;	
	
	for ( int i = 0; i < n_c; i = i + 1 ) 
    {    	
    SOLO_TITULO();//Pertenece a la libreria TITULO.h	
	if ( n_c != 1 )
	{
		titulo_a_m ();	
    	cout << "\n\t\t\t\t\t      | REGISTRO DE MUNICIPALIDADES | \n" ;    
		cout << "\n\t\t\t\t\t       ---  MUNICIPALIDAD N"<<char(167)<<" " << i+1 << "  --- \n\n" ;
	}
	if ( n_c == 1 )
	{
	cout << "\n\n\n\n\n\n\n";
	}	
	cout << "\n\t\t\t\t|- Datos Municipales -| \n\n" ; 
	do {
	cout << "\t\t\t\t~~ Digite el n\xA3mero del CODIGO de la Municipalidad: "; 				
	cin  >> codigo_m;	
	} while ( codigo_m < 100000 || codigo_m > 999999 ) ;	 
	cout << "\t\t\t\t~~ Digite la Denominaci\xA2n de la Municipalidad : ";		fflush(stdin);
	getline(cin, denominacion_m);
	cout << "\n\n\t\t\t\t|- Ubicaci\xA2n de la Municipalidad -| \n\n"; 											
	cout << "\t\t\t\t~~ Digite el distrito al que pertenece    : ";				fflush(stdin);
	getline (cin, distrito_m) ;   	
	cout << "\t\t\t\t~~ Digite la provincia al que pertenece   : ";				fflush(stdin);
	getline (cin, provincia_m) ; 				  		
	cout << "\t\t\t\t~~ Digite el departamento al que pertenece: "; 			fflush(stdin);
	getline(cin, departamento_m) ;
			
	system ("CLS");
	SOLO_TITULO();
	
	if ( n_c != 1 )
		titulo_a_m ();
	else
	{   
		cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS MUNICIPALES "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
		cout << "\t\t\t\t  || AGREGAR NUEVA MUNICIPALIDAD AL REGISTRO || \n\n\n" ; 
	}
	
	cout << "\n\t\t\t\t| REGISTRO DE TIPO DE DESECHOS RECICLADOS DE LA "<< denominacion_m <<" | \n\n\n" ;
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
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [0] <<" DE LA "<< denominacion_m <<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			D_desechos = "\n\n\t\t\t\t\t  - DESECHOS EN GENERAL (GRIS) \n";
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;	
			cin  >> cantidad_kg_m ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;	
			cin  >> precio_venta_kg_m ;
						
			precio_total_m = cantidad_kg_m * precio_venta_kg_m;	
					
			system ( "CLS" ) ;			
   			break ;
   		case 2:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_a_m ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 5);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [1] <<" DE LA "<< denominacion_m  <<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			D_desechos = "\n\n\t\t\t\t\t  - DESECHOS ORGANICOS (MORADO) \n" ;
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;	
			cin  >> cantidad_kg_m ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;	
			cin  >> precio_venta_kg_m ;
						
			precio_total_m = cantidad_kg_m * precio_venta_kg_m;	
					
			system ( "CLS" ) ;			
   			break ;
		case 3:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_a_m ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 2);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [2] <<" DE LA "<< denominacion_m <<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			D_desechos = "\n\n\t\t\t\t\t  - DESECHOS VIDRIOS (VERDE) \n";
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;	
			cin  >> cantidad_kg_m ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;	
			cin  >> precio_venta_kg_m ;
						
			precio_total_m = cantidad_kg_m * precio_venta_kg_m;	
					
			system ( "CLS" ) ;			
   			break ;
		case 4:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_a_m ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 6);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [3] <<" DE LA "<< denominacion_m <<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			D_desechos = "\n\n\t\t\t\t\t  - DESECHOS PLASTICOS Y ENVASES METALICOS (AMARILLO)\n" ;
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;	
			cin  >> cantidad_kg_m ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;	
			cin  >> precio_venta_kg_m ;
						
			precio_total_m = cantidad_kg_m * precio_venta_kg_m;	
					
			system ( "CLS" ) ;			
   			break ;
		case 5:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_a_m ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 1);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [4] <<" DE LA "<< denominacion_m <<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			D_desechos = "\n\n\t\t\t\t\t  - DESECHOS PAPEL (AZUL)\n";
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;	
			cin  >> cantidad_kg_m ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;	
			cin  >> precio_venta_kg_m ;
						
			precio_total_m = cantidad_kg_m * precio_venta_kg_m;	
					
			system ( "CLS" ) ;			
   			break ;
		case 6:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_a_m ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 4);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [5] <<" DE LA "<< denominacion_m <<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			D_desechos = "\n\n\t\t\t\t\t  - DESECHOS PELIGROSOS (ROJO)\n";
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;	
			cin  >> cantidad_kg_m ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;	
			cin  >> precio_venta_kg_m ;
						
			precio_total_m = cantidad_kg_m * precio_venta_kg_m;	
					
			system ( "CLS" ) ;			
   			break ;
   		}
		   		
	insertar_nodo_muni ( arbol_m, codigo_m, denominacion_m , distrito_m, provincia_m, departamento_m, cantidad_kg_m, precio_venta_kg_m, precio_total_m, D_desechos);		   				
	
	}
}

//Funcion que permite ver en forma de arbol el codigo de las municipalidades
int X_m = 0;		
void ver_registro_arbol_muni ( municipalidades *arbol_m, int Y)//y=8
{  
    if ( arbol_m == NULL ) //evalúa si el arbol está vacio
      return;
    
  	X_m = X_m + 15;

    ver_registro_arbol_muni ( arbol_m -> izquierda_m, Y + 5 );

    gotoxy( 32 + X_m - Y , 5 + Y );
	cout << "	" << arbol_m -> codigo <<endl;
	
	gotoxy( 32 + X_m - Y , 6 + Y );
	cout << "	" << arbol_m -> ubicacion.distrito << endl << endl;
	
    ver_registro_arbol_muni ( arbol_m -> derecha_m, Y + 5 );    
}

//Funcion que muestra datos del registro segun codigo, denominacion, distrito, provincia, departamento
void ver_buscar_recicladores_m ( municipalidades *arbol_m)
{
	cout <<"\n\n\t\t\t\t -| DATOS DE LA MUNICIPALIDAD |- \n";	
	cout <<"\n\t\t\t	    Denominaci\xA2n: " << arbol_m -> denominacion ;
    cout <<"\n\t\t\t	    N"<<char(167)<<" CODIGO   : " <<arbol_m -> codigo ;
	cout <<"\n\t\t\t	    Ubicaci\xA2n   : " << arbol_m -> ubicacion.distrito <<" "<<arbol_m -> ubicacion.provincia <<" "<< arbol_m -> ubicacion.departamento ;
			
	cout << arbol_m -> D.desechos;
			
	cout << "\n\t\t\t\t	    CANTIDAD (Kg.)\t  PRECIO - VENTA(S/.)\t  TOTAL(S/.)\n " ;
	cout << "\n\t\t\t\t\t	    "<< arbol_m -> P.cantidad_kg <<"\t\t\t  " ;
    cout << arbol_m -> P.precio_venta_kg	<<" \t\t     " ;
    cout << arbol_m -> P.precio_total	;        
}

//Funcion que busca y muestra datos según 
bool buscar_arbol ( municipalidades *arbol_m, int c, string d , string u_d, string u_p, string u_de, int valor)
{
  	if (valor == 1) //Funcion que busca según codigo
  	{
  		if ( arbol_m == NULL )
    		return false ;
  		else
  		{
    		if ( arbol_m->codigo == c )
    		{
    		ver_buscar_recicladores_m (arbol_m);
    		buscar_arbol ( arbol_m -> izquierda_m, c, d , u_d, u_p, u_de, valor);  
     		buscar_arbol ( arbol_m -> derecha_m, c, d , u_d, u_p, u_de, valor );
			return true;			   
  			}
  
 		buscar_arbol ( arbol_m -> izquierda_m, c, d , u_d, u_p, u_de, valor);
 		buscar_arbol ( arbol_m -> derecha_m, c, d , u_d, u_p, u_de, valor);   
  		}
	}
	if (valor == 2) //Funcion que busca según denominacion
  	{
  		if ( arbol_m == NULL )
    		return false ;
  		else
  		{
    		if ( arbol_m->denominacion == d )
    		{
    		ver_buscar_recicladores_m (arbol_m);
    		buscar_arbol ( arbol_m -> izquierda_m, c, d , u_d, u_p, u_de, valor);  
     		buscar_arbol ( arbol_m -> derecha_m, c, d , u_d, u_p, u_de, valor );
			return true;    
  			}
  
 		buscar_arbol ( arbol_m -> izquierda_m, c, d , u_d, u_p, u_de, valor);
 		buscar_arbol ( arbol_m -> derecha_m, c, d , u_d, u_p, u_de, valor);   
  		}
	}			
	if (valor == 3) //Funcion que busca según distrito
  	{
  		if ( arbol_m == NULL )
    		return false ;
  		else
  		{
    		if ( arbol_m->ubicacion.distrito == u_d )
    		{
    		ver_buscar_recicladores_m (arbol_m);
    		buscar_arbol ( arbol_m -> izquierda_m, c, d , u_d, u_p, u_de, valor);  
     		buscar_arbol ( arbol_m -> derecha_m, c, d , u_d, u_p, u_de, valor );
			return true;    
  			}
  
 		buscar_arbol ( arbol_m -> izquierda_m, c, d , u_d, u_p, u_de, valor);
 		buscar_arbol ( arbol_m -> derecha_m, c, d , u_d, u_p, u_de, valor);   
  		}
	}
	if (valor == 4) //Funcion que busca según provincia
  	{
  		if ( arbol_m == NULL )
    		return false ;
  		else
  		{
    		if ( arbol_m->ubicacion.provincia == u_p )
    		{
    		ver_buscar_recicladores_m (arbol_m);
    		buscar_arbol ( arbol_m -> izquierda_m, c, d , u_d, u_p, u_de, valor);  
     		buscar_arbol ( arbol_m -> derecha_m, c, d , u_d, u_p, u_de, valor );
			return true;    
  			}
  
 		buscar_arbol ( arbol_m -> izquierda_m, c, d , u_d, u_p, u_de, valor);
 		buscar_arbol ( arbol_m -> derecha_m, c, d , u_d, u_p, u_de, valor);   
  		}
	}
	if (valor == 5) //Funcion que busca según departamento
  	{
  		if ( arbol_m == NULL )
    		return false ;
  		else
  		{
    		if ( arbol_m->ubicacion.departamento == u_de )
    		{
    		ver_buscar_recicladores_m (arbol_m);
    		buscar_arbol ( arbol_m -> izquierda_m, c, d , u_d, u_p, u_de, valor);  
     		buscar_arbol ( arbol_m -> derecha_m, c, d , u_d, u_p, u_de, valor );
			return true;    
  			}
  
 		buscar_arbol ( arbol_m -> izquierda_m, c, d , u_d, u_p, u_de, valor);
 		buscar_arbol ( arbol_m -> derecha_m, c, d , u_d, u_p, u_de, valor);   
  		}
	}	
}

//Funcion que muestra datos del registro total
void ver_recicladores_m ( municipalidades *arbol_m)
{
	if ( arbol_m == NULL)
		return ;

	ver_recicladores_m ( arbol_m -> izquierda_m);

	cout <<"\n\n\t\t\t\t -| DATOS DE LA MUNICIPALIDAD |- \n";	
	cout <<"\n\t\t\t	    Denominaci\xA2n: " << arbol_m -> denominacion ;
    cout <<"\n\t\t\t	    N"<<char(167)<<" CODIGO   : " <<arbol_m -> codigo ;
	cout <<"\n\t\t\t	    Ubicaci\xA2n   : " << arbol_m -> ubicacion.distrito <<" "<<arbol_m -> ubicacion.provincia <<" "<< arbol_m -> ubicacion.departamento ;
			
	cout << arbol_m -> D.desechos;
			
	cout << "\n\t\t\t\t	    CANTIDAD (Kg.)\t  PRECIO - VENTA(S/.)\t  TOTAL(S/.)\n " ;
	cout << "\n\t\t\t\t\t	    "<< arbol_m -> P.cantidad_kg <<"\t\t\t  " ;
    cout << arbol_m -> P.precio_venta_kg	<<" \t\t     " ;
    cout << arbol_m -> P.precio_total	;
    
    ver_recicladores_m ( arbol_m -> derecha_m);
}

//Funcion que une nodos despues de eliminar
municipalidades *union_arbol_muni (municipalidades *i, municipalidades *d)
	{
		if (i == NULL)
			return d;
		
		if (d == NULL)
			return i;
				
		municipalidades *centro = new (struct municipalidades);								
		centro = union_arbol_muni (i->derecha_m, d->izquierda_m);
		i->derecha_m = centro;
		d->izquierda_m = i;
		
		return d;
	}

//Funcion que elimina una municipalidad segun el codigo
void elimina_una_municipalidad (municipalidades *&arbol_m, int e)
{
		if (arbol_m == NULL)
			return;
						
		if (e < arbol_m->codigo)
		{
			elimina_una_municipalidad (arbol_m->izquierda_m, e);
		}						
		else 
		{
			if (e > arbol_m->codigo)
			{
				elimina_una_municipalidad (arbol_m->derecha_m, e);
			}
			else
			{
				municipalidades *p = new (struct municipalidades);	
				p = arbol_m;
				arbol_m = union_arbol_muni (arbol_m->izquierda_m, arbol_m->derecha_m);				
				numero_municipalidades = numero_municipalidades - 1;
				delete p;				 
			}			
		}									
}

void menu_principal_municipalidades ()
{
	do {
	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS MUNICIPALES "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
    cout << "\t\t\t 1. REGISTRAR DATOS Y TIPO DE DESECHO DE LA MUNICIPALIDAD\n\n" ;
    cout << "\t\t\t 2. REGISTRO DE CODIGOS DE LAS MUNICIPALIDADES - FORMA ARBOL  \n\n" ;
    cout << "\t\t\t 3. REGISTRO TOTAL DE LAS MUNICIPALIDADES Y TIPO DE DESECHO  \n\n" ;
    cout << "\t\t\t 4. BUSCAR MUNICIPALIDAD EN EL REGISTRO \n\n" ;    
	cout << "\t\t\t 5. AGREGAR NUEVA MUNICIPALIDAD AL REGISTRO					\n\n" ;
	cout << "\t\t\t 6. ELIMINAR DATOS DE UNA MUNICIPALIDAD EN ESPEC"<<char(214)<<"FICO\n\n" ;
	cout << "\t\t\t 7. ELIMINAR TODO EL REGISTRO\n\n" ;
	cout << "\t\t\t 8. ATR"<<char(181)<<"S                                    	\n\n" ;
    cout << "\t\t\t 9. SALIR                                    				\n\n" ;
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
            
        case 2: // Registro de codigos - forma arbol 
        	SOLO_TITULO();//Pertenece a la libreria TITULO.h
            cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS MUNICIPALES "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t    || REGISTRO DE CODIGOS DE LAS MUNICIPALIDADES - FORMA ARBOL || \n\n" ;
			ver_registro_arbol_muni ( arbol_m, 8 ) ;//Funcion que permite ver en forma de arbol el codigo de las municipalidades
			cout << "\n\n\n\n\n\n";			
			retorna_principal_m () ;//Regresa al menú municipalidades
			break;
			
        case 3: // Registro total de municipalidades 
        	SOLO_TITULO();//Pertenece a la libreria TITULO.h
            cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS MUNICIPALES "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t    || REGISTRO TOTAL DE LAS MUNICIPALIDADES Y TIPO DE DESECHO || \n\n" ;
			if ( arbol_m == NULL )
				cout << "\t\t\t\t    "<<char(175)<<"No hay Datos en el REGISTRO!";
			else
				ver_recicladores_m ( arbol_m );	
			retorna_principal_m () ;//Regresa al menú municipalidades
			break;
			
		case 4: // Busqueda de municipalidades
        	SOLO_TITULO();//Pertenece a la libreria TITULO.h
            cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS MUNICIPALES "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t\t    || BUSCAR MUNICIPALIDAD EN EL REGISTRO || \n\n" ;
			cout << "\t\t\t\t      1. CODIGO \n\n" ;
    		cout << "\t\t\t\t      2. DENOMINACION  \n\n" ;
    		cout << "\t\t\t\t      3. DISTRITO \n\n" ;
			cout << "\t\t\t\t      4. PROVINCIA \n\n" ;    
			cout << "\t\t\t\t      5. DEPARTAMENTO		\n\n" ;
			cout << "\t\t\t\t\t    "<<char(175)<<char(175)<<" Digite una opci\xA2n : " ;
			cin  >> op_m ;
			system ( "CLS" ) ;
			switch (op_m)
			{
				case 1:
					SOLO_TITULO();//Pertenece a la libreria TITULO.h
            		cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS MUNICIPALES "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
					cout << "\t\t\t\t\t  || BUSCAR MUNICIPALIDAD EN EL REGISTRO || \n\n\n" ;
					cout << "\t\t\t\t\t   || BUSQUEDA POR CODIGO EN EL REGISTRO || \n\n" ;
					cout << "\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero del CODIGO de la Municipalidad a buscar: ";
					cin  >> cod_m ;
					buscar_arbol ( arbol_m, cod_m, a , b, c, d, 1 );
					retorna_principal_m () ;//Regresa al menú municipalidades
            		break;	
				case 2:
					SOLO_TITULO();//Pertenece a la libreria TITULO.h
            		cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS MUNICIPALES "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
					cout << "\t\t\t\t\t  || BUSCAR MUNICIPALIDAD EN EL REGISTRO || \n\n\n" ;
					cout << "\t\t\t\t || BUSQUEDA POR DENOMINACION EN EL REGISTRO || \n\n" ;
					cout << "\t\t\t\t  "<<char(175)<<char(175)<<" Digite la DENOMINACION de la Municipalidad a buscar: ";			fflush(stdin);
					getline (cin, denom_m) ;	
					buscar_arbol ( arbol_m, 0, denom_m , b, c, d, 2 );
					retorna_principal_m () ;//Regresa al menú municipalidades
            		break;
				case 3:
					SOLO_TITULO();//Pertenece a la libreria TITULO.h
            		cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS MUNICIPALES "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
					cout << "\t\t\t\t\t  || BUSCAR MUNICIPALIDAD EN EL REGISTRO || \n\n\n" ;
					cout << "\t\t\t\t\t  || BUSQUEDA POR DISTRITO EN EL REGISTRO || \n\n" ;
					cout << "\t\t\t\t  "<<char(175)<<char(175)<<" Digite el DISTRITO de la Municipalidad a buscar: ";				fflush(stdin);
					getline ( cin, distrito_m) ;
					buscar_arbol ( arbol_m, 0, a , distrito_m, c, d, 3 );
					retorna_principal_m () ;//Regresa al menú municipalidades
            		break;
				case 4:
					SOLO_TITULO();//Pertenece a la libreria TITULO.h
            		cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS MUNICIPALES "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
					cout << "\t\t\t\t\t  || BUSCAR MUNICIPALIDAD EN EL REGISTRO || \n\n\n" ;
					cout << "\t\t\t\t\t || BUSQUEDA POR PROVINCIA EN EL REGISTRO || \n\n" ;
					cout << "\t\t\t\t  "<<char(175)<<char(175)<<" Digite la PROVINCIA de la Municipalidad a buscar: ";				fflush(stdin);
					getline ( cin, provincia_m) ;
					buscar_arbol ( arbol_m, 0, a , b, provincia_m, d, 4 );
					retorna_principal_m () ;//Regresa al menú municipalidades
            		break;
				case 5:	
					SOLO_TITULO();//Pertenece a la libreria TITULO.h
            		cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS MUNICIPALES "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
					cout << "\t\t\t\t\t  || BUSCAR MUNICIPALIDAD EN EL REGISTRO || \n\n\n" ;
					cout << "\t\t\t\t || BUSQUEDA POR DEPARTAMENTO EN EL REGISTRO || \n\n" ;
					cout << "\t\t\t\t  "<<char(175)<<char(175)<<" Digite el DEPARTAMENTO de la Municipalidad a buscar: ";			fflush(stdin);
					getline ( cin, departamento_m) ;
					buscar_arbol ( arbol_m, 0, a , b, c, departamento_m, 5 );					
					retorna_principal_m () ;//Regresa al menú municipalidades
            		break;
			}			
			break;
		case 5: //Agregar una nueva municipalidad al registro 
        	SOLO_TITULO();//Pertenece a la libreria TITULO.h
            cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS MUNICIPALES "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t  || AGREGAR NUEVA MUNICIPALIDAD AL REGISTRO || \n\n" ;        	
			regis_recicladores_m ( 1 ) ;//Función que registra municipalidades
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
            cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS MUNICIPALES "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t  || AGREGAR NUEVA MUNICIPALIDAD AL REGISTRO || \n\n\n" ; 
            cout << "\t\t\t\t  "<<char(175)<<"La MUNICIPALIDAD ha sido REGISTRADA con EXITO!! ";
			retorna_principal_m () ;//Regresa al menú municipalidades
			break;
		case 6: // Registro especifico de una municipalidad según codigo
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
        	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS MUNICIPALES "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t  || ELIMINAR DATOS DE UNA MUNICIPALIDAD EN ESPEC"<<char(214)<<"FICO"<<" || \n\n\n" ;
            cout << "\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de CODIGO de la municipalidad a eliminar: ";
            do {
			cin  >> codigo_elim_m ;
			} while ( codigo_elim_m < 100000 || codigo_elim_m > 999999 ) ;									
			system ( "CLS" ) ; 
			elimina_una_municipalidad (arbol_m, codigo_elim_m );
			cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS MUNICIPALES "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t\t  || ELIMINAR DATOS DE UNA MUNICIPALIDAD EN ESPEC"<<char(214)<<"FICO"<<" || \n\n\n" ;
			cout << "\t\t\t\t  "<<char(175)<<"La MUNICIPALIDAD ha sido ELIMINADA con EXITO!! ";      
			retorna_principal_m () ;//Regresa al menú municipalidades
            break;
		case 7: // Elimina todo el registro
        	SOLO_TITULO();//Pertenece a la libreria TITULO.h
        	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS MUNICIPALES "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t\t\t || ELIMINAR TODO EL REGISTRO"<<" || \n\n\n" ;
			if ( arbol_m != NULL)
      		{
        		arbol_m = NULL;
        		cout << "\t\t\t\t\t  "<<char(175)<<"TODO el REGISTRO ha sido ELIMINADO con EXITO!! ";     
      		}
      		else
        		cout << "\t\t\t\t\t  "<<char(175)<<"El REGISTRO esta vacio!! ";
          	retorna_principal_m () ;//Regresa al menú municipalidades           
        	break;
		case 8: // Atrás
        	interfaz_secundaria ();
        	break;;
    }
    } while ( ( elegir_m < 1 ) || ( elegir_m > 9 ) );
}

void RES_MUNICIPALIDADES ()
{
	menu_principal_municipalidades () ;
}
//------------------------------------------------------- fin menú municipalidades-------------------------------------------------------------

//MENÚ HOSPITALARIO
/* Inicio arbol_hospitales ----------------------------------------------------------------------------------------------------------------------------------------------------*/
    void 	menu_principal_hospitalarios () ;
	int 	regresar_h, elegir_h, numero_hospitales = 0, opc_h, op_h, cod_h, codigo_elim_h;
	string 	nomb_h, mode_h, a_h, b_h, c_h, d_h, e_h, distrito_h, provincia_h, departamento_h;
	
struct info_datos_h {
	string 	distrito_h ;
	string  provincia_h ;
	string 	departamento_h ;	
} ;

struct info_desechos_h {
	float 	cantidad_kg_h ;
	float  	precio_venta_kg_h ;
	float   precio_total_h ;
};

struct desechos_h {
	string	desechos_h ;
};

struct hospitales{
    int   	codigo_unico ;
	string 	nombres ;
	string 	modelo_h ;
	struct 	info_datos_h direccion ;
	struct 	info_desechos_h P ; 
	struct  desechos_h D ;
	struct 	hospitales *izquierda_h ;
	struct 	hospitales *derecha_h ;						
};

hospitales *arbol_h = NULL;  //creación e inicialización del árbol ABB

string desechos_h [6] = { "EN GENERAL (GRIS)", "ORGANICOS (MORADO)",	"VIDRIOS (VERDE)", 
						"PLASTICOS Y ENVASES METALICOS (AMARILLO)",	"PAPEL (AZUL)", "PELIGROSOS (ROJO)"};

void titulo_a_h ()
{
	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS HOSPITALARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
	cout << "\t\t\t\t     || REGISTRAR DATOS Y TIPO DE DESECHO DEL HOSPITAL || \n\n" ;
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

//Función para crear un nuevo nodo del arbol ABB
hospitales *crear_nodo_h (int c, string d, string mod, string u_d, string u_p, string u_de, float p_cant, float p_precio, float p_precio_total, string des)
	{
		hospitales *nuevo_nodo = new hospitales();
		
		nuevo_nodo-> codigo_unico = c;
		nuevo_nodo-> nombres = d;
		nuevo_nodo-> modelo_h = mod;
		nuevo_nodo-> direccion.distrito_h = u_d;
		nuevo_nodo-> direccion.provincia_h = u_p;
		nuevo_nodo-> direccion.departamento_h = u_de;
		nuevo_nodo-> P.cantidad_kg_h = p_cant;	 
		nuevo_nodo-> P.precio_venta_kg_h = p_precio;
		nuevo_nodo-> P.precio_total_h = p_precio_total;
		nuevo_nodo-> D.desechos_h = des;
		nuevo_nodo-> izquierda_h = NULL;
		nuevo_nodo-> derecha_h = NULL;
		
		return nuevo_nodo;
	}
	
//Funcion para insertar datos dentro del arbol	
void insertar_nodo_h (hospitales *&arbol_h, int c, string d, string mod, string u_d, string u_p, string u_de, float p_cant, float p_precio, float p_precio_total, string des)
	{
		if (arbol_h == NULL)
		{
			hospitales *n_nodo = crear_nodo_h (c, d, mod, u_d, u_p, u_de, p_cant, p_precio, p_precio_total, des);
			arbol_h = n_nodo;
		}			
		else 
		{
			int raiz_h = arbol_h->codigo_unico;
			if (c < raiz_h)
			{	//si el codigo es menor - izquierda h
				insertar_nodo_h (arbol_h->izquierda_h, c, d, mod, u_d, u_p, u_de, p_cant, p_precio, p_precio_total, des);	
			}
			else
			{	//si el codigo es mayor - derecha h 
				insertar_nodo_h (arbol_h->derecha_h, c, d, mod, u_d, u_p, u_de, p_cant, p_precio, p_precio_total, des);
			}				
		}						
	}
	
//Función que registra hospitales	
void regis_recicladores_h ( int n_h ) // n_h=numero de hospitales
{
	int codigo_h, precio_total_h, cantidad_kg_h, precio_venta_kg_h;
	string nombre_h, modelo_h, distrito_h, provincia_h, departamento_h, D_desechos_h;	
	
	for ( int i = 0; i < n_h; i = i + 1 ) 
    {    	
    SOLO_TITULO();//Pertenece a la libreria TITULO.h
	if ( n_h != 1 )
	{ 
		titulo_a_h ();
	    cout << "\n\t\t\t\t\t      | REGISTRO DE HOSPITALES | \n" ;    
		cout << "\n\t\t\t\t\t       ---  HOSPITAL N"<<char(167)<<" " << i+1 << "  --- \n\n" ;
	}
	if ( n_h == 1 )
	{
	cout << "\n\n\n\n\n\n\n";
	}
	cout << "\n\t\t\t\t|- Datos Hospitalarios -| \n\n" ; 
	do {
	cout << "\t\t\t\t~~ Digite el n\xA3mero de CODIGO UNICO del hospital: "; 				
	cin  >> codigo_h;	
	} while ( codigo_h < 1000 || codigo_h > 9999 ) ;
	cout << "\t\t\t\t~~ Digite el nombre del hospital     : ";				fflush(stdin);
	getline (cin, nombre_h) ;	 
	cout << "\t\t\t\t~~ Digite el modelo al que pertenece el hospital: ";	fflush(stdin);
	getline (cin, modelo_h);
	cout << "\n\n\t\t\t\t|- Ubicaci\xA2n del Hospital -| \n\n"; 											
	cout << "\t\t\t\t~~ Digite el distrito al que pertenece    : ";			fflush(stdin);
	cin >> distrito_h ;   	
	cout << "\t\t\t\t~~ Digite la provincia al que pertenece   : ";			fflush(stdin);
	cin >> provincia_h ; 				  		
	cout << "\t\t\t\t~~ Digite el departamento al que pertenece: "; 		fflush(stdin);
	getline (cin, departamento_h) ;
			
	system ("CLS");
	SOLO_TITULO();
	
	if ( n_h != 1 )
		titulo_a_h ();
	else
	{   
		cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS HOSPITALARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
		cout << "\t\t\t\t  || AGREGAR NUEVO HOSPITAL AL REGISTRO || \n\n\n" ; 
	}
	
	cout << "\n\t\t\t\t| REGISTRO DE TIPO DE DESECHOS RECICLADOS DE "<< nombre_h <<" "<< modelo_h <<" | \n\n\n" ;
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
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos_h [0] <<" DE "<< nombre_h <<" "<< modelo_h <<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			D_desechos_h = "\n\n\t\t\t\t\t  - DESECHOS EN GENERAL (GRIS) \n";
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;	
			cin  >> cantidad_kg_h ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;	
			cin  >> precio_venta_kg_h ;
						
			precio_total_h = cantidad_kg_h * precio_venta_kg_h;	
					
			system ( "CLS" ) ;			
   			break ;
   		case 2:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_a_h ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 5);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos_h [1] <<" DE "<< nombre_h <<" "<< modelo_h <<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			D_desechos_h = "\n\n\t\t\t\t\t  - DESECHOS ORGANICOS (MORADO) \n" ;
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;	
			cin  >> cantidad_kg_h ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;	
			cin  >> precio_venta_kg_h ;
						
			precio_total_h = cantidad_kg_h * precio_venta_kg_h;	
					
			system ( "CLS" ) ;			
   			break ;
		case 3:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_a_h ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 2);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos_h [2] <<" DE "<< nombre_h <<" "<< modelo_h <<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			D_desechos_h = "\n\n\t\t\t\t\t  - DESECHOS VIDRIOS (VERDE) \n";
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;	
			cin  >> cantidad_kg_h ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;	
			cin  >> precio_venta_kg_h ;
						
			precio_total_h = cantidad_kg_h * precio_venta_kg_h;	
					
			system ( "CLS" ) ;			
   			break ;
		case 4:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_a_h ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 6);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos_h [3] <<" DE "<< nombre_h <<" "<< modelo_h <<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			D_desechos_h = "\n\n\t\t\t\t\t  - DESECHOS PLASTICOS Y ENVASES METALICOS (AMARILLO)\n" ;
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;	
			cin  >> cantidad_kg_h ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;	
			cin  >> precio_venta_kg_h ;
						
			precio_total_h = cantidad_kg_h * precio_venta_kg_h;	
					
			system ( "CLS" ) ;			
   			break ;
		case 5:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_a_h ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 1);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos_h [4] <<" DE "<< nombre_h <<" "<< modelo_h <<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			D_desechos_h = "\n\n\t\t\t\t\t  - DESECHOS PAPEL (AZUL)\n";
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;	
			cin  >> cantidad_kg_h ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;	
			cin  >> precio_venta_kg_h ;
						
			precio_total_h = cantidad_kg_h * precio_venta_kg_h;	
					
			system ( "CLS" ) ;			
   			break ;
		case 6:
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
			titulo_a_h ();			
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 4);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos_h [5] <<" DE "<< nombre_h <<" "<< modelo_h <<" "<<char(244)<<" \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			D_desechos_h = "\n\n\t\t\t\t\t  - DESECHOS PELIGROSOS (ROJO)\n";
			cout << "\n\t\t\t\t\t  ~~ Digite la cantidad (Kg)        : " ;	
			cin  >> cantidad_kg_h ;
			cout << "\n\t\t\t\t\t  ~~ Digite el precio - venta (S/.) : " ;	
			cin  >> precio_venta_kg_h ;
						
			precio_total_h = cantidad_kg_h * precio_venta_kg_h;	
					
			system ( "CLS" ) ;			
   			break ;
   		}
		   		
	insertar_nodo_h ( arbol_h, codigo_h, nombre_h, modelo_h , distrito_h, provincia_h, departamento_h, cantidad_kg_h, precio_venta_kg_h, precio_total_h, D_desechos_h);		   				
	
	}
}

//Funcion que permite ver en forma de arbol el codigo-unico y modelo de los hospitales
int X_h = 0;		
void ver_registro_arbol_h ( hospitales *arbol_h, int Y)//y=8
{  
    if ( arbol_h == NULL ) //evalúa si el arbol está vacio
      return;
    
  	X_h = X_h + 15;

    ver_registro_arbol_h ( arbol_h -> izquierda_h, Y + 5 );

    gotoxy( 35 + X_h - Y , 5 + Y );
	cout << "	" << arbol_h -> codigo_unico <<endl;
	
	gotoxy( 35 + X_h - Y , 6 + Y );
	cout << "	" << arbol_h -> modelo_h << endl << endl;
	
    ver_registro_arbol_h ( arbol_h -> derecha_h, Y + 5 );    
}

//Funcion que muestra datos del registro segun codigo-unico, nombres, modelo, distrito, provincia, departamento
void ver_buscar_recicladores_h ( hospitales *arbol_h)
{
	cout <<"\n\t\t\t	    Nombre y modelo : " << arbol_h -> nombres <<" "<< arbol_h -> modelo_h ;
    cout <<"\n\t\t\t	    N"<<char(167)<<" CODIGO UNICO : " << arbol_h -> codigo_unico ;
	cout <<"\n\t\t\t	    Ubicaci\xA2n       : " << arbol_h -> direccion.distrito_h<<" "<< arbol_h -> direccion.provincia_h<<" "<< arbol_h->direccion.departamento_h ;
			
	cout << arbol_h -> D.desechos_h;
			
	cout << "\n\t\t\t\t	    CANTIDAD (Kg.)\t  PRECIO - VENTA(S/.)\t  TOTAL(S/.)\n " ;
	cout << "\n\t\t\t\t\t	    "<< arbol_h -> P.cantidad_kg_h <<"\t\t\t  " ;
    cout << arbol_h -> P.precio_venta_kg_h	<<" \t\t     " ;
    cout << arbol_h -> P.precio_total_h	;        
}

//Funcion que busca y muestra datos según codigo-unico, nombres, modelo, distrito, provincia, departamento
bool buscar_arbol_h ( hospitales *arbol_h, int c, string d, string mod, string u_d, string u_p, string u_de, int valor)
{
  	if (valor == 1) //Funcion que busca según codigo-unico
  	{
  		if ( arbol_h == NULL )
    		return false ;
  		else
  		{
    		if ( arbol_h->codigo_unico == c )
    		{
    		ver_buscar_recicladores_h (arbol_h);
    		buscar_arbol_h ( arbol_h -> izquierda_h, c, d, mod, u_d, u_p, u_de, valor);  
     		buscar_arbol_h ( arbol_h -> derecha_h, c, d, mod, u_d, u_p, u_de, valor);
			return true;			   
  			}
  
 		buscar_arbol_h ( arbol_h -> izquierda_h, c, d, mod, u_d, u_p, u_de, valor);  
     	buscar_arbol_h ( arbol_h -> derecha_h, c, d, mod, u_d, u_p, u_de, valor);   
  		}
	}
	if (valor == 2) //Funcion que busca según nombres del hospital
  	{
  		if ( arbol_h == NULL )
    		return false ;
  		else
  		{
    		if ( arbol_h->nombres == d )
    		{
    		ver_buscar_recicladores_h (arbol_h);
    		buscar_arbol_h ( arbol_h -> izquierda_h, c, d, mod, u_d, u_p, u_de, valor);  
     		buscar_arbol_h ( arbol_h -> derecha_h, c, d, mod, u_d, u_p, u_de, valor);
			return true;			   
  			}
  
 		buscar_arbol_h ( arbol_h -> izquierda_h, c, d, mod, u_d, u_p, u_de, valor);  
     	buscar_arbol_h ( arbol_h -> derecha_h, c, d, mod, u_d, u_p, u_de, valor);   
  		}
	}			
	if (valor == 3) //Funcion que busca según modelo del hospital
  	{
  		if ( arbol_h == NULL )
    		return false ;
  		else
  		{
    		if ( arbol_h->modelo_h == mod )
    		{
    		ver_buscar_recicladores_h (arbol_h);
    		buscar_arbol_h ( arbol_h -> izquierda_h, c, d, mod, u_d, u_p, u_de, valor);  
     		buscar_arbol_h ( arbol_h -> derecha_h, c, d, mod, u_d, u_p, u_de, valor);
			return true;			   
  			}
  
 		buscar_arbol_h ( arbol_h -> izquierda_h, c, d, mod, u_d, u_p, u_de, valor);  
     	buscar_arbol_h ( arbol_h -> derecha_h, c, d, mod, u_d, u_p, u_de, valor);   
  		}
	}
	if (valor == 4) //Funcion que busca según distrito
  	{
  		if ( arbol_h == NULL )
    		return false ;
    	else
  		{
    		if ( arbol_h->direccion.distrito_h == u_d )
    		{
    		ver_buscar_recicladores_h (arbol_h);
    		buscar_arbol_h ( arbol_h -> izquierda_h, c, d, mod, u_d, u_p, u_de, valor);  
     		buscar_arbol_h ( arbol_h -> derecha_h, c, d, mod, u_d, u_p, u_de, valor);
			return true;			   
  			}
  
 		buscar_arbol_h ( arbol_h -> izquierda_h, c, d, mod, u_d, u_p, u_de, valor);  
     	buscar_arbol_h ( arbol_h -> derecha_h, c, d, mod, u_d, u_p, u_de, valor);   
  		}
	}	
	if (valor == 5) //Funcion que busca según provincia
  	{
  		if ( arbol_h == NULL )
    		return false ;
  		else
  		{
    		if ( arbol_h->direccion.provincia_h == u_p )
    		{
    		ver_buscar_recicladores_h (arbol_h);
    		buscar_arbol_h ( arbol_h -> izquierda_h, c, d, mod, u_d, u_p, u_de, valor);  
     		buscar_arbol_h ( arbol_h -> derecha_h, c, d, mod, u_d, u_p, u_de, valor);
			return true;			   
  			}
  
 		buscar_arbol_h ( arbol_h -> izquierda_h, c, d, mod, u_d, u_p, u_de, valor);  
     	buscar_arbol_h ( arbol_h -> derecha_h, c, d, mod, u_d, u_p, u_de, valor);   
  		}
	}	
	if (valor == 6) //Funcion que busca según departamento
  	{
  		if ( arbol_h == NULL )
    		return false ;
  		else
  		{
    		if ( arbol_h->direccion.departamento_h == u_de )
    		{
    		ver_buscar_recicladores_h (arbol_h);
    		buscar_arbol_h ( arbol_h -> izquierda_h, c, d, mod, u_d, u_p, u_de, valor);  
     		buscar_arbol_h ( arbol_h -> derecha_h, c, d, mod, u_d, u_p, u_de, valor);
			return true;			   
  			}
  
 		buscar_arbol_h ( arbol_h -> izquierda_h, c, d, mod, u_d, u_p, u_de, valor);  
     	buscar_arbol_h ( arbol_h -> derecha_h, c, d, mod, u_d, u_p, u_de, valor);   
  		}
	}	
}

//Funcion que muestra datos del registro total de hospitales
void ver_recicladores_h ( hospitales *arbol_h)
{
	if ( arbol_h == NULL)
		return ;

	ver_recicladores_h  ( arbol_h -> izquierda_h);

	cout <<"\n\n\t\t\t\t -| DATOS PERSONALES DEL HOSPITAL |- \n";	
	cout <<"\n\t\t\t	    Nombre y modelo : " << arbol_h -> nombres <<" "<< arbol_h -> modelo_h ;
    cout <<"\n\t\t\t	    N"<<char(167)<<" CODIGO UNICO : " << arbol_h -> codigo_unico ;
	cout <<"\n\t\t\t	    Ubicaci\xA2n       : " << arbol_h -> direccion.distrito_h<<" "<< arbol_h -> direccion.provincia_h<<" "<< arbol_h->direccion.departamento_h ;
			
	cout << arbol_h -> D.desechos_h;
			
	cout << "\n\t\t\t\t	    CANTIDAD (Kg.)\t  PRECIO - VENTA(S/.)\t  TOTAL(S/.)\n " ;
	cout << "\n\t\t\t\t\t	    "<< arbol_h -> P.cantidad_kg_h <<"\t\t\t  " ;
    cout << arbol_h -> P.precio_venta_kg_h	<<" \t\t     " ;
    cout << arbol_h -> P.precio_total_h	;
    
    ver_recicladores_h ( arbol_h -> derecha_h);
}

//Funcion invocada dentro de la funcion elimina un hospital segun el codigo
hospitales *union_arbol_h (hospitales *i, hospitales *d)
	{
		if (i == NULL)
			return d;
		
		if (d == NULL)
			return i;
				
		hospitales *centro = new (struct hospitales);								
		centro = union_arbol_h (i->derecha_h, d->izquierda_h);
		i->derecha_h = centro;
		d->izquierda_h = i;
		
		return d;
	}

//Funcion que elimina un hospital segun el codigo-unico
void elimina_un_hospital (hospitales *&arbol_h, int e)
{
		if (arbol_h == NULL)
			return;
						
		if (e < arbol_h->codigo_unico)
		{
			elimina_un_hospital (arbol_h->izquierda_h, e);
		}						
		else 
		{
			if (e > arbol_h->codigo_unico)
			{
				elimina_un_hospital (arbol_h->derecha_h, e);
			}
			else
			{
				hospitales *p = new (struct hospitales);	
				p = arbol_h;
				arbol_h = union_arbol_h (arbol_h->izquierda_h, arbol_h->derecha_h);				
				numero_hospitales = numero_hospitales - 1;
				delete p;				 
			}			
		}									
}

void menu_principal_hospitalarios ()
{
	do {
	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS HOSPITALARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
    cout << "\t\t\t 1. REGISTRAR DATOS Y TIPO DE DESECHO DEL HOSPITAL 					\n\n" ;
    cout << "\t\t\t 2. REGISTRO DE CODIGO-UNICO DEL HOSPITAL - FORMA ARBOL  			\n\n" ;
    cout << "\t\t\t 3. REGISTRO TOTAL DE LOS HOSPITALES Y TIPO DE DESECHO  				\n\n" ;
    cout << "\t\t\t 4. BUSCAR HOSPITAL EN EL REGISTRO 									\n\n" ;    
	cout << "\t\t\t 5. AGREGAR NUEVO HOSPITAL AL REGISTRO								\n\n" ;
	cout << "\t\t\t 6. ELIMINAR DATOS DE UN HOSPITAL EN ESPEC"<<char(214)<<"FICO		\n\n" ;
	cout << "\t\t\t 7. ELIMINAR TODO EL REGISTRO										\n\n" ;
	cout << "\t\t\t 8. ATR"<<char(181)<<"S                                    			\n\n" ;
    cout << "\t\t\t 9. SALIR                                    						\n\n" ;
    cout << "\t\t	 "<<char(175)<<char(175)<<" Digite una opci\xA2n : " ;
    cin  >> elegir_h ;														
	system ( "CLS" ) ;
   
	switch ( elegir_h )
    {
        case 1: // Registrar hospitales
        	SOLO_TITULO();//Pertenece a la libreria TITULO.h
            do { 
            titulo_a_h () ;
			cout << "\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de hospitales que registrar\xA0: ";
			cin  >> numero_hospitales ;
			system ( "CLS" ) ;
			} while ( numero_hospitales < 1 ) ;			
			regis_recicladores_h ( numero_hospitales ) ;//Función que registra hospitales
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
            titulo_a_h ();
			retorna_principal_h () ;//Regresa al menú hospitalario
            break;
            
        case 2: // Registro de codigos-unico y modelo - forma arbol 
        	SOLO_TITULO();//Pertenece a la libreria TITULO.h
            cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS HOSPITALARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t    || REGISTRO DE CODIGO-UNICO DEL HOSPITAL - FORMA ARBOL || \n\n" ;
			ver_registro_arbol_h ( arbol_h, 8 ) ;//Funcion que permite ver en forma de arbol el codigo-unico y modelo de los hospitales
			cout << "\n\n\n\n\n\n";			
			retorna_principal_h () ;//Regresa al menú hospitalario
			break;
			
        case 3: // Registro total de hospitales 
        	SOLO_TITULO();//Pertenece a la libreria TITULO.h
            cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS HOSPITALARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t    || REGISTRO TOTAL DE LOS HOSPITALES Y TIPO DE DESECHO || \n\n" ;
			if ( arbol_h == NULL )
				cout << "\t\t\t\t    "<<char(175)<<"No hay Datos en el REGISTRO HOSPITALARIO!";
			else
				ver_recicladores_h ( arbol_h );	
			retorna_principal_h () ;//Regresa al menú hospitalario
			break;
			
		case 4: // Busqueda de hospitales
        	SOLO_TITULO();//Pertenece a la libreria TITULO.h
            cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS HOSPITALARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t\t    || BUSCAR HOSPITAL EN EL REGISTRO || \n\n" ;
			cout << "\t\t\t\t      1. CODIGO-UNICO \n\n" ;
    		cout << "\t\t\t\t      2. NOMBRE  \n\n" ;
    		cout << "\t\t\t\t      3. MODELO  \n\n" ;
    		cout << "\t\t\t\t      4. DISTRITO \n\n" ;
			cout << "\t\t\t\t      5. PROVINCIA \n\n" ;    
			cout << "\t\t\t\t      6. DEPARTAMENTO		\n\n" ;
			cout << "\t\t\t\t\t    "<<char(175)<<char(175)<<" Digite una opci\xA2n : " ;
			cin  >> op_h ;
			system ( "CLS" ) ;
			switch (op_h)
			{
				case 1:
					SOLO_TITULO();//Pertenece a la libreria TITULO.h
            		cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS HOSPITALARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
					cout << "\t\t\t\t\t  || BUSCAR HOSPITAL EN EL REGISTRO || \n\n\n" ;
					cout << "\t\t\t\t\t   || BUSQUEDA POR CODIGO-UNICO EN EL REGISTRO || \n\n" ;
					cout << "\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de CODIGO-UNICO del hospital: ";
					cin  >> cod_h ;
					buscar_arbol_h ( arbol_h, cod_h, a_h , b_h, c_h, d_h, e_h, 1 ); 
					retorna_principal_h () ;//Regresa al menú hospitalario
            		break;	
				case 2:
					SOLO_TITULO();//Pertenece a la libreria TITULO.h
            		cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS HOSPITALARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
					cout << "\t\t\t\t\t  || BUSCAR HOSPITAL EN EL REGISTRO || \n\n\n" ;
					cout << "\t\t\t\t || BUSQUEDA POR NOMBRE EN EL REGISTRO || \n\n" ;
					cout << "\t\t\t\t  "<<char(175)<<char(175)<<" Digite el NOMBRE del hospital: ";							fflush(stdin);
					getline ( cin, nomb_h ) ;
					buscar_arbol_h ( arbol_h, 0, nomb_h, a_h , b_h, c_h, d_h, 2 );
					retorna_principal_h () ;//Regresa al menú hospitalario
            		break;
            	case 3:
					SOLO_TITULO();//Pertenece a la libreria TITULO.h
            		cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS HOSPITALARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
					cout << "\t\t\t\t\t  || BUSCAR HOSPITAL EN EL REGISTRO || \n\n\n" ;
					cout << "\t\t\t\t || BUSQUEDA POR MODELO EN EL REGISTRO || \n\n" ;
					cout << "\t\t\t\t  "<<char(175)<<char(175)<<" Digite el MODELO al que pertenece el hospital: ";			fflush(stdin);
					getline ( cin, mode_h ) ;
					buscar_arbol_h ( arbol_h, 0, a_h , mode_h, b_h, c_h, e_h, 3 );
					retorna_principal_h () ;//Regresa al menú hospitalario
            		break;
				case 4:
					SOLO_TITULO();//Pertenece a la libreria TITULO.h
            		cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS HOSPITALARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
					cout << "\t\t\t\t\t  || BUSCAR HOSPITAL EN EL REGISTRO || \n\n\n" ;
					cout << "\t\t\t\t\t  || BUSQUEDA POR DISTRITO EN EL REGISTRO || \n\n" ;
					cout << "\t\t\t\t  "<<char(175)<<char(175)<<" Digite el DISTRITO del hospital a buscar: ";				fflush(stdin);
					getline ( cin, distrito_h) ;
					buscar_arbol_h ( arbol_h, 0, a_h , b_h, distrito_h, c_h, e_h, 4 );
					retorna_principal_h () ;//Regresa al menú hospitalario
            		break;
				case 5:
					SOLO_TITULO();//Pertenece a la libreria TITULO.h
            		cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS HOSPITALARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
					cout << "\t\t\t\t\t  || BUSCAR HOSPITAL EN EL REGISTRO || \n\n\n" ;
					cout << "\t\t\t\t\t || BUSQUEDA POR PROVINCIA EN EL REGISTRO || \n\n" ;
					cout << "\t\t\t\t  "<<char(175)<<char(175)<<" Digite la PROVINCIA del hospital a buscar: ";				fflush(stdin);
					getline ( cin, provincia_h );
					buscar_arbol_h ( arbol_h, 0, a_h , b_h, c_h, provincia_h, e_h, 5 );
					retorna_principal_h () ;//Regresa al menú hospitalario
            		break;
				case 6:	
					SOLO_TITULO();//Pertenece a la libreria TITULO.h
            		cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS HOSPITALARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
					cout << "\t\t\t\t\t  || BUSCAR HOSPITAL EN EL REGISTRO || \n\n\n" ;
					cout << "\t\t\t\t || BUSQUEDA POR DEPARTAMENTO EN EL REGISTRO || \n\n" ;
					cout << "\t\t\t\t  "<<char(175)<<char(175)<<" Digite el DEPARTAMENTO del hospital a buscar: ";			fflush(stdin);
					getline ( cin, departamento_h ) ;
					buscar_arbol_h ( arbol_h, 0, a_h , b_h, c_h, d_h,departamento_h, 6 );					
					retorna_principal_h () ;//Regresa al menú hospitalario
            		break;
			}			
			break;
		case 5: //Agregar un nuevo hospital al registro 
        	SOLO_TITULO();//Pertenece a la libreria TITULO.h
            cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS HOSPITALARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t  || AGREGAR NUEVO HOSPITAL AL REGISTRO || \n\n" ;        	
			regis_recicladores_h ( 1 ) ;//Función que registra hospitales
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
            cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS HOSPITALARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t  || AGREGAR NUEVO HOSPITAL AL REGISTRO || \n\n\n" ; 
            cout << "\t\t\t\t  "<<char(175)<<"El HOSPITAL ha sido REGISTRADO con EXITO!! ";
			retorna_principal_h () ;//Regresa al menú hospitalario
			break;
		case 6: // Elimina un hospital según codigo-unico
			SOLO_TITULO();//Pertenece a la libreria TITULO.h
        	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS HOSPITALARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t  || ELIMINAR DATOS DE UN HOSPITAL EN ESPEC"<<char(214)<<"FICO" <<" || \n\n\n" ;
            cout << "\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de CODIGO-UNICO del hospital a eliminar: ";
            do {
			cin  >> codigo_elim_h ;
			} while ( codigo_elim_h < 1000 || codigo_elim_h > 9999 ) ;									
			system ( "CLS" ) ; 
			elimina_un_hospital (arbol_h, codigo_elim_h );
			cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS HOSPITALARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t\t  || ELIMINAR DATOS DE UN HOSPITAL EN ESPEC"<<char(214)<<"FICO" <<" || \n\n\n" ;
			cout << "\t\t\t\t  "<<char(175)<<"El HOSPITAL ha sido ELIMINADO con EXITO!! ";      
			retorna_principal_h () ;//Regresa al menú hospitalario
            break;
		case 7: // Elimina todo el registro
        	SOLO_TITULO();//Pertenece a la libreria TITULO.h
        	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS HOSPITALARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t\t\t || ELIMINAR TODO EL REGISTRO"<<" || \n\n\n" ;
			if ( arbol_h != NULL)
      		{
        		arbol_h = NULL;
        		cout << "\t\t\t\t\t  "<<char(175)<<"TODO el REGISTRO ha sido ELIMINADO con EXITO!! ";     
      		}
      		else
        		cout << "\t\t\t\t\t  "<<char(175)<<"El REGISTRO esta vacio!! ";
          	retorna_principal_h () ;//Regresa al menú hospitalario           
        	break;
		case 8: // Atrás
        	interfaz_secundaria ();
        	break;;
    }
    } while ( ( elegir_h < 1 ) || ( elegir_h > 9 ) );
}

int RES_HOSPITALARIOS ()
{
	menu_principal_hospitalarios ();	
}
//------------------------------------------------------- fin menú hospitalario-------------------------------------------------------------

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
