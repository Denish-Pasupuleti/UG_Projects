; Name: Muni Denish Kumar Pasupuleti
; ID: 	BA87612
; This is an asm file for generating a random 16 character length string
; and asking the user for a index to replace the char at index with
; a random generated char
	
	section .data
num_r:		db	"Enter a location in the string you want to replace(1-16): ", 10
len_r:		equ	$-num_r

msg_original:	db	"Here is the original string"
len_original:	equ	$-msg_original

msg_edited:	db	"Here is the string with the random character updated"
len_edited:	equ	$-msg_edited

new_line:	db	10

	section .bss
num_buff:	resb	3
string:		resb	16

	section .text

	global main

main:
	; asks index to replace
	mov	rax, 1
	mov	rdi, 1
	mov rsi, num_r
	mov rdx, len_r
	syscall

	; stores num_buff
	mov rax, 0
	mov rdi, 0
	mov rsi, num_buff
	mov	rdx, 3
	syscall

	; calls randomNumber 16 times for 16 char string
	; stores that number in string at increasing index
	call 	randomNumber
	mov 	[string], byte al
	
	call 	randomNumber
	mov 	[string + 1], byte al
		
	call 	randomNumber
	mov 	[string + 2], byte al

	call 	randomNumber
	mov 	[string + 3], byte al

	call 	randomNumber
	mov 	[string + 4], byte al

	call 	randomNumber
	mov 	[string + 5], byte al

	call 	randomNumber
	mov 	[string + 6], byte al

	call 	randomNumber
	mov 	[string + 7], byte al

	call 	randomNumber
	mov 	[string + 8], byte al

	call 	randomNumber
	mov 	[string + 9], byte al

	call	randomNumber
	mov 	[string + 10], byte al

	call 	randomNumber
	mov 	[string + 11], byte al

	call 	randomNumber
	mov 	[string + 12], byte al

	call 	randomNumber
	mov 	[string + 13], byte al

	call 	randomNumber
	mov 	[string + 14], byte al

	call 	randomNumber
	mov 	[string + 15], byte al

	; prints out unedited message
	mov 	rax, 1
	mov 	rdi, 1
	mov	rsi, msg_original
	mov 	rdx, len_original
	syscall

	; print new_line
	mov 	rax, 1
	mov 	rdi, 1
	mov 	rsi, new_line
	mov 	rdx, 1
	syscall

	; print unedited string
	mov 	rax, 1
	mov 	rdi, 1
	mov 	rsi, string
	mov 	rdx, 16
	syscall

	; print new_line
	mov 	rax, 1
	mov 	rdi, 1
	mov 	rsi, new_line
	mov 	rdx, 1
	syscall

	; converts user input to int
	call 	convertToInt
	mov 	rbx, rax
	
	; edits char at index
	call 	randomNumber
	mov 	[string + rbx], byte al

	; prints out edited message
	mov 	rax, 1
	mov 	rdi, 1
	mov 	rsi, msg_edited
	mov 	rdx, len_edited
	syscall

	; print new_line
	mov 	rax, 1
	mov 	rdi, 1
	mov 	rsi, new_line
	mov 	rdx, 1
	syscall

	; print edited string
	mov 	rax, 1
	mov 	rdi, 1
	mov 	rsi, string
	mov 	rdx, 16
	syscall

	; print new_line
	mov 	rax, 1
	mov 	rdi, 1
	mov 	rsi, new_line
	mov 	rdx, 1
	syscall

convertToInt:
	; function converts the user input(index) to ints
	; dl -> cl | bl -> al | al -> dl
	mov		dl, [num_buff]
	sub		dl, 48
	mov   al, dl
	mov   bl, 10
	mul   bl
	mov   dl, [num_buff + 1]
	sub   dl, 48
	add   al, dl
	sub		al, 1
	ret

randomNumber:
	; generates a random number using RDRAND in range 97-122
	xor 	eax,eax
	RDRAND 	eax
	xor 	edx, edx
	mov 	ecx, 122 - 97 + 1
	div 	ecx
	mov 	eax, edx
	add 	eax, 97
	ret

exit:
	mov		rax, 60
	xor		rdi, rdi
	syscall
