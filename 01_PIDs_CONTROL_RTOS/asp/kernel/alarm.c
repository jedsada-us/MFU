/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005-2007 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: alarm.c 748 2008-03-07 17:18:06Z hiro $
 */

/*
 *		�A���[���n���h���@�\
 */

#include "kernel_impl.h"
#include "check.h"
#include "alarm.h"

/*
 *  �g���[�X���O�}�N���̃f�t�H���g��`
 */
#ifndef LOG_ALM_ENTER
#define LOG_ALM_ENTER(p_almcb)
#endif /* LOG_ALM_ENTER */

#ifndef LOG_ALM_LEAVE
#define LOG_ALM_LEAVE(p_almcb)
#endif /* LOG_ALM_LEAVE */

#ifndef LOG_STA_ALM_ENTER
#define LOG_STA_ALM_ENTER(almid, almtim)
#endif /* LOG_STA_ALM_ENTER */

#ifndef LOG_STA_ALM_LEAVE
#define LOG_STA_ALM_LEAVE(ercd)
#endif /* LOG_STA_ALM_LEAVE */

#ifndef LOG_ISTA_ALM_ENTER
#define LOG_ISTA_ALM_ENTER(almid, almtim)
#endif /* LOG_ISTA_ALM_ENTER */

#ifndef LOG_ISTA_ALM_LEAVE
#define LOG_ISTA_ALM_LEAVE(ercd)
#endif /* LOG_ISTA_ALM_LEAVE */

#ifndef LOG_STP_ALM_ENTER
#define LOG_STP_ALM_ENTER(almid)
#endif /* LOG_STP_ALM_ENTER */

#ifndef LOG_STP_ALM_LEAVE
#define LOG_STP_ALM_LEAVE(ercd)
#endif /* LOG_STP_ALM_LEAVE */

#ifndef LOG_ISTP_ALM_ENTER
#define LOG_ISTP_ALM_ENTER(almid)
#endif /* LOG_ISTP_ALM_ENTER */

#ifndef LOG_ISTP_ALM_LEAVE
#define LOG_ISTP_ALM_LEAVE(ercd)
#endif /* LOG_ISTP_ALM_LEAVE */

#ifndef LOG_REF_ALM_ENTER
#define LOG_REF_ALM_ENTER(almid, pk_ralm)
#endif /* LOG_REF_ALM_ENTER */

#ifndef LOG_REF_ALM_LEAVE
#define LOG_REF_ALM_LEAVE(ercd, pk_ralm)
#endif /* LOG_REF_ALM_LEAVE */

/*
 *  �A���[���n���h���̐�
 */
#define tnum_alm	((uint_t)(tmax_almid - TMIN_ALMID + 1))

/*
 *  �A���[���n���h��ID����A���[���n���h���Ǘ��u���b�N�����o�����߂̃}�N��
 */
#define INDEX_ALM(almid)	((uint_t)((almid) - TMIN_ALMID))
#define get_almcb(almid)	(&(almcb_table[INDEX_ALM(almid)]))

/*
 *  �A���[���n���h���@�\�̏�����
 */
#ifdef TOPPERS_almini

void
initialize_alarm(void)
{
	uint_t	i;
	ALMCB	*p_almcb;

	for (p_almcb = almcb_table, i = 0; i < tnum_alm; p_almcb++, i++) {
		p_almcb->p_alminib = &(alminib_table[i]);
		p_almcb->almsta = false;
	}
}

#endif /* TOPPERS_almini */

/*
 *  �A���[���n���h���̓���J�n
 */
#ifdef TOPPERS_sta_alm

