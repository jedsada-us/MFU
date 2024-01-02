/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 * 
 *  Copyright (C) 2007-2009 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: test_mutex5.c 1696 2010-01-01 16:01:25Z ertl-hiro $
 */

/* 
 *		�~���[�e�b�N�X�̃e�X�g(5)
 *
 * �y�e�X�g�̖ړI�z
 *
 *  �D��x����~���[�e�b�N�X�ɑ΂��āC�~���[�e�b�N�X�̍ď������������
 *  ���I�Ƀe�X�g����D�������Cchange_priority��mutex_calc_priority�̓�
 *  �e�ɂ͓��ݍ��܂Ȃ��D
 *
 * �y�e�X�g���ځz
 *
 *	(A) �~���[�e�b�N�X�̏������iini_mtx�j�ɔ����~���[�e�b�N�X�����b�N��
 *		�Ă����^�X�N�i���s�ł����ԁj�̗D��x�ύX
 *		(A-1) �����������~���[�e�b�N�X�̏���D��x���C�~���[�e�b�N�X��
 *			  ���b�N���Ă����^�X�N�i���s�ł����ԁj�̌��ݗD��x�Ɠ���
 *			  �ŁC�~���[�e�b�N�X�̃��b�N�����ŗD��x��������ׂ��ꍇ�ɁC
 *			  ���Y�^�X�N�̗D��x���K�؂ɉ������邱�ƁD�܂��C�����D��
 *			  �x���ł̗D�揇�ʂ��ō��ɂȂ邱��
 *		(A-2) �����������~���[�e�b�N�X�̏���D��x���C�~���[�e�b�N�X��
 *			  ���b�N���Ă����^�X�N�i���s�ł����ԁj�̌��ݗD��x�Ɠ���
 *			  �ŁC�~���[�e�b�N�X�̃��b�N�����ŗD��x���ς��ׂ��łȂ�
 *			  �ꍇ�ɁC���Y�^�X�N�̗D��x���ς��Ȃ����ƁD�܂��C�����D
 *			  ��x���ł̗D�揇�ʂ��ς��Ȃ�����
 *		(A-3) �����������~���[�e�b�N�X�̏���D��x���C�~���[�e�b�N�X��
 *			  ���b�N���Ă����^�X�N�i���s�ł����ԁj�̌��ݗD��x����
 *			  �Ⴂ�ꍇ�ɁC���Y�^�X�N�̗D��x���ς��Ȃ����ƁD�܂��C��
 *			  ���D��x���ł̗D�揇�ʂ��ς��Ȃ�����
 *		(A-4) (A-1)�̌��ʁC�^�X�N�f�B�X�p�b�`���N���邱�ƁD
 *	(B) �~���[�e�b�N�X�̏������iini_mtx�j�ɔ����~���[�e�b�N�X�����b�N��
 *		�Ă����^�X�N�i�҂���ԁj�̗D��x�ύX
 *		(B-1) �����������~���[�e�b�N�X�̏���D��x���C�~���[�e�b�N�X��
 *			  ���b�N���Ă����^�X�N�i�҂���ԁj�̌��ݗD��x�Ɠ����ŁC
 *			  �~���[�e�b�N�X�̃��b�N�����ŗD��x��������ׂ��ꍇ�ɁC��
 *			  �Y�^�X�N�̗D��x���K�؂ɉ������邱�ƁD�܂��C�����D��x
 *			  ���ł̏������Ō�ɂȂ邱��
 *		(B-2) �����������~���[�e�b�N�X�̏���D��x���C�~���[�e�b�N�X��
 *			  ���b�N���Ă����^�X�N�i�҂���ԁj�̌��ݗD��x�Ɠ����ŁC
 *			  �~���[�e�b�N�X�̃��b�N�����ŗD��x���ς��ׂ��łȂ��ꍇ
 *			  �ɁC���Y�^�X�N�̗D��x���ς��Ȃ����ƁD�܂��C�����D��x
 *			  ���ł̏������ς��Ȃ�����
 *		(B-3) �����������~���[�e�b�N�X�̏���D��x���C�~���[�e�b�N�X��
 *			  ���b�N���Ă����^�X�N�i�҂���ԁj�̌��ݗD��x�����Ⴂ��
 *			  ���ɁC���Y�^�X�N�̗D��x���ς��Ȃ����ƁD�܂��C�����D��
 *			  �x���ł̏������ς��Ȃ�����
 *	(C) �~���[�e�b�N�X�̏������iini_mtx�j�ɔ����~���[�e�b�N�X��҂��Ă�
 *		���^�X�N�̏�ԕω�
 *		(C-1) �~���[�e�b�N�X��҂��Ă����^�X�N���҂���������邱�ƁD
 *		(C-2) (C-1)�̌��ʁC�^�X�N�f�B�X�p�b�`���N���邱�ƁD
 *
 * �y�e�X�g���ڂ̎������@�z
 *
 *	(A-1)
 *		��D��x�^�X�N�iTASK1�j���C���D��x����~���[�e�b�N�X�iMTX1�j��
 *		���b�N������ԂŁC���D��x�^�X�N�iTASK5�j����MTX1���ď��������C
 *		TASK1�̗D��x����D��x�ɉ����邱�Ƃ��m�F����D�܂��C���s�\��
 *		�Ԃ̒�D��x�^�X�N�iTASK2�j�����C�D�揇�ʂ������Ȃ邱�Ƃ��m�F
 *		����D�@
 *	(A-2)
 *		��D��x�^�X�N�iTASK1�j���C���D��x����~���[�e�b�N�X��2��
 *		�iMTX1�CMTX2�j�����b�N������ԂŁC���D��x�^�X�N�iTASK5�j����
 *		MTX1���ď��������CTASK1�̗D��x���ω����Ȃ����Ƃ��m�F����D�܂��C
 *		���s�\��Ԃ̒��D��x�^�X�N��2�iTASK3�CTASK4�j��p�ӂ��Ă����C
 *		�D�揇�ʂ��ς��Ȃ����Ƃ��m�F����D
 *	(A-3)
 *		��D��x�^�X�N�iTASK1�j���C���D��x����~���[�e�b�N�X�iMTX2�j��
 *		��D��x����~���[�e�b�N�X�iMTX3�j�����b�N������ԂŁC���D��x
 *		�^�X�N�iTASK5�j����MTX3���ď��������CTASK1�̗D��x���ω����Ȃ�
 *		���Ƃ��m�F����D�܂��C���s�\��Ԃ̒��D��x�^�X�N��2�iTASK3�C
 *		TASK4�j��p�ӂ��Ă����C�D�揇�ʂ��ς��Ȃ����Ƃ��m�F����D
 *	(A-4)
 *		��D��x�^�X�N�iTASK1�j���C���D��x����~���[�e�b�N�X�iMTX2�j��
 *		���b�N������ԂŁCTASK1����MTX2���ď��������CTASK1�̗D��x����
 *		�D��x�ɉ�����C���s�\��Ԃ̒��D��x�^�X�N�iTASK4�j�ɐ؂芷��
 *		�邱�Ƃ��m�F����D�܂��C���s�\��Ԃ̒�D��x�^�X�N�iTASK2�j��
 *		����C�D�揇�ʂ������Ȃ邱�Ƃ��m�F����D�@
 *	(B-1)
 *		��D��x�^�X�N�iTASK1�j���C���D��x����~���[�e�b�N�X�iMTX1�j��
 *		���b�N������ԂŁC�ʂ̃~���[�e�b�N�X�iMTX4�j�҂���ԂƂ��C���D
 *		��x�^�X�N�iTASK5�j����MTX1���ď��������CTASK1�̗D��x����D��
 *		�x�ɉ����邱�Ƃ��m�F����D�܂��CMTX4�҂���Ԃ̒�D��x�^�X�N
 *		�iTASK2�j�����C�҂��s�񒆂ł̏�������ɂȂ邱�Ƃ��m�F����D
 *	(B-2)
 *		��D��x�^�X�N�iTASK1�j���C���D��x����~���[�e�b�N�X��2��
 *		�iMTX1�CMTX2�j�����b�N������ԂŁC�ʂ̃~���[�e�b�N�X�iMTX4�j��
 *		����ԂƂ��C���D��x�^�X�N�iTASK5�j����MTX1���ď��������CTASK1
 *		�̗D��x���ω����Ȃ����Ƃ��m�F����D�܂��CMTX4�҂���Ԃ̒��D��
 *		�x�^�X�N��2�iTASK3�CTASK4�j��p�ӂ��Ă����C�҂��s�񒆂ł̏���
 *		���ς��Ȃ����Ƃ��m�F����D
 *	(B-3)
 *		��D��x�^�X�N�iTASK1�j���C���D��x����~���[�e�b�N�X�iMTX2�j��
 *		��D��x����~���[�e�b�N�X�iMTX3�j�����b�N������ԂŁC�ʂ̃~���[
 *		�e�b�N�X�iMTX4�j�҂���ԂƂ��C���D��x�^�X�N�iTASK5�j����MTX3��
 *		�ď��������CTASK1�̗D��x���ω����Ȃ����Ƃ��m�F����D�܂��C
 *		MTX4�҂���Ԃ̒��D��x�^�X�N��2�iTASK3�CTASK4�j��p�ӂ��Ă����C
 *		�҂��s�񒆂ł̏������ς��Ȃ����Ƃ��m�F����D
 *	(C-1)
 *		��D��x�^�X�N�iTASK1�j�����D��x����~���[�e�b�N�X�iMTX1�j�����b
 *		�N���C���D��x�^�X�N�iTASK3�j��MTX1��҂��Ă����ԂŁC���D��x
 *		�^�X�N�iTASK5�j����MTX1���ď��������CTASK3���҂���������邱��
 *		���m�F����D�܂��C���s�\��Ԃ̒��D��x�^�X�N�iTASK4�j�����C
 *		TASK3�̕����D�揇�ʂ��Ⴍ�Ȃ邱�Ƃ��m�F����D�@
 *	(C-2)
 *		��D��x�^�X�N�iTASK1�j�����D��x����~���[�e�b�N�X�iMTX1�j�����b
 *		�N���C���D��x�^�X�N�iTASK3�j��MTX1��҂��CTASK1���N���҂����
 *		�Ƃ�����ԂŁC�ʂ̒�D��x�^�X�N�iTASK2�j����MTX1���ď��������C
 *		TASK3���҂���������CTASK3�ɐ؂芷��邱�Ƃ��m�F����D
 *
 * �y�g�p���\�[�X�z
 *
 *	TASK1: ��D��x�^�X�N�C���C���^�X�N�C�ŏ�����N��
 *	TASK2: ��D��x�^�X�N
 *	TASK3: ���D��x�^�X�N
 *	TASK4: ���D��x�^�X�N
 *	TASK5: ���D��x�^�X�N
 *	MTX1: �~���[�e�b�N�X�iTA_CEILING�����C����͒��D��x�j
 *	MTX2: �~���[�e�b�N�X�iTA_CEILING�����C����͒��D��x�j
 *	MTX3: �~���[�e�b�N�X�iTA_CEILING�����C����͒�D��x�j
 *	MTX4: �~���[�e�b�N�X�iTA_CEILING�����C����͍��D��x�j
 *
 * �y�e�X�g�V�[�P���X�z
 *
 *	== TASK1�i�D��x�F��j==
 *		call(set_bit_func(bit_mutex))
 *	1:	loc_mtx(MTX1)
 *	2:	act_tsk(TASK2)
 *	3:	act_tsk(TASK5)
 *	//		���FTASK5�C���FTASK1�C��FTASK2�CMTX1�FTASK1
 *	== TASK5�i�D��x�F���j==
 *	4:	ini_mtx(MTX1)			... (A-1)
 *	//		���FTASK5�C��FTASK1��TASK2
 *		get_pri(TASK1, &tskpri)
 *		assert(tskpri == LOW_PRIORITY)
 *	5:	slp_tsk()
 *	//		��FTASK1��TASK2
 *
 *	== TASK1�i�����j==
 *	6:	sus_tsk(TASK2)
 *	7:	loc_mtx(MTX1)
 *		loc_mtx(MTX2)
 *	8:	act_tsk(TASK3)
 *	//		���FTASK1��TASK3�CMTX1�FTASK1�CMTX2�FTASK1
 *	9:	dis_dsp()
 *	10:	rot_rdq(MID_PRIORITY)
 *	//		���FTASK3��TASK1�CMTX1�FTASK1�CMTX2�FTASK1
 *	11:	act_tsk(TASK4)
 *	//		���FTASK3��TASK1��TASK4�CMTX1�FTASK1�CMTX2�FTASK1
 *	12:	wup_tsk(TASK5)
 *	//		���FTASK5�C���FTASK3��TASK1��TASK4�CMTX1�FTASK1�CMTX2�FTASK1
 *	13:	ena_dsp()
 *	== TASK5�i�����j==
 *	14:	ini_mtx(MTX1)			... (A-2)
 *	//		���FTASK5�C���FTASK3��TASK1��TASK4�CMTX2�FTASK1
 *		get_pri(TASK1, &tskpri)
 *		assert(tskpri == MID_PRIORITY)
 *	15:	slp_tsk()
 *	//		���FTASK3��TASK1��TASK4�CMTX2�FTASK1
 *	== TASK3�i�D��x�F���j==
 *	16:	slp_tsk()
 *	//		���FTASK1��TASK4�CMTX2�FTASK1
 *	== TASK1�i�����j==
 *	17:	slp_tsk()
 *	//		���FTASK4�CMTX2�FTASK1
 *	== TASK4�i�D��x�F���j==
 *	18:	wup_tsk(TASK1)
 *	//		���FTASK4��TASK1�CMTX2�FTASK1
 *	19:	slp_tsk()
 *	//		���FTASK1�CMTX2�FTASK1
 *
 *	== TASK1�i�����j==
 *	20:	loc_mtx(MTX3)
 *	//		���FTASK1�CMTX2�FTASK1�CMTX3�FTASK1
 *	21:	wup_tsk(TASK3)
 *	//		���FTASK1��TASK3�CMTX2�FTASK1�CMTX3�FTASK1
 *	22:	dis_dsp()
 *	23:	rot_rdq(MID_PRIORITY)
 *	//		���FTASK3��TASK1�CMTX2�FTASK1�CMTX3�FTASK1
 *	24:	wup_tsk(TASK4)
 *	//		���FTASK3��TASK1��TASK4�CMTX2�FTASK1�CMTX3�FTASK1
 *	25:	wup_tsk(TASK5)
 *	//		���FTASK5�C���FTASK3��TASK1��TASK4�CMTX2�FTASK1�CMTX3�FTASK1
 *	26:	ena_dsp()
 *	== TASK5�i�����j==
 *	27:	ini_mtx(MTX3)			... (A-3)
 *	//		���FTASK5�C���FTASK3��TASK1��TASK4�CMTX2�FTASK1
 *		get_pri(TASK1, &tskpri)
 *		assert(tskpri == MID_PRIORITY)
 *	28:	slp_tsk()
 *	//		���FTASK3��TASK1��TASK4�CMTX2�FTASK1
 *	== TASK3�i�����j==
 *	29:	slp_tsk()
 *	//		���FTASK1��TASK4�CMTX2�FTASK1
 *
 *	== TASK1�i�����j==
 *	30:	slp_tsk()
 *	//		���FTASK4�CMTX2�FTASK1
 *	== TASK4�i�����j==
 *	31:	wup_tsk(TASK1)
 *	//		���FTASK4��TASK1�CMTX2�FTASK1
 *	32:	rot_rdq(MID_PRIORITY)
 *	//		���FTASK1��TASK4�CMTX2�FTASK1
 *	== TASK1�i�����j==
 *	33:	rsm_tsk(TASK2)
 *	//		���FTASK1��TASK4�C��FTASK2�CMTX2�FTASK1
 *	34:	ini_mtx(MTX2)			... (A-4)
 *	//		���FTASK4�C��FTASK1��TASK2
 *	== TASK4�i�����j==
 *	35:	get_pri(TASK1, &tskpri)
 *		assert(tskpri == LOW_PRIORITY)
 *	36:	slp_tsk()
 *	//		��FTASK1��TASK2
 *
 *	== TASK1�i�����j==
 *	37:	wup_tsk(TASK5)
 *	== TASK5�i�����j==
 *	38:	loc_mtx(MTX4)
 *	39:	tslp_tsk(10) -> E_TMOUT
 *	//		��FTASK1��TASK2�CMTX4�FTASK5
 *	== TASK1�i�����j==
 *	40:	loc_mtx(MTX1)
 *	//		���FTASK1�C��FTASK2�CMTX1�FTASK1�CMTX4�FTASK5
 *	41:	loc_mtx(MTX4)
 *	//		��FTASK2�CMTX1�FTASK1�CMTX4�FTASK5��TASK1
 *	== TASK2�i�D��x�F��j==
 *	42:	loc_mtx(MTX4)
 *	//		MTX1�FTASK1�CMTX4�FTASK5��TASK1��TASK2
 *	//		�^�C���A�E�g�҂�
 *	//		���FTASK5�CMTX1�FTASK1�CMTX4�FTASK5��TASK1��TASK2
 *	== TASK5�i�����j==
 *	43:	ini_mtx(MTX1)			... (B-1)
 *	//		���FTASK5�CMTX4�FTASK5��TASK2��TASK1
 *		get_pri(TASK1, &tskpri)
 *		assert(tskpri == LOW_PRIORITY)
 *	44:	unl_mtx(MTX4)
 *	//		���FTASK5��TASK2�CMTX4�FTASK2��TASK1
 *	45:	slp_tsk()
 *	//		���FTASK2�CMTX4�FTASK2��TASK1
 *	== TASK2�i�����j==
 *	46:	unl_mtx(MTX4)
 *	//		���FTASK1�C��FTASK2�CMTX4�FTASK1
 *	== TASK1�i�����j==
 *	47:	unl_mtx(MTX4)
 *	//		��FTASK1��TASK2
 *
 *	48:	wup_tsk(TASK5)
 *	== TASK5�i�����j==
 *	49:	loc_mtx(MTX4)
 *	50:	slp_tsk()
 *	//		��FTASK1��TASK2�CMTX4�FTASK5
 *	== TASK1�i�����j==
 *	51:	wup_tsk(TASK3)
 *	//		���FTASK3�C��FTASK1��TASK2�CMTX4�FTASK5
 *	== TASK3�i�����j==
 *	52:	loc_mtx(MTX4)
 *	//		��FTASK1��TASK2�CMTX4�FTASK5��TASK3
 *	== TASK1�i�����j==
 *	53:	loc_mtx(MTX1)
 *		loc_mtx(MTX2)
 *	//		���FTASK1�C��FTASK2�CMTX1�FTASK1�CMTX2�FTASK1�CMTX4�FTASK5��TASK3
 *	54:	loc_mtx(MTX4)
 *	//		��FTASK2�CMTX1�FTASK1�CMTX2�FTASK1�CMTX4�FTASK5��TASK3��TASK1
 *	== TASK2�i�����j==
 *	55:	wup_tsk(TASK4)
 *	== TASK4�i�����j==
 *	56:	loc_mtx(MTX4)
 *	//		��FTASK2�CMTX1�FTASK1�CMTX2�FTASK1�C
 *	//								MTX4�FTASK5��TASK3��TASK1��TASK4
 *	== TASK2�i�����j==
 *	57:	wup_tsk(TASK5)
 *	//		���FTASK5�C��FTASK2�CMTX1�FTASK1�CMTX2�FTASK1�C
 *	//								MTX4�FTASK5��TASK3��TASK1��TASK4
 *	== TASK5�i�����j==
 *	58:	ini_mtx(MTX1)			... (B-2)
 *	//		���FTASK5�C��FTASK2�CMTX2�FTASK1�CMTX4�FTASK5��TASK3��TASK1��TASK4
 *		get_pri(TASK1, &tskpri)
 *		assert(tskpri == MID_PRIORITY)
 *	59:	unl_mtx(MTX4)
 *	//		���FTASK5��TASK3�C��FTASK2�CMTX2�FTASK1�CMTX4�FTASK3��TASK1��TASK4
 *	60:	slp_tsk()
 *	//		���FTASK3�C��FTASK2�CMTX2�FTASK1�CMTX4�FTASK3��TASK1��TASK4
 *	== TASK3�i�����j==
 *	61:	unl_mtx(MTX4)
 *	//		���FTASK1�C���FTASK3�C��FTASK2�CMTX2�FTASK1�CMTX4�FTASK1��TASK4
 *	== TASK1�i�����j==
 *	62:	unl_mtx(MTX4)
 *	//		���FTASK4�C���FTASK1��TASK3�C��FTASK2�CMTX2�FTASK1�CMTX4�FTASK4
 *	== TASK4�i�����j==
 *	63:	unl_mtx(MTX4)
 *	//		���FTASK4��TASK1��TASK3�C��FTASK2�CMTX2�FTASK1
 *	64:	slp_tsk()
 *	//		���FTASK1��TASK3�C��FTASK2�CMTX2�FTASK1
 *	== TASK1�i�����j==
 *	65:	slp_tsk()
 *	//		���FTASK3�C��FTASK2�CMTX2�FTASK1
 *	== TASK3�i�����j==
 *	66:	slp_tsk()
 *	//		��FTASK2�CMTX2�FTASK1
 *
 *	== TASK2�i�����j==
 *	67: wup_tsk(TASK5)
 *	== TASK5�i�����j==
 *	68:	loc_mtx(MTX4)
 *	69:	slp_tsk()
 *	//		��FTASK2�CMTX4�FTASK5
 *	== TASK2�i�����j==
 *	70:	wup_tsk(TASK3)
 *	== TASK3�i�����j==
 *	71:	loc_mtx(MTX4)
 *	//		��FTASK2�CMTX4�FTASK5��TASK3
 *	== TASK2�i�����j==
 *	72:	wup_tsk(TASK1)
 *	//		���FTASK1�C��FTASK2�CMTX4�FTASK5
 *	== TASK1�i�����j==
 *	73:	loc_mtx(MTX3)
 *	//		���FTASK1�C��FTASK2�CMTX2�FTASK1�CMTX3�FTASK1�CMTX4�FTASK5��TASK3
 *	74:	loc_mtx(MTX4)
 *	//		��FTASK2�CMTX2�FTASK1�CMTX3�FTASK1�CMTX4�FTASK5��TASK3��TASK1
 *	== TASK2�i�����j==
 *	75:	wup_tsk(TASK4)
 *	== TASK4�i�����j==
 *	76:	loc_mtx(MTX4)
 *	//		��FTASK2�CMTX2�FTASK1�CMTX3�FTASK1�C
 *	//								MTX4�FTASK5��TASK3��TASK1��TASK4
 *	== TASK2�i�����j==
 *	77:	wup_tsk(TASK5)
 *	//		���FTASK5�C��FTASK2�CMTX2�FTASK1�CMTX3�FTASK1�C
 *	//								MTX4�FTASK5��TASK3��TASK1��TASK4
 *	== TASK5�i�����j==
 *	78:	ini_mtx(MTX3)			... (B-3)
 *	//		���FTASK5�C��FTASK2�CMTX2�FTASK1�CMTX4�FTASK5��TASK3��TASK1��TASK4
 *		get_pri(TASK1, &tskpri)
 *		assert(tskpri == MID_PRIORITY)
 *	79:	unl_mtx(MTX4)
 *	//		���FTASK5��TASK3�C��FTASK2�CMTX2�FTASK1�CMTX4�FTASK3��TASK1��TASK4
 *	80:	slp_tsk()
 *	//		���FTASK3�C��FTASK2�CMTX2�FTASK1�CMTX4�FTASK3��TASK1��TASK4
 *	== TASK3�i�����j==
 *	81:	unl_mtx(MTX4)
 *	//		���FTASK1�C���FTASK3�C��FTASK2�CMTX2�FTASK1�CMTX4�FTASK1��TASK4
 *	== TASK1�i�����j==
 *	82:	unl_mtx(MTX4)
 *	//		���FTASK4�C���FTASK1��TASK3�C��FTASK2�CMTX2�FTASK1�CMTX4�FTASK4
 *	== TASK4�i�����j==
 *	83:	unl_mtx(MTX4)
 *	//		���FTASK4��TASK1��TASK3�C��FTASK2�CMTX2�FTASK1
 *	84:	slp_tsk()
 *	//		���FTASK1��TASK3�C��FTASK2�CMTX2�FTASK1
 *	== TASK1�i�����j==
 *	85:	unl_mtx(MTX2)
 *	//		���FTASK3�C��FTASK1��TASK2
 *	== TASK3�i�����j==
 *	86:	slp_tsk()
 *	//		��FTASK1��TASK2
 *
 *	== TASK1�i�����j==
 *	87:	sus_tsk(TASK2)
 *	//		��FTASK1
 *	88:	loc_mtx(MTX1)
 *	//		���FTASK1�CMTX1�FTASK1
 *	89:	wup_tsk(TASK3)
 *	//		���FTASK1��TASK3�CMTX1�FTASK1
 *	90:	rot_rdq(MID_PRIORITY)
 *	//		���FTASK3��TASK1�CMTX1�FTASK1
 *	== TASK3�i�����j==
 *	91:	loc_mtx(MTX1) -> E_DLT
 *	//		���FTASK1�CMTX1�FTASK1��TASK3
 *	== TASK1�i�����j==
 *	92:	wup_tsk(TASK5)
 *	//		���FTASK5�C���FTASK1�CMTX1�FTASK1��TASK3
 *	== TASK5�i�����j==
 *	93:	wup_tsk(TASK4)
 *	//		���FTASK5�C���FTASK1��TASK4�CMTX1�FTASK1��TASK3
 *	94:	ini_mtx(MTX1)			... (C-1)
 *	//		���FTASK5�C���FTASK4��TASK3�C��FTASK1
 *	95:	ext_tsk() -> noreturn
 *	//		���FTASK4��TASK3�C��FTASK1
 *	== TASK4�i�����j==
 *	96:	ext_tsk() -> noreturn
 *	//		���FTASK3�C��FTASK1
 *	== TASK3�i�����j==
 *	97:	slp_tsk()
 *	//		��FTASK1
 *
 *	== TASK1�i�����j==
 *	98:	loc_mtx(MTX1)
 *	//		���FTASK1�CMTX1�FTASK1
 *	99:	wup_tsk(TASK3)
 *	//		���FTASK1��TASK3�CMTX1�FTASK1
 * 100:	rot_rdq(MID_PRIORITY)
 *	//		���FTASK3��TASK1�CMTX1�FTASK1
 *	== TASK3�i�����j==
 * 101:	loc_mtx(MTX1) -> E_DLT
 *	//		���FTASK1�CMTX1�FTASK1��TASK3
 *	== TASK1�i�����j==
 * 102:	rsm_tsk(TASK2)
 *	//		���FTASK1�C��FTASK2�CMTX1�FTASK1��TASK3
 * 103:	slp_tsk()
 *	//		��FTASK2�CMTX1�FTASK1��TASK3
 *	== TASK2�i�����j==
 * 104:	ini_mtx(MTX1)			... (C-2)
 *	//		���FTASK3�C��FTASK2
 *	== TASK3�i�����j==
 * 105:	ext_tsk() -> noreturn
 *	//		��FTASK2
 *	== TASK2�i�����j==
 * 106:	ter_tsk(TASK1)
 * 107:	END
 */

