/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
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
 *  @(#) $Id: pridataq.c 1774 2010-03-19 12:45:46Z ertl-hiro $
 */

/*
 *		�D��x�f�[�^�L���[�@�\
 */

#include "kernel_impl.h"
#include "check.h"
#include "task.h"
#include "wait.h"
#include "pridataq.h"

/*
 *  �g���[�X���O�}�N���̃f�t�H���g��`
 */
#ifndef LOG_SND_PDQ_ENTER
#define LOG_SND_PDQ_ENTER(pdqid, data, datapri)
#endif /* LOG_SND_PDQ_ENTER */

#ifndef LOG_SND_PDQ_LEAVE
#define LOG_SND_PDQ_LEAVE(ercd)
#endif /* LOG_SND_PDQ_LEAVE */

#ifndef LOG_PSND_PDQ_ENTER
#define LOG_PSND_PDQ_ENTER(pdqid, data, datapri)
#endif /* LOG_PSND_PDQ_ENTER */

#ifndef LOG_PSND_PDQ_LEAVE
#define LOG_PSND_PDQ_LEAVE(ercd)
#endif /* LOG_PSND_PDQ_LEAVE */

#ifndef LOG_IPSND_PDQ_ENTER
#define LOG_IPSND_PDQ_ENTER(pdqid, data, datapri)
#endif /* LOG_IPSND_PDQ_ENTER */

#ifndef LOG_IPSND_PDQ_LEAVE
#define LOG_IPSND_PDQ_LEAVE(ercd)
#endif /* LOG_IPSND_PDQ_LEAVE */

#ifndef LOG_TSND_PDQ_ENTER
#define LOG_TSND_PDQ_ENTER(pdqid, data, datapri, tmout)
#endif /* LOG_TSND_PDQ_ENTER */

#ifndef LOG_TSND_PDQ_LEAVE
#define LOG_TSND_PDQ_LEAVE(ercd)
#endif /* LOG_TSND_PDQ_LEAVE */

#ifndef LOG_RCV_PDQ_ENTER
#define LOG_RCV_PDQ_ENTER(pdqid, p_data, p_datapri)
#endif /* LOG_RCV_PDQ_ENTER */

#ifndef LOG_RCV_PDQ_LEAVE
#define LOG_RCV_PDQ_LEAVE(ercd, data, datapri)
#endif /* LOG_RCV_PDQ_LEAVE */

#ifndef LOG_PRCV_PDQ_ENTER
#define LOG_PRCV_PDQ_ENTER(pdqid, p_data, p_datapri)
#endif /* LOG_PRCV_PDQ_ENTER */

#ifndef LOG_PRCV_PDQ_LEAVE
#define LOG_PRCV_PDQ_LEAVE(ercd, data, datapri)
#endif /* LOG_PRCV_PDQ_LEAVE */

#ifndef LOG_TRCV_PDQ_ENTER
#define LOG_TRCV_PDQ_ENTER(pdqid, p_data, p_datapri, tmout)
#endif /* LOG_TRCV_PDQ_ENTER */

#ifndef LOG_TRCV_PDQ_LEAVE
#define LOG_TRCV_PDQ_LEAVE(ercd, data, datapri)
#endif /* LOG_TRCV_PDQ_LEAVE */

#ifndef LOG_INI_PDQ_ENTER
#define LOG_INI_PDQ_ENTER(pdqid)
#endif /* LOG_INI_PDQ_ENTER */

#ifndef LOG_INI_PDQ_LEAVE
#define LOG_INI_PDQ_LEAVE(ercd)
#endif /* LOG_INI_PDQ_LEAVE */

#ifndef LOG_REF_PDQ_ENTER
#define LOG_REF_PDQ_ENTER(pdqid, pk_rpdq)
#endif /* LOG_REF_PDQ_ENTER */

#ifndef LOG_REF_PDQ_LEAVE
#define LOG_REF_PDQ_LEAVE(ercd, pk_rpdq)
#endif /* LOG_REF_PDQ_LEAVE */

/*
 *  �D��x�f�[�^�L���[�̐�
 */
#define tnum_pdq	((uint_t)(tmax_pdqid - TMIN_PDQID + 1))

/*
 *  �D��x�f�[�^�L���[ID����D��x�f�[�^�L���[�Ǘ��u���b�N�����o����
 *  �߂̃}�N��
 */
#define INDEX_PDQ(pdqid)	((uint_t)((pdqid) - TMIN_PDQID))
#define get_pdqcb(pdqid)	(&(pdqcb_table[INDEX_PDQ(pdqid)]))

/*
 *  �D��x�f�[�^�L���[�@�\�̏�����
 */
#ifdef TOPPERS_pdqini

void
initialize_pridataq(void)
{
	uint_t	i;
	PDQCB	*p_pdqcb;

	for (p_pdqcb = pdqcb_table, i = 0; i < tnum_pdq; p_pdqcb++, i++) {
		queue_initialize(&(p_pdqcb->swait_queue));
		p_pdqcb->p_pdqinib = &(pdqinib_table[i]);
		queue_initialize(&(p_pdqcb->rwait_queue));
		p_pdqcb->count = 0U;
		p_pdqcb->p_head = NULL;
		p_pdqcb->unused = 0U;
		p_pdqcb->p_freelist = NULL;
	}
}

#endif /* TOPPERS_pdqini */

/*
 *  �D��x�f�[�^�L���[�Ǘ��̈�ւ̃f�[�^�̊i�[
 */
#ifdef TOPPERS_pdqenq

void
enqueue_pridata(PDQCB *p_pdqcb, intptr_t data, PRI datapri)
{
	PDQMB	*p_pdqmb;
	PDQMB	**pp_prev_next, *p_next;

	if (p_pdqcb->p_freelist != NULL) {
		p_pdqmb = p_pdqcb->p_freelist;
		p_pdqcb->p_freelist = p_pdqmb->p_next;
	}
	else {
		p_pdqmb = p_pdqcb->p_pdqinib->p_pdqmb + p_pdqcb->unused;
		p_pdqcb->unused++;
	}

	p_pdqmb->data = data;
	p_pdqmb->datapri = datapri;

	pp_prev_next = &(p_pdqcb->p_head);
	while ((p_next = *pp_prev_next) != NULL) {
		if (p_next->datapri > datapri) {
			break;
		}
		pp_prev_next = &(p_next->p_next);
	}
	p_pdqmb->p_next = p_next;
	*pp_prev_next = p_pdqmb;
	p_pdqcb->count++;
}

#endif /* TOPPERS_pdqenq */

/*
 *  �D��x�f�[�^�L���[�Ǘ��̈悩��̃f�[�^�̎�o��
 */
#ifdef TOPPERS_pdqdeq

void
dequeue_pridata(PDQCB *p_pdqcb, intptr_t *p_data, PRI *p_datapri)
{
	PDQMB	*p_pdqmb;

	p_pdqmb = p_pdqcb->p_head;
	p_pdqcb->p_head = p_pdqmb->p_next;
	p_pdqcb->count--;

	*p_data = p_pdqmb->data;
	*p_datapri = p_pdqmb->datapri;

	p_pdqmb->p_next = p_pdqcb->p_freelist;
	p_pdqcb->p_freelist = p_pdqmb;
}

#endif /* TOPPERS_pdqdeq */

/*
 *  �D��x�f�[�^�L���[�ւ̃f�[�^���M
 */
#ifdef TOPPERS_pdqsnd

bool_t
send_pridata(PDQCB *p_pdqcb, intptr_t data, PRI datapri, bool_t *p_reqdsp)
{
	TCB		*p_tcb;

	if (!queue_empty(&(p_pdqcb->rwait_queue))) {
		p_tcb = (TCB *) queue_delete_next(&(p_pdqcb->rwait_queue));
		((WINFO_PDQ *)(p_tcb->p_winfo))->data = data;
		((WINFO_PDQ *)(p_tcb->p_winfo))->datapri = datapri;
		*p_reqdsp = wait_complete(p_tcb);
		return(true);
	}
	else if (p_pdqcb->count < p_pdqcb->p_pdqinib->pdqcnt) {
		enqueue_pridata(p_pdqcb, data, datapri);
		*p_reqdsp = false;
		return(true);
	}
	else {
		return(false);
	}
}

#endif /* TOPPERS_pdqsnd */

/*
 *  �D��x�f�[�^�L���[����̃f�[�^��M
 */
#ifdef TOPPERS_pdqrcv

bool_t
receive_pridata(PDQCB *p_pdqcb, intptr_t *p_data,
									PRI *p_datapri, bool_t *p_reqdsp)
{
	TCB		*p_tcb;
	intptr_t data;
	PRI		datapri;

	if (p_pdqcb->count > 0U) {
		dequeue_pridata(p_pdqcb, p_data, p_datapri);
		if (!queue_empty(&(p_pdqcb->swait_queue))) {
			p_tcb = (TCB *) queue_delete_next(&(p_pdqcb->swait_queue));
			data = ((WINFO_PDQ *)(p_tcb->p_winfo))->data;
			datapri = ((WINFO_PDQ *)(p_tcb->p_winfo))->datapri;
			enqueue_pridata(p_pdqcb, data, datapri);
			*p_reqdsp = wait_complete(p_tcb);
		}
		else {
			*p_reqdsp = false;
		}
		return(true);
	}
	else if (!queue_empty(&(p_pdqcb->swait_queue))) {
		p_tcb = (TCB *) queue_delete_next(&(p_pdqcb->swait_queue));
		*p_data = ((WINFO_PDQ *)(p_tcb->p_winfo))->data;
		*p_datapri = ((WINFO_PDQ *)(p_tcb->p_winfo))->datapri;
		*p_reqdsp = wait_complete(p_tcb);
		return(true);
	}
	else {
		return(false);
	}
}

#endif /* TOPPERS_pdqrcv */

/*
 *  �D��x�f�[�^�L���[�ւ̑��M
 */
#ifdef TOPPERS_snd_pdq

ER
snd_pdq(ID pdqid, intptr_t data, PRI datapri)
{
	PDQCB	*p_pdqcb;
	WINFO_PDQ winfo_pdq;
	bool_t	reqdsp;
	ER		ercd;

	LOG_SND_PDQ_ENTER(pdqid, data, datapri);
	CHECK_DISPATCH();
	CHECK_PDQID(pdqid);
	p_pdqcb = get_pdqcb(pdqid);
	CHECK_PAR(TMIN_DPRI <= datapri && datapri <= p_pdqcb->p_pdqinib->maxdpri);

	t_lock_cpu();
	if (send_pridata(p_pdqcb, data, datapri, &reqdsp)) {
		if (reqdsp) {
			dispatch();
		}
		ercd = E_OK;
	}
	else {
		winfo_pdq.data = data;
		winfo_pdq.datapri = datapri;
		p_runtsk->tstat = (TS_WAITING | TS_WAIT_SPDQ);
		wobj_make_wait((WOBJCB *) p_pdqcb, (WINFO_WOBJ *) &winfo_pdq);
		dispatch();
		ercd = winfo_pdq.winfo.wercd;
	}
	t_unlock_cpu();

  error_exit:
	LOG_SND_PDQ_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_snd_pdq */

/*
 *  �D��x�f�[�^�L���[�ւ̑��M�i�|�[�����O�j
 */
#ifdef TOPPERS_psnd_pdq

ER
psnd_pdq(ID pdqid, intptr_t data, PRI datapri)
{
	PDQCB	*p_pdqcb;
	bool_t	reqdsp;
	ER		ercd;

	LOG_PSND_PDQ_ENTER(pdqid, data, datapri);
	CHECK_TSKCTX_UNL();
	CHECK_PDQID(pdqid);
	p_pdqcb = get_pdqcb(pdqid);
	CHECK_PAR(TMIN_DPRI <= datapri && datapri <= p_pdqcb->p_pdqinib->maxdpri);

	t_lock_cpu();
	if (send_pridata(p_pdqcb, data, datapri, &reqdsp)) {
		if (reqdsp) {
			dispatch();
		}
		ercd = E_OK;
	}
	else {
		ercd = E_TMOUT;
	}
	t_unlock_cpu();

  error_exit:
	LOG_PSND_PDQ_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_psnd_pdq */

/*
 *  �D��x�f�[�^�L���[�ւ̑��M�i�|�[�����O�C��^�X�N�R���e�L�X�g�p�j
 */
#ifdef TOPPERS_ipsnd_pdq

ER
ipsnd_pdq(ID pdqid, intptr_t data, PRI datapri)
{
	PDQCB	*p_pdqcb;
	bool_t	reqdsp;
	ER		ercd;

	LOG_IPSND_PDQ_ENTER(pdqid, data, datapri);
	CHECK_INTCTX_UNL();
	CHECK_PDQID(pdqid);
	p_pdqcb = get_pdqcb(pdqid);
	CHECK_PAR(TMIN_DPRI <= datapri && datapri <= p_pdqcb->p_pdqinib->maxdpri);

	i_lock_cpu();
	if (send_pridata(p_pdqcb, data, datapri, &reqdsp)) {
		if (reqdsp) {
			reqflg = true;
		}
		ercd = E_OK;
	}
	else {
		ercd = E_TMOUT;
	}
	i_unlock_cpu();

  error_exit:
	LOG_IPSND_PDQ_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_ipsnd_pdq */

/*
 *  �D��x�f�[�^�L���[�ւ̑��M�i�^�C���A�E�g����j
 */
#ifdef TOPPERS_tsnd_pdq

ER
tsnd_pdq(ID pdqid, intptr_t data, PRI datapri, TMO tmout)
{
	PDQCB	*p_pdqcb;
	WINFO_PDQ winfo_pdq;
	TMEVTB	tmevtb;
	bool_t	reqdsp;
	ER		ercd;

	LOG_TSND_PDQ_ENTER(pdqid, data, datapri, tmout);
	CHECK_DISPATCH();
	CHECK_PDQID(pdqid);
	CHECK_TMOUT(tmout);
	p_pdqcb = get_pdqcb(pdqid);
	CHECK_PAR(TMIN_DPRI <= datapri && datapri <= p_pdqcb->p_pdqinib->maxdpri);

	t_lock_cpu();
	if (send_pridata(p_pdqcb, data, datapri, &reqdsp)) {
		if (reqdsp) {
			dispatch();
		}
		ercd = E_OK;
	}
	else if (tmout == TMO_POL) {
		ercd = E_TMOUT;
	}
	else {
		winfo_pdq.data = data;
		winfo_pdq.datapri = datapri;
		p_runtsk->tstat = (TS_WAITING | TS_WAIT_SPDQ);
		wobj_make_wait_tmout((WOBJCB *) p_pdqcb, (WINFO_WOBJ *) &winfo_pdq,
														&tmevtb, tmout);
		dispatch();
		ercd = winfo_pdq.winfo.wercd;
	}
	t_unlock_cpu();

  error_exit:
	LOG_TSND_PDQ_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_tsnd_pdq */

/*
 *  �D��x�f�[�^�L���[����̎�M
 */
#ifdef TOPPERS_rcv_pdq

ER
rcv_pdq(ID pdqid, intptr_t *p_data, PRI *p_datapri)
{
	PDQCB	*p_pdqcb;
	WINFO_PDQ winfo_pdq;
	bool_t	reqdsp;
	ER		ercd;

	LOG_RCV_PDQ_ENTER(pdqid, p_data, p_datapri);
	CHECK_DISPATCH();
	CHECK_PDQID(pdqid);
	p_pdqcb = get_pdqcb(pdqid);

	t_lock_cpu();
	if (receive_pridata(p_pdqcb, p_data, p_datapri, &reqdsp)) {
		if (reqdsp) {
			dispatch();
		}
		ercd = E_OK;
	}
	else {
		p_runtsk->tstat = (TS_WAITING | TS_WAIT_RPDQ);
		make_wait(&(winfo_pdq.winfo));
		queue_insert_prev(&(p_pdqcb->rwait_queue), &(p_runtsk->task_queue));
		winfo_pdq.p_pdqcb = p_pdqcb;
		LOG_TSKSTAT(p_runtsk);
		dispatch();
		ercd = winfo_pdq.winfo.wercd;
		if (ercd == E_OK) {
			*p_data = winfo_pdq.data;
			*p_datapri = winfo_pdq.datapri;
		}
	}
	t_unlock_cpu();

  error_exit:
	LOG_RCV_PDQ_LEAVE(ercd, *p_data, *p_datapri);
	return(ercd);
}

#endif /* TOPPERS_rcv_pdq */

/*
 *  �D��x�f�[�^�L���[����̎�M�i�|�[�����O�j
 */
#ifdef TOPPERS_prcv_pdq

ER
prcv_pdq(ID pdqid, intptr_t *p_data, PRI *p_datapri)
{
	PDQCB	*p_pdqcb;
	bool_t	reqdsp;
	ER		ercd;

	LOG_PRCV_PDQ_ENTER(pdqid, p_data, p_datapri);
	CHECK_TSKCTX_UNL();
	CHECK_PDQID(pdqid);
	p_pdqcb = get_pdqcb(pdqid);

	t_lock_cpu();
	if (receive_pridata(p_pdqcb, p_data, p_datapri, &reqdsp)) {
		if (reqdsp) {
			dispatch();
		}
		ercd = E_OK;
	}
	else {
		ercd = E_TMOUT;
	}
	t_unlock_cpu();

  error_exit:
	LOG_PRCV_PDQ_LEAVE(ercd, *p_data, *p_datapri);
	return(ercd);
}

#endif /* TOPPERS_prcv_pdq */

/*
 *  �D��x�f�[�^�L���[����̎�M�i�^�C���A�E�g����j
 */
#ifdef TOPPERS_trcv_pdq

ER
trcv_pdq(ID pdqid, intptr_t *p_data, PRI *p_datapri, TMO tmout)
{
	PDQCB	*p_pdqcb;
	WINFO_PDQ winfo_pdq;
	TMEVTB	tmevtb;
	bool_t	reqdsp;
	ER		ercd;

	LOG_TRCV_PDQ_ENTER(pdqid, p_data, p_datapri, tmout);
	CHECK_DISPATCH();
	CHECK_PDQID(pdqid);
	CHECK_TMOUT(tmout);
	p_pdqcb = get_pdqcb(pdqid);

	t_lock_cpu();
	if (receive_pridata(p_pdqcb, p_data, p_datapri, &reqdsp)) {
		if (reqdsp) {
			dispatch();
		}
		ercd = E_OK;
	}
	else if (tmout == TMO_POL) {
		ercd = E_TMOUT;
	}
	else {
		p_runtsk->tstat = (TS_WAITING | TS_WAIT_RPDQ);
		make_wait_tmout(&(winfo_pdq.winfo), &tmevtb, tmout);
		queue_insert_prev(&(p_pdqcb->rwait_queue), &(p_runtsk->task_queue));
		winfo_pdq.p_pdqcb = p_pdqcb;
		LOG_TSKSTAT(p_runtsk);
		dispatch();
		ercd = winfo_pdq.winfo.wercd;
		if (ercd == E_OK) {
			*p_data = winfo_pdq.data;
			*p_datapri = winfo_pdq.datapri;
		}
	}
	t_unlock_cpu();

  error_exit:
	LOG_TRCV_PDQ_LEAVE(ercd, *p_data, *p_datapri);
	return(ercd);
}

#endif /* TOPPERS_trcv_pdq */

/*
 *  �D��x�f�[�^�L���[�̍ď�����
 */
#ifdef TOPPERS_ini_pdq

ER
ini_pdq(ID pdqid)
{
	PDQCB	*p_pdqcb;
	bool_t	dspreq;
	ER		ercd;
    
	LOG_INI_PDQ_ENTER(pdqid);
	CHECK_TSKCTX_UNL();
	CHECK_PDQID(pdqid);
	p_pdqcb = get_pdqcb(pdqid);

	t_lock_cpu();
	dspreq = init_wait_queue(&(p_pdqcb->swait_queue));
	if (init_wait_queue(&(p_pdqcb->rwait_queue))) {
		dspreq = true;
	}
	p_pdqcb->count = 0U;
	p_pdqcb->p_head = NULL;
	p_pdqcb->unused = 0U;
	p_pdqcb->p_freelist = NULL;
	if (dspreq) {
		dispatch();
	}
	ercd = E_OK;
	t_unlock_cpu();

  error_exit:
	LOG_INI_PDQ_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_ini_pdq */

/*
 *  �D��x�f�[�^�L���[�̏�ԎQ��
 */
#ifdef TOPPERS_ref_pdq

ER
ref_pdq(ID pdqid, T_RPDQ *pk_rpdq)
{
	PDQCB	*p_pdqcb;
	ER		ercd;
    
	LOG_REF_PDQ_ENTER(pdqid, pk_rpdq);
	CHECK_TSKCTX_UNL();
	CHECK_PDQID(pdqid);
	p_pdqcb = get_pdqcb(pdqid);

	t_lock_cpu();
	pk_rpdq->stskid = wait_tskid(&(p_pdqcb->swait_queue));
	pk_rpdq->rtskid = wait_tskid(&(p_pdqcb->rwait_queue));
	pk_rpdq->spdqcnt = p_pdqcb->count;
	ercd = E_OK;
	t_unlock_cpu();

  error_exit:
	LOG_REF_PDQ_LEAVE(ercd, pk_rpdq);
	return(ercd);
}

#endif /* TOPPERS_ref_pdq */
