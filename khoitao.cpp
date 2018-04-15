void Khoitao (xe &xe, vatcan &vc)
{
	//---------------XE---------------------------------------------------
	#define pHD xe.hd.a
	xe.td.x = cot/2;
	xe.td.y = dong-2;
	
	pHD[0][0] = pHD[0][2] = pHD[2][0] = pHD[2][2] = 'o'; // banh xe
	pHD[0][1] = '^'; // dau xe
	pHD[1][0] = pHD[1][2] = '|'; // than xe
	pHD[2][1] = '-';
	pHD[1][1] = ' ';
	//--------------------VAT CAN----------------------------------------
	vc.td.x = 2 + rand() % (cot-4);
	vc.td.y = 3;
	
	vc.hd.a[0][0] = vc.hd.a[0][2] ='o';
	vc.hd.a[2][0] = 'o';
	vc.hd.a[2][2] = 'o'; // tao hinh dang vat can 1
	vc.hd.a[0][1] = '_';
	vc.hd.a[2][1] = 'V';
	vc.hd.a[1][0] = vc.hd.a[1][2] = '|';
	vc.hd.a[1][1]=' ';
}

