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
 *  @(#) $Id: test_task1.c 1577 2009-05-31 14:30:51Z ertl-hiro $
 */

/* 
 *		�^�X�N�Ǘ����W���[���̃e�X�g(1)
 *
 * �y�e�X�g�̖ړI�z
 *
 *  make_runnable��make_non_runnable��ԗ��I�Ƀe�X�g����D
 *
 * �y�e�X�g���ځz
 *
 *	(A) ���s��Ԃ̃^�X�N���������D��x�̃^�X�N�����s�ł����Ԃɂ���
 *		(A-1) �f�B�X�p�b�`�ۗ���Ԃł͂Ȃ��ꍇ
 *		(A-2) �f�B�X�p�b�`�ۗ���Ԃ̏ꍇ
 *	(B) ���s��Ԃ̃^�X�N�Ɠ����D��x�̃^�X�N�����s�ł����Ԃɂ���
 *		�I�����D��x�̃^�X�N�̒��̖����ɓ��邱�Ƃ��m�F����
 *	(C) ���s��Ԃ̃^�X�N�����Ⴂ�D��x�̃^�X�N�����s�ł����Ԃɂ���
 *		�I�����D��x�̃^�X�N�̒��̖����ɓ��邱�Ƃ��m�F����
 *	(D) ���s�ł����Ԃ̃^�X�N���Ȃ���ԂŁC�^�X�N�����s�ł����Ԃɂ���
 *		�I���̏ꍇ�́C�f�B�X�p�b�`�ۗ���Ԃł͂Ȃ�
 *	(E) �f�B�X�p�b�`�ۗ���ԂŁC���s��ԂɂȂ�ׂ��������s�\��ԃ^�X
 *		�N���������D��x�̃^�X�N���C���s�ł����Ԃɂ���
 *	(F) �f�B�X�p�b�`�ۗ���ԂŁC���s��ԂɂȂ�ׂ��������s�\��ԃ^�X
 *		�N�Ɠ����D��x�̃^�X�N���C���s�ł����Ԃɂ���
 *	(G) �f�B�X�p�b�`�ۗ���ԂŁC���s��ԂɂȂ�ׂ��������s�\��ԃ^�X
 *		�N�����Ⴂ�D��x�̃^�X�N���C���s�ł����Ԃɂ���
 *	(H) ���s��Ԃ̃^�X�N���C���s�ł����ԂłȂ���
 *		(H-1) ���s�ł����Ԃ̃^�X�N���Ȃ��Ȃ�ꍇ
 *		(H-2) ����D��x�̃^�X�N���Ȃ��Ȃ�ꍇ
 *		(H-3) ����D��x�̃^�X�N���Ȃ��Ȃ�Ȃ��ꍇ
 *	(I) ���s�\��Ԃ̃^�X�N���C���s�ł����ԂłȂ���
 *		(I-1) ����D��x�̃^�X�N���Ȃ��Ȃ�ꍇ
 *		(I-2) ����D��x�̃^�X�N���Ȃ��Ȃ�Ȃ��ꍇ
 *	(J) �f�B�X�p�b�`�ۗ���ԂŁC���s��ԂɂȂ�ׂ��������s�\��ԂƂȂ�
 *		�Ă���^�X�N���C���s�ł����ԂłȂ���
 *		(J-1) ����D��x�̃^�X�N���Ȃ��Ȃ�ꍇ
 *		(J-2) ����D��x�̃^�X�N���Ȃ��Ȃ�Ȃ��ꍇ
 *	(K) �f�B�X�p�b�`�ۗ���ԂŁC���s�\��ԂɂȂ�ׂ��������s��Ԃ̃^
 *		�X�N���C���s�ł����ԂłȂ���
 *		�I�f�B�X�p�b�`�ۗ��ł́C���s��Ԃ̃^�X�N�����s�ł����ԂłȂ�
 *		�Ȃ�悤�ȑJ�ڂ��N�������Ƃ��ł��Ȃ����߁C���̏󋵂͋N����Ȃ��D
 *
 * �y�g�p���\�[�X�z
 *
 *	TASK1: ���D��x�^�X�N�C���C���^�X�N�C�ŏ�����N��
 *	TASK2: ���D��x�^�X�N
 *	TASK3: ���D��x�^�X�N
 *	TASK4: ���D��x�^�X�N
 *	TASK5: ��D��x�^�X�N
 *	TASK6: ��D��x�^�X�N
 *	ALM1:  �A���[���n���h��
 *
 * �y�e�X�g�V�[�P���X�z
 *
 *	== TASK1�i�D��x�F���j==
 *	1:	act_tsk(TASK2)					... (A-1)
 *	== TASK2�i�D��x�F���j==
 *	2:	slp_tsk()						... (H-2)
 *	== TASK1�i�����j==
 *	3:	act_tsk(TASK3)					... (B)
 *	4:	act_tsk(TASK4)					... (B)
 *	5:	slp_tsk()						... (H-3)
 *	== TASK3�i�D��x�F���j==
 *	6:	slp_tsk()						... (H-3)
 *	== TASK4�i�D��x�F���j==
 *	7:	wup_tsk(TASK1)
 *	8:	slp_tsk()						... (H-3)
 *	== TASK1�i�����j==
 *	9:	act_tsk(TASK5)					... (C)
 *	10:	act_tsk(TASK6)					... (C)
 *	11:	sus_tsk(TASK6)					... (I-2)
 *	12:	sus_tsk(TASK5)					... (I-1)
 *	13:	rsm_tsk(TASK5)					... (C)
 *	14:	rsm_tsk(TASK6)					... (C)
 *	15:	slp_tsk()						... (H-2)
 *	== TASK5�i�D��x�F��j==
 *	16:	slp_tsk()						... (H-3)
 *	== TASK6�i�D��x�F��j==
 *	17:	dis_dsp()
 *	18:	wup_tsk(TASK1)					... (A-2)
 *	19:	wup_tsk(TASK2)					... (E)
 *	20:	sus_tsk(TASK2)					... (J-1)
 *	21:	wup_tsk(TASK3)					... (F)
 *	22:	wup_tsk(TASK4)					... (F)
 *	23:	sus_tsk(TASK1)					... (J-2)
 *	24:	ena_dsp()
 *	== TASK3�i�����j==
 *	25:	slp_tsk()						... (H-3)
 *	== TASK4�i�����j==
 *	26:	slp_tsk()						... (H-2)
 *	== TASK6�i�����j==
 *	27:	dis_dsp()
 *	28:	rsm_tsk(TASK1)					... (A-2)
 *	29:	wup_tsk(TASK5)					... (G)
 *	30:	ena_dsp()
 *	== TASK1�i�����j==
 *	31:	slp_tsk()						... (H-2)
 *	== TASK6�i�����j==
 *	32:	slp_tsk()						... (H-3)
 *	== TASK5�i�����j==
 *	33:	sta_alm(ALM1, 10)
 *	34:	slp_tsk()						... (H-1)
 *	== ALM1 ==
 *	35:	iget_tid(&tskid)
 *		assert(tskid == TSK_NONE)
 *	36:	iwup_tsk(TASK1)					... (D)
 *	37:	RETURN
 *	== TASK1�i�����j==
 *	38: END
 */

#include <kernel.h>
#include <test_lib.h>
#include <t_syslog.h>
#include "kernel_cfg.h"
#include "test_task1.h"

void
alarm1_handler(intptr_t exinf)
{
	ER		ercd;
	ID		tskid;

	check_point(35);
	ercd = iget_tid(&tskid);
	check_ercd(ercd, E_OK);
	check_assert(tskid == TSK_NONE);

	check_point(36);
	ercd = iwup_tsk(TASK1);
	check_ercd(ercd, E_OK);

	check_point(37);
	return;

	check_point(0);
}

void
task1(intptr_t exinf)
{
	ER		ercd;

	check_point(1);
	ercd = act_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(3);
	ercd = act_tsk(TASK3);
	check_ercd(ercd, E_OK);

	check_point(4);
	ercd = act_tsk(TASK4);
	check_ercd(ercd, E_OK);

	check_point(5);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(9);
	ercd = act_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(10);
	ercd = act_tsk(TASK6);
	check_ercd(ercd, E_OK);

	check_point(11);
	ercd = sus_tsk(TASK6);
	check_ercd(ercd, E_OK);

	check_point(12);
	ercd = sus_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(13);
	ercd = rsm_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(14);
	ercd = rsm_tsk(TASK6);
	check_ercd(ercd, E_OK);

	check_point(15);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(31);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_finish(38);

	check_point(0);
}

void
task2(intptr_t exinf)
{
	ER		ercd;

	check_point(2);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(0);
}

void
task3(intptr_t exinf)
{
	ER		ercd;

	check_point(6);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(25);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(0);
}

void
task4(intptr_t exinf)
{
	ER		ercd;

	check_point(7);
	ercd = wup_tsk(TASK1);
	check_ercd(ercd, E_OK);

	check_point(8);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(26);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(0);
}

void
task5(intptr_t exinf)
{
	ER		ercd;

	check_point(16);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(33);
	ercd = sta_alm(ALM1, 10);
	check_ercd(ercd, E_OK);

	check_point(34);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(0);
}

void
task6(intptr_t exinf)
{
	ER		ercd;

	check_point(17);
	ercd = dis_dsp();
	check_ercd(ercd, E_OK);

	check_point(18);
	ercd = wup_tsk(TASK1);
	check_ercd(ercd, E_OK);

	check_point(19);
	ercd = wup_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(20);
	ercd = sus_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(21);
	ercd = wup_tsk(TASK3);
	check_ercd(ercd, E_OK);

	check_point(22);
	ercd = wup_tsk(TASK4);
	check_ercd(ercd, E_OK);

	check_point(23);
	ercd = sus_tsk(TASK1);
	check_ercd(ercd, E_OK);

	check_point(24);
	ercd = ena_dsp();
	check_ercd(ercd, E_OK);

	check_point(27);
	ercd = dis_dsp();
	check_ercd(ercd, E_OK);

	check_point(28);
	ercd = rsm_tsk(TASK1);
	check_ercd(ercd, E_OK);

	check_point(29);
	ercd = wup_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(30);
	ercd = ena_dsp();
	check_ercd(ercd, E_OK);

	check_point(32);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(0);
}
