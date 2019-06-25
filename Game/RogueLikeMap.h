#pragma once
#include <cstdint>
#include <vector>
#include <random>
//����̃}�b�v�f�[�^�������܂�
class RogueLikeMap
{
public:
	RogueLikeMap(const size_t var_) :mapData(var_)
	{
	}
	RogueLikeMap() = default;
	~RogueLikeMap();
	std::vector<std::vector<RogueLikeMap>> NewMap();
	//���������\�ȃ}�b�v
	size_t mapData = 1;

};

enum :int {
	RL_COUNT_X,
	RL_COUNT_Y
};

struct DungeonMap_RL
{

	//��������镔���̐� (���m�Ɍ����Ɛ����������̐�)
	size_t divCountMin = 5; //�}�b�v�̋敪���ŏ���
	size_t divCountRand = 2; //�}�b�v�̋敪�������Z

							 //��������镔���̃T�C�Y
	size_t roomLengthMinX = 5; //������X���W�̍ŏ��T�C�Y
	size_t roomLengthMinY = 5; //������Y���W�̍ŏ��T�C�Y
	size_t roomLengthRandX = 10; //������X���W�̃T�C�Y���Z
	size_t roomLengthRandY = 10; //������Y���W�̃T�C�Y���Z

	size_t mapDivCount{}; //�}�b�v�̋敪���� (�����̌�) 0~n�܂ł̕���ID
	size_t mapDiv[8][4]{}; //�}�b�v�̋�� [����ID][X�I�_ , Y�I�_ , X�n�_ , Y�n�_]
	size_t mapRoom[8][4]{}; //�}�b�v�̕��� [����ID][X�I�_ , Y�I�_ , X�n�_ , Y�n�_]
	size_t mapRoad[8][4]{}; //�}�b�v�̓� [����ID(�O)][�q�����̕���ID(��) , (0.X���W , 1.Y���W) , (�O)���̒ʘH�̈ʒu , (��)���̒ʘH�̈ʒu]
	size_t mapRoomPlayer[8]{};

};

