#include<iostream>
#include<windows.h>
#include<time.h>
#include<conio.h>
#include<math.h>
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


#include"DieuKhien.h"
#include"hienThi.h"
#include"xoa.h"


using namespace std;


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
	vc1.td.x = 3 + rand() % 10;
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



int main ()
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
			    if(quaylai == 'a' || quaylai == 'A')
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
