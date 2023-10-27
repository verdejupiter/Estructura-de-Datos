#include <iostream>
#include <conio.h>
#include <string.h>
#include "TITULO.h"
#include "I-PRINCIPAL.h"
#include "I-SECUNDARIA.h"

using namespace std ;
void interfaz_secundaria ();

//MENÚ DOMICILIARIOS
    int 	elegir, regresar, establece = 0; ; 
	void 	menu_principal_domiciliarios () ;
	int 	i, d, opc,valor,  numero_recicladores = 0;
	
struct info_datos {
	char 	calle [30] ;
	int  	numero ;
	char 	urbanizacion [30] ;	
} ;

struct solo_material {
	int 	dni ;
	char 	nombre_material [30] ;
	int	 	cantidad ;
	float  	precio_venta ;
	float  	sub_total ;
} ;

struct varios_materiales {
	int	   	cifra_materiales ;
	struct 	solo_material S [30] ;
	float   precio_total ;
} ;

struct desechos {
	string	desechos ;
};
struct recicladores{
    int   	dni ;
	char   	nombres [30] ;
	char   	apellidos [30] ;
	struct 	info_datos direccion ;
	struct 	varios_materiales P ; 
	struct  desechos D ;		
}reciclador [30], numero ;	//struct recicladores numero;

string desechos [6] = { "EN GENERAL (GRIS)", "ORGANICOS (MORADO)",	"VIDRIOS (VERDE)", 
						"PLASTICOS Y ENVASES METALICOS (AMARILLO)",	"PAPEL (AZUL)", "PELIGROSOS (ROJO)"};

void titulo_a ()
{
	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS DOMICILIARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
	cout << "\t\t\t       || REGISTRAR DATOS PERSONALES Y MATERIALES DEL RECICLADOR || \n\n" ;
}

void retorna_principal ()
{
    cout << "\n\n\n\n\n\t\t\t      Digite | 1 | para regresar al "<<char(174)<<"| MENé RESIDUOS DOMICILIARIOS |"<<char(175)<<" \n\n" ;
    cout << "\n\t\t\t\t\t        Digite | 0 | para "<<char(174)<<"| SALIR |"<<char(175)<<" \n\n\t\t\t\t\t\t\t "<<char(174)<<char(175)<<" " ;
    cin  >> regresar ; 	
			
	system ( "CLS" ) ;
	
	if ( regresar == 1 ) 
		{SOLO_TITULO();
		menu_principal_domiciliarios () ;
		}
}

void registrar_materiales ( int p , int s, int d, int color ) //p = # recicladores , s = # materiales
{
	reciclador[p].P.precio_total = 0;

	for ( int i = 0; i < s; i = i + 1 )
    {
    SOLO_TITULO();
    titulo_a ();
    cout << "\n\t\t\t\t| REGISTRO DE MATERIALES RECICLADOS DE "<<reciclador[p].nombres<<" "<<reciclador[p].apellidos<<" | \n\n" ;
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), color);
	cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [d] <<" "<<char(244)<<" \n\n " ;
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 7);
	cout << "\n\t\t\t\t\t\t   :: MATERIAL N"<<char(167)<<" " << i+1 <<" :: \n\n " ;
	cout << "\n\t\t\t\t  ~~ Digite el nombre del material reciclado: " ;				fflush(stdin);
	cin.getline(reciclador[p].P.S[i].nombre_material, 30 , '\n' ) ; 			
	cout << "\t\t\t\t  ~~ Digite la cantidad (Kg)                : " ;				fflush(stdin);
	cin  >> reciclador[p].P.S[i].cantidad ;						  				
	cout << "\t\t\t\t  ~~ Digite el precio - venta (S/.)         : " ;				fflush(stdin);
	cin  >> reciclador[p].P.S[i].precio_venta ;	
					  				
	system ( "CLS" );	
	
	reciclador[p].P.S[i].sub_total = reciclador[p].P.S[i].cantidad * reciclador[p].P.S[i].precio_venta ; 
	
	reciclador[p].P.precio_total = reciclador[p].P.precio_total + reciclador[p].P.S[i].sub_total ;
	}
}

void regis_recicladores ( int n_c )
{
	for ( int i = 0; i < n_c; i = i + 1 ) // n_c=numero de recicladores
    {
    SOLO_TITULO();
	titulo_a ();
    cout << "\n\t\t\t\t\t      | REGISTRO DE RECICLADORES | \n" ;
	cout << "\n\t\t\t\t\t       ---  RECICLADOR N"<<char(167)<<" " << i+1 << "  --- \n\n" ; 	fflush(stdin);
	cout << "\n\t\t\t\t|- Datos Personales -| \n\n" ; 
	cout << "\t\t\t\t~~ Digite el n\xA3mero de DNI del reciclador: " ; 		fflush(stdin);
	cin  >> reciclador[i].dni; 						 
	cout << "\t\t\t\t~~ Digite los nombres del reciclador     : " ;			fflush(stdin);
	cin.getline ( reciclador[i].nombres,30,'\n' ) ;		
	cout << "\t\t\t\t~~ Digite los apellidos del reciclador   : " ;			fflush(stdin);
	cin.getline ( reciclador[i].apellidos,30,'\n' ) ; 			
	cout << "\n\n\t\t\t\t|- Direcci\xA2n de la vivienda -| \n\n" ; 											
	cout << "\t\t\t\t~~ Digite el nombre de la calle          : " ;			fflush(stdin);
	cin.getline ( reciclador[i].direccion.calle,30,'\n' ) ;   	
	cout << "\t\t\t\t~~ Digite el n\xA3mero de la casa           : " ;			fflush(stdin);
	cin  >> reciclador[i].direccion.numero ; 				  		
	cout << "\t\t\t\t~~ Digite la urbanizaci\xA2n o distrito     : " ; 		fflush(stdin);
	cin.getline ( reciclador[i].direccion.urbanizacion,30,'\n') ;
	
	system ("CLS");
	SOLO_TITULO();
	titulo_a ();
	cout << "\n\t\t\t\t| REGISTRO DE MATERIALES RECICLADOS DE "<<reciclador[i].nombres<<" "<<reciclador[i].apellidos<<" | \n\n\n" ;
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
			SOLO_TITULO();
			titulo_a ();
			cout << "\n\t\t\t\t| REGISTRO DE MATERIALES RECICLADOS DE "<<reciclador[i].nombres<<" "<<reciclador[i].apellidos<<" | \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 8);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [0] <<" "<<char(244)<<" \n\n " ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 7);
			cout << "\n\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de materiales a registrar: " ;			fflush(stdin);
			cin  >> reciclador[i].P.cifra_materiales ;
			reciclador[i].D.desechos = "\n\n\t\t\t\t -| DESECHOS EN GENERAL (GRIS) |- \n";								
			system ( "CLS" ) ;
			registrar_materiales ( i , reciclador[i].P.cifra_materiales, 0 , 8 ) ;
			break ;
		case 2:
			SOLO_TITULO();
			titulo_a ();
			cout << "\n\t\t\t\t| REGISTRO DE MATERIALES RECICLADOS DE "<<reciclador[i].nombres<<" "<<reciclador[i].apellidos<<" | \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 5);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [1] <<" "<<char(244)<<" \n\n " ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 7);
			cout << "\n\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de materiales a registrar: " ;			fflush(stdin);
			cin  >> reciclador[i].P.cifra_materiales ;
			reciclador[i].D.desechos = "\n\n\t\t\t\t -| DESECHOS ORGANICOS (MORADO) |- \n";									
			system ( "CLS" ) ;
			registrar_materiales( i , reciclador[i].P.cifra_materiales, 1 , 5 ) ;
			break ;
		case 3:
			SOLO_TITULO();
			titulo_a ();
			cout << "\n\t\t\t\t| REGISTRO DE MATERIALES RECICLADOS DE "<<reciclador[i].nombres<<" "<<reciclador[i].apellidos<<" | \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 2);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [2] <<" "<<char(244)<<" \n\n " ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 7);
			cout << "\n\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de materiales a registrar: " ;			fflush(stdin);
			cin  >> reciclador[i].P.cifra_materiales ;
			reciclador[i].D.desechos = "\n\n\t\t\t\t -| DESECHOS VIDRIOS (VERDE) |- \n";								
			system ( "CLS" ) ;
			registrar_materiales( i , reciclador[i].P.cifra_materiales, 2 , 2 ) ;
			break ;
		case 4:
			SOLO_TITULO();
			titulo_a ();
    		cout << "\n\t\t\t\t| REGISTRO DE MATERIALES RECICLADOS DE "<<reciclador[i].nombres<<" "<<reciclador[i].apellidos<<" | \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 6);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [3] <<" "<<char(244)<<" \n\n " ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 7);
			cout << "\n\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de materiales a registrar: " ;			fflush(stdin);
			cin  >> reciclador[i].P.cifra_materiales ;
			reciclador[i].D.desechos = "\n\n\t\t\t\t -| DESECHOS PLASTICOS Y ENVASES METALICOS (AMARILLO) |- \n";								
			system ( "CLS" ) ;
			registrar_materiales( i , reciclador[i].P.cifra_materiales, 3 , 6 ) ;
			break ;
		case 5:
			SOLO_TITULO();
			titulo_a ();
    		cout << "\n\t\t\t\t| REGISTRO DE MATERIALES RECICLADOS DE "<<reciclador[i].nombres<<" "<<reciclador[i].apellidos<<" | \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 1);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [4] <<" "<<char(244)<<" \n\n " ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			cout << "\n\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de materiales a registrar: " ;			fflush(stdin);
			cin  >> reciclador[i].P.cifra_materiales ;
			reciclador[i].D.desechos = "\n\n\t\t\t\t -| DESECHOS PAPEL (AZUL) |- \n";								
			system ( "CLS" ) ;
			registrar_materiales( i , reciclador[i].P.cifra_materiales, 4 , 1 ) ;
			break ;
		case 6:
			SOLO_TITULO();
			titulo_a ();
    		cout << "\n\t\t\t\t| REGISTRO DE MATERIALES RECICLADOS DE "<<reciclador[i].nombres<<" "<<reciclador[i].apellidos<<" | \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 4);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos [5] <<" "<<char(244)<<" \n\n " ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			cout << "\n\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de materiales a registrar: " ;			fflush(stdin);
			cin  >> reciclador[i].P.cifra_materiales ;
			reciclador[i].D.desechos = "\n\n\t\t\t\t -| DESECHOS PELIGROSOS (ROJO) |- \n";								
			system ( "CLS" ) ;
			registrar_materiales( i , reciclador[i].P.cifra_materiales, 5 , 4 ) ;
			break ;
		}
	}
}