/*���[�O���C�N�����֐�*/
template <typename T>
int rogueLikeMapMake(DungeonMap_RL* const dng, T& maprl)
{
	std::random_device rnd;     // �񌈒�I�ȗ���������𐶐�
	std::mt19937 Rand(rnd());     //  �����Z���k�E�c�C�X�^��32�r�b�g�ŁA�����͏����V�[�h�l
	std::uniform_int_distribution<> GetRand(0, 10000);        // [0, 10000] �͈͂̈�l����
	if (maprl.size() == 0 || maprl.front().size() == 0) return -1;
	for (size_t i = 0; i < maprl.size(); ++i)
		for (size_t j = 0; j < maprl[i].size(); ++j)
			maprl[i][j].mapData = 1; 
	dng->mapDivCount = dng->divCountMin + (size_t)(GetRand(Rand) * ((int)(dng->divCountRand)+1)/ (1 + 10000)); //�}�b�v�̋敪���� (�����̌�) 0~n�܂ł̕���ID
	if (dng->mapDivCount > 7) return -1;

	dng->mapDiv[0][0] = (maprl.size() - 1); //�}�b�v�̋敪�������T�C�YX�I�_ (�}�b�v�̑傫��X��)
	dng->mapDiv[0][1] = (maprl.front().size() - 1); //�}�b�v�̋敪�������T�C�YY�I�_ (�}�b�v�̑傫��Y��)
	dng->mapDiv[0][2] = 1; //�}�b�v�̋敪�������T�C�YX�n�_ (�}�b�v�̑傫��X��)
	dng->mapDiv[0][3] = 1; //�}�b�v�̋敪�������T�C�YY�n�_ (�}�b�v�̑傫��Y��)

	dng->mapRoad[0][0] = 255;
	dng->mapRoad[0][1] = 255;

	/*�}�b�v���敪�����Ă�������(���𕪊����鏈��)*/
	size_t divAfter;
	int count; //(0:X, 1:Y) X���ŕ����邩Y���ŕ����邩���߂�

	for (size_t i = 1; i < dng->mapDivCount; ++i) {

		//���܂ō�����敪���������_���Ɏw��(�w�肵����������ɋ敪������)
		divAfter = (size_t)(GetRand(Rand)*(i-1 + 1) / (1 + 10000));

		//�w�肵������X��Y�̒����ɂ���āA����������������߂�(�����ق��𕪊�����)
		if (dng->mapDiv[divAfter][0] - dng->mapDiv[divAfter][2] > dng->mapDiv[divAfter][1] - dng->mapDiv[divAfter][3]) count = RL_COUNT_X;
		else count = RL_COUNT_Y;

		if (dng->mapDiv[divAfter][count] - dng->mapDiv[divAfter][count + 2] < dng->divCountRand * 2 + 8) {
			size_t k = 0;
			for (size_t j = 1; j < dng->mapDivCount; ++j) {
				if (dng->mapDiv[j][0] - dng->mapDiv[j][2] > k) {
					k = dng->mapDiv[j][0] - dng->mapDiv[j][2];
					divAfter = j;
					count = RL_COUNT_X;
				}
				if (dng->mapDiv[j][1] - dng->mapDiv[j][3] > k) {
					k = dng->mapDiv[j][1] - dng->mapDiv[j][3];
					divAfter = j;
					count = RL_COUNT_Y;
				}
			}
		}

		dng->mapRoad[i][0] = divAfter;
		dng->mapRoad[i][1] = count;

		for (size_t j = 1; j < i; ++j)
			if (dng->mapRoad[j][0] == divAfter) dng->mapRoad[j][0] = i;

		//count���̐ݒ�
		dng->mapDiv[i][count] = dng->mapDiv[divAfter][count + 2] + (dng->mapDiv[divAfter][count] - dng->mapDiv[divAfter][count + 2]) / 3 + (size_t)(GetRand(Rand) * (int)(((dng->mapDiv[divAfter][count] - dng->mapDiv[divAfter][count + 2]) / 3)+1) / (1 + 10000)); //0.���̉E�[(iR)�̍��W(divAfter*R/3~2divAfter*R/3)
		dng->mapDiv[i][count + 2] = dng->mapDiv[divAfter][count + 2]; //0.���̍��[(iL)�̍��W(divAfterL)
		dng->mapDiv[divAfter][count + 2] = dng->mapDiv[i][count]; //divAfter���̍��[(divAfterL)�̍��W(iR)

																  //count�Ƃ͋t�̎��̐ݒ�
		dng->mapDiv[i][abs(count - 1)] = dng->mapDiv[divAfter][abs(count - 1)]; //���̉E�[(iR)�̍��W(divAfterR)
		dng->mapDiv[i][abs(count - 1) + 2] = dng->mapDiv[divAfter][abs(count - 1) + 2]; //���̍��[(iL)�̍��W(divAfterL)
	}

	/*�����𐶐����鏈��*/
	for (size_t i = 0; i < dng->mapDivCount; ++i) {//�敪��
		dng->mapRoomPlayer[i] = 0;//�v���C���[�N��������
		dng->mapRoom[i][2] = dng->mapDiv[i][2]; //�敪��X�n�_���}�b�vX�n�_�֑��
		dng->mapRoom[i][3] = dng->mapDiv[i][3]; //�敪��Y�n�_���}�b�vY�n�_�֑��
												//X���W�̕����̒������w��
		dng->mapRoom[i][0] = dng->mapDiv[i][2] + dng->divCountRand + (size_t)(GetRand(Rand) * ((int)(dng->roomLengthRandX)+1)/(1+ 10000));
		if (dng->mapDiv[i][0] - dng->mapDiv[i][2] < dng->mapRoom[i][0] - dng->mapRoom[i][2] + 5) {
			dng->mapRoom[i][0] = dng->mapDiv[i][0] - 4;
			if (dng->mapDiv[i][0] - dng->mapDiv[i][2] < dng->mapRoom[i][0] - dng->mapRoom[i][2] + 5) {
				dng->mapRoom[i][0] = dng->mapDiv[i][2] + 1;
			}
		}

		dng->mapRoom[i][1] = dng->mapDiv[i][3] + dng->roomLengthMinY + (size_t)(GetRand(Rand) * ((int)(dng->roomLengthRandY)+1)/(1+ 10000));
		if (dng->mapDiv[i][1] - dng->mapDiv[i][3] < dng->mapRoom[i][1] - dng->mapRoom[i][3] + 5) {
			dng->mapRoom[i][1] = dng->mapDiv[i][1] - 4;
			if (dng->mapDiv[i][1] - dng->mapDiv[i][3] < dng->mapRoom[i][1] - dng->mapRoom[i][3] + 5) {
				dng->mapRoom[i][1] = dng->mapDiv[i][3] + 1;
			}
		}

		if (dng->mapRoom[i][0] - dng->mapDiv[i][2] <= 1 || dng->mapRoom[i][1] - dng->mapDiv[i][3] <= 1) {
			dng->mapRoom[i][0] = dng->mapDiv[i][2] + 1;
			dng->mapRoom[i][1] = dng->mapDiv[i][3] + 1;
		}
		size_t l;
		size_t m;
		auto k=GetRand(Rand);
		l = (size_t)(2+k * (((int)dng->mapDiv[i][0] - (int)dng->mapRoom[i][0] - 5)+1) / (1 + 10000));
		
		auto nn = GetRand(Rand);
		m = (size_t)(2 + nn * (((int)dng->mapDiv[i][1] - (int)dng->mapRoom[i][1] - 5)+1)/ (1 + 10000));
		dng->mapRoom[i][0] += l;
		dng->mapRoom[i][2] += l;
		dng->mapRoom[i][1] += m;
		dng->mapRoom[i][3] += m;

		for (size_t j = dng->mapRoom[i][2]; j < dng->mapRoom[i][0]; ++j)
			for (size_t k = dng->mapRoom[i][3]; k < dng->mapRoom[i][1]; ++k)
				maprl[j][k].mapData = 0;
	}


	/*�ʘH�𐶐����鏈��*/
	/*�ʘH�͂Q�����Ԃׂ̍����̂��Ƃ��w���B
	�ʘH����邽�߂ɂQ���������ꂼ��O(Before)�ƌ�(After)�ŕ�����B
	for���őS�Ă̕������`�F�b�N���A�O��̕������q���ʘH�����B
	�܂��A�O�̒ʘH�����A���Ɍ�̒ʘH�����B
	�Ō�ɑO�ƌ�̒ʘH���q����B
	*/
	size_t roomAfter;
	for (size_t roomBefore = 0; roomBefore < dng->mapDivCount; ++roomBefore) {
		roomAfter = dng->mapRoad[roomBefore][0];

		//X���W�̒ʘH
		switch (dng->mapRoad[roomBefore][1]) {
		case RL_COUNT_X:
			dng->mapRoad[roomBefore][2] = (size_t)( GetRand(Rand) * ((int)(dng->mapRoom[roomBefore][1] - dng->mapRoom[roomBefore][3]) - 2 +1)/ (1 + 10000)); //�O���̒ʘH�̈ʒu
			dng->mapRoad[roomBefore][3] = (size_t)( GetRand(Rand) * ((int)(dng->mapRoom[roomAfter][1] - dng->mapRoom[roomAfter][3] ) - 2 +1) / (1 + 10000)) ; //�㑤�̒ʘH�̈ʒu
																															   //�O�̒ʘH
			for (size_t j = dng->mapRoom[roomBefore][0]; j < dng->mapDiv[roomBefore][0]; ++j)
				maprl[j][dng->mapRoad[roomBefore][2] + dng->mapRoom[roomBefore][3]].mapData = 0; //�ʘH���}�b�v�`�b�v�ɐ���

																								 //��̒ʘH
			for (size_t j = dng->mapDiv[roomAfter][2]; j < dng->mapRoom[roomAfter][2]; ++j)
				maprl[j][dng->mapRoad[roomBefore][3] + dng->mapRoom[roomAfter][3]].mapData = 0; //�ʘH���}�b�v�`�b�v�ɐ���

																								//�ʘH���Ȃ�
			for (size_t j = dng->mapRoad[roomBefore][2] + dng->mapRoom[roomBefore][3]; j <= dng->mapRoad[roomBefore][3] + dng->mapRoom[roomAfter][3]; ++j)
				maprl[dng->mapDiv[roomBefore][0]][j].mapData = 0; //�ʘH���}�b�v�`�b�v�ɐ��� 2����5(�ォ�牺)
			for (size_t j = dng->mapRoad[roomBefore][3] + dng->mapRoom[roomAfter][3]; j <= dng->mapRoad[roomBefore][2] + dng->mapRoom[roomBefore][3]; ++j)
				maprl[dng->mapDiv[roomBefore][0]][j].mapData = 0; //�ʘH���}�b�v�`�b�v�ɐ��� 5����2(�������)
			break;

		case RL_COUNT_Y:
			dng->mapRoad[roomBefore][2] = (size_t)( GetRand(Rand) * ((int)(dng->mapRoom[roomBefore][0] - dng->mapRoom[roomBefore][2]) - 2 +1)/ (1.0f + 10000)); //�O���̒ʘH�̈ʒu
			dng->mapRoad[roomBefore][3] = (size_t)( GetRand(Rand) * ((int)(dng->mapRoom[roomAfter][0] - dng->mapRoom[roomAfter][2])-2 + 1) / (1.0f + 10000)); //�㑤�̒ʘH�̈ʒu
																															   //�O�̒ʘH
			for (size_t j = dng->mapRoom[roomBefore][1]; j < dng->mapDiv[roomBefore][1]; ++j)
				maprl[dng->mapRoad[roomBefore][2] + dng->mapRoom[roomBefore][2]][j].mapData = 0; //�ʘH���}�b�v�`�b�v�ɐ���

																								 //��̒ʘH
			for (size_t j = dng->mapDiv[roomAfter][3]; j < dng->mapRoom[roomAfter][3]; ++j)
				maprl[dng->mapRoad[roomBefore][3] + dng->mapRoom[roomAfter][2]][j].mapData = 0; //�ʘH���}�b�v�`�b�v�ɐ���

																								//�ʘH���Ȃ�
			for (size_t j = dng->mapRoad[roomBefore][2] + dng->mapRoom[roomBefore][2]; j <= dng->mapRoad[roomBefore][3] + dng->mapRoom[roomAfter][2]; ++j)
				maprl[j][dng->mapDiv[roomBefore][1]].mapData = 0; //�ʘH���}�b�v�`�b�v�ɐ���
			for (size_t j = dng->mapRoad[roomBefore][3] + dng->mapRoom[roomAfter][2]; j <= dng->mapRoad[roomBefore][2] + dng->mapRoom[roomBefore][2]; ++j)
				maprl[j][dng->mapDiv[roomBefore][1]].mapData = 0; //�ʘH���}�b�v�`�b�v�ɐ���
			break;
		}

	}
	return 0;
}