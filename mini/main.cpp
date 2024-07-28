#include "screen.h"
#include <cmath>

void line(Screen& screen, float x1, float y1, float x2, float y2)
{
   float dx = std::abs(x2 - x1);
   float dy = std::abs(y2 - y1);
   float sx = x1 < x2 ? 1 : -1;
   float sy = y1 < y2 ? 1 : -1;
   float err = dx - dy;
   
   while (true) {
     screen.pixel(x1,y1);
     if (x1 == x2 && y1 == y2) break;
     float e2 = err * 2;
     if (e2 > -dy) {
       err -= dy;
       x1 += sx;
     }
     if (e2 < dx) {
       err += dx;
       y1 += sy;
     }
   }
}


int main()
{
  Screen screen;

  for (int i = 0; i < 100; i ++)
  {
    screen.pixel(rand()% 400,rand()% 400);
  }
  line(screen, 100, 100, 300, 300);
  while(true)
  {
    screen.show();
    screen.input();
  }
  return 0;
}
