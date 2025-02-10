#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>

using namespace std;

int main() {
    // ファイル名
    string filename = "PG3_2024_03_02.txt";
    ifstream file(filename);

    if (!file) {
        assert(0 && "ファイルを開けませんでした");
    }

    string line;
    vector<string> emails;

    // ファイルから1行読み込む
    if (getline(file, line)) {
        // 角括弧を削除
        if (!line.empty() && line.front() == '[') line.erase(line.begin());
        if (!line.empty() && line.back() == ']') line.pop_back();

        stringstream ss(line);
        string email;

        // カンマ(,)区切りで分割
        while (getline(ss, email, ',')) {
            // 不要な空白とダブルクォートを削除
            email.erase(remove(email.begin(), email.end(), ' '), email.end());
            email.erase(remove(email.begin(), email.end(), '\"'), email.end());
            emails.push_back(email);
        }
    }

    // ファイルを閉じる
    file.close();

    // 一旦出力
    printf("一旦全要素を出力する\n");
    for (const string& email : emails) {
        printf("%s\n", email.c_str());
    }

    // 昇順に並び替え
    sort(emails.begin(), emails.end());
    printf("昇順に並び替え\n");
    for (const string& email : emails) {
        printf("%s\n", email.c_str());
    }

    return 0;
}
