;computer play hard

  extern scanf
  extern printf
  extern draw_board
  extern rand_num

  section .data
prompt_msg:  db "Enter a location on the board(1-16)", 0 
fmt_msg:     db "%s", 10, 0  
fmt_input: db  "%i", 0
fmt_output:  db  "%s", 10, 0
win_msg:     db  "We have found a winner", 10, 0
lose_msg:     db  "NO WIN", 10, 0
board: db "________________"

  section .bss
num_buff:   resb 2 ; can changed to resq

  section .text

  global comp_play_hard
comp_play_hard:
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

  cmp ebp, 10
  je exit

  ; print updates board
  xor rdi, rdi
  mov rdi, board
  push rdi
  call draw_board
  pop rdi
  
  inc ebp

  cmp ebp, 8
  jl  play_loop

  ret

winner:
  ; print win message
  mov ebp, 10
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
  cmp byte [board + ebx], '_'
  jne play_usr

  xor rdi, rdi
  xor rsi, rsi
  xor rax, rax

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
  push rdi
  call draw_board
  pop rdi

  ret

comp_play:
  call check
  cmp ebp, 10
  je place_o

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

  xor rbx, rbx
  xor r14, r14
  mov ebx, [num_buff]
  dec ebx
  mov r14b, 'o'
  mov [board + ebx], byte r14b

  ; print updates board
  xor rdi, rdi
  mov rdi, board
  push rdi
  call draw_board
  pop rdi

  ret

place_o:
  mov [rdi + r9], byte 'o'
  ret

