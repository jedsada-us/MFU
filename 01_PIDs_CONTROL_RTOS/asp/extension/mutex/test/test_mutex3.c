/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 * 
 *  Copyright (C) 2007,2008 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: test_mutex3.c 1696 2010-01-01 16:01:25Z ertl-hiro $
 */

/* 
 *		�~���[�e�b�N�X�̃e�X�g(3)
 *
 * �y�e�X�g�̖ړI�z
 *
 *  �D��x����~���[�e�b�N�X���C���b�N���鏈���ƃ��b�N�������鏈������
 *  �ʂ�e�X�g����Dref_tsk�ɂ��x�[�X�D��x�ƌ��ݗD��x�̎Q�Ə����̃e
 *  �X�g�����˂Ă���D
 *
 * �y�e�X�g���ځz
 *
 *	(A) �~���[�e�b�N�X�̃��b�N�����iloc_mtx�j
 *		(A-1) ���b�N����Ă��Ȃ��ꍇ�ɂ́C�����Ƀ��b�N�ł��邱��
 *		(A-2) ���d�Ƀ��b�N���悤�Ƃ���ƁCE_ILUSE�G���[�ɂȂ邱��
 *		(A-3) ���b�N����Ă���ꍇ�ɂ́C�D��x���ő҂���ԂɂȂ邱��
 *	(B) �~���[�e�b�N�X�̃��b�N���������iunl_mtx�j
 *		(B-1) ���^�X�N�����b�N���Ă���~���[�e�b�N�X��������悤�Ƃ����
 *		�@�@�@E_ILUSE�G���[�ɂȂ邱��
 *		(B-2) �҂��^�X�N���Ȃ��ƁC�P�Ƀ��b�N�������邱��
 *		(B-3) �҂��^�X�N�Ƀ��b�N��n������
 *		(B-4) �҂��^�X�N�Ƀ��b�N��n���āC�f�B�X�p�b�`���N���邱��
 *	(C) �~���[�e�b�N�X�̃��b�N�����iploc_mtx�j
 *		(C-1) ���b�N����Ă���ꍇ�ɂ́C������E_TMOUT�G���[�ɂȂ邱��
 *	(D) �~���[�e�b�N�X�̃��b�N�����itloc_mtx�j
 *		(D-1) ���b�N����Ă���ꍇ�ɂ́C�^�C���A�E�g�t���̑҂���Ԃɂ�
 *		�@�@�@�邱��
 *	(E) ���܂�
 *		(E-1) �^�X�N���I������ƁC�~���[�e�b�N�X�����b�N�������邱��
 *
 * �y�g�p���\�[�X�z
 *
 *	TASK1: ��D��x�^�X�N�C���C���^�X�N�C�ŏ�����N��
 *	TASK2: ���D��x�^�X�N
 *	TASK3: ���D��x�^�X�N
 *	MTX1: �~���[�e�b�N�X�iTA_CEILING�����C����͍��D��x�j
 *
 * �y�e�X�g�V�[�P���X�z
 *
 *	== TASK1�i�D��x�F��j==
 *		call(set_bit_func(bit_mutex))
 *	1:	ref_mtx(MTX1, &rmtx)
 *		assert(rmtx.htskid == TSK_NONE)
 *		assert(rmtx.wtskid == TSK_NONE)
 *		loc_mtx(MTX1)					... (A-1)
 *	2:	ref_tsk(TASK1, &rtsk)
 *		assert(rtsk.tskpri == HIGH_PRIORITY)
 *		assert(rtsk.tskbpri == LOW_PRIORITY)
 *		loc_mtx(MTX1) -> E_ILUSE		... (A-2)
 *	3:	ref_mtx(MTX1, &rmtx)
 *		assert(rmtx.htskid == TASK1)
 *		assert(rmtx.wtskid == TSK_NONE)
 *		act_tsk(TASK2)
 *	4:	tslp_tsk(10) -> E_TMOUT
 *	== TASK2�i�D��x�F���j==
 *	5:	ploc_mtx(MTX1) -> E_TMOUT		... (C-1)
 *		loc_mtx(MTX1)					... (A-3)
 *	== TASK1�i�����j==
 *	6:	ref_mtx(MTX1, &rmtx)
 *		assert(rmtx.htskid == TASK1)
 *		assert(rmtx.wtskid == TASK2)
 *		act_tsk(TASK3)
 *	7:	tslp_tsk(10) -> E_TMOUT
 *	== TASK3�i�D��x�F���j==
 *	8:	unl_mtx(MTX1) -> E_ILUSE		... (B-1)
 *	9:	loc_mtx(MTX1)					... (A-3)
 *	== TASK1�i�����j==
 *	10:	ref_mtx(MTX1, &rmtx)
 *		assert(rmtx.htskid == TASK1)
 *		assert(rmtx.wtskid == TASK3)
 *		dis_dsp()
 *		unl_mtx(MTX1)					... (B-3)
 *	11:	ref_tsk(TASK1, &rtsk)
 *		assert(rtsk.tskpri == LOW_PRIORITY)
 *		assert(rtsk.tskbpri == LOW_PRIORITY)
 *		ref_mtx(MTX1, &rmtx)
 *		assert(rmtx.htskid == TASK3)
 *		assert(rmtx.wtskid == TASK2)
 *		ena_dsp()
 *	== TASK3�i�����j==
 *	12:	ext_tsk() -> noreturn			... (E-1)
 *	== TASK2�i�����j==
 *	13:	ref_tsk(TASK2, &rtsk)
 *		assert(rtsk.tskpri == HIGH_PRIORITY)
 *		assert(rtsk.tskbpri == MID_PRIORITY)
 *		unl_mtx(MTX1)					... (B-4)
 *	14:	loc_mtx(MTX1)
 *	15:	slp_tsk()
 *	== TASK1�i�����j==
 *	16:	ref_mtx(MTX1, &rmtx)
 *		assert(rmtx.htskid == TASK2)
 *		assert(rmtx.wtskid == TSK_NONE)
 *		tloc_mtx(MTX1, 10) -> E_TMOUT	... (D-1)
 *	17:	wup_tsk(TASK2)
 *	== TASK2�i�����j==
 *	18:	unl_mtx(MTX1)					... (B-2)
 *	19:	ext_tsk() -> noreturn
 *	== TASK1�i�����j==
 *	20:	END
 */

