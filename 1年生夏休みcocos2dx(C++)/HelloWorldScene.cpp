#include "HelloWorldScene.h"
#include "SecondScene.h"
//�����Ȃ炷���߂�include
#include "SimpleAudioEngine.h"

USING_NS_CC;


//	/2�ŉ摜�̐^�񒆂�����W�����߂ĐڐG��������߂�
//�n�߂���[�����̉摜��2�������č�����1�ڂ���������Ƃ��@��|��
//������1/3���Ɓ@��|���������ɂ���B����3�́��Ɓ���2�́��͓���1�́��̂Ȃ����Ⴄ�T�C�Y�ŕ������Ă�

Scene* HelloWorld::createScene()
{
	// �V�[�����I�[�g�����B
	auto scene = Scene::create();

	// ���C���[�𐶐��B
	auto layer = HelloWorld::create();

	// �V�[���Ɂu�q�v�Ƃ��ă��C���[��ǉ��B		�H
	scene->addChild(layer);

	// �߂�B									�H
	return scene;
}

//�V�[����::init�Ŋ֐���錾�B
bool HelloWorld::init()
{
	//////////////////////////////			������́H�H
	// 1. super init first			�ŏ��̒�init	?
	if (!Layer::init())
	{
		return false;
	}

	// �v���C���[�̐ݒu�B
	this->addPlayer();
	// �{�^���̐ݒu�B
	this->addButton();

	// �o�b�N�O���E���h�B													tuika
	makeBackground();

	// ��ʃT�C�Y���擾�B
	Size winSize = Director::getInstance()->getWinSize();

	// �X�^�[�g�{�^����ݒu�B
	auto startButton = MenuItemImage::create(
		"aiee.png",  // �ʏ��Ԃ̉摜�B
		"aiee2.png",  // ������Ԃ̉摜�B										MenuItemImage�Œʏ펞�Ɖ����Ă鎞�̂Q����C�Ɏw��\�H�������{�^���̉摜����Ȃ��ă{�^���œ��������̉摜
		CC_CALLBACK_1(HelloWorld::pushStart, this)); // �������̃A�N�V�����B
	// �{�^���̐ݒu�B
	startButton->setPosition(Point(winSize.width / 3, winSize.height / 2));

	// ���j���[���쐬 ��������I�u�W�F�N�g�B										��������I�u�W�F�N�g�H
	auto menu = Menu::create(startButton, NULL);
	//���j���[�̔z�u																	0,0�ƈꏏ
	menu->setPosition(Point::ZERO);
	// ���j���[��ǉ��B
	this->addChild(menu, 1);

	return true;
}

//�w�i�̃N���X�B
void HelloWorld::makeBackground()
{

	// ��ʃT�C�Y���擾�B
	Size winSize = Director::getInstance()->getWinSize();
	//�}���`���]�����[�V�����Ή����ǂ��Ƃ�
	Point origin = Director::getInstance()->getVisibleOrigin();

	// �o�b�N�O�����h�J���[
	auto background = LayerColor::create(Color4B::GREEN,
		winSize.width,
		winSize.height);
	// �o�b�N�O�����h�J���[�B ��2�����͕\�����B
	this->addChild(background, -1);						//0���ƌ����Ȃ��̂��������肵���̂ŁA-1�ɂ��܂����I

	// �^�C�g����ݒu
	auto lbl_title = Label::createWithSystemFont
		("Splatooooon", "Segoe Script", 100);
	lbl_title->setPosition(Point(origin.x + winSize.width / 2,
		origin.y + winSize.height
		- lbl_title->getContentSize().height));
	// ���x���^�C�g����ǉ��B
	this->addChild(lbl_title, 1);
}

//�V�[���J�� �ipushStart�{�^���j
void HelloWorld::pushStart(Ref *pSender)
{
	//���O���o��
	CCLOG("Push�{�^��");

	// ���ʉ���炷
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("uni15.wav");

	// �J�ڐ�̉�ʂ̃C���X�^���X
	Scene *pScene = SecondScene::createScene();

	// 0.5�b�����ăt�F�[�h�A�E�g���Ȃ��玟�̉�ʂɑJ�ڂ��܂��B
	//    �����P:�t�B�[�h�̎���
	//    �����Q�F�ړ���̃V�[��
	//    �����R�F�t�B�[�h�̐F�i�I�v�V�����j
	TransitionFade* transition = TransitionFade::create(0.5f, pScene);

	// �J�ڎ��s  �J�ڎ��̃A�j���[�V����
	// ���O��scene�͂����g��Ȃ�����̂ĂĂ��܂����@�B��{�͂���炵���B
	Director::getInstance()->replaceScene(transition);
}



// �v���C���[�̐ݒu�B
void HelloWorld::addPlayer(){
	// ��ʃT�C�Y�擾�B
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// �v���C���[�쐬�B
	_player1 = Sprite::create("natsu.png");
	_player2 = Sprite::create("jotaro.png");

	// �v���C���[�̐ݒu�ꏊ�B
	_player1->setPosition(Vec2(visibleSize.width / 4, visibleSize.height / 2));
	_player2->setPosition(Vec2(visibleSize.width / 4 * 3, visibleSize.height / 2));

	// �v���C���[�̃A���J�[�|�C���g�i��_�j�B�^�񒆒������ƁA0.4&0.6�Ɏw��B					//�ύX�D�D�D�D�D�D�D�D�D
	_player1->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
	_player2->setAnchorPoint(Vec2(0.4, 0.6));

	// �v���C���[�̓\��t���B
	this->addChild(_player1);																	//�q���ɉ�����ƂȂɂ��ł���悤�ɂȂ�H
	this->addChild(_player2);
}

