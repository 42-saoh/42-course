#include <iostream>
#include <cmath>

class Point {
	int x, y;

 public:
	Point(int pos_x, int pos_y)
	{
		x = pos_x;
		y = pos_y;
	}
	const int	Get_x(void) const
	{
		return (x);
	}
	const int	Get_y(void) const
	{
		return (y);
	}
};

class Geometry {
 public:
  Geometry() {
    num_points = 0;
  }

  void AddPoint(const Point &point) {
    point_array[num_points ++] = new Point(point.Get_x(), point.Get_y());
  }

  // 모든 점들 간의 거리를 출력하는 함수 입니다.
  void PrintDistance(void)
  {
	  int i = 0;
	  while (i < num_points - 1)
	  {
		  int j = i + 1;
		  while (j < num_points)
		  {
			  std::cout << "point : [" << point_array[i]->Get_x() << ", " << point_array[i]->Get_y() << "] point : [" \
			  << point_array[j]->Get_x() << ", " << point_array[j]->Get_y() << "] distance : " << get_distance(point_array[i], point_array[j]) << std::endl;
			  j++;
		  }
		  i++;
	  }
  }

  double	get_distance(Point *point1, Point *point2)
  {
	  double x = pow(point1->Get_x() - point2->Get_x(), 2);
	  double y = pow(point1->Get_y() - point2->Get_y(), 2);
	  return (sqrt(x + y));
  }

  void PrintNumMeets()
  {
	  int i = 0;
	  while (i < num_points - 1)
	  {

	  }
  }

  void	get_line_fnc(Point *point1, Point *point2)
  {
	int m;

	if (point1->Get_x() == point2->Get_x())
	{
		a = 1;
		b = 0;
		c = -point1->Get_x();
		return ;
	}
	else if (point1->Get_y() == point2->Get_y())
	{
		a = 0;
		b = 1;
		c = -point1->Get_y();
		return ;
	}
	m = (point2->Get_y() - point1->Get_y()) / (point2->Get_x() - point1->Get_x());
	a = m;
	b = 1;
	c = -point2->Get_y() + (m * point2->Get_x());
  }

  int	is_cross_line(Point *point1, Point *point2)
  {
	  int p1_fx;
	  int p2_fx;

	  p1_fx = a * (point1->Get_x()) + b * (point1->Get_y()) + c;
	  p2_fx = a * (point2->Get_x()) + b * (point2->Get_y()) + c;
	  if (p1_fx * p2_fx <= 0)
		  return (1);
	  else
		  return (0);
  }

private:
	Point* point_array[100];
	int num_points;
	int a;
	int b;
	int c;
};

int main()
{
	Geometry g1;

	g1.AddPoint(Point(1, 3));
	g1.AddPoint(Point(3, 3));
	g1.AddPoint(Point(5, 3));

	g1.PrintDistance();
}
