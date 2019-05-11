// ConsoleApplication3.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include<iostream>
#include<chrono>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	// ①　コンピュータ、プレイヤーの宣言
	int  computer, player;
	//乱数系列の初期化
	srand(time(NULL));			//sとrand(time(NULL))　NULL文字ってなんだっけ。			

	cout << "0:グー 1:チョキ 2:パー  ";	//""で囲ってる内容は、好きにしていいメッセージ。
	cin >> player;	//代入

	// ②　コンピュータの手をランダム生成
	computer = rand() % 3;		//% ３ は3で割った余り。 rand()で生成かな。３つのうちランダムで出す、ってことか？

	if (player == computer )
	{
		printf("あいこです\n");			//これがC言語的表記の仕方ね。	printf("\n"); 	「\n」は改行
	}
	else if (player == 1 && computer == 2){
		printf("プレイヤーの勝ちです\n");			
	}
	else if (player == 2 && computer == 3){
		printf("プレイヤーの勝ちです\n");
	}
	else if (player == 3 && computer == 1){
		printf("プレイヤーの勝ちです\n");
	}
	else{
		printf("コンピュータの勝ちです\n");
	}

	return 0;
}

