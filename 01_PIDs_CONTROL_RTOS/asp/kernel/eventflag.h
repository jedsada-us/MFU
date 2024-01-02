/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005-2008 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: eventflag.h 748 2008-03-07 17:18:06Z hiro $
 */

/*
 *		�C�x���g�t���O�@�\
 */

#ifndef TOPPERS_EVENTFLAG_H
#define TOPPERS_EVENTFLAG_H

#include <queue.h>

/*
 *  �C�x���g�t���O�������u���b�N
 *
 *  ���̍\���̂́C�����E�ʐM�I�u�W�F�N�g�̏������u���b�N�̋��ʕ���
 *  �iWOBJINIB�j���g���i�I�u�W�F�N�g�w������̌p���ɑ����j�������̂ŁC
 *  �ŏ��̃t�B�[���h�����ʂɂȂ��Ă���D
 */
typedef struct eventflag_initialization_block {
	ATR			flgatr;			/* �C�x���g�t���O���� */
	FLGPTN		iflgptn;		/* �C�x���g�t���O�̃r�b�g�p�^�[���̏����l */
} FLGINIB;

/*
 *  �C�x���g�t���O�Ǘ��u���b�N
 *
 *  ���̍\���̂́C�����E�ʐM�I�u�W�F�N�g�̊Ǘ��u���b�N�̋��ʕ����iWOBJCB�j
 *  ���g���i�I�u�W�F�N�g�w������̌p���ɑ����j�������̂ŁC�ŏ���2��
 *  �t�B�[���h�����ʂɂȂ��Ă���D
 */
typedef struct eventflag_control_block {
	QUEUE		wait_queue;		/* �C�x���g�t���O�҂��L���[ */
	const FLGINIB *p_flginib;	/* �������u���b�N�ւ̃|�C���^ */
	FLGPTN		flgptn;			/* �C�x���g�t���O���݃p�^�[�� */
} FLGCB;

/*
 *  �C�x���g�t���O�҂����u���b�N�̒�`
 *
 *  ���̍\���̂́C�����E�ʐM�I�u�W�F�N�g�̑҂����u���b�N�̋��ʕ���
 *  �iWINFO_WOBJ�j���g���i�I�u�W�F�N�g�w������̌p���ɑ����j�������̂ŁC
 *  �ŏ���2�̃t�B�[���h�����ʂɂȂ��Ă���D
 *
 *  flgptn�́Cwaiptn�����wfmode�Ɠ����Ɏg�����Ƃ͂Ȃ����߁C���p�̂��g
 *  ���΃�������ߖ񂷂邱�Ƃ��\�ł���D
 */
typedef struct eventflag_waiting_information {
	WINFO		winfo;			/* �W���̑҂����u���b�N */
	FLGCB		*p_flgcb;		/* �҂��Ă���C�x���g�t���O�̊Ǘ��u���b�N */
	FLGPTN		waiptn;			/* �҂��p�^�[�� */
	MODE		wfmode;			/* �҂����[�h */
	FLGPTN		flgptn;			/* �҂��������̃p�^�[�� */
} WINFO_FLG;

/*
 *  �C�x���g�t���OID�̍ő�l�ikernel_cfg.c�j
 */
extern const ID	tmax_flgid;

/*
 *  �C�x���g�t���O�������u���b�N�̃G���A�ikernel_cfg.c�j
 */
extern const FLGINIB	flginib_table[];

/*
 *  �C�x���g�t���O�Ǘ��u���b�N�̃G���A�ikernel_cfg.c�j
 */
extern FLGCB	flgcb_table[];

/*
 *  �C�x���g�t���O�Ǘ��u���b�N����C�x���g�t���OID�����o�����߂̃}�N��
 */
#define	FLGID(p_flgcb)	((ID)(((p_flgcb) - flgcb_table) + TMIN_FLGID))

/*
 *  �C�x���g�t���O�@�\�̏�����
 */
extern void	initialize_eventflag(void);

/*
 *  �C�x���g�t���O�҂����������̃`�F�b�N
 */
extern bool_t	check_flg_cond(FLGCB *p_flgcb, FLGPTN waiptn,
								MODE wfmode, FLGPTN *p_flgptn);

#endif /* TOPPERS_EVENTFLAG_H */
