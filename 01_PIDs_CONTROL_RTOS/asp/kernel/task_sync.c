/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005-2009 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: task_sync.c 1453 2009-02-18 09:09:34Z ertl-hiro $
 */

/*
 *		�^�X�N�t�������@�\
 */

#include "kernel_impl.h"
#include "check.h"
#include "task.h"
#include "wait.h"

/*
 *  �g���[�X���O�}�N���̃f�t�H���g��`
 */
#ifndef LOG_SLP_TSK_ENTER
#define LOG_SLP_TSK_ENTER()
#endif /* LOG_SLP_TSK_ENTER */

#ifndef LOG_SLP_TSK_LEAVE
#define LOG_SLP_TSK_LEAVE(ercd)
#endif /* LOG_SLP_TSK_LEAVE */

#ifndef LOG_TSLP_TSK_ENTER
#define LOG_TSLP_TSK_ENTER(tmout)
#endif /* LOG_TSLP_TSK_ENTER */

#ifndef LOG_TSLP_TSK_LEAVE
#define LOG_TSLP_TSK_LEAVE(ercd)
#endif /* LOG_TSLP_TSK_LEAVE */

#ifndef LOG_WUP_TSK_ENTER
#define LOG_WUP_TSK_ENTER(tskid)
#endif /* LOG_WUP_TSK_ENTER */

#ifndef LOG_WUP_TSK_LEAVE
#define LOG_WUP_TSK_LEAVE(ercd)
#endif /* LOG_WUP_TSK_LEAVE */

#ifndef LOG_IWUP_TSK_ENTER
#define LOG_IWUP_TSK_ENTER(tskid)
#endif /* LOG_IWUP_TSK_ENTER */

#ifndef LOG_IWUP_TSK_LEAVE
#define LOG_IWUP_TSK_LEAVE(ercd)
#endif /* LOG_IWUP_TSK_LEAVE */

#ifndef LOG_CAN_WUP_ENTER
#define LOG_CAN_WUP_ENTER(tskid)
#endif /* LOG_CAN_WUP_ENTER */

#ifndef LOG_CAN_WUP_LEAVE
#define LOG_CAN_WUP_LEAVE(ercd)
#endif /* LOG_CAN_WUP_LEAVE */

#ifndef LOG_REL_WAI_ENTER
#define LOG_REL_WAI_ENTER(tskid)
#endif /* LOG_REL_WAI_ENTER */

#ifndef LOG_REL_WAI_LEAVE
#define LOG_REL_WAI_LEAVE(ercd)
#endif /* LOG_REL_WAI_LEAVE */

#ifndef LOG_IREL_WAI_ENTER
#define LOG_IREL_WAI_ENTER(tskid)
#endif /* LOG_IREL_WAI_ENTER */

#ifndef LOG_IREL_WAI_LEAVE
#define LOG_IREL_WAI_LEAVE(ercd)
#endif /* LOG_IREL_WAI_LEAVE */

#ifndef LOG_SUS_TSK_ENTER
#define LOG_SUS_TSK_ENTER(tskid)
#endif /* LOG_SUS_TSK_ENTER */

#ifndef LOG_SUS_TSK_LEAVE
#define LOG_SUS_TSK_LEAVE(ercd)
#endif /* LOG_SUS_TSK_LEAVE */

#ifndef LOG_RSM_TSK_ENTER
#define LOG_RSM_TSK_ENTER(tskid)
#endif /* LOG_RSM_TSK_ENTER */

#ifndef LOG_RSM_TSK_LEAVE
#define LOG_RSM_TSK_LEAVE(ercd)
#endif /* LOG_RSM_TSK_LEAVE */

#ifndef LOG_DLY_TSK_ENTER
#define LOG_DLY_TSK_ENTER(dlytim)
#endif /* LOG_DLY_TSK_ENTER */

#ifndef LOG_DLY_TSK_LEAVE
#define LOG_DLY_TSK_LEAVE(ercd)
#endif /* LOG_DLY_TSK_LEAVE */

/*
 *  �N���҂�
 */
#ifdef TOPPERS_slp_tsk

