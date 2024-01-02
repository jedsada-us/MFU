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
 *  @(#) $Id: mempfix.h 264 2007-07-12 08:23:10Z hiro $
 */

/*
 *		�Œ蒷�������v�[���@�\
 */

#ifndef TOPPERS_MEMPFIX_H
#define TOPPERS_MEMPFIX_H

#include <queue.h>

/*
 *  �Œ蒷�������u���b�N�Ǘ��u���b�N
 *
 *  next�t�B�[���h�ɂ́C�������u���b�N�������čς݂̏ꍇ��INDEX_ALLOC���C
 *  �������Ă̏ꍇ�͎��̖������ău���b�N�̃C���f�b�N�X�ԍ����i�[����D
 *  �Ō�̖������ău���b�N�̏ꍇ�ɂ́CINDEX_NULL���i�[����D
 */
typedef struct fixed_memoryblock_management_block {
	uint_t		next;			/* ���̖������ău���b�N */
} MPFMB;

/*
 *  �Œ蒷�������v�[���������u���b�N
 *
 *  ���̍\���̂́C�����E�ʐM�I�u�W�F�N�g�̏������u���b�N�̋��ʕ���
 *  �iWOBJINIB�j���g���i�I�u�W�F�N�g�w������̌p���ɑ����j�������̂ŁC
 *  �ŏ��̃t�B�[���h�����ʂɂȂ��Ă���D
 */
typedef struct fixed_memorypool_initialization_block {
	ATR			mpfatr;			/* �Œ蒷�������v�[������ */
	uint_t		blkcnt;			/* �������u���b�N�� */
	uint_t		blksz;			/* �������u���b�N�̃T�C�Y�i�ۂ߂��l�j */
	void		*mpf;			/* �Œ蒷�������v�[���̈�̐擪�Ԓn */
	MPFMB		*p_mpfmb;		/* �Œ蒷�������v�[���Ǘ��̈�̐擪�Ԓn */
} MPFINIB;

/*
 *  �Œ蒷�������v�[���Ǘ��u���b�N
 *
 *  ���̍\���̂́C�����E�ʐM�I�u�W�F�N�g�̊Ǘ��u���b�N�̋��ʕ����iWOBJCB�j
 *  ���g���i�I�u�W�F�N�g�w������̌p���ɑ����j�������̂ŁC�ŏ���2��
 *  �t�B�[���h�����ʂɂȂ��Ă���D
 */
typedef struct fixed_memorypool_control_block {
	QUEUE		wait_queue;		/* �Œ蒷�������v�[���҂��L���[ */
	const MPFINIB *p_mpfinib;	/* �������u���b�N�ւ̃|�C���^ */
	uint_t		fblkcnt;		/* �������ău���b�N�� */
	uint_t		unused;			/* ���g�p�u���b�N�̐擪 */
	uint_t		freelist;		/* �������ău���b�N�̃��X�g */
} MPFCB;

/*
 *  �Œ蒷�������v�[���҂����u���b�N�̒�`
 *
 *  ���̍\���̂́C�����E�ʐM�I�u�W�F�N�g�̑҂����u���b�N�̋��ʕ���
 *  �iWINFO_WOBJ�j���g���i�I�u�W�F�N�g�w������̌p���ɑ����j�������̂ŁC
 *  �ŏ���2�̃t�B�[���h�����ʂɂȂ��Ă���D
 */
typedef struct fixed_memorypool_waiting_information {
	WINFO		winfo;			/* �W���̑҂����u���b�N */
	MPFCB		*p_mpfcb;		/* �҂��Ă���Œ蒷�������v�[���̊Ǘ��u���b�N*/
	void		*blk;			/* �l�������������u���b�N */
} WINFO_MPF;

/*
 *  �Œ蒷�������v�[��ID�̍ő�l�ikernel_cfg.c�j
 */
extern const ID	tmax_mpfid;

/*
 *  �Œ蒷�������v�[���������u���b�N�̃G���A�ikernel_cfg.c�j
 */
extern const MPFINIB	mpfinib_table[];

/*
 *  �Œ蒷�������v�[���Ǘ��u���b�N�̃G���A�ikernel_cfg.c�j
 */
extern MPFCB	mpfcb_table[];

/*
 *  �Œ蒷�������v�[���Ǘ��u���b�N����Œ蒷�������v�[��ID�����o����
 *  �߂̃}�N��
 */
#define	MPFID(p_mpfcb)	((ID)(((p_mpfcb) - mpfcb_table) + TMIN_MPFID))

/*
 *  �Œ蒷�������v�[���@�\�̏�����
 */
extern void	initialize_mempfix(void);

/*
 *  �Œ蒷�������v�[������u���b�N���l��
 */
extern void	get_mpf_block(MPFCB *p_mpfcb, void **p_blk);

#endif /* TOPPERS_MEMPFIX_H */
