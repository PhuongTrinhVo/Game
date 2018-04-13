#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
#include<math.h>

#define dong 25
#define cot 25

int thoigian=200;

typedef struct // Khai bao cau truc toa do cua xe
{
	int x,y;
} toado;

typedef struct // khai bao cau truc hinh dang xe
{
	char a[3][3];
} hinhdang;

typedef struct // khai bao cau truc xe
{
	toado td;
	hinhdang hd;
	int diem;
	int level;
} xe;

typedef struct // khai bao cua truc vat can
{
	toado td;
	hinhdang hd;
} vatcan;


void gotoxy(int , int ); //dich chuyen con tro toi vi tri (x,y) tren man hinh

void hienthi(xe,vatcan,vatcan); // ham hien thi xe va vat can

void gotoxy(int x, int y)
{
    static HANDLE h = NULL;
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h,c);
}

void induongbien(){
	int i,j;
	system("cls");// ham xoa man hinh

	for(i=0;i<dong;i++) // in duong bien
	{
		gotoxy(0,i);
		printf("|");
	}

	for(i=0;i<dong;i++) // in duong bien
	{
		gotoxy(cot,i);
		printf("|");
	}
}

void hienthi(xe xe, vatcan vc1, vatcan vc2)
{
	int i,j;
	for(i=-1;i<=1;i++) // hien thi vat can
		for(j=-1;j<=1;j++)
		{
			int c,d;
			c=j+ vc1.td.x;
			d=i+ vc1.td.y;

			if(d>=0 && d<25)
			{
				gotoxy(c,d);
		    	putchar(vc1.hd.a[i+1][j+1]);
			}
		}

	for(i=-1;i<=1;i++) // hien thi vat can
	for(j=-1;j<=1;j++)
	{
		int p,l;
		p=j+ vc2.td.x;
		l=i+ vc2.td.y;

		if(l>=0 && l<25)
		{
			gotoxy(p,l);
		    putchar(vc2.hd.a[i+1][j+1]);
		}

	}

	for(i=-1;i<=1;i++) // hien thi xe
	for(j=-1;j<=1;j++)
	{
		int c,d;
		c=j+ xe.td.x;
		d=i+ xe.td.y;
		gotoxy(c,d);
		putchar(xe.hd.a[i+1][j+1]);
	}

	gotoxy(cot+15 ,10);
	printf("DIEM  =  %d",xe.diem);
	gotoxy(cot+15,11);
	printf("LEVEL  = %d ",xe.level);
}

void inmenu(){
		system("cls");
		printf("      _ _ _ _ _ _ _ _ _ _ _ _ GAME DUA XE _ _ _ _ _ _ _ _ _ _ _ _\n");
	    printf("\n                                  MENU\n\n");
	    printf("                           1 : BAT DAU CHOI       \n\n");				//dung de in menu chinh
	    printf("                           2 : HUONG DAN CHOI GAME\n\n");
	    printf("                           3 : MUC DO KHO\n\n");
}

void inchonmuc(){
		system("cls");
		printf("          Moi ban chon muc do kho cua game:");
		printf("\n\n                   D : DE\n");						//dung cho phan 3.Chon muc do kho
		printf("                   T : TRUNG BINH\n");
		printf("                   K : KHO\n");
}

void inhuongdan(){
		system("cls");
		printf("                Nhan phim f de di chuyen sang phai.\n");
		printf("                Nhan phim a de di chuyen sang phai.\n");
		printf("\n");
		printf("                Nhan phim b de quay lai menu.");
}

void phanmuc(){
	char nhap;
	NHAPLAI: nhap=getch();
	if (nhap=='d'||nhap=='D') thoigian=200;			//dung cho phan 3.Chon muc do kho
	else if (nhap=='t'||nhap=='T') thoigian=130;
	else if (nhap=='k'||nhap=='K') thoigian=80;
	else goto NHAPLAI;
}

