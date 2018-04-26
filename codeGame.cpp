#include<iostream>
#include<windows.h>
#include<time.h>
#include<conio.h>
#include<math.h>
#include"header.h"
#define ColorCode_Back			0
#define ColorCode_DarkBlue		1
#define ColorCode_DarkGreen		2
#define ColorCode_DarkCyan		3
#define ColorCode_DarkRed		4
#define ColorCode_DarkPink		5
#define ColorCode_DarkYellow	6
#define ColorCode_DarkWhite		7
#define ColorCode_Grey			8
#define ColorCode_Blue			9
#define ColorCode_Green			10
#define ColorCode_Cyan			11
#define ColorCode_Red			12



#define ColorCode_Pink			13
#define ColorCode_Yellow		14
#define ColorCode_White			15

using namespace std;

#define dong 25
#define cot 25


int thoigian = 200 ;
//------------------------------------------KHAI BAO CAU TRUC TOA DO CUA XE-------------------------------


//-------------------------------------------HAM GOTO-----------------------------------------------------

void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h) 
		h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h,c);
}

//--------------------------------------------HAM TO MAU-----------------------------------------------

void TextColor (int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , color);
}

//---------------------------------------------HAM MENU----------------------------------------------------

void inmenu()
{
		TextColor(10);
		system("cls");
		cout << "      _ _ _ _ _ _ _ _ _ _ _ _ GAME DUA XE _ _ _ _ _ _ _ _ _ _ _ _\n";
		TextColor(12);
	    cout << "\n        ************************* MENU*********************\n\n";
	    cout << "                           1 : BAT DAU CHOI       \n\n";				//dung de in menu chinh
	    cout << "                           2 : HUONG DAN CHOI GAME\n\n";
	    cout << "                           3 : MUC DO KHO\n\n";
}

//---------------------------------------------HIEN THI MUC CHON MUC---------------------------------------

void inchonmuc()
{
		TextColor(7);
		system("cls");
		cout << "          Moi ban chon muc do kho cua game:";
		cout << "\n\n                   D : DE\n";						//dung cho phan 3.Chon muc do kho
		cout << "                   T : TRUNG BINH\n";
		cout << "                   K : KHO\n";
}

//-------------------------------------------HIEN THI MUC HUONG DAN CHOI GAME------------------------------

void inhuongdan()
{
		TextColor(7);
		system("cls");
		cout << "                Nhan phim f de di chuyen sang phai.\n";
		cout << "                Nhan phim a de di chuyen sang phai.\n";
		cout << "                Nhan phim b de quay lai menu.";
}

//-------------------------------------------HAM CHO MUC 3 : CHON MUC DO KHO--------------------------------------------

void phanmuc()
{
	char nhap;
	NHAP: nhap = getch();
	if (nhap == 'd'||nhap == 'D') 
			thoigian=200;			
	else if (nhap == 't'||nhap == 'T')
			thoigian=130;
	else if (nhap == 'k'||nhap == 'K') 
			thoigian=80;
	else goto NHAP;
}

//-------------------------------------------HAM XOA MAN HINH----------------------------------------

void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;                  
	HANDLE	hConsoleOut;
	COORD	Home = {0,0};
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut,' ',csbiInfo.dwSize.X * csbiInfo.dwSize.Y,Home,&dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition);
}

//-------------------------------------------- KHOI TAO HINH DANG XE VA VAT CAN--------------------------------------

void Khoitao (xe &xe, vatcan &vc1, vatcan &vc2)
{
	
  				//-----------------------------XE----------------------------//
	
	#define pHD xe.hd.a
	xe.diem  = 0;
	xe.level = 1;
                    //--------------------vi tri cua xe--------------------//
	xe.td.x = cot/2;
	xe.td.y = dong-2;
                    //----------------hinh dang cua xe---------------------//	
	pHD[0][0] = pHD[0][2] = pHD[2][0] = pHD[2][2] = 'o'; 
	pHD[0][1] = '^'; 
	pHD[1][0] = pHD[1][2] = '|'; 
	pHD[2][1] = '-';
	pHD[1][1] = ' ';
	
				//------------------------VAT CAN 1----------------------//
                //-------------------vi tri cua vat can-----------------//
	vc1.td.x = 2 + rand() % 11;
	vc1.td.y = 1;
                    //---------------- hinh dang cua vat can----------------//	
	
	vc1.hd.a[0][0] = vc1.hd.a[0][2] ='o';
	vc1.hd.a[2][0] = 'o';
	vc1.hd.a[2][2] = 'o';
	vc1.hd.a[0][1] = '_';
	vc1.hd.a[2][1] = 'V';
	vc1.hd.a[1][0] = vc1.hd.a[1][2] = '|';
	vc1.hd.a[1][1]=' ';
	
				//-------------------------VATCAN 2------------------//
					//-------------------vi tri cua vat can 2----------------//
	vc2.td.x = 12+ rand() % 12; 
	vc2.td.y = 1;
					//-------------------hinh dang vat can 2-----------------//
	vc2.hd.a[0][0] = vc2.hd.a[0][2] ='o';
	vc2.hd.a[2][0] = 'o';
	vc2.hd.a[2][2] = 'o'; 
	vc2.hd.a[0][1] = '_';
	vc2.hd.a[2][1] = 'V';
	vc2.hd.a[1][0] = vc2.hd.a[1][2] = '|';
	vc2.hd.a[1][1]=' ';
}

