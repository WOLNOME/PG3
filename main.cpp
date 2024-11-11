#include <stdio.h>
#include <iostream>
#include <Windows.h>

template <typename T>
class Comparison
{
public:
	T s1;
	T s2;

	Comparison(T s1, T s2) : s1(s1), s2(s2) {}

	T Min() {
		if (s1 < s2) {
			return s1;
		}
		else {
			return s2;
		}
	}

};

int main() {
	//数値定義
	Comparison<int> c1(10, 20);
	Comparison<float> c2(3.3f, 4.0f);
	Comparison<double> c3(1.2, 3.4);

	//出力
	printf("int : %d\n", c1.Min());
	printf("float : %f\n", c2.Min());
	printf("double : %lf\n", c3.Min());

	return 0;
}