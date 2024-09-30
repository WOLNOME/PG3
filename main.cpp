#include <stdio.h>
#include <iostream>
#include <Windows.h>

int RecursionNowTime(int recursion, int time) {
	if (time == 1) {
		return recursion;
	}
	else {
		time--;
		return RecursionNowTime(recursion * 2 - 50, time);
	}
}

int RecursionTotal(int recursion, int time) {
	int total = 0;
	if (time == 1) {
		total = recursion;
	}
	else {
		for (int i = time; i > 0; --i) {
			total += RecursionNowTime(recursion, i);
		}
	}
	return total;
}

void Recursive(int general, int recursion, int time) {
	//時間をインクリメント
	time++;

	//現在時間の給与比較
	printf("----------------------------\n");
	printf("現在時間 : %d\n", time);
	printf("一般時間給与 : %d\n", general);
	printf("一般合計給与 : %d\n", general * time);
	printf("再帰時間給与 : %d\n", RecursionNowTime(recursion, time));
	printf("再帰合計給与 : %d\n", RecursionTotal(recursion, time));
	printf("----------------------------\n");
	//再帰合計給与が一般合計給与を下回るなら測定継続
	if (RecursionTotal(recursion, time) < general * time) {
		Recursive(general, recursion, time);
	}
}

int main() {
	//初期値
	int general = 1072;
	int recursion = 100;
	int time = 0;

	Recursive(general, recursion, time);

	return 0;
}