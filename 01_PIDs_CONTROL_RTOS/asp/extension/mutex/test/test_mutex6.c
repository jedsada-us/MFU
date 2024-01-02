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
 *  @(#) $Id: test_mutex6.c 1696 2010-01-01 16:01:25Z ertl-hiro $
 */

/* 
 *		�~���[�e�b�N�X�̃e�X�g(6)
 *
 * �y�e�X�g�̖ړI�z
 *
 *  �D��x����~���[�e�b�N�X�ɑ΂��āC�^�X�N�̏I�����C�^�X�N�̗D�揇��
 *  �̉�]���̃~���[�e�b�N�X�֘A�̏�����ԗ��I�Ƀe�X�g����D
 *
 * �y�e�X�g���ځz
 *
 *	(A) �^�X�N�̏I�����iext_tsk�j
 *		(A-1) ���b�N���Ă����~���[�e�b�N�X�i1�j�����b�N��������邱�ƁD
 *		(A-2) ���b�N���Ă����~���[�e�b�N�X�i1�j�����b�N��������C���b
 *			  �N��҂��Ă����^�X�N����������b�N���C�D��x���ω����C��
 *			  ����������邱�ƁD
 *		(A-3) ���b�N���Ă����~���[�e�b�N�X�i�����j�����ׂă��b�N������
 *			  ��邱�ƁD
 *		(A-4) ���b�N���Ă����~���[�e�b�N�X�i�����j�����b�N��������C���b
 *			  �N��҂��Ă����^�X�N�i�����j����������b�N���C�D��x����
 *			  �����C�҂���������邱�ƁD���̎��ɁC��Ń~���[�e�b�N�X��
 *			  ���b�N�����^�X�N�i��Ƀ��b�N���Ă����~���[�e�b�N�X��҂�
 *			  �Ă����^�X�N�j�̕����C�D�揇�ʂ������Ȃ邱�ƁD
 *	(B) �^�X�N�̗D�揇�ʂ̉�]�irot_rdq�j
 *		(B-1) TPRI_SELF���w�肵�����ɁC�^�X�N�̃x�[�X�D��x�̗D�揇�ʂ�
 *		�@�@�@��]���邱�ƁD
 *		(B-2) TPRI_SELF���w�肵�����ɁC�^�X�N�̌��ݗD��x�̗D�揇�ʂ���
 *		�@�@�@�]���Ȃ����ƁD
 *
 * �y�e�X�g���ڂ̎������@�z
 *
 *	(A-1)
 *		��D��x�^�X�N�iTASK2�j�Ƀ~���[�e�b�N�X�iMTX1�j�����b�N�����C
 *		ext_tsk����ƁC���b�N����������邱�Ƃ��m�F����D
 *	(A-2)
 *		��D��x�^�X�N�iTASK2�j�ɍ��D��x����~���[�e�b�N�X�iMTX1�j�����b
 *		�N�����C�ʂ̒�D��x�^�X�N�iTASK3�j��MTX1��҂�������ԂŁC
 *		TASK2 ��ext_tsk����ƁCTASK3�����D��x�ɂȂ��đ҂���������邱
 *		�Ƃ��m�F����D
 *	(A-3)
 *		��D��x�^�X�N�iTASK2�j�Ƀ~���[�e�b�N�X��2�iMTX1�CMTX2�j���b
 *		�N�����Cext_tsk����ƁC�����̃��b�N����������邱�Ƃ��m�F����D
 *	(A-4)
 *		��D��x�^�X�N�iTASK2�j�ɍ��D��x����~���[�e�b�N�X2�iMTX1�C
 *		MTX2�j�����̏��Ń��b�N�����C�ʂ̒�D��x�^�X�N2�iTASK3�C
 *		TASK4�j�ɂ��ꂼ��̃��b�N��҂�������ԂŁCTASK2��ext_tsk����ƁC
 *		TASK3��TASK4�����D��x�ɂȂ��đ҂���������邱�Ƃ��m�F����D��
 *		���C��Ƀ��b�N���Ă����~���[�e�b�N�X�iMTX1�j��҂��Ă����^�X�N
 *		�iTASK3�j���CTASK4�����D�揇�ʂ������Ȃ邱�Ƃ��m�F����D
 *	(B-1)
 *		��D��x�^�X�N��3�iTASK2�CTASK3�CTASK4�j�����s�ł����Ԃ̎�
 *		�ɁC1�̒�D��x�^�X�N�iTASK2�j�ɍ��D��x����~���[�e�b�N�X��
 *		���b�N�����Crot_rdq(TPRI_SELF)����ƁC�c���2�̒�D��x�^�X�N
 *		�̗D�揇�ʂ���]���邱�Ƃ��m�F����D
 *	(B-2)
 *		��Ɠ����󋵂ŁC���D��x�^�X�N�̗D�揇�ʂ���]���Ȃ����Ƃ��m�F
 *		����D
 *
 * �y�g�p���\�[�X�z
 *
 *	TASK1: ��D��x�^�X�N�C���C���^�X�N�C�ŏ�����N��
 *	TASK2: ��D��x�^�X�N
 *	TASK3: ��D��x�^�X�N
 *	TASK4: ��D��x�^�X�N
 *	MTX1: �~���[�e�b�N�X�iTA_CEILING�����C����͍��D��x�j
 *	MTX2: �~���[�e�b�N�X�iTA_CEILING�����C����͍��D��x�j
 *
 * �y�e�X�g�V�[�P���X�z
 *
 *	== TASK1�i�D��x�F��j==
 *		call(set_bit_func(bit_mutex))
 *	1:	act_tsk(TASK2)
 *	2:	rot_rdq(TPRI_SELF)
 *	//		��FTASK2��TASK1
 *	== TASK2-1�i�D��x�F��j1��� ==
 *	3:	loc_mtx(MTX1)
 *	//		���FTASK2�C��FTASK1�CMTX1�FTASK2
 *	4:	ext_tsk() -> noreturn			... (A-1)
 *	//		��FTASK1
 *	== TASK1�i�����j==
 *	5:	ref_mtx(MTX1, &rmtx)
 *		assert(rmtx.htskid == TSK_NONE)
 *		assert(rmtx.wtskid == TSK_NONE)
 *
 *	6:	act_tsk(TASK2)
 *		act_tsk(TASK3)
 *	7:	rot_rdq(TPRI_SELF)
 *	//		��FTASK2��TASK3��TASK1
 *	== TASK2-2�i�D��x�F��j2��� ==
 *	8:	loc_mtx(MTX1)
 *	//		���FTASK2�C��FTASK3��TASK1�CMTX1�FTASK2
 *	9:	slp_tsk()
 *	//		��FTASK3��TASK1�CMTX1�FTASK2
 *	== TASK3�i�D��x�F��j==
 *	10:	loc_mtx(MTX1)
 *	//		��FTASK1�CMTX1�FTASK2��TASK3
 *	== TASK1�i�����j==
 *	11:	wup_tsk(TASK2)
 *	//		���FTASK2�C��FTASK1�CMTX1�FTASK2��TASK3
 *	== TASK2-2�i�����j==
 *	12:	ext_tsk() -> noreturn			... (A-2)
 *	//		���FTASK3�C��FTASK1�CMTX1�FTASK3
 *	== TASK3�i�����j==
 *	13:	ref_mtx(MTX1, &rmtx)
 *		assert(rmtx.htskid == TASK3)
 *		assert(rmtx.wtskid == TSK_NONE)
 *		get_pri(TPRI_SELF, &tskpri)
 *		assert(tskpri == HIGH_PRIORITY)
 *		unl_mtx(MTX1)
 *		slp_tsk()
 *	//		��FTASK1
 *
 *	== TASK1�i�����j==
 *	14:	act_tsk(TASK2)
 *	15:	rot_rdq(TPRI_SELF)
 *	//		��FTASK2��TASK1
 *	== TASK2-3�i�D��x�F��j3��� ==
 *	16:	loc_mtx(MTX1)
 *		loc_mtx(MTX2)
 *	//		���FTASK2�C��FTASK1�CMTX1�FTASK2�CMTX2�FTASK2
 *	17:	ext_tsk() -> noreturn			... (A-3)
 *	//		��FTASK1
 *	== TASK1�i�����j==
 *	18:	ref_mtx(MTX1, &rmtx)
 *		assert(rmtx.htskid == TSK_NONE)
 *		assert(rmtx.wtskid == TSK_NONE)
 *		ref_mtx(MTX2, &rmtx)
 *		assert(rmtx.htskid == TSK_NONE)
 *		assert(rmtx.wtskid == TSK_NONE)
 *
 *	19:	act_tsk(TASK2)
 *		wup_tsk(TASK3)
 *		act_tsk(TASK4)
 *	20:	rot_rdq(TPRI_SELF)
 *	//		��FTASK2��TASK3��TASK4��TASK1
 *	== TASK2-4�i�D��x�F��j4��� ==
 *	21:	loc_mtx(MTX1)
 *		loc_mtx(MTX2)
 *	//		���FTASK2�C��FTASK3��TASK4��TASK1�CMTX1�FTASK2�CMTX2�FTASK2
 *	22:	chg_pri(TASK1, HIGH_PRIORITY)
 *	//		���FTASK2��TASK1�C��FTASK3��TASK4�CMTX1�FTASK2�CMTX2�FTASK2
 *	23:	rot_rdq(TPRI_SELF)				... (B-1)(B-2)
 *	//		���FTASK2��TASK1�C��FTASK4��TASK3�CMTX1�FTASK2�CMTX2�FTASK2
 *	24:	slp_tsk()
 *	//		���FTASK1�C��FTASK4��TASK3�CMTX1�FTASK2�CMTX2�FTASK2
 *	== TASK1�i�����j==
 *	25:	chg_pri(TSK_SELF, TPRI_INI)
 *	//		��FTASK4��TASK3��TASK1�CMTX1�FTASK2�CMTX2�FTASK2
 *	== TASK4�i�D��x�F��j==
 *	26:	loc_mtx(MTX2)
 *	//		��FTASK3��TASK1�CMTX1�FTASK2�CMTX2�FTASK2��TASK4
 *	== TASK3�i�����j==
 *	27:	loc_mtx(MTX1)
 *	//		��FTASK1�CMTX1�FTASK2��TASK3�CMTX2�FTASK2��TASK4
 *	== TASK1�i�����j==
 *	28:	wup_tsk(TASK2)
 *	//		���FTASK2�C��FTASK1�CMTX1�FTASK2��TASK3�CMTX2�FTASK2��TASK4
 *	== TASK2-4�i�����j==
 *	29:	ext_tsk() -> noreturn			... (A-4)
 *	//		���FTASK3��TASK4�C��FTASK1�CMTX1�FTASK3�CMTX2�FTASK4
 *	== TASK3�i�����j==
 *	30:	ref_mtx(MTX1, &rmtx)
 *		assert(rmtx.htskid == TASK3)
 *		assert(rmtx.wtskid == TSK_NONE)
 *		ref_mtx(MTX2, &rmtx)
 *		assert(rmtx.htskid == TASK4)
 *		assert(rmtx.wtskid == TSK_NONE)
 *		get_pri(TPRI_SELF, &tskpri)
 *		assert(tskpri == HIGH_PRIORITY)
 *		ext_tsk() -> noreturn
 *	//		���FTASK4�C��FTASK1�CMTX2�FTASK4
 *	== TASK4�i�����j==
 *	31:	get_pri(TPRI_SELF, &tskpri)
 *		assert(tskpri == HIGH_PRIORITY)
 *		ext_tsk() -> noreturn
 *	//		��FTASK1
 *	== TASK1�i�����j==
 *	32:	END
 */

#include <kernel.h>
#include <t_syslog.h>
#include "syssvc/logtask.h"
#include "kernel_cfg.h"
#include "test_lib.h"
#include "test_mutex6.h"

extern ER	bit_mutex(void);

void
task1(intptr_t exinf)
{
	ER		ercd;
	T_RMTX	rmtx;

	set_bit_func(bit_mutex);

	check_point(1);
	ercd = act_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(2);
	ercd = rot_rdq(TPRI_SELF);
	check_ercd(ercd, E_OK);

	check_point(5);
	ercd = ref_mtx(MTX1, &rmtx);
	check_ercd(ercd, E_OK);
	check_assert(rmtx.htskid == TSK_NONE);
	check_assert(rmtx.wtskid == TSK_NONE);

	check_point(6);
	ercd = act_tsk(TASK2);
	check_ercd(ercd, E_OK);

	ercd = act_tsk(TASK3);
	check_ercd(ercd, E_OK);

	check_point(7);
	ercd = rot_rdq(TPRI_SELF);
	check_ercd(ercd, E_OK);

	check_point(11);
	ercd = wup_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(14);
	ercd = act_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(15);
	ercd = rot_rdq(TPRI_SELF);
	check_ercd(ercd, E_OK);

	check_point(18);
	ercd = ref_mtx(MTX1, &rmtx);
	check_ercd(ercd, E_OK);
	check_assert(rmtx.htskid == TSK_NONE);
	check_assert(rmtx.wtskid == TSK_NONE);

	ercd = ref_mtx(MTX2, &rmtx);
	check_ercd(ercd, E_OK);
	check_assert(rmtx.htskid == TSK_NONE);
	check_assert(rmtx.wtskid == TSK_NONE);

	check_point(19);
	ercd = act_tsk(TASK2);
	check_ercd(ercd, E_OK);

	ercd = wup_tsk(TASK3);
	check_ercd(ercd, E_OK);

	ercd = act_tsk(TASK4);
	check_ercd(ercd, E_OK);

	check_point(20);
	ercd = rot_rdq(TPRI_SELF);
	check_ercd(ercd, E_OK);

	check_point(25);
	ercd = chg_pri(TSK_SELF, TPRI_INI);
	check_ercd(ercd, E_OK);

	check_point(28);
	ercd = wup_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_finish(32);

	check_point(0);
}

static uint_t	task2_count = 0;

void
task2(intptr_t exinf)
{
	ER		ercd;

	switch (++task2_count) {
	case 1:
		check_point(3);
		ercd = loc_mtx(MTX1);
		check_ercd(ercd, E_OK);

		check_point(4);
		ercd = ext_tsk();

		check_point(0);

	case 2:
		check_point(8);
		ercd = loc_mtx(MTX1);
		check_ercd(ercd, E_OK);

		check_point(9);
		ercd = slp_tsk();
		check_ercd(ercd, E_OK);

		check_point(12);
		ercd = ext_tsk();

		check_point(0);

	case 3:
		check_point(16);
		ercd = loc_mtx(MTX1);
		check_ercd(ercd, E_OK);

		ercd = loc_mtx(MTX2);
		check_ercd(ercd, E_OK);

		check_point(17);
		ercd = ext_tsk();

		check_point(0);

	case 4:
		check_point(21);
		ercd = loc_mtx(MTX1);
		check_ercd(ercd, E_OK);

		ercd = loc_mtx(MTX2);
		check_ercd(ercd, E_OK);

		check_point(22);
		ercd = chg_pri(TASK1, HIGH_PRIORITY);
		check_ercd(ercd, E_OK);

		check_point(23);
		ercd = rot_rdq(TPRI_SELF);
		check_ercd(ercd, E_OK);

		check_point(24);
		ercd = slp_tsk();
		check_ercd(ercd, E_OK);

		check_point(29);
		ercd = ext_tsk();

		check_point(0);
	}
	check_point(0);
}

void
task3(intptr_t exinf)
{
	ER		ercd;
	PRI		tskpri;
	T_RMTX	rmtx;

	check_point(10);
	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(13);
	ercd = ref_mtx(MTX1, &rmtx);
	check_ercd(ercd, E_OK);
	check_assert(rmtx.htskid == TASK3);
	check_assert(rmtx.wtskid == TSK_NONE);

	ercd = get_pri(TPRI_SELF, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == HIGH_PRIORITY);

	ercd = unl_mtx(MTX1);
	check_ercd(ercd, E_OK);

	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(27);
	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(30);
	ercd = ref_mtx(MTX1, &rmtx);
	check_ercd(ercd, E_OK);
	check_assert(rmtx.htskid == TASK3);
	check_assert(rmtx.wtskid == TSK_NONE);

	ercd = ref_mtx(MTX2, &rmtx);
	check_ercd(ercd, E_OK);
	check_assert(rmtx.htskid == TASK4);
	check_assert(rmtx.wtskid == TSK_NONE);

	ercd = get_pri(TPRI_SELF, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == HIGH_PRIORITY);

	ercd = ext_tsk();

	check_point(0);
}

void
task4(intptr_t exinf)
{
	ER		ercd;
	PRI		tskpri;

	check_point(26);
	ercd = loc_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(31);
	ercd = get_pri(TPRI_SELF, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == HIGH_PRIORITY);

	ercd = ext_tsk();

	check_point(0);
}
