#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
void color(int a, int b){
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	int    nuevo_color= b + (a * 16);
	SetConsoleTextAttribute(Console, nuevo_color);
}
void gotoxy(int x,int y){
	HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
} 

void letraP(int x)
{
	 
	gotoxy(x,1);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<endl;
	gotoxy(x,2);cout<<char(219)<<char(219)<<"   "<<char(219)<<char(219)<<endl;
	gotoxy(x,3);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<endl;
	gotoxy(x,4);cout<<char(219)<<char(219)<<endl;
	gotoxy(x,5);cout<<char(219)<<char(219)<<endl;
}

void letraR(int x)
{
	
	gotoxy(x,1);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<endl;
	gotoxy(x,2);cout<<char(219)<<char(219)<<"   "<<char(219)<<char(219)<<endl;
	gotoxy(x,3);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<endl;
	gotoxy(x,4);cout<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<endl;
	gotoxy(x,5);cout<<char(219)<<char(219)<<"   "<<char(219)<<char(219)<<endl;
}

void letraE(int x)
{
	
	gotoxy(x,1);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<endl;
	gotoxy(x,2);cout<<char(219)<<char(219)<<endl;
	gotoxy(x,3);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<endl;
	gotoxy(x,4);cout<<char(219)<<char(219)<<endl;
	gotoxy(x,5);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<endl;
}

void letraC(int x)
{
	 
	gotoxy(x,1);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<endl;
	gotoxy(x,2);cout<<char(219)<<char(219)<<endl;
	gotoxy(x,3);cout<<char(219)<<char(219)<<endl;
	gotoxy(x,4);cout<<char(219)<<char(219)<<endl;
	gotoxy(x,5);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<endl;
}

void letraI(int x)
{
	
	gotoxy(x,1);cout<<char(219)<<char(219)<<endl;
	gotoxy(x,2);cout<<char(219)<<char(219)<<endl;
	gotoxy(x,3);cout<<char(219)<<char(219)<<endl;
	gotoxy(x,4);cout<<char(219)<<char(219)<<endl;
	gotoxy(x,5);cout<<char(219)<<char(219)<<endl;
}

void letraL(int x)
{
	 
	gotoxy(x,1);cout<<char(219)<<char(219)<<endl;
	gotoxy(x,2);cout<<char(219)<<char(219)<<endl;
	gotoxy(x,3);cout<<char(219)<<char(219)<<endl;
	gotoxy(x,4);cout<<char(219)<<char(219)<<endl;
	gotoxy(x,5);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<endl;
}

void letraA(int x)
{
	 
	gotoxy(x,1);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<endl;
	gotoxy(x,2);cout<<char(219)<<char(219)<<"   "<<char(219)<<char(219)<<endl;
	gotoxy(x,3);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<endl;
	gotoxy(x,4);cout<<char(219)<<char(219)<<"   "<<char(219)<<char(219)<<endl;
	gotoxy(x,5);cout<<char(219)<<char(219)<<"   "<<char(219)<<char(219)<<endl;
}

void letraD(int x)
{
	
	gotoxy(x,1);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<endl;
	gotoxy(x,2);cout<<char(219)<<char(219)<<"   "<<char(219)<<char(219)<<endl;
	gotoxy(x,3);cout<<char(219)<<char(219)<<"   "<<char(219)<<char(219)<<endl;
	gotoxy(x,4);cout<<char(219)<<char(219)<<"   "<<char(219)<<char(219)<<endl;
	gotoxy(x,5);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<endl;
}

void letraO(int x)
{
	
	gotoxy(x,1);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<endl;
	gotoxy(x,2);cout<<char(219)<<char(219)<<"   "<<char(219)<<char(219)<<endl;
	gotoxy(x,3);cout<<char(219)<<char(219)<<"   "<<char(219)<<char(219)<<endl;
	gotoxy(x,4);cout<<char(219)<<char(219)<<"   "<<char(219)<<char(219)<<endl;
	gotoxy(x,5);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<endl;
}

void letraM(int x)
{
	
	gotoxy(x,1);cout<<char(219)<<char(219)<<char(219)<<char(219)<<"   "<<char(219)<<char(219)<<char(219)<<char(219)<<endl;
	gotoxy(x,2);cout<<char(219)<<char(219)<<" "<<char(219)<<char(219)<<" "<<char(219)<<char(219)<<" "<<char(219)<<char(219)<<endl;
	gotoxy(x,3);cout<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<endl;
	gotoxy(x,4);cout<<char(219)<<char(219)<<"       "<<char(219)<<char(219)<<endl;
	gotoxy(x,5);cout<<char(219)<<char(219)<<"       "<<char(219)<<char(219)<<endl;
}

