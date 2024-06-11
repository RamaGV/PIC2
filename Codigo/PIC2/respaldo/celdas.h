struct celda {
	int valor;
	int LCD_X;
	int LCD_Y;
};
struct celda celdas[9];
int indiceCelda = 0;

void vaciarCeldas(){
	for(int i=0; i<9; i++){
		celdas[i].valor = 0;
	}
}

void instanciarCeldas(){
	celdas[0].LCD_X = 4;
	celdas[0].LCD_Y = 2;

	celdas[1].LCD_X = 11;
	celdas[1].LCD_Y = 2;
	
	celdas[2].LCD_X = 18;
	celdas[2].LCD_Y = 2;
	
	celdas[3].LCD_X = 4;
	celdas[3].LCD_Y = 3;

	celdas[4].LCD_X = 11;
	celdas[4].LCD_Y = 3;
	
	celdas[5].LCD_X = 18;
	celdas[5].LCD_Y = 3;
	
	celdas[6].LCD_X = 4;
	celdas[6].LCD_Y = 4;

	celdas[7].LCD_X = 11;
	celdas[7].LCD_Y = 4;
	
	celdas[8].LCD_X = 18;
	celdas[8].LCD_Y = 4;
}

