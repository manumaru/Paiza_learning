#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class HelloWorld : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer					クラスを生成？
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone		既存のinitとの競合を避けるタメ？
	virtual bool init();

	// オリジナルメソッド。init()内の見通しをよくするためにプレイヤーとボタンの作成を別関数とする。
	void addPlayer();
	void addButton();


	// implement the "static create()" method manually						関数追加？？
	CREATE_FUNC(HelloWorld);

	//背景を宣言。
	void makeBackground();

	// スタートボタン押下時の処理宣言。 戻る Object →　Ref に変更					ん？
	void pushStart(Ref *pSender);


	// プレイヤーのプロパティ宣言。
	CC_SYNTHESIZE_RETAIN(cocos2d::Sprite*, _player1, Player1);
	CC_SYNTHESIZE_RETAIN(cocos2d::Sprite*, _player2, Player2);
};

#endif // __HELLOWORLD_SCENE_H__