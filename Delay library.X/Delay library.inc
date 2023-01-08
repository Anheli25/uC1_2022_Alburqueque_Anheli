;--------------------------------------------------------------------------------
    ;@file     Delay library
    ;@brief    This library has different delays in both microseconds and milliseconds. 
    ;          The first of these delays is used as the base delay for the following ones. 
    ;          It also contains nested cycles in order not to make the worked code extensive.
    ;@Date     07/01/23
    ;@Author   Anheli Paola Alburqueque Sernaque 
    ;@Assembler version   MPLAB X IDE v6.00
    ;@Driver version      pic-as v2.40
;--------------------------------------------------------------------------------
   ;Frequency [OSC] = 4MHz
;--------------------------------------------------------------------------------    

PSECT udata_acs
Counter1: DS 1      ;reserva un comentario en access ram
Counter2: DS 1      ;reserva un comentario en access ram
  
PSECT code
; Delay 1[10us]
     ;Tt =(6+4k0)*Tcy
Delay_10us:                  ;  CALL  --> 2 Tcy (Llamada)
    MOVLW  1                 ;  MOVLW --> 1 Tcy ---- W=k0
    MOVWF  Counter1,0        ;  MOVWF --> 1 Tcy
Loop_1:   
    NOP                      ;  k0*Tcy
    DECFSZ Counter1,1,0      ;  (k0-1) + 3*Tcy
    GOTO   Loop_1            ;  (k0-1)*2Tcy
    RETURN                   ;  2*Tcy
    
; Delay 2 [25us]
      ;Tt =(6+4k0)*Tcy 
Delay_25us:                  ;  CALL  --> 2 Tcy (Llamada) 
    MOVLW  5                 ;  MOVLW --> 1 Tcy ---- W=k0
    MOVWF  Counter1,0        ;  MOVWF --> 1 Tcy
Loop_2:   
    NOP                      ;  k0*Tcy
    DECFSZ Counter1,1,0      ; (k0-1) + 3*Tcy
    GOTO   Loop_2            ; (k0-1)*2Tcy
    RETURN                   ;  2*Tcy

; Delay 3 [50us]
       ;Tt =(6+4k0)*Tcy   
Delay_50us:                  ;  CALL  --> 2 Tcy (Llamada)
    MOVLW  11                ;  MOVLW --> 1 Tcy ---- W=k0
    MOVWF  Counter1,0        ;  MOVWF --> 1 Tcy
Loop_3:
    NOP                      ;  k0*Tcy
    DECFSZ Counter1,1,0      ;  (k0-1) + 3*Tcy
    GOTO   Loop_3            ;  (k0-1)*2Tcy
    RETURN                   ;  2*Tcy
                                  
                                  
; Delay 4 [100us]           
      ;Tt =(6+4k0)*Tcy  
Delay_100us:                 ;  CALL  --> 2 Tcy (Llamada)
    MOVLW  24                ;  MOVLW --> 1 Tcy ---- W=k0
    MOVWF  Counter1,0        ;  MOVWF --> 1 Tcy
Loop_4:
    NOP                      ;  k0*Tcy
    DECFSZ Counter1,1,0      ;  (k0-1) + 3*Tcy
    GOTO   Loop_4            ;  (k0-1)*2Tcy
    RETURN                   ;  2*Tcy

      
; Delay 5 [200us]
      ;Tt =(6+4k0)*Tcy  
Delay_200us:                 ;  CALL  --> 2 Tcy (Llamada)
    MOVLW  49                ;  MOVLW --> 1 Tcy ---- W=k0
    MOVWF  Counter1,0        ;  MOVWF --> 1 Tcy
Loop_5:
    NOP                      ;  k0*Tcy
    DECFSZ Counter1,1,0      ;  (k0-1) + 3*Tcy
    GOTO   Loop_5            ;  (k0-1)*2Tcy
    RETURN                   ;  2*Tcy

; Delay 6 [250us]
      ;Tt =(6+4k0)*Tcy  
Delay_250us:                 ;  CALL  --> 2 Tcy (Llamada)
    MOVLW  61                ;  MOVLW --> 1 Tcy ---- W=k0
    MOVWF  Counter1,0        ;  MOVWF --> 1 Tcy
Loop_6:
    NOP                      ;  k0*Tcy
    DECFSZ Counter1,1,0      ;  (k0-1) + 3*Tcy
    GOTO   Loop_6            ;  (k0-1)*2Tcy
    RETURN                   ;  2*Tcy

    
; Delay 7 [500us]
      ;Tt =(6+4k0)*Tcy 
Delay_500us:                 ;   CALL  --> 2 Tcy (Llamada)
    MOVLW  124               ;   MOVLW --> 1 Tcy ---- W=k0
    MOVWF  Counter1,0        ;   MOVWF --> 1 Tcy
