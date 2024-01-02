/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 * 
 *  Copyright (C) 2008,2009 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: test_sem2.c 1577 2009-05-31 14:30:51Z ertl-hiro $
 */

/* 
 *		�Z�}�t�H�@�\�̃e�X�g(2)
 *
 * �y�e�X�g�̖ړI�z
 *
 *  isig_sem���Csig_sem�Ƃ̈Ⴂ�𒆐S�Ƀe�X�g����D
 *  pol_sem�Ctwai_sem���Cwai_sem�Ƃ̈Ⴂ�𒆐S�Ƀe�X�g����D
 *
 * �y�e�X�g���ځz
 *
 *	(A) isig_sem�̐ÓI�G���[�̃e�X�g
 *		(A-1) �^�X�N�R���e�L�X�g����̌ďo��
 *		(A-2) CPU���b�N��Ԃ���̌ďo��
 *	(B) isig_sem�ɂ��Z�}�t�H�҂���Ԃ̃^�X�N���҂����������
 *		(B-1) �A�C�h����Ԃ���C�҂��������ꂽ�^�X�N�ɐ؂芷���
 *		(B-2) ���s��Ԃ̃^�X�N����C�҂��������ꂽ�^�X�N�ɐ؂芷���
 *		(B-3) �f�B�X�p�b�`�ۗ���ԂŁC�؂芷���Ȃ�
 *		(B-4) �҂��������ꂽ�^�X�N�������҂���ԂŁC�؂芷���Ȃ�
 *		(B-5) �҂��������ꂽ�^�X�N���D��x���Ⴍ�C�؂芷���Ȃ�
 *	(C) pol_sem�̐ÓI�G���[�̃e�X�g
 *		(C-1) ��^�X�N�R���e�L�X�g����̌ďo��
 *		(C-2) CPU���b�N��Ԃ���̌ďo��
 *		(C-3) �f�B�X�p�b�`�֎~��Ԃ���̌ďo���iE_CTX�G���[�ɂȂ�Ȃ��j
 *		(C-4) �����ݗD��x�}�X�N�S�����łȂ���Ԃ���̌ďo���iE_CTX�G���[
 *		      �ɂȂ�Ȃ��j
 *	(D) pol_sem�Ń|�[�����O���s����
 *	(E) twai_sem�̐ÓI�G���[�̃e�X�g
 *		(E-1) ��^�X�N�R���e�L�X�g����̌ďo��
 *		(E-2) CPU���b�N��Ԃ���̌ďo��
 *		(E-3) �f�B�X�p�b�`�֎~��Ԃ���̌ďo��
 *		(E-4) �����ݗD��x�}�X�N�S�����łȂ���Ԃ���̌ďo��
 *		(E-5) tmout���s��
 *	(F) twai_sem��tmout=TMO_POL�̎��Ƀ|�[�����O���s����
 *	(G) twai_sem��tmout=TMO_FEVR�̎��ɃZ�}�t�H�҂���ԂɂȂ�
 *	(H) twai_sem��tmout�Ƀ^�C���A�E�g��ݒ肵�����ɁC�^�C���A�E�g�t����
 *		�Z�}�t�H�҂���ԂɂȂ�
 *
 * �y�g�p���\�[�X�z
 *
 *	TASK1: ���D��x�^�X�N�CTA_ACT����
 *	TASK2: ���D��x�^�X�N
 *	TASK3: ��D��x�^�X�N
 *	TASK4: ���D��x�^�X�N
 *	TASK5: ���D��x�^�X�N
 *	ALM1:  �A���[���n���h��
 *  SEM1:  TA_NULL�����C����������1�C�ő厑����1
 *
 * �y�e�X�g�V�[�P���X�z
 *
 *	== TASK1�i�D��x�F���j==
 *  1:	isig_sem(SEM1) -> E_CTX				... (A-1)
 *	2:	loc_cpu()
 *		pol_sem(SEM1) -> E_CTX				... (C-2)
 *		twai_sem(SEM1, TMO_POL) -> E_CTX	... (E-2)
 *		unl_cpu()
 *	3:	dis_dsp()
 *		pol_sem(SEM1)						... (C-3)
 *		twai_sem(SEM1, TMO_POL) -> E_CTX	... (E-3)
 *		ena_dsp()
 *	4:	chg_ipm(TMAX_INTPRI)
 *		pol_sem(SEM1) -> E_TMOUT			... (C-4)(D)
 *		twai_sem(SEM1, TMO_POL) -> E_CTX	... (E-4)
 *		chg_ipm(TIPM_ENAALL)
 *	5:	twai_sem(SEM1, -2) -> E_PAR			... (E-5)
 *		twai_sem(SEM1, TMO_POL) -> E_TMOUT	... (F)
 *	6:	sta_alm(ALM1, 10)
 *	7:	twai_sem(SEM1, TMO_FEVR)			... (G)
 *	== ALM1-1 ==
 *	8:	pol_sem(SEM1) -> E_CTX				... (C-1)
 *		twai_sem(SEM1, TMO_POL) -> E_CTX	... (E-1)
 *	9:	iloc_cpu()
 *		isig_sem(SEM1) -> E_CTX				... (A-2)
 *		iunl_cpu()
 *	10:	isig_sem(SEM1)						... (B-1)
 *		RETURN
 *	== TASK1�i�����j==
 *	11:	act_tsk(TASK3)
 *	12:	wai_sem(SEM1)
 *	== TASK3�i�D��x�F��j==
 *	13:	sta_alm(ALM1, 10)
 *		call(wait_var())
 *	== ALM1-2 ==
 *	14:	isig_sem(SEM1)						... (B-2)
 *		call(signal_var())
 *		RETURN
 *	== TASK1�i�����j==
 *	15:	wai_sem(SEM1)
 *	== TASK3�i�����j==
 *	16:	sta_alm(ALM1, 10)
 *		dis_dsp()
 *		call(wait_var())
 *	== ALM1-3 ==
 *	17:	isig_sem(SEM1)						... (B-3)
 *		call(signal_var())
 *		RETURN
 *	== TASK3�i�����j==
 *	18:	ena_dsp()
 *	== TASK1�i�����j==
 *	19:	wai_sem(SEM1)
 *	== TASK3�i�����j==
 *	20:	sta_alm(ALM1, 10)
 *		sus_tsk(TASK1)
 *		call(wait_var())
 *	== ALM1-4 ==
 *	21:	isig_sem(SEM1)						... (B-4)
 *		call(signal_var())
 *		RETURN
 *	== TASK3�i�����j==
 *	22:	rsm_tsk(TASK1)
 *	== TASK1�i�����j==
 *	23:	act_tsk(TASK2)
 *	== TASK2�i�D��x�F���j==
 *	24:	tslp_tsk(10) -> E_TMOUT
 *	== TASK1�i�����j==
 *	25:	wai_sem(SEM1)
 *	== TASK3�i�����j==
 *	26:	ext_tsk() -> noreturn
 *	== TASK2�i�����j==
 *	27:	sta_alm(ALM1, 10)
 *		call(wait_var())
 *	== ALM1-5 ==
 *	28:	isig_sem(SEM1)						... (B-5)
 *		call(signal_var())
 *		RETURN
 *	== TASK2�i�����j==
 *	29:	ext_tsk() -> noreturn
 *	== TASK1�i�����j==
 *	30:	sta_alm(ALM1, 10)
 *	31:	twai_sem(SEM1, 100) -> E_RLWAI
 *	== ALM1-6 ==
 *	32:	irel_wai(TASK1)
 *		RETURN
 *	== TASK1�i�����j==
 *	33:	sta_alm(ALM1, 100)
 *	34:	twai_sem(SEM1, 10) -> E_TMOUT		... (H)
 *	35:	stp_alm(ALM1)
 *	36:	END
 */

