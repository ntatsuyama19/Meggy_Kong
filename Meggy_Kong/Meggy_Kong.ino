/*
  Meggy_Kong.pde bbarrel1.y Noah Tatsubarrel1.yama
 
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
Point barrel3 = {7,1};  // barrel 3 x & y position
Point barrel4 = {3,1};  // barrel 4 x & y position
int direction = 0;
int platform1 = 1;
int platform2 = 4;
int platform3 = 7;
int enemyspeed1 = 200;
int enemyspeed2 = 100;
int playerspeed = 200;


  
void setup() 
{
  MeggyJrSimpleSetup();     // put your setup code here, to run once:
  player.direction = 90;
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
  if (drawlevel2)
  {
    Level2();
  }
  checkRestart();
}

void checkRestart()
{
  CheckButtonsDown;
  if (Button_Down)
  {
    ClearSlate();
    player.x = 0;
    player.y = 1;
    badguy1.x = 7;
    badguy2.y = 7;
    barrel1.x = 1;
    barrel1.y = 7;
    barrel2.x = 5;
    barrel2.y = 7;
    fire1.x = 2;
    fire1.y = 4;
    fire2.x = 6;
    fire2.y = 4;  
    barrel3.x = 7;
    barrel3.y = 1;
    barrel4.x = 3;
    barrel4.y = 1;
    drawBackground();
    drawHandB();
    drawEnemies();
    Level1();
  }
}




void Level1()
{
  drawBackground();
  drawHandB();
  drawEnemies();
  checkDeath();

  DisplaySlate();
  heroMovement();
  updateHero();  
  level1enemymovement();
  checkLevel2();
  ClearSlate();
}

void drawlevel2()
{
  drawBackground();
  drawHandB();
  drawEnemies();
  DisplaySlate();
  if (Level2)
  {
    ClearSlate();
  }
}

void Level2()
{
  drawBackground();
  drawHandB();
  drawEnemies();
  checkDeath();

  DisplaySlate();
  heroMovement();
  updateHero();  
  level2enemymovement();
  checkLevel3();
  ClearSlate();
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
  DrawPx(0,0,Red);
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

void level1enemymovement()
{
  barrel1Movement1();
  barrel2Movement1();
  fire1Movement1();
  fire2Movement1();
  barrel3Movement1();
  barrel4Movement1();
}

void level2enemymovement()
{
  barrel1Movement2();
  barrel2Movement2();
  fire1Movement2();
  fire2Movement2();
  barrel3Movement2();
  barrel4Movement2();
}

void barrel1Movement1()
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
  delay(enemyspeed1);                                // wait 500 mil. sec.
  if ((barrel1.x < 0) && (barrel1.y == 7)) //if at this point shift to next line
  {
    barrel1.x = 0;                            //spawn barrel x position
    barrel1.y = platform2;                          //spawn barrel y position
    barrel1.direction = 90;                           //move in direction 90
    delay(enemyspeed1);                               // wait 500 mil. sec.
  }
  if ((barrel1.x > 7) && (barrel1.y == 4))  //if at this point shift to next line
  {
    barrel1.direction = 270;;
    barrel1.x = 7;                            //spawn barrel x position
    barrel1.y = platform1;                            //spawn barrel y position
    delay(enemyspeed1);                               // wait 500 mil. sec.
  }
  if ((barrel1.x < 0) && (barrel1.y == 1))
  {
    barrel1.direction = 270;                           //move in direction 270
    barrel1.x = 6;                             //spawn barrel x position
    barrel1.y = platform3;                             //spawn barrel y position
    delay(enemyspeed1);                                // wait 500 mil. sec.
  }
}

void barrel2Movement1()
{
  if (barrel2.direction == 270)                        //if going in certain direction
  {
    barrel2.x = barrel2.x - 1;                 //move to the left
  }
  if (barrel2.direction == 90)
  {
    barrel2.x = barrel2.x + 1;                 //move to the right
  }        
  delay(enemyspeed1);                                // wait 500 mil. sec.
  if ((barrel2.x < 0) && (barrel2.y == platform3)) //if at this point shift to next line
  {
    barrel2.x = 0;                            //spawn barrel x position
    barrel2.y = platform2;                          //spawn barrel y position
    barrel2.direction = 90;                           //move in direction 90
    delay(enemyspeed1);                               // wait 500 mil. sec.
  }
  if ((barrel2.x > 7) && (barrel2.y == platform2))  //if at this point shift to next line
  {
    barrel2.direction = 270;
    barrel2.x = 7;                            //spawn barrel x position
    barrel2.y = platform1;                            //spawn barrel y position
    delay(enemyspeed1);                               // wait 500 mil. sec.
  }
  if ((barrel2.x < 0) && (barrel2.y == platform1))
  {
    barrel2.direction = 270;                           //move in direction 270
    barrel2.x = 6;                             //spawn barrel x position
    barrel2.y = platform3;                             //spawn barrel y position
    delay(enemyspeed1);                                // wait 500 mil. sec.
  }
}

void fire1Movement1()
{
  if (fire1.direction == 270)                        //if going in certain direction
  {
    fire1.x = fire1.x - 1;                 //move to the left
  }
  if (fire1.direction == 90)
  {
    fire1.x = fire1.x + 1;                 //move to the right
  }        
  delay(enemyspeed1);                                // wait 500 mil. sec.
  if ((fire1.x > 7) && (fire1.y == platform2))  //if at this point shift to next line
  {
    fire1.direction = 270;
    fire1.x = 7;                            //spawn barrel x position
    fire1.y = platform1;                            //spawn barrel y position
    delay(enemyspeed1);                               // wait 500 mil. sec.
  }
  if ((fire1.x < 0) && (fire1.y == platform1))
  {
    fire1.direction = 270;                           //move in direction 270
    fire1.x = 6;                             //spawn barrel x position
    fire1.y = platform3;                             //spawn barrel y position
    delay(enemyspeed1);                                // wait 500 mil. sec.
  }
  if ((fire1.x < 0) && (fire1.y == platform3)) //if at this point shift to next line
  {
    fire1.x = 0;                            //spawn barrel x position
    fire1.y = platform2;                          //spawn barrel y position
    fire1.direction = 90;                           //move in direction 90
    delay(enemyspeed1);                               // wait 500 mil. sec.
  }
}

void fire2Movement1()
{
  if (fire2.direction == 270)                        //if going in certain direction
  {
    fire2.x = fire2.x - 1;                 //move to the left
  }
  if (fire2.direction == 90)
  {
    fire2.x = fire2.x + 1;                 //move to the right
  }        
  delay(enemyspeed1);                                // wait 500 mil. sec.
  if ((fire2.x > 7) && (fire2.y == platform2))  //if at this point shift to next line
  {
    fire2.direction = 270;
    fire2.x = 7;                            //spawn barrel x position
    fire2.y = platform1;                            //spawn barrel y position
    delay(enemyspeed1);                               // 500 mil. sec.
  }
  if ((fire2.x < 0) && (fire2.y == platform1))
  {
    fire2.direction = 270;                           //move in direction 270
    fire2.x = 6;                             //spawn barrel x position
    fire2.y = platform3;                             //spawn barrel y position
    delay(enemyspeed1);                                // wait 500 mil. sec.
  }
  if ((fire2.x < 0) && (fire2.y == platform3)) //if at this point shift to next line
  {
    fire2.x = 0;                            //spawn barrel x position
    fire2.y = platform2;                          //spawn barrel y position
    fire2.direction = 90;                           //move in direction 90
    delay(enemyspeed1);                               // wait 500 mil. sec.
  }
}

void barrel3Movement1()
{
  if (barrel3.direction == 270)                        //if going in certain direction
  {
    barrel3.x = barrel3.x - 1;                 //move to the left
  }
  if (barrel3.direction == 90)
  {
    barrel3.x = barrel3.x + 1;                 //move to the right
  }        
  delay(enemyspeed1);                                // wait 500 mil. sec.
  if ((barrel3.x < 0) && (barrel3.y == platform3)) //if at this point shift to next line
  {
    barrel3.x = 0;                            //spawn barrel x position
    barrel3.y = platform2;                          //spawn barrel y position
    barrel3.direction = 90;                           //move in direction 90
    delay(enemyspeed1);                               // wait 500 mil. sec.
  }
  if ((barrel3.x > 7) && (barrel3.y == platform2))  //if at this point shift to next line
  {
    barrel3.direction = 270;
    barrel3.x = 7;                            //spawn barrel x position
    barrel3.y = platform1;                            //spawn barrel y position
    delay(enemyspeed1);                               // wait 500 mil. sec.
  }
  if ((barrel3.x < 0) && (barrel3.y == platform1))
  {
    barrel3.direction = 270;                           //move in direction 270
    barrel3.x = 6;                             //spawn barrel x position
    barrel3.y = platform3;                             //spawn barrel y position
    delay(enemyspeed1);                                // wait 500 mil. sec.
  }
}

void barrel4Movement1()
{
  if (barrel4.direction == 270)                        //if going in certain direction
  {
    barrel4.x = barrel4.x - 1;                 //move to the left
  }
  if (barrel4.direction == 90)
  {
    barrel4.x = barrel4.x + 1;                 //move to the right
  }        
  delay(enemyspeed1);                                // wait 500 mil. sec.
  if ((barrel4.x < 0) && (barrel4.y == platform3)) //if at this point shift to next line
  {
    barrel4.x = 0;                            //spawn barrel x position
    barrel4.y = platform2;                          //spawn barrel y position
    barrel4.direction = 90;                           //move in direction 90
    delay(enemyspeed1);                               // wait 500 mil. sec.
  }
  if ((barrel4.x > 7) && (barrel4.y == platform2))  //if at this point shift to next line
  {
    barrel4.direction = 270;
    barrel4.x = 7;                            //spawn barrel x position
    barrel4.y = platform1;                            //spawn barrel y position
    delay(enemyspeed1);                               // wait 500 mil. sec.
  }
  if ((barrel4.x < 0) && (barrel4.y == platform1))
  {
    barrel4.direction = 270;                           //move in direction 270
    barrel4.x = 6;                             //spawn barrel x position
    barrel4.y = platform3;                             //spawn barrel y position
    delay(enemyspeed1);                                // wait 500 mil. sec.
  }
}

void updateHero()
{                          //check movement
  if (player.direction == 90)
  {
    DisplaySlate();
    delay(playerspeed);     
    if ((player.x > 7) && (player.y == platform1))
    {
      player.direction = 270;
      player.x = 7;
      player.y = platform2;
    }
  }  
  if (player.direction == 270)
  { 
    DisplaySlate();
    delay(playerspeed);
    if ((player.x < 0) && (player.y == platform2))
    {
      player.direction = 90;
      player.x = 0;
      player.y = platform3;
    }  
  } 
  if (player.direction == 180)
  { 
    if (Button_Up && player.direction == 90)
    {
      player.y = player.y + 1;
      delay(playerspeed);
      player.x = player.x + 1;
      delay(playerspeed);
      player.x = player.x + 1;
      delay(playerspeed);
      player.y = player.y - 1;                    //move down
      delay(playerspeed);
    }  
    if (Button_Up && player.direction == 270)
    {
      player.y = player.y + 1;
      delay(playerspeed);
      player.x = player.x - 1;                    //move left
      delay(playerspeed);
      player.x = player.x - 1;                    //move left
      delay(playerspeed);
      player.y = player.y - 1;                    //move down
      delay(playerspeed);
    }
  }  
}

void heroMovement()
{
  CheckButtonsPress();
  if (Button_Right)
  {
    player.x = player.x + 1;
    player.direction = 90;
  }
  if (Button_Left)
  {
    player.x = player.x - 1;
    player.direction = 270;
  }
  if  (Button_A)
  {
    playerspeed = playerspeed * 2;
  }
  if (Button_B)
  {
    playerspeed = playerspeed / 2;
  }
}

void checkLevel2()
{
  if ((player.x == badguy1.x) && (player.y == badguy1.y))
  {
    drawNextLevel();
  }
}

void checkLevel3()
{
  if ((player.x == badguy1.x) && (player.y == badguy1.y))
  {
    drawNextLevel();
  }
}

void drawNextLevel()
{
  ClearSlate();
  DrawPx(3,1,Violet);
  DrawPx(4,1,Violet);
  DrawPx(3,0,Orange);
  DrawPx(4,0,Orange);
  DisplaySlate();
  delay(500);
  ClearSlate();

  DrawPx(3,2,Violet);
  DrawPx(4,2,Violet);
  DrawPx(3,1,Orange);
  DrawPx(4,1,Orange);
  DisplaySlate();
  delay(500);
  ClearSlate();

  DrawPx(3,3,Violet);
  DrawPx(4,3,Violet);
  DrawPx(3,2,Orange);
  DrawPx(4,2,Orange);
  DisplaySlate();
  delay(500);
  ClearSlate();

  DrawPx(3,4,Violet);
  DrawPx(4,4,Violet);
  DrawPx(3,3,Orange);
  DrawPx(4,3,Orange);
  DisplaySlate();
  delay(500);
  ClearSlate();

  DrawPx(3,5,Violet);
  DrawPx(4,5,Violet);
  DrawPx(3,4,Orange);
  DrawPx(4,4,Orange);
  DisplaySlate();
  delay(500);
  ClearSlate();

  DrawPx(3,6,Violet);
  DrawPx(4,6,Violet);
  DrawPx(3,5,Orange);
  DrawPx(4,5,Orange);
  DisplaySlate();
  delay(500);
  ClearSlate();

  DrawPx(3,7,Violet);
  DrawPx(4,7,Violet);
  DrawPx(3,6,Orange);
  DrawPx(4,6,Orange);
  DisplaySlate();
  delay(500);
  ClearSlate();

  DrawPx(3,7,Orange);
  DrawPx(4,7,Orange);
  DisplaySlate();
  delay(500);
  ClearSlate();

  drawlevel2();
}



void drawHandB()
{
  DrawPx(player.x,player.y,Green);             //spanw hero
  DrawPx(badguy1.x,badguy1.y,Violet);            //spaen badguy1.1
}



void checkDeath()                                //check dead
{
  if ((player.x == barrel1.x) && (player.y == barrel1.y))
  {
    ClearSlate(); 
    playDeath();
  }
  if ((player.x == barrel2.x) && (player.y == barrel2.y))
  {
    ClearSlate(); 
    playDeath();
  }
  if ((player.x == barrel3.x) && (player.y == barrel3.y))
  {
    ClearSlate(); 
    playDeath();
  }
  if ((player.x == barrel4.x) && (player.y == barrel4.y))
  {
    ClearSlate(); 
    playDeath();
  }
  if ((player.x == fire1.x) && (player.y == fire1.y))
  {
    ClearSlate(); 
    playDeath(); 
  }
  if ((player.x == fire2.x) && (player.y == fire2.y))
  {
    ClearSlate(); 
    playDeath();
  }
  
}

void drawLoweringFlag()
{
  DrawPx(2,0,Violet);
  DrawPx(2,1,Violet);
  DrawPx(2,2,Violet);
  DrawPx(2,3,Violet);
  DrawPx(2,4,Violet);
  DrawPx(2,5,Violet);
  DrawPx(2,6,Violet);
  DrawPx(2,7,Violet);
  DrawPx(3,0,Violet);
  DrawPx(3,1,Violet);
  DrawPx(3,2,Violet);
  DrawPx(3,3,Violet);
  DrawPx(3,4,Violet);
  DrawPx(3,5,Violet);
  DrawPx(3,6,Violet);
  DrawPx(3,7,Violet);
  DrawPx(4,5,Green);
  DrawPx(4,6,Green);
  DrawPx(4,7,Green);
  DrawPx(5,6,Green);
  DisplaySlate();
  delay(500);
  ClearSlate();
  
  DrawPx(2,0,Violet);
  DrawPx(2,1,Violet);
  DrawPx(2,2,Violet);
  DrawPx(2,3,Violet);
  DrawPx(2,4,Violet);
  DrawPx(2,5,Violet);
  DrawPx(2,6,Violet);
  DrawPx(2,7,Violet);
  DrawPx(3,0,Violet);
  DrawPx(3,1,Violet);
  DrawPx(3,2,Violet);
  DrawPx(3,3,Violet);
  DrawPx(3,4,Violet);
  DrawPx(3,5,Violet);
  DrawPx(3,6,Violet);
  DrawPx(3,7,Violet);
  DrawPx(4,4,Green);
  DrawPx(4,5,Green);
  DrawPx(4,6,Green);
  DrawPx(5,5,Green);
  DisplaySlate();
  delay(500);
  ClearSlate(); 

  DrawPx(2,0,Violet);
  DrawPx(2,1,Violet);
  DrawPx(2,2,Violet);
  DrawPx(2,3,Violet);
  DrawPx(2,4,Violet);
  DrawPx(2,5,Violet);
  DrawPx(2,6,Violet);
  DrawPx(2,7,Violet);
  DrawPx(3,0,Violet);
  DrawPx(3,1,Violet);
  DrawPx(3,2,Violet);
  DrawPx(3,3,Violet);
  DrawPx(3,4,Violet);
  DrawPx(3,5,Violet);
  DrawPx(3,6,Violet);
  DrawPx(3,7,Violet);
  DrawPx(4,3,Green);
  DrawPx(4,4,Green);
  DrawPx(4,5,Green);
  DrawPx(5,4,Green);
  DisplaySlate();
  delay(500);
  ClearSlate();

  DrawPx(2,0,Violet);
  DrawPx(2,1,Violet);
  DrawPx(2,2,Violet);
  DrawPx(2,3,Violet);
  DrawPx(2,4,Violet);
  DrawPx(2,5,Violet);
  DrawPx(2,6,Violet);
  DrawPx(2,7,Violet);
  DrawPx(3,0,Violet);
  DrawPx(3,1,Violet);
  DrawPx(3,2,Violet);
  DrawPx(3,3,Violet);
  DrawPx(3,4,Violet);
  DrawPx(3,5,Violet);
  DrawPx(3,6,Violet);
  DrawPx(3,7,Violet);
  DrawPx(4,2,Green);
  DrawPx(4,3,Green);
  DrawPx(4,4,Green);
  DrawPx(5,3,Green);
  DisplaySlate();
  delay(500);
  ClearSlate();

  DrawPx(2,0,Violet);
  DrawPx(2,1,Violet);
  DrawPx(2,2,Violet);
  DrawPx(2,3,Violet);
  DrawPx(2,4,Violet);
  DrawPx(2,5,Violet);
  DrawPx(2,6,Violet);
  DrawPx(2,7,Violet);
  DrawPx(3,0,Violet);
  DrawPx(3,1,Violet);
  DrawPx(3,2,Violet);
  DrawPx(3,3,Violet);
  DrawPx(3,4,Violet);
  DrawPx(3,5,Violet);
  DrawPx(3,6,Violet);
  DrawPx(3,7,Violet);
  DrawPx(4,1,Green);
  DrawPx(4,2,Green);
  DrawPx(4,3,Green);
  DrawPx(5,2,Green);
  DisplaySlate();
  delay(500);
  ClearSlate(); 

  DrawPx(2,0,Violet);
  DrawPx(2,1,Violet);
  DrawPx(2,2,Violet);
  DrawPx(2,3,Violet);
  DrawPx(2,4,Violet);
  DrawPx(2,5,Violet);
  DrawPx(2,6,Violet);
  DrawPx(2,7,Violet);
  DrawPx(3,0,Violet);
  DrawPx(3,1,Violet);
  DrawPx(3,2,Violet);
  DrawPx(3,3,Violet);
  DrawPx(3,4,Violet);
  DrawPx(3,5,Violet);
  DrawPx(3,6,Violet);
  DrawPx(3,7,Violet);
  DrawPx(4,0,Green);
  DrawPx(4,1,Green);
  DrawPx(4,2,Green);
  DrawPx(5,1,Green);
  DisplaySlate();
  delay(500);
  ClearSlate();        
}

void playDeath()                                  //what to do if dead
{ 
  drawLoweringFlag();
  DrawPx(0,0,Red);
  DrawPx(0,7,Red);
  DrawPx(1,1,Red);
  DrawPx(1,6,Red);
  DrawPx(2,2,Red);
  DrawPx(2,5,Red);
  DrawPx(3,3,Red);
  DrawPx(3,4,Red);
  DrawPx(4,4,Red);
  DrawPx(4,3,Red);
  DrawPx(5,5,Red);
  DrawPx(5,2,Red);
  DrawPx(6,6,Red);
  DrawPx(6,1,Red);
  DrawPx(7,7,Red);
  DrawPx(7,0,Red);
  DisplaySlate();
  delay(500);
  ClearSlate();
  Restart();

}

void Restart()
{
  player.x = 0;
  player.y = 1;
  badguy1.x = 7;
  badguy2.y = 7;
  barrel1.x = 1;
  barrel1.y = 7;
  barrel2.x = 5;
  barrel2.y = 7;
  fire1.x = 2;
  fire1.y = 4;
  fire2.x = 6;
  fire2.y = 4;  
  barrel3.x = 7;
  barrel3.y = 1;
  barrel4.x = 3;
  barrel4.y = 1;
  drawBackground();
  drawHandB();
  drawEnemies();
  Level1();
}

void barrel1Movement2()
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
  delay(enemyspeed2);                                // wait 300 mil. sec.
  if ((barrel1.x < 0) && (barrel1.y == 7)) //if at this point shift to next line
  {
    barrel1.x = 0;                            //spawn barrel x position
    barrel1.y = platform2;                          //spawn barrel y position
    barrel1.direction = 90;                           //move in direction 90
    delay(enemyspeed2);                               // wait 300 mil. sec.
  }
  if ((barrel1.x > 7) && (barrel1.y == 4))  //if at this point shift to next line
  {
    barrel1.direction = 270;;
    barrel1.x = 7;                            //spawn barrel x position
    barrel1.y = platform1;                            //spawn barrel y position
    delay(enemyspeed2);                               // wait 300 mil. sec.
  }
  if ((barrel1.x < 0) && (barrel1.y == 1))
  {
    barrel1.direction = 270;                           //move in direction 270
    barrel1.x = 6;                             //spawn barrel x position
    barrel1.y = platform3;                             //spawn barrel y position
    delay(enemyspeed2);                                // wait 300 mil. sec.
  }
}

void barrel2Movement2()
{
  if (barrel2.direction == 270)                        //if going in certain direction
  {
    barrel2.x = barrel2.x - 1;                 //move to the left
  }
  if (barrel2.direction == 90)
  {
    barrel2.x = barrel2.x + 1;                 //move to the right
  }        
  delay(enemyspeed2);                                // wait 300 mil. sec.
  if ((barrel2.x < 0) && (barrel2.y == platform3)) //if at this point shift to next line
  {
    barrel2.x = 0;                            //spawn barrel x position
    barrel2.y = platform2;                          //spawn barrel y position
    barrel2.direction = 90;                           //move in direction 90
    delay(enemyspeed2);                               // wait 300 mil. sec.
  }
  if ((barrel2.x > 7) && (barrel2.y == platform2))  //if at this point shift to next line
  {
    barrel2.direction = 270;
    barrel2.x = 7;                            //spawn barrel x position
    barrel2.y = platform1;                            //spawn barrel y position
    delay(enemyspeed2);                               // wait 300 mil. sec.
  }
  if ((barrel2.x < 0) && (barrel2.y == platform1))
  {
    barrel2.direction = 270;                           //move in direction 270
    barrel2.x = 6;                             //spawn barrel x position
    barrel2.y = platform3;                             //spawn barrel y position
    delay(enemyspeed2);                                // wait 300 mil. sec.
  }
}

void fire1Movement2()
{
  if (fire1.direction == 270)                        //if going in certain direction
  {
    fire1.x = fire1.x - 1;                 //move to the left
  }
  if (fire1.direction == 90)
  {
    fire1.x = fire1.x + 1;                 //move to the right
  }        
  delay(enemyspeed2);                                // wait 300 mil. sec.
  if ((fire1.x > 7) && (fire1.y == platform2))  //if at this point shift to next line
  {
    fire1.direction = 270;
    fire1.x = 7;                            //spawn barrel x position
    fire1.y = platform1;                            //spawn barrel y position
    delay(enemyspeed2);                               // wait 300 mil. sec.
  }
  if ((fire1.x < 0) && (fire1.y == platform1))
  {
    fire1.direction = 270;                           //move in direction 270
    fire1.x = 6;                             //spawn barrel x position
    fire1.y = platform3;                             //spawn barrel y position
    delay(enemyspeed2);                                // wait 300 mil. sec.
  }
  if ((fire1.x < 0) && (fire1.y == platform3)) //if at this point shift to next line
  {
    fire1.x = 0;                            //spawn barrel x position
    fire1.y = platform2;                          //spawn barrel y position
    fire1.direction = 90;                           //move in direction 90
    delay(enemyspeed2);                               // wait 300 mil. sec.
  }
}

void fire2Movement2()
{
  if (fire2.direction == 270)                        //if going in certain direction
  {
    fire2.x = fire2.x - 1;                 //move to the left
  }
  if (fire2.direction == 90)
  {
    fire2.x = fire2.x + 1;                 //move to the right
  }        
  delay(enemyspeed2);                                // wait 300 mil. sec.
  if ((fire2.x > 7) && (fire2.y == platform2))  //if at this point shift to next line
  {
    fire2.direction = 270;
    fire2.x = 7;                            //spawn barrel x position
    fire2.y = platform1;                            //spawn barrel y position
    delay(enemyspeed2);                               // 300 mil. sec.
  }
  if ((fire2.x < 0) && (fire2.y == platform1))
  {
    fire2.direction = 270;                           //move in direction 270
    fire2.x = 6;                             //spawn barrel x position
    fire2.y = platform3;                             //spawn barrel y position
    delay(enemyspeed2);                                // wait 300 mil. sec.
  }
  if ((fire2.x < 0) && (fire2.y == platform3)) //if at this point shift to next line
  {
    fire2.x = 0;                            //spawn barrel x position
    fire2.y = platform2;                          //spawn barrel y position
    fire2.direction = 90;                           //move in direction 90
    delay(enemyspeed2);                               // wait 300 mil. sec.
  }
}

void barrel3Movement2()
{
  if (barrel3.direction == 270)                        //if going in certain direction
  {
    barrel3.x = barrel3.x - 1;                 //move to the left
  }
  if (barrel3.direction == 90)
  {
    barrel3.x = barrel3.x + 1;                 //move to the right
  }        
  delay(enemyspeed2);                                // wait 300 mil. sec.
  if ((barrel3.x < 0) && (barrel3.y == platform3)) //if at this point shift to next line
  {
    barrel3.x = 0;                            //spawn barrel x position
    barrel3.y = platform2;                          //spawn barrel y position
    barrel3.direction = 90;                           //move in direction 90
    delay(enemyspeed2);                               // wait 300 mil. sec.
  }
  if ((barrel3.x > 7) && (barrel3.y == platform2))  //if at this point shift to next line
  {
    barrel3.direction = 270;
    barrel3.x = 7;                            //spawn barrel x position
    barrel3.y = platform1;                            //spawn barrel y position
    delay(enemyspeed2);                               // wait 300 mil. sec.
  }
  if ((barrel3.x < 0) && (barrel3.y == platform1))
  {
    barrel3.direction = 270;                           //move in direction 270
    barrel3.x = 6;                             //spawn barrel x position
    barrel3.y = platform3;                             //spawn barrel y position
    delay(enemyspeed2);                                // wait 300 mil. sec.
  }
}

void barrel4Movement2()
{
  if (barrel4.direction == 270)                        //if going in certain direction
  {
    barrel4.x = barrel4.x - 1;                 //move to the left
  }
  if (barrel4.direction == 90)
  {
    barrel4.x = barrel4.x + 1;                 //move to the right
  }        
  delay(enemyspeed2);                                // wait 300 mil. sec.
  if ((barrel4.x < 0) && (barrel4.y == platform3)) //if at this point shift to next line
  {
    barrel4.x = 0;                            //spawn barrel x position
    barrel4.y = platform2;                          //spawn barrel y position
    barrel4.direction = 90;                           //move in direction 90
    delay(enemyspeed2);                               // wait 300 mil. sec.
  }
  if ((barrel4.x > 7) && (barrel4.y == platform2))  //if at this point shift to next line
  {
    barrel4.direction = 270;
    barrel4.x = 7;                            //spawn barrel x position
    barrel4.y = platform1;                            //spawn barrel y position
    delay(enemyspeed2);                               // wait 300 mil. sec.
  }
  if ((barrel4.x < 0) && (barrel4.y == platform1))
  {
    barrel4.direction = 270;                           //move in direction 270
    barrel4.x = 6;                             //spawn barrel x position
    barrel4.y = platform3;                             //spawn barrel y position
    delay(enemyspeed2);                                // wait 300 mil. sec.
  }
}





