/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005,2006 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: cyclic.h 748 2008-03-07 17:18:06Z hiro $
 */

/*
 *		�����n���h���@�\
 */

#ifndef TOPPERS_CYCLIC_H
#define TOPPERS_CYCLIC_H

#include "time_event.h"

/*
 *  �����n���h���������u���b�N
 */
typedef struct cyclic_handler_initialization_block {
	ATR			cycatr;			/* �����n���h������ */
	intptr_t	exinf;			/* �����n���h���̊g����� */
	CYCHDR		cychdr;			/* �����n���h���̋N���Ԓn */
	RELTIM		cyctim;			/* �����n���h���̋N������ */
	RELTIM		cycphs;			/* �����n���h���̋N���ʑ� */
} CYCINIB;

/*
 *  �����n���h���Ǘ��u���b�N
 */
typedef struct cyclic_handler_control_block {
	const CYCINIB *p_cycinib;	/* �������u���b�N�ւ̃|�C���^ */
	bool_t		cycsta;			/* �����n���h���̓����� */
	EVTTIM		evttim;			/* ���Ɏ����n���h�����N�����鎞�� */
	TMEVTB		tmevtb;			/* �^�C���C�x���g�u���b�N */
} CYCCB;

/*
 *  �����n���h��ID�̍ő�l�ikernel_cfg.c�j
 */
extern const ID	tmax_cycid;

/*
 *  �����n���h���������u���b�N�̃G���A�ikernel_cfg.c�j
 */
extern const CYCINIB	cycinib_table[];

/*
 *  �����n���h���Ǘ��u���b�N�̃G���A�ikernel_cfg.c�j
 */
extern CYCCB	cyccb_table[];

/*
 *  �����n���h���@�\�̏�����
 */
extern void	initialize_cyclic(void);

/*
 *  �����n���h���N�����[�`��
 */
extern void	call_cychdr(CYCCB *p_cyccb);

#endif /* TOPPERS_CYCLIC_H */
