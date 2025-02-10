#include <stdio.h>
#include <Windows.h>
#include <random>
#include <functional>

typedef std::function<void()> FuncType;

void SetTimeout(FuncType p, int second) {
    Sleep(second * 1000);
    p();
}

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

    if (a < 1 || a > 2) {
        printf("正しくない値が入力されました。やり直してください。\n");
        return 1;
    }

    int roll = DiceRoller();
    printf("抽選中・・・\n");

    //ラムダ式の定義
    FuncType resultFunc = [roll, a]() {
        printf("抽選結果が出ました\n");
        printf("抽選結果は%dでした\n", roll);

        if ((roll % 2 == 0 && a == 2) || (roll % 2 == 1 && a == 1)) {
            printf("おめでとうございます！\n");
        }
        else {
            printf("残念でした・・・\n");
        }
        };

    SetTimeout(resultFunc, 3);

    return 0;
}
