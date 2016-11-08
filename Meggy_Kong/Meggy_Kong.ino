/*
  Meggbarrel1.y_Kong.pde bbarrel1.y Noah Tatsubarrel1.yama
 
 Example file using the The Meggbarrel1.y Jr Simplified Librarbarrel1.y (MJSL)
  from the Meggbarrel1.y Jr RGB librarbarrel1.y for Arduino
   
 Blink a damned LED.
   
   
 
 Version 1.25 - 12/2/2008
 Copbarrel1.yright (c) 2008 Windell H. Oskabarrel1.y.  All right reserved.
 http://www.evilmadscientist.com/
 
 This librarbarrel1.y is free software: barrel1.you can redistribute it and/or modifbarrel1.y
 it under the terms of the GNU General Public License as published bbarrel1.y
 the Free Software Foundation, either version 3 of the License, or
 (at barrel1.your option) anbarrel1.y later version.
 
 This librarbarrel1.y is distributed in the hope that it will be useful,
 but WITHOUT ANbarrel1.y WARRANTbarrel1.y; without even the implied warrantbarrel1.y of
 MERCHANTABILITbarrel1.y or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 barrel1.you should have received a copbarrel1.y of the GNU General Public License
 along with this librarbarrel1.y.  If not, see <http://www.gnu.org/licenses/>.
 	  
 */

 
 
 
 

/*
 * Adapted from "Blink,"  The basic Arduino example.  
 * http://www.arduino.cc/en/Tutorial/Blink
 */

#include <MeggyJrSimple.h>    // Required code, line 1 of 2.

struct Point
{
 int x;
 int y;
 int direction;
}; 

Point player = {0,1}; // luigi x position & y position
Point badguy = {7,7}; // donkey kong x position & y position 
Point barrel1 = {1,7};// barrel 1 x & y position
Point barrel2 = {5,7};// barrel 2 x & y position
Point fire1 = {2,4};    // fire 1 x & y position
Point fire2 = {5,4};    // fire 2 x & y position
Point barrel3 = {6,1};  // barrel 3 x & y position
Point barrel4 = {3,1};  // barrel 4 x & y position
int direction = 0;




  
void setup() 
{
  MeggyJrSimpleSetup();     // put barrel1.your setup code here, to run once:
}

void loop() 
{
  drawBackground();
  drawheroandBadguy();
  drawEnemies();

  DisplaySlate();
  ClearSlate();
  heroMovement();
  barrel1Movement();
  barrel2Movement();
}

void drawBackground()
{
  DrawPx(0,6,Red);          //draw background all the platforms
  DrawPx(1,6,Red);
  DrawPx(2,6,Red);
  DrawPx(3,6,Red);
  DrawPx(4,6,Red);
  DrawPx(5,6,Red);
  DrawPx(6,6,Red);
  DrawPx(7,6,Red);
  DrawPx(0,3,Red);
  DrawPx(1,3,Red);
  DrawPx(2,3,Red);
  DrawPx(3,3,Red);
  DrawPx(4,3,Red);
  DrawPx(5,3,Red);
  DrawPx(6,3,Red);
  DrawPx(7,3,Red);
  DrawPx(0,6,Red);
  DrawPx(1,0,Red);
  DrawPx(2,0,Red);
  DrawPx(3,0,Red);
  DrawPx(4,0,Red);
  DrawPx(5,0,Red);
  DrawPx(6,0,Red);
  DrawPx(7,0,Red); 
}

