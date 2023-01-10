PROCESSOR 18F57Q84
#include "Bit_Configuration.inc" /* config statements should precede project file includes. */
#include <xc.inc>
#include "retardos2.inc"    

     PSECT resetVect,class=CODE, reloc=2
    resetVect:
        goto Main 
    Psect CODE
 
 Main: 
    CALL Config_OSC,1
    CALL Retardos,1
    NOP
   
Config_OSC:
    ;Configuración del oscilador interno a una frecuencia de 4MHz
     BANKSEL OSCCON1          ;Seleccionamos el banco donde está el resgisto
     MOVLW 0x60
     MOVWF  OSCCON1 
     MOVLW 0x02
     MOVWF OSCFRQ
     RETURN 
     