check:
  ; rdi has board
  row1_loop1: ; checks (0, 1, 2) if usr can win on index 3 
  cmp [rdi], byte '_' ; if pos 0 = '_'
  je  row1_loop2

  cmp [rdi + 1], byte '_' ;if pos 1 = '_'
  je row1_loop2

  cmp [rdi + 2], byte '_' ;if pos 2 = '_'
  je row1_loop2

  ; 0, 1, 2 spots taken so proceed to this and check for usr
  cmp [rdi], byte 'x' ; if pos 0 == x
  jne row1_loop2 

  cmp [rdi + 1], byte 'x' ; if pos 1 == x
  jne row1_loop2  

  cmp [rdi + 2], byte 'x' ; if pos 2 == x
  jne row1_loop2   

  xor r9, r9
  mov r9b, 3
  cmp [rdi + 3], byte '_' ; if pos 3 == '_'
  jne row1_loop2   
  je winner

  row1_loop2: ; checks (0, 1, 3) if urs can win on index 2
  cmp [rdi], byte '_' ; if pos 0 == '_'
  je  row1_loop3

  cmp [rdi + 1], byte '_' ; if pos 1 == '_'
  je row1_loop3

  cmp [rdi + 3], byte '_' ; if pos 3 == '_'
  je row1_loop3

  ; 0, 1, 3 spots taken so proceed to this and check for usr
  cmp byte [rdi], 'x' ; if pos 0 == x
  jne row1_loop3

  cmp byte [rdi + 1], 'x' ; if pos 1 == x
  jne row1_loop3  

  cmp byte [rdi + 3], 'x' ; if pos 3 == 'x'
  jne row1_loop3   

   xor r9, r9
  mov r9b, 2
  cmp byte [rdi + 2], '_' ; if pos 2 == '_'
  jne row1_loop3
  je winner   

 

  row1_loop3:
  cmp [rdi], byte '_' ; if pos 0 == '_'
  je  row1_loop4

  cmp [rdi + 2], byte '_' ; if pos 1 == '_'
  je row1_loop4

  cmp [rdi + 3], byte '_' ; if pos 3 == '_'
  je row1_loop4

  ; 0, 1, 3 spots taken so proceed to this and check for usr
  cmp byte [rdi], 'x' ; if pos 0 == x
  jne row1_loop4 

  cmp byte [rdi + 2], 'x' ; if pos 2 == 'x'
  jne row1_loop4 

  cmp byte [rdi + 3], 'x' ; if pos 3 == 'x'
  jne row1_loop4

   xor r9, r9
  mov r9b, 1
  cmp byte [rdi + 1], '_' ; if pos 1 == '_'
  je winner
  jne row1_loop4


  row1_loop4:
  cmp [rdi + 1], byte '_' ; if pos 1 == '_'
  je  row2_loop1

  cmp [rdi + 2], byte '_' ; if pos 2 == '_'
  je row2_loop1

  cmp [rdi + 3], byte '_' ; if pos 3 == '_'
  je row2_loop1

  ; 1, 2, 3 spots taken so proceed to this and check for usr
  cmp byte [rdi + 1], 'x' ; if pos 1 == 'x'
  jne row2_loop1 

  cmp byte [rdi + 2], 'x' ; if pos 2 == 'x'
  jne row2_loop1

  cmp byte [rdi + 3], 'x' ; if pos 3 == x
  jne row2_loop1

  xor r9, r9
  mov r9b, 0
  cmp byte [rdi], '_' ; if pos 1 == '_'
  je winner
  jne row2_loop1


  ;************ROW 2 LOOP 1***************
  row2_loop1: ; checks (4, 5, 6) if usr can win on index 7
  cmp [rdi + 4], byte '_' ; if pos 4 = '_'
  je  row2_loop2

  cmp [rdi + 5], byte '_' ;if pos 5 = '_'
  je row2_loop2

  cmp [rdi + 6], byte '_' ;if pos 6 = '_'
  je row2_loop2

  cmp byte [rdi + 4], 'x' ; if pos 4 == x
  jne row2_loop2 

  cmp byte [rdi + 5], 'x' ; if pos 5 == x
  jne row2_loop2  

  cmp byte [rdi + 6], 'x' ; if pos 6 == x
  jne row2_loop2   

  xor r9, r9
  mov r9b, 7
  cmp byte [rdi + 7], '_' ; if pos 7 == '_'
  jne row2_loop2   
  je winner

  row2_loop2: ; checks (4, 5, 7) if urs can win on index 6
  cmp [rdi + 4], byte '_' ; if pos 4 == '_'
  je  row2_loop3

  cmp [rdi + 5], byte '_' ; if pos 5 == '_'
  je row2_loop3

  cmp [rdi + 7], byte '_' ; if pos 7 == '_'
  je row2_loop3

  cmp byte [rdi + 4], 'x' ; if pos 4 == x
  jne row2_loop3

  cmp byte [rdi + 5], 'x' ; if pos 5 == x
  jne row2_loop3  

  cmp byte [rdi + 7], 'x' ; if pos 7 == 'x'
  jne row2_loop3   

  xor r9, r9
  mov r9b, 6
  cmp byte [rdi + 6], '_' ; if pos 6 == '_'
  jne row2_loop3
  je winner   

  row2_loop3:
  cmp [rdi + 4], byte '_' ; if pos 4 == '_'
  je  row2_loop4

  cmp [rdi + 6], byte '_' ; if pos 6 == '_'
  je row2_loop4

  cmp [rdi + 7], byte '_' ; if pos 7 == '_'
  je row2_loop4

  cmp byte [rdi + 4], 'x' ; if pos 4 == x
  jne row2_loop4 

  cmp byte [rdi + 6], 'x' ; if pos 6 == 'x'
  jne row2_loop4 

  cmp byte [rdi + 7], 'x' ; if pos 6 == 'x'
  jne row2_loop4

  xor r9, r9
  mov r9b, 5
  cmp byte [rdi + 5], '_' ; if pos 5 == '_'
  je winner
  jne row2_loop4
  
  row2_loop4:
  cmp [rdi + 5], byte '_' ; if pos 5 == '_'
  je  row3_loop1

  cmp [rdi + 6], byte '_' ; if pos 6 == '_'
  je row3_loop1

  cmp [rdi + 7], byte '_' ; if pos 7 == '_'
  je row3_loop1

  ; 1, 2, 3 spots taken so proceed to this and check for usr
  cmp byte [rdi + 5], 'x' ; if pos 5 == 'x'
  jne row3_loop1 

  cmp byte [rdi + 6], 'x' ; if pos 6 == 'x'
  jne row3_loop1

  cmp byte [rdi + 7], 'x' ; if pos 7 == x
  jne row3_loop1

  xor r9, r9
  mov r9b, 4
  cmp byte [rdi + 4], '_' ; if pos 4 == '_'
  je winner
  jne row3_loop1

  row3_loop1: ; checks (8, 9, 10) if usr can win on index 11
  cmp [rdi + 8], byte '_' ; if pos 8 = '_'
  je  row3_loop2

  cmp [rdi + 9], byte '_' ;if pos 9 = '_'
  je row3_loop2

  cmp [rdi + 10], byte '_' ;if pos 10 = '_'
  je row3_loop2

  cmp byte [rdi + 8], 'x' ; if pos 8 == x
  jne row3_loop2 

  cmp byte [rdi + 9], 'x' ; if pos 8 == x
  jne row3_loop2  

  cmp byte [rdi + 10], 'x' ; if pos 10 == x
  jne row3_loop2   

  xor r9, r9
  mov r9b, 11
  cmp byte [rdi + 11], '_' ; if pos 11 == '_'
  jne row3_loop2   
  je winner

  row3_loop2: ; checks (8, 9, 11) if urs can win on index 10
  cmp [rdi + 8], byte '_' ; if pos 8 == '_'
  je  row3_loop3

  cmp [rdi + 9], byte '_' ; if pos 9 == '_'
  je row3_loop3

  cmp [rdi + 11], byte '_' ; if pos 11 == '_'
  je row3_loop3

  cmp byte [rdi + 8], 'x' ; if pos 8 == x
  jne row3_loop3

  cmp byte [rdi + 9], 'x' ; if pos 9 == x
  jne row3_loop3  

  cmp byte [rdi + 11], 'x' ; if pos 11 == 'x'
  jne row3_loop3   

  xor r9, r9
  mov r9b, 10
  cmp byte [rdi + 10], '_' ; if pos 10 == '_'
  jne row3_loop3
  je winner   

  row3_loop3: ; checks (8, 10, 11) if urs can win on index 9
  cmp [rdi + 8], byte '_' ; if pos 8 == '_'
  je  row3_loop4

  cmp [rdi + 10], byte '_' ; if pos 10 == '_'
  je row3_loop4

  cmp [rdi + 11], byte '_' ; if pos 11 == '_'
  je row3_loop4

  cmp byte [rdi + 8], 'x' ; if pos 8 == x
  jne row3_loop4 

  cmp byte [rdi + 10], 'x' ; if pos 10 == 'x'
  jne row3_loop4 

  cmp byte [rdi + 11], 'x' ; if pos 11 == 'x'
  jne row3_loop4

  xor r9, r9
  mov r9b, 9
  cmp byte [rdi + 9], '_' ; if pos 9 == '_'
  je winner
  jne row3_loop4
  
  row3_loop4: ; checks (9, 10, 11) if urs can win on index 8
  cmp [rdi + 9], byte '_' ; if pos 9 == '_'
  je  row4_loop1

  cmp [rdi + 10], byte '_' ; if pos 10 == '_'
  je row4_loop1

  cmp [rdi + 11], byte '_' ; if pos 11 == '_'
  je row4_loop1

  cmp byte [rdi + 9], 'x' ; if pos 9 == 'x'
  jne row4_loop1 

  cmp byte [rdi + 10], 'x' ; if pos 10 == 'x'
  jne row4_loop1

  cmp byte [rdi + 11], 'x' ; if pos 11 == x
  jne row4_loop1

  xor r9, r9
  mov r9b, 8
  cmp byte [rdi + 8], '_' ; if pos 8 == '_'
  je winner
  jne row4_loop1

  row4_loop1: ; checks (8, 9, 10) if usr can win on index 11
  cmp [rdi + 12], byte '_' ; if pos 12 = '_'
  je  row4_loop2

  cmp [rdi + 13], byte '_' ;if pos 13 = '_'
  je row4_loop2

  cmp [rdi + 14], byte '_' ;if pos 14 = '_'
  je row4_loop2

  cmp byte [rdi + 12], 'x' ; if pos 12 == x
  jne row4_loop2 

  cmp byte [rdi + 13], 'x' ; if pos 13 == x
  jne row4_loop2  

  cmp byte [rdi + 14], 'x' ; if pos 14 == x
  jne row4_loop2   

  xor r9, r9
  mov r9b, 15
  cmp byte [rdi + 15], '_' ; if pos 15 == '_'
  jne row4_loop2   
  je winner

  row4_loop2: ; checks (8, 9, 11) if urs can win on index 10
  cmp [rdi + 12], byte '_' ; if pos 12 = '_'
  je  row4_loop3

  cmp [rdi + 13], byte '_' ;if pos 13 = '_'
  je row4_loop3

  cmp [rdi + 15], byte '_' ;if pos 15 = '_'
  je row4_loop3

  cmp byte [rdi + 12], 'x' ; if pos 12 == x
  jne row4_loop3 

  cmp byte [rdi + 13], 'x' ; if pos 13 == x
  jne row4_loop3  

  cmp byte [rdi + 15], 'x' ; if pos 15 == x
  jne row4_loop3   
  
  xor r9, r9
  mov r9b, 14
  cmp byte [rdi + 14], '_' ; if pos 14 == '_'
  jne row4_loop3   
  je winner

  row4_loop3: ; checks (8, 10, 11) if urs can win on index 9
  cmp [rdi + 12], byte '_' ; if pos 12 = '_'
  je  row4_loop4

  cmp [rdi + 14], byte '_' ;if pos 14 = '_'
  je row4_loop4

  cmp [rdi + 15], byte '_' ;if pos 15 = '_'
  je row4_loop4

  cmp byte [rdi + 12], 'x' ; if pos 12 == x
  jne row4_loop4 

  cmp byte [rdi + 14], 'x' ; if pos 14 == x
  jne row4_loop4  

  cmp byte [rdi + 15], 'x' ; if pos 15 == x
  jne row4_loop4   

  xor r9, r9
  mov r9b, 13
  cmp byte [rdi + 13], '_' ; if pos 13 == '_'
  jne row4_loop4  
  je winner

  row4_loop4: ; checks (8, 10, 11) if urs can win on index 9
  cmp [rdi + 13], byte '_' ; if pos 13 = '_'
  je  col1_loop1

  cmp [rdi + 14], byte '_' ;if pos 14 = '_'
  je col1_loop1

  cmp [rdi + 15], byte '_' ;if pos 15 = '_'
  je col1_loop1

  cmp byte [rdi + 13], 'x' ; if pos 13 == x
  jne col1_loop1

  cmp byte [rdi + 14], 'x' ; if pos 14 == x
  jne col1_loop1

  cmp byte [rdi + 15], 'x' ; if pos 15 == x
  jne col1_loop1  

  xor r9, r9
  mov r9b, 12
  cmp byte [rdi + 12], '_' ; if pos 12 == '_'
  jne col1_loop1
  je winner


  col1_loop1:
  jmp no_win
  ret
  
no_win:
  xor rdi, rdi
  xor rsi, rsi
  mov  rdi, fmt_output
  mov  rsi, lose_msg
  mov  rax, 0
  call printf
  ret

exit:
	mov		rax, 60
	xor		rdi, rdi
	syscall 