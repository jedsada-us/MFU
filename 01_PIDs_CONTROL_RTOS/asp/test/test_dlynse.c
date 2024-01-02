/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2007-2010 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: test_dlynse.c 1803 2010-06-20 08:55:06Z ertl-hiro $
 */

/*
 *		sil_dly_nse�Ɋւ���e�X�g
 */

#include <kernel.h>
#include <sil.h>
#include <test_lib.h>
#include <t_syslog.h>
#include "kernel_cfg.h"
#include "test_dlynse.h"

/*
 *  SIL_DLY_TIM1��SIL_DLY_TIM2���Q�Ƃ��邽�߂ɁC�J�[�l���p�̃w�b�_�t�@
 *  �C�����C���N���[�h����D
 */
#include "kernel/kernel_impl.h"

#define	NO_LOOP		ULONG_C(1000000)

SYSTIM	empty_time;

static void
test_empty(void)
{
	SYSTIM	stime, etime;
	volatile ulong_t	i;

	get_tim(&stime);
	for (i = 0; i < NO_LOOP; i++) {
	}
	get_tim(&etime);
	empty_time = etime - stime;
	syslog(LOG_NOTICE, "empty loop: %u", empty_time);
	syslog_flush();
}

static void
test_dly_nse(ulong_t dlytim)
{
	SYSTIM	stime, etime, delay_time;
	volatile ulong_t	i;

	get_tim(&stime);
	for (i = 0; i < NO_LOOP; i++) {
		sil_dly_nse(dlytim);
	}
	get_tim(&etime);
	delay_time = (etime - stime) - empty_time;
	syslog(LOG_NOTICE, "sil_dly_nse(%u): %u %s", (uint_t)(dlytim),
				(uint_t)(delay_time), delay_time > dlytim ? "OK" : "NG");
	syslog_flush();
}

void
main_task(intptr_t exinf)
{
	test_empty();

	syslog(LOG_NOTICE, "-- for fitting parameters --");
	test_dly_nse(0);
	test_dly_nse(SIL_DLY_TIM1);
	test_dly_nse(SIL_DLY_TIM1 + SIL_DLY_TIM2 * 1);
	test_dly_nse(SIL_DLY_TIM1 + SIL_DLY_TIM2 * 2);
	test_dly_nse(SIL_DLY_TIM1 + SIL_DLY_TIM2 * 3);
	test_dly_nse(SIL_DLY_TIM1 + SIL_DLY_TIM2 * 4);
	test_dly_nse(SIL_DLY_TIM1 + SIL_DLY_TIM2 * 5);
	test_dly_nse(SIL_DLY_TIM1 + SIL_DLY_TIM2 * 10);
	test_dly_nse(SIL_DLY_TIM1 + SIL_DLY_TIM2 * 20);
	test_dly_nse(SIL_DLY_TIM1 + SIL_DLY_TIM2 * 50);

	syslog(LOG_NOTICE, "-- for checking boundary conditions --");
	test_dly_nse(SIL_DLY_TIM1 + 1);
	test_dly_nse(SIL_DLY_TIM1 + SIL_DLY_TIM2 * 1 + 1);
	test_dly_nse(SIL_DLY_TIM1 + SIL_DLY_TIM2 * 2 + 1);

	test_finish();
}
