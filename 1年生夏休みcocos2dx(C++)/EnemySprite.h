#ifndef __SpriteTouchTestProject__EnemySprite__
#define __SpriteTouchTestProject__EnemySprite__

#include "cocos2d.h"

class EnemySprite : public cocos2d::CCSprite
{
public:

	EnemySprite();

	cocos2d::CCRect getRect();
	bool isTouchPoint(cocos2d::CCPoint);

};
#endif /* defined(__SpriteTouchTestProject__EnemySprite__) */
