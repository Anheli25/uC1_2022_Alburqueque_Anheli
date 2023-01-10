PROCESSOR 18F57Q84
#include "Bit_Configuration.inc" /* config statements should precede project file includes. */
#include <xc.inc>
#include "Retardos.inc"
 
    PSECT resetVect,class=CODE, reloc=2
    resetVect:
        goto Main 
    Psect CODE
    
 Main:
    CALL Config_OSC,1
    CALL Config_Port,1
    CALL Delay250ms,1
    NOP

Led_On:
    BCF LATF,3,1         ;Led on
    CALL Delay250ms,1  
    CALL Delay250ms,1 
    CALL Delay250ms,1 
    CALL Delay250ms,1 
    
Led_Off:
    BSF LATF,3,1         ;Led off
    CALL Delay250ms,1  
    CALL Delay250ms,1 
    CALL Delay250ms,1 
    CALL Delay250ms,1 
    
Config_OSC:

    ;Configuración del oscilador interno a una frecuencia de 4MHz
     BANKSEL OSCCON1     ; Seleccionamos el banco donde está el registro / no viene en la hoja de dato "PSEUDOINTRUCCIÓN" 
     MOVLW  0x60         ; 01100000B // 0x60  - Seleccionamos el bloque del osc interno con un div:1    
     MOVWF  OSCCON1         
     MOVLW 0x02          ; Seleccionamos una frecuencia de 4MHz
     MOVWF OSCFRQ
     RETURN
   
Config_Port:

    ;PORT-> LAT->ANSEL->TRIS
     ;como están un mismo banco no hay necesidad de darle un banksel a cada uno
     ;Pero si se le quiere dar + portabilidad, es mejor hacerlo
     BANKSEL PORTF ; (CUANDO SE CONECTE EL PIN)
     CLRF PORTF,1    ; PORTF = 0
     ;BCF PORTF,3,1
     BSF LATF,3,1     ;LATF <3>=1  -LED OFF
     CLRF ANSELF,1    ; ANSELF <7:0> = 0  - PortF como digital
     BCF TRISF,3,1    ;TRISF<3> = 0 - RF3 como salida
     
     ;config buttom
     BANKSEL PORTA
     CLRF PORTA,1    ;PORTA<7:0> = 0
     CLRF ANSELA,1    ;PortA digital
     BSF TRISA,3,1   ;RA3 como entrada
     BSF WPUA,3,1    ;Activamos la resistencia Pull-up del pin RA3
    RETURN

END resetVect


