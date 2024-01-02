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
 *  @(#) $Id: perf2.c 1575 2009-05-31 14:15:46Z ertl-hiro $
 */

/*
 *		�J�[�l�����\�]���v���O����(2)
 *
 *  �D��x�f�[�^�L���[�ɒ~�ς���Ă���f�[�^�̐��ɂ��Csnd_pdq�̏�����
 *  �Ԃ��ǂ̂悤�ɕω����邩���v�����邽�߂̃v���O�����D
 */

#include <kernel.h>
#include <t_syslog.h>
#include <test_lib.h>
#include <histogram.h>
#include "kernel_cfg.h"
#include "perf2.h"

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
 *  �v�����[�`��
 */
void
perf_eval(uint_t n)
{
	uint_t		i;
	intptr_t	data;
	PRI			pri;

	ini_pdq(PDQ1);
	init_hist(1, MAX_TIME, histarea1);

	for (i = 0; i < n; i++) {
		data = i;
		snd_pdq(PDQ1, data, 1);
	}

	for (i = 0; i < NO_MEASURE; i++) {
		data = i;
		begin_measure(1);
		snd_pdq(PDQ1, data, 2);
		end_measure(1);
		rcv_pdq(PDQ1, &data, &pri);
	}

	syslog_1(LOG_NOTICE, "Execution times of snd_pdq"
								" when %d data are queued.", n);
	print_hist(1);
	syslog_flush();
}

/*
 *  ���C���^�X�N�i��D��x�j
 */
void main_task(intptr_t exinf)
{
	syslog_0(LOG_NOTICE, "Performance evaluation program (2)");
	syslog_flush();

	perf_eval(0);
	perf_eval(10);
	perf_eval(20);
	perf_eval(30);
	perf_eval(40);
	perf_eval(50);
	perf_eval(100);
	perf_eval(200);
	perf_eval(300);
	test_finish();
}
