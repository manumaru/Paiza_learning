#include "HelloWorldScene.h"
#include "SecondScene.h"
//音をならすためにinclude
#include "SimpleAudioEngine.h"

USING_NS_CC;


//	/2で画像の真ん中から座標を初めて接触判定を決める
//始めるっつーかその画像を2分割して左から1個目がおわったとこ　■|■
//だから1/3だと　■|■■ここにくる。左の3つの■と↑の2つの■は同じ1つの□のなかを違うサイズで分割してる

Scene* HelloWorld::createScene()
{
	// シーンをオート生成。
	auto scene = Scene::create();

	// レイヤーを生成。
	auto layer = HelloWorld::create();

	// シーンに「子」としてレイヤーを追加。		？
	scene->addChild(layer);

	// 戻る。									？
	return scene;
}

//シーン名::initで関数を宣言。
bool HelloWorld::init()
{
	//////////////////////////////			←これは？？
	// 1. super init first			最初の超init	?
	if (!Layer::init())
	{
		return false;
	}

	// プレイヤーの設置。
	this->addPlayer();
	// ボタンの設置。
	this->addButton();

	// バックグラウンド。													tuika
	makeBackground();

	// 画面サイズを取得。
	Size winSize = Director::getInstance()->getWinSize();

	// スタートボタンを設置。
	auto startButton = MenuItemImage::create(
		"aiee.png",  // 通常状態の画像。
		"aiee2.png",  // 押下状態の画像。										MenuItemImageで通常時と押してる時の２つを一気に指定可能？ただしボタンの画像じゃなくてボタンで動かす方の画像
		CC_CALLBACK_1(HelloWorld::pushStart, this)); // 押下時のアクション。
	// ボタンの設置。
	startButton->setPosition(Point(winSize.width / 3, winSize.height / 2));

	// メニューを作成 自動解放オブジェクト。										自動解放オブジェクト？
	auto menu = Menu::create(startButton, NULL);
	//メニューの配置																	0,0と一緒
	menu->setPosition(Point::ZERO);
	// メニューを追加。
	this->addChild(menu, 1);

	return true;
}

//背景のクラス。
void HelloWorld::makeBackground()
{

	// 画面サイズを取得。
	Size winSize = Director::getInstance()->getWinSize();
	//マルチレゾリューション対応がどうとか
	Point origin = Director::getInstance()->getVisibleOrigin();

	// バックグランドカラー
	auto background = LayerColor::create(Color4B::GREEN,
		winSize.width,
		winSize.height);
	// バックグランドカラー。 第2引数は表示順。
	this->addChild(background, -1);						//0だと見えないのがあったりしたので、-1にしました！

	// タイトルを設置
	auto lbl_title = Label::createWithSystemFont
		("Splatooooon", "Segoe Script", 100);
	lbl_title->setPosition(Point(origin.x + winSize.width / 2,
		origin.y + winSize.height
		- lbl_title->getContentSize().height));
	// ラベルタイトルを追加。
	this->addChild(lbl_title, 1);
}

//シーン遷移 （pushStartボタン）
void HelloWorld::pushStart(Ref *pSender)
{
	//ログを出力
	CCLOG("Pushボタン");

	// 効果音を鳴らす
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("uni15.wav");

	// 遷移先の画面のインスタンス
	Scene *pScene = SecondScene::createScene();

	// 0.5秒かけてフェードアウトしながら次の画面に遷移します。
	//    引数１:フィードの時間
	//    引数２：移動先のシーン
	//    引数３：フィードの色（オプション）
	TransitionFade* transition = TransitionFade::create(0.5f, pScene);

	// 遷移実行  遷移時のアニメーション
	// 直前のsceneはもう使わないから捨ててしまう方法。基本はこれらしい。
	Director::getInstance()->replaceScene(transition);
}



// プレイヤーの設置。
void HelloWorld::addPlayer(){
	// 画面サイズ取得。
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// プレイヤー作成。
	_player1 = Sprite::create("natsu.png");
	_player2 = Sprite::create("jotaro.png");

	// プレイヤーの設置場所。
	_player1->setPosition(Vec2(visibleSize.width / 4, visibleSize.height / 2));
	_player2->setPosition(Vec2(visibleSize.width / 4 * 3, visibleSize.height / 2));

	// プレイヤーのアンカーポイント（基準点）。真ん中中央下と、0.4&0.6に指定。					//変更ゥゥゥゥゥゥゥゥゥ
	_player1->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
	_player2->setAnchorPoint(Vec2(0.4, 0.6));

	// プレイヤーの貼り付け。
	this->addChild(_player1);																	//子供に加えるとなにができるようになる？
	this->addChild(_player2);
}