#include <kernel.h>
#include <test_lib.h>
#include <t_syslog.h>
#include "kernel_cfg.h"
#include "test_sem2.h"

static volatile bool_t	flagvar;

static void
wait_var(void)
{
	flagvar = false;
	while (!flagvar);
}

static void
signal_var(void)
{
	flagvar = true;
}

static uint_t	alarm1_count = 0;

void
alarm1_handler(intptr_t exinf)
{
	ER		ercd;

	switch (++alarm1_count) {
	case 1:
		check_point(8);
		ercd = pol_sem(SEM1);
		check_ercd(ercd, E_CTX);

		ercd = twai_sem(SEM1, TMO_POL);
		check_ercd(ercd, E_CTX);

		check_point(9);
		ercd = iloc_cpu();
		check_ercd(ercd, E_OK);

		ercd = isig_sem(SEM1);
		check_ercd(ercd, E_CTX);

		ercd = iunl_cpu();
		check_ercd(ercd, E_OK);

		check_point(10);
		ercd = isig_sem(SEM1);
		check_ercd(ercd, E_OK);

		return;

		check_point(0);

	case 2:
		check_point(14);
		ercd = isig_sem(SEM1);
		check_ercd(ercd, E_OK);

		signal_var();

		return;

		check_point(0);

	case 3:
		check_point(17);
		ercd = isig_sem(SEM1);
		check_ercd(ercd, E_OK);

		signal_var();

		return;

		check_point(0);

	case 4:
		check_point(21);
		ercd = isig_sem(SEM1);
		check_ercd(ercd, E_OK);

		signal_var();

		return;

		check_point(0);

	case 5:
		check_point(28);
		ercd = isig_sem(SEM1);
		check_ercd(ercd, E_OK);

		signal_var();

		return;

		check_point(0);

	case 6:
		check_point(32);
		ercd = irel_wai(TASK1);
		check_ercd(ercd, E_OK);

		return;

		check_point(0);
	}
	check_point(0);
}

