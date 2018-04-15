void hienthi (xe xe, vatcan vc)
{
	system ("cls");
	//---------------------------in duong bien-------------------------------------
	for (int i = 0; i < dong; i++)
	{
		gotoxy (0,i);
		cout << "|";
	}
	for (int i = 0; i < cot ;i++)
	{
		gotoxy(cot,i);
		cout << "|";
	}
	//---------------------------hien thi xe---------------------------------------
	for (int kdong = -1 ; kdong<= 1 ; kdong ++)
		for (int kcot =-1 ;kcot <=1 ; kcot++)
		{	int x= kcot + xe.td.x;
			int y= kdong +xe.td.y;
			
			gotoxy(x,y);
			putchar (xe.hd.a[kdong+1][kcot+1]);
		}
	//----------------------------hien thi vat can--------------------------------------
	for (int kdong = -1 ; kdong<= 1 ; kdong ++)
		for (int kcot =-1 ;kcot <=1 ; kcot++)
		{
			int x= kcot + vc.td.x;
			int y= kdong +vc.td.y;
			if (y >= 0)
			{
			gotoxy(x,y);
			putchar (vc.hd.a[kdong+1][kcot+1]);
			}
		}
}

