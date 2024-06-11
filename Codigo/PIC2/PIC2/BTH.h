#include <avr/io.h>
#include <string.h>

char data[20] = "";				// Aquí se almacena la info recibida del bth

void BTH_init(){
	// USART como UART
	UCSR0C &=~ (1<<UMSEL00);
	UCSR0C &=~ (1<<UMSEL01);
	
	// Paridad desactivada
	UCSR0C &=~ (1<<UPM00);
	UCSR0C &=~ (1<<UPM01);
	
	// Bit de parada = 1
	UCSR0C &=~ (1<<USBS0);
	
	// 8-bits para datos
	UCSR0C |= (1<<UCSZ00);
	UCSR0C |= (1<<UCSZ01);
	
	UCSR0B &=~ (1<<UCSZ02);
	
	// Calculo baudrate
	UCSR0A |= (1<<U2X0);
	UBRR0 = (F_CPU/8/9600) - 1;
		
	UCSR0B |= (1<<TXEN0);
	UCSR0B |= (1<<RXEN0);
}

void BTH_recibe(){
	memset(data, 0, sizeof(data)); // Limpia los registros
	int i = 0;
	while(i<20){
		while(!(UCSR0A & (1<<UDRE0)));
		data[i] = UDR0;

		if(data[i] == '\n') // Espera el salto de linea
		{
			i=20;
		}
		i++;
	}
}
