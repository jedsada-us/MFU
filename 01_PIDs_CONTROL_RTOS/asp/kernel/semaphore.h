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
 *  @(#) $Id: semaphore.h 264 2007-07-12 08:23:10Z hiro $
 */

/*
 *		�Z�}�t�H�@�\
 */

#ifndef TOPPERS_SEMAPHORE_H
#define TOPPERS_SEMAPHORE_H

#include <queue.h>

/*
 *  �Z�}�t�H�������u���b�N
 *
 *  ���̍\���̂́C�����E�ʐM�I�u�W�F�N�g�̏������u���b�N�̋��ʕ���
 *  �iWOBJINIB�j���g���i�I�u�W�F�N�g�w������̌p���ɑ����j�������̂ŁC
 *  �ŏ��̃t�B�[���h�����ʂɂȂ��Ă���D
 */
typedef struct semaphore_initialization_block {
	ATR			sematr;			/* �Z�}�t�H���� */
	uint_t		isemcnt;		/* �Z�}�t�H�̎������̏����l */
	uint_t		maxsem;			/* �Z�}�t�H�̍ő厑���� */
} SEMINIB;

/*
 *  �Z�}�t�H�Ǘ��u���b�N
 *
 *  ���̍\���̂́C�����E�ʐM�I�u�W�F�N�g�̊Ǘ��u���b�N�̋��ʕ����iWOBJCB�j
 *  ���g���i�I�u�W�F�N�g�w������̌p���ɑ����j�������̂ŁC�ŏ���2��
 *  �t�B�[���h�����ʂɂȂ��Ă���D
 */
typedef struct semaphore_control_block {
	QUEUE		wait_queue;		/* �Z�}�t�H�҂��L���[ */
	const SEMINIB *p_seminib;	/* �������u���b�N�ւ̃|�C���^ */
	uint_t		semcnt;			/* �Z�}�t�H���݃J�E���g�l */
} SEMCB;

/*
 *  �Z�}�t�H�҂����u���b�N�̒�`
 *
 *  ���̍\���̂́C�����E�ʐM�I�u�W�F�N�g�̑҂����u���b�N�̋��ʕ���
 *  �iWINFO_WOBJ�j���g���i�I�u�W�F�N�g�w������̌p���ɑ����j�������̂ŁC
 *  ���ׂẴt�B�[���h�����ʂɂȂ��Ă���D
 */
typedef struct semaphore_waiting_information {
	WINFO	winfo;			/* �W���̑҂����u���b�N */
	SEMCB	*p_semcb;		/* �҂��Ă���Z�}�t�H�̊Ǘ��u���b�N */
} WINFO_SEM;

/*
 *  �Z�}�t�HID�̍ő�l�ikernel_cfg.c�j
 */
extern const ID	tmax_semid;

/*
 *  �Z�}�t�H�������u���b�N�̃G���A�ikernel_cfg.c�j
 */
extern const SEMINIB	seminib_table[];

/*
 *  �Z�}�t�H�Ǘ��u���b�N�̃G���A�ikernel_cfg.c�j
 */
extern SEMCB	semcb_table[];

/*
 *  �Z�}�t�H�Ǘ��u���b�N����Z�}�t�HID�����o�����߂̃}�N��
 */
#define	SEMID(p_semcb)	((ID)(((p_semcb) - semcb_table) + TMIN_SEMID))

/*
 *  �Z�}�t�H�@�\�̏�����
 */
extern void	initialize_semaphore(void);

#endif /* TOPPERS_SEMAPHORE_H */
