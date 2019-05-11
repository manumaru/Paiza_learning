// ConsoleApplication1.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>	//追加
using namespace std;


//標準出力、スタンダード。　出力先をかえるのがリダイレクション。
int _tmain(int argc, _TCHAR* argv[])
{
	float height, weight, bmi;
	cout << "height(cm):";
	cin >> height;
	cout << "weight(kg):";
	cin >> weight;
	height /= 100; //評価して	[Reバリエイト]
	bmi = weight / (height * height);
	cout << bmi << endl;

	///3種類（C++,C言語,）
	//19.5未満が「干からびてる」
	//25.0以上が「死んでる」
	//19.5以上25,0未満が「正常」

	/*if (bmi < 19.5f){			//fを加えて『float』型にしないと元々『double』型。 Unityだと19.5fにしなきゃ怒られる。
		cout << "干からびてる" << endl;	//C++的に表記	endlと/nはどちらも『改行』を意味
	}
	else if ( bmi >=25.0f ){			
		printf("死んでる\n");			//C言語的に表記するならprint f
	}
	else	{
		cout << "正常\n";				//C++的に表記
	}
	*/

	//★★★★C言語の文字列はどうなんだろね・・？まだわかんないや

	//↓文字列。C++での文字列を扱うときのベーシックなやり方。後から追加する時に便利
	string s;
	if (bmi < 19.5f) s = "痩せ過ぎ";
	else if (bmi < 25.0f) s = "ふつう";
	else s = "太り過ぎ";
	cout << s.c_str() << endl;	//"s/c_str"の部分は　string的なものをC言語的なものに変換するものだと捉えとけばおｋ

	//cout << "hello" << endl;
	//↑同じ意味↓だけど違う記述の仕方
	//	cout << "hello\n";			//C言語的にいくならprint f

	return 0;

	//Cの定義だと0がfalse、それ以外がtrue
}

