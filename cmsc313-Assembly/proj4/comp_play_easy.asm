; computer play easy

  extern printf
  extern scanf
  extern rand_num
  extern draw_board
  extern check_winner
  extern main

  section .data
prompt_msg:  db "Enter a location on the board(1-16)", 0 
fmt_msg:     db "%s", 10, 0   
fmt_input: db  "%i", 0
fmt_output:  db  "%i", 10, 0
msg_invalid_input db "Invalid input!", 0         
board: db "________________"

  section .bss
num_buff:   resb 1 ; can changed to resq

  section .text

  global comp_play_easy

comp_play_easy:
  ; display empty board
  xor rdi, rdi
  mov rdi, board
  call draw_board
  
  ; play loop
  ; usr play
  xor ebp, ebp
  mov ebp, 0

  play_loop:
  call play_usr

  ; comp play
  call comp_play

  ; call check winner
  xor rdi, rdi
  xor rsi, rsi
  xor rax, rax
  mov rdi, board
  call check_winner

  cmp ebp, 10
  je reset
  
  inc ebp

  cmp ebp, 8
  jl  play_loop

  ret

play_usr:
  ;call play_usr
  ; prompt user for input
  xor rdi, rdi
  xor rsi, rsi
  mov  rdi, fmt_msg
  mov  rsi, prompt_msg
  mov  rax, 0
  call printf

  ; get user input(location)
  xor rdi, rdi
  xor rsi, rsi
  mov  rdi, fmt_input
  mov  rsi, num_buff
  mov  rax, 0
  push rbp         
  call scanf
  pop rbp

  ; input validation
  xor ebx, ebx
  add ebx, [num_buff]
  dec ebx
  cmp [board + ebx], byte '_'
  je place_move

  invalid_input:
  xor rdi, rdi
  xor rsi, rsi
  mov  rdi, fmt_msg
  mov  rsi, msg_invalid_input
  mov  rax, 0
  call printf
  jmp play_usr

  xor rdi, rdi
  xor rsi, rsi
  xor rax, rax

  place_move:
  ; moves x into user location
  xor rbx, rbx
  xor r14, r14
  mov ebx, [num_buff]
  dec ebx
  mov r14b, 'x'
  mov [board + ebx], byte r14b

  ; print updates board
  xor rdi, rdi
  mov rdi, board
  call draw_board

  ret

comp_play:
   ; input validation
  xor rax, rax
  xor rdi, rdi
  xor rsi, rsi

  call rand_num
  mov [num_buff], byte al

  xor rax, rax
  mov ebx, [num_buff]
  dec ebx
  cmp byte [board + ebx], '_'
  jne comp_play

  xor rdi, rdi
  xor rsi, rsi
  xor rax, rax
  mov rdi, fmt_output
  mov rsi, [num_buff]
  mov  rax, 0
  call printf

  xor rbx, rbx
  xor r14, r14
  mov ebx, [num_buff]
  dec ebx
  mov r14b, 'o'
  mov [board + ebx], byte r14b

  ; print updates board
  xor rdi, rdi
  mov rdi, board
  call draw_board

  ret

reset:
  ;pop rdi
  mov [board], byte '_'
  mov [board + 1], byte '_'
  mov [board + 2], byte '_'
  mov [board + 3], byte '_'
  mov [board + 4], byte '_'
  mov [board + 5], byte '_'
  mov [board + 6], byte '_'
  mov [board + 7], byte '_'
  mov [board + 8], byte '_'
  mov [board + 9], byte '_'
  mov [board + 10], byte '_'
  mov [board + 11], byte '_'
  mov [board + 12], byte '_'
  mov [board + 13], byte '_'
  mov [board + 14], byte '_'
  mov [board + 15], byte '_'

  ret

 exit:
	mov		rax, 60
	xor		rdi, rdi
	syscall 