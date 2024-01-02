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
 *  @(#) $Id: test_sem1.c 1577 2009-05-31 14:30:51Z ertl-hiro $
 */

/* 
 *		�Z�}�t�H�@�\�̃e�X�g(1)
 *
 * �y�e�X�g�̖ړI�z
 *
 *  sig_sem�Cwai_sem�CCRE_SEM��ԗ��I�Ƀe�X�g����D
 *  �������CCRE_SEM�̃G���[�̃e�X�g�͏����D
 *
 * �y�e�X�g���ځz
 *
 *	(A) sig_sem�̐ÓI�G���[�̃e�X�g
 *		(A-1) ��^�X�N�R���e�L�X�g����̌ďo��
 *		(A-2) CPU���b�N��Ԃ���̌ďo��
 *		(A-3) semid���s���i����������j
 *		(A-4) semid���s���i�傫������j
 *	(B) sig_sem�ɂ��Z�}�t�H�҂���Ԃ̃^�X�N���҂����������
 *		(B-1) �҂��������ꂽ�^�X�N�ɐ؂芷���
 *		(B-2) �f�B�X�p�b�`�ۗ���ԂŁC�؂芷���Ȃ�
 *		(B-3) �҂��������ꂽ�^�X�N�������҂���ԂŁC�؂芷���Ȃ�
 *		(B-4) �҂��������ꂽ�^�X�N���D��x���Ⴍ�C�؂芷���Ȃ�
 *	(C) sig_sem�ɂ��Z�}�t�H�̎�������1������
 *		(C-1) �Z�}�t�H�̎�������0����1�ɂȂ�
 *		(C-2) �Z�}�t�H�̎�������1����2�ɂȂ�
 *	(D) sig_sem��E_QOVR�G���[�ƂȂ�
 *		(D-1) �Z�}�t�H�̍ő厑������1�̎�
 *		(D-2) �Z�}�t�H�̍ő厑������2�̎�
 *	(E) wai_sem�̐ÓI�G���[�̃e�X�g
 *		(E-1) ��^�X�N�R���e�L�X�g����̌ďo��
 *		(E-2) CPU���b�N��Ԃ���̌ďo��
 *		(E-3) �f�B�X�p�b�`�֎~��Ԃ���̌ďo��
 *		(E-4) �����ݗD��x�}�X�N�S�����łȂ���Ԃ���̌ďo��
 *		(E-5) semid���s���i����������j
 *		(E-6) semid���s���i�傫������j
 *	(F) wai_sem�ɂ��Z�}�t�H�̎�������1����
 *		(F-1) �Z�}�t�H�̎�������1����0�ɂȂ�
 *		(F-2) �Z�}�t�H�̎�������2����1�ɂȂ�
 *	(G) wai_sem�ɂ��Z�}�t�H�҂���ԂɂȂ�
 *		(G-1) TA_TNULL�����̃Z�}�t�H�ŁC�҂��Ă���^�X�N���Ȃ������ꍇ
 *		(G-2) TA_TNULL�����̃Z�}�t�H�ŁC�҂��Ă���^�X�N���������ꍇ
 *		(G-3) TA_TPRI�����̃Z�}�t�H�ŁC�҂��Ă���^�X�N���Ȃ������ꍇ
 *		(G-4) TA_TPRI�����̃Z�}�t�H�ŁC�D��x�������^�X�N���҂��Ă���ꍇ
 *		(G-5) TA_TPRI�����̃Z�}�t�H�ŁC�D��x�������^�X�N���҂��Ă���ꍇ
 *		(G-6) TA_TPRI�����̃Z�}�t�H�ŁC�D��x���Ⴂ�^�X�N���҂��Ă���ꍇ
 *	(H) �Z�}�t�H�҂���Ԃ��������������
 *	(I) �Z�}�t�H�҂���Ԃ̊ԂɃZ�}�t�H�������������
 *	(J) �Z�}�t�H�̎������̏����l���������ݒ肳���
 *		(J-1) �Z�}�t�H�̎������̏����l��0
 *		(J-2) �Z�}�t�H�̎������̏����l��1
 *		(J-3) �Z�}�t�H�̎������̏����l��2
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
 *  SEM2:  TA_NULL�����C����������2�C�ő厑����2
 *  SEM3:  TA_TPRI�����C����������0�C�ő厑����1
 *
 * �y�e�X�g�V�[�P���X�z
 *
 *	== TASK1�i�D��x�F���j==
 *  1:	ref_sem(SEM1, &rsem)
 *		assert(rsem.wtskid == TSK_NONE)
 *		assert(rsem.semcnt == 1)			... (J-2)
 *  	ref_sem(SEM2, &rsem)
 *		assert(rsem.wtskid == TSK_NONE)
 *		assert(rsem.semcnt == 2)			... (J-3)
 *  	ref_sem(SEM3, &rsem)
 *		assert(rsem.wtskid == TSK_NONE)
 *		assert(rsem.semcnt == 0)			... (J-1)
 *	2:	loc_cpu()
 *		sig_sem(SEM1) -> E_CTX				... (A-2)
 *		wai_sem(SEM1) -> E_CTX				... (E-2)
 *		unl_cpu()
 *		dis_dsp()
 *		wai_sem(SEM1) -> E_CTX				... (E-3)
 *		ena_dsp()
 *		chg_ipm(TMAX_INTPRI)
 *		wai_sem(SEM1) -> E_CTX				... (E-4)
 *		chg_ipm(TIPM_ENAALL)
 *		sig_sem(0) -> E_ID					... (A-3)
 *		wai_sem(0) -> E_ID					... (E-5)
 *		sig_sem(TNUM_SEMID+1) -> E_ID		... (A-4)
 *		wai_sem(TNUM_SEMID+1) -> E_ID		... (E-6)
 *	3:	act_tsk(TASK3)
 *	4:	slp_tsk()
 *	== TASK3�i�D��x�F��j==
 *	5:	wai_sem(SEM1)						... (F-1)
 *  6:	ref_sem(SEM1, &rsem)
 *		assert(rsem.wtskid == TSK_NONE)
 *		assert(rsem.semcnt == 0)
 *	7:	sta_alm(ALM1, 10)
 *	8:	wai_sem(SEM1)						... (G-1)
 *	== ALM1 ==
 *	9:	sig_sem(SEM1) -> E_CTX				... (A-1)
 *		wai_sem(SEM1) -> E_CTX				... (E-1)
 *	10:	iwup_tsk(TASK1)
 *	11:	RETURN
 *	== TASK1�i�����j==
 *	12:	act_tsk(TASK2)
 *	== TASK2�i�D��x�F���j==
 *	13:	wai_sem(SEM1)						... (G-2)
 *	== TASK1�i�����j==
 *  14:	ref_sem(SEM1, &rsem)
 *		assert(rsem.wtskid == TASK3)
 *		assert(rsem.semcnt == 0)
 *	15:	sig_sem(SEM1)						... (B-4)
 *	16:	sig_sem(SEM1)						... (B-1)
 *	== TASK2�i�����j==
 *	17:	wai_sem(SEM1)						... (G-1)
 *	== TASK1�i�����j==
 *	18: dis_dsp()
 *	19:	sig_sem(SEM1)						... (B-2)
 *	20:	ena_dsp()
 *	== TASK2�i�����j==
 *	21:	wai_sem(SEM1)						... (G-1)
 *	== TASK1�i�����j==
 *	22: sus_tsk(TASK2)
 *	23:	sig_sem(SEM1)						... (B-3)
 *	24: sig_sem(SEM1)						... (C-1)
 *	25: sig_sem(SEM1) -> E_QOVR				... (D-1)
 *  26:	ref_sem(SEM1, &rsem)
 *		assert(rsem.wtskid == TSK_NONE)
 *		assert(rsem.semcnt == 1)
 *	27:	rsm_tsk(TASK2)
 *	== TASK2�i�����j==
 *	28:	wai_sem(SEM2)						... (F-2)
 *  29:	ref_sem(SEM2, &rsem)
 *		assert(rsem.wtskid == TSK_NONE)
 *		assert(rsem.semcnt == 1)
 *	30:	wai_sem(SEM2)						... (F-1)
 *	31: wai_sem(SEM2)						... (G-1)
 *	== TASK1�i�����j==
 *	32:	sig_sem(SEM2)						... (B-1)
 *	== TASK2�i�����j==
 *	33:	wai_sem(SEM3)						... (G-3)
 *	== TASK1�i�����j==
 *	34:	sig_sem(SEM2)						... (C-1)
 *	35:	sig_sem(SEM2)						... (C-2)
 *  36:	ref_sem(SEM2, &rsem)
 *		assert(rsem.wtskid == TSK_NONE)
 *		assert(rsem.semcnt == 2)
 *	37:	sig_sem(SEM2) -> E_QOVR				... (D-2)
 *  38:	ref_sem(SEM2, &rsem)
 *		assert(rsem.wtskid == TSK_NONE)
 *		assert(rsem.semcnt == 2)
 *	39:	MISSING
 *	40:	tslp_tsk(10) -> E_TMOUT
 *	== TASK3�i�����j==
 *	41:	wai_sem(SEM3)						... (G-4)
 *	== TASK1�i�����j==
 *	42:	act_tsk(TASK4)
 *	43:	act_tsk(TASK5)
 *	44:	rot_rdq(TPRI_SELF)
 *	== TASK4�i�D��x�F���j==
 *	45:	wai_sem(SEM3)						... (G-6)
 *	== TASK5�i�D��x�F���j==
 *	46:	wai_sem(SEM3)						... (G-5)
 *	== TASK1�i�����j==
 *	47:	sig_sem(SEM3)						... (B-1)
 *	== TASK2�i�����j==
 *	48:	wai_sem(SEM1)
 *		wai_sem(SEM1) -> E_RLWAI
 *	== TASK1�i�����j==
 *	49:	sig_sem(SEM3)						... (B-4)
 *	50:	tslp_tsk(10) -> E_TMOUT
 *	== TASK4�i�����j==
 *	51:	ext_tsk() -> noreturn
 *	== TASK1�i�����j==
 *	52:	sig_sem(SEM3)						... (B-4)
 *	53:	tslp_tsk(10) -> E_TMOUT
 *	== TASK5�i�����j==
 *	54:	ext_tsk() -> noreturn
 *	== TASK1�i�����j==
 *	55:	sig_sem(SEM3)						... (B-4)
 *	56:	tslp_tsk(10) -> E_TMOUT
 *	== TASK3�i�����j==
 *	57:	ext_tsk() -> noreturn
 *	== TASK1�i�����j==
 *	58: rel_wai(TASK2)						... (H)
 *	== TASK2�i�����j==
 *	59:	wai_sem(SEM1) -> E_DLT
 *	== TASK1�i�����j==
 *	60: ini_sem(SEM1)						... (I)
 *	== TASK2�i�����j==
 *	61: ext_tsk() -> noreturn
 *	== TASK1�i�����j==
 *	62: END
 */

#include <kernel.h>
#include <test_lib.h>
#include <t_syslog.h>
#include "kernel_cfg.h"
#include "test_sem1.h"

void
alarm1_handler(intptr_t exinf)
{
	ER		ercd;

	check_point(9);
	ercd = sig_sem(SEM1);
	check_ercd(ercd, E_CTX);

	ercd = wai_sem(SEM1);
	check_ercd(ercd, E_CTX);

	check_point(10);
	ercd = iwup_tsk(TASK1);
	check_ercd(ercd, E_OK);

	check_point(11);
	return;

	check_point(0);
}

void
task1(intptr_t exinf)
{
	ER		ercd;
	T_RSEM	rsem;

	check_point(1);
	ercd = ref_sem(SEM1, &rsem);
	check_ercd(ercd, E_OK);
	check_assert(rsem.wtskid == TSK_NONE);
	check_assert(rsem.semcnt == 1);

	ercd = ref_sem(SEM2, &rsem);
	check_ercd(ercd, E_OK);
	check_assert(rsem.wtskid == TSK_NONE);
	check_assert(rsem.semcnt == 2);

	ercd = ref_sem(SEM3, &rsem);
	check_ercd(ercd, E_OK);
	check_assert(rsem.wtskid == TSK_NONE);
	check_assert(rsem.semcnt == 0);

	check_point(2);
	ercd = loc_cpu();
	check_ercd(ercd, E_OK);

	ercd = sig_sem(SEM1);
	check_ercd(ercd, E_CTX);

	ercd = wai_sem(SEM1);
	check_ercd(ercd, E_CTX);

	ercd = unl_cpu();
	check_ercd(ercd, E_OK);

	ercd = dis_dsp();
	check_ercd(ercd, E_OK);

	ercd = wai_sem(SEM1);
	check_ercd(ercd, E_CTX);

	ercd = ena_dsp();
	check_ercd(ercd, E_OK);

	ercd = chg_ipm(TMAX_INTPRI);
	check_ercd(ercd, E_OK);

	ercd = wai_sem(SEM1);
	check_ercd(ercd, E_CTX);

	ercd = chg_ipm(TIPM_ENAALL);
	check_ercd(ercd, E_OK);

	ercd = sig_sem(0);
	check_ercd(ercd, E_ID);

	ercd = wai_sem(0);
	check_ercd(ercd, E_ID);

	ercd = sig_sem(TNUM_SEMID+1);
	check_ercd(ercd, E_ID);

	ercd = wai_sem(TNUM_SEMID+1);
	check_ercd(ercd, E_ID);

	check_point(3);
	ercd = act_tsk(TASK3);
	check_ercd(ercd, E_OK);

	check_point(4);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(12);
	ercd = act_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(14);
	ercd = ref_sem(SEM1, &rsem);
	check_ercd(ercd, E_OK);
	check_assert(rsem.wtskid == TASK3);
	check_assert(rsem.semcnt == 0);

	check_point(15);
	ercd = sig_sem(SEM1);
	check_ercd(ercd, E_OK);

	check_point(16);
	ercd = sig_sem(SEM1);
	check_ercd(ercd, E_OK);

	check_point(18);
	ercd = dis_dsp();
	check_ercd(ercd, E_OK);

	check_point(19);
	ercd = sig_sem(SEM1);
	check_ercd(ercd, E_OK);

	check_point(20);
	ercd = ena_dsp();
	check_ercd(ercd, E_OK);

	check_point(22);
	ercd = sus_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(23);
	ercd = sig_sem(SEM1);
	check_ercd(ercd, E_OK);

	check_point(24);
	ercd = sig_sem(SEM1);
	check_ercd(ercd, E_OK);

	check_point(25);
	ercd = sig_sem(SEM1);
	check_ercd(ercd, E_QOVR);

	check_point(26);
	ercd = ref_sem(SEM1, &rsem);
	check_ercd(ercd, E_OK);
	check_assert(rsem.wtskid == TSK_NONE);
	check_assert(rsem.semcnt == 1);

	check_point(27);
	ercd = rsm_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(32);
	ercd = sig_sem(SEM2);
	check_ercd(ercd, E_OK);

	check_point(34);
	ercd = sig_sem(SEM2);
	check_ercd(ercd, E_OK);

	check_point(35);
	ercd = sig_sem(SEM2);
	check_ercd(ercd, E_OK);

	check_point(36);
	ercd = ref_sem(SEM2, &rsem);
	check_ercd(ercd, E_OK);
	check_assert(rsem.wtskid == TSK_NONE);
	check_assert(rsem.semcnt == 2);

	check_point(37);
	ercd = sig_sem(SEM2);
	check_ercd(ercd, E_QOVR);

	check_point(38);
	ercd = ref_sem(SEM2, &rsem);
	check_ercd(ercd, E_OK);
	check_assert(rsem.wtskid == TSK_NONE);
	check_assert(rsem.semcnt == 2);

	check_point(39);

	check_point(40);
	ercd = tslp_tsk(10);
	check_ercd(ercd, E_TMOUT);

	check_point(42);
	ercd = act_tsk(TASK4);
	check_ercd(ercd, E_OK);

	check_point(43);
	ercd = act_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(44);
	ercd = rot_rdq(TPRI_SELF);
	check_ercd(ercd, E_OK);

	check_point(47);
	ercd = sig_sem(SEM3);
	check_ercd(ercd, E_OK);

	check_point(49);
	ercd = sig_sem(SEM3);
	check_ercd(ercd, E_OK);

	check_point(50);
	ercd = tslp_tsk(10);
	check_ercd(ercd, E_TMOUT);

	check_point(52);
	ercd = sig_sem(SEM3);
	check_ercd(ercd, E_OK);

	check_point(53);
	ercd = tslp_tsk(10);
	check_ercd(ercd, E_TMOUT);

	check_point(55);
	ercd = sig_sem(SEM3);
	check_ercd(ercd, E_OK);

	check_point(56);
	ercd = tslp_tsk(10);
	check_ercd(ercd, E_TMOUT);

	check_point(58);
	ercd = rel_wai(TASK2);
	check_ercd(ercd, E_OK);

	check_point(60);
	ercd = ini_sem(SEM1);
	check_ercd(ercd, E_OK);

	check_finish(62);

	check_point(0);
}

void
task2(intptr_t exinf)
{
	ER		ercd;
	T_RSEM	rsem;

	check_point(13);
	ercd = wai_sem(SEM1);
	check_ercd(ercd, E_OK);

	check_point(17);
	ercd = wai_sem(SEM1);
	check_ercd(ercd, E_OK);

	check_point(21);
	ercd = wai_sem(SEM1);
	check_ercd(ercd, E_OK);

	check_point(28);
	ercd = wai_sem(SEM2);
	check_ercd(ercd, E_OK);

	check_point(29);
	ercd = ref_sem(SEM2, &rsem);
	check_ercd(ercd, E_OK);
	check_assert(rsem.wtskid == TSK_NONE);
	check_assert(rsem.semcnt == 1);

	check_point(30);
	ercd = wai_sem(SEM2);
	check_ercd(ercd, E_OK);

	check_point(31);
	ercd = wai_sem(SEM2);
	check_ercd(ercd, E_OK);

	check_point(33);
	ercd = wai_sem(SEM3);
	check_ercd(ercd, E_OK);

	check_point(48);
	ercd = wai_sem(SEM1);
	check_ercd(ercd, E_OK);

	ercd = wai_sem(SEM1);
	check_ercd(ercd, E_RLWAI);

	check_point(59);
	ercd = wai_sem(SEM1);
	check_ercd(ercd, E_DLT);

	check_point(61);
	ercd = ext_tsk();

	check_point(0);
}

void
task3(intptr_t exinf)
{
	ER		ercd;
	T_RSEM	rsem;

	check_point(5);
	ercd = wai_sem(SEM1);
	check_ercd(ercd, E_OK);

	check_point(6);
	ercd = ref_sem(SEM1, &rsem);
	check_ercd(ercd, E_OK);
	check_assert(rsem.wtskid == TSK_NONE);
	check_assert(rsem.semcnt == 0);

	check_point(7);
	ercd = sta_alm(ALM1, 10);
	check_ercd(ercd, E_OK);

	check_point(8);
	ercd = wai_sem(SEM1);
	check_ercd(ercd, E_OK);

	check_point(41);
	ercd = wai_sem(SEM3);
	check_ercd(ercd, E_OK);

	check_point(57);
	ercd = ext_tsk();

	check_point(0);
}

void
task4(intptr_t exinf)
{
	ER		ercd;

	check_point(45);
	ercd = wai_sem(SEM3);
	check_ercd(ercd, E_OK);

	check_point(51);
	ercd = ext_tsk();

	check_point(0);
}

void
task5(intptr_t exinf)
{
	ER		ercd;

	check_point(46);
	ercd = wai_sem(SEM3);
	check_ercd(ercd, E_OK);

	check_point(54);
	ercd = ext_tsk();

	check_point(0);
}
