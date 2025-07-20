.MODEL SMALL
.STACK 1000H
.DATA
	number DB "00000$"
	i DW 1 DUP (0000H)
	j DW 1 DUP (0000H)
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
	MOV AX, 1       ; Line 6
	MOV i, AX
	MOV AX, i       ; Line 7
	CALL print_output
	CALL new_line
	MOV AX, 8       ; Line 9
	MOV DX, AX
	MOV AX, 5       ; Line 9
	ADD AX, DX
	MOV j, AX
	MOV AX, j       ; Line 10
	CALL print_output
	CALL new_line
	MOV AX, i
	MOV AX, j
	MOV AX, j       ; Line 12
	MOV CX, AX
	MOV AX, 2       ; Line 12
	CWD
	MUL CX
	PUSH AX
	POP AX       ; Line 12
	MOV DX, AX
	MOV AX, i       ; Line 12
	ADD AX, DX
	PUSH AX
	POP AX       ; Line 12
	MOV [BP-2], AX
	MOV AX, [BP-2]       ; Line 13
	CALL print_output
	CALL new_line
	MOV AX, [BP-2]
	MOV AX, 9       ; Line 15
	MOV CX, AX
	MOV AX, [BP-2]       ; Line 15
	CWD
	DIV CX
	MOV AX, DX
	PUSH AX
	MOV [BP-6], AX
	MOV AX, [BP-6]       ; Line 16
	CALL print_output
	CALL new_line
	MOV AX, [BP-6]
	MOV AX, [BP-4]
	MOV AX, [BP-6]       ; Line 18
	CMP AX, [BP-4]
	JLE L4
	JMP L6
L4:
	MOV AX, 1       ; Line 18
	JMP L5
L6:
	MOV AX, 0
L5:
	PUSH AX
	POP AX       ; Line 18
	MOV [BP-8], AX
	MOV AX, [BP-8]       ; Line 19
	CALL print_output
	CALL new_line
	MOV AX, i
	MOV AX, j
	MOV AX, i       ; Line 21
	CMP AX, j
	JNE L10
	JMP L12
L10:
	MOV AX, 1       ; Line 21
	JMP L11
L12:
	MOV AX, 0
L11:
	PUSH AX
	POP AX       ; Line 21
	MOV [BP-10], AX
	MOV AX, [BP-10]       ; Line 22
	CALL print_output
	CALL new_line
	MOV AX, [BP-8]
	MOV AX, [BP-10]
	MOV AX, [BP-8]       ; Line 24
	CMP AX, 0
	JNE L13
	JMP L15
L15:
	MOV AX, [BP-10]       ; Line 24
	CMP AX, 0
	JNE L13
	JMP L14
L13:
	MOV AX, 1       ; Line 24
	JMP L16
L14:
	MOV AX, 0
L16:
	MOV [BP-12], AX
	MOV AX, [BP-12]       ; Line 25
	CALL print_output
	CALL new_line
	MOV AX, [BP-8]
	MOV AX, [BP-10]
	MOV AX, [BP-8]       ; Line 27
	CMP AX, 0
	JE L18
	MOV AX, [BP-10]       ; Line 27
	CMP AX, 0
	JE L18
	MOV AX, 1       ; Line 27
	JMP L20
L18:
	MOV AX, 0
L20:
	MOV [BP-12], AX
	MOV AX, [BP-12]       ; Line 28
	CALL print_output
	CALL new_line
	MOV AX, [BP-12]       ; Line 30
	PUSH AX
	INC AX
	MOV [BP-12], AX
	POP AX
	MOV AX, [BP-12]       ; Line 31
	CALL print_output
	CALL new_line
	MOV AX, [BP-12]
	MOV AX, [BP-12]       ; Line 33
	NEG AX
	MOV [BP-2], AX
	MOV AX, [BP-2]       ; Line 34
	CALL print_output
	CALL new_line
	MOV AX, 0
	ADD SP, 12
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
