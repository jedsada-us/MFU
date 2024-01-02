/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
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
 *  @(#) $Id: mutex.c 1694 2010-01-01 15:59:09Z ertl-hiro $
 */

/*
 *		�~���[�e�b�N�X�@�\
 */

#include "kernel_impl.h"
#include "check.h"
#include "task.h"
#include "wait.h"
#include "mutex.h"

/*
 *  �g���[�X���O�}�N���̃f�t�H���g��`
 */
#ifndef LOG_LOC_MTX_ENTER
#define LOG_LOC_MTX_ENTER(mtxid)
#endif /* LOG_LOC_MTX_ENTER */

#ifndef LOG_LOC_MTX_LEAVE
#define LOG_LOC_MTX_LEAVE(ercd)
#endif /* LOG_LOC_MTX_LEAVE */

#ifndef LOG_PLOC_MTX_ENTER
#define LOG_PLOC_MTX_ENTER(mtxid)
#endif /* LOG_PLOC_MTX_ENTER */

#ifndef LOG_PLOC_MTX_LEAVE
#define LOG_PLOC_MTX_LEAVE(ercd)
#endif /* LOG_PLOC_MTX_LEAVE */

#ifndef LOG_TLOC_MTX_ENTER
#define LOG_TLOC_MTX_ENTER(mtxid, tmout)
#endif /* LOG_TLOC_MTX_ENTER */

#ifndef LOG_TLOC_MTX_LEAVE
#define LOG_TLOC_MTX_LEAVE(ercd)
#endif /* LOG_TLOC_MTX_LEAVE */

#ifndef LOG_UNL_MTX_ENTER
#define LOG_UNL_MTX_ENTER(mtxid)
#endif /* LOG_UNL_MTX_ENTER */

#ifndef LOG_UNL_MTX_LEAVE
#define LOG_UNL_MTX_LEAVE(ercd)
#endif /* LOG_UNL_MTX_LEAVE */

#ifndef LOG_INI_MTX_ENTER
#define LOG_INI_MTX_ENTER(mtxid)
#endif /* LOG_INI_MTX_ENTER */

#ifndef LOG_INI_MTX_LEAVE
#define LOG_INI_MTX_LEAVE(ercd)
#endif /* LOG_INI_MTX_LEAVE */

#ifndef LOG_REF_MTX_ENTER
#define LOG_REF_MTX_ENTER(mtxid, pk_rmtx)
#endif /* LOG_REF_MTX_ENTER */

#ifndef LOG_REF_MTX_LEAVE
#define LOG_REF_MTX_LEAVE(ercd, pk_rmtx)
#endif /* LOG_REF_MTX_LEAVE */

/*
 *  �~���[�e�b�N�X�̐�
 */
#define tnum_mtx	((uint_t)(tmax_mtxid - TMIN_MTXID + 1))

/*
 *  �~���[�e�b�N�XID����~���[�e�b�N�X�Ǘ��u���b�N�����o�����߂̃}�N��
 */
#define INDEX_MTX(mtxid)	((uint_t)((mtxid) - TMIN_MTXID))
#define get_mtxcb(mtxid)	(&(mtxcb_table[INDEX_MTX(mtxid)]))

/*
 *  �~���[�e�b�N�X�Ǘ��u���b�N����mutex_queue�ւ̃|�C���^����C�~���[�e�b
 *  �N�X�Ǘ��u���b�N�ւ̃|�C���^�����o�����߂̃}�N��
 */
#define MTXCB_QUEUE(p_queue) \
			((MTXCB *)(((char *) p_queue) - offsetof(MTXCB, mutex_queue)))

/*
 *  �~���[�e�b�N�X�̃v���g�R���𔻒f����}�N��
 */
#define MTXPROTO_MASK			0x03U
#define MTXPROTO(p_mtxcb)		((p_mtxcb)->p_mtxinib->mtxatr & MTXPROTO_MASK)
#define MTX_CEILING(p_mtxcb)	(MTXPROTO(p_mtxcb) == TA_CEILING)

/*
 *  �t�b�N���[�`���ďo���p�̕ϐ�
 */
#ifdef TOPPERS_mtxhook

bool_t	(*mtxhook_check_ceilpri)(TCB *p_tcb, uint_t bpriority) = NULL;
bool_t	(*mtxhook_scan_ceilmtx)(TCB *p_tcb) = NULL;
bool_t	(*mtxhook_release_all)(TCB *p_tcb) = NULL;

#endif /* TOPPERS_mtxhook */

/* 
 *  �~���[�e�b�N�X�@�\�̏�����
 */
#ifdef TOPPERS_mtxini

void
initialize_mutex(void)
{
	uint_t	i;
	MTXCB	*p_mtxcb;

	mtxhook_check_ceilpri = mutex_check_ceilpri;
	mtxhook_scan_ceilmtx = mutex_scan_ceilmtx;
	mtxhook_release_all = mutex_release_all;

	for (p_mtxcb = mtxcb_table, i = 0; i < tnum_mtx; p_mtxcb++, i++) {
		queue_initialize(&(p_mtxcb->wait_queue));
		p_mtxcb->p_mtxinib = &(mtxinib_table[i]);
		p_mtxcb->p_loctsk = NULL;
	}
}

#endif /* TOPPERS_mtxini */

/* 
 *  ����D��x�ᔽ�̃`�F�b�N
 */
#ifdef TOPPERS_mtxchk

bool_t
mutex_check_ceilpri(TCB *p_tcb, uint_t bpriority)
{
	QUEUE	*p_queue;
	MTXCB	*p_mtxcb;

	/*
	 *  �^�X�N�����b�N���Ă���D��x����~���[�e�b�N�X�̒��ŁC����D��
	 *  �x��bpriority�����Ⴂ���̂�����΁Cfalse��Ԃ��D
	 */
	p_queue = p_tcb->mutex_queue.p_next;
	while (p_queue != &(p_tcb->mutex_queue)) {
		p_mtxcb = MTXCB_QUEUE(p_queue);
		if (MTX_CEILING(p_mtxcb) && bpriority < p_mtxcb->p_mtxinib->ceilpri) {
			return(false);
		}
		p_queue = p_queue->p_next;
	}

	/*
	 *  �^�X�N���D��x����~���[�e�b�N�X�̃��b�N��҂��Ă���ꍇ�ɁC��
	 *  �̏���D��x��bpriority�����Ⴍ����΁Cfalse��Ԃ��D
	 */
	if (TSTAT_WAIT_MTX(p_tcb->tstat)) {
		p_mtxcb = ((WINFO_MTX *)(p_tcb->p_winfo))->p_mtxcb;
		if (MTX_CEILING(p_mtxcb) && bpriority < p_mtxcb->p_mtxinib->ceilpri) {
			return(false);
		}
	}

	/*
	 *  ������̏����ɂ����Ă͂܂�Ȃ����true��Ԃ��D
	 */
	return(true);
}

#endif /* TOPPERS_mtxchk */

/* 
 *  �D��x����~���[�e�b�N�X�����b�N���Ă��邩�̃`�F�b�N
 */
#ifdef TOPPERS_mtxscan

bool_t
mutex_scan_ceilmtx(TCB *p_tcb)
{
	QUEUE	*p_queue;
	MTXCB	*p_mtxcb;

	p_queue = p_tcb->mutex_queue.p_next;
	while (p_queue != &(p_tcb->mutex_queue)) {
		p_mtxcb = MTXCB_QUEUE(p_queue);
		if (MTX_CEILING(p_mtxcb)) {
			return(true);
		}
		p_queue = p_queue->p_next;
	}
	return(false);
}

#endif /* TOPPERS_mtxscan */

/* 
 *  �^�X�N�̌��ݗD��x�̌v�Z
 */
#ifdef TOPPERS_mtxcalc

uint_t
mutex_calc_priority(TCB *p_tcb)
{
	uint_t	priority;
	QUEUE	*p_queue;
	MTXCB	*p_mtxcb;

	priority = p_tcb->bpriority;
	p_queue = p_tcb->mutex_queue.p_next;
	while (p_queue != &(p_tcb->mutex_queue)) {
		p_mtxcb = MTXCB_QUEUE(p_queue);
		if (MTX_CEILING(p_mtxcb) && p_mtxcb->p_mtxinib->ceilpri < priority) {
			priority = p_mtxcb->p_mtxinib->ceilpri;
		}
		p_queue = p_queue->p_next;
	}
	return(priority);
}

#endif /* TOPPERS_mtxcalc */

/*
 *  �v�f�D��x���オ��i�܂��͑�����j�ꍇ�̌��ݗD��x�ύX����
 */
Inline bool_t
mutex_raise_priority(TCB *p_tcb, uint_t newpri)
{
	if (newpri < p_tcb->priority) {
		return(change_priority(p_tcb, newpri, true));
	}
	return(false);
}

/*
 *  �v�f�D��x��������i�܂��͌���j�ꍇ�̌��ݗD��x�ύX����
 */
Inline bool_t
mutex_drop_priority(TCB *p_tcb, uint_t oldpri)
{
	uint_t	newpri;

	if (oldpri == p_tcb->priority) {
		newpri = mutex_calc_priority(p_tcb);
		if (newpri != p_tcb->priority) {
			return(change_priority(p_tcb, newpri, true));
		}
	}
	return(false);
}

/*
 *  �~���[�e�b�N�X�����b�N�����ꍇ�̏���
 */
Inline bool_t
mutex_acquire(TCB *p_loctsk, MTXCB *p_mtxcb)
{
	p_mtxcb->p_loctsk = p_loctsk;
	queue_insert_prev(&(p_loctsk->mutex_queue), &(p_mtxcb->mutex_queue));
	if (MTX_CEILING(p_mtxcb)) {
		return(mutex_raise_priority(p_loctsk, p_mtxcb->p_mtxinib->ceilpri));
	}
	return(false);
}

/*
 *  �~���[�e�b�N�X�̃��b�N����
 */
#ifdef TOPPERS_mtxrel

bool_t
mutex_release(MTXCB *p_mtxcb)
{
	TCB		*p_tcb;

	if (queue_empty(&(p_mtxcb->wait_queue))) {
		p_mtxcb->p_loctsk = NULL;
		return(false);
	}
	else {
		/*
		 *  �~���[�e�b�N�X�҂��L���[�̐擪�^�X�N�ip_tcb�j�ɁC�~���[�e�b
		 *  �N�X�����b�N������D
		 */
		p_tcb = (TCB *) queue_delete_next(&(p_mtxcb->wait_queue));
		wait_dequeue_tmevtb(p_tcb);
		p_tcb->p_winfo->wercd = E_OK;

		p_mtxcb->p_loctsk = p_tcb;
		queue_insert_prev(&(p_tcb->mutex_queue), &(p_mtxcb->mutex_queue));
		if (MTX_CEILING(p_mtxcb)) {
			if (p_mtxcb->p_mtxinib->ceilpri < p_tcb->priority) {
				p_tcb->priority = p_mtxcb->p_mtxinib->ceilpri;
			}
		}
		return(make_non_wait(p_tcb));
	}
}

#endif /* TOPPERS_mtxrel */

/*
 *  �^�X�N�����b�N���Ă��邷�ׂẴ~���[�e�b�N�X�̃��b�N����
 */
#ifdef TOPPERS_mtxrela

bool_t
mutex_release_all(TCB *p_tcb)
{
	MTXCB	*p_mtxcb;
	bool_t	dspreq = false;

	while (!queue_empty(&(p_tcb->mutex_queue))) {
		p_mtxcb = MTXCB_QUEUE(p_tcb->mutex_queue.p_next);
		queue_delete(&(p_mtxcb->mutex_queue));
		if (mutex_release(p_mtxcb)) {
			dspreq = true;
		}
	}
	return(dspreq);
}

#endif /* TOPPERS_mtxrela */

/*
 *  �~���[�e�b�N�X�̃��b�N
 */
#ifdef TOPPERS_loc_mtx

ER
loc_mtx(ID mtxid)
{
	MTXCB	*p_mtxcb;
	WINFO_MTX winfo_mtx;
	ER		ercd;

	LOG_LOC_MTX_ENTER(mtxid);
	CHECK_DISPATCH();
	CHECK_MTXID(mtxid);
	p_mtxcb = get_mtxcb(mtxid);

	t_lock_cpu();
	if (MTX_CEILING(p_mtxcb)
				&& p_runtsk->bpriority < p_mtxcb->p_mtxinib->ceilpri) {
		ercd = E_ILUSE;
	}
	else if (p_mtxcb->p_loctsk == NULL) {
		(void) mutex_acquire(p_runtsk, p_mtxcb);
		/*
		 *  �D��x����~���[�e�b�N�X�����b�N�����ꍇ�Cp_runtsk�̗D��x
		 *  ���オ��\�������邪�C�f�B�X�p�b�`���K�v�ɂȂ邱�Ƃ͂Ȃ��D
		 */
		assert(!(p_runtsk != p_schedtsk && dspflg));
		ercd = E_OK;
	}
	else if (p_mtxcb->p_loctsk == p_runtsk) {
		ercd = E_ILUSE;
	}
	else {
		p_runtsk->tstat = (TS_WAITING | TS_WAIT_MTX);
		wobj_make_wait((WOBJCB *) p_mtxcb, (WINFO_WOBJ *) &winfo_mtx);
		dispatch();
		ercd = winfo_mtx.winfo.wercd;
	}
	t_unlock_cpu();

  error_exit:
	LOG_LOC_MTX_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_loc_mtx */

/*
 *  �~���[�e�b�N�X�̃��b�N�i�|�[�����O�j
 */
#ifdef TOPPERS_ploc_mtx

ER
ploc_mtx(ID mtxid)
{
	MTXCB	*p_mtxcb;
	ER		ercd;

	LOG_PLOC_MTX_ENTER(mtxid);
	CHECK_TSKCTX_UNL();
	CHECK_MTXID(mtxid);
	p_mtxcb = get_mtxcb(mtxid);

	t_lock_cpu();
	if (MTX_CEILING(p_mtxcb)
				&& p_runtsk->bpriority < p_mtxcb->p_mtxinib->ceilpri) {
		ercd = E_ILUSE;
	}
	else if (p_mtxcb->p_loctsk == NULL) {
		(void) mutex_acquire(p_runtsk, p_mtxcb);
		/*
		 *  �D��x����~���[�e�b�N�X�����b�N�����ꍇ�Cp_runtsk�̗D��x
		 *  ���オ��\�������邪�C�f�B�X�p�b�`���K�v�ɂȂ邱�Ƃ͂Ȃ��D
		 */
		assert(!(p_runtsk != p_schedtsk && dspflg));
		ercd = E_OK;
	}
	else if (p_mtxcb->p_loctsk == p_runtsk) {
		ercd = E_ILUSE;
	}
	else {
		ercd = E_TMOUT;
	}
	t_unlock_cpu();

  error_exit:
	LOG_PLOC_MTX_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_ploc_mtx */

/*
 *  �~���[�e�b�N�X�̃��b�N�i�^�C���A�E�g����j
 */
#ifdef TOPPERS_tloc_mtx

ER
tloc_mtx(ID mtxid, TMO tmout)
{
	MTXCB	*p_mtxcb;
	WINFO_MTX winfo_mtx;
	TMEVTB	tmevtb;
	ER		ercd;

	LOG_TLOC_MTX_ENTER(mtxid, tmout);
	CHECK_DISPATCH();
	CHECK_MTXID(mtxid);
	CHECK_TMOUT(tmout);
	p_mtxcb = get_mtxcb(mtxid);

	t_lock_cpu();
	if (MTX_CEILING(p_mtxcb)
				&& p_runtsk->bpriority < p_mtxcb->p_mtxinib->ceilpri) {
		ercd = E_ILUSE;
	}
	else if (p_mtxcb->p_loctsk == NULL) {
		(void) mutex_acquire(p_runtsk, p_mtxcb);
		/*
		 *  �D��x����~���[�e�b�N�X�����b�N�����ꍇ�Cp_runtsk�̗D��x
		 *  ���オ��\�������邪�C�f�B�X�p�b�`���K�v�ɂȂ邱�Ƃ͂Ȃ��D
		 */
		assert(!(p_runtsk != p_schedtsk && dspflg));
		ercd = E_OK;
	}
	else if (p_mtxcb->p_loctsk == p_runtsk) {
		ercd = E_ILUSE;
	}
	else if (tmout == TMO_POL) {
		ercd = E_TMOUT;
	}
	else {
		p_runtsk->tstat = (TS_WAITING | TS_WAIT_MTX);
		wobj_make_wait_tmout((WOBJCB *) p_mtxcb, (WINFO_WOBJ *) &winfo_mtx,
														&tmevtb, tmout);
		dispatch();
		ercd = winfo_mtx.winfo.wercd;
	}
	t_unlock_cpu();

  error_exit:
	LOG_TLOC_MTX_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_tloc_mtx */

/*
 *  �~���[�e�b�N�X�̃��b�N����
 */
#ifdef TOPPERS_unl_mtx

ER
unl_mtx(ID mtxid)
{
	MTXCB	*p_mtxcb;
	bool_t	dspreq = false;
	ER		ercd;
    
	LOG_UNL_MTX_ENTER(mtxid);
	CHECK_TSKCTX_UNL();
	CHECK_MTXID(mtxid);
	p_mtxcb = get_mtxcb(mtxid);

	t_lock_cpu();
	if (p_mtxcb->p_loctsk != p_runtsk) {
		ercd = E_ILUSE;
	}
	else {
		queue_delete(&(p_mtxcb->mutex_queue));
		if (MTX_CEILING(p_mtxcb)) {
			if (mutex_drop_priority(p_runtsk, p_mtxcb->p_mtxinib->ceilpri)) {
				dspreq = true;
			}
		}
		if (mutex_release(p_mtxcb)) {
			dspreq = true;
		}
		if (dspreq) {
			dispatch();
		}
		ercd = E_OK;
	}
	t_unlock_cpu();

  error_exit:
	LOG_UNL_MTX_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_unl_mtx */

/*
 *  �~���[�e�b�N�X�̏�����
 */
#ifdef TOPPERS_ini_mtx

ER
ini_mtx(ID mtxid)
{
	MTXCB	*p_mtxcb;
	TCB		*p_loctsk;
	bool_t	dspreq;
	ER		ercd;
    
	LOG_INI_MTX_ENTER(mtxid);
	CHECK_TSKCTX_UNL();
	CHECK_MTXID(mtxid);
	p_mtxcb = get_mtxcb(mtxid);

	t_lock_cpu();
	dspreq = init_wait_queue(&(p_mtxcb->wait_queue));
	p_loctsk = p_mtxcb->p_loctsk;
	if (p_loctsk != NULL) {
		queue_delete(&(p_mtxcb->mutex_queue));
		p_mtxcb->p_loctsk = NULL;
		if (MTX_CEILING(p_mtxcb)) {
			if (mutex_drop_priority(p_loctsk, p_mtxcb->p_mtxinib->ceilpri)) {
				dspreq = true;
			}
		}
	}
	if (dspreq) {
		dispatch();
	}
	ercd = E_OK;
	t_unlock_cpu();

  error_exit:
	LOG_INI_MTX_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_ini_mtx */

/*
 *  �~���[�e�b�N�X�̏�ԎQ��
 */
#ifdef TOPPERS_ref_mtx

ER
ref_mtx(ID mtxid, T_RMTX *pk_rmtx)
{
	MTXCB	*p_mtxcb;
	ER		ercd;
    
	LOG_REF_MTX_ENTER(mtxid, pk_rmtx);
	CHECK_TSKCTX_UNL();
	CHECK_MTXID(mtxid);
	p_mtxcb = get_mtxcb(mtxid);

	t_lock_cpu();
	pk_rmtx->htskid = (p_mtxcb->p_loctsk != NULL) ? TSKID(p_mtxcb->p_loctsk)
													: TSK_NONE;
	pk_rmtx->wtskid = wait_tskid(&(p_mtxcb->wait_queue));
	ercd = E_OK;
	t_unlock_cpu();

  error_exit:
	LOG_REF_MTX_LEAVE(ercd, pk_rmtx);
	return(ercd);
}

#endif /* TOPPERS_ref_mtx */