Loop_7:
    NOP                      ;   k1*k0*Tcy
    DECFSZ Counter1,1,0      ;   (k0-1) + 3*Tcy
    GOTO   Loop_7            ;   (k0-1)*2Tcy
    RETURN                   ;   2*Tcy
    
    
; Delay 8[1ms]
      ;Tt= (k1*(6+4(k)us))+k1*(1us)+ 6*(1us)= (k1*(6+4(249)us))+ k1*(1us)+ 6us     
Delay_1ms:                    ;  CALL  --> 2 Tcy (Llamada)
    MOVLW  1                  ;  MOVLW --> 1 Tcy ---- W=k1
    MOVWF  Counter2,0         ;  MOVWF --> 1 Tcy
      ; Tp = (6+4k0)ua= (6+4*(249))= 1ms 
Loop_Ext1:  
    MOVLW  249                ;  k1*Tcy ----- k0 = 249
    MOVWF  Counter1,0         ;  k1*Tcy
Loop_Int1:
    NOP                       ;  k1*k0*Tcy
    DECFSZ Counter1,1,0       ;  k1*((k0-1) + 3*Tcy)
    GOTO   Loop_Int1         ;  k1((k0-1)*2Tcy)
    DECFSZ Counter2,1,0       ;  (k1-1) + 3*Tcy
    GOTO   Loop_Ext1         ;  (k1-1)*2Tcy
    RETURN                    ;  2*Tcy

; Delay 9 [5ms]
       ;Tt = [k1*(6+4(k0)us)]+k1*(1us)+ 6*(1us)= [k1*(6+4(249)us)]+ k1*(1us)+ 6us       
Delay_5ms:                    ;  CALL  --> 2 Tcy (Llamada)
    MOVLW  5                  ;  MOVLW --> 1 Tcy ---- W=k1
    MOVWF  Counter2,0         ;  MOVWF --> 1 Tcy
      ; Tp = (6+4k1)ua= (6+4*(249))= 1ms 
Loop_Ext2:  
    MOVLW  249                ;  k1*Tcy ---- k0 = 249
    MOVWF  Counter1,0         ;  k1*Tcy
Loop_Int2:
    NOP                       ;  k1*k0*Tcy
    DECFSZ Counter1,1,0       ;  k1*[(k0-1) + 3*Tcy]
    GOTO   Loop_Int2         ;  k1[(k0-1)*2*Tcy]
    DECFSZ Counter2,1,0       ;  (k1-1) + 3*Tcy
    GOTO   Loop_Ext2         ;  (k1-1)*2*Tcy
    RETURN                    ;  2*Tcy
    
    
; Delay 10 [10ms]
      ;Tt= (k1*(6+4(k0)us))+k1*(1us)+ 6*(1us)= (k1*(6+4(249)us))+k1*(1us)+ 6us
Delay_10ms:                   ;  CALL  --> 2 Tcy (Llamada)
    MOVLW  10                 ;  MOVLW --> 1 Tcy ---- W=k1
    MOVWF  Counter2,0         ;  MOVWF --> 1 Tcy
      ; Tp = (6+4k0)ua= (6+4*(249))= 1ms 
Loop_Ext3:  
    MOVLW  249                ;  k1*Tcy ---- k0 = 249
    MOVWF  Counter1,0         ;  k1*Tcy
Loop_Int3:
    NOP                       ;  k1*k0*Tcy
    DECFSZ Counter1,1,0       ;  k1*[(k0-1) + 3*Tcy]
    GOTO   Loop_Int3         ;  k1[(k0-1)*2*Tcy]
    DECFSZ Counter2,1,0       ;  (k1-1) + 3*Tcy
    GOTO   Loop_Ext3         ;  (k1-1)*2*Tcy
    RETURN                    ;  2*Tcy
    
   
; Delay 11 [25ms]
      ;Tt= (k1*(6+4(k0)us))+k1*(1us)+ 6*(1us)= (k1*(6+4(249)us))+k1*(1us)+ 6us     
Delay_25ms:                   ;  CALL  --> 2 Tcy (Llamada)
    MOVLW  25                 ;  MOVLW --> 1 Tcy ---- W=k1
    MOVWF  Counter2,0         ;  MOVWF --> 1 Tcy
      ; Tp = (6+4k0)ua= (6+4*(249))= 1ms 
Loop_Ext4:  
    MOVLW  249                ;  k1*Tcy ---- k0=249
    MOVWF  Counter1,0         ;  k1*Tcy
Loop_Int4:
    NOP                       ;  k1*k0*Tcy
    DECFSZ Counter1,1,0       ;  k1*[(k0-1) + 3*Tcy]
    GOTO   Loop_Int4         ;  k1[(k0-1)*2*Tcy]
    DECFSZ Counter2,1,0       ;  (k1-1) + 3*Tcy
    GOTO   Loop_Ext4         ;  (k1-1)*2*Tcy
    RETURN                    ;  2*TCY
    
    