void dibujo_reciclaje(int x)
{
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 2);
	gotoxy(x+4,6);cout<<"           ____________"<<endl;
	gotoxy(x+4,7);cout<<"          {"<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(92)<<endl;
	gotoxy(x+4,8);cout<<"         /"<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(92)<<endl;
	gotoxy(x+4,9);cout<<"        /"<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(92)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(92)<<endl;
	gotoxy(x+4,10);cout<<"       /"<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<"/ "<<char(92)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(92)<<"__                 "<<endl;
	gotoxy(x+4,11);cout<<"      /"<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<"/   "<<char(92)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<"/               "<<endl;
	gotoxy(x+4,12);cout<<"      "<<char(92)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<"/    /"<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<"/"<<endl;
	gotoxy(x+4,13);cout<<"       "<<char(92)<<char(244)<<char(244)<<char(244)<<char(244)<<"/    /"<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<"/"<<endl;
	gotoxy(x+4,14);cout<<"        "<<char(92)<<char(244)<<char(244)<<"/     "<<char(238)<<char(238)<<char(238)<<char(238)<<char(238)<<char(238)<<char(238)<<char(238)<<char(238)<<"                   "<<endl;
	gotoxy(x,15);cout<<"        /"<<char(244)<<char(92)<<"                    /"<<char(244)<<char(244)<<char(92)<<endl;
	gotoxy(x,16);cout<<"      /"<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(92)<<"                 /"<<char(244)<<char(244)<<char(244)<<char(244)<<char(92)<<endl;
	gotoxy(x,17);cout<<"    /"<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(92)<<"               /"<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(92)<<"      "<<endl;
	gotoxy(x,18);cout<<"  /"<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(92)<<"            /"<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(92)<<endl;
	gotoxy(x,19);cout<<" "<<char(238)<<char(238)<<char(238)<<"/"<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<"/"<<char(238)<<char(238)<<"             "<<char(92)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(92)<<endl;
	gotoxy(x,20);cout<<"   /"<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<"/                 "<<char(92)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(92)<<endl;
	gotoxy(x,21);cout<<"  /"<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<"/           /"<<char(244)<<"|     "<<char(92)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(92)<<endl;
	gotoxy(x,22);cout<<" {"<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<"/______     /"<<char(244)<<char(244)<<"|______"<<char(92)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<"}"<<endl;
	gotoxy(x,23);cout<<"  "<<char(92)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<"|   /"<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<"/"<<endl;
	gotoxy(x,24);cout<<"   "<<char(92)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<"|   "<<char(92)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<"/"<<endl;
	gotoxy(x,25);cout<<"    "<<char(92)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<"|    "<<char(92)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<char(244)<<"/"<<endl;
	gotoxy(x,26);cout<<"     "<<char(238)<<char(238)<<char(238)<<char(238)<<char(238)<<char(238)<<char(238)<<char(238)<<char(238)<<char(238)<<char(238)<<char(238)<<char(238)<<"     "<<char(92)<<char(244)<<"|"<<char(238)<<char(238)<<char(238)<<char(238)<<char(238)<<char(238)<<char(238)<<char(238)<<char(238)<<char(238)<<char(238)<<endl;
	gotoxy(x,27);cout<<"                                        ";
}

void I_TITULO()
	{
	system ("color 0F");
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
	letraR(6);
	letraE(14);
	letraC(21);
	letraI(28);
	letraC(31);
	letraL(38);
	letraA(45);
	letraD(53);
	letraO(61);
	letraR(69);
	letraA(77);
	letraM(93);
	letraC(105);
	
	for(int i=0; i<80; i++){
	dibujo_reciclaje(i);
	}
	system("CLS");
	
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
	letraR(6);
	letraE(14);
	letraC(21);
	letraI(28);
	letraC(31);
	letraL(38);
	letraA(45);
	letraD(53);
	letraO(61);
	letraR(69);
	letraA(77);
	letraM(93);
	letraC(105);
	
	dibujo_reciclaje(35);
	
	}
	
void SOLO_TITULO()
{
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
	letraR(6);
	letraE(14);
	letraC(21);
	letraI(28);
	letraC(31);
	letraL(38);
	letraA(45);
	letraD(53);
	letraO(61);
	letraR(69);
	letraA(77);
	letraM(93);
	letraC(105);
}

