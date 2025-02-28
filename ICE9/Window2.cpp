#include "Shape.h"

// define window class
class Window 
{
public:
  // Upper left (x1, y1), lower right (x2, y2)
  Window(int x1, int y1, int x2, int y2) : isRectangular(true), rect(x2 - x1, y2 - y1), circle(0) {}
  Window(int x1, int y1, int radius) : isRectangular(false), rect(0,0), circle(radius) {}
  double GetDisplayArea() const 
  {
    if (isRectangular)
    {
      return rect.GetArea();
    }
    else
    {
      return circle.GetArea();
    }
  }
  
  // other stuff: drawing, etc
  // skipped: no implementation for now

  // your code here
private:
  bool isRectangular;
  Rectangle rect;
  Circle circle;
};