ER
sta_alm(ID almid, RELTIM almtim)
{
	ALMCB	*p_almcb;
	ER		ercd;

	LOG_STA_ALM_ENTER(almid, almtim);
	CHECK_TSKCTX_UNL();
	CHECK_ALMID(almid);
	CHECK_PAR(almtim <= TMAX_RELTIM);
	p_almcb = get_almcb(almid);

	t_lock_cpu();
	if (p_almcb->almsta) {
		tmevtb_dequeue(&(p_almcb->tmevtb));
	}
	else {
		p_almcb->almsta = true;
	}
	tmevtb_enqueue(&(p_almcb->tmevtb), almtim,
								(CBACK) call_almhdr, (void *) p_almcb);
	ercd = E_OK;
	t_unlock_cpu();

  error_exit:
	LOG_STA_ALM_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_sta_alm */

/*
 *  �A���[���n���h���̓���J�n�i��^�X�N�R���e�L�X�g�p�j
 */
#ifdef TOPPERS_ista_alm

ER
ista_alm(ID almid, RELTIM almtim)
{
	ALMCB	*p_almcb;
	ER		ercd;

	LOG_ISTA_ALM_ENTER(almid, almtim);
	CHECK_INTCTX_UNL();
	CHECK_ALMID(almid);
	CHECK_PAR(almtim <= TMAX_RELTIM);
	p_almcb = get_almcb(almid);

	i_lock_cpu();
	if (p_almcb->almsta) {
		tmevtb_dequeue(&(p_almcb->tmevtb));
	}
	else {
		p_almcb->almsta = true;
	}
	tmevtb_enqueue(&(p_almcb->tmevtb), almtim,
								(CBACK) call_almhdr, (void *) p_almcb);
	ercd = E_OK;
	i_unlock_cpu();

  error_exit:
	LOG_ISTA_ALM_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_ista_alm */

/*
 *  �A���[���n���h���̓����~
 */
#ifdef TOPPERS_stp_alm

ER
stp_alm(ID almid)
{
	ALMCB	*p_almcb;
	ER		ercd;

	LOG_STP_ALM_ENTER(almid);
	CHECK_TSKCTX_UNL();
	CHECK_ALMID(almid);
	p_almcb = get_almcb(almid);

	t_lock_cpu();
	if (p_almcb->almsta) {
		p_almcb->almsta = false;
		tmevtb_dequeue(&(p_almcb->tmevtb));
	}
	ercd = E_OK;
	t_unlock_cpu();

  error_exit:
	LOG_STP_ALM_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_stp_alm */

/*
 *  �A���[���n���h���̓����~�i��^�X�N�R���e�L�X�g�p�j
 */
#ifdef TOPPERS_istp_alm

ER
istp_alm(ID almid)
{
	ALMCB	*p_almcb;
	ER		ercd;

	LOG_ISTP_ALM_ENTER(almid);
	CHECK_INTCTX_UNL();
	CHECK_ALMID(almid);
	p_almcb = get_almcb(almid);

	i_lock_cpu();
	if (p_almcb->almsta) {
		p_almcb->almsta = false;
		tmevtb_dequeue(&(p_almcb->tmevtb));
	}
	ercd = E_OK;
	i_unlock_cpu();

  error_exit:
	LOG_ISTP_ALM_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_istp_alm */

/*
 *  �A���[���n���h���̏�ԎQ��
 */
#ifdef TOPPERS_ref_alm

ER
ref_alm(ID almid, T_RALM *pk_ralm)
{
	ALMCB	*p_almcb;
	ER		ercd;
    
	LOG_REF_ALM_ENTER(almid, pk_ralm);
	CHECK_TSKCTX_UNL();
	CHECK_ALMID(almid);
	p_almcb = get_almcb(almid);

	t_lock_cpu();
	if (p_almcb->almsta) {
		pk_ralm->almstat = TALM_STA;
		pk_ralm->lefttim = tmevt_lefttim(&(p_almcb->tmevtb));
	}
	else {
		pk_ralm->almstat = TALM_STP;
	}
	ercd = E_OK;
	t_unlock_cpu();

  error_exit:
	LOG_REF_ALM_LEAVE(ercd, pk_ralm);
	return(ercd);
}

#endif /* TOPPERS_ref_alm */

/*
 *  �A���[���n���h���N�����[�`��
 */
#ifdef TOPPERS_almcal

void
call_almhdr(ALMCB *p_almcb)
{
	PRI		saved_ipm;

	/*
	 *  �A���[���n���h�����~��Ԃɂ���D
	 */
	p_almcb->almsta = false;

	/*
	 *  �A���[���n���h�����CCPU���b�N������ԂŌĂяo���D
	 */
	saved_ipm = i_get_ipm();
	i_unlock_cpu();

	LOG_ALM_ENTER(p_almcb);
	(*((ALMHDR)(p_almcb->p_alminib->almhdr)))(p_almcb->p_alminib->exinf);
	LOG_ALM_LEAVE(p_almcb);

	if (!i_sense_lock()) {
		i_lock_cpu();
	}
	i_set_ipm(saved_ipm);
}

#endif /* TOPPERS_almcal */