void
task1(intptr_t exinf)
{
	ER		ercd;

	check_point(1);
	ercd = isig_sem(SEM1);
	check_ercd(ercd, E_CTX);

	check_point(2);
	ercd = loc_cpu();
	check_ercd(ercd, E_OK);

	ercd = pol_sem(SEM1);
	check_ercd(ercd, E_CTX);

	ercd = twai_sem(SEM1, TMO_POL);
	check_ercd(ercd, E_CTX);

	ercd = unl_cpu();
	check_ercd(ercd, E_OK);

	check_point(3);
	ercd = dis_dsp();
	check_ercd(ercd, E_OK);

	ercd = pol_sem(SEM1);
	check_ercd(ercd, E_OK);

	ercd = twai_sem(SEM1, TMO_POL);
	check_ercd(ercd, E_CTX);

	ercd = ena_dsp();
	check_ercd(ercd, E_OK);

	check_point(4);
	ercd = chg_ipm(TMAX_INTPRI);
	check_ercd(ercd, E_OK);

	ercd = pol_sem(SEM1);
	check_ercd(ercd, E_TMOUT);

	ercd = twai_sem(SEM1, TMO_POL);
	check_ercd(ercd, E_CTX);

	ercd = chg_ipm(TIPM_ENAALL);
	check_ercd(ercd, E_OK);

	check_point(5);
	ercd = twai_sem(SEM1, -2);
	check_ercd(ercd, E_PAR);

	ercd = twai_sem(SEM1, TMO_POL);
	check_ercd(ercd, E_TMOUT);

	check_point(6);
	ercd = sta_alm(ALM1, 10);
	check_ercd(ercd, E_OK);

	check_point(7);
	ercd = twai_sem(SEM1, TMO_FEVR);
	check_ercd(ercd, E_OK);

	check_point(11);
	ercd = act_tsk(TASK3);
	check_ercd(ercd, E_OK);

	check_point(12);
	ercd = wai_sem(SEM1);
	check_ercd(ercd, E_OK);

	check_point(15);
	ercd = wai_sem(SEM1);
	check_ercd(ercd, E_OK);

	check_point(19);
	ercd = wai_sem(SEM1);
	check_ercd(ercd, E_OK);

	check_point(23);
	ercd = act_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(25);
	ercd = wai_sem(SEM1);
	check_ercd(ercd, E_OK);

	check_point(30);
	ercd = sta_alm(ALM1, 10);
	check_ercd(ercd, E_OK);

	check_point(31);
	ercd = twai_sem(SEM1, 100);
	check_ercd(ercd, E_RLWAI);

	check_point(33);
	ercd = sta_alm(ALM1, 100);
	check_ercd(ercd, E_OK);

	check_point(34);
	ercd = twai_sem(SEM1, 10);
	check_ercd(ercd, E_TMOUT);

	check_point(35);
	ercd = stp_alm(ALM1);
	check_ercd(ercd, E_OK);

	check_finish(36);

	check_point(0);
}

void
task2(intptr_t exinf)
{
	ER		ercd;

	check_point(24);
	ercd = tslp_tsk(10);
	check_ercd(ercd, E_TMOUT);

	check_point(27);
	ercd = sta_alm(ALM1, 10);
	check_ercd(ercd, E_OK);

	wait_var();

	check_point(29);
	ercd = ext_tsk();

	check_point(0);
}

void
task3(intptr_t exinf)
{
	ER		ercd;

	check_point(13);
	ercd = sta_alm(ALM1, 10);
	check_ercd(ercd, E_OK);

	wait_var();

	check_point(16);
	ercd = sta_alm(ALM1, 10);
	check_ercd(ercd, E_OK);

	ercd = dis_dsp();
	check_ercd(ercd, E_OK);

	wait_var();

	check_point(18);
	ercd = ena_dsp();
	check_ercd(ercd, E_OK);

	check_point(20);
	ercd = sta_alm(ALM1, 10);
	check_ercd(ercd, E_OK);

	ercd = sus_tsk(TASK1);
	check_ercd(ercd, E_OK);

	wait_var();

	check_point(22);
	ercd = rsm_tsk(TASK1);
	check_ercd(ercd, E_OK);

	check_point(26);
	ercd = ext_tsk();

	check_point(0);
}
