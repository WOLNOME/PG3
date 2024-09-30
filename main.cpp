#include <stdio.h>
#include <iostream>
#include <Windows.h>

template <typename T>
T Min(T a, T b) { return min(a, b); }
template <>
char Min<char>(char a, char b) {return ' '; }

int main() {
	int a = 0;
	int b = 1;
	float c = 2.3f;
	float d = 4.5f;
	double e = 6.7;
	double f = 8.9;
	char g = 'a';
	char h = 'b';
	printf("%d\n", Min<int>(a, b));
	printf("%f\n", Min<float>(c, d));
	printf("%lf\n", Min<double>(e, f));
	printf("数字以外は代入できません%c\n", Min<char>(g, h));


	return 0;
}