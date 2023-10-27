#include <iostream>
#include <conio.h>
#include <windows.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

void dibujo_menu()
{
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 9); 
	gotoxy(10,7);cout<<"  "<<""<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<endl;
	gotoxy(10,8);cout<<"  "<<char(186)<<"		      "<<char(186)<<endl;	
	gotoxy(10,9);cout<<"  "<<char(186)<<"  "<<char(220)<<char(220)<<" "<<char(95)<<char(95)<<char(95)<<char(95)<<char(95)<<char(95)<<char(95)<<char(95)<<char(95)<<char(95)<<"  "<<char(186)<<endl;
	gotoxy(10,10);cout<<"  "<<char(186)<<"  "<<char(220)<<char(220)<<" "<<char(95)<<char(95)<<char(95)<<char(95)<<char(95)<<char(95)<<char(95)<<char(95)<<char(95)<<char(95)<<"  "<<char(186)<<endl;
	gotoxy(10,11);cout<<"  "<<char(186)<<"  "<<char(220)<<char(220)<<" "<<char(95)<<char(95)<<char(95)<<char(95)<<char(95)<<char(95)<<char(95)<<char(95)<<char(95)<<char(95)<<"  "<<char(186)<<endl;
	gotoxy(10,12);cout<<"  "<<char(186)<<"  "<<char(220)<<char(220)<<" "<<char(95)<<char(95)<<char(95)<<char(95)<<char(95)<<char(95)<<char(95)<<char(95)<<char(95)<<char(95)<<"  "<<char(186)<<endl;
	gotoxy(10,13);cout<<"  "<<char(186)<<"  "<<char(220)<<char(220)<<" "<<char(95)<<char(95)<<char(95)<<char(95)<<char(95)<<char(95)<<char(95)<<char(95)<<char(95)<<char(95)<<"  "<<char(186)<<endl;
	gotoxy(10,14);cout<<"  "<<char(186)<<"		      "<<char(186)<<endl;	
	gotoxy(10,15);cout<<"  "<<char(186)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(186)<<endl;	
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15); 
	gotoxy(19,16);cout<<" ~ 1 ~ "<<endl;
	gotoxy(19,17);cout<<" MEN"<<char(233)<<endl;
	
}

void dibujo_quienes_somos()
{
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 6); 
	gotoxy(45,7);cout<<"  "<<""<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<endl;
	gotoxy(45,8);cout<<"  "<<char(186)<<"	 -----        "<<char(186)<<endl;		 
	gotoxy(45,9);cout<<"  "<<char(186)<<"	/     "<<char(92)<<"       "<<char(186)<<endl;
	gotoxy(45,10);cout<<"  "<<char(186)<<"       (  O O  )      "<<char(186)<<endl;
	gotoxy(45,11);cout<<"  "<<char(186)<<"     ___"<<char(92)<<"  =  /___    "<<char(186)<<endl;
	gotoxy(45,12);cout<<"  "<<char(186)<<"#  /               "<<char(92)<<"  "<<char(186)<<endl;
	gotoxy(45,13);cout<<"  "<<char(186)<<""<<char(92)<<"\\//|   "<<"  "<<char(254)<<char(254)<<"      |"<<char(92)<<char(92)<<" "<<char(186)<<endl;
	gotoxy(45,14);cout<<"  "<<char(186)<<" "<<char(92)<<"/ |     "<<char(254)<<char(254)<<"      |"<<" "<<char(92)<<char(92)<<char(186)<<endl;
	gotoxy(45,15);cout<<"  "<<char(186)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(186)<<endl;	
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15); 
	gotoxy(55,16);cout<<" ~ 2 ~ "<<endl;
	gotoxy(51,17);cout<<" QUI"<<char(144)<<"NES SOMOS "<<endl;
	
}

void dibujo_salida()
{
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 2); 
	gotoxy(85,7);cout<<"  "<<""<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<endl;
	gotoxy(85,8);cout<<"  "<<char(186)<<"		  "<<char(186)<<endl;	
	gotoxy(85,9);cout<<"  "<<char(186)<<"    		  "<<char(186)<<endl;
	gotoxy(85,10);cout<<"  "<<char(186)<<"  "<<char(95)<<char(95)<<char(95)<<char(95)<<char(95)<<char(95)<<char(95)<<char(95)<<char(95)<<char(95)<<"|"<<char(92)<<"    "<<char(186)<<endl;
	gotoxy(85,11);cout<<"  "<<char(186)<<"   E X I T    "<<char (92)<<"   "<<char(186)<<endl;
	gotoxy(85,12);cout<<"  "<<char(186)<<"  "<<char(95)<<char(95)<<char(95)<<char(95)<<char(95)<<char(95)<<char(95)<<char(95)<<char(95)<<char(95)<<"  /   "<<char(186)<<endl;
	gotoxy(85,13);cout<<"  "<<char(186)<<"            |/    "<<char(186)<<endl;
	gotoxy(85,14);cout<<"  "<<char(186)<<"		  "<<char(186)<<endl;	
	gotoxy(85,15);cout<<"  "<<char(186)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(242)<<char(186)<<endl;	
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15); 
	gotoxy(94,16);cout<<" ~ 3 ~ "<<endl;
	gotoxy(94,17);cout<<" SALIR "<<endl;
	
}

int I_PRINCIPAL()
	{
	
	system ("color 0F");
	dibujo_menu();
	
	dibujo_quienes_somos();
	
	dibujo_salida();
	
	}
