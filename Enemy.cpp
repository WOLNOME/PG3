#include "Enemy.h"
#include "stdio.h"

void (Enemy::* Enemy::functionTable[])() = {
	&Enemy::Approach,
	&Enemy::Shooting,
	&Enemy::Withdrawal
};

void Enemy::Approach()
{
	//接近コメント
	printf("Enemy Approach\n");
}

void Enemy::Shooting()
{
	//射撃コメント
	printf("Enemy Shooting\n");
}

void Enemy::Withdrawal()
{
	//離脱コメント
	printf("Enemy Withdrawal\n");
}

void Enemy::Update()
{
	//現在フェーズの関数を実行
	for (int phase = 0; phase < 3; phase++) {
		(this->*functionTable[static_cast<size_t>(phase)])();
	}

}


