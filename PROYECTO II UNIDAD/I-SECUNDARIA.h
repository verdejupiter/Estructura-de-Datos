#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

void dibujo_resi_domiciliarios()
{
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 6); 
	gotoxy(10,7);cout<<"  "<<""<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<endl;
	gotoxy(10,8);cout<<"  "<<char(186)<<"   _______________   "<<char(186)<<endl;
	gotoxy(10,9);cout<<"  "<<char(186)<<"  / / / / / / / / "<<char(92)<<"  "<<char(186)<<endl;
	gotoxy(10,10);cout<<"  "<<char(186)<<" /_/_/_/_/_/_/_/_/_"<<char(92)<<" "<<char(186)<<endl;	
	gotoxy(10,11);cout<<"  "<<char(186)<<"   |              |"<<"  "<<char(186)<<endl;
	gotoxy(10,12);cout<<"  "<<char(186)<<"   |  "<<char(254)<<char(254)<<" "<<char(254)<<char(254)<<" "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<" |  "<<char(186)<<endl;
	gotoxy(10,13);cout<<"  "<<char(186)<<"   |  "<<char(219)<<char(219)<<" "<<char(219)<<char(219)<<" "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<" |  "<<char(186)<<endl;
	gotoxy(10,14);cout<<"  "<<char(186)<<"   |        "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<" |  "<<char(186)<<endl;
	gotoxy(10,15);cout<<"  "<<char(186)<<"   |        "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<" |  "<<char(186)<<endl;
	gotoxy(10,16);cout<<"  "<<char(186)<<"   |        "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<" |  "<<char(186)<<endl;	
	gotoxy(10,17);cout<<"  "<<char(186)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(186)<<endl;	
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
	gotoxy(20,18);cout<<" ~ 1 ~ "<<endl;
	gotoxy(12,19);cout<<" RESIDUOS DOMICILIARIOS  "<<endl;
}
void dibujo_resi_municipales()
{
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 2); 
	gotoxy(45,7);cout<<"  "<<""<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<endl;
	gotoxy(45,8);cout<<"  "<<char(186)<<"            _____"<<"    "<<char(186)<<endl;
	gotoxy(45,9);cout<<"  "<<char(186)<<"           |"<<char(219)<<char(219)<<" "<<char(219)<<char(219)<<"    "<<char(186)<<endl;
	gotoxy(45,10);cout<<"  "<<char(186)<<"   ________|_____    "<<char(186)<<endl;
	gotoxy(45,11);cout<<"  "<<char(186)<<"  / / / / / / / / "<<char(92)<<"  "<<char(186)<<endl;
	gotoxy(45,12);cout<<"  "<<char(186)<<" /_/_/_/_/_/_/_/_/_"<<char(92)<<" "<<char(186)<<endl;	
	gotoxy(45,13);cout<<"  "<<char(186)<<"   |             |"<<"   "<<char(186)<<endl;
	gotoxy(45,14);cout<<"  "<<char(186)<<"   |	  "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<"  |   "<<char(186)<<endl;
	gotoxy(45,15);cout<<"  "<<char(186)<<"   |      "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<"  |   "<<char(186)<<endl;
	gotoxy(45,16);cout<<"  "<<char(186)<<"   |	  "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<"  |   "<<char(186)<<endl;
	gotoxy(45,17);cout<<"  "<<char(186)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(186)<<endl;	
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
	gotoxy(55,18);cout<<" ~ 2 ~ "<<endl;
	gotoxy(48,19);cout<<" RESIDUOS MUNICIPALES "<<endl;
}

void dibujo_resi_hospitales()
{
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 4); 
	gotoxy(82,7);cout<<"  "<<""<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<endl;
	gotoxy(82,8);cout<<"  "<<char(186)<<"          "<<char(220)<<char(220)<<"         "<<char(186)<<endl;
	gotoxy(82,9);cout<<"  "<<char(186)<<"        "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<"       "<<char(186)<<endl;
	gotoxy(82,10);cout<<"  "<<char(186)<<"   _______"<<char(223)<<char(223)<<"______   "<<char(186)<<endl;
	gotoxy(82,11);cout<<"  "<<char(186)<<"  / / / / / / / / "<<char(92)<<"  "<<char(186)<<endl;
	gotoxy(82,12);cout<<"  "<<char(186)<<" /_/_/_/_/_/_/_/_/_"<<char(92)<<" "<<char(186)<<endl;	
	gotoxy(82,13);cout<<"  "<<char(186)<<"   | "<<char(254)<<char(254)<<"   "<<char(254)<<char(254)<<"   "<<char(254)<<char(254)<<"|   "<<char(186)<<endl;
	gotoxy(82,14);cout<<"  "<<char(186)<<"   | "<<char(254)<<char(254)<<"   "<<char(254)<<char(254)<<"   "<<char(254)<<char(254)<<"|   "<<char(186)<<endl;
	gotoxy(82,15);cout<<"  "<<char(186)<<"   |   "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<"  |   "<<char(186)<<endl;
	gotoxy(82,16);cout<<"  "<<char(186)<<"   |   "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<"  |   "<<char(186)<<endl;
	gotoxy(82,17);cout<<"  "<<char(186)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(186)<<endl;	
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
	gotoxy(92,18);cout<<" ~ 3 ~ "<<endl;
	gotoxy(84,19);cout<<" RESIDUOS HOSPITALARIOS "<<endl;
}
int I_SECUNDARIA()
	{
	system ("color 0F");
	dibujo_resi_domiciliarios();
	dibujo_resi_municipales();
	dibujo_resi_hospitales();	
	
	}
