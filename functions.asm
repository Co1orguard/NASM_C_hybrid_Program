BITS 32

GLOBAL addstr, factstr, palindrome_check, is_palindrome

EXTERN atoi
EXTERN fact
EXTERN C_palindrome
SECTION .bss

buf RESB 1024


SECTION .data 

text DB "Hello World", 0xa
textlen EQU $-text


EnterStringPrompt DB "Enter a string: "
promptlen EQU $-EnterStringPrompt

isPalindrome DB "Is a palindrome", 0xa
lenIsPal EQU $-isPalindrome

notPalindrome DB "Is not a palindrome", 0xa
lenNotPal EQU $-notPalindrome

SECTION .text



addstr:

	push ebp
	mov ebp, esp
	
	push ebx
	push edx

	mov eax, [ebp+8]
	mov ebx, [ebp+12]	
	
	push eax	
	call atoi
	add esp, 4

	push eax

	push ebx
	call atoi
	add esp, 4

	mov edx, eax ;save register edx 
	
	pop eax

	add eax, edx
	pop edx
	pop ebx
	mov esp, ebp
	pop ebp
	ret


factstr:
	push ebp
        mov ebp, esp


        mov eax, [ebp+8]

        push eax
        call atoi
        add esp, 4


        push eax
	call fact
	add esp, 4

        mov esp, ebp
        pop ebp
        ret



palindrome_check:

	;push ebp,
	;mov ebp, esp
	pushad

	mov eax, 4
	mov edx, promptlen
	mov ecx, EnterStringPrompt
	mov ebx, 1
	int 80h

	; clear out buffer
	mov ecx, 1024
	mov edi, buf 
	xor eax, eax
	rep stosb	

	mov eax, 3
	mov edx, 1024
	mov ecx, buf
	mov ebx, 0
	int 80h

	push buf
	call C_palindrome
	
	;remove top 4 bytes from stack pointer
	add esp, 4

	popad
	ret 



;;If you use this code in your functions.asm file make sure to list a comment above where you place it
is_palindrome:
    push    ebp
    mov     ebp, esp
    pusha 
    mov eax, [ebp+8]
    mov ebx, [ebp+12]
    mov ecx, eax
    add ecx, ebx
    sub ecx, 1
loop1:
    cmp eax, ecx
    jge palindrome
    mov dl, [eax]
    mov dh, [ecx]
    cmp dl, dh
    jne not_palindrome
    inc eax
    dec ecx
    jmp loop1

palindrome:
    popa
    pop ebp
    mov eax, 1
    ret

not_palindrome:
    popa
    pop ebp
    mov eax, 0
    ret 


		
	
	
