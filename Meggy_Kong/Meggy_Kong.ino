/*
  Meggy_Kong.pde by Noah Tatsuyama
 
 Example file using the The Meggy Jr Simplified Library (MJSL)
  from the Meggy Jr RGB library for Arduino
   
 Blink a damned LED.
   
   
 
 Version 1.25 - 12/2/2008
 Copyright (c) 2008 Windell H. Oskay.  All right reserved.
 http://www.evilmadscientist.com/
 
 This library is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this library.  If not, see <http://www.gnu.org/licenses/>.
 	  
 */

 
 
 
 

/*
 * Adapted from "Blink,"  The basic Arduino example.  
 * http://www.arduino.cc/en/Tutorial/Blink
 */

#include <MeggyJrSimple.h>    // Required code, line 1 of 2.

struct Barrel 1
{
  int c = 1; // barrel x position
  int d = 7; // barrel y position
  direction = 270;
}

struct Barrel 2
{
  int e = 5; // barrel2 x position
  int f = 7; // barrel2 y position
  direction = 270;
}

struct Fire 1
{
  int g = 2; // fire x position
  int h = 4; // fire y position
  direction = 90;
}

struct Fire 2
{
  int k = 5; // fire2 x position
  int m = 4; // fire2 y position
  direction = 90;
}

struct Barrel 3
{
  int n = 6; // barrel3 x position
  int o = 1; // barrel3 y position
  direction = 270;
}

struct Barrel 4
{
  int p = 3; // barrel4 x position
  int r = 1; // barrel4 y position
  direction = 270;
}

int x = 0; // luigi x position
int y = 1; // luigi y position
int a = 7; // donkey kong x position
int b = 7; // donkey kong y position






  
void setup() 
{
  MeggyJrSimpleSetup();     // put your setup code here, to run once:
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
  DrawPx(c,d,Blue);
  DrawPx(e,f,Blue);
  DrawPx(g,h,Orange);
  DrawPx(k,m,Orange);
  DrawPx(n,o,Blue);
  DrawPx(p,r,Blue);
}

void moveEnemies()
{
  c = c - 1;
  if (c = 0)
  {
    c = 6;
    d = 7;
  }
}

void drawHeroandBadguy()
{
  DrawPx(x,y,Green);
  DrawPx(a,b,Violet);
}

void HeroMovement()
{
  CheckButtonsPress();
  if (Button_Right)
  {
    x = x + 1;
    if (x > 7)
    {
      x = 7;
      y = 4;
    }
  }
  if (Button_Left)
  {
    x = x - 1;
    if (x < 0)
    {
      x = 0;
      y = 7;
    }
  }
  if (Button_Up)
  {
    y = y + 1;
    delay(75);
    x = x + 1;
    delay(75);
    y = y - 1;
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
  moveEnemies();
}















