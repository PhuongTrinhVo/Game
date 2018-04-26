#include<iostream>
#include<windows.h>
#include<time.h>
#include<conio.h>
#include<math.h>
using namespace std;
typedef struct
{
	char a[3][3];
} hinhdang;
typedef struct 
{
	int x,y;
} toado;
typedef struct 
{
	toado td;
	hinhdang hd;
	int diem;
	int level;
} xe;

typedef struct 
{
	toado td;
	hinhdang hd;
} vatcan;
void gotoxy(int x, int y);
void TextColor (int color);
void inmenu();
void inchonmuc();
void inhuongdan();
void phanmuc();
void clrscr();
void Khoitao (xe &xe, vatcan &vc1, vatcan &vc2);

void dieukhien(xe &xe);
void hienthi (xe xe, vatcan vc1, vatcan vc2);
	int xuly (xe &xe , vatcan &vc1, vatcan &vc2);
	int run();
