/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 * 
 *  Copyright (C) 2009 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 * 
 *  ��L���쌠�҂́C�ȉ���(1)�`(4)�̏����𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F
 *  �A�i�{�\�t�g�E�F�A�����ς������̂��܂ށD�ȉ������j���g�p�E�����E��
 *  �ρE�Ĕz�z�i�ȉ��C���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
 *  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
 *      ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
 *      �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
 *  (2) �{�\�t�g�E�F�A���C���C�u�����`���ȂǁC���̃\�t�g�E�F�A�J���Ɏg
 *      �p�ł���`�ōĔz�z����ꍇ�ɂ́C�Ĕz�z�ɔ����h�L�������g�i���p
 *      �҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C���̗��p��������щ��L
 *      �̖��ۏ؋K����f�ڂ��邱�ƁD
 *  (3) �{�\�t�g�E�F�A���C�@��ɑg�ݍ��ނȂǁC���̃\�t�g�E�F�A�J���Ɏg
 *      �p�ł��Ȃ��`�ōĔz�z����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂�����
 *      �ƁD
 *    (a) �Ĕz�z�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒�
 *        �쌠�\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *    (b) �Ĕz�z�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āCTOPPERS�v���W�F�N�g��
 *        �񍐂��邱�ƁD
 *  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
 *      �Q������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD
 *      �܂��C�{�\�t�g�E�F�A�̃��[�U�܂��̓G���h���[�U����̂����Ȃ闝
 *      �R�Ɋ�Â�����������C��L���쌠�҂����TOPPERS�v���W�F�N�g��
 *      �Ɛӂ��邱�ƁD
 * 
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
 *  ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC����̎g�p�ړI
 *  �ɑ΂���K�������܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F
 *  �A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C��
 *  �̐ӔC�𕉂�Ȃ��D
 * 
 *  @(#) $Id: test_mutex8.c 1696 2010-01-01 16:01:25Z ertl-hiro $
 */

/* 
 *		�~���[�e�b�N�X�̃e�X�g(8)
 *
 * �y�e�X�g�̖ړI�z
 *
 *  �D��x����~���[�e�b�N�X�ɑ΂��āCchg_pri�ɔ����~���[�e�b�N�X�֘A��
 *  �D��x�ύX������ԗ��I�Ƀe�X�g����D�������Cchange_priority��
 *  mutex_calc_priority�̓��e�ɂ͓��ݍ��܂Ȃ��D
 *
 * �y�e�X�g���ځz
 *
 *	(A) �^�X�N�̃x�[�X�D��x�̕ύX�����ichg_pri�j
 *		(A-1) �Ώۃ^�X�N�����s�ł����ԂŁC�~���[�e�b�N�X�����b�N����
 *			  ���Ȃ��ꍇ�ɁC�����D��x���ł̗D�揇�ʂ��Œ�ɂȂ邱��
 *		(A-2) �Ώۃ^�X�N�����s�ł����ԂŁC�D��x����~���[�e�b�N�X��
 *			  �O�̃~���[�e�b�N�X�݂̂����b�N���Ă���ꍇ�ɁC�����D��x
 *			  ���ł̗D�揇�ʂ��Œ�ɂȂ邱��
 *		(A-3) �Ώۃ^�X�N�����s�ł����ԂŁC�D��x����~���[�e�b�N�X��
 *			  ���b�N���Ă���ꍇ�ɁC�����D��x���ł̗D�揇�ʂ��ς���
 *			  ������
 *		(A-4) �Ώۃ^�X�N���҂���ԂŁC�D��x���̑҂��s��ɂȂ���Ă�
 *			  ��C�~���[�e�b�N�X�����b�N���Ă��Ȃ��ꍇ�ɁC�D��x������
 *			  ���ύX����C�����D��x���ł̏������Ō�ɂȂ邱��
 *		(A-5) �Ώۃ^�X�N���҂���ԂŁC�D��x���̑҂��s��ɂȂ���Ă�
 *			  ��C�D��x����~���[�e�b�N�X�ȊO�̃~���[�e�b�N�X�݂̂����b
 *			  �N���Ă���ꍇ�ɁC�D��x���������ύX����C�����D��x����
 *			  �̏������Ō�ɂȂ邱��
 *		(A-6) �Ώۃ^�X�N���҂���ԂŁC�D��x���̑҂��s��ɂȂ���Ă�
 *			  ��C�D��x����~���[�e�b�N�X�����b�N���Ă���ꍇ�ɁC����
 *			  �D��x���ł̏������ς��Ȃ�����
 *	(B) �^�X�N�̃x�[�X�D��x�̕ύX�����ichg_pri�j��E_ILUSE�G���[
 *		(B-1) �Ώۃ^�X�N�����b�N���Ă���~���[�e�b�N�X�̏���D��x���
 *			  ���C�x�[�X�D��x���������悤�Ƃ������CE_ILUSE�G���[�ɂȂ�
 *			  ����
 *		(B-2) �Ώۃ^�X�N���D��x����~���[�e�b�N�X�����b�N���Ă��Ă��C
 *			  ���b�N���Ă���~���[�e�b�N�X�̏���D��x�����C�x�[�X�D
 *			  ��x���������悤�Ƃ��Ȃ��ꍇ�ɂ́CE_ILUSE�G���[�ɂȂ�Ȃ�
 *			  ����
 *		(B-3) �Ώۃ^�X�N�����b�N��҂��Ă���~���[�e�b�N�X�̏���D��x
 *			  �����C�x�[�X�D��x���������悤�Ƃ������CE_ILUSE�G���[��
 *			  �Ȃ邱��
 *		(B-4) �Ώۃ^�X�N���D��x����~���[�e�b�N�X�҂��ł����Ă��C���b
 *			  �N��҂��Ă���~���[�e�b�N�X�̏���D��x�����C�x�[�X�D
 *			  ��x���������悤�Ƃ��Ȃ��ꍇ�ɂ́CE_ILUSE�G���[�ɂȂ�Ȃ�
 *			  ����
 *
 * �y�e�X�g���ڂ̎������@�z
 *
 *	(A-1)
 *		���D��x�^�X�N�iTASK1�j�����s�\��Ԃ̎��ɁC���D��x�^�X�N
 *		�iTASK5�j����TASK1���D��x��chg_pri����ƁC���s�\��Ԃ̑���
 *		��D��x�^�X�N�iTASK4�j�����C�D�揇�ʂ��Ⴍ�Ȃ邱�Ƃ��m�F����D
 *	(A-2)
 *		���D��x�^�X�N�iTASK1�j���D��x���~���[�e�b�N�X�iMTX3�j�����b�N
 *		���C���s�\��Ԃ̎��ɁC���D��x�^�X�N�iTASK5�j����TASK1���D
 *		��x��chg_pri����ƁC���s�\��Ԃ̑��̒�D��x�^�X�N�iTASK4�j
 *		�����C�D�揇�ʂ��Ⴍ�Ȃ邱�Ƃ��m�F����D
 *	(A-3)
 *		���D��x�^�X�N�iTASK1�j�����D��x����~���[�e�b�N�X�iMTX1�j�����b
 *		�N���C���s�\��Ԃ̎��ɁC���D��x�^�X�N�iTASK5�j����TASK1���
 *		�D��x��chg_pri����ƁCTASK1�̗D��x���ω����Ȃ����Ƃ��m�F����D
 *		�܂��C���s�\��Ԃ̒��D��x�^�X�N��2�iTASK2�CTASK3�j��p�ӂ�
 *		�Ă����C�D�揇�ʂ��ς��Ȃ����Ƃ��m�F����D
 *	(A-4)
 *		���D��x�^�X�N�iTASK1�j�����D��x����~���[�e�b�N�X�iMTX2�j��҂�
 *		�Ă��鎞�ɁC���D��x�^�X�N�iTASK5�j����TASK1���D��x��
 *		chg_pri����ƁCMTX2��҂��Ă��鑼�̒�D��x�^�X�N�iTASK4�j���
 *		���C�҂��s�񒆂ł̏�������ɂȂ邱�Ƃ��m�F����D
 *	(A-5)
 *		���D��x�^�X�N�iTASK1�j���D��x���~���[�e�b�N�X�iMTX3�j�����b�N
 *		���C���D��x����~���[�e�b�N�X�iMTX2�j��҂��Ă��鎞�ɁC���D��x�^
 *		�X�N�iTASK5�j����TASK1���D��x��chg_pri����ƁCMTX2��҂��Ă�
 *		�鑼�̒�D��x�^�X�N�iTASK4�j�����C�҂��s�񒆂ł̏������ς��
 *		�Ȃ����Ƃ��m�F����D
 *	(A-6)
 *		���D��x�^�X�N�iTASK1�j�����D��x����~���[�e�b�N�X�iMTX1�j�����b
 *		�N���C���D��x����~���[�e�b�N�X�iMTX2�j��҂��Ă��鎞�ɁC���D
 *		��x�^�X�N�iTASK5�j����TASK1���D��x��chg_pri����ƁCTASK1��
 *		�D��x���ω����Ȃ����Ƃ��m�F����D�܂��CMTX2��҂��Ă��钆�D��
 *		�x�^�X�N��2�iTASK2�CTASK3�j��p�ӂ��Ă����C�҂��s�񒆂ł̏���
 *		���ς��Ȃ����Ƃ��m�F����D
 *	(B-1)
 *		���D��x�^�X�N�iTASK1�j�����D��x����~���[�e�b�N�X�iMTX1�j�����b
 *		�N���C���s�\��Ԃ̎��ɁC���D��x�^�X�N�iTASK5�j����TASK1����
 *		�D��x��chg_pri����ƁCE_ILUSE�G���[�ɂȂ邱�Ƃ��m�F����D
 *	(B-2)
 *		(A-3)�̃e�X�g���ڂŁCchg_pri��E_ILUSE�G���[�ɂȂ�Ȃ����ƂŊm�F
 *		�ł��Ă���D
 *	(B-3)
 *		���D��x�^�X�N�iTASK2�j�����D��x����~���[�e�b�N�X�iMTX1�j�̃��b
 *		�N��҂��Ă��鎞�ɁC���D��x�^�X�N�iTASK5�j����TASK2�����D��x
 *		��chg_pri����ƁCE_ILUSE�G���[�ɂȂ邱�Ƃ��m�F����D
 *	(B-4)
 *		(A-6)�̃e�X�g���ڂŁCchg_pri��E_ILUSE�G���[�ɂȂ�Ȃ����ƂŊm�F
 *		�ł��Ă���D
 *
 * �y�g�p���\�[�X�z
 *
 *	TASK1: ���D��x�^�X�N�C���C���^�X�N�C�ŏ�����N��
 *	TASK2: ���D��x�^�X�N
 *	TASK3: ���D��x�^�X�N
 *	TASK4: ��D��x�^�X�N
 *	TASK5: ���D��x�^�X�N
 *	MTX1: �~���[�e�b�N�X�iTA_CEILING�����C����͒��D��x�j
 *	MTX2: �~���[�e�b�N�X�iTA_CEILING�����C����͍��D��x�j
 *	MTX3: �~���[�e�b�N�X�iTA_TPRI�����j
 *
 * �y�e�X�g�V�[�P���X�z
 *
 *	== TASK1�i�D��x�F���j==
 *		call(set_bit_func(bit_mutex))
 *	1:	act_tsk(TASK4)
 *	2:	act_tsk(TASK5)
 *	//		���FTASK5�C���FTASK1�C��FTASK4
 *	== TASK5�i�D��x�F���j==
 *	3:	chg_pri(TASK1, LOW_PRIORITY)		... (A-1)
 *	//		���FTASK5�C��FTASK4��TASK1
 *	4:	slp_tsk()
 *	== TASK4�i�D��x�F��j==
 *	5:	slp_tsk()
 *	== TASK1�i�����j==
 *	6:	chg_pri(TSK_SELF, TPRI_INI)
 *
 *	7:	loc_mtx(MTX3)
 *	8:	wup_tsk(TASK4)
 *	9:	wup_tsk(TASK5)
 *	//		���FTASK5�C���FTASK1�C��FTASK4�CMTX3�FTASK1
 *	== TASK5�i�����j==
 *	10:	chg_pri(TASK1, LOW_PRIORITY)		... (A-2)
 *	//		���FTASK5�C��FTASK4��TASK1�CMTX3�FTASK1
 *	11:	slp_tsk()
 *	== TASK4�i�����j==
 *	12:	slp_tsk()
 *	== TASK1�i�����j==
 *	13:	unl_mtx(MTX3)
 *		chg_pri(TSK_SELF, TPRI_INI)
 *
 *	14:	loc_mtx(MTX1)
 *	15:	act_tsk(TASK2)
 *	16:	dis_dsp()
 *	17:	rot_rdq(MID_PRIORITY)
 *	18:	act_tsk(TASK3)
 *	//		���FTASK2��TASK1��TASK3�CMTX1�FTASK1
 *	19:	wup_tsk(TASK5)
 *	//		���FTASK5�C���FTASK2��TASK1��TASK3�CMTX1�FTASK1
 *	20:	ena_dsp()
 *	== TASK5�i�����j==
 *	21:	chg_pri(TASK1, LOW_PRIORITY)		... (A-3)(B-2)
 *	//		���FTASK5�C���FTASK2��TASK1��TASK3�CMTX1�FTASK1
 *		get_pri(TASK1, &tskpri)
 *		assert(tskpri == MID_PRIORITY)
 *	22:	slp_tsk()
 *	//		���FTASK2��TASK1��TASK3�CMTX1�FTASK1
 *	== TASK2�i�����j==
 *	23:	slp_tsk()
 *	//		���FTASK1��TASK3�CMTX1�FTASK1
 *	== TASK1�i�����j==
 *	24:	unl_mtx(MTX1)
 *	//		���FTASK3�C��FTASK1
 *	== TASK3�i�����j==
 *	25:	slp_tsk()
 *	== TASK1�i�����j==
 *	26:	chg_pri(TSK_SELF, TPRI_INI)
 *
 *	27:	wup_tsk(TASK5)
 *	== TASK5�i�����j==
 *	28:	loc_mtx(MTX2)
 *	29:	tslp_tsk(10) -> E_TMOUT
 *	== TASK1�i�����j==
 *	30:	wup_tsk(TASK4)
 *	31:	loc_mtx(MTX2)
 *	== TASK4�i�����j==
 *	32:	loc_mtx(MTX2)
 *	//		MTX2�FTASK5��TASK1��TASK4
 *	//		�^�C���A�E�g�҂�
 *	//		���FTASK5�CMTX2�FTASK5��TASK1��TASK4
 *	== TASK5�i�����j==
 *	33:	chg_pri(TASK1, LOW_PRIORITY)		... (A-4)
 *	//		���FTASK5�CMTX2�FTASK5��TASK4��TASK1
 *	34:	unl_mtx(MTX2)
 *	//		���FTASK5��TASK4�CMTX2�FTASK4��TASK1
 *	35:	slp_tsk()
 *	//		���FTASK4�CMTX2�FTASK4��TASK1
 *	== TASK4�i�����j==
 *	36:	unl_mtx(MTX2)
 *	//		���FTASK1�C��FTASK4�CMTX2�FTASK1
 *	== TASK1�i�����j==
 *	37:	unl_mtx(MTX2)
 *	//		��FTASK1��TASK4
 *	38:	chg_pri(TSK_SELF, TPRI_INI)
 *
 *	39:	loc_mtx(MTX3)
 *	40:	wup_tsk(TASK5)
 *	//		���FTASK5�C���FTASK1�C��FTASK4�CMTX3�FTASK1
 *	== TASK5�i�����j==
 *	41:	loc_mtx(MTX2)
 *	42:	tslp_tsk(10) -> E_TMOUT
 *	== TASK1�i�����j==
 *	43:	loc_mtx(MTX2)
 *	== TASK4�i�����j==
 *	44:	loc_mtx(MTX2)
 *	//		MTX2�FTASK5��TASK1��TASK4�CMTX3�FTASK1
 *	//		�^�C���A�E�g�҂�
 *	//		���FTASK5�CMTX2�FTASK5��TASK1��TASK4�CMTX3�FTASK1
 *	== TASK5�i�����j==
 *	45:	chg_pri(TASK1, LOW_PRIORITY)		... (A-5)
 *	//		���FTASK5�CMTX2�FTASK5��TASK4��TASK1�CMTX3�FTASK1
 *	46:	unl_mtx(MTX2)
 *	//		���FTASK5��TASK4�CMTX2�FTASK4��TASK1�CMTX3�FTASK1
 *	47:	slp_tsk()
 *	//		���FTASK4�CMTX2�FTASK4��TASK1�CMTX3�FTASK1
 *	== TASK4�i�����j==
 *	48:	unl_mtx(MTX2)
 *	//		���FTASK1�C��FTASK4�CMTX2�FTASK1�CMTX3�FTASK1
 *	== TASK1�i�����j==
 *	49:	unl_mtx(MTX2)
 *	//		��FTASK1��TASK4�CMTX3�FTASK1
 *	50:	unl_mtx(MTX3)
 *	//		��FTASK1��TASK4
 *	51:	ter_tsk(TASK4)
 *	52:	chg_pri(TSK_SELF, TPRI_INI)
 *
 *	53:	loc_mtx(MTX1)
 *	54:	wup_tsk(TASK5)
 *	//		���FTASK5�C���FTASK1�CMTX1�FTASK1
 *	== TASK5�i�����j==
 *	55:	loc_mtx(MTX2)
 *	56:	tslp_tsk(10) -> E_TMOUT
 *	//		���FTASK1�CMTX1�FTASK1�CMTX2�FTASK5
 *	== TASK1�i�����j==
 *	57:	wup_tsk(TASK2)
 *	58:	rot_rdq(MID_PRIORITY)
 *	== TASK2�i�����j==
 *	59:	loc_mtx(MTX2)
 *	//		���FTASK1�CMTX1�FTASK1�CMTX2�FTASK5��TASK2
 *	== TASK1�i�����j==
 *	60:	wup_tsk(TASK3)
 *	61:	loc_mtx(MTX2)
 *	//		���FTASK3�CMTX1�FTASK1�CMTX2�FTASK5��TASK2��TASK1
 *	== TASK3�i�����j==
 *	62:	loc_mtx(MTX2)
 *	//		MTX1�FTASK1�CMTX2�FTASK5��TASK2��TASK1��TASK3
 *	//		�^�C���A�E�g�҂�
 *	//		���FTASK5�CMTX1�FTASK1�CMTX2�FTASK5��TASK2��TASK1��TASK3
 *	== TASK5�i�����j==
 *	63:	chg_pri(TASK1, LOW_PRIORITY)		... (A-6)(B-4)
 *	//		���FTASK5�CMTX1�FTASK1�CMTX2�FTASK5��TASK2��TASK1��TASK3
 *		get_pri(TASK1, &tskpri)
 *		assert(tskpri == MID_PRIORITY)
 *	64:	unl_mtx(MTX2)
 *	//		���FTASK5��TASK2�CMTX1�FTASK1�CMTX2�FTASK2��TASK1��TASK3
 *	65:	slp_tsk()
 *	//		���FTASK2�CMTX1�FTASK1�CMTX2�FTASK2��TASK1��TASK3
 *	== TASK2�i�����j==
 *	66:	unl_mtx(MTX2)
 *	//		���FTASK1�C���FTASK2�CMTX1�FTASK1�CMTX2�FTASK1��TASK3
 *	== TASK1�i�����j==
 *	67:	unl_mtx(MTX2)
 *	//		���FTASK3�C���FTASK1��TASK2�CMTX1�FTASK1�CMTX2�FTASK3
 *	== TASK3�i�����j==
 *	68:	unl_mtx(MTX2)
 *	//		���FTASK3��TASK1��TASK2�CMTX1�FTASK1
 *	69:	ext_tsk() -> noreturn
 *	//		���FTASK1��TASK2�CMTX1�FTASK1
 *	== TASK1�i�����j==
 *	70:	chg_pri(TSK_SELF, TPRI_INI)
 *	//		���FTASK1��TASK2�CMTX1�FTASK1
 *
 *	71:	rot_rdq(MID_PRIORITY)
 *	//		���FTASK2��TASK1�CMTX1�FTASK1
 *	== TASK2�i�����j==
 *	72:	loc_mtx(MTX1)
 *	//		���FTASK1�CMTX1�FTASK1��TASK2
 *	== TASK1�i�����j==
 *	73:	wup_tsk(TASK5)
 *	//		���FTASK5�C���FTASK1�CMTX1�FTASK1��TASK2
 *	== TASK5�i�����j==
 *	74:	chg_pri(TASK1, HIGH_PRIORITY) -> E_ILUSE	... (B-1)
 *	75:	chg_pri(TASK2, HIGH_PRIORITY) -> E_ILUSE	... (B-3)
 *	76:	ext_tsk() -> noreturn
 *	//		���FTASK1�CMTX1�FTASK1��TASK2
 *	== TASK1�i�����j==
 *	77:	unl_mtx(MTX1)
 *	//		���FTASK1��TASK2�CMTX1�FTASK2
 *	78:	ext_tsk() -> noreturn
 *	== TASK2�i�����j==
 *	79:	unl_mtx(MTX1)
 *	80:	END
 */

#include <kernel.h>
#include <t_syslog.h>
#include "syssvc/logtask.h"
#include "kernel_cfg.h"
#include "test_lib.h"
#include "test_mutex8.h"

extern ER	bit_mutex(void);

void
task1(intptr_t exinf)
{
	ER		ercd;

	set_bit_func(bit_mutex);

	check_point(1);
	ercd = act_tsk(TASK4);
	check_ercd(ercd, E_OK);

	check_point(2);
	ercd = act_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(6);
	ercd = chg_pri(TSK_SELF, TPRI_INI);
	check_ercd(ercd, E_OK);

	check_point(7);
	ercd = loc_mtx(MTX3);
	check_ercd(ercd, E_OK);

	check_point(8);
	ercd = wup_tsk(TASK4);
	check_ercd(ercd, E_OK);

	check_point(9);
	ercd = wup_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(13);
	ercd = unl_mtx(MTX3);
	check_ercd(ercd, E_OK);

	ercd = chg_pri(TSK_SELF, TPRI_INI);
	check_ercd(ercd, E_OK);

	check_point(14);
	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(15);
	ercd = act_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(16);
	ercd = dis_dsp();
	check_ercd(ercd, E_OK);

	check_point(17);
	ercd = rot_rdq(MID_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(18);
	ercd = act_tsk(TASK3);
	check_ercd(ercd, E_OK);

	check_point(19);
	ercd = wup_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(20);
	ercd = ena_dsp();
	check_ercd(ercd, E_OK);

	check_point(24);
	ercd = unl_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(26);
	ercd = chg_pri(TSK_SELF, TPRI_INI);
	check_ercd(ercd, E_OK);

	check_point(27);
	ercd = wup_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(30);
	ercd = wup_tsk(TASK4);
	check_ercd(ercd, E_OK);

	check_point(31);
	ercd = loc_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(37);
	ercd = unl_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(38);
	ercd = chg_pri(TSK_SELF, TPRI_INI);
	check_ercd(ercd, E_OK);

	check_point(39);
	ercd = loc_mtx(MTX3);
	check_ercd(ercd, E_OK);

	check_point(40);
	ercd = wup_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(43);
	ercd = loc_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(49);
	ercd = unl_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(50);
	ercd = unl_mtx(MTX3);
	check_ercd(ercd, E_OK);

	check_point(51);
	ercd = ter_tsk(TASK4);
	check_ercd(ercd, E_OK);

	check_point(52);
	ercd = chg_pri(TSK_SELF, TPRI_INI);
	check_ercd(ercd, E_OK);

	check_point(53);
	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(54);
	ercd = wup_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(57);
	ercd = wup_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(58);
	ercd = rot_rdq(MID_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(60);
	ercd = wup_tsk(TASK3);
	check_ercd(ercd, E_OK);

	check_point(61);
	ercd = loc_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(67);
	ercd = unl_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(70);
	ercd = chg_pri(TSK_SELF, TPRI_INI);
	check_ercd(ercd, E_OK);

	check_point(71);
	ercd = rot_rdq(MID_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(73);
	ercd = wup_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(77);
	ercd = unl_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(78);
	ercd = ext_tsk();

	check_point(0);
}

void
task2(intptr_t exinf)
{
	ER		ercd;

	check_point(23);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(59);
	ercd = loc_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(66);
	ercd = unl_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(72);
	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(79);
	ercd = unl_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_finish(80);

	check_point(0);
}

void
task3(intptr_t exinf)
{
	ER		ercd;

	check_point(25);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(62);
	ercd = loc_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(68);
	ercd = unl_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(69);
	ercd = ext_tsk();

	check_point(0);
}

void
task4(intptr_t exinf)
{
	ER		ercd;

	check_point(5);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(12);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(32);
	ercd = loc_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(36);
	ercd = unl_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(44);
	ercd = loc_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(48);
	ercd = unl_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(0);
}

void
task5(intptr_t exinf)
{
	ER		ercd;
	PRI		tskpri;

	check_point(3);
	ercd = chg_pri(TASK1, LOW_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(4);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(10);
	ercd = chg_pri(TASK1, LOW_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(11);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(21);
	ercd = chg_pri(TASK1, LOW_PRIORITY);
	check_ercd(ercd, E_OK);

	ercd = get_pri(TASK1, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == MID_PRIORITY);

	check_point(22);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(28);
	ercd = loc_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(29);
	ercd = tslp_tsk(10);
	check_ercd(ercd, E_TMOUT);

	check_point(33);
	ercd = chg_pri(TASK1, LOW_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(34);
	ercd = unl_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(35);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(41);
	ercd = loc_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(42);
	ercd = tslp_tsk(10);
	check_ercd(ercd, E_TMOUT);

	check_point(45);
	ercd = chg_pri(TASK1, LOW_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(46);
	ercd = unl_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(47);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(55);
	ercd = loc_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(56);
	ercd = tslp_tsk(10);
	check_ercd(ercd, E_TMOUT);

	check_point(63);
	ercd = chg_pri(TASK1, LOW_PRIORITY);
	check_ercd(ercd, E_OK);

	ercd = get_pri(TASK1, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == MID_PRIORITY);

	check_point(64);
	ercd = unl_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(65);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(74);
	ercd = chg_pri(TASK1, HIGH_PRIORITY);
	check_ercd(ercd, E_ILUSE);

	check_point(75);
	ercd = chg_pri(TASK2, HIGH_PRIORITY);
	check_ercd(ercd, E_ILUSE);

	check_point(76);
	ercd = ext_tsk();

	check_point(0);
}
