/*
 * File:   JuegoDeCarreras.c
 * Author: Santiago Fernandez
 *
 * Created on January 30, 2021, 4:33 PM
 */


#include <xc.h>
//******************************************************************************
//Configuration Bits
//******************************************************************************
// CONFIG1
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator: Crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

//******************************************************************************
//Variables
//******************************************************************************

#define _XTAL_FREQ 8000000
#define LedR PORTAbits.RA2
#define LedV PORTAbits.RA0
#define LedA PORTAbits.RA1
//******************************************************************************
//Prototipos de Funciones
//******************************************************************************
void setup(void);
void StartSecuence(void);
//******************************************************************************
//Loop Principal
//******************************************************************************

/* Info general del circuito
 *   Semaforo: 
 *     Boton de inicio: pin RA3
 *     Verde: pin RA0
 *     Amarillo: pin RA1
 *     Rojo: pin RA2
 *   Jugador 1:
 *     Boton de avance: pin RA4
 *     Contador decada: puerto C completo
 *   Jugador 2:
 *     Boton de avance: pin RA5
 *     Contador decada: puerto D completo 
 */
void main(void) {
    setup();

    while (1) {
        if (PORTAbits.RA3==1){
            StartSecuence();
        }
    }
}


//******************************************************************************
//Setup
//******************************************************************************

void setup(void) {
    ANSEL = 0;
    ANSELH = 0;
    TRISD = 0;
    TRISC = 0;
    TRISAbits.TRISA0 = 0;
    TRISAbits.TRISA1 = 0;
    TRISAbits.TRISA2 = 0;
    TRISAbits.TRISA3 = 1;
    TRISAbits.TRISA4 = 1;
    TRISAbits.TRISA5 = 1;
    PORTD = 0;
    PORTC = 0;
    LedR = 0;
    LedV = 0;
    LedA = 0;
    
}

/*Secuencia del Semaforo*/
void StartSecuence(void){
    LedR = 1;
    __delay_ms(600);
    LedR = 0;
    LedA = 1;
    __delay_ms(600);
    LedA = 0;
    LedV = 1;
}