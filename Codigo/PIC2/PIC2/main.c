#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#include "DEF_ATMEGA328P.h"
/*
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

int main(void)
{
	LCD_instanciar();
	PAD_init();
	LCD_print("F");
	LCD_num(145);
	BTH_init();
	
	while (1)
	{
		
		/*
		// Leo pad
		uint8_t key = PAD_leer();
		if (key != 0)
		{
			switch(menuPrincipal_estadoActual)
			{
				case opc_bth:
					if(in_menuPrincipal)	// FSM para menu principal
					{
						if(key == '>')					// Se dirige a la opción de la derecha
							menuPrincipal_estadoActual = opc_agregar;
						else if(key == '0')				// 0 selecciona y envia el menu interno a la LCD
						{
							// Vaciar valores de las box
							menuInterno_estadoActual = opc_bth_opcA;
							in_menuPrincipal = false;							
						}
					} 
					else						// FSM para menu interno
					{
						switch(menuInterno_estadoActual)
						{
							case opc_bth_opcA:
							if (key == '>')
								menuInterno_estadoActual = opc_bth_opcB;
							break;

							case opc_bth_opcB:
							if (key == '<')
								menuInterno_estadoActual = opc_bth_opcA;
							else if (key == '>')
								menuInterno_estadoActual = opc_bth_opcC;
							break;

							case opc_bth_opcC:
							if (key == '<')
								menuInterno_estadoActual = opc_bth_opcB;
							break; 
						}
					}
				break;
				case opc_agregar:
					if (menu_muestra_interno)
					{
						if (key == '<')
						{
							menuPrincipal_estadoActual = opc_bth;
						}
						else if (key == '>')
						{
							menuPrincipal_estadoActual = opc_quitar;
						}
						else if (key == '0')
						{
							menuInterno_estadoActual = opc_agregar_int;
							in_menuPrincipal = false;
						}
					}
					else
					{											// Acciones dentro del menu interno agregar.
						if (key == 'A')
						{ // Enviar.
							// mostrarDatos(); Muestra la cantidad que tiene cada box !
							// Llamar a función que envía nuevo stock.
						}
						else if (key == 'B')
						{ 
							// Ver stock.
						}
						else if (key == 'C')
						{ 
							// Vaciar celda.
						}
						else if (key == 'D')
						{ // Volver.
							//indBox = 0;
							in_menuPrincipal = true;
						}
					}
				break;
				case opc_quitar:
					if (in_menuPrincipal)
					{
						if (key == '<')
						{
							menuPrincipal_estadoActual = opc_agregar;
						}
						else if (key == '0')
						{
							menuInterno_estadoActual = opc_quitar_int;
							in_menuPrincipal = false;
						}
					}
					else
					{											// Acciones dentro del menu interno quitar.
						if (key == 'A')
						{ // Enviar.
							// mostrarDatos(); Muestra la cantidad que tiene cada box !
							// Llamar a función que envía nuevo stock.
						}
						else if (key == 'B')
						{
							// Ver stock.
						}
						else if (key == 'C')
						{
							// Vaciar celda.
						}
						else if (key == 'D')
						{ // Volver.
							//indBox = 0;
							in_menuPrincipal = true;
						}
					}
				break;
			}		
			
			// Muestro pantalla luego de presionar el pad
			if(in_menuPrincipal)
				menu_muestra_principal[menuPrincipal_estadoActual]();
			else
				menu_muestra_interno[menuInterno_estadoActual]();
		}
	*/
	}
}