; Delay 12 [50ms]
      ;Tt = (k1*(6+4(k0)us))+k1*(1us)+ 6*(1us)= (k1*(6+4(249)us))+k1*(1us)+ 6us   
Delay_50ms:                   ;  CALL  --> 2 Tcy (Llamada)
    MOVLW  50                 ;  MOVLW --> 1 Tcy ---- W=k1
    MOVWF  Counter2,0         ;  MOVWF --> 1 Tcy
      ; Tp = (6+4k0)ua= (6+4*(249))= 1ms 
Loop_Ext5:  
    MOVLW  249                ;  k1*Tcy ---- k0 = 249
    MOVWF  Counter1,0         ;  k1*Tcy
Loop_Int5:
    Nop                       ;  k1*k0*Tcy
    DECFSZ Counter1,1,0       ;  k1*((k0-1) + 3*Tcy)
    GOTO   Loop_Int5         ;  k1((k0-1)*2Tcy)
    DECFSZ Counter2,1,0       ;  (k1-1) + 3*Tcy
    GOTO   Loop_Ext5         ;  (k1-1)*2*Tcy
    RETURN                    ;  2*Tcy  
                                                                 
; Delay 13 [100ms]            
      ;Tt = (k1*(6+4(k0)us))+k1*(1us)+ 6*(1us)= (k1*(6+4(249)us))+ k1*(1us)+ 6us 
Delay_100ms:                  ;  CALL  --> 2 Tcy (Llamada)
    MOVLW  100                ;  MOVLW --> 1 Tcy ---- W=k1
    MOVWF  Counter2,0         ;  MOVWF --> 1 Tcy
      ; Tp = (6+4k1)ua= (6+4*(249))= 1ms 
Loop_Ext6:                          
    MOVLW  249                ;  k1*Tcy ---- k0 = 249
    MOVWF  Counter1,0         ;  k1*Tcy
Loop_Int6:                             
    Nop                       ;  k1*k0*Tcy
    DECFSZ Counter1,1,0       ;  k1*((k0-1) + 3*Tcy)
    GOTO   Loop_Int6         ;  k1((k0-1)*2Tcy)
    DECFSZ Counter2,1,0       ;  (k1-1) + 3*Tcy
    GOTO   Loop_Ext6         ;  (k1-1)*2Tcy
    RETURN                    ;  2*Tcy
   
; Delay 14 [200ms]
      ;Tt = (k1*(6+4(k0)us))+k1*(1us)+ 6*(1us)= (k1*(6+4(249)us))+ k1*(1us)+ 6us 
Delay_200ms:                  ;  CALL  --> 2 Tcy (Llamada)
    MOVLW  200                ;  MOVLW --> 1 Tcy ---- W=k1
    MOVWF  Counter2,0         ;  MOVWF --> 1 Tcy
      ; Tp = (6+4k0)ua= (6+4*(249))= 1ms 
Loop_Ext7:  
    MOVLW  249                ;  k1*Tcy ---- k0 = 249
    MOVWF  Counter1,0         ;  k1*Tcy
Loop_Int7:
    Nop                       ;  k1*k0*Tcy
    DECFSZ Counter1,1,0       ;  k1*((k0-1) + 3*Tcy)
    GOTO   Loop_Int7         ;  k1[(k0-1)*2Tcy]
    DECFSZ Counter2,1,0       ;  (k1-1) + 3*Tcy
    GOTO   Loop_Ext7         ;  (k1-1)*2Tcy
    RETURN                    ;  2*Tcy
    
    
; Delay 15 [250ms]
      ;Tt = (k1*(6+4(k0)us))+k1*(1us)+ 6*(1us)= (k1*(6+4(249)us))+ k1*(1us)+ 6us
Delay_250ms:                  ;  CALL  --> 2 Tcy (Llamada)
    MOVLW  250                ;  MOVLW --> 1 Tcy ---- W=k1
    MOVWF  Counter2,0         ;  MOVWF --> 1 Tcy
      ; Tp = (6+4k0)ua= (6+4*(249))= 1ms 
Loop_Ext8:  
    MOVLW  249                ;  k1*Tcy ---- k0 = 249
    MOVWF  Counter1,0         ;  k1*Tcy
Loop_Int8:
    NOP                       ;  k1*k0*Tcy
    DECFSZ Counter1,1,0       ;  k1*((k0-1) + 3*Tcy)
    GOTO   Loop_Int8         ;  k1[(k0-1)*2Tcy]
    DECFSZ Counter2,1,0       ;  (k1-1) + 3*Tcy
    GOTO   Loop_Ext8         ;  (k1-1)*2Tcy
    RETURN                    ;  2*Tcy	


