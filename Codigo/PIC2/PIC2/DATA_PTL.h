// Agregar estructura de comunicación con el PTL
// En la estructura, un atributo "buffer_envio" -> contiene el mensaje a enviar
// Crear un método que recorra las boxes y genere el buffer_envio
// https://replit.com/@ramirovazquez4/Prueba-de-concepto#main.c
#include <string.h>

struct box {
	int valor;
	int LCD_X;
	int LCD_Y;
};

struct datosPTL{
	char* addr_bth;
	char buffer_envio[256];
	//int indice_box = 0;
	//struct box boxes[9];
};

struct datosPTL PTL_datos;
struct box boxes[9];
int indice_box = 0;

void DATA_PTL_generarEnvio(struct datosPTL nuevoPTL) {
	for (int i = 0; i < 9; i++) {
		char temp_str[10]; 
		sprintf(temp_str, "%d", boxes[i].valor);
		strcat(nuevoPTL.buffer_envio, temp_str);
		strcat(nuevoPTL.buffer_envio, "#");
	}
}

void DATA_PTL_vaciarBoxes(){
	for(int i=0; i<9; i++){
		boxes[i].valor = 0;
	}
	indice_box = 0;
}

void DATA_PTL_cargaXY(){
	boxes[0].LCD_X = 4;
	boxes[0].LCD_Y = 2;

	boxes[1].LCD_X = 11;
	boxes[1].LCD_Y = 2;
	
	boxes[2].LCD_X = 18;
	boxes[2].LCD_Y = 2;
	
	boxes[3].LCD_X = 4;
	boxes[3].LCD_Y = 3;

	boxes[4].LCD_X = 11;
	boxes[4].LCD_Y = 3;
	
	boxes[5].LCD_X = 18;
	boxes[5].LCD_Y = 3;
	
	boxes[6].LCD_X = 4;
	boxes[6].LCD_Y = 4;

	boxes[7].LCD_X = 11;
	boxes[7].LCD_Y = 4;
	
	boxes[8].LCD_X = 18;
	boxes[8].LCD_Y = 4;
}