void ver_materiales (int numero_recicladores)
{
	cout << reciclador[numero_recicladores].D.desechos ;
    
	cout << "\n\t\t\t	    MATERIALES\t  CANTIDAD\t  PRECIO - VENTA\tSUBTOTAL\n " ;
    
    for ( int i=0; i < reciclador[numero_recicladores].P.cifra_materiales ; i = i + 1 ) 
    {
    cout << "\n\t\t\t	    "<<reciclador[numero_recicladores].P.S[i].nombre_material <<"\t  " ;
    cout << reciclador[numero_recicladores].P.S[i].cantidad		<<" \t\t  " ;
    cout << reciclador[numero_recicladores].P.S[i].precio_venta	<<" \t\t\t" ;
    cout << reciclador[numero_recicladores].P.S[i].sub_total ;
    }
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t--------- " ;
    cout << "\n\t\t\t	    TOTAL\t\t\t\t\t      "<<char(175)<<" " << reciclador[numero_recicladores].P.precio_total<< "\n\n" ; 
}

void ver_recicladores ( int numero_recicladores )
{
    if ( numero_recicladores > 0 )
    {
        for ( int i = 0 ; i < numero_recicladores; i = i + 1 )
        {
        cout <<"\n\n\t\t\t\t -| DATOS PERSONALES DEL RECICLADOR " << i+1 << " |- \n";
        cout <<"\n\t\t\t	    Nombres y apellidos : " <<reciclador[i].nombres<<" "<<reciclador[i].apellidos ;
        cout <<"\n\t\t\t	    N"<<char(167)<<" DNI              : " << reciclador[i].dni ;
		cout <<"\n\t\t\t	    Direcci\xA2n           : " << reciclador[i].direccion.calle<<" "<<reciclador[i].direccion.numero<<" "<<reciclador[i].direccion.urbanizacion ;
		ver_materiales ( i );            
        }
    }
}

void mayor_venta ( int numero_recicladores ) 
{
	float mayor=0;
	int   valor=0;
	mayor=reciclador[0].P.precio_total;
	
	for (int i=0; i<numero_recicladores; i=i+1)
    {
    cout <<"\n\t\t\t\t	| - DATOS PERSONALES DEL RECICLADOR " << i+1 << " - | \n";
    cout <<"\n\t\t\t\t	    Nombres y apellidos : " <<reciclador[i].nombres<<" "<<reciclador[i].apellidos ;
    cout <<"\n\t\t\t\t	    N"<<char(167)<<" DNI              : " << reciclador[i].dni ;
	cout <<"\n\t\t\t\t	    TOTAL DE VENTA      : " << reciclador[i].P.precio_total <<"\n\n" ;
    
	if (reciclador[i].P.precio_total>mayor)
		{
		mayor=reciclador[i].P.precio_total;
		valor=i;
		}
	}
	cout << "\n\n\t\t\t\t	| ~ MAYOR VENTA (S/.) ~ | \n ";
    cout << "\n\t\t\t\t	    Nombres y apellidos : " <<reciclador[valor].nombres<<" "<<reciclador[valor].apellidos ;
    cout << "\n\t\t\t\t	    N"<<char(167)<<" DNI              : " <<reciclador[valor].dni ;
    cout << "\n\n\t\t\t\t	    "<<char(175)<<char(175)<<" "<<char(175)<<char(175)<<" TOTAL DE VENTA: " << mayor ;
}

void contribucion ( )
{
	SOLO_TITULO();
	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS DOMICILIARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
	cout << "\t\t	      || CONTRIBUCI"<<char(224)<<"N AL MEDIO AMBIENTE DE UN RECICLADOR EN ESPEC"<<char(214)<<"FICO || \n\n\n";
	
	for ( int i=0; i < numero_recicladores ; i=i+1 )
    {
		if ( reciclador[i].dni == numero.dni )
        {
        cout <<"\n\t\t\t\t -| DATOS PERSONALES DEL RECICLADOR " << i+1 << " |- \n";
        cout <<"\n\t\t\t	    Nombres y apellidos : " <<reciclador[i].nombres<<" "<<reciclador[i].apellidos ;
        cout <<"\n\t\t\t	    N"<<char(167)<<" DNI              : " << reciclador[i].dni ;
		cout <<"\n\t\t\t	    Direcci\xA2n           : " << reciclador[i].direccion.calle<<" "<<reciclador[i].direccion.numero<<" "<<reciclador[i].direccion.urbanizacion ;
     
		cout << reciclador[i].D.desechos ;
		cout << "\n\t\t\t	    MATERIALES\t  CANTIDAD\t  PRECIO - VENTA\tSUBTOTAL\n " ;
    
    	for(int j=0; j<reciclador[i].P.cifra_materiales; j=j+1)
    	{
    	cout << "\n\t\t\t	    "<<reciclador[i].P.S[j].nombre_material <<"\t  " ;
    	cout << reciclador[i].P.S[j].cantidad		<<" \t\t  " ;
    	cout << reciclador[i].P.S[j].precio_venta	<<" \t\t\t" ;
    	cout << reciclador[i].P.S[j].sub_total ;
    	}
	
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t--------- " ;
		cout << "\n\t\t\t	    TOTAL\t\t\t\t\t      "<<char (175)<<" "<< reciclador[i].P.precio_total<< "\n\n" ;
		
		cout << "\n\t\t\t\t  | CONTRIBUCION AL MEDIO AMBIENTE DE "<<reciclador[i].nombres<<" "<<reciclador[i].apellidos<<" |"  ;
	
		if ( reciclador[i].P.precio_total > 0 )
		{ cout << "\n\n\t\t\t\t\t\t   Contribuci\xA2n POSITIVA" ;
		cout << "\n\n\t\t\t            Usted pertenece al 3% de los Peruanos que RECICLA." ; 
		cout << "\n\t\t\t Gracias por apoyar LA REDUCCI"<<char(224)<<"N DE LA CONTAMINACION del Pa"<<char(161)<<"s y del Planeta. " ;
		}
		}
	}
}

