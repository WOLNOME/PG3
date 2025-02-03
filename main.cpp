#include <stdio.h>
#include <string>
#include <chrono>
#include <utility>

int main() {
	//元となる文字列
	std::string a(100000, 'a');

	printf("100,000文字を移動とコピーで比較しました。\n");

	//コピー計測開始
	auto copyStart = std::chrono::high_resolution_clock::now();
	//コピー処理
	std::string b = a;
	//コピー計測終了
	auto copyEnd = std::chrono::high_resolution_clock::now();
	//計測時間を表示
	auto copyDuration = std::chrono::duration_cast<std::chrono::microseconds>(copyEnd - copyStart);
	printf("コピー : %dμs\n", (int)copyDuration.count());
	//移動計測開始
	auto moveStart = std::chrono::high_resolution_clock::now();
	//移動処理
	std::string c = std::move(a);
	//移動計測終了
	auto moveEnd = std::chrono::high_resolution_clock::now();
	//計測時間を表示
	auto moveDuration = std::chrono::duration_cast<std::chrono::microseconds>(moveEnd - moveStart);
	printf("移動 : %dμs\n", (int)moveDuration.count());


	return 0;
}
