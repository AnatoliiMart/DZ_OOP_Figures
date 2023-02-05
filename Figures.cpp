#include<iostream>
#include<cmath>
using namespace std;
class OneSide
{
public:
	OneSide() :side(0.0f) {} 
	OneSide(float Side) :side(Side) {}
	float InputSide()
	{
		
		cout << "Enter size of the side (in sm): ";
		cin >> side;
		return side;
	}
	~OneSide() { cout << "Destruct side" << endl; }
protected:
	float side;
};

class Sqare: public OneSide
{
public:
	void SqarePerimeter()
	{
		perimeter = OneSide::InputSide() * 4;
	}
	void SqareArea()
	{
		area = pow(side, 2);
	}
	void OutputPerimeter()
	{
		cout << "Perimeter of sqare is:\t" << perimeter << " sm" << endl;
	}
	void OutputArea()
	{
		cout << "Area of sqare is:\t" << area << " sm^2" << endl;
	}

	~Sqare() { cout << "Destruct Sqare" << endl; }

protected:
	float perimeter = 0.0f;
	float area = 0.0f;
};

class Triangle:public OneSide
{
public:
	void TrianglePerimeter()
	{
		perimeter = OneSide::InputSide() * 3;
	}
	void TriangleArea()
	{
		float h = sqrt(pow(side, 2) - pow(side / 2, 2));
		area = 0.5 * side * h;
	}
	void OutputPerimeter()
	{
		cout << "Perimeter of triangle is:\t" << perimeter << " sm" << endl;
	}
	void OutputArea()
	{
		cout << "Area of triangle is:\t" << area << " sm^2" << endl;
	}
	~Triangle() { cout << "Destruct Triangle" << endl; }

private:
	float perimeter = 0.0f;
	float area = 0.0f;

};

class Circle:public OneSide
{
public:
	void CirclePerimeter()
	{
		perimeter = 2 * Pi * radius;
	}
	void CircleArea()
	{
		area = Pi * pow(radius, 2);
	}
	void OutputPerimeter()
	{
		cout << "Perimeter of circle is:\t" << perimeter << " sm" << endl;
	}
	void OutputArea()
	{
		cout << "Area of circle is:\t" << area << " sm^2" << endl;
	}

	~Circle() { cout << "Destruct Circle" << endl; }

protected:
	const float Pi = 3.14;
	const float radius = OneSide::InputSide() / 2;
	float area = 0.0f;
	float perimeter = 0.0f;
};

class Rectangle: public OneSide
{
public:
	void RectanglePerimeter()
	{
		perimeter = firstSide * 2 + secondSide * 2;
	}
	void RectangleArea()
	{
		
		area = firstSide * secondSide;
	}
	void OutputPerimeter()
	{
		cout << "Perimeter of rectangle is:\t" << perimeter << " sm" << endl;
	}
	void OutputArea()
	{
		cout << "Area of rectangle is:\t" << area << " sm^2" << endl;
	}

	~Rectangle() { cout << "Destruct Rectangle" << endl; }

private:
	const float firstSide  = OneSide::InputSide();
	const float secondSide = OneSide::InputSide();

	float perimeter = 0.0f; 
	float area = 0.0f;

};

class CircleInSqare:public Circle, public Sqare
{
public:
	void IsInscribed()
	{

		if (Circle::radius == Sqare::InputSide() / 2)
		{
			std::cout << "Circle can be inscribed in sqare!" << endl;
		}
		else
		{
			std::cout << "Circle can't be inscribed in sqare!" << endl;
		}
	}

private:
	
};





int main()
{
	Sqare sqare;
	sqare.SqarePerimeter();
	sqare.SqareArea();
	sqare.OutputArea();
	sqare.OutputPerimeter();
	cout << endl;
	cout << endl;
	cout << endl;
	Triangle triangle;
	triangle.TrianglePerimeter();
	triangle.TriangleArea();
	triangle.OutputArea();
	triangle.OutputPerimeter();
	cout << endl;
	cout << endl;
	cout << endl;
	Circle circle;
	circle.CirclePerimeter();
	circle.CircleArea();
	circle.OutputArea();
	circle.OutputPerimeter();
	cout << endl;
	cout << endl;
	cout << endl;
	Rectangle rectangle;
	rectangle.RectanglePerimeter();
	rectangle.RectangleArea();
	rectangle.OutputArea();
	rectangle.OutputPerimeter();
	cout << endl;
	cout << endl;
	cout << endl;
	CircleInSqare res;
	res.IsInscribed();
	return 0;
}