int dni_un_reciclador ( int numero_recicladores )
{
   	SOLO_TITULO();
	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS DOMICILIARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
	cout << "\t\t\t\t|| REGISTRO ESPEC"<<char(214)<<"FICO DE UN RECICLADOR Y SUS MATERIALES || \n\n\n" ;
	 
	for ( int i=0; i < numero_recicladores ; i=i+1 )
    {
		if ( reciclador[i].dni == numero.dni )
        {
        cout <<"\n\t\t\t\t -| DATOS PERSONALES DEL RECICLADOR " << i+1 << " |- \n";
        cout <<"\n\t\t\t	    Nombres y apellidos : " <<reciclador[i].nombres<<" "<<reciclador[i].apellidos ;
        cout <<"\n\t\t\t	    N"<<char(167)<<" DNI              : " << reciclador[i].dni ;
		cout <<"\n\t\t\t	    Direcci\xA2n           : " << reciclador[i].direccion.calle<<" "<<reciclador[i].direccion.numero<<" "<<reciclador[i].direccion.urbanizacion ;
     
		cout << reciclador[i].D.desechos ;
		cout << "\n\t\t\t	    MATERIALES\t  CANTIDAD\t  PRECIO - VENTA\tSUBTOTAL\n " ;
    
    	for(int j=0; j<reciclador[i].P.cifra_materiales; j=j+1)
    	{
    	cout << "\n\t\t\t	    "<<reciclador[i].P.S[j].nombre_material <<"\t  " ;
    	cout << reciclador[i].P.S[j].cantidad		<<" \t\t  " ;
    	cout << reciclador[i].P.S[j].precio_venta	<<" \t\t\t" ;
    	cout << reciclador[i].P.S[j].sub_total ;
    	}
	
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t--------- " ;
		cout << "\n\t\t\t	    TOTAL\t\t\t\t\t      "<<char (175)<< reciclador[i].P.precio_total<< "\n\n" ;
		}
	}
}
	
void menu_principal_domiciliarios ()
{
	do {
	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS DOMICILIARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
    cout << "\t\t\t\t 1. REGISTRAR DATOS PERSONALES Y MATERIALES DEL RECICLADOR			\n\n" ;
    cout << "\t\t\t\t 2. REGISTRO TOTAL DE LOS RECICLADORES Y MATERIALES 				\n\n" ;
    cout << "\t\t\t\t 3. REGISTRO ESPEC"<<char(214)<<"FICO DE UN RECICLADOR Y SUS MATERIALES 			\n\n" ;
    cout << "\t\t\t\t 4. RECICLADOR CON MAYOR VENTA										\n\n" ; 
	cout << "\t\t\t\t 5. CONTRIBUCI"<<char(224)<<"N AL MEDIO AMBIENTE DE UN RECICLADOR EN ESPEC"<<char(214)<<"FICO	\n\n" ;
	cout << "\t\t\t\t 6. ATR"<<char(181)<<"S                                    						\n\n" ;
    cout << "\t\t\t\t 7. SALIR                                    						\n\n\n" ;
    cout << "\n\t\t\t	 "<<char(175)<<char(175)<<" Digite una opci\xA2n : " ;
    cin  >> elegir ;														
	system ( "CLS" ) ;
   
	switch ( elegir )
    {
        case 1:
        	SOLO_TITULO();
            do { 
            titulo_a ();
			cout << "\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de recicladores que registrar\xA0: ";
			cin  >> numero_recicladores ;
			system ( "CLS" ) ;
			} while ( numero_recicladores <1);			
			regis_recicladores ( numero_recicladores ) ;
			SOLO_TITULO();
            titulo_a ();
			retorna_principal () ;
            break;
        case 2:
        	SOLO_TITULO();
            cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS DOMICILIARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t   || REGISTRO TOTAL DE LOS RECICLADORES Y MATERIALES || \n\n" ;
			ver_recicladores ( numero_recicladores ) ;
            retorna_principal () ;
			break;	      
        case 3:
        	SOLO_TITULO();
        	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS DOMICILIARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t|| REGISTRO ESPEC"<<char(214)<<"FICO DE UN RECICLADOR Y SUS MATERIALES || \n\n\n" ;
            cout << "\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de DNI de un reciclador: ";					fflush(stdin);
            cin  >> numero.dni ;									
			system ( "CLS" ) ;
            dni_un_reciclador ( numero_recicladores ) ;		          
			retorna_principal () ;
            break;
        case 4:
        	SOLO_TITULO();
        	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS DOMICILIARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t\t     || RECICLADOR CON MAYOR VENTA || \n\n\n" ;
			mayor_venta ( numero_recicladores ) ;
			retorna_principal () ;
			break;
        case 5:
        	SOLO_TITULO();
            cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS DOMICILIARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t	      || CONTRIBUCI"<<char(224)<<"N AL MEDIO AMBIENTE DE UN RECICLADOR EN ESPEC"<<char(214)<<"FICO || \n\n\n" ;
			cout << "\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de DNI de un reciclador: ";					fflush(stdin);
            cin  >> numero.dni;									
			system ( "CLS" ) ;
            contribucion ( );		          
			retorna_principal () ;
            break;
        case 6:
        	interfaz_secundaria ();
        	break;
    }
    } while ( (elegir <1) || (elegir > 7) );
}

void RES_DOMICILIOS ( )
{
	menu_principal_domiciliarios () ;
}


//MENÚ MUNICIPALES
    int 	elegir_m, regresar_m, establece_m = 0, establece_c_m = 0;
	void 	menu_principal_municipalidades () ;
	int 	opc_m, valor_m,  numero_municipalidades = 0;
	
struct info_datos_m {
	char 	distrito [30] ;
	char  	provincia [30];
	char 	departamento [30] ;	
} ;

struct solo_material_m {
	int 	codigo ;
	char 	nombre_material [30] ;
	int	 	cantidad ;
	float  	precio_venta ;
	float  	sub_total ;
} ;

struct varios_materiales_m {
	int	   	cifra_materiales ;
	struct 	solo_material_m S [30] ;
	float   precio_total ;
} ;

struct desechos_m {
	string	desechos ;
};
struct municipalidades{
    int   	codigo ;
	char   	denominacion [50] ;
	struct 	info_datos_m ubicacion ;
	struct 	varios_materiales_m P ; 
	struct  desechos_m D ;		
} municipalidad [30], numero_m, numero_m_1 ;	//struct recicladores numero;

string desechos_m [6] = { "EN GENERAL (GRIS)", "ORGANICOS (MORADO)",	"VIDRIOS (VERDE)", 
						"PLASTICOS Y ENVASES METALICOS (AMARILLO)",	"PAPEL (AZUL)", "PELIGROSOS (ROJO)"};

void titulo_a_m ()
{
	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS MUNICIPALES "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
	cout << "\t\t\t       || REGISTRAR DATOS Y MATERIALES DE LA MUNICIPALIDAD || \n\n" ;
}

void retorna_principal_m ()
{
    cout << "\n\n\n\n\n\t\t\t      Digite | 1 | para regresar al "<<char(174)<<"| MENé RESIDUOS MUNICIPALES |"<<char(175)<<" \n\n" ;
    cout << "\n\t\t\t\t\t        Digite | 0 | para "<<char(174)<<"| SALIR |"<<char(175)<<" \n\n\t\t\t\t\t\t\t "<<char(174)<<char(175)<<" " ;
    cin  >> regresar_m ; 	
			
	system ( "CLS" ) ;
	
	if ( regresar_m == 1 ) 
		{SOLO_TITULO();
		menu_principal_municipalidades () ;
		}
}

void registrar_materiales_m ( int p , int s, int d, int color ) //p = # recicladores , s = # materiales
{
	municipalidad[p].P.precio_total = 0;

	for ( int i = 0; i < s; i = i + 1 )
    {
    SOLO_TITULO();
    titulo_a_m ();
    cout << "\n\t\t\t\t| REGISTRO DE MATERIALES RECICLADOS DE LA "<<municipalidad[p].denominacion <<" | \n\n" ;
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), color);
	cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos_m [d] <<" "<<char(244)<<" \n\n " ;
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 7);
	cout << "\n\t\t\t\t\t\t   :: MATERIAL N"<<char(167)<<" " << i+1 <<" :: \n\n " ;
	cout << "\n\t\t\t\t  ~~ Digite el nombre del material reciclado: " ;				fflush(stdin);
	cin.getline(municipalidad[p].P.S[i].nombre_material, 30 , '\n' ) ; 			
	cout << "\t\t\t\t  ~~ Digite la cantidad (Kg)                : " ;				fflush(stdin);
	cin  >> municipalidad[p].P.S[i].cantidad ;						  				
	cout << "\t\t\t\t  ~~ Digite el precio - venta (S/.)         : " ;				fflush(stdin);
	cin  >> municipalidad[p].P.S[i].precio_venta ;	
					  				
	system ( "CLS" );	
	
	municipalidad[p].P.S[i].sub_total = municipalidad[p].P.S[i].cantidad * municipalidad[p].P.S[i].precio_venta ; 
	
	municipalidad[p].P.precio_total = municipalidad[p].P.precio_total + municipalidad[p].P.S[i].sub_total ;
	}
}

