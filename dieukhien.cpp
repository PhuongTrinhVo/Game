void dieukhien(xe &xe)
{
	if (kbhit())
	{
		char key = _getch();
		if ((key == 'F' || key =='f' ) && xe.td.x > 2)
		xe.td.x --;
		if ((key == 'J' || key == 'j') && xe.td.x <23 )
		xe.td.x ++;
		if ((key == 'Y' || key == 'y') && xe.td.y >0 )
		xe.td.y --;
		if ((key == 'B' || key == 'b') && xe.td.y <23 )
		xe.td.y ++;
	}
}