ER
slp_tsk(void)
{
	WINFO	winfo;
	ER		ercd;

	LOG_SLP_TSK_ENTER();
	CHECK_DISPATCH();

	t_lock_cpu();
	if (p_runtsk->wupque) {
		p_runtsk->wupque = false;
		ercd = E_OK;
	}
	else {
		p_runtsk->tstat = (TS_WAITING | TS_WAIT_SLP);
		make_wait(&winfo);
		LOG_TSKSTAT(p_runtsk);
		dispatch();
		ercd = winfo.wercd;
	}
	t_unlock_cpu();

  error_exit:
	LOG_SLP_TSK_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_slp_tsk */

/*
 *  �N���҂��i�^�C���A�E�g����j
 */
#ifdef TOPPERS_tslp_tsk

ER
tslp_tsk(TMO tmout)
{
	WINFO	winfo;
	TMEVTB	tmevtb;
	ER		ercd;

	LOG_TSLP_TSK_ENTER(tmout);
	CHECK_DISPATCH();
	CHECK_TMOUT(tmout);

	t_lock_cpu();
	if (p_runtsk->wupque) {
		p_runtsk->wupque = false;
		ercd = E_OK;
	}
	else if (tmout == TMO_POL) {
		ercd = E_TMOUT;
	}
	else {
		p_runtsk->tstat = (TS_WAITING | TS_WAIT_SLP);
		make_wait_tmout(&winfo, &tmevtb, tmout);
		LOG_TSKSTAT(p_runtsk);
		dispatch();
		ercd = winfo.wercd;
	}
	t_unlock_cpu();

  error_exit:
	LOG_TSLP_TSK_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_tslp_tsk */

/*
 *  �^�X�N�̋N��
 */
#ifdef TOPPERS_wup_tsk

ER
wup_tsk(ID tskid)
{
	TCB		*p_tcb;
	ER		ercd;

	LOG_WUP_TSK_ENTER(tskid);
	CHECK_TSKCTX_UNL();
	CHECK_TSKID_SELF(tskid);
	p_tcb = get_tcb_self(tskid);

	t_lock_cpu();
	if (TSTAT_DORMANT(p_tcb->tstat)) {
		ercd = E_OBJ;
	}
	else if (TSTAT_WAIT_SLP(p_tcb->tstat)) {
		if (wait_complete(p_tcb)) {
			dispatch();
		}
		ercd = E_OK;
	}
	else if (!(p_tcb->wupque)) {
		p_tcb->wupque = true;
		ercd = E_OK;
	}
	else {
		ercd = E_QOVR;
	}
	t_unlock_cpu();

  error_exit:
	LOG_WUP_TSK_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_wup_tsk */

/*
 *  �^�X�N�̋N���i��^�X�N�R���e�L�X�g�p�j
 */
#ifdef TOPPERS_iwup_tsk

ER
iwup_tsk(ID tskid)
{
	TCB		*p_tcb;
	ER		ercd;

	LOG_IWUP_TSK_ENTER(tskid);
	CHECK_INTCTX_UNL();
	CHECK_TSKID(tskid);
	p_tcb = get_tcb(tskid);

	i_lock_cpu();
	if (TSTAT_DORMANT(p_tcb->tstat)) {
		ercd = E_OBJ;
	}
	else if (TSTAT_WAIT_SLP(p_tcb->tstat)) {
		if (wait_complete(p_tcb)) {
			reqflg = true;
		}
		ercd = E_OK;
	}
	else if (!(p_tcb->wupque)) {
		p_tcb->wupque = true;
		ercd = E_OK;
	}
	else {
		ercd = E_QOVR;
	}
	i_unlock_cpu();

  error_exit:
	LOG_IWUP_TSK_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_iwup_tsk */

/*
 *  �^�X�N�N���v���̃L�����Z��
 */
#ifdef TOPPERS_can_wup

ER_UINT
can_wup(ID tskid)
{
	TCB		*p_tcb;
	ER_UINT	ercd;

	LOG_CAN_WUP_ENTER(tskid);
	CHECK_TSKCTX_UNL();
	CHECK_TSKID_SELF(tskid);
	p_tcb = get_tcb_self(tskid);

	t_lock_cpu();
	if (TSTAT_DORMANT(p_tcb->tstat)) {
		ercd = E_OBJ;
	}
	else {
		ercd = p_tcb->wupque ? 1 : 0;
		p_tcb->wupque = false;
	}
	t_unlock_cpu();

  error_exit:
	LOG_CAN_WUP_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_can_wup */

/*
 *  �҂���Ԃ̋�������
 */
#ifdef TOPPERS_rel_wai

ER
rel_wai(ID tskid)
{
	TCB		*p_tcb;
	ER		ercd;

	LOG_REL_WAI_ENTER(tskid);
	CHECK_TSKCTX_UNL();
	CHECK_TSKID(tskid);
	p_tcb = get_tcb(tskid);

	t_lock_cpu();
	if (!TSTAT_WAITING(p_tcb->tstat)) {
		ercd = E_OBJ;
	}
	else {
		if (wait_release(p_tcb)) {
			dispatch();
		}
		ercd = E_OK;
	}
	t_unlock_cpu();

  error_exit:
	LOG_REL_WAI_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_rel_wai */

/*
 *  �҂���Ԃ̋��������i��^�X�N�R���e�L�X�g�p�j
 */
#ifdef TOPPERS_irel_wai

ER
irel_wai(ID tskid)
{
	TCB		*p_tcb;
	ER		ercd;

	LOG_IREL_WAI_ENTER(tskid);
	CHECK_INTCTX_UNL();
	CHECK_TSKID(tskid);
	p_tcb = get_tcb(tskid);

	i_lock_cpu();
	if (!TSTAT_WAITING(p_tcb->tstat)) {
		ercd = E_OBJ;
	}
	else {
		if (wait_release(p_tcb)) {
			reqflg = true;
		}
		ercd = E_OK;
	}
	i_unlock_cpu();

  error_exit:
	LOG_IREL_WAI_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_irel_wai */

/*
 *  �����҂���Ԃւ̈ڍs
 */
#ifdef TOPPERS_sus_tsk

ER
sus_tsk(ID tskid)
{
	TCB		*p_tcb;
	ER		ercd;

	LOG_SUS_TSK_ENTER(tskid);
	CHECK_TSKCTX_UNL();
	CHECK_TSKID_SELF(tskid);
	p_tcb = get_tcb_self(tskid);

	t_lock_cpu();
	if (p_tcb == p_runtsk && !dspflg) {
		ercd = E_CTX;
	}
	else if (TSTAT_DORMANT(p_tcb->tstat)) {
		ercd = E_OBJ;
	}
	else if (TSTAT_RUNNABLE(p_tcb->tstat)) {
		/*
		 *  ���s�ł����Ԃ��狭���҂���Ԃւ̑J��
		 */
		p_tcb->tstat = TS_SUSPENDED;
		LOG_TSKSTAT(p_tcb);
		if (make_non_runnable(p_tcb)) {
			dispatch();
		}
		ercd = E_OK;
	}
	else if (TSTAT_SUSPENDED(p_tcb->tstat)) {
		ercd = E_QOVR;
	}
	else {
		/*
		 *  �҂���Ԃ����d�҂���Ԃւ̑J��
		 */
		p_tcb->tstat |= TS_SUSPENDED;
		LOG_TSKSTAT(p_tcb);
		ercd = E_OK;
	}
	t_unlock_cpu();

  error_exit:
	LOG_SUS_TSK_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_sus_tsk */

/*
 *  �����҂���Ԃ���̍ĊJ
 */
#ifdef TOPPERS_rsm_tsk

ER
rsm_tsk(ID tskid)
{
	TCB		*p_tcb;
	ER		ercd;

	LOG_RSM_TSK_ENTER(tskid);
	CHECK_TSKCTX_UNL();
	CHECK_TSKID(tskid);
	p_tcb = get_tcb(tskid);

	t_lock_cpu();
	if (!TSTAT_SUSPENDED(p_tcb->tstat)) {
		ercd = E_OBJ;
	}
	else if (!TSTAT_WAITING(p_tcb->tstat)) {
		/*
		 *  �����҂���Ԃ�����s�ł����Ԃւ̑J��
		 */
		p_tcb->tstat = TS_RUNNABLE;
		LOG_TSKSTAT(p_tcb);
		if (make_runnable(p_tcb)) {
			dispatch();
		}
		ercd = E_OK;
	}
	else {
		/*
		 *  ��d�҂���Ԃ���҂���Ԃւ̑J��
		 */
		p_tcb->tstat &= ~TS_SUSPENDED;
		LOG_TSKSTAT(p_tcb);
		ercd = E_OK;
	}
	t_unlock_cpu();

  error_exit:
	LOG_RSM_TSK_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_rsm_tsk */

/*
 *  ���^�X�N�̒x��
 */
#ifdef TOPPERS_dly_tsk

ER
dly_tsk(RELTIM dlytim)
{
	WINFO	winfo;
	TMEVTB	tmevtb;
	ER		ercd;

	LOG_DLY_TSK_ENTER(dlytim);
	CHECK_DISPATCH();
	CHECK_PAR(dlytim <= TMAX_RELTIM);

	t_lock_cpu();
	p_runtsk->tstat = (TS_WAITING | TS_WAIT_DLY);
	(void) make_non_runnable(p_runtsk);
	p_runtsk->p_winfo = &winfo;
	winfo.p_tmevtb = &tmevtb;
	tmevtb_enqueue(&tmevtb, dlytim, (CBACK) wait_tmout_ok, (void *) p_runtsk);
	LOG_TSKSTAT(p_runtsk);
	dispatch();
	ercd = winfo.wercd;
	t_unlock_cpu();

  error_exit:
	LOG_DLY_TSK_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_dly_tsk */