void regis_recicladores_m ( int n_c )
{
	for ( int i = 0; i < n_c; i = i + 1 ) // n_c=numero de recicladores
    {
    SOLO_TITULO();
	titulo_a_m ();
    cout << "\n\t\t\t\t\t      | REGISTRO DE MUNICIPALIDADES | \n" ;
	cout << "\n\t\t\t\t\t       ---  MUNICIPALIDAD N"<<char(167)<<" " << i+1 << "  --- \n\n" ; 	fflush(stdin);
	cout << "\n\t\t\t\t|- Datos Municipales -| \n\n" ; 
	cout << "\t\t\t\t~~ Digite el n\xA3mero del CODIGO de la Municipalidad: " ; 		fflush(stdin);
	cin  >> municipalidad[i].codigo; 						 
	cout << "\t\t\t\t~~ Digite la Denominaci\xA2n de la Municipalidad : " ;			fflush(stdin);
	cin.getline ( municipalidad[i].denominacion,50,'\n' ) ;		
	cout << "\n\n\t\t\t\t|- Ubicaci\xA2n de la Municipalidad -| \n\n" ; 											
	cout << "\t\t\t\t~~ Digite el distrito al que pertenece    : " ;			fflush(stdin);
	cin.getline ( municipalidad[i].ubicacion.distrito,30,'\n' ) ;   	
	cout << "\t\t\t\t~~ Digite la provincia al que pertenece   : " ;			fflush(stdin);
	cin.getline ( municipalidad[i].ubicacion.provincia,30,'\n' )  ; 				  		
	cout << "\t\t\t\t~~ Digite el departamento al que pertenece: " ; 		fflush(stdin);
	cin.getline ( municipalidad[i].ubicacion.departamento,30,'\n') ;
	
	system ("CLS");
	SOLO_TITULO();
	titulo_a_m ();
	cout << "\n\t\t\t\t| REGISTRO DE MATERIALES RECICLADOS DE LA "<<municipalidad[i].denominacion<<" | \n\n\n" ;
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
			SOLO_TITULO();
			titulo_a_m ();
			cout << "\n\t\t\t\t| REGISTRO DE MATERIALES RECICLADOS DE LA "<<municipalidad[i].denominacion<<" | \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 8);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos_m [0] <<" "<<char(244)<<" \n\n " ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 7);
			cout << "\n\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de materiales a registrar: " ;			fflush(stdin);
			cin  >> municipalidad[i].P.cifra_materiales ;
			municipalidad[i].D.desechos = "\n\n\t\t\t\t -| DESECHOS EN GENERAL (GRIS) |- \n";								
			system ( "CLS" ) ;
			registrar_materiales_m ( i , municipalidad[i].P.cifra_materiales, 0 , 8 ) ;
			break ;
		case 2:
			SOLO_TITULO();
			titulo_a_m ();
			cout << "\n\t\t\t\t| REGISTRO DE MATERIALES RECICLADOS DE LA "<<municipalidad[i].denominacion<<" | \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 5);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos_m [1] <<" "<<char(244)<<" \n\n " ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 7);
			cout << "\n\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de materiales a registrar: " ;			fflush(stdin);
			cin  >> municipalidad[i].P.cifra_materiales ;
			municipalidad[i].D.desechos = "\n\n\t\t\t\t -| DESECHOS ORGANICOS (MORADO) |- \n";									
			system ( "CLS" ) ;
			registrar_materiales_m ( i , municipalidad[i].P.cifra_materiales, 1 , 5 ) ;
			break ;
		case 3:
			SOLO_TITULO();
			titulo_a_m ();
			cout << "\n\t\t\t\t| REGISTRO DE MATERIALES RECICLADOS DE LA "<<municipalidad[i].denominacion<<" | \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 2);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos_m [2] <<" "<<char(244)<<" \n\n " ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 7);
			cout << "\n\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de materiales a registrar: " ;			fflush(stdin);
			cin  >> municipalidad[i].P.cifra_materiales ;
			municipalidad[i].D.desechos = "\n\n\t\t\t\t -| DESECHOS VIDRIOS (VERDE) |- \n";								
			system ( "CLS" ) ;
			registrar_materiales_m ( i , municipalidad[i].P.cifra_materiales, 2 , 2 ) ;
			break ;
		case 4:
			SOLO_TITULO();
			titulo_a_m ();
    		cout << "\n\t\t\t\t| REGISTRO DE MATERIALES RECICLADOS DE LA "<<municipalidad[i].denominacion<<" | \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 6);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos_m [3] <<" "<<char(244)<<" \n\n " ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 7);
			cout << "\n\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de materiales a registrar: " ;			fflush(stdin);
			cin  >> municipalidad[i].P.cifra_materiales ;
			municipalidad[i].D.desechos = "\n\n\t\t\t\t -| DESECHOS PLASTICOS Y ENVASES METALICOS (AMARILLO) |- \n";								
			system ( "CLS" ) ;
			registrar_materiales_m ( i , municipalidad[i].P.cifra_materiales, 3 , 6 ) ;
			break ;
		case 5:
			SOLO_TITULO();
			titulo_a_m ();
    		cout << "\n\t\t\t\t| REGISTRO DE MATERIALES RECICLADOS DE LA "<<municipalidad[i].denominacion<<" | \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 1);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos_m [4] <<" "<<char(244)<<" \n\n " ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			cout << "\n\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de materiales a registrar: " ;			fflush(stdin);
			cin  >> municipalidad[i].P.cifra_materiales ;
			municipalidad[i].D.desechos = "\n\n\t\t\t\t -| DESECHOS PAPEL (AZUL) |- \n";								
			system ( "CLS" ) ;
			registrar_materiales_m ( i , municipalidad[i].P.cifra_materiales, 4 , 1 ) ;
			break ;
		case 6:
			SOLO_TITULO();
			titulo_a_m ();
    		cout << "\n\t\t\t\t| REGISTRO DE MATERIALES RECICLADOS DE LA "<<municipalidad[i].denominacion<<" | \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 4);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos_m [5] <<" "<<char(244)<<" \n\n " ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			cout << "\n\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de materiales a registrar: " ;			fflush(stdin);
			cin  >> municipalidad[i].P.cifra_materiales ;
			municipalidad[i].D.desechos = "\n\n\t\t\t\t -| DESECHOS PELIGROSOS (ROJO) |- \n";								
			system ( "CLS" ) ;
			registrar_materiales_m ( i , municipalidad[i].P.cifra_materiales, 5 , 4 ) ;
			break ;
		}
	}
}

void ver_materiales_m (int numero_municipalidades)
{
	cout << municipalidad[numero_municipalidades].D.desechos ;
    
	cout << "\n\t\t\t	    MATERIALES\t  CANTIDAD\t  PRECIO - VENTA\tSUBTOTAL\n " ;
    
    for ( int i=0; i < municipalidad[numero_municipalidades].P.cifra_materiales ; i = i + 1 ) 
    {
    cout << "\n\t\t\t	    "<<municipalidad[numero_municipalidades].P.S[i].nombre_material <<"\t  " ;
    cout << municipalidad[numero_municipalidades].P.S[i].cantidad		<<" \t\t  " ;
    cout << municipalidad[numero_municipalidades].P.S[i].precio_venta	<<" \t\t\t" ;
    cout << municipalidad[numero_municipalidades].P.S[i].sub_total ;
    }
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t--------- " ;
    cout << "\n\t\t\t	    TOTAL\t\t\t\t\t      "<<char(175)<<" " << municipalidad[numero_municipalidades].P.precio_total<< "\n\n" ; 
}

void ver_recicladores_m ( int numero_municipalidades )
{
    if ( numero_municipalidades > 0 )
    {
        for ( int i = 0 ; i < numero_municipalidades; i = i + 1 )
        {
        cout <<"\n\n\t\t\t\t -| DATOS DE LA MUNICIPALIDAD " << i+1 << " |- \n";
        cout <<"\n\t\t\t	    Denominaci\xA2n: " <<municipalidad[i].denominacion ;
        cout <<"\n\t\t\t	    N"<<char(167)<<" CODIGO   : " << municipalidad[i].codigo ;
		cout <<"\n\t\t\t	    Ubicaci\xA2n   : " << municipalidad[i].ubicacion.distrito<<" - "<<municipalidad[i].ubicacion.provincia<<" - "<<municipalidad[i].ubicacion.departamento ;
		ver_materiales_m ( i );            
        }
    }
}

