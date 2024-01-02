/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: mailbox.h 264 2007-07-12 08:23:10Z hiro $
 */

/*
 *		���[���{�b�N�X�@�\
 */

#ifndef TOPPERS_MAILBOX_H
#define TOPPERS_MAILBOX_H

#include <queue.h>

/*
 *  ���[���{�b�N�X�������u���b�N
 *
 *  ���̍\���̂́C�����E�ʐM�I�u�W�F�N�g�̏������u���b�N�̋��ʕ���
 *  �iWOBJINIB�j���g���i�I�u�W�F�N�g�w������̌p���ɑ����j�������̂ŁC
 *  �ŏ��̃t�B�[���h�����ʂɂȂ��Ă���D
 */
typedef struct mailbox_initialization_block {
	ATR			mbxatr;			/* ���[���{�b�N�X���� */
	PRI			maxmpri;		/* ���b�Z�[�W�D��x�̍ő�l */
} MBXINIB;

/*
 *  ���[���{�b�N�X�Ǘ��u���b�N
 *
 *  ���̍\���̂́C�����E�ʐM�I�u�W�F�N�g�̊Ǘ��u���b�N�̋��ʕ����iWOBJCB�j
 *  ���g���i�I�u�W�F�N�g�w������̌p���ɑ����j�������̂ŁC�ŏ���2��
 *  �t�B�[���h�����ʂɂȂ��Ă���D
 *
 *  ���b�Z�[�W�L���[�����b�Z�[�W�̗D��x���̏ꍇ�ɂ́Cpk_last�͎g���
 *  ���D�܂��C���b�Z�[�W�L���[����̏ꍇ�ipk_head��NULL�̏ꍇ�j�ɂ��C
 *  pk_last�͖����ł���D
 */
typedef struct mailbox_control_block {
	QUEUE		wait_queue;		/* ���[���{�b�N�X�҂��L���[ */
	const MBXINIB *p_mbxinib;	/* �������u���b�N�ւ̃|�C���^ */
	T_MSG		*pk_head;		/* �擪�̃��b�Z�[�W */
	T_MSG		*pk_last;		/* �����̃��b�Z�[�W */
} MBXCB;

/*
 *  ���[���{�b�N�X�҂����u���b�N�̒�`
 *
 *  ���̍\���̂́C�����E�ʐM�I�u�W�F�N�g�̑҂����u���b�N�̋��ʕ���
 *  �iWINFO_WOBJ�j���g���i�I�u�W�F�N�g�w������̌p���ɑ����j�������̂ŁC
 *  �ŏ���2�̃t�B�[���h�����ʂɂȂ��Ă���D
 */
typedef struct mailbox_waiting_information {
	WINFO		winfo;			/* �W���̑҂����u���b�N */
	MBXCB		*p_mbxcb;		/* �҂��Ă��郁�[���{�b�N�X�̊Ǘ��u���b�N */
	T_MSG		*pk_msg;		/* ��M�������b�Z�[�W */
} WINFO_MBX;

/*
 *  ���[���{�b�N�XID�̍ő�l�ikernel_cfg.c�j
 */
extern const ID	tmax_mbxid;

/*
 *  ���[���{�b�N�X�������u���b�N�̃G���A�ikernel_cfg.c�j
 */
extern const MBXINIB	mbxinib_table[];

/*
 *  ���[���{�b�N�X�Ǘ��u���b�N�̃G���A�ikernel_cfg.c�j
 */
extern MBXCB	mbxcb_table[];

/*
 *  ���[���{�b�N�X�Ǘ��u���b�N���烁�[���{�b�N�XID�����o�����߂̃}�N��
 */
#define	MBXID(p_mbxcb)	((ID)(((p_mbxcb) - mbxcb_table) + TMIN_MBXID))

/*
 *  ���[���{�b�N�X�@�\�̏�����
 */
extern void	initialize_mailbox(void);

#endif /* TOPPERS_MAILBOX_H */
