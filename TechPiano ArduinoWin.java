import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import processing.serial.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class sketch_180314a extends PApplet {



int code = 0;
String str = "";

Serial port;
int[] _color = {0,0,0};

public void setup()
{
  
  port = new Serial(this,"COM11",9600);
}

public void draw()
{
  //if (keyPressed == true)
  if (port.available() > 0)
  {
    str = port.readStringUntil('\n');
    if ((str == "0") || (str == "1"))
    {
      _color[0] = 0;
      _color[1] = 200;
      _color[2] = 0;
      background(_color[0],_color[1],_color[2]);
    } else if ((str == "2") || (str == "3"))
    {
       _color[0] = 200;
      _color[1] = 0;
      _color[2] = 0; 
      background(_color[0],_color[1],_color[2]);
    } else if(str == "4") 
    {
      _color[0] = 0;
      _color[1] = 0;
      _color[2] = 200;
      background(_color[0],_color[1],_color[2]);
    }
    
  }
  background(_color[0],_color[1],_color[2]);
}

public void keyPressed()
{ 
  if (keyPressed == true){
    
  if (key == CODED)
  {
    if ((keyCode == DOWN) || (keyCode == LEFT))
    {
      code = 0;
      _color[0] = 200;
      _color[1] = 0;
      _color[2] = 0;
    } 
    else if ((keyCode == RIGHT) || (keyCode == UP))
    {
      code = 2;
      _color[0] = 0;
      _color[1] = 200;
      _color[2] = 0;
    }
    else if (keyCode == SHIFT)
    {
      code = 4;
      _color[0] = 0;
      _color[1] = 0;
      _color[2] = 200;
    } 
    port.write(code);
  }
  }
  
}
  public void settings() {  size(500,500); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "sketch_180314a" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
