#include "paintRoom.h"
#include <stdbool.h>

/* if moveup=' ' place letter set to true
else set to true and turn if turn = ' ' etc.
*/


int findDistance(char** roomArr, int ai,int aj,int row, int col);
void recPaintRoom(char **roomArr, int row, int col, int ai, int aj, int distanceFromA /* feel free to remove/add any other parameters here*/);
/* declare any other helper functions here*/
void moveUp(char **roomArr, int row, int col, int distanceFromA, bool);
void moveDown(char **roomArr, int row, int col, int distanceFromA, bool);
void turnRight(char **roomArr, int row, int col, int distanceFromA, bool);
void turnLeft(char **roomArr, int row, int col, int distanceFromA, bool);
void placeLet(char **roomArr, int distanceFromA, int row, int col,bool visited);
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
 
  char ** roomArr=room.roomArray; // change to a more manageable name
  int nrows = room.numrows; 
  int ncols = room.numcols;
  int i, j;
  int row;
  int col;
  int ai, aj;
  int distanceFromA;
  for (i = 0; i < nrows; i++)
  {
    for (j = 0; j < ncols; j++)
    {
      row=i;
      col=j;
    
      if (roomArr[i][j] == 'A')
      {

        ai = i;
        aj = j;
        
      }



   distanceFromA = abs((row-ai) + (col -aj));
 
recPaintRoom(roomArr, row, col, ai, aj, distanceFromA);

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
void recPaintRoom(char **roomArr, int row, int col, int ai, int ji, int distanceFromA /* feel free to remove/add any other parameters here*/)
{
  bool visited;
 printf("95");
visited=false;
while(visited=false)
{
  // iterate through roomArr

  moveUp(roomArr, row, col, distanceFromA, visited);
  turnRight(roomArr, row, col, distanceFromA, visited);
  moveDown(roomArr, row, col, distanceFromA, visited);
  turnLeft(roomArr, row, col, distanceFromA, visited);
}
}
/* My functions */

  
/* ///////////////// MOVE UP //////////////////// */

void moveUp(char **roomArr, int row, int col, int distanceFromA, bool visited)
{
 printf("114");
  /* move forward in the array if space else try other options */
  {
 printf("117");
    if (roomArr[row][col] == ' ')
    {

      placeLet(roomArr, distanceFromA, row, col,visited);
      moveUp(roomArr, row,  col,  distanceFromA,  visited);
    }
    else if (roomArr[row][col] == '*')
    {

   turnLeft(roomArr, row,  col,  distanceFromA,  visited);
   
     }
    
    }
}
//////////////////////////////////////////
/* TURN LEFT BY DECREASING ROW*/

void turnLeft(char **roomArr, int row, int col, int distanceFromA, bool visited)
{

  // move left by deceeasing row  //
  row - 1;
 
    if (roomArr[row][col] == ' ')
    {

      placeLet(roomArr, distanceFromA, row, col ,visited);
      moveUp(roomArr, row,  col,  distanceFromA,  visited);
      
    }
    else if (roomArr[row][col] == '*')
    {
turnRight(roomArr, row,  col,  distanceFromA,  visited);
    
    }
   
}







/* TURN RIGHT INCREASE ROW*/
void turnRight(char **roomArr, int row, int col, int distanceFromA, bool visited)
{
  // move right by increase row //
 printf("141");
  row + 1;

  
    if (roomArr[row][col] == ' ')
    {

      placeLet(roomArr, distanceFromA, row, col,visited);
      moveDown(roomArr, row,  col,  distanceFromA,  visited);
    }
    else if (roomArr[row][col] == '*')
    {

      
    
    moveDown(roomArr, row,  col,  distanceFromA,  visited);
    }
    else
{
      visited = true;
  }
  
}
////////////////////////////////////////

/*MOVE DOWN BY DECREASING COL*/
void moveDown(char **roomArr, int row, int col, int distanceFromA, bool visited)
{
 printf("168");
  // move down  by decreasing column  //
  col - 1;
  
  
    if (roomArr[row][col] == ' ')
    {

      placeLet(roomArr, distanceFromA, row, col,visited);
      
    }
    else if (roomArr[row][col] == '*')
    {

turnLeft(roomArr, row,  col,  distanceFromA,  visited);
    }

}



/* PLACE LETTER*/
void placeLet(char **roomArr, int distanceFromA, int row, int col,bool visited)
{
  /* if space place letter */
  char let = 'A' + distanceFromA;
  if (distanceFromA <= 24)
  {
    roomArr[row][col] = let;
    visited=true;
  }
  else
  {
    roomArr[row][col] = 'Z';
    visited=true;
  }
}
