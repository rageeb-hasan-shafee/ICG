.MODEL SMALL
.STACK 1000H
.DATA
	number DB "00000$"
.CODE
main PROC
	MOV AX, @DATA
	MOV DS, AX
	PUSH BP
	MOV BP, SP
	SUB SP, 2
	SUB SP, 2
	SUB SP, 2
	SUB SP, 2
	SUB SP, 2
	SUB SP, 2
	SUB SP, 2
	MOV AX, 0       ; Line 3
	MOV [BP-4], AX
	MOV AX, 0       ; Line 4
	MOV [BP-6], AX
	MOV AX, 0       ; Line 5
	MOV [BP-10], AX
	JMP L2
L1:
	MOV AX, [BP-10]
	MOV AX, 3       ; Line 6
	MOV [BP-2], AX
L7:
	MOV AX, [BP-2]
	DEC AX
	MOV [BP-2], AX
	ADD AX, 1
	CMP AX, 0
	JE L9
	MOV [BP-14], AX
	JMP L11
L10:
	MOV AX, [BP-14]
	MOV AX, [BP-6]       ; Line 9
	PUSH AX
	INC AX
	MOV [BP-6], AX
	POP AX
	MOV AX, [BP-6]       ; Line 10
	CALL print_output
	CALL new_line
	MOV AX, [BP-14]
	INC AX
	MOV [BP-14], AX
L11:
	MOV AX, [BP-14]
	CMP AX, 5
	JL L10
	JMP L12
L12:
	MOV AX, [BP-4]       ; Line 12
	PUSH AX
	INC AX
	MOV [BP-4], AX
	POP AX
	JMP L7
L9:
	MOV AX, [BP-10]
	INC AX
	MOV [BP-10], AX
L2:
	MOV AX, [BP-10]
	CMP AX, 4
	JL L1
	JMP L3
L3:
	MOV AX, [BP-2]       ; Line 29
	CALL print_output
	CALL new_line
	MOV AX, [BP-4]       ; Line 30
	CALL print_output
	CALL new_line
	MOV AX, [BP-6]       ; Line 31
	CALL print_output
	CALL new_line
	ADD SP, 14
	POP BP
	MOV AX,4CH
	INT 21H
main ENDP
;-------------------------------
;         print library         
;-------------------------------
print_output proc
    push ax
    push bx
    push cx
    push dx
    push si
    lea si, number
    mov bx, 10
    add si, 4
    cmp ax, 0
    jnge negate
    print_loop:
        xor dx, dx
        div bx
        mov [si], dl
        add [si], 48
        dec si
        cmp ax, 0
        jne print_loop
        inc si
        jmp print_output2
    negate:
        neg ax
        print_loop2:
            xor dx, dx
            div bx
            mov [si], dl
            add [si], 48
            dec si
            cmp ax, 0
            jne print_loop2
        mov [si], 45
        jmp print_output2
    print_output2:
        lea dx, si
        mov ah, 9
        int 21h
        pop si
        pop dx
        pop cx
        pop bx
        pop ax
        ret
print_output endp

new_line proc
    push ax
    push dx
    mov ah, 2
    mov dl, 10
    int 21h
    mov dl, 13
    int 21h
    pop dx
    pop ax
    ret
new_line endp
;-------------------------------
END main