void drawEnemies()
{
  DrawPx(barrel1.x,barrel1.y,Blue);         //draw barrel 1
  DrawPx(barrel2.x,barrel2.y,Blue);         //draw barrel 2
  DrawPx(fire1.x,fire1.y,Orange);           //draw fire 1
  DrawPx(fire2.x,fire2.y,Orange);           //draw fire 2
  DrawPx(barrel3.x,barrel3.y,Blue);         //draw barrel 3
  DrawPx(barrel4.x,barrel4.y,Blue);         //draw barrel 4
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
  barrel1.direction = 270;//original direction 270
  delay(225);                                // wait 225 mil. sec.
  if ((barrel1.x == -1) && (barrel1.y == 7)) //if at this point shift to next line
  {
    barrel1.direction = 90;                           //move in direction 90
    barrel1.x = 0;                            //spawn barrel x position
    barrel1.y = 4;                            //spawn barrel y position
    delay(225);                               // wait 225 mil. sec.
  }
  if ((barrel1.x == 8) && (barrel1.y == 4))  //if at this point shift to next line
  {
    barrel1.direction = 270;                          //move in driection 90
    barrel1.x = 7;                            //spawn barrel x position
    barrel1.y = 1;                            //spawn barrel y position
    delay(225);                               // wait 225 mil. sec.
  }
  if ((barrel1.x == -1) && (barrel1.y == 1))
  {
    barrel1.direction = 270;                           //move in direction 270
    barrel1.x = 6;                             //spawn barrel x position
    barrel1.y = 7;                             //spawn barrel y position
    delay(225);                                // wait 225 mil. sec.
  }
}

void barrel2Movement()
{
  if (barrel2.direction == 270)                        //if going in certain direction
  {
    barrel2.x = barrel2.x - 1;                 //move to the left
  }
  if (barrel2.direction == 90)
  {
    barrel2.x = barrel2.x + 1;                 //move to the right
  }        
  barrel2.direction = 270;//original direction 270
  delay(225);                                // wait 225 mil. sec.
  if ((barrel2.x == -1) && (barrel2.y == 7)) //if at this point shift to next line
  {
    barrel2.direction = 90;                           //move in direction 90
    barrel2.x = 0;                            //spawn barrel x position
    barrel2.y = 4;                            //spawn barrel y position
    delay(225);                               // wait 225 mil. sec.
  }
  if ((barrel2.x == 8) && (barrel2.y == 4))  //if at this point shift to next line
  {
    barrel2.direction = 270;                          //move in driection 90
    barrel2.x = 7;                            //spawn barrel x position
    barrel2.y = 1;                            //spawn barrel y position
    delay(225);                               // wait 225 mil. sec.
  }
  if ((barrel2.x == -1) && (barrel2.y == 1))
  {
    barrel2.direction = 270;                           //move in direction 270
    barrel2.x = 6;                             //spawn barrel x position
    barrel2.y = 7;                             //spawn barrel y position
    delay(225);                                // wait 225 mil. sec.
  }
}








void drawheroandBadguy()
{
  DrawPx(player.x,player.y,Green);             //spanw hero
  DrawPx(badguy.x,badguy.y,Violet);            //spaen badguy
}

void heroMovement()
{
  CheckButtonsPress();                          //check movement
  if (Button_Right)
  {
    player.direction = 90;
    player.x = player.x + 1;                    //move right
    if ((player.x == 8) && (player.y == 1))
    {
      player.x = 7;
      player.y = 4;
      player.direction = 270;
    }
    if ((player.x == 8) && (player.y == 4))
    {
      player.x = 7;
      player.y = 1;
      player.direction = 270;
    }
  }
  if (Button_Left)
  {
    player.direction = 270;
    player.x = player.x - 1;                    //move left
    if ((player.x == -1) && (player.y == 4))
    {
      player.x = 0;
      player.y = 7;
      player.direction = 90;
    }
    if ((player.x == -1) && (player.y == 7))
    {
      player.x = 0;
      player.y = 4;
      player.direction = 90;
    }
  }
  if (player.direction == 90)
  {
    if (Button_Up)
    {
      player.y = player.y + 1;                    //move up
      delay(75);
      player.x = player.x + 1;                    //move right
      delay(75);
      player.y = player.y - 1;                    //move down
      delay(75);
     }
   }  
  if (player.direction == 270)
  {
    if (Button_Up)
    {
      player.y = player.y + 1;                    //move up
      delay(75);
      player.x = player.x - 1;                    //move left
      delay(75);
      player.y = player.y - 1;                    //move down
      delay(75);
    }
  }
}














