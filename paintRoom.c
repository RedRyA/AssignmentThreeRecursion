#include "paintRoom.h"
#include <stdbool.h>

/*Brute Force No distance formula*/
/* if moveup=' ' place letter set to true
else set to true and turn if turn = ' ' etc.
*/

int findDistance(char **roomArr, int row, int col, int ai, int aj, int distanceFromA);
void recPaintRoom(char **roomArr, int row, int col, int distanceFromA /* feel free to remove/add any other parameters here*/);
/* declare any other helper functions here*/
void moveUp(char **roomArr, int row, int col, int distanceFromA, bool visited, bool noGo);
void moveDown(char **roomArr, int row, int col, int distanceFromA, bool visited, bool noGo);
void turnRight(char **roomArr, int row, int col, int distanceFromA, bool visited, bool noGo);
void turnLeft(char **roomArr, int row, int col, int distanceFromA, bool visited, bool noGo);
void placeLet(char **roomArr, int row, int col, int distanceFromA, bool visited);
/* printName
 * input: none
 * output: none
 *
 * Prints name the student who worked on this solution
 */
void printName()
{
  /* TODO : Fill in your name*/
  printf("\nThis solution was completed by:\n");
  printf("<Ryan Reddoch>\n");
}

/* TODO
 * paintRoom
 * input: the room to process
 * output: N/A
 *
 * This non-recursive function is called by the driver and it makes the initial
 * call to recursive function recPaintRoom.
 */
void paintRoom(RoomData room)
{
  /* Call any other helper functions (a helper function to find the location of
   * 'A' in room may be handy) */

  char **roomArr = room.roomArray; // change to a more manageable name
  int nrows = room.numrows;
  int ncols = room.numcols;
  int i, j;
  int row; // initial staring row for A
  int col; // initial starting col for A
int distanceFromA;
  for (i = 0; i < nrows; i++)
  {
    for (j = 0; j < ncols; j++)
    {
      if (roomArr[i][j] == 'A')
      {

        row = i;
        col = j;
      int ai=row;
      int  aj=col;
     
     
        recPaintRoom(roomArr, row, col, distanceFromA);
      }
    }
       
  }
}

/* Base cases: All places visited boolean set to true.or unreachable*/

/* Recursive cases: */

/* Call your recursive function here */
// recPaintRoom( room,  initial row value ,  initial col value ,
// initial value for distanceFromA */  );

/* TODO
 * recPaintRoom
 * input: the room to process, the row and column of the current location
 * being explored, the distance traveled from 'A' output: N/A
 */
void recPaintRoom(char **roomArr, int row, int col, int distanceFromA /* feel free to remove/add any other parameters here*/)
{
  bool visited;
  bool noGo;
  noGo = false;
  visited = false;
int aRow=row;
int aCol=col;

distanceFromA=abs((row-aRow)+(col-aCol));
 

  moveUp(roomArr, row, col, distanceFromA, visited, noGo);
  moveDown(roomArr, row, col, distanceFromA, visited, noGo);
  turnRight(roomArr, row, col, distanceFromA, visited, noGo);
  turnLeft(roomArr, row, col, distanceFromA, visited, noGo);
}

/* My functions */

/* ///////////////// MOVE UP //////////////////// */

void moveUp(char **roomArr, int row, int col, int distanceFromA, bool visited, bool noGo)
{
  col += 1;

  /* move forward in the array if space else try other options */

  if (roomArr[row][col] == ' ')
  {
  
     placeLet(roomArr, row, col, distanceFromA, visited);
    turnLeft(roomArr, row, col, distanceFromA, visited, noGo);
    turnRight(roomArr, row, col, distanceFromA, visited, noGo);
    moveDown(roomArr, row, col, distanceFromA, visited, noGo);
  }

  if (roomArr[row][col] == '*')
  {
    col -= 1;
    moveDown(roomArr, row, col, distanceFromA, visited, noGo);
  }
  else
  {

    moveUp(roomArr, row, col, distanceFromA, visited, noGo);
  }
}

////////////////////////////////////////

/*MOVE DOWN BY DECREASING COL*/
void moveDown(char **roomArr, int row, int col, int distanceFromA, bool visited, bool noGo)
{

  // move down  by decreasing column  //
  col -= 1;

  if (roomArr[row][col] == ' ')
  {
    placeLet(roomArr, row, col, distanceFromA, visited);
    turnRight(roomArr, row, col, distanceFromA, visited, noGo);
    turnLeft(roomArr, row, col, distanceFromA, visited, noGo);
    moveDown(roomArr, row, col, distanceFromA, visited, noGo);
  }

  if (roomArr[row][col] == '*')
  {

    col += 1;
    return;
  }

  else
  {

    moveDown(roomArr, row, col, distanceFromA, visited, noGo);
  }
}

//////////////////////////////////////////
/* TURN LEFT BY DECREASING ROW*/

void turnLeft(char **roomArr, int row, int col, int distanceFromA, bool visited, bool noGo)
{

  // move left by deceeasing row  //
  row -= 1;

  if (roomArr[row][col] == ' ')
  {
    placeLet(roomArr, row, col, distanceFromA, visited);
    turnRight(roomArr, row, col, distanceFromA, visited, noGo);
    moveDown(roomArr, row, col, distanceFromA, visited, noGo);
    moveUp(roomArr, row, col, distanceFromA, visited, noGo);
  }

  if (roomArr[row][col] == '*')
  {

    row += 1;
    return;
  }
  else
  {
    turnLeft(roomArr, row, col, distanceFromA, visited, noGo);
  }
}

/* TURN RIGHT INCREASE ROW*/
void turnRight(char **roomArr, int row, int col, int distanceFromA, bool visited, bool noGo)
{
  // move right by increase row //
  row += 1;

  if (roomArr[row][col] == ' ')
  {
    placeLet(roomArr, row, col, distanceFromA, visited);
    turnLeft(roomArr, row, col, distanceFromA, visited, noGo);
    moveDown(roomArr, row, col, distanceFromA, visited, noGo);
    moveUp(roomArr, row, col, distanceFromA, visited, noGo);
  }
  if (roomArr[row][col] == '*')
  {
    row -= 1;
    return;
  }
  else
  {
    turnRight(roomArr, row, col, distanceFromA, visited, noGo);
  }
}

/* PLACE LETTER*/
void placeLet(char **roomArr, int row, int col, int distanceFromA, bool visited)
{
  /* if space place letter */

char let;

   let = 'B'+distanceFromA;
printf("%d",distanceFromA);




    if (let <= 'Z')
    {
      roomArr[row][col] = let;
    }
    else if (let >90)
    {
    
     roomArr[row][col] = 'Z';
      
    }
       
}
//findDistance(char **roomArr, int row, int col, int ai, int aj, int distanceFromA){
//distanceFromA=abs()

//}