#include "EnemySprite.h"

using namespace cocos2d;

EnemySprite::EnemySprite()
{
}

/**
*  �X�v���C�g�͈̔͂��擾
*
*  @return CCRect
*/
CCRect EnemySprite::getRect()
{
	// �X�v���C�g�̍��W�i�摜�̐^�񒆂̍��W�̂��Ɓj
	CCPoint point = this->getPosition();

	// �X�v���C�g�̕��ƍ���
	int w = this->getContentSize().width;
	int h = this->getContentSize().height;

	// �X�v���C�g�͈̔͂�Ԃ�
	return CCRectMake(point.x - (w / 2), point.y - (h / 2), w, h);
}

/**
*  �����̍��W���X�v���C�g�͈͓̔����ǂ�����Ԃ��i�^�b�`���̍��W����n���j
*
*  @param point ���W�|�C���g
*
*  @return ture or false
*/
bool EnemySprite::isTouchPoint(CCPoint point)
{
	return this->getRect().containsPoint(point);
}