#include <kernel.h>
#include <t_syslog.h>
#include "syssvc/logtask.h"
#include "kernel_cfg.h"
#include "test_lib.h"
#include "test_mutex5.h"

extern ER	bit_mutex(void);

void
task1(intptr_t exinf)
{
	ER		ercd;

	set_bit_func(bit_mutex);

	check_point(1);
	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(2);
	ercd = act_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(3);
	ercd = act_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(6);
	ercd = sus_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(7);
	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_OK);

	ercd = loc_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(8);
	ercd = act_tsk(TASK3);
	check_ercd(ercd, E_OK);

	check_point(9);
	ercd = dis_dsp();
	check_ercd(ercd, E_OK);

	check_point(10);
	ercd = rot_rdq(MID_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(11);
	ercd = act_tsk(TASK4);
	check_ercd(ercd, E_OK);

	check_point(12);
	ercd = wup_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(13);
	ercd = ena_dsp();
	check_ercd(ercd, E_OK);

	check_point(17);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(20);
	ercd = loc_mtx(MTX3);
	check_ercd(ercd, E_OK);

	check_point(21);
	ercd = wup_tsk(TASK3);
	check_ercd(ercd, E_OK);

	check_point(22);
	ercd = dis_dsp();
	check_ercd(ercd, E_OK);

	check_point(23);
	ercd = rot_rdq(MID_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(24);
	ercd = wup_tsk(TASK4);
	check_ercd(ercd, E_OK);

	check_point(25);
	ercd = wup_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(26);
	ercd = ena_dsp();
	check_ercd(ercd, E_OK);

	check_point(30);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(33);
	ercd = rsm_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(34);
	ercd = ini_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(37);
	ercd = wup_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(40);
	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(41);
	ercd = loc_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(47);
	ercd = unl_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(48);
	ercd = wup_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(51);
	ercd = wup_tsk(TASK3);
	check_ercd(ercd, E_OK);

	check_point(53);
	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_OK);

	ercd = loc_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(54);
	ercd = loc_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(62);
	ercd = unl_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(65);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(73);
	ercd = loc_mtx(MTX3);
	check_ercd(ercd, E_OK);

	check_point(74);
	ercd = loc_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(82);
	ercd = unl_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(85);
	ercd = unl_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(87);
	ercd = sus_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(88);
	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(89);
	ercd = wup_tsk(TASK3);
	check_ercd(ercd, E_OK);

	check_point(90);
	ercd = rot_rdq(MID_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(92);
	ercd = wup_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(98);
	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(99);
	ercd = wup_tsk(TASK3);
	check_ercd(ercd, E_OK);

	check_point(100);
	ercd = rot_rdq(MID_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(102);
	ercd = rsm_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(103);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(0);
}

void
task2(intptr_t exinf)
{
	ER		ercd;

	check_point(42);
	ercd = loc_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(46);
	ercd = unl_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(55);
	ercd = wup_tsk(TASK4);
	check_ercd(ercd, E_OK);

	check_point(57);
	ercd = wup_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(67);
	ercd = wup_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(70);
	ercd = wup_tsk(TASK3);
	check_ercd(ercd, E_OK);

	check_point(72);
	ercd = wup_tsk(TASK1);
	check_ercd(ercd, E_OK);

	check_point(75);
	ercd = wup_tsk(TASK4);
	check_ercd(ercd, E_OK);

	check_point(77);
	ercd = wup_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(104);
	ercd = ini_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(106);
	ercd = ter_tsk(TASK1);
	check_ercd(ercd, E_OK);

	check_finish(107);

	check_point(0);
}

void
task3(intptr_t exinf)
{
	ER		ercd;

	check_point(16);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(29);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(52);
	ercd = loc_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(61);
	ercd = unl_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(66);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(71);
	ercd = loc_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(81);
	ercd = unl_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(86);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(91);
	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_DLT);

	check_point(97);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(101);
	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_DLT);

	check_point(105);
	ercd = ext_tsk();

	check_point(0);
}

