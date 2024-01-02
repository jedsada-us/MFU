/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 * 
 *  Copyright (C) 2006-2009 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: perf4.c 1575 2009-05-31 14:15:46Z ertl-hiro $
 */

/*
 *		�J�[�l�����\�]���v���O����(4)
 *
 *  act_tsk�Ciact_tsk�̏������Ԃƃ^�X�N�؊������Ԃ��v�����邽�߂̃v���O
 *  �����D�ȉ���3�̎��Ԃ𑪒肷��D
 *
 *  (1) �^�X�N�؊������N�����Ȃ�act_tsk�̏������ԁD���^�X�N�����D��x
 *      �̒Ⴂ�^�X�N�ɑ΂���act_tsk�𔭍s���C�x�~��Ԃ�����s�ł�����
 *      �ɑJ�ڂ����鏈���̎��ԁD
 *
 *  (2) �^�X�N�؊������N����act_tsk�̏������ԁD���^�X�N�����D��x�̍�
 *      ���^�X�N�ɑ΂���act_tsk�𔭍s���C�x�~��Ԃ�����s�ł����ԂɑJ
 *      �ڂ����C�^�X�N�؊������N�����āC�����D��x�̃^�X�N�̎��s���n��
 *      ��܂ł̎��ԁD
 *
 *  (3) �^�X�N�؊������N����iact_tsk�̏������ԁD�����n���h������C���s
 *      ��Ԃ̃^�X�N���������D��x�̃^�X�N�ɑ΂���act_tsk�𔭍s���C�x
 *      �~��Ԃ�����s�ł����ԂɑJ�ڂ��������ƂɎ����n���h�����烊�^�[
 *      �����C�^�X�N�؊������N�����āC�����D��x�̃^�X�N�̎��s���n�܂�
 *      �܂ł̎��ԁD
 */

#include <kernel.h>
#include <t_syslog.h>
#include <test_lib.h>
#include <histogram.h>
#include "kernel_cfg.h"
#include "perf4.h"

/*
 *  �v���񐔂Ǝ��s���ԕ��z���L�^����ő厞��
 */
#define NO_MEASURE	10000U			/* �v���� */
#define MAX_TIME	1000U			/* ���s���ԕ��z���L�^����ő厞�� */

/*
 *  ���s���ԕ��z���L�^���郁�����̈�
 */
static uint_t	histarea1[MAX_TIME + 1];
static uint_t	histarea2[MAX_TIME + 1];
static uint_t	histarea3[MAX_TIME + 1];

/*
 *  �v���^�X�N1�i���D��x�j
 */
void task1(intptr_t exinf)
{
	end_measure(2);
	ext_tsk();
}

/*
 *  �v���^�X�N2�ƃ��C���^�X�N�̋��L�ϐ�
 */
volatile uint_t		task2_count;

/*
 *  �v���^�X�N2�i���D��x�j
 */
void task2(intptr_t exinf)
{
	end_measure(3);
	task2_count++;
	ext_tsk();
}

/*
 *  �v���^�X�N3�i��D��x�j
 */
void task3(intptr_t exinf)
{
	ext_tsk();
}

/*
 *  �v���^�X�N4�i�Œ�D��x�j
 */
void task4(intptr_t exinf)
{
	while (true) {
		wup_tsk(MAIN_TASK);
	}
}

/*
 *  �����n���h��
 */
void cyclic_handler(intptr_t exinf)
{
	begin_measure(3);
	iact_tsk(TASK2);
}

/*
 *  ���C���^�X�N�i���D��x�j
 */
void main_task(intptr_t exinf)
{
	uint_t	i;

	syslog_0(LOG_NOTICE, "Performance evaluation program (4)");
	init_hist(1, MAX_TIME, histarea1);
	init_hist(2, MAX_TIME, histarea2);
	init_hist(3, MAX_TIME, histarea3);
	syslog_flush();

	/*
	 *  �^�X�N�؊������N�����Ȃ�act_tsk�̏������Ԃ̑���
	 */
	for (i = 0; i < NO_MEASURE; i++) {
		begin_measure(1);
		act_tsk(TASK3);
		end_measure(1);
		slp_tsk();
	}

	/*
	 *  �^�X�N�؊������N����act_tsk�̏������Ԃ̑���
	 */
	for (i = 0; i < NO_MEASURE; i++) {
		begin_measure(2);
		act_tsk(TASK1);
	}

	/*
	 *  �^�X�N�؊������N����iact_tsk�̏������Ԃ̑���i����񐔂�10����1�j
	 */
	task2_count = 0;
	sta_cyc(CYC1);
	while (task2_count < NO_MEASURE / 10) ;
	stp_cyc(CYC1);

	syslog_0(LOG_NOTICE, "Execution times of act_tsk without task switch");
	print_hist(1);
	syslog_0(LOG_NOTICE, "Execution times of act_tsk with task switch");
	print_hist(2);
	syslog_0(LOG_NOTICE, "Execution times of iact_tsk with task switch");
	print_hist(3);
	test_finish();
}
