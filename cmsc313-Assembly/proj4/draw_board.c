#include <stdio.h>  // printf, scanf

// function to draw board
void draw_board(char board[]) {
  for (int rows = 0; rows < 16; rows += 4) {
    for (int column = 0; column < 4; column++) {
      if (board[column + rows]) {
        printf("|%c", board[column + rows]);
      } else {
        printf("| ");
      }
    }
    printf("|\n");
  }
}