void
task4(intptr_t exinf)
{
	ER		ercd;
	PRI		tskpri;

	check_point(18);
	ercd = wup_tsk(TASK1);
	check_ercd(ercd, E_OK);

	check_point(19);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(31);
	ercd = wup_tsk(TASK1);
	check_ercd(ercd, E_OK);

	check_point(32);
	ercd = rot_rdq(MID_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(35);
	ercd = get_pri(TASK1, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == LOW_PRIORITY);

	check_point(36);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(56);
	ercd = loc_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(63);
	ercd = unl_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(64);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(76);
	ercd = loc_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(83);
	ercd = unl_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(84);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(96);
	ercd = ext_tsk();

	check_point(0);
}

void
task5(intptr_t exinf)
{
	ER		ercd;
	PRI		tskpri;

	check_point(4);
	ercd = ini_mtx(MTX1);
	check_ercd(ercd, E_OK);

	ercd = get_pri(TASK1, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == LOW_PRIORITY);

	check_point(5);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(14);
	ercd = ini_mtx(MTX1);
	check_ercd(ercd, E_OK);

	ercd = get_pri(TASK1, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == MID_PRIORITY);

	check_point(15);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(27);
	ercd = ini_mtx(MTX3);
	check_ercd(ercd, E_OK);

	ercd = get_pri(TASK1, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == MID_PRIORITY);

	check_point(28);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(38);
	ercd = loc_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(39);
	ercd = tslp_tsk(10);
	check_ercd(ercd, E_TMOUT);

	check_point(43);
	ercd = ini_mtx(MTX1);
	check_ercd(ercd, E_OK);

	ercd = get_pri(TASK1, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == LOW_PRIORITY);

	check_point(44);
	ercd = unl_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(45);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(49);
	ercd = loc_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(50);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(58);
	ercd = ini_mtx(MTX1);
	check_ercd(ercd, E_OK);

	ercd = get_pri(TASK1, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == MID_PRIORITY);

	check_point(59);
	ercd = unl_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(60);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(68);
	ercd = loc_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(69);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(78);
	ercd = ini_mtx(MTX3);
	check_ercd(ercd, E_OK);

	ercd = get_pri(TASK1, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == MID_PRIORITY);

	check_point(79);
	ercd = unl_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(80);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(93);
	ercd = wup_tsk(TASK4);
	check_ercd(ercd, E_OK);

	check_point(94);
	ercd = ini_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(95);
	ercd = ext_tsk();

	check_point(0);
}
