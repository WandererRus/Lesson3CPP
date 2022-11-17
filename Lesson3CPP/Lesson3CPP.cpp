// Lesson3CPP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
using namespace std;
class Point {
private:
        double x;
        double y;
public:
    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    Point() : Point(0, 0) {}

    void remove() 
    {
        x = 0;
        y = 0;
    }
    void display() const
    {
        cout << "Точка с координатами X:" << this->x << " Y:" << this->y << endl;
    }
    void read()
    {
        cout << "Укажите точку X" << endl;
        cin >> this->x;
        cout << "Укажите точку X" << endl;
        cin >> this->y;
    }
    static bool isEqual(const Point& point1, const Point& point2)
    {
        if (point1.x == point2.x && point1.y == point2.y)
        {
            return true;
        }
        else
        {
            return false;
        }
    }    
    static double distance(const Point& point1,const Point& point2)
    {
        return sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2));
    }
    static double length(const Point& point)
    {
        return sqrt(pow(point.x, 2) + pow(point.y, 2));
    }   
    Point operator+(const Point& point2)
    {
        cout << "Унарный" << endl;
        return Point(this->x + point2.x, this->y + point2.y);
    }
    friend Point operator+(const Point& point1, const Point& point2)
    {
        cout << "Бинарный" << endl;
        return Point(point1.x + point2.x, point1.y + point2.y);
    }
    friend Point operator*(const Point& point, double value)
    {
        return Point{ point.x * value, point.y * value };
    }
    friend Point operator*(double value,const Point& point)
    {
        return Point{ point.x * value, point.y * value };
    }
    const Point operator++(int)
    {
        Point point{ x, y }; // создается временный объект
        // с текущими значениями
        ++(*this); // выполняется префиксная перегрузка
        return point; // возвращается временный объект
        // с текущими значениями
    }
    const Point operator--(int)
    {
        Point point{ x, y };
        --(*this);
        return point;
    }
    Point& operator++()
    {
        ++x; ++y; return *this;
    }
    Point& operator--()
    {
        --x; --y; return *this;
    }
    friend bool operator==(const Point& point1,
        const Point& point2)
    {
        return point1.x == point2.x && point1.y == point2.y;
    }
    friend bool operator!=(const Point& point1,
        const Point& point2)
    {
        return !(point1.x == point2.x && point1.y == point2.y);
    }
    friend bool operator>(const Point& point1,
        const Point& point2)
    {
        return length(point1) > length(point2);;
    }

    friend ostream& operator<< (ostream& output, const Point& point)
    {
        output << "(" << point.x << "," << point.y << ")";
        return output;
    }
    friend istream& operator>> (istream& input, Point& point)
    {
        input >> point.x;
        input.ignore(1);
        input >> point.y;
        return input;
    }
    Point& operator= (const Point& point)
    {
        // обходим самокопирование
        if (this == &point)
            return *this;
        // если уже есть значение, то удаляем это значение
        remove();
        // выполняем глубокое копирование
        this->x = point.x;
        this->y = point.y;
        // Возвращаем текущий объект
        return *this;
    }
    //
};



int main()
{
    setlocale(LC_ALL, "");

    Point point1(1, 1);
    Point point2;
    Point point3(1, 1);

    if (Point::isEqual(point1, point3))
    {
        cout << "point1 and point3 are equal" << endl;
    }
    cout << "p1: ";
    point1.display();
    point1++;
    point1.display();
    cout << endl;
    cout << "Enter point p2 in format x,y (e.g. 12,10):";
    point2.read();
    cout << "p2: ";
    point2.display();
    cout << endl;
    cout << "p2 + p1 = ";
    point1 = point1 + point2; 
    point1.display();
    cout << endl;
    cout << point1 << endl;
    (point1 * 5).display();
    cout << "Distance between ";
    point1.display();
    cout << " and ";
    point2 = point3;
    point2.display();
    cout << " is ";
    cout << Point::distance(point1, point2);
    cout << endl;

   
    return 0;   
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
