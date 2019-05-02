#ifndef __SECOND_SCENE_H__
#define __SECOND_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class SecondScene : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// �I���W�i�����\�b�h�Binit()���̌��ʂ����悭���邽�߂Ƀv���C���[�ƃ{�^���̍쐬��ʊ֐��Ƃ���B
	void addPlayer();
	void addButton();


	// implement the "static create()" method manually
	CREATE_FUNC(SecondScene);

	//�w�i��錾�B
	void makeBackground();

	// �X�^�[�g�{�^���������̏����錾�B �߂� Object ���@Ref �ɕύX
	void pushBack(cocos2d::Ref *pSender);


	// �v���C���[�̃v���p�e�B�錾�B
	CC_SYNTHESIZE_RETAIN(cocos2d::Sprite*, _player1, Player1);
	CC_SYNTHESIZE_RETAIN(cocos2d::Sprite*, _player2, Player2);
};

#endif // __HELLOWORLD_SCENE_H__