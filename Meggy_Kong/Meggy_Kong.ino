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
Point badguy1 = {7,7}; // donkey kong x position & y position 
Point badguy2 = {4,1};
Point badguy3 = {3,1};
Point princess1 = {3,0};
Point princess2 = {4,0};
Point barrel1 = {1,7};// barrel 1 x & y position
Point barrel2 = {5,7};// barrel 2 x & y position
Point fire1 = {2,4};    // fire 1 x & y position
Point fire2 = {5,4};    // fire 2 x & y position
Point barrel3 = {6,1};  // barrel 3 x & y position
Point barrel4 = {3,1};  // barrel 4 x & y position
int direction = 0;
int platform1 = 1;
int platform2 = 4;
int platform3 = 7;
int enemyspeed = 225;


  
void setup() 
{
  MeggyJrSimpleSetup();     // put your setup code here, to run once:
  barrel1.direction = 270;
  barrel2.direction = 270;//original direction 270
  fire1.direction = 90;//original direction 90
  fire2.direction = 90;//original direction 90
  barrel3.direction = 270;
  barrel4.direction = 270;
}

void loop() 
{
  Level1();
}

void Level1()
{
  drawBackground();
  drawHandB();
  drawEnemies();

  DisplaySlate();
  ClearSlate();
  heroMovement();
  updateHero();  
  barrel1Movement();
  barrel2Movement();
  fire1Movement();
  fire2Movement();
  barrel3Movement();
  barrel4Movement();
  checkLevel2();
  if (drawNextLevel);
  {
    ClearSlate();
  }
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
  // barrel1.direction = 270;                 //original direction 270
  delay(enemyspeed);                                // wait 225 mil. sec.
  if ((barrel1.x < 0) && (barrel1.y == 7)) //if at this point shift to next line
  {
    barrel1.x = 0;                            //spawn barrel x position
    barrel1.y = platform2;                          //spawn barrel y position
    barrel1.direction = 90;                           //move in direction 90
    delay(enemyspeed);                               // wait 225 mil. sec.
  }
  if ((barrel1.x > 7) && (barrel1.y == 4))  //if at this point shift to next line
  {
    barrel1.direction = 270;;
    barrel1.x = 7;                            //spawn barrel x position
    barrel1.y = platform1;                            //spawn barrel y position
    delay(enemyspeed);                               // wait 225 mil. sec.
  }
  if ((barrel1.x < 0) && (barrel1.y == 1))
  {
    barrel1.direction = 270;                           //move in direction 270
    barrel1.x = 6;                             //spawn barrel x position
    barrel1.y = platform3;                             //spawn barrel y position
    delay(enemyspeed);                                // wait 225 mil. sec.
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
  delay(enemyspeed);                                // wait 225 mil. sec.
  if ((barrel2.x < 0) && (barrel2.y == platform3)) //if at this point shift to next line
  {
    barrel2.x = 0;                            //spawn barrel x position
    barrel2.y = platform2;                          //spawn barrel y position
    barrel2.direction = 90;                           //move in direction 90
    delay(enemyspeed);                               // wait 225 mil. sec.
  }
  if ((barrel2.x > 7) && (barrel2.y == platform2))  //if at this point shift to next line
  {
    barrel2.direction = 270;
    barrel2.x = 7;                            //spawn barrel x position
    barrel2.y = platform1;                            //spawn barrel y position
    delay(enemyspeed);                               // wait 225 mil. sec.
  }
  if ((barrel2.x < 0) && (barrel2.y == platform1))
  {
    barrel2.direction = 270;                           //move in direction 270
    barrel2.x = 6;                             //spawn barrel x position
    barrel2.y = platform3;                             //spawn barrel y position
    delay(enemyspeed);                                // wait 225 mil. sec.
  }
}

void fire1Movement()
{
  if (fire1.direction == 270)                        //if going in certain direction
  {
    fire1.x = fire1.x - 1;                 //move to the left
  }
  if (fire1.direction == 90)
  {
    fire1.x = fire1.x + 1;                 //move to the right
  }        
  delay(enemyspeed);                                // wait 225 mil. sec.
  if ((fire1.x > 7) && (fire1.y == platform2))  //if at this point shift to next line
  {
    fire1.direction = 270;
    fire1.x = 7;                            //spawn barrel x position
    fire1.y = platform1;                            //spawn barrel y position
    delay(enemyspeed);                               // wait 225 mil. sec.
  }
  if ((fire1.x < 0) && (fire1.y == platform1))
  {
    fire1.direction = 270;                           //move in direction 270
    fire1.x = 6;                             //spawn barrel x position
    fire1.y = platform3;                             //spawn barrel y position
    delay(enemyspeed);                                // wait 225 mil. sec.
  }
  if ((fire1.x < 0) && (fire1.y == platform3)) //if at this point shift to next line
  {
    fire1.x = 0;                            //spawn barrel x position
    fire1.y = platform2;                          //spawn barrel y position
    fire1.direction = 90;                           //move in direction 90
    delay(enemyspeed);                               // wait 225 mil. sec.
  }
}

void fire2Movement()
{
  if (fire2.direction == 270)                        //if going in certain direction
  {
    fire2.x = fire2.x - 1;                 //move to the left
  }
  if (fire2.direction == 90)
  {
    fire2.x = fire2.x + 1;                 //move to the right
  }        
  delay(enemyspeed);                                // wait 225 mil. sec.
  if ((fire2.x > 7) && (fire2.y == platform2))  //if at this point shift to next line
  {
    fire2.direction = 270;
    fire2.x = 7;                            //spawn barrel x position
    fire2.y = platform1;                            //spawn barrel y position
    delay(enemyspeed);                               // wait 225 mil. sec.
  }
  if ((fire2.x < 0) && (fire2.y == platform1))
  {
    fire2.direction = 270;                           //move in direction 270
    fire2.x = 6;                             //spawn barrel x position
    fire2.y = platform3;                             //spawn barrel y position
    delay(enemyspeed);                                // wait 225 mil. sec.
  }
  if ((fire2.x < 0) && (fire2.y == platform3)) //if at this point shift to next line
  {
    fire2.x = 0;                            //spawn barrel x position
    fire2.y = platform2;                          //spawn barrel y position
    fire2.direction = 90;                           //move in direction 90
    delay(enemyspeed);                               // wait 225 mil. sec.
  }
}

void barrel3Movement()
{
  if (barrel3.direction == 270)                        //if going in certain direction
  {
    barrel3.x = barrel3.x - 1;                 //move to the left
  }
  if (barrel3.direction == 90)
  {
    barrel3.x = barrel3.x + 1;                 //move to the right
  }        
  delay(enemyspeed);                                // wait 225 mil. sec.
  if ((barrel3.x < 0) && (barrel3.y == platform3)) //if at this point shift to next line
  {
    barrel3.x = 0;                            //spawn barrel x position
    barrel3.y = platform2;                          //spawn barrel y position
    barrel3.direction = 90;                           //move in direction 90
    delay(enemyspeed);                               // wait 225 mil. sec.
  }
  if ((barrel3.x > 7) && (barrel3.y == platform2))  //if at this point shift to next line
  {
    barrel3.direction = 270;
    barrel3.x = 7;                            //spawn barrel x position
    barrel3.y = platform1;                            //spawn barrel y position
    delay(enemyspeed);                               // wait 225 mil. sec.
  }
  if ((barrel3.x < 0) && (barrel3.y == platform1))
  {
    barrel3.direction = 270;                           //move in direction 270
    barrel3.x = 6;                             //spawn barrel x position
    barrel3.y = platform3;                             //spawn barrel y position
    delay(enemyspeed);                                // wait 225 mil. sec.
  }
}

void barrel4Movement()
{
  if (barrel4.direction == 270)                        //if going in certain direction
  {
    barrel4.x = barrel4.x - 1;                 //move to the left
  }
  if (barrel4.direction == 90)
  {
    barrel4.x = barrel4.x + 1;                 //move to the right
  }        
  delay(enemyspeed);                                // wait 225 mil. sec.
  if ((barrel4.x < 0) && (barrel4.y == platform3)) //if at this point shift to next line
  {
    barrel4.x = 0;                            //spawn barrel x position
    barrel4.y = platform2;                          //spawn barrel y position
    barrel4.direction = 90;                           //move in direction 90
    delay(enemyspeed);                               // wait 225 mil. sec.
  }
  if ((barrel4.x > 7) && (barrel4.y == platform2))  //if at this point shift to next line
  {
    barrel4.direction = 270;
    barrel4.x = 7;                            //spawn barrel x position
    barrel4.y = platform1;                            //spawn barrel y position
    delay(enemyspeed);                               // wait 225 mil. sec.
  }
  if ((barrel4.x < 0) && (barrel4.y == platform1))
  {
    barrel4.direction = 270;                           //move in direction 270
    barrel4.x = 6;                             //spawn barrel x position
    barrel4.y = platform3;                             //spawn barrel y position
    delay(enemyspeed);                                // wait 225 mil. sec.
  }
}

void updateHero()
{                          //check movement
  if (player.direction == 90)
  {
    player.x = player.x + 1;
    delay(75);
    DisplaySlate(); 
    ClearSlate();      
    if ((player.x == 8) && (player.y == platform1))
    {
      player.x = 7;
      player.y = platform2;
    }
    if ((player.x == 8) && (player.y == platform2))
    {
      player.x = 7;
      player.y = platform1;
    }
  }  
  if (player.direction == 270)
  { 
    player.x = player.x - 1; 
    delay(75);
    DisplaySlate();
    ClearSlate();
    if ((player.x == -1) && (player.y == platform2))
    {
      player.x = 0;
      player.y = platform3;
    }
    if ((player.x == -1) && (player.y == platform3))
    {
      player.x = 0;
      player.y = platform2;
    }
  }  
  if (Button_Up && player.direction == 90)
  {
    player.y = player.y + 1;
    delay(75);
    player.x = player.x + 1;
    delay(75);
    player.y = player.y - 1;                    //move down
    delay(75);
  }  
  if (Button_Up && player.direction == 270)
  {
    player.y = player.y + 1;
    delay(75);
    player.x = player.x - 1;                    //move left
    delay(75);
    player.y = player.y - 1;                    //move down
    delay(75);
  }
}

void heroMovement()
{
  CheckButtonsPress();
  if (Button_Right)
  {
    player.direction = 90;
  }
  if (Button_Left)
  {
    player.direction = 270;
  }
}


void checkLevel2()
{
  if ((player.x == badguy1.x) && (player.y == badguy1.y))
  {
    drawNextLevel();
  }
}

void drawNextLevel()
{
  DrawPx(badguy3.x,badguy3.y,Violet);
  DrawPx(badguy2.x,badguy2.y,Violet);
  DrawPx(princess1.x,princess1.y,Orange);
  DrawPx(princess2.x,princess2.y,Orange);
  DisplaySlate();
  ClearSlate();
  nextLevelMovement();
  delay(300);
}

void nextLevelMovement()
{
  badguy3.y = badguy3.y + 1;
  badguy2.y = badguy2.y + 1;
  princess1.y = princess1.y + 1;
  princess2.y = princess2.y + 1; 
  if (badguy3.y == 8)
  {
    ClearSlate(); 
  }
  if (badguy2.y == 8)
  {
    ClearSlate(); 
  }
  if (princess1.y == 8)
  {
    ClearSlate(); 
  }
  if (princess2.y == 8)
  {
    ClearSlate(); 
  }      
}

void drawHandB()
{
  DrawPx(player.x,player.y,Green);             //spanw hero
  DrawPx(badguy1.x,badguy1.y,Violet);            //spaen badguy1.1
}














