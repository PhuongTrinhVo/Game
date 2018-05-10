

#include"xoa.h"
#include"DieuKhien.h"
#include"hienThi.h"


using namespace std;


void TextColor (int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , color);
}

//---------------------------------------------HAM MENU----------------------------------------------------

void inmenu()
{
		TextColor(10);
		system("cls");
		cout << "      _ _ _ _ _ _ _ _ _ _ _ _ GAME DUA XE _ _ _ _ _ _ _ _ _ _ _ _\n\n";
		TextColor(12);
	    cout << "        |*************************MENU**********************|\n";
	    cout << "        |                                                   |\n";
	    cout << "        |                1 : BAT DAU CHOI                   |\n";
	    cout << "        |                                                   |\n";
	    cout << "        |                2 : HUONG DAN CHOI GAME            |\n";
	    cout << "        |                                                   |\n";
	    cout << "        |                3 : MUC DO KHO                     |\n";
	    cout << "        |                                                   |\n";
	    cout << "        |***************************************************|";
}

//---------------------------------------------HIEN THI MUC CHON MUC---------------------------------------

void inchonmuc()
{
		TextColor(6);
		system("cls");
        cout << "        |***********************************************|\n";
	    cout << "        |                                               |\n";
	    cout << "        |                D : DE                         |\n";
	    cout << "        |                                               |\n";
	    cout << "        |                T : TRUNG BINH                 |\n";
	    cout << "        |                                               |\n";
	    cout << "        |                K : KHO                        |\n";
	    cout << "        |                                               |\n";
	    cout << "        |***********************************************|";
}


//-------------------------------------------HIEN THI MUC HUONG DAN CHOI GAME------------------------------

void inhuongdan()
{
		TextColor(10);
		system("cls");
		cout << " ____________________________________________________________\n";
		cout << "|                                                            |\n";
		cout << "|               PHIM J :  DI CHUYEN SANG PHAI                |\n";
		cout << "|               PHIM F :  DI CHUYEN SANG TRAI                |\n";
		cout << "|               PHIM Y :  DI CHUYEN LEN TREN                 |\n";
		cout << "|               PHIM B :  DI CHUYEN XUONG DUOI               |\n";
		cout << "|               PHIM A :  DI CHUYEN VE MENU CHINH            |\n";
		cout << "|____________________________________________________________|";
}



void hienthi (xe xe, vatcan vc1, vatcan vc2)
{
	       //-------------------------hien thi duong bien--------------------//
	clrscr();
	for (int i = 0; i < dong; i++)
	{
		gotoxy (0,i);
		TextColor(6);
		cout << "||";
	}
	for (int i = 0; i < cot ;i++)
	{
		gotoxy(cot,i);
		TextColor(6);
		cout << "||";
	}


	        //--------------------------hien thi xe-----------------------//
	for (int i = -1 ; i <= 1 ; i ++)
		for (int j =-1 ;j <=1 ; j++)
		{
			int x = j + xe.td.x;
			int y = i + xe.td.y;
			gotoxy (x,y);
			TextColor(4);
			putchar (xe.hd.a[i+1][j+1]);
		}

	        //--------------------------hien thi vat can 1-----------------//
	for(int i = -1; i <= 1; i++)
		for(int j = -1; j <= 1; j++)
		{
			int x = j+ vc1.td.x;
			int y = i+ vc1.td.y;

			if(y >=0 && y <25)
			{
				gotoxy(x,y);
				TextColor(1);
		    	putchar(vc1.hd.a[i+1][j+1]);
			}
		}
			//--------------------------hien thi vat can 2-----------------//

	for(int i = -1; i <= 1; i++)
		for(int j = -1; j <= 1; j++)
	{
		int z,t;
		z = j+ vc2.td.x ;
		t = i+ vc2.td.y ;

		if(t >=0 && t <25)
		{
			gotoxy(z,t);
			TextColor(1);
		    putchar(vc2.hd.a[i+1][j+1]);
		}
    }
	     	//--------------------------hien thi trang thai game------------//

	gotoxy (cot+15 ,10);
	cout << "DIEM  = " << xe.diem;
	gotoxy (cot+15,11);
	cout << "LEVEL = " << xe.level;
}
