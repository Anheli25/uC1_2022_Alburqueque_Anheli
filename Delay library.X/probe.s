PROCESSOR 18F57Q84
#include "Bit_Configuration.inc" // config statements should precede project file includes.
#include <xc.inc>
#include "Delay.inc"

    PSECT resetVect,class=CODE,reloc=2
      resetVect:
     GOTO Main
    
   PSECT CODE
Main:
CALL Delay_100ms,1
 NOP
 
END resetVect

