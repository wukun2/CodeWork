CODE  SEGMENT
      ;ASSUME CS:CODE,DS:DATA
start:	
	mov ah,01H
	int 21H;等待键入，键入后把字符的ASCII码送AL
		
	mov dl,al;待显示字符的ASCII码要放到DL里
	mov ah,02H
	int 21H;
    ;HLT
	mov ah,4CH	
	int 21H	
	
CODE ENDS
END start