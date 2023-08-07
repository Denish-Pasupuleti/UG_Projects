; checks winner

  extern draw_board
  extern printf
  extern main

  section .data
fmt_output:  db  "%s", 10, 0
msg:         db  "fourth row check successful", 10, 0
msg_usr_win: db  "YOU WIN! ", 10, 0
msg_cpu_win: db  "COMPUTER WINS(trash) ", 10, 0
lose_msg:    db  "NO WIN", 10, 0
  section .bss

  section .text

  global check_winner

check_winner:
  ; rdi will have the board
  ;call draw_board

  call check_row_1
  ret

winner:
  ; print win message
  cmp r9b, 'x'
  je usr_win

  cpu_win:
  xor rdi, rdi
  xor rsi, rsi
  mov  rdi, fmt_output
  mov  rsi, msg_cpu_win
  mov  rax, 0
  call printf

  usr_win:
  xor rdi, rdi
  xor rsi, rsi
  mov  rdi, fmt_output
  mov  rsi, msg_usr_win
  mov  rax, 0
  call printf

  mov ebp, 10
  ret

check_row_1:
  ; rdi has board
  cmp [rdi + 1], byte '_'
  je  check_row_2

  xor r9b, r9b
  mov r9b, [rdi + 1]  ; pos 2
  cmp byte [rdi], r9b ; if pos 1 == pos 2
  jne check_row_2 ; jump to check row 2 if not equal

  xor r9b, r9b
  mov r9b, [rdi + 2]  ; pos 3
  cmp byte [rdi + 1], r9b ; if pos 2 == pos 3
  jne check_row_2  ; jump to check row 2 if not equal

  xor r9b, r9b
  mov r9b, [rdi + 3]  ; pos 3
  cmp byte [rdi + 2], r9b ; if pos 2 == pos 3
  jne check_row_2   ; jump to check row 2 if not equal
  je winner

check_row_2:
  ; row 2, columns 1-4
  cmp [rdi + 4], byte '_'
  je  check_row_3
  
  xor r9, r9
  mov r9b, [rdi + 5]  ; pos 5
  cmp byte [rdi + 4], r9b ; if pos 4 == pos 5
  jne check_row_3 ; jump to check row 2 if not equal

  xor r9b, r9b
  mov r9b, [rdi + 6]  ; pos 6
  cmp byte [rdi + 5], r9b ; if pos 5 == pos 6
  jne check_row_3  ; jump to check row 2 if not equal

  xor r9b, r9b
  mov r9b, [rdi + 7]  ; pos 7
  cmp byte [rdi + 6], r9b ; if pos 6 == pos 7
  jne check_row_3   ; jump to check row 2 if not 
  je winner

check_row_3:
  cmp [rdi + 8], byte '_'
  je  check_row_4

  ; row 3, columns 1-4
  xor r9, r9
  mov r9b, [rdi + 9]  ; pos 9
  cmp byte [rdi + 8], r9b ; if pos 8 == pos 9
  jne check_row_4 ; jump to check row 2 if not equal

  xor r9b, r9b
  mov r9b, [rdi + 10]  ; pos 10
  cmp byte [rdi + 9], r9b ; if pos 9 == pos 10
  jne check_row_4  ; jump to check row 2 if not equal

  xor r9b, r9b
  mov r9b, [rdi + 11]  ; pos 11
  cmp byte [rdi + 10], r9b ; if pos 10 == pos 11
  jne check_row_4   ; jump to check row 2 if not equal
  je winner

check_row_4:
  ; row 4, columns 1-
  cmp [rdi + 12], byte '_'
  je  check_column1

  xor r9, r9
  mov r9b, [rdi + 13]  ; pos 13
  cmp byte [rdi + 12], r9b ; if pos 12 == pos 13
  jne check_column1 ; jump to check row 2 if not equal

  xor r9b, r9b
  mov r9b, [rdi + 14]  ; pos 14
  cmp byte [rdi + 13], r9b ; if pos 13 == pos 14
  jne check_column1  ; jump to check row 2 if not equal

  xor r9b, r9b
  mov r9b, [rdi + 15]  ; pos 15
  cmp byte [rdi + 14], r9b ; if pos 14 == pos 15
  jne check_column1   ; jump to check row 2 if not equal
  je winner
 
