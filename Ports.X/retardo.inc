PSECT udata_acs
contador1: DS 1    ; reserva 1 byte en ACCESS RAM
contador2:  DS 1 

PSECT code
delay_250ms:                ;2TCY.----->CALL...k
    MOVLW 250                ;1TCY
    MOVWF contador2,0        ;1TCY
 ;t=6+4k
 ext_loop:                 ;2TCY.----->CALL...k
    MOVLW  249               ;1TCY
    MOVWF  contador1,0     ;1TCY
 int_loop:
    NOP                    ; k*1TCY
    DECFSZ contador1,1,0   ;(k-1) + 3TCY
    GOTO int_loop        ;(k-1)*2TCY
    DECFSZ contador2,1,0
    GOTO ext_loop
    RETURN                 ;2 TCY


