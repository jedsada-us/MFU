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
 *  @(#) $Id: dataqueue.h 748 2008-03-07 17:18:06Z hiro $
 */

/*
 *		�f�[�^�L���[�@�\
 */

#ifndef TOPPERS_DATAQUEUE_H
#define TOPPERS_DATAQUEUE_H

#include <queue.h>

/*
 *  �f�[�^�L���[�������u���b�N
 *
 *  ���̍\���̂́C�����E�ʐM�I�u�W�F�N�g�̏������u���b�N�̋��ʕ���
 *  �iWOBJINIB�j���g���i�I�u�W�F�N�g�w������̌p���ɑ����j�������̂ŁC
 *  �ŏ��̃t�B�[���h�����ʂɂȂ��Ă���D
 */
typedef struct dataqueue_initialization_block {
	ATR			dtqatr;			/* �f�[�^�L���[���� */
	uint_t		dtqcnt;			/* �f�[�^�L���[�̗e�� */
	intptr_t	*p_dtqmb;		/* �f�[�^�L���[�Ǘ��̈�̐擪�Ԓn */
} DTQINIB;

/*
 *  �f�[�^�L���[�Ǘ��u���b�N
 *
 *  ���̍\���̂́C�����E�ʐM�I�u�W�F�N�g�̊Ǘ��u���b�N�̋��ʕ����iWOBJCB�j
 *  ���g���i�I�u�W�F�N�g�w������̌p���ɑ����j�������̂ŁC�ŏ���2��
 *  �t�B�[���h�����ʂɂȂ��Ă���D
 */
typedef struct dataqueue_control_block {
	QUEUE		swait_queue;	/* �f�[�^�L���[���M�҂��L���[ */
	const DTQINIB *p_dtqinib;	/* �������u���b�N�ւ̃|�C���^ */
	QUEUE		rwait_queue;	/* �f�[�^�L���[��M�҂��L���[ */
	uint_t		count;			/* �f�[�^�L���[���̃f�[�^�̐� */
	uint_t		head;			/* �ŏ��̃f�[�^�̊i�[�ꏊ */
	uint_t		tail;			/* �Ō�̃f�[�^�̊i�[�ꏊ�̎� */
} DTQCB;

/*
 *  �f�[�^�L���[�҂����u���b�N�̒�`
 *
 *  ���̍\���̂́C�����E�ʐM�I�u�W�F�N�g�̑҂����u���b�N�̋��ʕ���
 *  �iWINFO_WOBJ�j���g���i�I�u�W�F�N�g�w������̌p���ɑ����j�������̂ŁC
 *  �ŏ���2�̃t�B�[���h�����ʂɂȂ��Ă���D
 *  �f�[�^�L���[�ւ̑��M�҂��ƃf�[�^�L���[����̎�M�҂��ŁC�����҂���
 *  ��u���b�N���g���D
 */
typedef struct dataqueue_waiting_information {
	WINFO		winfo;			/* �W���̑҂����u���b�N */
	DTQCB		*p_dtqcb;		/* �҂��Ă���f�[�^�L���[�̊Ǘ��u���b�N */
	intptr_t	data;			/* ����M�f�[�^ */
} WINFO_DTQ;

/*
 *  �f�[�^�L���[ID�̍ő�l�ikernel_cfg.c�j
 */
extern const ID	tmax_dtqid;

/*
 *  �f�[�^�L���[�������u���b�N�̃G���A�ikernel_cfg.c�j
 */
extern const DTQINIB	dtqinib_table[];

/*
 *  �f�[�^�L���[�Ǘ��u���b�N�̃G���A�ikernel_cfg.c�j
 */
extern DTQCB	dtqcb_table[];

/*
 *  �f�[�^�L���[�Ǘ��u���b�N����f�[�^�L���[ID�����o�����߂̃}�N��
 */
#define	DTQID(p_dtqcb)	((ID)(((p_dtqcb) - dtqcb_table) + TMIN_DTQID))

/*
 *  �f�[�^�L���[�@�\�̏�����
 */
extern void	initialize_dataqueue(void);

/*
 *  �f�[�^�L���[�Ǘ��̈�ւ̃f�[�^�̊i�[
 */
extern void	enqueue_data(DTQCB *p_dtqcb, intptr_t data);

/*
 *  �f�[�^�L���[�Ǘ��̈�ւ̃f�[�^�̋����i�[
 */
extern void	force_enqueue_data(DTQCB *p_dtqcb, intptr_t data);

/*
 *  �f�[�^�L���[�Ǘ��̈悩��̃f�[�^�̎�o��
 */
extern void	dequeue_data(DTQCB *p_dtqcb, intptr_t *p_data);

/*
 *  �f�[�^�L���[�ւ̃f�[�^���M
 */
extern bool_t	send_data(DTQCB *p_dtqcb, intptr_t data, bool_t *p_reqdsp);

/*
 *  �f�[�^�L���[�ւ̃f�[�^�������M
 */
extern bool_t	force_send_data(DTQCB *p_dtqcb, intptr_t data);

/*
 *  �f�[�^�L���[����̃f�[�^��M
 */
extern bool_t	receive_data(DTQCB *p_dtqcb, intptr_t *p_data,
													bool_t *p_reqdsp);

#endif /* TOPPERS_DATAQUEUE_H */
