#include "paintRoom.h"
#include <stdbool.h>

/*Brute Force No distance formula*/
/* if moveup=' ' place letter set to true
else set to true and turn if turn = ' ' etc.
*/
void recPaintRoom(RoomData room, int row, int col, char let, int distanceFromA );



 /* Prints name the student who worked on this solution*/
 
void printName()
{
  /* TODO : Fill in your name*/
  printf("\nThis solution was completed by:\n");
  printf("<Ryan Reddoch>\n");
}

/*
 * This non-recursive function is called by the driver and it makes the initial
 * call to recursive function recPaintRoom.
 */
void paintRoom(RoomData room)
{
 

  /* change room.numRows to a more manageable name*/
  int nrows = room.numrows;
  int ncols = room.numcols;
  int i, j;
  int row; /* initial staring row for A*/
  int col; /* initial starting col for A*/
  char let = 'A';
  int distanceFromA;
 
 /*This finds finds 'A' and pasees to recPaintRoom   */
  for (i = 0; i < nrows; i++)
  {
    for (j = 0; j < ncols; j++)
    {

      if (room.roomArray[i][j] == 'A')
      {

        row = i;
        col = j;

        distanceFromA = 0;

          /* My call to my recursive cases*/
      recPaintRoom(room, row, col, let, distanceFromA);
      }
    }
  }
}
  

/*
 * recPaintRoom
 * input: the room to process, the row and column of the current location
 * being explored, the distance traveled from 'A' output: N/A
 */
void recPaintRoom(RoomData room, int row, int col, char let, int distanceFromA )
{

  // Check to see if array is out of bounds or '*'//
   if (row < 0 || row >= room.numrows || col < 0 || col >= room.numcols || room.roomArray[row][col] == '*')
  {
    return;
  }

/* This will place letters including the inital 'A' because DFA is 0 at first */
  else if (distanceFromA < 26 || room.roomArray[row][col] > distanceFromA + 'A')
  {
    room.roomArray[row][col] = distanceFromA + 'A';
  }
  else 
  {
    room.roomArray[row][col] = 'Z';
  }

  /* Recursive cases: */
  /* Moving up*/
  if (room.roomArray[row - 1][col] == ' ' || room.roomArray[row][col] + 1 < room.roomArray[row - 1][col])
  {
    recPaintRoom(room, row - 1, col, let, distanceFromA + 1);
  }

  /* Moving down*/
  if (room.roomArray[row + 1][col] == ' ' || room.roomArray[row][col] + 1 < room.roomArray[row + 1][col])
  {
    recPaintRoom(room, row + 1, col, let, distanceFromA + 1);
  }

  /* Moving to the right*/
  if (room.roomArray[row][col + 1] == ' ' || room.roomArray[row][col] + 1 < room.roomArray[row][col + 1])
  {
    recPaintRoom(room, row, col + 1, let, distanceFromA + 1);
  }

  /* Moving to the left */
  if (room.roomArray[row][col - 1] == ' ' || room.roomArray[row][col] + 1 < room.roomArray[row][col - 1])
  {
    recPaintRoom(room, row, col - 1, let, distanceFromA + 1);
  }

  return;
}