void mayor_venta_m ( int numero_municipalidades ) 
{
	float mayor_m =0;
	int   valor_m =0;
	mayor_m=municipalidad[0].P.precio_total;
	
	for (int i=0; i<numero_municipalidades; i=i+1)
    {
    cout <<"\n\t\t\t\t	| - DATOS MUNICIPALES " << i+1 << " - | \n";
    cout <<"\n\t\t\t\t	    Denominaci\xA2n  : " <<municipalidad[i].denominacion ;
    cout <<"\n\t\t\t\t	    N"<<char(167)<<" CODIGO     : " << municipalidad[i].codigo ;
	cout <<"\n\t\t\t\t	    TOTAL DE VENTA: " << municipalidad[i].P.precio_total <<"\n\n" ;
    
	if (municipalidad[i].P.precio_total>mayor_m)
		{
		mayor_m = municipalidad[i].P.precio_total;
		valor_m = i;
		}
	}
	cout << "\n\n\t\t\t\t	| ~ MAYOR VENTA (S/.) ~ | \n ";
    cout << "\n\t\t\t\t	    Denominaci\xA2n : " <<municipalidad[valor_m].denominacion ;
    cout << "\n\t\t\t\t	    N"<<char(167)<<" CODIGO    : " <<municipalidad[valor_m].codigo ;
    cout << "\n\t\t\t\t	    "<<char(175)<<char(175)<<" "<<char(175)<<char(175)<<" TOTAL DE VENTA: " << mayor_m ;
}

void contribucion_m ( int numero_municipalidades)
{
	SOLO_TITULO();
	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS MUNICIPALES "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
	cout << "\t\t	      || CONTRIBUCI"<<char(224)<<"N AL MEDIO AMBIENTE DE UNA MUNICIPALIDAD EN ESPEC"<<char(214)<<"FICO || \n\n\n";
	
	for ( int i=0; i < numero_municipalidades ; i=i+1 )
    {
		if ( municipalidad[i].codigo == numero_m.codigo )
        {
        cout <<"\n\t\t\t\t -| DATOS PERSONALES DEL RECICLADOR " << i+1 << " |- \n";
        cout <<"\n\t\t\t	    Denominaci\xA2n : " <<municipalidad[i].denominacion ;
        cout <<"\n\t\t\t	    N"<<char(167)<<" CODIGO    : " << municipalidad[i].codigo ;
		cout <<"\n\t\t\t	    Ubicaci\xA2n    : " << municipalidad[i].ubicacion.distrito<<" - "<<municipalidad[i].ubicacion.provincia<<" - "<<municipalidad[i].ubicacion.departamento ;
     
		cout << municipalidad[i].D.desechos ;
		cout << "\n\t\t\t	    MATERIALES\t  CANTIDAD\t  PRECIO - VENTA\tSUBTOTAL\n " ;
    
    	for(int j=0; j<municipalidad[i].P.cifra_materiales; j=j+1)
    	{
    	cout << "\n\t\t\t	    "<<municipalidad[i].P.S[j].nombre_material <<"\t  " ;
    	cout << municipalidad[i].P.S[j].cantidad		<<" \t\t  " ;
    	cout << municipalidad[i].P.S[j].precio_venta	<<" \t\t\t" ;
    	cout << municipalidad[i].P.S[j].sub_total ;
    	}
	
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t--------- " ;
		cout << "\n\t\t\t	    TOTAL\t\t\t\t\t      "<<char (175)<<" "<< municipalidad[i].P.precio_total<< "\n\n" ;
				
		cout << "\n\t\t\t\t  | CONTRIBUCION AL MEDIO AMBIENTE DE "<<municipalidad[i].denominacion<<" |"  ;
	
		if ( municipalidad[i].P.precio_total > 0 )
		{ cout << "\n\n\t\t\t\t\t\t   Contribuci\xA2n POSITIVA" ;
		cout << "\n\n\t\t\t           La Municipalidad pertenece al 3% de los Peruanos que RECICLA." ; 
		cout << "\n\t\t\t Gracias por apoyar LA REDUCCI"<<char(224)<<"N DE LA CONTAMINACION del Pa"<<char(161)<<"s y del Planeta. " ;
		}
		}
	}
}

int dni_un_reciclador_m ( int numero_municipales )
{
   	SOLO_TITULO();
	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS MUNICIPALES "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
	cout << "\t\t\t\t|| REGISTRO ESPEC"<<char(214)<<"FICO DE UNA MUNICIPALIDAD Y SUS MATERIALES || \n\n\n" ;
	 
	for ( int i=0; i < numero_municipalidades ; i=i+1 )
    {
		if ( municipalidad[i].codigo == numero_m_1.codigo )
        {
        cout <<"\n\t\t\t\t -| DATOS PERSONALES DEL RECICLADOR " << i+1 << " |- \n";
        cout <<"\n\t\t\t	    Denominaci\xA2n : " <<municipalidad[i].denominacion ;
        cout <<"\n\t\t\t	    N"<<char(167)<<" CODIGO    : " << municipalidad[i].codigo ;
		cout <<"\n\t\t\t	    Ubicaci\xA2n    : " << municipalidad[i].ubicacion.distrito<<" - "<<municipalidad[i].ubicacion.provincia<<" - "<<municipalidad[i].ubicacion.departamento ;
     
		cout << municipalidad[i].D.desechos ;
		cout << "\n\t\t\t	    MATERIALES\t  CANTIDAD\t  PRECIO - VENTA\tSUBTOTAL\n " ;
    
    	for(int j=0; j<municipalidad[i].P.cifra_materiales; j=j+1)
    	{
    	cout << "\n\t\t\t	    "<<municipalidad[i].P.S[j].nombre_material <<"\t  " ;
    	cout << municipalidad[i].P.S[j].cantidad		<<" \t\t  " ;
    	cout << municipalidad[i].P.S[j].precio_venta	<<" \t\t\t" ;
    	cout << municipalidad[i].P.S[j].sub_total ;
    	}
	
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t--------- " ;
		cout << "\n\t\t\t	    TOTAL\t\t\t\t\t      "<<char(175)<<" "<< municipalidad[i].P.precio_total<< "\n\n" ;
		}
	}
}
	
void menu_principal_municipalidades ()
{
	do {
	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS MUNICIPALES "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
    cout << "\t\t\t\t 1. REGISTRAR DATOS Y MATERIALES DE LA MUNICIPALIDAD				\n\n" ;
    cout << "\t\t\t\t 2. REGISTRO TOTAL DE LAS MUNICIPALIDADES Y SUS MATERIALES 					\n\n" ;
    cout << "\t\t\t\t 3. REGISTRO ESPEC"<<char(214)<<"FICO DE UNA MUNICIPALIDAD Y SUS MATERIALES \n\n" ;
    cout << "\t\t\t\t 4. MUNICIPALIDAD CON MAYOR VENTA											\n\n" ; 
	cout << "\t\t\t\t 5. CONTRIBUCI"<<char(224)<<"N AL MEDIO AMBIENTE DE UNA MUNICIPALIDAD EN ESPEC"<<char(214)<<"FICO\n\n" ;
	cout << "\t\t\t\t 6. ATR"<<char(181)<<"S                                    		\n\n" ;
    cout << "\t\t\t\t 7. SALIR                                    						\n\n\n" ;
    cout << "\n\t\t\t	 "<<char(175)<<char(175)<<" Digite una opci\xA2n : " ;
    cin  >> elegir_m ;														
	system ( "CLS" ) ;
   
	switch ( elegir_m )
    {
        case 1:
        	SOLO_TITULO();
            do { 
            titulo_a_m ();
			cout << "\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de municipalidades que registrar\xA0: ";
			cin  >> numero_municipalidades ;
			system ( "CLS" ) ;
			} while ( numero_municipalidades < 1 );			
			regis_recicladores_m ( numero_municipalidades ) ;
			SOLO_TITULO();
            titulo_a_m ();
			retorna_principal_m () ;
            break;
        case 2:
        	SOLO_TITULO();
            cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS MUNICIPALES "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t   || REGISTRO TOTAL DE LAS MUNICIPALIDADES Y SUS MATERIALES || \n\n" ;
			ver_recicladores_m ( numero_municipalidades ) ;
            retorna_principal_m () ;
			break;	      
        case 3:
        	SOLO_TITULO();
        	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS MUNICIPALES "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t|| REGISTRO ESPEC"<<char(214)<<"FICO DE UNA MUNICIPALIDAD Y SUS MATERIALES || \n\n\n" ;
            cout << "\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de CODIGO de una municipalidad: ";					fflush(stdin);
            cin  >> numero_m_1.codigo ;									
			system ( "CLS" ) ;
            dni_un_reciclador_m ( numero_municipalidades ) ;		          
			retorna_principal_m () ;
            break;
        case 4:
        	SOLO_TITULO();
        	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS MUNICIPALES "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t\t     || MUNICIPALIDAD CON MAYOR VENTA || \n\n\n" ;
			mayor_venta_m ( numero_municipalidades ) ;
			retorna_principal_m () ;
			break;
        case 5:
        	SOLO_TITULO();
            cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS MUNICIPALES "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t	      || CONTRIBUCI"<<char(224)<<"N AL MEDIO AMBIENTE DE UNA MUNICIPALIDAD EN ESPEC"<<char(214)<<"FICO || \n\n\n" ;
			cout << "\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de CODIGO de una municipalidad: ";					fflush(stdin);
            cin  >> numero_m.codigo;									
			system ( "CLS" ) ;
            contribucion_m ( numero_municipalidades );		          
			retorna_principal_m () ;
            break;
        case 6:
        	interfaz_secundaria ();
        	break;
    }
    } while ( (elegir_m <1) || (elegir_m > 7) );
}

