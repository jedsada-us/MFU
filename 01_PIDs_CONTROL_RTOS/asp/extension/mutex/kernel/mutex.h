/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2005-2010 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: mutex.h 1910 2010-08-25 06:30:21Z ertl-hiro $
 */

/*
 *		�~���[�e�b�N�X�@�\
 */

#ifndef TOPPERS_MUTEX_H
#define TOPPERS_MUTEX_H

#include <queue.h>

/*
 *  �~���[�e�b�N�X�������u���b�N
 *
 *  ���̍\���̂́C�����E�ʐM�I�u�W�F�N�g�̏������u���b�N�̋��ʕ���
 *  �iWOBJINIB�j���g���i�I�u�W�F�N�g�w������̌p���ɑ����j�������̂ŁC
 *  �ŏ��̃t�B�[���h�����ʂɂȂ��Ă���D
 */
typedef struct mutex_initialization_block {
	ATR			mtxatr;			/* �~���[�e�b�N�X���� */
	uint_t		ceilpri;		/* �~���[�e�b�N�X�̏���D��x�i�����\���j*/
} MTXINIB;

/*
 *  �~���[�e�b�N�X�Ǘ��u���b�N
 *
 *  ���̍\���̂́C�����E�ʐM�I�u�W�F�N�g�̊Ǘ��u���b�N�̋��ʕ����iWOBJCB�j
 *  ���g���i�I�u�W�F�N�g�w������̌p���ɑ����j�������̂ŁC�ŏ���2��
 *  �t�B�[���h�����ʂɂȂ��Ă���D
 */
typedef struct mutex_control_block {
	QUEUE		wait_queue;		/* �~���[�e�b�N�X�҂��L���[ */
	const MTXINIB *p_mtxinib;	/* �������u���b�N�ւ̃|�C���^ */
	TCB			*p_loctsk;		/* �~���[�e�b�N�X�����b�N���Ă���^�X�N */
	QUEUE		mutex_queue;	/* ���b�N���Ă���~���[�e�b�N�X�̃L���[ */
} MTXCB;

/*
 *  �~���[�e�b�N�X�҂����u���b�N�̒�`
 *
 *  ���̍\���̂́C�����E�ʐM�I�u�W�F�N�g�̑҂����u���b�N�̋��ʕ���
 *  �iWINFO_WOBJ�j���g���i�I�u�W�F�N�g�w������̌p���ɑ����j�������̂ŁC
 *  ���ׂẴt�B�[���h�����ʂɂȂ��Ă���D
 */
typedef struct mutex_waiting_information {
	WINFO	winfo;			/* �W���̑҂����u���b�N */
	MTXCB	*p_mtxcb;		/* �҂��Ă���~���[�e�b�N�X�̊Ǘ��u���b�N */
} WINFO_MTX;

/*
 *  �~���[�e�b�N�XID�̍ő�l�ikernel_cfg.c�j
 */
extern const ID	tmax_mtxid;

/*
 *  �~���[�e�b�N�X�������u���b�N�̃G���A�ikernel_cfg.c�j
 */
extern const MTXINIB	mtxinib_table[];

/*
 *  �~���[�e�b�N�X�Ǘ��u���b�N�̃G���A�ikernel_cfg.c�j
 */
extern MTXCB	mtxcb_table[];

/*
 *  �~���[�e�b�N�X�Ǘ��u���b�N����~���[�e�b�N�XID�����o�����߂̃}�N��
 */
#define	MTXID(p_mtxcb)	((ID)(((p_mtxcb) - mtxcb_table) + TMIN_MTXID))

/*
 *  �~���[�e�b�N�X�@�\�̏�����
 */
extern void	initialize_mutex(void);

/*
 *  ����D��x�ᔽ�̃`�F�b�N
 *
 *  chg_pri�̒��ŏ���D��x�ᔽ�̃`�F�b�N���s�����߂ɗp����֐��ł���C
 *  p_tcb�Ŏw�肳���^�X�N�����b�N���Ă���D��x����~���[�e�b�N�X�ƁC
 *  ���b�N��҂��Ă���D��x����~���[�e�b�N�X�̒��ŁC����D��x��
 *  bpriority�����Ⴂ���̂������false���C�����łȂ����true��Ԃ��D
 */
extern bool_t	(*mtxhook_check_ceilpri)(TCB *p_tcb, uint_t bpriority);
extern bool_t	mutex_check_ceilpri(TCB *p_tcb, uint_t bpriority);

/* 
 *  �D��x����~���[�e�b�N�X�����b�N���Ă��邩�̃`�F�b�N
 *
 *  p_tcb�Ŏw�肳���^�X�N���D��x����~���[�e�b�N�X�����b�N���Ă����
 *  true�C�����łȂ����false��Ԃ��D
 */
extern bool_t	(*mtxhook_scan_ceilmtx)(TCB *p_tcb);
extern bool_t	mutex_scan_ceilmtx(TCB *p_tcb);

/* 
 *  �^�X�N�̌��ݗD��x�̌v�Z
 *
 *  p_tcb�Ŏw�肳���^�X�N�̌��ݗD��x�i�ɐݒ肷�ׂ��l�j���v�Z����D
 */
extern uint_t	mutex_calc_priority(TCB *p_tcb);

/*
 *  �~���[�e�b�N�X�̃��b�N����
 *
 *  p_mtxcb�Ŏw�肳���~���[�e�b�N�X�����b�N��������D���b�N��������
 *  �~���[�e�b�N�X�ɁC���b�N�҂���Ԃ̃^�X�N������ꍇ�ɂ́C���̃^�X�N
 *  �Ƀ~���[�e�b�N�X�����b�N������D
 */
extern bool_t	mutex_release(MTXCB *p_mtxcb);

/*
 *  �^�X�N�����b�N���Ă��邷�ׂẴ~���[�e�b�N�X�̃��b�N����
 *
 *  p_tcb�Ŏw�肳���^�X�N�ɁC���ꂪ���b�N���Ă��邷�ׂẴ~���[�e�b�N
 *  �X�����b�N����������D���b�N���������~���[�e�b�N�X�ɁC���b�N�҂���
 *  �Ԃ̃^�X�N������ꍇ�ɂ́C���̃^�X�N�Ƀ~���[�e�b�N�X�����b�N������D
 *
 *  ���̊֐��́C�^�X�N�̏I�����Ɏg������̂ł��邽�߁Cp_tcb�Ŏw�肳��
 *  ��^�X�N�̗D��x��ύX���鏈���͍s��Ȃ��D�������C���̊֐��̒��ő�
 *  �̃^�X�N�̗D��x���ω����C���s���ׂ��^�X�N���ς�邱�Ƃ�����D����
 *  ���߁C���̊֐�����߂�����ɁC�f�B�X�p�b�`���K�v�����ʂ��āC�K�v��
 *  �ꍇ�ɂ̓f�B�X�p�b�`���s��Ȃ���΂Ȃ�Ȃ��D
 */
extern bool_t	(*mtxhook_release_all)(TCB *p_tcb);
extern bool_t	mutex_release_all(TCB *p_tcb);

#endif /* TOPPERS_MUTEX_H */
