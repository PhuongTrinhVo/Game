void hienthi(xe,vatcan,vatcan); // ham hien thi xe va vat can

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
