#include <stdbool.h>
#include "DATA_PTL.h"

void LCD_agregar();
void LCD_bth();
void LCD_quitar();
void LCD_agregar_interno();
void LCD_quitar_interno();
void LCD_bth_interno();
void LCD_bth_vincular();
void LCD_bth_modificar();

enum menu{
	// Menu principal
	opc_bth,
	opc_agregar,
	opc_quitar,
	
	// Menus internos.
	opc_agregar_interno,
	opc_quitar_interno,
	opc_bth_interno,
	opc_bth_vincular,
	opc_bth_modificar
};
enum menu menu_estadoActual = opc_bth;
typedef void (*Menu_FSM)();

Menu_FSM LCD_menu[] = {LCD_bth, LCD_agregar, LCD_quitar, LCD_agregar_interno, LCD_quitar_interno, LCD_bth_interno, LCD_bth_vincular, LCD_bth_modificar};

void LCD_agregar(){
	LCD_clear();
	LCD_goto(1,1); LCD_print("12:00      Bat. 100%");
	LCD_goto(1,2); LCD_print("--------------------");
	LCD_goto(1,3); LCD_print("|      Agregar  >  |");
	LCD_goto(1,4); LCD_print("--------------------");
}
void LCD_bth(){
	LCD_clear();
	LCD_goto(1,1); LCD_print("12:00      Bat. 100%");
	LCD_goto(1,2); LCD_print("--------------------");
	LCD_goto(1,3); LCD_print("| <  Bluetooth  >  |");
	LCD_goto(1,4); LCD_print("--------------------");
}
void LCD_quitar(){
	LCD_clear();
	LCD_goto(1,1); LCD_print("12:00      Bat. 100%");
	LCD_goto(1,2); LCD_print("--------------------");
	LCD_goto(1,3); LCD_print("|  <   Quitar      |");
	LCD_goto(1,4); LCD_print("--------------------");
}

void LCD_boxes(){ // Método de muestreo que reutiliza código en opción agregar y quitar
	// Carga datos que se van almacenando en la estructura de celdas, análogo a la solicitud por enviar
	for(int i=0; i<9; i++){
		LCD_goto(boxes[i].LCD_X, boxes[i].LCD_Y);
		LCD_num(boxes[i].valor/10);
		LCD_goto(boxes[i].LCD_X+1, boxes[i].LCD_Y);
		LCD_num(boxes[i].valor%10);
	}
	
	// Primero se dirige a la posición que representa al número de casilla/box seleccionada, luego imprime una X
	LCD_goto(boxes[indice_box].LCD_X - 2, boxes[indice_box].LCD_Y);
	LCD_print("X");
}
void LCD_agregar_interno(){
	LCD_clear();
	LCD_goto(1,1); LCD_print("Agregar    Bat. 100%");
	LCD_goto(1,2); LCD_print("|1:00 | 2:00 | 3:00|");
	LCD_goto(1,3); LCD_print("|4:00 | 5:00 | 6:00|");
	LCD_goto(1,4); LCD_print("|7:00 | 8:00 | 9:00|");
	
	LCD_boxes();
}
void LCD_quitar_interno(){
	LCD_clear();
	LCD_goto(1,1); LCD_print("Quitar     Bat. 100%");
	LCD_goto(1,2); LCD_print("|1:00 | 2:00 | 3:00|");
	LCD_goto(1,3); LCD_print("|4:00 | 5:00 | 6:00|");
	LCD_goto(1,4); LCD_print("|7:00 | 8:00 | 9:00|");
	
	LCD_boxes();
}

void LCD_bth_interno(){
	LCD_clear();
	LCD_goto(1,1); LCD_print("Bth.       Bat. 100%");
	LCD_goto(1,2); LCD_print("|   A - Vincular   |");
	LCD_goto(1,3); LCD_print("|   B - Modificar  |");
	LCD_goto(1,4); LCD_print("|   D - Volver     |");
}
void LCD_bth_vincular(){
	LCD_clear();
	LCD_goto(1,1); LCD_print("Bth         Vincular");
	LCD_goto(1,2); LCD_print("| A- Resistencias  |");
	LCD_goto(1,3); LCD_print("| B- Tornillos     |");
	LCD_goto(1,4); LCD_print("| D- Volver        |");
}
void LCD_bth_modificar(){
	LCD_clear();
	LCD_goto(1,1); LCD_print("Bth        Modificar");
	LCD_goto(1,2); LCD_print("| A- Resistencias  |");
	LCD_goto(1,3); LCD_print("| B- Tornillos     |");
	LCD_goto(1,4); LCD_print("| D- Volver        |");
}
void LCD_stock(){
	LCD_clear();
	LCD_goto(1,1); LCD_print("|                  |");
	LCD_goto(1,2); LCD_print("|      Stock..     |");
	LCD_goto(1,3); LCD_print("|                  |");
	LCD_goto(1,4); LCD_print("|                  |");
}
void LCD_enviando(){
	LCD_clear();
	LCD_goto(1,1); LCD_print("|                  |");
	LCD_goto(1,2); LCD_print("|     Enviando..   |");
	LCD_goto(1,3); LCD_print("|                  |");
	LCD_goto(1,4); LCD_print("|                  |");
}
void LCD_vaciar(){
	LCD_clear();
	LCD_goto(1,1); LCD_print("|                  |");
	LCD_goto(1,2); LCD_print("|     Vaciando..   |");
	LCD_goto(1,3); LCD_print("|                  |");
	LCD_goto(1,4); LCD_print("|                  |");
}

void LCD_vinculando(){
	LCD_clear();
	LCD_goto(1,1); LCD_print("|                  |");
	LCD_goto(1,2); LCD_print("|   Vinculando..  |");
	LCD_goto(1,3); LCD_print("|                  |");
	LCD_goto(1,4); LCD_print("|                  |");
}

void LCD_modificar(){
	LCD_clear();
	LCD_goto(1,1); LCD_print("|                  |");
	LCD_goto(1,2); LCD_print("|    Modificar..   |");
	LCD_goto(1,3); LCD_print("|                  |");
	LCD_goto(1,4); LCD_print("|                  |");
}
