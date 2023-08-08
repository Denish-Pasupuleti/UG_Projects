FILE  = main
FILE2 =	rand_num
FILE3 = draw_board
FILE4 = comp_play_easy
FILE5 = check_winner
all:
	$(FILE)

two: $(FILE).asm $(FILE2).asm $(FILE4).asm $(FILE5).asm $(FILE3).c
	nasm -f elf64 -l $(FILE).lst $(FILE).asm
	nasm -f elf64 -l $(FILE2).lst $(FILE2).asm
	nasm -f elf64 -l $(FILE4).lst $(FILE4).asm
	nasm -f elf64 -l $(FILE5).lst $(FILE5).asm
	gcc -c  $(FILE3).c -o $(FILE3).o
	gcc -m64 -o $(FILE) $(FILE2).o $(FILE3).o $(FILE4).o $(FILE5).o $(FILE).o -lm

run: $(FILE)
	./$(FILE)

clean:
	rm *.o  *.lst

