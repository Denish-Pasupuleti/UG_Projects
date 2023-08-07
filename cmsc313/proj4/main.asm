; main file for running game

; Declaring needed c functions
  extern printf
  extern scanf
  extern rand_num
  extern draw_board
  extern comp_play_easy
  extern check_winner
  extern comp_play_hard

	section .data
welcome:     db "Welcome to TIC-TAC-ASSEMBLY", 0              
options:     db  "Pick an option from the menu below:", 0   
option_a:    db  "a - Easy", 0                              
option_b:    db  "b - Hard", 0                              
option_q:    db  "q - Quit", 0
msg_A        db  "Input A", 0
msg_B        db  "Input B", 0
msg_Q        db  "Quit", 0
msg_invalid_input db "Invalid input!", 0 
fmt:         db  "%s", 10, 0                   
fmt_input:   db  "%s", 0
fmt_output:  db  "%s", 10, 0
fmt_invalid_input db "%s", 10, 0
fmt_randNum   db "%i", 10, 0

;board db "________________"

	section .bss
char_buff:  resb  2
num_buff:   resb 2

	section .text

	global main

main:

get_input:
  xor rdi, rdi
  xor rsi, rsi
  xor rax, rax

  call print_welcome

  xor rdi, rdi
  xor rsi, rsi
  xor rax, rax
  ; get user input
  mov  rdi, fmt_input 
  mov  rsi, char_buff 
  mov  rax, 0
  push rbp         
  call scanf 
  pop rbp

  ; checking user input for exit
  ; if zero flag is true then exit
  ; enter q
  xor rdi, rdi
  xor rsi, rsi
  mov rdi, [char_buff]
  mov rsi, 'q'
  cmp rdi, rsi
  je  invalid_input

  ; enter a
  xor rsi, rsi
  mov rsi, 'a'
  cmp rdi, rsi
  je easyPlay

  ; enter b
  xor rsi, rsi
  mov rsi, 'b'
  cmp rdi, rsi
  je play_hard

  ; enter anything else
  xor rsi, rsi
  mov rsi, 'c'
  cmp rdi, rsi
  jge invalid_input
  jmp get_input

  easyPlay:
  call comp_play_easy
  jmp main

  play_hard:
  call comp_play_hard
  jmp main

  invalid_input:
  mov  rdi, fmt
  mov  rsi, msg_invalid_input
  mov  rax, 0
  call printf
  jmp main

  jmp main

print_welcome:
   ; print welcome and options
  ; clear registers
  xor rdi, rdi
  xor rsi, rsi

 ; print welcome
  mov  rdi, fmt
  mov  rsi, welcome
  mov  rax, 0
  call printf

  ; print option a
  mov  rdi, fmt
  mov  rsi, option_a
  mov  rax, 0
  call printf

  ; print option b
  mov rdi, fmt
  mov rsi, option_b
  mov rax, 0
  call printf

  ; print option q
  mov rdi, fmt
  mov rsi, option_q
  mov rax, 0
  call printf
  ret

exit:
	mov		rax, 60
	xor		rdi, rdi
	syscall
