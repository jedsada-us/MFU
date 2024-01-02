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
 *  @(#) $Id: pridataq.h 748 2008-03-07 17:18:06Z hiro $
 */

/*
 *		�D��x�f�[�^�L���[�@�\
 */

#ifndef TOPPERS_PRIDATAQ_H
#define TOPPERS_PRIDATAQ_H

#include <queue.h>

/*
 *  �D��x�f�[�^�Ǘ��u���b�N
 */
typedef struct pridata_management_block PDQMB;

struct pridata_management_block {
	PDQMB		*p_next;		/* ���̃f�[�^ */
	intptr_t	data;			/* �f�[�^�{�� */
	PRI			datapri;		/* �f�[�^�D��x */
};

/*
 *  �D��x�f�[�^�L���[�������u���b�N
 *
 *  ���̍\���̂́C�����E�ʐM�I�u�W�F�N�g�̏������u���b�N�̋��ʕ���
 *  �iWOBJINIB�j���g���i�I�u�W�F�N�g�w������̌p���ɑ����j�������̂ŁC
 *  �ŏ��̃t�B�[���h�����ʂɂȂ��Ă���D
 */
typedef struct pridataq_initialization_block {
	ATR			pdqatr;			/* �D��x�f�[�^�L���[���� */
	uint_t		pdqcnt;			/* �D��x�f�[�^�L���[�̗e�� */
	PRI			maxdpri;		/* �f�[�^�D��x�̍ő�l */
	PDQMB		*p_pdqmb;		/* �D��x�f�[�^�L���[�Ǘ��̈�̐擪�Ԓn */
} PDQINIB;

/*
 *  �D��x�f�[�^�L���[�Ǘ��u���b�N
 *
 *  ���̍\���̂́C�����E�ʐM�I�u�W�F�N�g�̊Ǘ��u���b�N�̋��ʕ����iWOBJCB�j
 *  ���g���i�I�u�W�F�N�g�w������̌p���ɑ����j�������̂ŁC�ŏ���2��
 *  �t�B�[���h�����ʂɂȂ��Ă���D
 */
typedef struct pridataq_control_block {
	QUEUE		swait_queue;	/* �D��x�f�[�^�L���[���M�҂��L���[ */
	const PDQINIB *p_pdqinib;	/* �������u���b�N�ւ̃|�C���^ */
	QUEUE		rwait_queue;	/* �D��x�f�[�^�L���[��M�҂��L���[ */
	uint_t		count;			/* �D��x�f�[�^�L���[���̃f�[�^�̐� */
	PDQMB		*p_head;		/* �ŏ��̃f�[�^ */
	uint_t		unused;			/* ���g�p�f�[�^�Ǘ��u���b�N�̐擪 */
	PDQMB		*p_freelist;	/* �������ăf�[�^�Ǘ��u���b�N�̃��X�g */
} PDQCB;

/*
 *  �D��x�f�[�^�L���[�҂����u���b�N�̒�`
 *
 *  ���̍\���̂́C�����E�ʐM�I�u�W�F�N�g�̑҂����u���b�N�̋��ʕ���
 *  �iWINFO_WOBJ�j���g���i�I�u�W�F�N�g�w������̌p���ɑ����j�������̂ŁC
 *  �ŏ���2�̃t�B�[���h�����ʂɂȂ��Ă���D
 *  �D��x�f�[�^�L���[�ւ̑��M�҂��ƗD��x�f�[�^�L���[����̎�M�҂��ŁC
 *  �����҂����u���b�N���g���D
 */
typedef struct pridataq_waiting_information {
	WINFO		winfo;			/* �W���̑҂����u���b�N */
	PDQCB		*p_pdqcb;		/* �҂��Ă���D��x�f�[�^�L���[�̊Ǘ��u���b�N*/
	intptr_t	data;			/* ����M�f�[�^ */
	PRI			datapri;		/* �f�[�^�D��x */
} WINFO_PDQ;

/*
 *  �D��x�f�[�^�L���[ID�̍ő�l�ikernel_cfg.c�j
 */
extern const ID	tmax_pdqid;

/*
 *  �D��x�f�[�^�L���[�������u���b�N�̃G���A�ikernel_cfg.c�j
 */
extern const PDQINIB	pdqinib_table[];

/*
 *  �D��x�f�[�^�L���[�Ǘ��u���b�N�̃G���A�ikernel_cfg.c�j
 */
extern PDQCB	pdqcb_table[];

/*
 *  �D��x�f�[�^�L���[�Ǘ��u���b�N����D��x�f�[�^�L���[ID�����o����
 *  �߂̃}�N��
 */
#define	PDQID(p_pdqcb)	((ID)(((p_pdqcb) - pdqcb_table) + TMIN_PDQID))

/*
 *  �D��x�f�[�^�L���[�@�\�̏�����
 */
extern void	initialize_pridataq(void);

/*
 *  �D��x�f�[�^�L���[�Ǘ��̈�ւ̃f�[�^�̊i�[
 */
extern void	enqueue_pridata(PDQCB *p_pdqcb, intptr_t data, PRI datapri);

/*
 *  �D��x�f�[�^�L���[�Ǘ��̈悩��̃f�[�^�̎�o��
 */
extern void	dequeue_pridata(PDQCB *p_pdqcb, intptr_t *p_data, PRI *p_datapri);

/*
 *  �D��x�f�[�^�L���[�ւ̃f�[�^���M
 */
extern bool_t	send_pridata(PDQCB *p_pdqcb, intptr_t data,
											PRI datapri, bool_t *p_reqdsp);

/*
 *  �D��x�f�[�^�L���[����̃f�[�^��M
 */
extern bool_t	receive_pridata(PDQCB *p_pdqcb, intptr_t *p_data,
											PRI *p_datapri, bool_t *p_reqdsp);

#endif /* TOPPERS_PRIDATAQ_H */