void HelloWorld::addButton(){
	// 画面サイズ取得。
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// ボタンを押した時、離した時の画像を設定。ラムダという概念で処理を記述　[](Ref* ref){ }
	auto PlayButton1 = MenuItemImage::create("GODDESS.png", "GODDESS2.png", [](Ref* ref){
		// ボタンを押した時の処理。今回は押した時、離した時どちらもアクションを設定するのでここでは処理を書かない
	});

	auto PlayButton2 = MenuItemImage::create("zoi.png", "zoi2.png", [](Ref* ref){
		// ボタンを押した時の処理。今回は押した時、離した時どちらもアクションを設定するのでここでは処理を書かない
	});

	// ボタンの設置場所。
	PlayButton1->setPosition(Vec2(visibleSize.width / 6.0, visibleSize.height / 8.0));
	PlayButton2->setPosition(Vec2(visibleSize.width / 6.0 * 5.0, visibleSize.height / 8.0));							//*　5.0　って書いてなんかきれいな割合の配置になってる？

	// MenuItemImageで作られたボタンからメニューを作成。
	auto menu1 = Menu::create(PlayButton1, NULL);
	auto menu2 = Menu::create(PlayButton2, NULL);
	// 基準点を0。
	menu1->setPosition(Point::ZERO);
	menu2->setPosition(Point::ZERO);
	// ボタン貼り付け。（メニュー貼り付け）
	this->addChild(menu1);
	this->addChild(menu2);


	// タッチイベント
	// 左のボタン
	auto listener1 = EventListenerTouchOneByOne::create();
	// ラムダを使用して関数内にonTouchBeganとonTouchEndedを実装する。																	Ramda?
	listener1->onTouchBegan = [this, visibleSize, PlayButton1](Touch* touch, Event* event){
		// タッチされたボタンが左かどうか判別している。これがないと複数のイベントリスナーが実行されてしまう。
		Vec2 point1 = touch->getLocation();                 // タッチしたポイント。														Vec2?
		Rect rectButton1 = PlayButton1->getBoundingBox();   // ボタン画像の範囲。
		if (rectButton1.containsPoint(point1)) {            // ボタン画像の範囲内をタッチした場合。
			// タッチされた時の処理。
			auto sprite_pose1_1 = Sprite::create("natsu2.png");																//新しい画像を、元の画像の大きさと位置に代入？
			auto sprite_pose1_1_size = sprite_pose1_1->getContentSize();
			auto poseRect = Rect(0, 0, sprite_pose1_1_size.width, sprite_pose1_1_size.height);
			auto poseFrame = SpriteFrame::create("natsu2.png", poseRect);														//この2行がイマイチ
			_player1->setSpriteFrame(poseFrame);
			return true;
		}
		else{
			return false;
		}

	};

	listener1->onTouchEnded = [this](Touch* touch, Event* event){
		// タッチ終了時の処理。（指を離した時）
		auto sprite_pose1_1 = Sprite::create("natsu.png");
		auto sprite_pose1_1_size = sprite_pose1_1->getContentSize();
		auto poseRect1 = Rect(0, 0, sprite_pose1_1_size.width, sprite_pose1_1_size.height);
		auto poseFrame1 = SpriteFrame::create("natsu.png", poseRect1);
		_player1->setSpriteFrame(poseFrame1);
	};

	// listener1, PlayButton1をイベント登録する。
	auto director = Director::getInstance();
	director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener1, PlayButton1);



	// 右のボタン
	auto listener2 = EventListenerTouchOneByOne::create();
	// ラムダを使用して関数内にonTouchBeganとonTouchEndedを実装する。
	listener2->onTouchBegan = [this, visibleSize, PlayButton2](Touch* touch, Event* event){
		// タッチされたボタンが右かどうか判別している。これがないと複数のイベントリスナーが実行されてしまう。
		Vec2 point2 = touch->getLocation();                 // タッチしたポイント。
		Rect rectButton2 = PlayButton2->getBoundingBox();   //　ボタン画像の範囲。
		if (rectButton2.containsPoint(point2)) {            // ボタン画像の範囲内をタッチした場合。
			// タッチされた時の処理。
			auto sprite_pose1_2 = Sprite::create("jotaro2.png");
			auto sprite_pose1_2_size = sprite_pose1_2->getContentSize();
			auto poseRect = Rect(0, 0, sprite_pose1_2_size.width, sprite_pose1_2_size.height);
			auto poseFrame = SpriteFrame::create("jotaro2.png", poseRect);
			_player2->setSpriteFrame(poseFrame);
			return true;
		}
		else{
			return false;
		}

	};

	listener2->onTouchEnded = [this](Touch* touch, Event* event){
		// タッチ終了時の処理。（指を離した時）
		auto sprite_pose1_2 = Sprite::create("jotaro.png");
		auto sprite_pose1_2_size = sprite_pose1_2->getContentSize();
		auto poseRect2 = Rect(0, 0, sprite_pose1_2_size.width, sprite_pose1_2_size.height);
		auto poseFrame2 = SpriteFrame::create("jotaro.png", poseRect2);
		_player2->setSpriteFrame(poseFrame2);
	};

	// listener2, PlayButton2をイベント登録する。
	director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener2, PlayButton2);


}
