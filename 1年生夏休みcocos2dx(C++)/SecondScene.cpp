#include "SecondScene.h"
#include "HelloWorldScene.h"
//�����Ȃ炷���߂�include
#include "SimpleAudioEngine.h"


USING_NS_CC;


Scene* SecondScene::createScene()
{
	// �V�[�����I�[�g�����B
	auto scene = Scene::create();

	// ���C���[�𐶐��B
	auto layer = SecondScene::create();

	// �V�[���Ɂu�q�v�Ƃ��ă��C���[��ǉ��B
	scene->addChild(layer);

	// �߂�B	
	return scene;
}

//�V�[����::init�Ŋ֐���錾�B
bool SecondScene::init()
{
	//////////////////////////////
	// 1. super init first			�ŏ��̒�init	?
	if (!Layer::init())
	{
		return false;
	}

	// �v���C���[�̐ݒu�B
	this->addPlayer();
	// �{�^���̐ݒu�B
	this->addButton();

	// �o�b�N�O���E���h
	makeBackground();

	//��ʃT�C�Y���擾
	Size winSize = Director::getInstance()->getVisibleSize();

	//�߂�{�^����ݒu
	auto backButton = MenuItemImage::create(
		"aiee.png",  //�\��
		"aiee2.png",  //�^�b�v���̉摜
		CC_CALLBACK_1(SecondScene::pushBack, this));// �������̃A�N�V����
	// �{�^���̐ݒu
	backButton->setPosition(Point(winSize.width / 2, winSize.height / 2));

	// ���j���[���쐬 ��������I�u�W�F�N�g�B
	auto menu = Menu::create(backButton, NULL);
	//���j���[�̔z�u
	menu->setPosition(Point::ZERO);
	// ���j���[��ǉ��B
	this->addChild(menu, 1);


	return true;
}

//�w�i�̃N���X
void SecondScene::makeBackground()
{
	//��ʂ̍��W�֌W�̏ڂ��������͂���
http://www.cocos2d-x.org/wiki/Coordinate_System
	//��ʃT�C�Y���擾
	Size winSize = Director::getInstance()->getVisibleSize();
	//�}���`���]�����[�V�����Ή����ǂ��Ƃ�
	Point origin = Director::getInstance()->getVisibleOrigin();

	// �o�b�N�O�����h�J���[
	auto background = LayerColor::create(Color4B::ORANGE,
		winSize.width,
		winSize.height);
	//�o�b�N�O�����h�J���[�ǉ��B ��2�����͕\����
	this->addChild(background, -1);

	//�^�C�g����ݒu
	auto lbl_title = Label::createWithSystemFont
		("HELLOO FOO", "Ebrima", 100);
	lbl_title->setPosition(Point(origin.x + winSize.width / 2,
		origin.y + winSize.height
		- lbl_title->getContentSize().height));
	// ���x���^�C�g����ǉ��B
	this->addChild(lbl_title, 1);
}

//�V�[���J�� �ipushBack�{�^���j
void SecondScene::pushBack(Ref *pSender)
{
	// ���ʉ���炷
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("yame.wav");

	// �J�ڐ�̉�ʂ̃C���X�^���X
	Scene *pScene = HelloWorld::createScene();

	// 0.5�b�����ăt�F�[�h�A�E�g���Ȃ��玟�̉�ʂɑJ�ڂ��܂��B
	//    �����P:�t�B�[�h�̎���
	//    �����Q�F�ړ���̃V�[��
	//    �����R�F�t�B�[�h�̐F�i�I�v�V�����j
	TransitionFade* transition = TransitionFade::create(0.5f, pScene);

	//�J�ڎ��s  �J�ڎ��̃A�j���[�V����
	Director::getInstance()->replaceScene(transition);
}

// �v���C���[�̐ݒu�B
void SecondScene::addPlayer(){
	// ��ʃT�C�Y�擾�B
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// �v���C���[�쐬�B
	_player1 = Sprite::create("natsu.png");
	_player2 = Sprite::create("jotaro.png");

	// �v���C���[�̐ݒu�ꏊ�B
	_player1->setPosition(Vec2(visibleSize.width / 4, visibleSize.height / 2));
	_player2->setPosition(Vec2(visibleSize.width / 4 * 3, visibleSize.height / 2));

	// �v���C���[�̃A���J�[�|�C���g�i��_�j�B�^�񒆒������ƁA0.4&0.6�Ɏw��					//�ύX�D�D�D�D�D�D�D�D�D
	_player1->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
	_player2->setAnchorPoint(Vec2(0.4, 0.6));

	// �v���C���[�̓\��t���B
	this->addChild(_player1);
	this->addChild(_player2);
}

void SecondScene::addButton(){
	// ��ʃT�C�Y�擾�B
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// �{�^�������������A���������̉摜��ݒ�B�����_�Ƃ����T�O�ŏ������L�q�B[](Ref* ref){ }
	auto PlayButton1 = MenuItemImage::create("GODDESS.png", "GODDESS2.png", [](Ref* ref){
		// �{�^�������������̏����B����͉��������A���������ǂ�����A�N�V������ݒ肷��̂ł����ł͏����������Ȃ��B
	});

	auto PlayButton2 = MenuItemImage::create("zoi.png", "zoi2.png", [](Ref* ref){
		// �{�^�������������̏����B����͉��������A���������ǂ�����A�N�V������ݒ肷��̂ł����ł͏����������Ȃ��B
	});

	// �{�^���̐ݒu�ꏊ�B
	PlayButton1->setPosition(Vec2(visibleSize.width / 6.0, visibleSize.height / 8.0));
	PlayButton2->setPosition(Vec2(visibleSize.width / 6.0 * 5.0, visibleSize.height / 8.0));

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
	// �����_���g�p���Ċ֐�����onTouchBegan��onTouchEnded����������B
	listener1->onTouchBegan = [this, visibleSize, PlayButton1](Touch* touch, Event* event){
		// �^�b�`���ꂽ�{�^���������ǂ������ʂ��Ă���B���ꂪ�Ȃ��ƕ����̃C�x���g���X�i�[�����s����Ă��܂��B
		Vec2 point1 = touch->getLocation();                 // �^�b�`�����|�C���g�B
		Rect rectButton1 = PlayButton1->getBoundingBox();   // �{�^���摜�͈̔́B
		if (rectButton1.containsPoint(point1)) {            // �{�^���摜�͈͓̔����^�b�`�����ꍇ�B
			// �^�b�`���ꂽ���̏����B
			auto sprite_pose1_1 = Sprite::create("natsu2.png");
			auto sprite_pose1_1_size = sprite_pose1_1->getContentSize();
			auto poseRect = Rect(0, 0, sprite_pose1_1_size.width, sprite_pose1_1_size.height);
			auto poseFrame = SpriteFrame::create("natsu2.png", poseRect);
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