void RES_MUNICIPALIDADES ( )
{
	menu_principal_municipalidades () ;
}

//MENÚ HOSPITALARIOS
    int 	elegir_h, regresar_h, establece_h = 0;  
	void 	menu_principal_hospitalarios () ;
	int 	opc_h,valor_h,  numero_hospitales = 0;
	
struct info_datos_h {
	char 	distrito_h [30] ;
	char 	provincia_h [30] ;
	char 	departamento_h [30] ;	
} ;

struct solo_material_h {
	int 	codigo_unico ;
	char 	nombre_material_h [30] ;
	int	 	cantidad_h ;
	float  	precio_venta_h ;
	float  	sub_total_h ;
} ;

struct varios_materiales_h {
	int	   	cifra_materiales_h ;
	struct 	solo_material_h S [30] ;
	float   precio_total_h ;
} ;

struct desechos_h {
	string	desechos_h ;
};
struct hospitales{
    int   	codigo_unico ;
	char   	nombres_h [50] ;
	char   	modelo_h [30] ;
	struct 	info_datos_h direccion ;
	struct 	varios_materiales_h P ; 
	struct  desechos_h D ;		
}hospital [30], numero_h ;	//struct recicladores numero;

string desechos_h [6] = { "EN GENERAL (GRIS)", "ORGANICOS (MORADO)",	"VIDRIOS (VERDE)", 
						"PLASTICOS Y ENVASES METALICOS (AMARILLO)",	"PAPEL (AZUL)", "PELIGROSOS (ROJO)"};

void titulo_a_h ()
{
	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS HOSPITALARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
	cout << "\t\t\t       || REGISTRAR DATOS PERSONALES Y MATERIALES DEL HOSPITAL || \n\n" ;
}

void retorna_principal_h ()
{
    cout << "\n\n\n\n\n\t\t\t      Digite | 1 | para regresar al "<<char(174)<<"| MENé RESIDUOS HOSPITALARIOS |"<<char(175)<<" \n\n" ;
    cout << "\n\t\t\t\t\t        Digite | 0 | para "<<char(174)<<"| SALIR |"<<char(175)<<" \n\n\t\t\t\t\t\t\t "<<char(174)<<char(175)<<" " ;
    cin  >> regresar_h ; 	
			
	system ( "CLS" ) ;
	
	if ( regresar_h == 1 ) 
		{SOLO_TITULO();
		menu_principal_hospitalarios () ;
		}
}

void registrar_materiales_h ( int p , int s, int d, int color ) //p = # hospitales , s = # materiales
{
	hospital[p].P.precio_total_h = 0;

	for ( int i = 0; i < s; i = i + 1 )
    {
    SOLO_TITULO();
    titulo_a_h ();
    cout << "\n\t\t\t\t| REGISTRO DE MATERIALES RECICLADOS DE "<<hospital[p].nombres_h<<" "<<hospital[p].modelo_h<<" | \n\n" ;
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), color);
	cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos_h [d] <<" "<<char(244)<<" \n\n " ;
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 7);
	cout << "\n\t\t\t\t\t\t   :: MATERIAL N"<<char(167)<<" " << i+1 <<" :: \n\n " ;
	cout << "\n\t\t\t\t  ~~ Digite el nombre del material reciclado: " ;				fflush(stdin);
	cin.getline(hospital[p].P.S[i].nombre_material_h, 30 , '\n' ) ; 			
	cout << "\t\t\t\t  ~~ Digite la cantidad (Kg)                : " ;				fflush(stdin);
	cin  >> hospital[p].P.S[i].cantidad_h ;						  				
	cout << "\t\t\t\t  ~~ Digite el precio - venta (S/.)         : " ;				fflush(stdin);
	cin  >> hospital[p].P.S[i].precio_venta_h ;	
					  				
	system ( "CLS" );	
	
	hospital[p].P.S[i].sub_total_h = hospital[p].P.S[i].cantidad_h * hospital[p].P.S[i].precio_venta_h ; 
	
	hospital[p].P.precio_total_h = hospital[p].P.precio_total_h + hospital[p].P.S[i].sub_total_h ;
	}
}

void regis_hospitales ( int n_c )
{
	for ( int i = 0; i < n_c; i = i + 1 ) // n_c=numero de recicladores
    {
    SOLO_TITULO();
	titulo_a_h ();
    cout << "\n\t\t\t\t\t      | REGISTRO DE HOSPITALES | \n" ;
	cout << "\n\t\t\t\t\t       ---  HOSPITAL N"<<char(167)<<" " << i+1 << "  --- \n\n" ; 	fflush(stdin);
	cout << "\n\t\t\t\t|- Datos Hospitalarios -| \n\n" ; 
	cout << "\t\t\t\t~~ Digite el n\xA3mero de CODIGO UNICO del hospital: " ; 				fflush(stdin);
	cin  >> hospital[i].codigo_unico; 						 
	cout << "\t\t\t\t~~ Digite el nombre del hospital                : " ;								fflush(stdin);
	cin.getline ( hospital[i].nombres_h,30,'\n' ) ;		
	cout << "\t\t\t\t~~ Digite el modelo al que pertenece el hospital: " ;				fflush(stdin);
	cin.getline ( hospital[i].modelo_h,30,'\n' ) ; 			
	cout << "\n\n\t\t\t\t|- Ubicaci\xA2n del Hospital -| \n\n" ; 											
	cout << "\t\t\t\t~~ Digite el nombre del distrito    : " ;						fflush(stdin);
	cin.getline ( hospital[i].direccion.distrito_h,30,'\n' ) ;   	
	cout << "\t\t\t\t~~ Digite el nombre de la provincia : " ;						fflush(stdin);
	cin.getline ( hospital[i].direccion.provincia_h,30,'\n' );			  		
	cout << "\t\t\t\t~~ Digite el nombre del departamento: " ; 							fflush(stdin);
	cin.getline ( hospital[i].direccion.departamento_h,30,'\n') ;
	
	system ("CLS");
	SOLO_TITULO();
	titulo_a_h ();
	cout << "\n\t\t\t\t| REGISTRO DE MATERIALES RECICLADOS DE "<<hospital[i].nombres_h<<" "<<hospital[i].modelo_h<<" | \n\n\n" ;
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
			SOLO_TITULO();
			titulo_a_h ();
			cout << "\n\t\t\t\t| REGISTRO DE MATERIALES RECICLADOS DE "<<hospital[i].nombres_h<<" "<<hospital[i].modelo_h<<" | \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 8);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos_h [0] <<" "<<char(244)<<" \n\n " ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			cout << "\n\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de materiales a registrar: " ;			fflush(stdin);
			cin  >> hospital[i].P.cifra_materiales_h ;
			hospital[i].D.desechos_h = "\n\n\t\t\t\t -| DESECHOS EN GENERAL (GRIS) |- \n";								
			system ( "CLS" ) ;
			registrar_materiales_h ( i , hospital[i].P.cifra_materiales_h, 0 , 8 ) ;
			break ;
		case 2:
			SOLO_TITULO();
			titulo_a_h ();
			cout << "\n\t\t\t\t| REGISTRO DE MATERIALES RECICLADOS DE "<<hospital[i].nombres_h<<" "<<hospital[i].modelo_h<<" | \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 5);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos_h [1] <<" "<<char(244)<<" \n\n " ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			cout << "\n\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de materiales a registrar: " ;			fflush(stdin);
			cin  >> hospital[i].P.cifra_materiales_h ;
			hospital[i].D.desechos_h = "\n\n\t\t\t\t -| DESECHOS ORGANICOS (MORADO) |- \n";									
			system ( "CLS" ) ;
			registrar_materiales_h ( i , hospital[i].P.cifra_materiales_h, 1 , 5 ) ;
			break ;
		case 3:
			SOLO_TITULO();
			titulo_a_h ();
			cout << "\n\t\t\t\t| REGISTRO DE MATERIALES RECICLADOS DE "<<hospital[i].nombres_h<<" "<<hospital[i].modelo_h<<" | \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 2);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos_h [2] <<" "<<char(244)<<" \n\n " ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			cout << "\n\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de materiales a registrar: " ;			fflush(stdin);
			cin  >> hospital[i].P.cifra_materiales_h ;
			hospital[i].D.desechos_h = "\n\n\t\t\t\t -| DESECHOS VIDRIOS (VERDE) |- \n";								
			system ( "CLS" ) ;
			registrar_materiales_h( i , hospital[i].P.cifra_materiales_h, 2 , 2 ) ;
			break ;
		case 4:
			SOLO_TITULO();
			titulo_a_h ();
    		cout << "\n\t\t\t\t| REGISTRO DE MATERIALES RECICLADOS DE "<<hospital[i].nombres_h<<" "<<hospital[i].modelo_h<<" | \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 6);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos_h [3] <<" "<<char(244)<<" \n\n " ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			cout << "\n\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de materiales a registrar: " ;			fflush(stdin);
			cin  >> hospital[i].P.cifra_materiales_h ;
			hospital[i].D.desechos_h = "\n\n\t\t\t\t -| DESECHOS PLASTICOS Y ENVASES METALICOS (AMARILLO) |- \n";								
			system ( "CLS" ) ;
			registrar_materiales_h( i , hospital[i].P.cifra_materiales_h, 3 , 6 ) ;
			break ;
		case 5:
			SOLO_TITULO();
			titulo_a_h ();
    		cout << "\n\t\t\t\t| REGISTRO DE MATERIALES RECICLADOS DE "<<hospital[i].nombres_h<<" "<<hospital[i].modelo_h<<" | \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 1);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos_h [4] <<" "<<char(244)<<" \n\n " ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			cout << "\n\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de materiales a registrar: " ;			fflush(stdin);
			cin  >> hospital[i].P.cifra_materiales_h ;
			hospital[i].D.desechos_h = "\n\n\t\t\t\t -| DESECHOS PAPEL (AZUL) |- \n";								
			system ( "CLS" ) ;
			registrar_materiales_h( i , hospital[i].P.cifra_materiales_h, 4 , 1 ) ;
			break ;
		case 6:
			SOLO_TITULO();
			titulo_a_h ();
    		cout << "\n\t\t\t\t| REGISTRO DE MATERIALES RECICLADOS DE "<<hospital[i].nombres_h<<" "<<hospital[i].modelo_h<<" | \n\n" ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 4);
			cout << "\n\t\t\t\t"<<char(244)<<" REGISTRO DE DESECHOS "<< desechos_h [5] <<" "<<char(244)<<" \n\n " ;
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
			cout << "\n\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de materiales a registrar: " ;			fflush(stdin);
			cin  >> hospital[i].P.cifra_materiales_h ;
			hospital[i].D.desechos_h = "\n\n\t\t\t\t -| DESECHOS PELIGROSOS (ROJO) |- \n";								
			system ( "CLS" ) ;
			registrar_materiales_h( i , hospital[i].P.cifra_materiales_h, 5 , 4 ) ;
			break ;
		}
	}
}

