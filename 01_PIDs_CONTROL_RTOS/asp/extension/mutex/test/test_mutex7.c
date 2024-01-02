/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 * 
 *  Copyright (C) 2008-2009 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: test_mutex7.c 1696 2010-01-01 16:01:25Z ertl-hiro $
 */

/* 
 *		�~���[�e�b�N�X�̃e�X�g(7)
 *
 * �y�e�X�g�̖ړI�z
 *
 *  �D��x����~���[�e�b�N�X�ɑ΂��āC�^�X�N�̋����I�����̃~���[�e�b�N
 *  �X�֘A�̏�����ԗ��I�Ƀe�X�g����D
 *
 * �y�e�X�g���ځz
 *
 *	(A) �^�X�N�̋����I�����iter_tsk�j
 *		(A-1) ���b�N���Ă����~���[�e�b�N�X�i1�j�����b�N��������邱�ƁD
 *		(A-2) ���b�N���Ă����~���[�e�b�N�X�i1�j�����b�N��������C���b
 *			  �N��҂��Ă����^�X�N����������b�N���C�D��x���ω����C��
 *			  ����������邱�ƁD
 *		(A-3) (A-2)�̌��ʁC�^�X�N�f�B�X�p�b�`���N���邱�ƁD
 *		(A-4) ���b�N���Ă����~���[�e�b�N�X�i�����j�����ׂă��b�N������
 *			  ��邱�ƁD
 *		(A-5) ���b�N���Ă����~���[�e�b�N�X�i�����j�����b�N��������C���b
 *			  �N��҂��Ă����^�X�N�i�����j����������b�N���C�D��x����
 *			  �����C�҂���������邱�ƁD���̎��ɁC��Ń~���[�e�b�N�X��
 *			  ���b�N�����^�X�N�i��Ƀ��b�N���Ă����~���[�e�b�N�X��҂�
 *			  �Ă����^�X�N�j�̕����C�D�揇�ʂ������Ȃ邱�ƁD
 *		(A-6) (A-5)�̌��ʁC�^�X�N�f�B�X�p�b�`���N���邱�ƁD
 *
 * �y�e�X�g���ڂ̎������@�z
 *
 *	(A-1)
 *		��D��x�^�X�N�iTASK2�j�Ƀ~���[�e�b�N�X�iMTX1�j�����b�N�����C��
 *		�̃^�X�N�iTASK1�j����TASK2��ter_tsk����ƁC���b�N����������邱
 *		�Ƃ��m�F����D
 *	(A-2)
 *		��D��x�^�X�N�iTASK2�j�ɒ��D��x����~���[�e�b�N�X�iMTX1�j�����b
 *		�N�����C�ʂ̒�D��x�^�X�N�iTASK3�j��MTX1��҂�������ԂŁC���D
 *		��x�^�X�N�iTASK1�j����TASK2��ter_tsk����ƁCTASK3�����D��x��
 *		�Ȃ��đ҂���������邱�Ƃ��m�F����D
 *	(A-3)
 *		��D��x�^�X�N�iTASK2�j�ɒ��D��x����~���[�e�b�N�X�iMTX1�j�����b
 *		�N�����C�ʂ̒�D��x�^�X�N�iTASK3�j��MTX1��҂�������ԂŁC�ʂ�
 *		��D��x�^�X�N�iTASK1�j����TASK2��ter_tsk����ƁCTASK3�����D��
 *		�x�ɂȂ��đ҂���������CTASK3�ɐ؂芷��邱�Ƃ��m�F����D
 *	(A-4)
 *		��D��x�^�X�N�iTASK2�j�Ƀ~���[�e�b�N�X��2�iMTX1�CMTX2�j���b
 *		�N�����C�ʂ̃^�X�N�iTASK1�j����TASK2��ter_tsk����ƁC�����̃��b
 *		�N����������邱�Ƃ��m�F����D
 *	(A-5)
 *		��D��x�^�X�N�iTASK2�j�ɍ��D��x����~���[�e�b�N�X2�iMTX1�C
 *		MTX2�j�����̏��Ń��b�N�����C�ʂ̒�D��x�^�X�N2�iTASK3�C
 *		TASK4�j�ɂ��ꂼ��̃��b�N��҂�������ԂŁC���D��x�^�X�N
 *		�iTASK1�j����TASK2��ter_tsk����ƁCTASK3��TASK4�����D��x�ɂȂ�
 *		�đ҂���������邱�Ƃ��m�F����D�܂��C��Ƀ��b�N���Ă����~���[
 *		�e�b�N�X�iMTX1�j��҂��Ă����^�X�N�iTASK3�j���CTASK4�����D��
 *		���ʂ������Ȃ邱�Ƃ��m�F����D
 *	(A-6)
 *		��D��x�^�X�N�iTASK2�j�ɍ��D��x����~���[�e�b�N�X2�iMTX1�C
 *		MTX2�j�����̏��Ń��b�N�����C�ʂ̒�D��x�^�X�N2�iTASK3�C
 *		TASK4�j�ɂ��ꂼ��̃��b�N��҂�������ԂŁC�ʂ̒�D��x�^�X�N
 *		�iTASK1�j����TASK2 ��ter_tsk����ƁCTASK3��TASK4�����D��x�ɂȂ�
 *		�đ҂���������CTASK3�ɐ؂芷��邱�Ƃ��m�F����D
 *
 * �y�g�p���\�[�X�z
 *
 *	TASK1: ���D��x�^�X�N�C���C���^�X�N�C�ŏ�����N��
 *	TASK2: ��D��x�^�X�N
 *	TASK3: ��D��x�^�X�N
 *	TASK4: ��D��x�^�X�N
 *	MTX1: �~���[�e�b�N�X�iTA_CEILING�����C����͒��D��x�j
 *	MTX2: �~���[�e�b�N�X�iTA_CEILING�����C����͒��D��x�j
 *
 * �y�e�X�g�V�[�P���X�z
 *
 *	== TASK1�i�D��x�F���j==
 *		call(set_bit_func(bit_mutex))
 *	1:	act_tsk(TASK2)
 *	2:	slp_tsk()
 *	== TASK2-1�i�D��x�F��j==
 *	3:	loc_mtx(MTX1)
 *	4:	wup_tsk(TASK1)
 *	== TASK1�i�����j==
 *	5:	ter_tsk(TASK2)			... (A-1)
 *	6:	ref_mtx(MTX1, &rmtx)
 *		assert(rmtx.htskid == TSK_NONE)
 *		assert(rmtx.wtskid == TSK_NONE)
 *
 *	7:	act_tsk(TASK2)
 *		act_tsk(TASK3)
 *	8:	slp_tsk()
 *	== TASK2-2�i�D��x�F��j==
 *	9:	loc_mtx(MTX1)
 *	10:	tslp_tsk(10) -> E_TMOUT
 *	== TASK3-1�i�D��x�F��j==
 *	11:	loc_mtx(MTX1)
 *	== TASK2-2�i�����j==
 *	12:	wup_tsk(TASK1)
 *	== TASK1�i�����j==
 *	13:	ter_tsk(TASK2)			... (A-2)
 *	14:	ref_mtx(MTX1, &rmtx)
 *		assert(rmtx.htskid == TASK3)
 *		assert(rmtx.wtskid == TSK_NONE)
 *		get_pri(TASK3, &tskpri)
 *		assert(tskpri == MID_PRIORITY)
 *	15:	ter_tsk(TASK3)
 *
 *	16:	act_tsk(TASK2)
 *		act_tsk(TASK3)
 *	17:	chg_pri(TSK_SELF, LOW_PRIORITY)
 *	== TASK2-3�i�D��x�F��j==
 *	18:	loc_mtx(MTX1)
 *	19:	slp_tsk()
 *	== TASK3-2�i�D��x�F��j==
 *	20:	loc_mtx(MTX1)
 *	== TASK1�i�����j==
 *	21:	ter_tsk(TASK2)			... (A-3)
 *	== TASK3-2�i�����j==
 *	22:	ref_mtx(MTX1, &rmtx)
 *		assert(rmtx.htskid == TASK3)
 *		assert(rmtx.wtskid == TSK_NONE)
 *		get_pri(TASK3, &tskpri)
 *		assert(tskpri == MID_PRIORITY)
 *	23:	ext_tsk() -> noreturn
 *	== TASK1�i�����j==
 *	24:	chg_pri(TSK_SELF, HIGH_PRIORITY)
 *
 *	25:	act_tsk(TASK2)
 *	26:	slp_tsk()
 *	== TASK2-4�i�D��x�F��j==
 *	27:	loc_mtx(MTX1)
 *		loc_mtx(MTX2)
 *	28:	wup_tsk(TASK1)
 *	== TASK1�i�����j==
 *	29:	ter_tsk(TASK2)			... (A-4)
 *	30:	ref_mtx(MTX1, &rmtx)
 *		assert(rmtx.htskid == TSK_NONE)
 *		assert(rmtx.wtskid == TSK_NONE)
 *		ref_mtx(MTX2, &rmtx)
 *		assert(rmtx.htskid == TSK_NONE)
 *		assert(rmtx.wtskid == TSK_NONE)
 *	31:	MISSING
 *
 *	32:	act_tsk(TASK2)
 *		act_tsk(TASK3)
 *		act_tsk(TASK4)
 *	33:	slp_tsk()
 *	== TASK2-5�i�D��x�F��j==
 *	34:	loc_mtx(MTX1)
 *		loc_mtx(MTX2)
 *	35:	tslp_tsk(10) -> E_TMOUT
 *	== TASK3-3�i�D��x�F��j==
 *	36:	loc_mtx(MTX1)
 *	== TASK4-1�i�D��x�F��j==
 *	37:	loc_mtx(MTX2)
 *	== TASK2-5�i�����j==
 *	38:	wup_tsk(TASK1)
 *	== TASK1�i�����j==
 *	39:	ter_tsk(TASK2)			... (A-5)
 *	40:	ref_mtx(MTX1, &rmtx)
 *		assert(rmtx.htskid == TASK3)
 *		assert(rmtx.wtskid == TSK_NONE)
 *		ref_mtx(MTX2, &rmtx)
 *		assert(rmtx.htskid == TASK4)
 *		assert(rmtx.wtskid == TSK_NONE)
 *		get_pri(TASK3, &tskpri)
 *		assert(tskpri == MID_PRIORITY)
 *		get_pri(TASK4, &tskpri)
 *		assert(tskpri == MID_PRIORITY)
 *	41:	chg_pri(TSK_SELF, LOW_PRIORITY)
 *	== TASK3-3�i�����j==
 *	42:	ext_tsk() -> noreturn
 *	== TASK4-1�i�����j==
 *	43:	ext_tsk() -> noreturn
 *	== TASK1�i�����j==
 *	44:	act_tsk(TASK2)
 *		act_tsk(TASK3)
 *		act_tsk(TASK4)
 *	45:	chg_pri(TSK_SELF, LOW_PRIORITY)
 *	== TASK2-6�i�D��x�F��j==
 *	46:	loc_mtx(MTX1)
 *		loc_mtx(MTX2)
 *	47:	slp_tsk()
 *	== TASK3-4�i�D��x�F��j==
 *	48:	loc_mtx(MTX1)
 *	== TASK4-2�i�D��x�F��j==
 *	49:	loc_mtx(MTX2)
 *	== TASK1�i�����j==
 *	50:	ter_tsk(TASK2)			... (A-6)
 *	== TASK3-4�i�����j==
 *	51:	ref_mtx(MTX1, &rmtx)
 *		assert(rmtx.htskid == TASK3)
 *		assert(rmtx.wtskid == TSK_NONE)
 *		ref_mtx(MTX2, &rmtx)
 *		assert(rmtx.htskid == TASK4)
 *		assert(rmtx.wtskid == TSK_NONE)
 *		get_pri(TASK3, &tskpri)
 *		assert(tskpri == MID_PRIORITY)
 *		get_pri(TASK4, &tskpri)
 *		assert(tskpri == MID_PRIORITY)
 *	52:	ext_tsk() -> noreturn
 *	== TASK4-2�i�����j==
 *	53:	ext_tsk() -> noreturn
 *	== TASK1�i�����j==
 *	54:	END
 */

