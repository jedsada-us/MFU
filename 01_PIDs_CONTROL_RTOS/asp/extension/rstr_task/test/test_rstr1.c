/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 * 
 *  Copyright (C) 2010 by Embedded and Real-Time Systems Laboratory
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
 *  $Id: test_rstr1.c 1887 2010-08-06 06:15:19Z ertl-hiro $
 */

/* 
 *		����^�X�N�̃e�X�g(1)
 *
 * �y�e�X�g�̖ړI�z
 *
 *  ����^�X�N�̊�{�I�ȐU�����iras_pri�T�[�r�X�R�[���ȊO�̓���j���e�X
 *  �g����D
 *
 * �y�e�X�g���ځz
 *
 *	(A) ����^�X�N���C���^�X�N��҂���Ԃɂ���\���̂���T�[�r�X�R�[
 *      �����Ăяo�����ꍇ�CE_NOSPT�G���[�ƂȂ�
 *		(A-1) slp_tsk
 *		(A-2) tslp_tsk
 *		(A-3) dly_tsk
 *      �� ���ɂ����邪�C���ꂾ���ɗ��߂�
 *	(B) ����^�X�N��ΏۂƂ��āCchg_pri�Cwup_tsk�Ciwup_tsk�Ccan_wup�C
 *	    rel_wai�Cirel_wai�Csus_tsk�Crsm_tsk���Ăяo�����ꍇ�CE_NOSPT�G
 *	    ���[�ƂȂ�
 *		(B-1) chg_pri
 *		(B-2) wup_tsk
 *		(B-3) iwup_tsk
 *		(B-4) can_wup
 *		(B-5) rel_wai
 *		(B-6) irel_wai
 *		(B-7) sus_tsk
 *		(B-8) rsm_tsk
 *  (C) rot_rdq�Cirot_rdq�́C�ΏۗD��x�������s�ł����Ԃ̃^�X�N�̒�
 *      �ōł��D�揇�ʂ������^�X�N������^�X�N�ł���ꍇ�CE_NOSPT�G���[
 *      �ƂȂ�
 *		(C-1) rot_rdq�����������삷��
 *		(C-2) rot_rdq��E_NOSPT��Ԃ�
 *		(C-3) irot_rdq�����������삷��
 *		(C-4) irot_rdq��E_NOSPT��Ԃ�
 *
 * �y�g�p���\�[�X�z
 *
 *	TASK1: ���D��x�^�X�N�C���C���^�X�N�C�ŏ�����N��
 *	TASK2: ���D��x�^�X�N�C����^�X�N
 *	TASK3: ���D��x�^�X�N�C����^�X�N
 *	TASK4: ���D��x�^�X�N�C����^�X�N
 *	ALM1:  �A���[���n���h��
 *
 * �y�e�X�g�V�[�P���X�z
 *
 *	== TASK1�i�D��x�F���j==
 *	1:	act_tsk(TASK2)
 *	== TASK2-1�i�D��x�F���j==
 *	2:	slp_tsk() -> E_NOSPT						... (A-1)
 *	3:	tslp_tsk(10) -> E_NOSPT						... (A-2)
 *	4:	dly_tsk(10) -> E_NOSPT						... (A-3)
 *  5:	ext_tsk()
 *	== TASK1�i�����j==
 *	6:	chg_pri(TASK3, HIGH_PRIORITY) -> E_NOSPT	... (B-1)
 *	7:	wup_tsk(TASK3) -> E_NOSPT					... (B-2)
 *	8:	can_wup(TASK3) -> E_NOSPT					... (B-4)
 *	9:	rel_wai(TASK3) -> E_NOSPT					... (B-5)
 *	10:	sus_tsk(TASK3) -> E_NOSPT					... (B-7)
 *	11:	rsm_tsk(TASK3) -> E_NOSPT					... (B-8)
 *	12:	sta_alm(ALM1, 10)
 *	13:	slp_tsk()
 *	== ALM1 ==
 *	14:	iwup_tsk(TASK3) -> E_NOSPT					... (B-3)
 *	15:	irel_wai(TASK3) -> E_NOSPT					... (B-6)
 *	16:	iwup_tsk(TASK1)
 *	17:	iact_tsk(TASK3)
 *	18:	iact_tsk(TASK4)
 *	19:	irot_rdq(MID_PRIORITY)						... (C-3)
 *	20:	irot_rdq(MID_PRIORITY) -> E_NOSPT			... (C-4)
 *	21:	RETURN
 *	== TASK3-1�i�D��x�F���j==
 *	22:	act_tsk(TASK2)
 *	== TASK2-2�i�D��x�F���j2��� ==
 *	23:	rot_rdq(MID_PRIORITY) -> E_NOSPT			... (C-2)
 *	24:	ext_tsk()
 *	== TASK3-1�i�����j==
 *	25:	ext_tsk()
 *	== TASK4-1�i�D��x�F���j1��� ==
 *	26:	ext_tsk()
 *	== TASK1�i�����j==
 *	27:	act_tsk(TASK3)
 *	28:	act_tsk(TASK4)
 *	29:	act_tsk(TASK2)
 *	== TASK2-3�i�D��x�F���j3��� ==
 *	30:	rot_rdq(MID_PRIORITY)						... (C-1)
 *	31:	ext_tsk()
 *	== TASK3-2�i�D��x�F���j2��� ==
 *	32:	ext_tsk()
 *	== TASK4-2�i�D��x�F���j2��� ==
 *	33:	ext_tsk()
 *	== TASK1�i�����j==
 *	34: END
 */

