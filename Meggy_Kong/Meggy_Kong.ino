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
}; 

Point player = {0,1}; // luigi x position & y position
Point badguy = {7,7}; // donkey kong x position & y position 
Point barrel1 = {1,7};
Point barrel2 = {5,7};
int g = 2;
int h = 4;
int k = 5;
int m = 4;
int n = 6; 
int o = 1;
int p = 3;
int r = 1;




  
void setup() 
{
  MeggyJrSimpleSetup();     // put barrel1.your setup code here, to run once:
}

void drawBackground()
{
  DrawPx(0,6,Red);
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
  DrawPx(barrel1.x,barrel1.y,Blue);
  DrawPx(e,f,Blue);
  DrawPx(g,h,Orange);
  DrawPx(k,m,Orange);
  DrawPx(n,o,Blue);
  DrawPx(p,r,Blue);
}

void barrel1Movement()
{
  int direction = 270;
  delay(225);
  if (direction == 270)
  {
    barrel1.x = barrel1.x - 1;
  }
  if (direction == 90)
  {
    barrel1.x = barrel1.x = 1;
  }
  if ((barrel1.x == -1) && (barrel1.y == 7))
  {
    barrel1.x = 1;
    barrel1.y = 4;
    direction = 90;
    delay(225);
  }
  if ((barrel1.x == 8) && (barrel1.y == 4))
  {
    barrel1.x = 7;
    barrel1.y = 1;
    direction = 270;
    delay(225);
  }
  if ((barrel1.x == -1) && (barrel1.y == 1))
  {
    barrel1.x = 6;
    barrel1.y = 7;
    direction = 270; 
    delay(225);
  }
}



void drawHeroandBadguy()
{
  DrawPx(player.x,player.y,Green);
  DrawPx(badguy.x,badguy.y,Violet);
}

void HeroMovement()
{
  CheckButtonsPress();
  if (Button_Right)
  {
    player.x = player.x + 1;
    if (player.x > 7)
    {
      player.x = 7;
      player.y = 4;
    }
  }
  if (Button_Left)
  {
    player.x = player.x - 1;
    if (player.x < 0)
    {
      player.x = 0;
      player.y = 7;
    }
  }
  if (Button_Up)
  {
    player.y = player.y + 1;
    delay(75);
    player.x = player.x + 1;
    delay(75);
    player.y = player.y - 1;
    delay(75);
  }
}



void loop() 
{
  drawBackground();
  drawHeroandBadguy();
  drawEnemies();

  DisplaySlate();
  ClearSlate();
  HeroMovement();
  barrel1Movement();

  
}















