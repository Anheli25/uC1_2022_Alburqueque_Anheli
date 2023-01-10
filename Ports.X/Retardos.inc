 PSECT udata_acs
    contador1: DS 1       ;reserva un byte en access RAM
    contador2: DS 1
 
PSECT CODE 
Delay250ms:                  ;2Tcy
    MOVLW  250                ;1Tcy ----k2
    MOVWF  contador2,0        ;1Tcy
    
;T = 6 + 4k 
Ext_Loop:                     ;2Tcy ---- Call(llamada)
    MOVLW   249               ;(k1)1Tcy       
    MOVWF   contador1,0       ;1Tcy
Int_Loop: 
    NOP                       ; k1*Tcy
    DECFSZ  contador1,1,0     ;(k1-1)+3Tcy
    GOTO    Int_Loop          ;(k1-1)*2Tcy
    DECFSZ contador2,1,0      ;
    GOTO Ext_Loop
    RETURN                   ;2Tcy


