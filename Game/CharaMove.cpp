#include "stdafx.h"
#include "CharaMove.h"



CharaMove::CharaMove()
{
}


CharaMove::~CharaMove()
{
}

CVector3 CharaMove::EneMove()
{
	m_moveSpeed = CVector3::Zero();
	if (phase.GetTaan() == 1) {
		m_moveSpeed = CVector3::AxisX();
		timerX++;
		if (randomX == 1 || randomX == 5 || randomX == 9) {
			if (timerX > 0 && timerX <= 10) {
				//�ړ��̌����B
				MoveDirection = 1;
				//�ړ��̕��������߂�B
				m_moveSpeed.x = m_moveSpeed.x * MoveDirection;
				if (timerX == 10) {
					//�ȈՃ^�C�}�[���Z�b�g�B
					timerX = 0;
					//1�`9�̗����擾�B
					randomX = rand() % 9 + 1;
				}
			}
		}
		if (randomX == 2 || randomX == 4 || randomX == 7) {
			if (timerX > 0 && timerX <= 10) {
				//�ړ��̌����B
				MoveDirection = -1;
				//�ړ��̕��������߂�B
				m_moveSpeed.x = m_moveSpeed.x * MoveDirection;
				if (timerX == 10) {
					//�ȈՃ^�C�}�[���Z�b�g�B
					timerX = 0;
					//1�`9�̗����擾�B
					randomX = rand() % 9 + 1;
				}
			}
		}
		//if (randomX == 3 || randomX == 6 || randomX == 8) {

		//	if (timerX > 0 && timerX <= 10) {
		//		//�ړ��̌����B
		//		MoveDirection = 0;
		//		//�ړ��̕��������߂�B
		//		m_moveSpeed.x = m_moveSpeed.x * MoveDirection;
		//		if (timerX == 10) {
		//			//�ȈՃ^�C�}�[���Z�b�g�B
		//			timerX = 0;
		//			//1�`9�̗����擾�B
		//			randomX = rand() % 9 + 1;
		//		}
		//	}
		//}

		m_moveSpeed = CVector3::AxisZ();
		timerZ++;
		if (randomZ == 1 || randomZ == 5 || randomZ == 9) {
			if (timerZ > 0 && timerZ <= 10) {
				//�ړ��̌����B
				MoveDirection = 1;
				//�ړ��̕��������߂�B
				m_moveSpeed.z = m_moveSpeed.z * MoveDirection;
				if (timerZ == 10) {
					//�ȈՃ^�C�}�[���Z�b�g�B
					timerZ = 0;
					//1�`9�̗����擾�B
					randomZ = rand() % 9 + 1;
				}
			}
		}
		if (randomZ == 2 || randomZ == 4 || randomZ == 7) {
			if (timerZ > 0 && timerZ <= 10) {
				//�ړ��̌����B
				MoveDirection = -1;
				//�ړ��̕��������߂�B
				m_moveSpeed.z = m_moveSpeed.z * MoveDirection;
				if (timerZ == 10) {
					//�ȈՃ^�C�}�[���Z�b�g�B
					timerZ = 0;
					//1�`9�̗����擾�B
					randomZ = rand() % 9 + 1;
				}
			}
		}
		//if (randomZ == 3 || randomZ == 6 || randomZ == 8) {

		//	if (timerZ > 0 && timerZ <= 10) {
		//		//�ړ��̌����B
		//		MoveDirection = 0;
		//		//�ړ��̕��������߂�B
		//		m_moveSpeed.z = m_moveSpeed.z * MoveDirection;
		//		if (timerZ == 10) {
		//			//�ȈՃ^�C�}�[���Z�b�g�B
		//			timerZ = 0;
		//			//1�`9�̗����擾�B
		//			randomZ = rand() % 9 + 1;
		//		}
		//	}
		//}
		auto move = CVector3::AxisX(), AxisZ();

		//�ړ��̌v�Z��Ԃ��B
	}
	return m_moveSpeed;
}