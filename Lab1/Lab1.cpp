#include <iostream>
#include <locale.h>
using namespace std;

double CorrectInput(double &value);

int main()
{
	setlocale(LC_ALL,"RUS");
	cout << "Вариант 9. ИКБО-02-18. Шошников Иван\n";
	double x, y, radius, sideY,sideX;
	bool flag = false;

	cout << "Введите координаты точки Х и Y\n";
	CorrectInput(x);
	CorrectInput(y);
	cout << "Координаты точки X: " << x << " Y: " << y << endl;

	cout << "Введите радиус окружности и стороны прямоугольника, причем радиус должен быть больше обеих сторон\n";
	while (!flag) 
	{
		CorrectInput(radius);
		CorrectInput(sideY);
		CorrectInput(sideX);
		if (radius > sideY && radius > sideX)
			flag = !flag;
		else
			cout << "радиус должен быть больше обеих сторон\n";
	}
	cout << "Радиус: " << radius << " Сторона прямоугольника Х: " << sideX << " Сторона прямоугольника Y: " << sideY << endl;

	if (y > 0 && y < radius && abs(x) <= radius || y < 0 && y > sideY && abs(x) < sideX/2)
		cout << "Точка попадает в область\n";
	else 
		cout << "Точка не попадает в область\n";
}

double CorrectInput(double &value)
{
	char fail;
	cin >> value;
	while (cin.fail()) 
	{
		cout << "Данные некорректны\n";
		cin.clear();
		cin >> fail;
		cin >> value;
	}
	return value;
}
