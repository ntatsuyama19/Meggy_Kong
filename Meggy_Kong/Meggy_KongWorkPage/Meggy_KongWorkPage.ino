#include <MeggyJrSimple.h>    // Required code, line 1 of 2.

struct Point
{
 int x;
 int y;
 int direction;
}; 

int direction = 0;
Point barrel1 = {1,7};// barrel 1 x & y position
int level1 = 1;
int level2 = 4;
int level3 = 7;

void setup() 
{
  MeggyJrSimpleSetup();     // put your main code here, to run repeatedly// put your setup code here, to run once:
  barrel1.direction = 270;                          //move in driection 270
}

void loop() 
{
  drawEnemies();
  DisplaySlate();
  ClearSlate();
  
  barrel1Movement();

}

void drawEnemies()
{
  DrawPx(barrel1.x,barrel1.y,Blue);  
}

void barrel1Movement()
{
  if (barrel1.direction == 270)                        //if going in certain direction
  {
    barrel1.x = barrel1.x - 1;                 //move to the left
  }
  if (barrel1.direction == 90)
  {
    barrel1.x = barrel1.x + 1;                 //move to the right
  }        
  // barrel1.direction = 270;                 //original direction 270
  delay(300);                                // wait 225 mil. sec.
  if ((barrel1.x < 0) && (barrel1.y == 7)) //if at this point shift to next line
  {
    barrel1.x = 0;                            //spawn barrel x position
    barrel1.y = level2;                          //spawn barrel y position
    barrel1.direction = 90;                           //move in direction 90
    delay(300);                               // wait 225 mil. sec.
  }
  if ((barrel1.x > 7) && (barrel1.y == 4))  //if at this point shift to next line
  {
    barrel1.direction = 90;
    barrel1.x = 7;                            //spawn barrel x position
    barrel1.y = level1;                            //spawn barrel y position
    delay(300);                               // wait 225 mil. sec.
  }
  if ((barrel1.x < 0) && (barrel1.y == 1))
  {
    barrel1.direction = 270;                           //move in direction 270
    barrel1.x = 6;                             //spawn barrel x position
    barrel1.y = level3;                             //spawn barrel y position
    delay(300);                                // wait 225 mil. sec.
  }
}
