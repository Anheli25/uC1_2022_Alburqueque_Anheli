PROCESSOR 18F57Q84
#include "Bit_Config.inc" // config statements should precede project file includes.
#include <xc.inc>
#include "retardo.inc"
PSECT resetVect,class=CODE,reloc=2
resetVect:
    goto Main
    
PSECT CODE
 Main:
 CALL Config_OSC,1
 CALL Config_port,1
 CALL delay_250ms,1
 NOP
 ;Loop:

  ;  BTFSC PORTA,3,0  ;PORTA<3>=0? - Button Press?
   ; goto Led_off
 Led_on:
    BCF LATF,3,1  ; LED on
    Call delay_250ms,1
    Call delay_250ms,1
    Call delay_250ms,1
    Call delay_250ms,1
 Led_off:
   BSF LATF,3,1  ;LED off
   Call delay_250ms,1
   Call delay_250ms,1
   Call delay_250ms,1
   Call delay_250ms,1
   GOTO Led_on
    
 
 Config_OSC: ;port-lat-ansel-tris  led:rf3
    ;configuracion del oscilador interno a una frecuencia d 4MHz
    BANKSEL OSCCON1
    MOVLW 0x60     ;seleccionamos l bloque del osc interno on un divisor de 1
    MOVWF OSCCON1
    MOVLW 0x02    ;seleccionamos una frecuencia de 4MHz
    MOVWF OSCFRQ
    
RETURN 
    
Config_port:
    ;Config LED
    BANKSEL PORTF
    CLRF PORTF      ;PORTF=0
    BSF LATF,3,1    ;LATF<3>=1-- LED OFF
    CLRF ANSELF,1   ;ANSELF<7:0>=0 --PORT F DIGITAL
    BCF TRISF,3,1   ;TRISF<3>=0 RF3 COMO SALIDA 
    
    ;Config Button 
    BANKSEL PORTA
    CLRF PORTA,1   ;PORTA <7:0> =0
    CLRF ANSELA,1  ;PortA digital
    BSF TRISA,3,1  ;RA3 como entrada
    BSF WPUA,3,1    ;ACTIVAMOS LA RESISTENCIA Pull- Up del pin RA3
RETURN
  
END resetVect

