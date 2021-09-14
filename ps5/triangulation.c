#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void work();
float to_degrees(float radian);
float to_radians(const int angle); //Конвертация градусов в радианы.
float get_watchtowers_distance(const int x1, const int y1, const int x2, const int y2); //Расчёт расстояния между двумя соседними смотровыми башнями.
float get_boat_distance(const float d, const int alpha, const int beta); //Расчёт дистанцию корабля до острова.
void get_ship_coordinates(float *x3, float *y3, const int x1, const int y1, const int x2, const int y2, const int alpha, const int beta);


int main(void)
{
	work();
	return 0;
}

void work()
{
	float Ax, Ay, Bx, By;
	float Cx, Cy;
	int Alpha, Beta;
	scanf("%f", &Ax);	scanf("%f", &Ay);	scanf("%d", &Alpha);
	scanf("%f", &Bx);	scanf("%f", &By);	scanf("%d", &Beta);
	if (((Ax >= 0 && Ax <= 10000) && (Ay >= 0 && Ay <= 10000)) && ((Bx >= 0 && Bx <= 10000) && (By >= 0 && By <= 10000)) && (Alpha > 0 && Alpha < 90) && (Beta > 0 && Beta < 90) && Ay != By)
	{
		get_ship_coordinates(&Cx, &Cy, Ax, Ay, Bx, By, Alpha, Beta);
		printf("%.2f %.2f %.2f\n", get_boat_distance(get_watchtowers_distance(Ax, Ay, Bx, By), Alpha, Beta), Cx, Cy);
	}
	else
	{
		printf("%d\n", -1);
	}
}

float to_radians(const int angle)
{
	if (angle > 0 && angle < 360)
	{
		return angle * M_PI / 180;
	}
	return -1;
}

float get_watchtowers_distance(const int x1, const int y1, const int x2, const int y2)
{
	if (((x1 >= 0 && x1 <= 1000) && (y1 >= 0 && y1 <= 1000)) && ((x2 >= 0 && x2 <= 1000) && (y2 >= 0 && y2 <= 1000)))
	{
		return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	}
	return -1;
}

float get_boat_distance(const float d, const int alpha, const int beta)
{
	if ((d >= 0 && d <= 1000) && (alpha > 0 && alpha < 90) && (beta > 0 && beta < 90))
	{
		return (d * sin(to_radians(alpha)) * sin(to_radians(beta)) / sin(to_radians(180 - alpha - beta)));
	}
	return -1;
}

void get_ship_coordinates(float *x3, float *y3, const int x1, const int y1, const int x2, const int y2, const int alpha, const int beta)
{
	float h, l;
	float a, b;
	l = get_watchtowers_distance(x1, y1, x2, y2);
	h = get_boat_distance(l, alpha, beta);
	a = h / sin(to_radians(alpha));
	b = h / sin(to_radians(beta));
	float W, D;
	if (y1 < y2)
	{
		W = sin(to_radians(alpha) + asin((y2 - y1) / l))*a;
		(*y3) = y1 + W;
		//D = fabs(cos(to_radians(alpha) + asin((y2 - y1) / l)))*a;
		D = sqrt(a*a - W * W);
		if (to_degrees(to_radians(alpha) + asin((y2 - y1) / l)) < 90)
		{
			(*x3) = x1 + D;
		}
		else if (to_degrees(to_radians(alpha) + asin((y2 - y1) / l)) > 90)
		{
			if (x1 < x2)
			{
				(*x3) = x1 - D;
			}
			else {
				(*x3) = x1 + D;
			}
		}
		else
		{
			(*x3) = x1;
		}
	}
	else
	{
		W = sin(to_radians(beta) + asin((y1 - y2) / l))*b;
		(*y3) = y2 + W;
		//D = fabs(cos(to_radians(beta) + asin((y1 - y2) / l)))*b;
		D = sqrt(b*b - W * W);
		if (to_degrees(to_radians(beta) + asin((y1 - y2) / l)) < 90)
		{
			(*x3) = x2 - D;
		}
		else if (to_degrees(to_radians(beta) + asin((y1 - y2) / l)) > 90)
		{
			if (x1 < x2)
			{
				(*x3) = x2 + D;
			}
			else
			{
				(*x3) = x2 - D;
			}
		}
		else
		{
			(*x3) = x2;
		}
		//(*x3) = floorf((*x3) * 100) / 100;
		//(*y3) = floorf((*y3) * 100) / 100;
	}
}

float to_degrees(float radian)
{
	if (radian > 0 && radian < 2 * M_PI)
	{
		return radian * 180 / M_PI;
	}
	return -1;
}