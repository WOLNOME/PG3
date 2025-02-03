#include <stdio.h>
#include <Windows.h>
#include <random>

typedef void (*PFunc)();

//コールバック関数
void DispResult() {
	printf("抽選結果が出ました\n");
}

void setTimeout(PFunc p, int second) {
	Sleep(second * 1000);

	p();
}

//サイコロ降る関数
int DiceRoller() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(1, 6);

	return dist(gen);
}


int main(void) {
	printf("サイコロをふります。\n");
	printf("出目が奇数か偶数か当ててください。\n");
	printf("奇数なら'1'、偶数なら'2'を入力してください。\n");
	int a;
	scanf_s("%d", &a);
	bool b = false;
	if (a < 1 || a > 2) {
		b = true;
		printf("正しくない値が入力されました。やり直してください。\n");
	}

	if (!b) {
		//サイコロの出目をランダムに出力
		int roll = DiceRoller();

		printf("抽選中・・・\n");

		PFunc p;
		p = DispResult;
		setTimeout(p, 3);

		printf("抽選結果は%dでした！\n", roll);

		if ((roll % 2 == 0 && a == 2) || (roll % 2 == 1 && a == 1)) {
			printf("おめでとうございます！\n");
		}
		else if ((roll % 2 == 0 && a == 1) || (roll % 2 == 1 && a == 2)) {
			printf("残念でした・・・\n");
		}
	}

	return 0;
}