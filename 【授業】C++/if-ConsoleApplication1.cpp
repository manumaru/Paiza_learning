// ConsoleApplication1.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include <iostream>	//�ǉ�
using namespace std;


//�W���o�́A�X�^���_�[�h�B�@�o�͐��������̂����_�C���N�V�����B
int _tmain(int argc, _TCHAR* argv[])
{
	float height, weight, bmi;
	cout << "height(cm):";
	cin >> height;
	cout << "weight(kg):";
	cin >> weight;
	height /= 100; //�]������	[Re�o���G�C�g]
	bmi = weight / (height * height);
	cout << bmi << endl;

	///3��ށiC++,C����,�j
	//19.5�������u������тĂ�v
	//25.0�ȏオ�u����ł�v
	//19.5�ȏ�25,0�������u����v

	/*if (bmi < 19.5f){			//f�������āwfloat�x�^�ɂ��Ȃ��ƌ��X�wdouble�x�^�B Unity����19.5f�ɂ��Ȃ���{����B
		cout << "������тĂ�" << endl;	//C++�I�ɕ\�L	endl��/n�͂ǂ�����w���s�x���Ӗ�
	}
	else if ( bmi >=25.0f ){			
		printf("����ł�\n");			//C����I�ɕ\�L����Ȃ�print f
	}
	else	{
		cout << "����\n";				//C++�I�ɕ\�L
	}
	*/

	//��������C����̕�����͂ǂ��Ȃ񂾂�ˁE�E�H�܂��킩��Ȃ���

	//��������BC++�ł̕�����������Ƃ��̃x�[�V�b�N�Ȃ����B�ォ��ǉ����鎞�ɕ֗�
	string s;
	if (bmi < 19.5f) s = "�����߂�";
	else if (bmi < 25.0f) s = "�ӂ�";
	else s = "����߂�";
	cout << s.c_str() << endl;	//"s/c_str"�̕����́@string�I�Ȃ��̂�C����I�Ȃ��̂ɕϊ�������̂��Ƒ����Ƃ��΂���

	//cout << "hello" << endl;
	//�������Ӗ��������ǈႤ�L�q�̎d��
	//	cout << "hello\n";			//C����I�ɂ����Ȃ�print f

	return 0;

	//C�̒�`����0��false�A����ȊO��true
}

