#include<iostream>
#include<windows.h>
#include<conio.h>


static int thoigian = 200 ;

//------------------------------------------KHAI BAO CAU TRUC TOA DO CUA XE-------------------------------

 typedef struct
{
	int x,y;
} toado;

//------------------------------------------KHAI BAO CAU TRC HINH DANG XE--------------------------------

typedef struct
{
	char a[3][3];
} hinhdang;

//-------------------------------------------KHAI BAO CAU TRUC XE-----------------------------------------

 typedef struct
{
	toado td;
	hinhdang hd;
	int diem;
	int level;
} xe;

//--------------------------------------------KHAI BAO CAU TRUC VAT CAN-----------------------------------

 typedef struct
{
	toado td;
	hinhdang hd;
} vatcan;


void dieukhien(xe &xe);
void phanmuc();
void gotoxy(int x, int y);
int xuly(xe& xe, vatcan& vc1, vatcan& vc2);
