void induongbien()
{
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