#include <kernel.h>
#include <t_syslog.h>
#include "syssvc/logtask.h"
#include "kernel_cfg.h"
#include "test_lib.h"
#include "test_mutex.h"

extern ER	bit_mutex(void);

void
task1(intptr_t exinf)
{
	ER		ercd;
	T_RTSK	rtsk;
	T_RMTX	rmtx;

	set_bit_func(bit_mutex);

	check_point(1);
	ercd = ref_mtx(MTX1, &rmtx);
	check_ercd(ercd, E_OK);
	check_assert(rmtx.htskid == TSK_NONE);
	check_assert(rmtx.wtskid == TSK_NONE);

	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(2);
	ercd = ref_tsk(TASK1, &rtsk);
	check_ercd(ercd, E_OK);
	check_assert(rtsk.tskpri == HIGH_PRIORITY);
	check_assert(rtsk.tskbpri == LOW_PRIORITY);

	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_ILUSE);

	check_point(3);
	ercd = ref_mtx(MTX1, &rmtx);
	check_ercd(ercd, E_OK);
	check_assert(rmtx.htskid == TASK1);
	check_assert(rmtx.wtskid == TSK_NONE);

	ercd = act_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(4);
	ercd = tslp_tsk(10);
	check_ercd(ercd, E_TMOUT);

	check_point(6);
	ercd = ref_mtx(MTX1, &rmtx);
	check_ercd(ercd, E_OK);
	check_assert(rmtx.htskid == TASK1);
	check_assert(rmtx.wtskid == TASK2);

	ercd = act_tsk(TASK3);
	check_ercd(ercd, E_OK);

	check_point(7);
	ercd = tslp_tsk(10);
	check_ercd(ercd, E_TMOUT);

	check_point(10);
	ercd = ref_mtx(MTX1, &rmtx);
	check_ercd(ercd, E_OK);
	check_assert(rmtx.htskid == TASK1);
	check_assert(rmtx.wtskid == TASK3);

	ercd = dis_dsp();
	check_ercd(ercd, E_OK);

	ercd = unl_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(11);
	ercd = ref_tsk(TASK1, &rtsk);
	check_ercd(ercd, E_OK);
	check_assert(rtsk.tskpri == LOW_PRIORITY);
	check_assert(rtsk.tskbpri == LOW_PRIORITY);

	ercd = ref_mtx(MTX1, &rmtx);
	check_ercd(ercd, E_OK);
	check_assert(rmtx.htskid == TASK3);
	check_assert(rmtx.wtskid == TASK2);

	ercd = ena_dsp();
	check_ercd(ercd, E_OK);

	check_point(16);
	ercd = ref_mtx(MTX1, &rmtx);
	check_ercd(ercd, E_OK);
	check_assert(rmtx.htskid == TASK2);
	check_assert(rmtx.wtskid == TSK_NONE);

	ercd = tloc_mtx(MTX1, 10);
	check_ercd(ercd, E_TMOUT);

	check_point(17);
	ercd = wup_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_finish(20);

	check_point(0);
}

void
task2(intptr_t exinf)
{
	ER		ercd;
	T_RTSK	rtsk;

	check_point(5);
	ercd = ploc_mtx(MTX1);
	check_ercd(ercd, E_TMOUT);

	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(13);
	ercd = ref_tsk(TASK2, &rtsk);
	check_ercd(ercd, E_OK);
	check_assert(rtsk.tskpri == HIGH_PRIORITY);
	check_assert(rtsk.tskbpri == MID_PRIORITY);

	ercd = unl_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(14);
	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(15);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(18);
	ercd = unl_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(19);
	ercd = ext_tsk();

	check_point(0);
}

void
task3(intptr_t exinf)
{
	ER		ercd;

	check_point(8);
	ercd = unl_mtx(MTX1);
	check_ercd(ercd, E_ILUSE);

	check_point(9);
	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(12);
	ercd = ext_tsk();

	check_point(0);
}