void ver_materiales_h (int numero_hospitales)
{
	cout << hospital[numero_hospitales].D.desechos_h ;
    
	cout << "\n\t\t\t	    MATERIALES\t  CANTIDAD\t  PRECIO - VENTA\tSUBTOTAL\n " ;
    
    for ( int i=0; i < hospital[numero_hospitales].P.cifra_materiales_h ; i = i + 1 ) 
    {
    cout << "\n\t\t\t	    "<<hospital[numero_hospitales].P.S[i].nombre_material_h <<"\t  " ;
    cout << hospital[numero_hospitales].P.S[i].cantidad_h		<<" \t\t  " ;
    cout << hospital[numero_hospitales].P.S[i].precio_venta_h	<<" \t\t\t" ;
    cout << hospital[numero_hospitales].P.S[i].sub_total_h ;
    }
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t--------- " ;
    cout << "\n\t\t\t	    TOTAL\t\t\t\t\t      "<<char(175)<<" " << hospital[numero_hospitales].P.precio_total_h<< "\n\n" ; 
}

void ver_hospitales ( int numero_hospitales )
{
    if ( numero_hospitales > 0 )
    {
        for ( int i = 0 ; i < numero_hospitales; i = i + 1 )
        {
        cout <<"\n\n\t\t\t\t -| DATOS HOSPITALARIOS " << i+1 << " |- \n";
        cout <<"\n\t\t\t	    Nombre y modelo : " <<hospital[i].nombres_h<<" "<<hospital[i].modelo_h;
        cout <<"\n\t\t\t	    N"<<char(167)<<" CODIGO UNICO : " << hospital[i].codigo_unico ;
		cout <<"\n\t\t\t	    Ubicaci\xA2n       : " << hospital[i].direccion.distrito_h<<" "<<hospital[i].direccion.provincia_h<<" "<<hospital[i].direccion.departamento_h ;
		ver_materiales_h ( i );            
        }
    }
}

void mayor_venta_h ( int numero_hospitales ) 
{
	float mayor_h=0;
	int   valor_h=0;
	mayor_h=hospital[0].P.precio_total_h;
	
	for ( i=0; i<numero_hospitales; i=i+1)
    {
    cout <<"\n\t\t\t\t	| - DATOS HOSPITALARIOS " << i+1 << " - | \n";
    cout <<"\n\t\t\t\t	    Nombre y modelo : " <<hospital[i].nombres_h<<" "<<hospital[i].modelo_h;
    cout <<"\n\t\t\t\t	    N"<<char(167)<<" CODIGO UNICO : " << hospital[i].codigo_unico ;
	cout <<"\n\t\t\t\t	    TOTAL DE VENTA  : " << hospital[i].P.precio_total_h <<"\n\n" ;
    
	if (hospital[i].P.precio_total_h > mayor_h)
		{
		mayor_h=hospital[i].P.precio_total_h;
		valor_h=i;
		}
	}
	cout << "\n\n\t\t\t\t	| ~ MAYOR VENTA (S/.) ~ | \n ";
    cout << "\n\t\t\t\t	    Nombre y modelo : " <<hospital[valor_h].nombres_h<<" "<<hospital[valor_h].modelo_h;
    cout << "\n\t\t\t\t	    N"<<char(167)<<" CODIGO UNICO : " <<hospital[valor_h].codigo_unico ;
    cout << "\n\n\t\t\t\t	    "<<char(175)<<char(175)<<" "<<char(175)<<char(175)<<" TOTAL DE VENTA: " << mayor_h ;
}

void contribucion_h ( int numero_hospitales )
{
	SOLO_TITULO();
	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS HOSPITALARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
	cout << "\t\t	      || CONTRIBUCI"<<char(224)<<"N AL MEDIO AMBIENTE DE UN HOSPITAL EN ESPEC"<<char(214)<<"FICO || \n\n\n";
	
	for ( int i=0; i < numero_hospitales ; i=i+1 )
    {
		if ( hospital[i].codigo_unico == numero_h.codigo_unico )
        {
        cout <<"\n\t\t\t\t -| DATOS HOSPITALARIOS " << i+1 << " |- \n";
        cout <<"\n\t\t\t	    Nombres y modelo : " <<hospital[i].nombres_h<<" "<<hospital[i].modelo_h ;
        cout <<"\n\t\t\t	    N"<<char(167)<<" CODIGO UNICO  : " << hospital[i].codigo_unico ;
		cout <<"\n\t\t\t	    Ubicaci\xA2n        : " << hospital[i].direccion.distrito_h<<" "<<hospital[i].direccion.provincia_h<<" "<<hospital[i].direccion.departamento_h ;
     
		cout << hospital[i].D.desechos_h ;
		cout << "\n\t\t\t	    MATERIALES\t  CANTIDAD\t  PRECIO - VENTA\tSUBTOTAL\n " ;
    
    	for(int j=0; j<hospital[i].P.cifra_materiales_h; j=j+1)
    	{
    	cout << "\n\t\t\t	    "<<hospital[i].P.S[j].nombre_material_h <<"\t  " ;
    	cout << hospital[i].P.S[j].cantidad_h		<<" \t\t  " ;
    	cout << hospital[i].P.S[j].precio_venta_h	<<" \t\t\t" ;
    	cout << hospital[i].P.S[j].sub_total_h ;
    	}
	
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t--------- " ;
		cout << "\n\t\t\t	    TOTAL\t\t\t\t\t      "<<char (175)<<" "<< hospital[i].P.precio_total_h<< "\n\n" ;
		
		cout << "\n\t\t\t\t  | CONTRIBUCION AL MEDIO AMBIENTE DE "<<hospital[i].nombres_h<<" "<<hospital[i].modelo_h<<" |"  ;
	
		if ( hospital[i].P.precio_total_h > 0 )
			{ cout << "\n\n\t\t\t\t\t\t   Contribuci\xA2n POSITIVA" ;
			cout << "\n\n\t\t\t           El Hospital pertenece al 3% de los Peruanos que RECICLA." ; 
			cout << "\n\t\t\t Gracias por apoyar LA REDUCCI"<<char(224)<<"N DE LA CONTAMINACION del Pa"<<char(161)<<"s y del Planeta. " ;
			}
		}
	}
}

