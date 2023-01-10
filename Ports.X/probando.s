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
    CALL Delay_10us
    NOP

PSECT udata_acs
Variable1: DS 1      ;reserva un comentario en access ram
Variable2: DS 1      ;reserva un comentario en access ram
  
Config_OSC:

    ;Configuración del oscilador interno a una frecuencia de 4MHz
     BANKSEL OSCCON1     ; Seleccionamos el banco donde está el registro / no viene en la hoja de dato "PSEUDOINTRUCCIÓN" 
     MOVLW  0x60         ; 01100000B // 0x60  - Seleccionamos el bloque del osc interno con un div:1    
     MOVWF  OSCCON1,1         
     MOVLW 0x02          ; Seleccionamos una frecuencia de 4MHz
     MOVWF OSCFRQ,1
     RETURN
     
PSECT code
    ;; Retardo1(10us)
       ;T=(6+4k1)*TCY  
Delay_10us:                  ;  2TCY---CALL
    MOVLW  1                 ;  1TCY.... w=k1
    MOVWF  Variable1,0       ;  1TCY
Loopa:   
    NOP                      ;  k1*TCY
    DECFSZ Variable1,1,0     ;  (k1-1) + 3*TCY
    GOTO   Loopa             ;  (k1-1)*2TCY
    RETURN                   ;  2*TCY