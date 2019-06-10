struct Point
{
  int x{ 0 }, y{ 0 };

  Point(){}
  
  Point(const int x, const int y) : x{x}, y{y} {}
};

struct Line
{
  Point *start, *end;
  
  Line(Point* const start, Point* const end)
    : start(start), end(end)
  {
  }

  ~Line()
  {
    delete start;
    delete end;
  }
  
  Line(const Line& other) 
  {
      start = new Point(*(other.start)); 
      end   = new Point(*(other.end)); 
  }

  Line deep_copy() const
  {
    return Line{*this};
  }
};