//HÀM CHÍNH  HUHUHU
int main()
{
	BATDAU:
	{
		NHAPLAIA: while(1) {
			inmenu();
			char chon=getch();
	    	if(chon=='1') goto CHOI;
	    	else if(chon=='2') goto TIEPTUC;
	    	else if(chon=='3') goto CHONMUC;
	    	else goto NHAPLAIA;
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
			    char quaylai=getch();
			    if(quaylai=='b'||quaylai=='B') goto BATDAU;
			}

		}

	CHOI:
	{
	int ketthuc;

	srand (time (NULL)); // bo sinh so ngau nhien

	 // thoi gian ban dau

	xe xe;

	xe.diem=0;// diem
	xe.level=1; // level

	xe.td.y = dong-2;// khoi tao vi tri xe
	xe.td.x = cot/2; //khoi tao vi tri xe

	xe.hd.a[2][0] = xe.hd.a[2][1] = xe.hd.a[2][2] = '-';// tao hinh dang xe
	xe.hd.a[0][0] = xe.hd.a[0][2] = '|';
	xe.hd.a[1][0] = xe.hd.a[1][2] = '|';
	xe.hd.a[1][1] =' ';
	xe.hd.a[0][1] ='A';

	vatcan vc1;
	vc1.td.x =2+ rand() % 11;//vi tri vat can 1
	vc1.td.y=1;
	vc1.hd.a[0][0] = vc1.hd.a[0][2] ='T';
	vc1.hd.a[2][0] = '|';
	vc1.hd.a[2][2] = '|'; // tao hinh dang vat can 1
	vc1.hd.a[0][1] = '_';
	vc1.hd.a[2][1] = 'V';
	vc1.hd.a[1][0] = vc1.hd.a[1][2] = '|';
	vc1.hd.a[1][1]=' ';


	vatcan vc2=vc1;     //hinh dang vat can 2 giong 1
	vc2.td.x =12+ rand() % 12; // vi tri vat can 2
	vc2.td.y=1;


	while(1) // chay chuong trinh
	{
		induongbien();
		hienthi(xe, vc1, vc2);

	if(kbhit()) // dieu khien xe.
	{
		char nhap;
		nhap=getch(); // nhap vao 1 ki tu de dieu khien
		if((nhap=='a' ||nhap=='A') && xe.td.x>2) // dieu khien sang trai
		xe.td.x--;

		else if((nhap=='f' ||nhap=='F') && xe.td.x<23) // dieu khien sang phai
		xe.td.x++;
	}

		// XU LI VA CHAM
		vc1.td.y++;// cho vat can di xuong
		vc2.td.y=vc2.td.y +2;
		if(vc1.td.y>25 || vc2.td.y>25) // neu vuot qua bien thi khoi tao lai vat can va tang toc do vat can
		{
			xe.diem++; // tang diem

			if(xe.diem%6==0)
			{
				xe.level ++;
				if (thoigian>20) thoigian=thoigian-20;   //tang toc vat can
			}

			if(vc1.td.y>25)
			{
				vc1.td.x= 2+rand() %22;		// khoi tao vat can sau khi xe bien mat
				vc1.td.y=-2;
			}

			if(vc2.td.y>25)
			{
				while(abs(vc2.td.x - vc1.td.x)<= 1)
				{
				vc2.td.x= 2 + rand() % 22;
				}													// khoi tao vat can sau khi xe bien mat
			    vc2.td.y=-2;
			}

		}

		int dx = abs(xe.td.x-vc1.td.x);// khoang cach giua tam xe va tam vat can
		int dy = abs(xe.td.y-vc1.td.y);// khoang cach xe va vat can

		int dxx = abs(xe.td.x-vc2.td.x);// khoang cach giua tam xe va tam vat can
		int dyy = abs(xe.td.y-vc2.td.y); // khoang cach xe va vat can

		if(dx<3 && dy<3 || dxx<3 && dyy<3)
		{
			ketthuc=1;
		}
		if(ketthuc==1)// va cham thi dung chay
		{
			gotoxy(5,5);// chuyen den vi tri (5,5) in ra
			printf("  LOSER ");
			printf("\n      Diem cua ban la %d",xe.diem);
			printf("\n\n    Choi lai ?");
			printf("\n           <Y/N>");
			if (getch()=='Y'||getch()=='y') goto BATDAU; // nhap vao phim enter ket thuc chung trinh
			else break;
		}
		Sleep (thoigian);    // thoi gian lam cham
	}
	}
	return 0;
}


