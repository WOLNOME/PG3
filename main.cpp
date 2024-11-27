#include <stdio.h>
#include <iostream>
#include <list>

int main() {
	//リスト
	std::list<const char*> yamanotesen;
	//1970年の駅名を保存
	yamanotesen.push_back("Tokyo");
	yamanotesen.push_back("Kanda");
	yamanotesen.push_back("Akihabara");
	yamanotesen.push_back("Okachimachi");
	yamanotesen.push_back("Ueno");
	yamanotesen.push_back("Uguisudani");
	yamanotesen.push_back("Nippori");
	//yamanotesen.push_back("Nishi-Nippori");
	yamanotesen.push_back("Tabata");
	yamanotesen.push_back("Komagome");
	yamanotesen.push_back("Sugamo");
	yamanotesen.push_back("Otsuka");
	yamanotesen.push_back("Ikebukuro");
	yamanotesen.push_back("Mejiro");
	yamanotesen.push_back("Takadanobaba");
	yamanotesen.push_back("Shin-Okubo");
	yamanotesen.push_back("Shinjuku");
	yamanotesen.push_back("Yoyogi");
	yamanotesen.push_back("Harajuku");
	yamanotesen.push_back("Shibuya");
	yamanotesen.push_back("Ebisu");
	yamanotesen.push_back("Meguro");
	yamanotesen.push_back("Gotanda");
	yamanotesen.push_back("Osaki");
	yamanotesen.push_back("Shinagawa");
	//yamanotesen.push_back("Takanawa Gateway");
	yamanotesen.push_back("Tamachi");
	yamanotesen.push_back("Hamamatsucho");
	yamanotesen.push_back("Shimbashi");
	yamanotesen.push_back("Yurakucho");
	//表示
	printf("1970\n");
	for (std::list<const char*>::iterator it = yamanotesen.begin(); it != yamanotesen.end(); ++it) {
		if (*it == "Yurakucho") {
			printf("%s\n", *it);
		}
		else {
			printf("%s,", *it);
		}
		
	}
	//西日暮里を挿入
	for (std::list<const char*>::iterator it = yamanotesen.begin(); it != yamanotesen.end(); ++it) {
		if (*it == "Tabata") {
			it = yamanotesen.insert(it, "Nishi-Nippori");
			++it;  // 挿入後の位置を調整
		}
	}
	//表示
	printf("2019\n");
	for (std::list<const char*>::iterator it = yamanotesen.begin(); it != yamanotesen.end(); ++it) {
		if (*it == "Yurakucho") {
			printf("%s\n", *it);
		}
		else {
			printf("%s,", *it);
		}
	}
	//高輪ゲートウェイを挿入
	for (std::list<const char*>::iterator it = yamanotesen.begin(); it != yamanotesen.end(); ++it) {
		if (*it == "Tamachi") {
			it = yamanotesen.insert(it, "Takanawa Gateway");
			++it;  // 挿入後の位置を調整
		}
	}
	//表示
	printf("2022\n");
	for (std::list<const char*>::iterator it = yamanotesen.begin(); it != yamanotesen.end(); ++it) {
		if (*it == "Yurakucho") {
			printf("%s\n", *it);
		}
		else {
			printf("%s,", *it);
		}
	}






	return 0;
}
