#pragma once
class Enemy
{
public://メンバ関数
	//接近
	void Approach();
	//射撃
	void Shooting();
	//離脱
	void Withdrawal();

	//更新
	void Update();
private://メンバ関数ポインタテーブル
	static void (Enemy::* functionTable[])();
};

