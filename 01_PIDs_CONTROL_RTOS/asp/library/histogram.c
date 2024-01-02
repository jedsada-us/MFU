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
 *  @(#) $Id: histogram.c 1574 2009-05-31 13:57:37Z ertl-hiro $
 */

/*
 *		���s���ԕ��z�W�v���W���[��
 */

#include <kernel.h>
#include <t_syslog.h>
#include <test_lib.h>
#include <histogram.h>
#include "target_test.h"

/*
 *  ���s���ԕ��z�v���̐�
 */
#ifndef TNUM_HIST
#define TNUM_HIST		10
#endif /* TNUM_HIST */

/*
 *  �^�[�Q�b�g�ˑ����Őݒ�ύX���邽�߂̃}�N��
 */
#ifndef HISTTIM						/* ���s���Ԍv���p�̎����̃f�[�^�^ */
#define HISTTIM			SYSUTM
#endif /* HISTTIM */

#ifndef HIST_GET_TIM				/* ���s���Ԍv���p�̌��ݎ����̎擾 */
#ifndef TOPPERS_SUPPORT_GET_UTM
#error get_utm is not supported.
#endif /* TOPPERS_SUPPORT_GET_UTM */
#define HIST_GET_TIM(p_time)	((void) get_utm(p_time))
#endif /* HIST_GET_TIM */

#ifndef HIST_CONV_TIM				/* �����̍�������s���Ԃւ̕ϊ� */
#define HIST_CONV_TIM(time)		((uint_t)(time))
#endif /* HIST_CONV_TIM */

#ifndef HIST_BM_HOOK				/* ���s���Ԍv�����O�ɍs���ׂ����� */
#define HIST_BM_HOOK()			((void) 0)
#endif

/*
 *  ���s���ԕ��z�v���Ǘ��u���b�N
 */
typedef struct histogram_control_block {
	HISTTIM		begin_time;			/* �v���J�n���� */
	uint_t		maxval;				/* ���z���L�^����ő厞�� */
	uint_t		*histarea;			/* ���z���L�^���郁�����̈� */
	uint_t		over;				/* �ő厞�Ԃ𒴂����x�� */
	uint_t		under;				/* ���Ԃ̋t�]���^����x�� */
} HISTCB;

/*
 *  ���s���ԕ��z�v���Ǘ��u���b�N�̃G���A
 */
HISTCB	histcb_table[TNUM_HIST];

/*
 *  ���s���ԕ��z�v��ID�̍ŏ��l�ƍő�l
 */
#define TMIN_HISTID		1
#define TMAX_HISTID		(TMIN_HISTID + TNUM_HIST - 1)

/*
 *  ���s���ԕ��z�v���̏�����
 */
void
init_hist(ID histid, uint_t maxval, uint_t histarea[])
{
	HISTCB	*p_histcb;
	uint_t	i;

	assert(TMIN_HISTID <= histid && histid <= TMAX_HISTID);
	p_histcb = &(histcb_table[histid - TMIN_HISTID]);

	for (i = 0; i <= maxval; i++) {
		histarea[i] = 0U;
	}
	p_histcb->maxval = maxval;
	p_histcb->histarea = histarea;
	p_histcb->over = 0U;
	p_histcb->under = 0U;
}

/*
 *  ���s���Ԍv���̊J�n
 */
void
begin_measure(ID histid)
{
	HISTCB	*p_histcb;

	assert(TMIN_HISTID <= histid && histid <= TMAX_HISTID);
	p_histcb = &(histcb_table[histid - TMIN_HISTID]);

	HIST_BM_HOOK();
	HIST_GET_TIM(&(p_histcb->begin_time));
}

/*
 *  ���s���Ԍv���̏I��
 */
void
end_measure(ID histid)
{
	HISTCB	*p_histcb;
	HISTTIM	end_time;
	uint_t	val;

	HIST_GET_TIM(&end_time);

	assert(TMIN_HISTID <= histid && histid <= TMAX_HISTID);
	p_histcb = &(histcb_table[histid - TMIN_HISTID]);

	val = HIST_CONV_TIM(end_time - p_histcb->begin_time);
	if (val <= p_histcb->maxval) {
		p_histcb->histarea[val]++;
	}
	else if (val <= ((uint_t) INT_MAX)) {
		p_histcb->over++;
	}
	else {
		p_histcb->under++;
	}
}

/*
 *  ���s���ԕ��z�v���̕\��
 */
void
print_hist(ID histid)
{
	HISTCB	*p_histcb;
	uint_t	i;

	assert(TMIN_HISTID <= histid && histid <= TMAX_HISTID);
	p_histcb = &(histcb_table[histid - TMIN_HISTID]);

	for (i = 0; i <= p_histcb->maxval; i++) {
		if (p_histcb->histarea[i] > 0) {
			syslog_2(LOG_NOTICE, "%d : %d", i, p_histcb->histarea[i]);
			syslog_flush();
		}
	}
	if (p_histcb->over > 0) {
		syslog_2(LOG_NOTICE, "> %d : %d", p_histcb->maxval, p_histcb->over);
	}
	if (p_histcb->under > 0) {
		syslog_1(LOG_NOTICE, "> INT_MAX : %d", p_histcb->under);
	}
	syslog_flush();
}