//-----------------------------------------DIEU KHIEN XE---------------------------------------------------------

void dieukhien(xe &xe)
{
	if (kbhit())
	{
		char key = _getch();
		if ((key == 'F' || key =='f' ) && xe.td.x > 2)
		xe.td.x --;
		if ((key == 'J' || key == 'j') && xe.td.x <23 )
		xe.td.x ++;
		if ((key == 'Y' || key == 'y') && xe.td.y > 1 )
		xe.td.y --;
		if ((key == 'B' || key == 'b') && xe.td.y <23 )
		xe.td.y ++;
	}
}

//--------------------------------------- HIEN THI GAME-----------------------------------------------------------

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

//---------------------------------------HAM XU LY-----------------------------------------------------	

	int xuly (xe &xe , vatcan &vc1, vatcan &vc2)
{
	//----------------------------tao cam giac vat can di chuyen------------------//	
	vc1.td.y ++;
	vc2.td.y = vc2.td.y + 2;

	//-----------------------------------------tang diem va tang toc do cua xe---------------------------------
	if (vc1.td.y > 25 || vc2.td.y > 25 )
	{
		xe.diem ++;
		
		if( xe.diem % 10 == 0)
			{
				xe.level ++;
				if (thoigian > 20) 
					thoigian = thoigian-20;   //tang toc vat can
			}

			if(vc1.td.y > 25)
			{
				vc1.td.x= 2 + rand() % 22;	 // khoi tao vat can 1 sau khi xe bien mat
				vc1.td.y= -2;
			}

			if(vc2.td.y > 25)
			{
				while(abs(vc2.td.x - vc1.td.x)<= 1)
				{
				vc2.td.x= 2 + rand() % 22;
				}													// khoi tao vat can 2 sau khi xe bien mat
			    vc2.td.y= -2;
			}
	}
	//------------------------------XU LY TINH HUONG VA CHAM---------------------//
	int dx = abs(xe.td.x - vc1.td.x);           // khoang cach giua tam xe va tam vat can 1
	int dy = abs(xe.td.y - vc1.td.y);           // khoang cach xe va vat can 1

	int dxx = abs(xe.td.x - vc2.td.x);          // khoang cach giua tam xe va tam vat can 2
	int dyy = abs(xe.td.y - vc2.td.y);          // khoang cach xe va vat can 2

		if (dx <3 && dy <3)
		{
			return 1;
		}
		else if (dxx < 3 && dyy <3)
		{
			return 1;
		}
		else
		return 0;
}
int run()
{
	BATDAU:
	{
	NHAP: while(1)
		{
			inmenu();
			char chon = getch();
	    	if(chon == '1') goto CHOI;
	    	else if(chon == '2') goto TIEPTUC;
	    	else if(chon=='3') goto CHONMUC;
	    	else goto NHAP;
		}
	}

	CHONMUC:
		{
			while(1)
			{
				inchonmuc();
				phanmuc();
				goto BATDAU;
			}
		}
	TIEPTUC:
		{
			while(1)
			{
				inhuongdan();
			    char quaylai = getch();
			    if(quaylai == 'b' || quaylai == 'B') 
				goto BATDAU;
			}

		}
	CHOI:
		{
			
			srand (time (NULL)); // bo sinh so ngau nhien
			xe xe;
			vatcan vc1;
			vatcan vc2;
			Khoitao (xe,vc1,vc2);
			while (1)
			{
				//-----------------------hien thi----------------//
				hienthi(xe, vc1, vc2);
				//-----------------------dieukhien---------------//
				dieukhien(xe);
				//-----------------------xu ly-------------------//
				int ma = xuly( xe, vc1, vc2);
				//---------------------game over--------------//
				if(ma == -1)// va cham thi dung chay
					{
						TextColor(4);
						gotoxy(60,5);// chuyen den vi tri (60,5) in ra
						cout << "GAME OVER " << endl ;
						gotoxy(60,6);
						cout << "DIEM CUA BAN LA : " << xe.diem << endl ;
						gotoxy(60,7);
						cout << "CHOI LAI ?" << endl;
						gotoxy(60,8);
						cout << "<Y/N>";
						if (getch()=='Y'||getch()=='y') 
						goto BATDAU; // nhap vao phim enter ket thuc chung trinh
						else break;
					}
			Sleep (thoigian);    // thoi gian lam cham
			}
		}
	return 0;
}