#include <kernel.h>
#include <t_syslog.h>
#include "syssvc/logtask.h"
#include "kernel_cfg.h"
#include "test_lib.h"
#include "test_mutex7.h"

extern ER	bit_mutex(void);

void
task1(intptr_t exinf)
{
	ER		ercd;
	PRI		tskpri;
	T_RMTX	rmtx;

	set_bit_func(bit_mutex);

	check_point(1);
	ercd = act_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(2);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(5);
	ercd = ter_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(6);
	ercd = ref_mtx(MTX1, &rmtx);
	check_ercd(ercd, E_OK);
	check_assert(rmtx.htskid == TSK_NONE);
	check_assert(rmtx.wtskid == TSK_NONE);

	check_point(7);
	ercd = act_tsk(TASK2);
	check_ercd(ercd, E_OK);

	ercd = act_tsk(TASK3);
	check_ercd(ercd, E_OK);

	check_point(8);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(13);
	ercd = ter_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(14);
	ercd = ref_mtx(MTX1, &rmtx);
	check_ercd(ercd, E_OK);
	check_assert(rmtx.htskid == TASK3);
	check_assert(rmtx.wtskid == TSK_NONE);

	ercd = get_pri(TASK3, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == MID_PRIORITY);

	check_point(15);
	ercd = ter_tsk(TASK3);
	check_ercd(ercd, E_OK);

	check_point(16);
	ercd = act_tsk(TASK2);
	check_ercd(ercd, E_OK);

	ercd = act_tsk(TASK3);
	check_ercd(ercd, E_OK);

	check_point(17);
	ercd = chg_pri(TSK_SELF, LOW_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(21);
	ercd = ter_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(24);
	ercd = chg_pri(TSK_SELF, HIGH_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(25);
	ercd = act_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(26);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(29);
	ercd = ter_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(30);
	ercd = ref_mtx(MTX1, &rmtx);
	check_ercd(ercd, E_OK);
	check_assert(rmtx.htskid == TSK_NONE);
	check_assert(rmtx.wtskid == TSK_NONE);

	ercd = ref_mtx(MTX2, &rmtx);
	check_ercd(ercd, E_OK);
	check_assert(rmtx.htskid == TSK_NONE);
	check_assert(rmtx.wtskid == TSK_NONE);

	check_point(31);

	check_point(32);
	ercd = act_tsk(TASK2);
	check_ercd(ercd, E_OK);

	ercd = act_tsk(TASK3);
	check_ercd(ercd, E_OK);

	ercd = act_tsk(TASK4);
	check_ercd(ercd, E_OK);

	check_point(33);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(39);
	ercd = ter_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(40);
	ercd = ref_mtx(MTX1, &rmtx);
	check_ercd(ercd, E_OK);
	check_assert(rmtx.htskid == TASK3);
	check_assert(rmtx.wtskid == TSK_NONE);

	ercd = ref_mtx(MTX2, &rmtx);
	check_ercd(ercd, E_OK);
	check_assert(rmtx.htskid == TASK4);
	check_assert(rmtx.wtskid == TSK_NONE);

	ercd = get_pri(TASK3, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == MID_PRIORITY);

	ercd = get_pri(TASK4, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == MID_PRIORITY);

	check_point(41);
	ercd = chg_pri(TSK_SELF, LOW_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(44);
	ercd = act_tsk(TASK2);
	check_ercd(ercd, E_OK);

	ercd = act_tsk(TASK3);
	check_ercd(ercd, E_OK);

	ercd = act_tsk(TASK4);
	check_ercd(ercd, E_OK);

	check_point(45);
	ercd = chg_pri(TSK_SELF, LOW_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(50);
	ercd = ter_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_finish(54);

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
		ercd = wup_tsk(TASK1);
		check_ercd(ercd, E_OK);

		check_point(0);

	case 2:
		check_point(9);
		ercd = loc_mtx(MTX1);
		check_ercd(ercd, E_OK);

		check_point(10);
		ercd = tslp_tsk(10);
		check_ercd(ercd, E_TMOUT);

		check_point(12);
		ercd = wup_tsk(TASK1);
		check_ercd(ercd, E_OK);

		check_point(0);

	case 3:
		check_point(18);
		ercd = loc_mtx(MTX1);
		check_ercd(ercd, E_OK);

		check_point(19);
		ercd = slp_tsk();
		check_ercd(ercd, E_OK);

		check_point(0);

	case 4:
		check_point(27);
		ercd = loc_mtx(MTX1);
		check_ercd(ercd, E_OK);

		ercd = loc_mtx(MTX2);
		check_ercd(ercd, E_OK);

		check_point(28);
		ercd = wup_tsk(TASK1);
		check_ercd(ercd, E_OK);

		check_point(0);

	case 5:
		check_point(34);
		ercd = loc_mtx(MTX1);
		check_ercd(ercd, E_OK);

		ercd = loc_mtx(MTX2);
		check_ercd(ercd, E_OK);

		check_point(35);
		ercd = tslp_tsk(10);
		check_ercd(ercd, E_TMOUT);

		check_point(38);
		ercd = wup_tsk(TASK1);
		check_ercd(ercd, E_OK);

		check_point(0);

	case 6:
		check_point(46);
		ercd = loc_mtx(MTX1);
		check_ercd(ercd, E_OK);

		ercd = loc_mtx(MTX2);
		check_ercd(ercd, E_OK);

		check_point(47);
		ercd = slp_tsk();
		check_ercd(ercd, E_OK);

		check_point(0);
	}
	check_point(0);
}

static uint_t	task3_count = 0;

void
task3(intptr_t exinf)
{
	ER		ercd;
	PRI		tskpri;
	T_RMTX	rmtx;

	switch (++task3_count) {
	case 1:
		check_point(11);
		ercd = loc_mtx(MTX1);
		check_ercd(ercd, E_OK);

		check_point(0);

	case 2:
		check_point(20);
		ercd = loc_mtx(MTX1);
		check_ercd(ercd, E_OK);

		check_point(22);
		ercd = ref_mtx(MTX1, &rmtx);
		check_ercd(ercd, E_OK);
		check_assert(rmtx.htskid == TASK3);
		check_assert(rmtx.wtskid == TSK_NONE);

		ercd = get_pri(TASK3, &tskpri);
		check_ercd(ercd, E_OK);
		check_assert(tskpri == MID_PRIORITY);

		check_point(23);
		ercd = ext_tsk();

		check_point(0);

	case 3:
		check_point(36);
		ercd = loc_mtx(MTX1);
		check_ercd(ercd, E_OK);

		check_point(42);
		ercd = ext_tsk();

		check_point(0);

	case 4:
		check_point(48);
		ercd = loc_mtx(MTX1);
		check_ercd(ercd, E_OK);

		check_point(51);
		ercd = ref_mtx(MTX1, &rmtx);
		check_ercd(ercd, E_OK);
		check_assert(rmtx.htskid == TASK3);
		check_assert(rmtx.wtskid == TSK_NONE);

		ercd = ref_mtx(MTX2, &rmtx);
		check_ercd(ercd, E_OK);
		check_assert(rmtx.htskid == TASK4);
		check_assert(rmtx.wtskid == TSK_NONE);

		ercd = get_pri(TASK3, &tskpri);
		check_ercd(ercd, E_OK);
		check_assert(tskpri == MID_PRIORITY);

		ercd = get_pri(TASK4, &tskpri);
		check_ercd(ercd, E_OK);
		check_assert(tskpri == MID_PRIORITY);

		check_point(52);
		ercd = ext_tsk();

		check_point(0);
	}
	check_point(0);
}

static uint_t	task4_count = 0;

void
task4(intptr_t exinf)
{
	ER		ercd;

	switch (++task4_count) {
	case 1:
		check_point(37);
		ercd = loc_mtx(MTX2);
		check_ercd(ercd, E_OK);

		check_point(43);
		ercd = ext_tsk();

		check_point(0);

	case 2:
		check_point(49);
		ercd = loc_mtx(MTX2);
		check_ercd(ercd, E_OK);

		check_point(53);
		ercd = ext_tsk();

		check_point(0);
	}
	check_point(0);
}
