// ConsoleApplication1.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include <iostream>	//�ǉ�
using namespace std;


//�W���o�́A�X�^���_�[�h�B�@�o�͐��������̂����_�C���N�V�����B
int _tmain(int argc, _TCHAR* argv[])
{
	//C�̒�`����0��false�A����ȊO��true
	printf("%d\n", 10 != 10);	 //�m�b�g�C�R�[�����w!=�x

	//���������[�v�͂���
	//for (::)
	//while(1),while(2)
	//while(0)������false�ɂȂ邩�炨���炭�������̂��̂��X���[�����

	//for --���g����10��J��Ԃ�
	//[--]�ň���������ƍŌ��0�Ŏ~�܂�.
	for (int i = 10; i > 0; i--)
	{
		cout << i << endl;			//cout�ŏo�́Ai���o�͂�����endl�łP�����s����Ă�
	}


	//for��10��J��Ԃ�
	for (int i = 0; i < 20; i = i + 2)
	{
		cout << i << ' ';
	}
	cout << endl;				//�킽�ׂ��̂��cout���ł́w���s�R�[�h�x


	//while��10��J��Ԃ�
	
	int a;	//int a = 4�ł�������
	a = 8;
	while ( a < 18 )					
	{
		printf("%4d", a);	//a���o��	//sniping tool�p�F�����w��̊֌W�ł���Ă�I%2d������񌅁B 0d�ɂ��܂����I4d�Ŕ��p�X�y4��
		a++;					//while������++��ǉ������ꍇ
	}	printf("\n");


	//while -- ��10��J��Ԃ�
	int j = 4;
	while (j-- >1)			//while������--��ǉ������ꍇ
	{
		printf("%d\n", j);	//j���o��
	}


	//do�̎g����
	int n = 1;
	do
	{
		printf("%d\n", n);	//����"\n�����s"���Ӗ�����
		n--;
	} while (n > 0);	//do��ǉ������炿�イ�������̂��Ƃɏ�������ǉ��ł���B
	//do while�́A�i���̏ꍇ�jn�����ɂ��Ă��A�w�Œ�1��x�s����B
	//2��2��`�E�E1�ȉ�����1��ƂȂ�

	return 0;

}