#include <kernel.h>
#include <test_lib.h>
#include <t_syslog.h>
#include "kernel_cfg.h"
#include "test_rstr1.h"

void
alarm1_handler(intptr_t exinf)
{
	ER		ercd;

	check_point(14);
	ercd = iwup_tsk(TASK3);
	check_ercd(ercd, E_NOSPT);

	check_point(15);
	ercd = irel_wai(TASK3);
	check_ercd(ercd, E_NOSPT);

	check_point(16);
	ercd = iwup_tsk(TASK1);
	check_ercd(ercd, E_OK);

	check_point(17);
	ercd = iact_tsk(TASK3);
	check_ercd(ercd, E_OK);

	check_point(18);
	ercd = iact_tsk(TASK4);
	check_ercd(ercd, E_OK);

	check_point(19);
	ercd = irot_rdq(MID_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(20);
	ercd = irot_rdq(MID_PRIORITY);
	check_ercd(ercd, E_NOSPT);

	check_point(21);
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

	check_point(6);
	ercd = chg_pri(TASK3, HIGH_PRIORITY);
	check_ercd(ercd, E_NOSPT);

	check_point(7);
	ercd = wup_tsk(TASK3);
	check_ercd(ercd, E_NOSPT);

	check_point(8);
	ercd = can_wup(TASK3);
	check_ercd(ercd, E_NOSPT);

	check_point(9);
	ercd = rel_wai(TASK3);
	check_ercd(ercd, E_NOSPT);

	check_point(10);
	ercd = sus_tsk(TASK3);
	check_ercd(ercd, E_NOSPT);

	check_point(11);
	ercd = rsm_tsk(TASK3);
	check_ercd(ercd, E_NOSPT);

	check_point(12);
	ercd = sta_alm(ALM1, 10);
	check_ercd(ercd, E_OK);

	check_point(13);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(27);
	ercd = act_tsk(TASK3);
	check_ercd(ercd, E_OK);

	check_point(28);
	ercd = act_tsk(TASK4);
	check_ercd(ercd, E_OK);

	check_point(29);
	ercd = act_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_finish(34);

	check_point(0);
}

static uint_t	task2_count = 0;

void
task2(intptr_t exinf)
{
	ER		ercd;

	switch (++task2_count) {
	case 1:
		check_point(2);
		ercd = slp_tsk();
		check_ercd(ercd, E_NOSPT);

		check_point(3);
		ercd = tslp_tsk(10);
		check_ercd(ercd, E_NOSPT);

		check_point(4);
		ercd = dly_tsk(10);
		check_ercd(ercd, E_NOSPT);

		check_point(5);
		ercd = ext_tsk();
		check_ercd(ercd, E_OK);

		check_point(0);

	case 2:
		check_point(23);
		ercd = rot_rdq(MID_PRIORITY);
		check_ercd(ercd, E_NOSPT);

		check_point(24);
		ercd = ext_tsk();
		check_ercd(ercd, E_OK);

		check_point(0);

	case 3:
		check_point(30);
		ercd = rot_rdq(MID_PRIORITY);
		check_ercd(ercd, E_OK);

		check_point(31);
		ercd = ext_tsk();
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

	switch (++task3_count) {
	case 1:
		check_point(22);
		ercd = act_tsk(TASK2);
		check_ercd(ercd, E_OK);

		check_point(25);
		ercd = ext_tsk();
		check_ercd(ercd, E_OK);

		check_point(0);

	case 2:
		check_point(32);
		ercd = ext_tsk();
		check_ercd(ercd, E_OK);

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
		check_point(26);
		ercd = ext_tsk();
		check_ercd(ercd, E_OK);

		check_point(0);

	case 2:
		check_point(33);
		ercd = ext_tsk();
		check_ercd(ercd, E_OK);

		check_point(0);
	}
	check_point(0);
}
