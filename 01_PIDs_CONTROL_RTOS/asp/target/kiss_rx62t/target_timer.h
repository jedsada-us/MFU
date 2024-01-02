/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2003-2004 by Naoki Saito
 *             Nagoya Municipal Industrial Research Institute, JAPAN
 *  Copyright (C) 2003-2004 by Platform Development Center
 *                                          RICOH COMPANY,LTD. JAPAN
 *  Copyright (C) 2008-2010 by Witz Corporation, JAPAN
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
 */

/*
 *		�^�C�}�h���C�o�iKISS-RX62T�p�j
 */
 
#ifndef TOPPERS_TARGET_TIMER_H
#define TOPPERS_TARGET_TIMER_H

#include <sil.h>
#include "kiss_rx62t_config.h"
#include "target_syssvc.h"

/*
 *  �^�C�}�����݃n���h���o�^�̂��߂̒萔
 */
#define INHNO_TIMER		INT_CMT0_CMI				/* �����݃n���h���ԍ� */
#define INTNO_TIMER		INT_CMT0_CMI				/* �����ݔԍ� */
#define INTPRI_TIMER	-5							/* �����ݗD��x */
#define INTATR_TIMER	(TA_ENAINT | TA_EDGE)		/* �����ݑ��� */

#ifndef TOPPERS_MACRO_ONLY

/*
 *  �^�C�}�l�̓����\���̌^
 */
typedef uint16_t	CLOCK;

/*
 *  �^�C�}�l�̓����\���ƃ~���b�P�ʂƂ̕ϊ�
 *
 *  1ms�̃^�C�}�[���荞�݂��g�p����̂ł��̃N���b�N���`����D
 */
#define TIMER_CLOCK				(50000U / 5U)		/* PCLK/�Œᕪ����10 = 5MHz */
#define TO_CLOCK(nume, deno)	((CLOCK)(TIMER_CLOCK * (nume) / (deno)))
#define	TO_USEC(clock)			((SYSUTM)((clock) * 1000U / TIMER_CLOCK))

/*
 *  �ݒ�ł���ő�̃^�C�}�����i�P�ʂ͓����\���j
 */
#define	MAX_CLOCK	((CLOCK) 0xFFFFU)

/*
 *  ���\�]���p�V�X�e�����������o���ۂ̏������Ԃ̌��ς�l�i�P�ʂ͓����\���j
 */
#define	GET_TOLERANCE	(100U)	/* �����x��̌��ς�l�i�P�ʂ͓����\���j*/
#define	BEFORE_IREQ(clock) \
		((clock) >= (TO_CLOCK(TIC_NUME, TIC_DENO) - GET_TOLERANCE))

/*
 *  �R���y�A�}�b�`�^�C�}�R���g���[�����W�X�^�̐ݒ�l
 */
/*
 *  �N���b�N�I���r�b�g
 *
 *  bit7�͗\��̈�ł���, �����݂�1�Œ�
 */
#define CMT_PCLK_DIV_8			(0x0080U)
#define CMT_PCLK_DIV_32			(0x0081U)
#define CMT_PCLK_DIV_128		(0x0082U)
#define CMT_PCLK_DIV_512		(0x0083U)

/*
 *  �R���y�A�}�b�`�^�C�}�R���X�^���g���W�X�^�iCMCOR�j
 *
 *  �R���y�A�}�b�`������1ms�Ƃ���D
 *  ���Ӄ��W���[���N���b�N�iPCLK�j50MHz��8��������̂ŁC
 *  1����������160nsec�ƂȂ�C6250������1ms�i�^�C���e�B�b�N�̎����j�Ƃ���D
 */
#define CMCOR_PERIOD			(TIMER_CLOCK)

/*
 * �R���y�A�}�b�`�^�C�}���荞�ݗv����ݒ背�W�X�^i�iISELRi�j�ii= ���荞�݃x�N�^�ԍ��j
 */
#define ICU_ISEL_CPU			(0x00U)




/*
 *  �^�C�}�̋N������
 *
 *  �^�C�}�����������C�����I�ȃ^�C�}�����ݗv���𔭐�������D
 */
extern void	target_timer_initialize(intptr_t exinf);

/*
 *  �^�C�}�̒�~����
 *
 *  �^�C�}�̓�����~������D
 */
extern void	target_timer_terminate(intptr_t exinf);

/*
 *  �^�C�}���W�X�^�l�̓ǂݏo��
 */
Inline uint16_t rx600_cmt_getcount(void)
{
	return *CMT0_CMCNT_ADDR;
}

/*
 *  �^�C�}���W�X�^�l�̏�������
 */
Inline void rx600_cmt_setcount(uint16_t count)
{
	*CMT0_CMCNT_ADDR = count;
}

/*
 *  �^�C�}�̌��ݒl�̓Ǐo��
 */
Inline CLOCK
target_timer_get_current(void)
{
	/* �A�b�v�J�E���g�̂��߃^�C�}���W�X�^�l�����̂܂ܕԂ�	*/
	return (rx600_cmt_getcount());
}

/*
 *  �^�C�}�����ݗv���̃`�F�b�N
 */
Inline bool_t
target_timer_probe_int(void)
{
	return(x_probe_int(INTNO_TIMER));
}

/*
 *  �^�C�}�����݃n���h��
 */
extern void	target_timer_handler(void);

#endif /* TOPPERS_MACRO_ONLY */
#endif /* TOPPERS_TARGET_TIMER_H */