check_column1:
  cmp [rdi + 4], byte '_'
  je  check_column2

  xor r9, r9
  mov r9b, [rdi + 4]  ; pos 2
  cmp byte [rdi], r9b ; if pos 1 == pos 2
  jne check_column2 ; jump to check row 2 if not equal

  xor r9b, r9b
  mov r9b, [rdi + 8]  ; pos 3
  cmp byte [rdi + 4], r9b ; if pos 2 == pos 3
  jne check_column2  ; jump to check row 2 if not equal

  xor r9b, r9b
  mov r9b, [rdi + 12]  ; pos 3
  cmp byte [rdi + 8], r9b ; if pos 2 == pos 3
  jne check_column2   ; jump to check row 2 if not equal
  je winner
  
check_column2:
  cmp [rdi + 5], byte '_'
  je  check_column3

  xor r9, r9
  mov r9b, [rdi + 5]  ; pos 2
  cmp byte [rdi + 1], r9b ; if pos 1 == pos 2
  jne check_column3 ; jump to check row 2 if not equal

  xor r9b, r9b
  mov r9b, [rdi + 9]  ; pos 3
  cmp byte [rdi + 5], r9b ; if pos 2 == pos 3
  jne check_column3  ; jump to check row 2 if not equal

  xor r9b, r9b
  mov r9b, [rdi + 13]  ; pos 3
  cmp byte [rdi + 9], r9b ; if pos 2 == pos 3
  jne check_column3   ; jump to check row 2 if not equal
  je winner
  
check_column3:
  cmp [rdi + 6], byte '_'
  je  check_column4

  xor r9, r9
  mov r9b, [rdi + 6]  ; pos 2
  cmp byte [rdi + 2], r9b ; if pos 1 == pos 2
  jne check_column4 ; jump to check row 2 if not equal

  xor r9b, r9b
  mov r9b, [rdi + 10]  ; pos 3
  cmp byte [rdi + 6], r9b ; if pos 2 == pos 3
  jne check_column4  ; jump to check row 2 if not equal

  xor r9b, r9b
  mov r9b, [rdi + 14]  ; pos 3
  cmp byte [rdi + 10], r9b ; if pos 2 == pos 3
  jne check_column4   ; jump to check row 2 if not equal
  je winner
  
check_column4:
  cmp [rdi + 7], byte '_'
  je  check_diag1

  xor r9, r9
  mov r9b, [rdi + 7]  ; pos 2
  cmp byte [rdi + 3], r9b ; if pos 1 == pos 2
  jne check_diag1 ; jump to check row 2 if not equal

  xor r9b, r9b
  mov r9b, [rdi + 11]  ; pos 3
  cmp byte [rdi + 7], r9b ; if pos 2 == pos 3
  jne check_diag1  ; jump to check row 2 if not equal

  xor r9b, r9b
  mov r9b, [rdi + 15]  ; pos 3
  cmp byte [rdi + 11], r9b ; if pos 2 == pos 3
  jne check_diag1   ; jump to check row 2 if not equal
  je winner
  
check_diag1:
  cmp [rdi + 5], byte '_'
  je  check_diag2

  xor r9, r9
  mov r9b, [rdi + 5]  ; pos 2
  cmp byte [rdi], r9b ; if pos 1 == pos 2
  jne check_diag2 ; jump to check row 2 if not equal

  xor r9b, r9b
  mov r9b, [rdi + 10]  ; pos 3
  cmp byte [rdi + 5], r9b ; if pos 2 == pos 3
  jne check_diag2  ; jump to check row 2 if not equal

  xor r9b, r9b
  mov r9b, [rdi + 15]  ; pos 3
  cmp byte [rdi + 10], r9b ; if pos 2 == pos 3
  jne check_diag2   ; jump to check row 2 if not equal
  je winner
  
check_diag2:
  cmp [rdi + 6], byte '_'
  je  no_win

  xor r9, r9
  mov r9b, [rdi + 6]  ; pos 2
  cmp byte [rdi + 3], r9b ; if pos 1 == pos 2
  jne no_win; jump to check row 2 if not equal

  xor r9b, r9b
  mov r9b, [rdi + 9]  ; pos 3
  cmp byte [rdi + 6], r9b ; if pos 2 == pos 3
  jne no_win  ; jump to check row 2 if not equal

  xor r9b, r9b
  mov r9b, [rdi + 12]  ; pos 3
  cmp byte [rdi + 9], r9b ; if pos 2 == pos 3
  jne no_win  ; jump to check row 2 if not equal
  je winner
  
no_win:
  ret

exit:
	mov		rax, 60
	xor		rdi, rdi
	syscall 