void HelloWorld::addButton(){
	// ��ʃT�C�Y�擾�B
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// �{�^�������������A���������̉摜��ݒ�B�����_�Ƃ����T�O�ŏ������L�q�@[](Ref* ref){ }
	auto PlayButton1 = MenuItemImage::create("GODDESS.png", "GODDESS2.png", [](Ref* ref){
		// �{�^�������������̏����B����͉��������A���������ǂ�����A�N�V������ݒ肷��̂ł����ł͏����������Ȃ�
	});

	auto PlayButton2 = MenuItemImage::create("zoi.png", "zoi2.png", [](Ref* ref){
		// �{�^�������������̏����B����͉��������A���������ǂ�����A�N�V������ݒ肷��̂ł����ł͏����������Ȃ�
	});

	// �{�^���̐ݒu�ꏊ�B
	PlayButton1->setPosition(Vec2(visibleSize.width / 6.0, visibleSize.height / 8.0));
	PlayButton2->setPosition(Vec2(visibleSize.width / 6.0 * 5.0, visibleSize.height / 8.0));							//*�@5.0�@���ď����ĂȂ񂩂��ꂢ�Ȋ����̔z�u�ɂȂ��Ă�H

	// MenuItemImage�ō��ꂽ�{�^�����烁�j���[���쐬�B
	auto menu1 = Menu::create(PlayButton1, NULL);
	auto menu2 = Menu::create(PlayButton2, NULL);
	// ��_��0�B
	menu1->setPosition(Point::ZERO);
	menu2->setPosition(Point::ZERO);
	// �{�^���\��t���B�i���j���[�\��t���j
	this->addChild(menu1);
	this->addChild(menu2);


	// �^�b�`�C�x���g
	// ���̃{�^��
	auto listener1 = EventListenerTouchOneByOne::create();
	// �����_���g�p���Ċ֐�����onTouchBegan��onTouchEnded����������B																	Ramda?
	listener1->onTouchBegan = [this, visibleSize, PlayButton1](Touch* touch, Event* event){
		// �^�b�`���ꂽ�{�^���������ǂ������ʂ��Ă���B���ꂪ�Ȃ��ƕ����̃C�x���g���X�i�[�����s����Ă��܂��B
		Vec2 point1 = touch->getLocation();                 // �^�b�`�����|�C���g�B														Vec2?
		Rect rectButton1 = PlayButton1->getBoundingBox();   // �{�^���摜�͈̔́B
		if (rectButton1.containsPoint(point1)) {            // �{�^���摜�͈͓̔����^�b�`�����ꍇ�B
			// �^�b�`���ꂽ���̏����B
			auto sprite_pose1_1 = Sprite::create("natsu2.png");																//�V�����摜���A���̉摜�̑傫���ƈʒu�ɑ���H
			auto sprite_pose1_1_size = sprite_pose1_1->getContentSize();
			auto poseRect = Rect(0, 0, sprite_pose1_1_size.width, sprite_pose1_1_size.height);
			auto poseFrame = SpriteFrame::create("natsu2.png", poseRect);														//����2�s���C�}�C�`
			_player1->setSpriteFrame(poseFrame);
			return true;
		}
		else{
			return false;
		}

	};

	listener1->onTouchEnded = [this](Touch* touch, Event* event){
		// �^�b�`�I�����̏����B�i�w�𗣂������j
		auto sprite_pose1_1 = Sprite::create("natsu.png");
		auto sprite_pose1_1_size = sprite_pose1_1->getContentSize();
		auto poseRect1 = Rect(0, 0, sprite_pose1_1_size.width, sprite_pose1_1_size.height);
		auto poseFrame1 = SpriteFrame::create("natsu.png", poseRect1);
		_player1->setSpriteFrame(poseFrame1);
	};

	// listener1, PlayButton1���C�x���g�o�^����B
	auto director = Director::getInstance();
	director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener1, PlayButton1);



	// �E�̃{�^��
	auto listener2 = EventListenerTouchOneByOne::create();
	// �����_���g�p���Ċ֐�����onTouchBegan��onTouchEnded����������B
	listener2->onTouchBegan = [this, visibleSize, PlayButton2](Touch* touch, Event* event){
		// �^�b�`���ꂽ�{�^�����E���ǂ������ʂ��Ă���B���ꂪ�Ȃ��ƕ����̃C�x���g���X�i�[�����s����Ă��܂��B
		Vec2 point2 = touch->getLocation();                 // �^�b�`�����|�C���g�B
		Rect rectButton2 = PlayButton2->getBoundingBox();   //�@�{�^���摜�͈̔́B
		if (rectButton2.containsPoint(point2)) {            // �{�^���摜�͈͓̔����^�b�`�����ꍇ�B
			// �^�b�`���ꂽ���̏����B
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
		// �^�b�`�I�����̏����B�i�w�𗣂������j
		auto sprite_pose1_2 = Sprite::create("jotaro.png");
		auto sprite_pose1_2_size = sprite_pose1_2->getContentSize();
		auto poseRect2 = Rect(0, 0, sprite_pose1_2_size.width, sprite_pose1_2_size.height);
		auto poseFrame2 = SpriteFrame::create("jotaro.png", poseRect2);
		_player2->setSpriteFrame(poseFrame2);
	};

	// listener2, PlayButton2���C�x���g�o�^����B
	director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener2, PlayButton2);


}
