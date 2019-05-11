// ConsoleApplication1.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>	//追加
using namespace std;


//標準出力、スタンダード。　出力先をかえるのがリダイレクション。
int _tmain(int argc, _TCHAR* argv[])
{
	//Cの定義だと0がfalse、それ以外がtrue
	printf("%d\n", 10 != 10);	 //ノットイコールが『!=』

	//↓無限ループはこう
	//for (::)
	//while(1),while(2)
	//while(0)→だとfalseになるからおそらく処理そのものがスルーされる

	//for --を使って10回繰り返し
	//[--]で引き続けると最後は0で止まる.
	for (int i = 10; i > 0; i--)
	{
		cout << i << endl;			//coutで出力、iを出力した後endlで１つずつ改行されてる
	}


	//forで10回繰り返し
	for (int i = 0; i < 20; i = i + 2)
	{
		cout << i << ' ';
	}
	cout << endl;				//わたべぇのやるcout式での『改行コード』


	//whileで10回繰り返し
	
	int a;	//int a = 4でもいける
	a = 8;
	while ( a < 18 )					
	{
		printf("%4d", a);	//aを出力	//sniping tool用：書式指定の関係でずれてる！%2dだから二桁。 0dにしました！4dで半角スペ4個分
		a++;					//while処理に++を追加した場合
	}	printf("\n");


	//while -- で10回繰り返し
	int j = 4;
	while (j-- >1)			//while条件に--を追加した場合
	{
		printf("%d\n", j);	//jを出力
	}


	//doの使い方
	int n = 1;
	do
	{
		printf("%d\n", n);	//★★"\nが改行"を意味する
		n--;
	} while (n > 0);	//doを追加したらちゅうかっこのあとに条件分を追加できる。
	//do whileは、（↑の場合）nを幾らにしても、『最低1回』行われる。
	//2で2回～・・1以下だと1回となる

	return 0;

}

