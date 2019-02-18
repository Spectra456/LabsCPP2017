#include <vector>
#include <list>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <numeric>

struct Point
{
  int x,y;

  friend std::ostream& operator<<(std::ostream& output, const Point& obj)
  {
    output <<"  (" <<obj.x <<"; " <<obj.y <<")";
    return output;
  }
};

using Shape = std::vector< Point >;

bool isSquare(const Shape& rect)
{
  if (rect.size() != 4)
  {
    return false;
  }

  if (rect[1].x != rect[0].x)
  {
    if (std::abs(rect[1].x - rect[0].x) != std::abs(rect[2].y - rect[1].y))
    {
      return false;
    }
  }
  else
  {
    if (std::abs(rect[2].x - rect[1].x) != std::abs(rect[1].y - rect[0].y))
    {
      return false;
    }
  }
  return true;
}

bool isNum(const std::string& strnum)
{
  char * Error;
  strtol(strnum.c_str(), &Error, 10);

  if (*Error != '\0' && !isspace(*Error))
  {
    return false;
  }

  return true;
}

void readCoords(Shape& targetShape, std::istream& input)
{
  std::string Buf;
  std::getline(input, Buf);
  Buf.erase(std::remove(Buf.begin(), Buf.end(), ')'), Buf.end());
  Buf.erase(std::remove(Buf.begin(), Buf.end(), ';'), Buf.end());
  Buf.erase(std::remove(Buf.begin(), Buf.end(), '('), Buf.end());

  while (!Buf.empty())
  {
    if (std::all_of(Buf.begin(), Buf.end(), isspace))
    {
      break;
    }

    size_t* Error = new size_t(0);
    try
    {
      int X = stoi(Buf, Error);
      Buf.erase(0, *Error);

      int Y = stoi(Buf, Error);
      Buf.erase(0, *Error);

      targetShape.push_back({X, Y});
    }
    catch (std::invalid_argument)
    {
      delete Error;
      throw;
    }

    delete Error;
  }
}

int part_2()
{
  std::list<Shape> Shapes;

  while (std::cin)
  {
    std::string StringVertices;

    std::cin >> StringVertices;
    if (std::cin.eof())
    {
      break;
    }

    if (!isNum(StringVertices))
    {
      std::cerr <<"Wrong number of Vertices" <<std::endl;
      return 1;
    }
    size_t ShapeVertices = stoi(StringVertices);

    Shape NewShape;
    try
    {
      readCoords(NewShape, std::cin);
    }
    catch (std::invalid_argument)
    {
      std::cerr <<"Invalid coords" <<std::endl;
      return 1;
    }

    if (NewShape.size() != ShapeVertices)
    {
      std::cerr <<"Wrong number of Vertices" <<std::endl;
      return 1;
    }

    Shapes.push_back(NewShape);
  }


  std::size_t CountFigures[3]= {0,0,0};

  size_t Vertices = std::accumulate(Shapes.begin(), Shapes.end(), size_t(0), [](size_t& sum, const Shape& obj)
                                                                        {
                                                                          return sum += obj.size();
                                                                        });

  CountFigures[0] = std::count_if(Shapes.begin(), Shapes.end(), [](const Shape& obj)
                                                                  {
                                                                    return obj.size() == 3;
                                                                  });
  CountFigures[1] = std::count_if(Shapes.begin(), Shapes.end(), &isSquare);

  CountFigures[2] = std::count_if(Shapes.begin(), Shapes.end(), [](const Shape& obj)
                                                                  {
                                                                    return obj.size() == 4;
                                                                  });

  Shapes.remove_if([](const Shape& obj)
                     {
                       return obj.size() == 5;
                     });

  std::vector< Point > Points;

  std::for_each(Shapes.begin(), Shapes.end(), [&Points](const std::vector<Point>& p)
                                                       {
                                                         Points.push_back(p[0]);
                                                       });
  std::list<Shape>::iterator Edge2 = std::stable_partition(Shapes.begin(), Shapes.end(), [](const Shape& obj)
                                                                                           {
                                                                                             return obj.size() < 5;
                                                                                           });
  std::list<Shape>::iterator Edge1 = std::stable_partition(Shapes.begin(), Edge2,[](const Shape& obj)
                                                                                   {
                                                                                     return obj.size() == 3;
                                                                                   });
  std::stable_partition(Edge1, Edge2, [](const Shape& obj)
                                        {
                                          if (isSquare(obj))
                                          {
                                            return true;
                                          }
                                          return false;
                                        });

  std::cout <<"Vertices: " <<Vertices <<std::endl;
  std::cout <<"Triangles: " <<CountFigures[0] <<std::endl;
  std::cout <<"Squares: " <<CountFigures[1] <<std::endl;
  std::cout <<"Rectangles: " <<CountFigures[2] <<std::endl;

  std::cout <<"Points:";
  std::copy(Points.begin(), Points.end(), std::ostream_iterator<Point>(std::cout));
  std::cout <<std::endl;

  std::cout <<"Shapes:" <<std::endl;

  std::for_each(Shapes.begin(), Shapes.end(), [](const Shape& Cur)
                                                {
                                                  std::cout <<Cur.size();
                                                  std::copy(Cur.begin(), Cur.end(), std::ostream_iterator<Point>(std::cout));
                                                  std::cout <<std::endl;
                                                });
  return 0;
}
