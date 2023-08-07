; random number generator subroutine

  section.text

  global rand_num

rand_num:
  ; sets up seed
  xor rax, rax
  RDRAND rax

  ; mul by 1103515245 and add 12345
  mov rbx, rax      
  imul rbx, 1103515245
  add rbx, 12345

  ; dividing by 65536
  mov rax, rbx
  xor rdx, rdx 
  mov rcx, 65536
  div rcx  

  ; have to mod by 17
  xor ecx, ecx
  xor edx, edx
  mov ecx, 17 
  div ecx
  mov eax, edx
  ret



