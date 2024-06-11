#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "DEF_ATMEGA328P.h"
/* DEF_ATMEGA328P.h>
	------ Estructura de datos para cada puerto y pin, posteriormente utilizados en cada componente para su configuración.
*/
#include "LCD.h"
/* LCD.h>
	------ void LCD_instanciar(void)> Inicializa LCD según configuración de puertos y pines del Atmega328 que se conectan con la LCD.
	------ void LCD_goto(uint8_t x, uint8_t y)> Posiciona mediante el comando 0x80 comprendido en la LCD, para imprimir el próximo dígito en la posición indicada por el argumento (x e y).
	------ void LCD_print(char *)> Imprime el char ingresado por argumento, enviando nible por nible. 
	------ void LCD_num(int)> Imprime el valor de tipo int ingresado por argumetno, convierte el valor y utiliza LCD_print().
	------ void LCD_clear(void)> Vacía la pantalla mediante el comando 0x01 comprendido en la LCD.
*/
#include "PAD.h"
/*	PAD.h>
	------ char keys_PAD[16]> Array de char que representa a cada key del PAD.
	------ void PAD_init(void)> Configura los puertos y pines del Atmega328 para conectar el PAD.
	------ uint8_t COLUMNA_scan(void)> Escanea columna por columna detectando si alguna tecla fue presionada. En caso afirmativo, retorna 1 y deja la variable global columna en la posición seleccionada.
	------ void FILA_init(uint8_t fila)> Activa todas las filas y deja en 0 la fila indicada por el argumento.
	------ uint8_t PAD_leer(void)> Realiza la lectura completa del teclado, recorriendo cada fila y escaneando las columnas. Si detecta una tecla presionada, retorna el carácter correspondiente según keys_PAD.
*/
#include "DATA_menu.h"

bool decenasCargadas = false;

int main(void){
	LCD_instanciar();
	DATA_PTL_cargaXY();
	PAD_init();
	//menu_estadoActual = opc_agregar_interno;
	LCD_menu[menu_estadoActual]();
	//BTH_init();
	
	while (1){
		uint8_t key = PAD_leer();	// Si se presiona el pad, guarda la key presionada
		
		if (key != 0){
			switch(menu_estadoActual){
				case opc_agregar:
					switch(key){
						case '0':
							menu_estadoActual = opc_agregar_interno;
						break;
						case '>':
							menu_estadoActual = opc_bth;
						break;
					}
				break;
				case opc_bth:
					switch(key){
						case '0':
							menu_estadoActual = opc_bth_interno;
						break;
						case '<':
							menu_estadoActual = opc_agregar;
						break;
						case '>':
							menu_estadoActual = opc_quitar;
						break;
					}
				break;
				case opc_quitar:
					switch(key){
						case '0':
							menu_estadoActual = opc_quitar_interno;
						break;
						case '<':
							menu_estadoActual = opc_bth;
						break;
					}
				break;
/*
				|--------------------------------------------------------|
				|  / \                                            / \    |
				| < # >     Opción para agregar objetos al PTL   < # >   | 
				|  \ /                                            \ /    |
				|--------------------------------------------------------| 
*/
				case opc_agregar_interno:
					switch(key){
						case 'A':
							LCD_enviando();
							// Cargar método que genera el buffer de enviado en DATA_PTL.
							// Utilizar el método de envío.
							//DATA_PTL_generarEnvio(PTL_datos);
							DATA_PTL_vaciarBoxes();
						break;
						case 'B':
							LCD_stock();
							_delay_ms(200);
						break;
						case 'C':
							LCD_vaciar();
							DATA_PTL_vaciarBoxes();
							_delay_ms(200);
						break;
						case 'D':
							menu_estadoActual = opc_agregar;
						break;
						case '<':
							decenasCargadas = false;
							if(indice_box == 0)
								indice_box = 8;
							else
								indice_box--;
						break;
						case '>':
							decenasCargadas = false;
							if(indice_box == 8)
								indice_box = 0;
							else
								indice_box++;
						break;
						default:
							key_numero = key - 48;					// Se sustrae 48, porque los números representados en ASCII comienzan en el caracter 48 [ASCII(48) = '0'].
							
							if (decenasCargadas){
								boxes[indice_box].valor += key_numero;
								indice_box++;						// Luego de cargar las unidades el índice de carga avanza.
							}else{
								boxes[indice_box].valor = 0;		// Si se vuelve a cargar, se reestablece.
								boxes[indice_box].valor += (10 * key_numero);
							}
							
							decenasCargadas = !decenasCargadas;
						break;
					}
				break;
							
				case opc_bth_interno:
					switch(key){
						case 'A':
							menu_estadoActual = opc_bth_vincular;
						break;
						case 'B':
							menu_estadoActual = opc_bth_modificar;
						break;
						case 'D':
							menu_estadoActual = opc_bth;
						break;
					}
				break;
				case opc_bth_vincular:
					switch(key){
						case 'A':
							LCD_vinculando();
							_delay_ms(200);
						break;
						case 'B':
							LCD_vinculando();
							_delay_ms(200);
						break;
						case 'D':
							menu_estadoActual = opc_bth_interno;
						break;
					}
				break;
				case opc_bth_modificar:
					switch(key){
						case 'A':
							LCD_modificar();
							_delay_ms(200);
						break;
						case 'B':
							LCD_modificar();
							_delay_ms(200);
						break;
						case 'D':
							menu_estadoActual = opc_bth_interno;
						break;
					}
				break;
	/*
					|--------------------------------------------------------|
					|  / \                                            / \    |
					| < # >     Opción para quitar objetos del PTL   < # >   | 
					|  \ /                                            \ /    |
					|--------------------------------------------------------| 
	*/
				case opc_quitar_interno:
					switch(key){
						case 'A':
							LCD_enviando();
							// Cargar método que genera el buffer de enviado en DATA_PTL.
							// Utilizar el método de envío.
							//DATA_PTL_generarEnvio(PTL_datos);
							DATA_PTL_vaciarBoxes();
						break;
						case 'B':
							LCD_stock();
							_delay_ms(200);
						break;
						case 'C':
							LCD_vaciar();
							DATA_PTL_vaciarBoxes();
							_delay_ms(200);
						break;
						case 'D':
							menu_estadoActual = opc_quitar;
						break;
						case '<':
							decenasCargadas = false;
							if(indice_box == 0)
								indice_box = 8;
							else
								indice_box--;
						break;
						case '>':
							decenasCargadas = false;
							if(indice_box == 8)
								indice_box = 0;
							else
								indice_box++;
						break;
						default:
							key_numero = key - 48;					// Se sustrae 48, porque los números representados en ASCII comienzan en el caracter 48 [ASCII(48) = '0'].
							
							if (decenasCargadas){
								boxes[indice_box].valor += key_numero;
								indice_box++;						// Luego de cargar las unidades el índice de carga avanza.
							}else{
								boxes[indice_box].valor = 0;		// Si se vuelve a cargar, se reestablece.
								boxes[indice_box].valor += (10 * key_numero);
							}
							
							decenasCargadas = !decenasCargadas;
						break;
					}
				break;
			}
			
			// Muestra en pantalla luego de presionar el pad
			_delay_ms(150);
			LCD_menu[menu_estadoActual]();
		}
	}
}

