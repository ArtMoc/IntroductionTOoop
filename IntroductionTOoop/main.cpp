#include <iostream>
using namespace std;

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//                Constructors:
	Point()
	{
		x = 0;
		y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//               Operators:
	void operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopeAssigment:\t\t" << this << endl;
	}

	//                Methods:
	double distance(Point other)
	{
		/*double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;*/
		return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
		//pow - ���������� � �������
		//sqrt - Square Root - ���������� ������ 
	}
	void print()const
	{
		cout << "X = " << x << "\t" << "Y = " << y << endl;
	}
};

double distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}

//#define STRUCT_POINT
//#define DISTANCE

void main()
{
	setlocale(LC_ALL, "");

#ifdef STRUCT_POINT
	int a;  //���������� ���������� "�" ���� int
	Point A;//���������� ���������� "�" ���� Point
			//���������� ���������� "�" ��������� Point
			//���������� ������� "�" ��������� Point
			//�������� ������� "�" ��������� Point
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT


#ifdef DISTANCE
	Point A; //Default constructor
	A.print();
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();
	Point B;
	B.set_x(3);
	B.set_y(4);
	cout << B.get_x() << "\t" << B.get_y() << endl;

	cout << "������ �������: " << sizeof(B) << " ����" << endl;
	cout << "���������� �� ����� � �� ����� �: " << A.distance(B) << endl;
	cout << "���������� �� ����� B �� ����� A: " << B.distance(A) << endl;
	cout << "���������� ����� ������� � � �:   " << distance(A, B) << endl;
	cout << "���������� ����� ������� B � A:   " << distance(B, A) << endl;
#endif // DISTANCE

	Point A; //Default constructor
	cout << "Point A: "; A.print();

	Point B(2, 3);
	cout << "Point B: "; B.print();

	Point C = B; //Copy constructor
	cout << "Point C: "; C.print();

	Point D;
	D = B; //Cope assigment - �������� ������������
	cout << "Point D: "; D.print();

}