// ConsoleApplication3.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include<iostream>
#include<chrono>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	// �@�@�R���s���[�^�A�v���C���[�̐錾
	int  computer, player;
	//�����n��̏�����
	srand(time(NULL));			//s��rand(time(NULL))�@NULL�������ĂȂ񂾂����B			

	cout << "0:�O�[ 1:�`���L 2:�p�[  ";	//""�ň͂��Ă���e�́A�D���ɂ��Ă������b�Z�[�W�B
	cin >> player;	//���

	// �A�@�R���s���[�^�̎�������_������
	computer = rand() % 3;		//% �R ��3�Ŋ������]��B rand()�Ő������ȁB�R�̂��������_���ŏo���A���Ă��Ƃ��H

	if (player == computer )
	{
		printf("�������ł�\n");			//���ꂪC����I�\�L�̎d���ˁB	printf("\n"); 	�u\n�v�͉��s
	}
	else if (player == 1 && computer == 2){
		printf("�v���C���[�̏����ł�\n");			
	}
	else if (player == 2 && computer == 3){
		printf("�v���C���[�̏����ł�\n");
	}
	else if (player == 3 && computer == 1){
		printf("�v���C���[�̏����ł�\n");
	}
	else{
		printf("�R���s���[�^�̏����ł�\n");
	}

	return 0;
}