int codigo_un_hospital ( int numero_hospitales )
{
   	SOLO_TITULO();
	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS HOSPITALARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
	cout << "\t\t\t\t|| REGISTRO ESPEC"<<char(214)<<"FICO DE UN HOSPITAL Y SUS MATERIALES || \n\n\n" ;
	 
	for ( int i=0; i < numero_hospitales ; i=i+1 )
    {
		if ( hospital[i].codigo_unico == numero_h.codigo_unico )
        {
        cout <<"\n\t\t\t\t -| DATOS HOSPITALARIOS " << i+1 << " |- \n";
        cout <<"\n\t\t\t	    Nombres y apellidos : " <<hospital[i].nombres_h<<" "<<hospital[i].modelo_h ;
        cout <<"\n\t\t\t	    N"<<char(167)<<" CODIGO UNICO    : " << hospital[i].codigo_unico  ;
		cout <<"\n\t\t\t	    Ubicaci\xA2n           : " << hospital[i].direccion.distrito_h<<" "<<hospital[i].direccion.provincia_h<<" "<<hospital[i].direccion.departamento_h ;
     
		cout << hospital[i].D.desechos_h ;
		cout << "\n\t\t\t	    MATERIALES\t  CANTIDAD\t  PRECIO - VENTA\tSUBTOTAL\n " ;
    
    	for(int j=0; j<hospital[i].P.cifra_materiales_h; j=j+1)
    	{
    	cout << "\n\t\t\t	    "<<hospital[i].P.S[j].nombre_material_h <<"\t  " ;
    	cout << hospital[i].P.S[j].cantidad_h		<<" \t\t  " ;
    	cout << hospital[i].P.S[j].precio_venta_h	<<" \t\t\t" ;
    	cout << hospital[i].P.S[j].sub_total_h ;
    	}
	
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t--------- " ;
		cout << "\n\t\t\t	    TOTAL\t\t\t\t\t      "<<char (175)<< hospital[i].P.precio_total_h<< "\n\n" ;
		}
	}
}
	
void menu_principal_hospitalarios ()
{
	do {
	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS HOSPITALARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
    cout << "\t\t\t\t 1. REGISTRAR DATOS PERSONALES Y MATERIALES DEL HOSPITAL			\n\n" ;
    cout << "\t\t\t\t 2. REGISTRO TOTAL DE LOS HOSPITALES Y MATERIALES 				\n\n" ;
    cout << "\t\t\t\t 3. REGISTRO ESPEC"<<char(214)<<"FICO DE UN HOSPITAL Y SUS MATERIALES 			\n\n" ;
    cout << "\t\t\t\t 4. HOSPITAL CON MAYOR VENTA										\n\n" ; 
	cout << "\t\t\t\t 5. CONTRIBUCI"<<char(224)<<"N AL MEDIO AMBIENTE DE UN HOSPITAL EN ESPEC"<<char(214)<<"FICO	\n\n" ;
	cout << "\t\t\t\t 6. ATR"<<char(181)<<"S                                    						\n\n" ;
    cout << "\t\t\t\t 7. SALIR                                    						\n\n\n" ;
    cout << "\n\t\t\t	 "<<char(175)<<char(175)<<" Digite una opci\xA2n : " ;
    cin  >> elegir_h ;														
	system ( "CLS" ) ;
   
	switch ( elegir_h )
    {
        case 1:
        	SOLO_TITULO();
            do { 
            titulo_a_h ();
			cout << "\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de hospitales que registrar\xA0: ";
			cin  >> numero_hospitales ;
			system ( "CLS" ) ;
			} while ( numero_hospitales <1);			
			regis_hospitales ( numero_hospitales ) ;
			SOLO_TITULO();
            titulo_a_h ();
			retorna_principal_h () ;
            break;
        case 2:
        	SOLO_TITULO();
            cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS HOSPITALARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t   || REGISTRO TOTAL DE LOS HOSPITALES Y MATERIALES || \n\n" ;
			ver_hospitales ( numero_hospitales ) ;
            retorna_principal_h () ;
			break;	      
        case 3:
        	SOLO_TITULO();
        	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS HOSPITALARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t|| REGISTRO ESPEC"<<char(214)<<"FICO DE UN HOSPITAL Y SUS MATERIALES || \n\n\n" ;
            cout << "\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de CODIGO UNICO de un hospital: ";					fflush(stdin);
            cin  >> numero_h.codigo_unico ;									
			system ( "CLS" ) ;
            codigo_un_hospital ( numero_hospitales ) ;		          
			retorna_principal_h () ;
            break;
        case 4:
        	SOLO_TITULO();
        	cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS HOSPITALARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t\t\t\t     || HOSPITAL CON MAYOR VENTA || \n\n\n" ;
			mayor_venta_h ( numero_hospitales ) ;
			retorna_principal_h () ;
			break;
        case 5:
        	SOLO_TITULO();
            cout << "\n\n\t\t\t\t\t      "<<char(179)<<char(179)<<char(179)<<" RESIDUOS HOSPITALARIOS "<<char(179)<<char(179)<<char(179)<<" \n\n\n" ;
			cout << "\t\t	      || CONTRIBUCI"<<char(224)<<"N AL MEDIO AMBIENTE DE UN HOSPITAL EN ESPEC"<<char(214)<<"FICO || \n\n\n" ;
			cout << "\t\t\t\t  "<<char(175)<<char(175)<<" Digite el n\xA3mero de CODIGO UNICO de un hospital: ";					fflush(stdin);
            cin  >> numero_h.codigo_unico;									
			system ( "CLS" ) ;
            contribucion_h ( numero_hospitales );		          
			retorna_principal_h () ;
            break;
        case 6:
        	interfaz_secundaria ();
        	break;
    }
    } while ( (elegir_h <1) || (elegir_h > 7) );
}

void RES_HOSPITALARIOS ( )
{
	menu_principal_hospitalarios () ;
}


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

void interfaz_secundaria ()
{	
	SOLO_TITULO();
    I_SECUNDARIA();
    cout << "\n\n\t\t\t\t\t\t\t ~ 4 ~ \n\t\t\t\t\t\t\t ATR"<<char(181)<<"S \n\n" ;
    
	do
	{
		cout << "\n\t\t\t\t\t	 "<<char(175)<<char(175)<<" Digite una opci\xA2n: " ;
    	cin  >> opcion_menu ;
	}										
	while ( (opcion_menu <1) || (opcion_menu > 4) );
			
	system("CLS");
			
	switch (opcion_menu)
	{
		case 1://domiciliarios
				SOLO_TITULO();
				RES_DOMICILIOS();
				break;
		case 2://municipales
				SOLO_TITULO();
				RES_MUNICIPALIDADES ();
				break;
		case 3://hospitalarios
				SOLO_TITULO();
				RES_HOSPITALARIOS ();
				break;
		case 4:		
				menu_principal();
				break;
	}
}

void menu_principal ()
{
	//Interfaz principal
	SOLO_TITULO () ;
	I_PRINCIPAL () ;
	
	do{
		cout << "\n\n\t\t\t\t\t	 "<<char (175)<<char (175)<< " Digite una opci\xA2n: " ;
    	cin  >> opcion ;
	}														
	while ( ( opcion < 1 ) || ( opcion > 3 ) );
	
	system("CLS");
	
	switch ( opcion )
    {
        case 1: //menu
        	//Interfaz secundaria
        	interfaz_secundaria () ;			
			break;
    	case 2: //quienes somos
    		SOLO_TITULO() ;
    		descripcion_somos () ;
			cout << "\n\n\n\n\n\t\t\t      Digite | 1 | para regresar al "<<char (174)<< "| MENé PRINCIPAL |"<<char (175)<< "\n\n" ;
    		cout << "\n\t\t\t\t\t    Digite | 0 | para "<<char (174)<<"| SALIR |"<<char (175)<< " \n\n\t\t\t\t\t\t "<<char (175)<<char (175);
    		cin  >> regresar ;
			 	
			system ( "CLS" ) ;
	
			if ( regresar == 1 )
			{
				SOLO_TITULO () ;
				menu_principal() ;
			} 
        	break;

    }    	
}

int main ()
{
	system ("mode con: cols=160 lines=65") ;
	
	//interfaz inicio
		I_TITULO();
		
		cout << "C A R G A N D O ..." ;
			Sleep ( 4000 ) ;
			
		system ( "CLS" ) ;
			
		menu_principal () ;
		
	getch();
}
