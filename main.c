#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;
 
  
  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = 0;
  
  clear_screen(s);

	/*
  //octant 1
  draw_line( 0, 0, XRES-1, YRES - 75, s, c);
  //octant 2
  draw_line( 0, 0, XRES - 75, YRES-1, s, c); 
  //octant 8
  draw_line( 0, YRES-1, XRES-1, 75, s, c);  
  //octant 7
  draw_line( 0, YRES-1, XRES - 75, 0, s, c);
  c.green = 0;
  c.blue = MAX_COLOR;
  //octant 5
  draw_line( XRES - 1, YRES - 1, 0, 75, s, c);
  //octant 6
  draw_line( XRES - 1, YRES -1, 75, 0, s, c);
  //octant 4
  draw_line( XRES - 1, 0, 0, YRES - 75, s, c);
  //octant 3
  draw_line( XRES - 1, 0, 75, YRES - 1, s, c);
  
  c.blue = 0;
  c.red = MAX_COLOR;
  //y = x, y = -x
  draw_line( 0, 0, XRES - 1, YRES - 1, s, c);
  draw_line( 0, YRES - 1, XRES - 1, 0, s, c);

  //horizontal, vertical line
  draw_line( 0, YRES / 2, XRES - 1, YRES / 2, s, c);
  draw_line( XRES / 2, 0, XRES / 2, YRES - 1, s, c);
  */
  int x, y;
  for (x = 0; x <= 500; x+=5){
  	for (y = 500; y >= 0; y-=12){
    	int x2 = (int)(x * cos(x * y) / 2) % 500;
    	int y2 = (int)(y * sin(y * x) / 2) % 500;
      int g = (int)floor((cos(3 * x2) * cos(3 * x2) + sin(5 * y2) + sin(5 * y2)) * 255);
 			c.green = abs(g) % 255;
 			c.red = c.green / 2;
 			c.blue = c.green / 2;
     	draw_line(x, y, x2, y2, s, c); 
    }
  }
  for (x = 500; x >= 0; x-=52){
  	for (y = 0; y <= 500; y+=39){
    	int x2 = (int)(x * tan(x * y) / 2) % 500;
    	int y2 = (int)(y * tan(y * x) / 2) % 500;
      int g = (int)floor((cos(3 * x2) * cos(3 * x2) + sin(5 * y2) + sin(5 * y2)) * 255);
 			c.blue = abs(g) % 255;
 			c.green = c.blue / 2;
 			c.red = c.blue / 2;
     	draw_line(x, y, x2, y2, s, c); 
    }
  }
  for (x = 450; x >= 210; x-=52){
  	for (y = 170; y <= 395; y+=39){
    	int x2 = (int)(x * cos(x * y) / 2) % 500;
    	int y2 = (int)(y * cos(y * x) / 2) % 500;
      int g = (int)floor((cos(3 * x2) * cos(3 * x2) + sin(5 * y2) + sin(5 * y2)) * 255);
 			c.red = abs(g) % 255;
 			c.green = c.red / 2;
 			c.blue = c.red / 2;
     	draw_line(x, y, x2, y2, s, c); 
    }
  }
  for (x = 413; x >= 22; x-=41){
  	for (y = 64; y <= 310; y+=37){
    	int x2 = (int)(x * sin(x * y) / 2) % 500;
    	int y2 = (int)(y * tan(y * x) / 3) % 500;
      int g = (int)floor((cos(3 * x2) * cos(3 * x2) + sin(5 * y2) + sin(5 * y2)) * 255);
 			c.red = abs(g) % 255;
 			c.green = c.red / 2;
 			c.blue = c.red / 2;
     	draw_line(x, y, x2, y2, s, c); 
    }
  }
  
  //display(s);
  save_extension(s, "lines.png");
}  
