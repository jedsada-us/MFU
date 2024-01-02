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
 *  @(#) $Id: perf3.c 1575 2009-05-31 14:15:46Z ertl-hiro $
 */

/*
 *		�J�[�l�����\�]���v���O����(3)
 *
 *  �҂���������^�X�N�̐��ɂ��Cset_flg�̏������Ԃ��ǂ̂悤�ɕω�����
 *  �����v�����邽�߂̃v���O�����D
 */

#include <kernel.h>
#include <t_syslog.h>
#include <test_lib.h>
#include <histogram.h>
#include "kernel_cfg.h"
#include "perf3.h"

/*
 *  �v���񐔂Ǝ��s���ԕ��z���L�^����ő厞��
 */
#define NO_MEASURE	10000U			/* �v���� */
#define MAX_TIME	1000U			/* ���s���ԕ��z���L�^����ő厞�� */

/*
 *  ���s���ԕ��z���L�^���郁�����̈�
 */
static uint_t	histarea1[MAX_TIME + 1];

/*
 *  �v���^�X�N�̃��X�g
 */
static ID task_list[20] = {
	TASK1, TASK2, TASK3, TASK4, TASK5,
	TASK6, TASK7, TASK8, TASK9, TASK10,
	TASK11, TASK12, TASK13, TASK14, TASK15,
	TASK16, TASK17, TASK18, TASK19, TASK20
};

/*
 *  �v���^�X�N�i���D��x�j
 */
void task(intptr_t exinf)
{
	FLGPTN	flgptn;

	wai_flg(FLG1, 0x01U, TWF_ORW, &flgptn);
}

/*
 *  �v�����[�`��
 */
void
perf_eval(uint_t n)
{
	uint_t		i, j;

	init_hist(1, MAX_TIME, histarea1);

	for (i = 0; i < NO_MEASURE; i++) {
		ini_flg(FLG1);
		for (j = 0; j < n; j++) {
			act_tsk(task_list[j]);
		}
		chg_pri(TSK_SELF, MAIN_PRIORITY_LOW);
		/* �^�X�N���҂���Ԃɓ���̂�҂� */
		chg_pri(TSK_SELF, TPRI_INI);

		begin_measure(1);
		set_flg(FLG1, 0x01U);
		end_measure(1);

		chg_pri(TSK_SELF, MAIN_PRIORITY_LOW);
		/* �^�X�N���I������̂�҂� */
		chg_pri(TSK_SELF, TPRI_INI);
	}

	syslog_1(LOG_NOTICE, "Execution times of set_flg"
							" when %d tasks are released from waiting.", n);
	print_hist(1);
	syslog_flush();
}

/*
 *  ���C���^�X�N�i���D��x�j
 */
void main_task(intptr_t exinf)
{
	syslog_0(LOG_NOTICE, "Performance evaluation program (3)");
	syslog_flush();

	perf_eval(0);
	perf_eval(1);
	perf_eval(2);
	perf_eval(3);
	perf_eval(4);
	perf_eval(5);
	perf_eval(10);
	perf_eval(20);
	test_finish();
}
