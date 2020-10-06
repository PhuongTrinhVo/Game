#include"DieuKhien.h";


void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h,c);
}

void gotoXPoint(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h,c);
}

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

		if (dx <3 && dy <2)
		{
			return -1;
		}
		else if (dxx < 3 && dyy <2)
		{
			return -1;
		}
		else
		return 0;
}
