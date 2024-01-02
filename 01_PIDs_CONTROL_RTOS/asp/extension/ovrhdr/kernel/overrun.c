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
 *  @(#) $Id: overrun.c 1902 2010-08-17 22:38:52Z ertl-hiro $
 */

/*
 *		�I�[�o�����n���h���@�\
 */

#include "kernel_impl.h"
#include "check.h"
#include "task.h"
#include "overrun.h"

#ifdef TOPPERS_SUPPORT_OVRHDR
#include "target_timer.h"

/*
 *  �g���[�X���O�}�N���̃f�t�H���g��`
 */
#ifndef LOG_OVR_ENTER
#define LOG_OVR_ENTER(p_runtsk)
#endif /* LOG_OVR_ENTER */

#ifndef LOG_OVR_LEAVE
#define LOG_OVR_LEAVE(p_runtsk)
#endif /* LOG_OVR_LEAVE */

#ifndef LOG_STA_OVR_ENTER
#define LOG_STA_OVR_ENTER(tskid, ovrtim)
#endif /* LOG_STA_OVR_ENTER */

#ifndef LOG_STA_OVR_LEAVE
#define LOG_STA_OVR_LEAVE(ercd)
#endif /* LOG_STA_OVR_LEAVE */

#ifndef LOG_ISTA_OVR_ENTER
#define LOG_ISTA_OVR_ENTER(tskid, ovrtim)
#endif /* LOG_ISTA_OVR_ENTER */

#ifndef LOG_ISTA_OVR_LEAVE
#define LOG_ISTA_OVR_LEAVE(ercd)
#endif /* LOG_ISTA_OVR_LEAVE */

#ifndef LOG_ISTP_OVR_ENTER
#define LOG_ISTP_OVR_ENTER(tskid)
#endif /* LOG_ISTP_OVR_ENTER */

#ifndef LOG_ISTP_OVR_LEAVE
#define LOG_ISTP_OVR_LEAVE(ercd)
#endif /* LOG_ISTP_OVR_LEAVE */

#ifndef LOG_STP_OVR_ENTER
#define LOG_STP_OVR_ENTER(tskid)
#endif /* LOG_STP_OVR_ENTER */

#ifndef LOG_STP_OVR_LEAVE
#define LOG_STP_OVR_LEAVE(ercd)
#endif /* LOG_STP_OVR_LEAVE */

#ifndef LOG_REF_OVR_ENTER
#define LOG_REF_OVR_ENTER(tskid, pk_rovr)
#endif /* LOG_REF_OVR_ENTER */

#ifndef LOG_REF_OVR_LEAVE
#define LOG_REF_OVR_LEAVE(ercd, pk_rovr)
#endif /* LOG_REF_OVR_LEAVE */

#ifdef TOPPERS_ovrini

/*
 *  �I�[�o�����^�C�}�����쒆���������t���O
 */
bool_t	ovrtimer_flag;

/*
 *  �I�[�o�����n���h���@�\�̏�����
 */
void
initialize_overrun(void)
{
	ovrtimer_flag = false;
}

#endif /* TOPPERS_ovrini */

/*
 *  �I�[�o�����n���h���p�^�C�}�̓���J�n
 */
#ifdef TOPPERS_ovrsta
#ifndef OMIT_OVRTIMER_START

void
ovrtimer_start(void)
{
	if (p_runtsk->leftotm > 0U) {
		target_ovrtimer_start(p_runtsk->leftotm);
		ovrtimer_flag = true;
	}
}

#endif /* OMIT_OVRTIMER_START */
#endif /* TOPPERS_ovrsta */

/*
 *  �I�[�o�����n���h���p�^�C�}�̒�~
 */
#ifdef TOPPERS_ovrstp
#ifndef OMIT_OVRTIMER_STOP

void
ovrtimer_stop(void)
{
	if (ovrtimer_flag) {
		assert(p_runtsk->leftotm > 0U);
		p_runtsk->leftotm = target_ovrtimer_stop();
		ovrtimer_flag = false;
	}
}

#endif /* OMIT_OVRTIMER_STOP */
#endif /* TOPPERS_ovrstp */

/*
 *  �I�[�o�����n���h���̓���J�n
 */
#ifdef TOPPERS_sta_ovr

ER
sta_ovr(ID tskid, OVRTIM ovrtim)
{
	TCB		*p_tcb;
	ER		ercd;

	LOG_STA_OVR_ENTER(tskid, ovrtim);
	CHECK_TSKCTX_UNL();
	CHECK_OBJ(ovrinib.ovrhdr != NULL);
	CHECK_TSKID_SELF(tskid);
	CHECK_PAR(0U < ovrtim && ovrtim <= TMAX_OVRTIM);
	p_tcb = get_tcb_self(tskid);

	t_lock_cpu();
	if (p_tcb == p_runtsk) {
		if (p_tcb->leftotm > 0U) {
			(void) target_ovrtimer_stop();
		}
		target_ovrtimer_start(ovrtim);
		ovrtimer_flag = true;
	}
	p_tcb->leftotm = ovrtim;
	ercd = E_OK;
	t_unlock_cpu();

  error_exit:
	LOG_STA_OVR_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_sta_ovr */

/*
 *  �I�[�o�����n���h���̓���J�n�i��^�X�N�R���e�L�X�g�p�j
 */
#ifdef TOPPERS_ista_ovr

ER
ista_ovr(ID tskid, OVRTIM ovrtim)
{
	TCB		*p_tcb;
	ER		ercd;

	LOG_ISTA_OVR_ENTER(tskid, ovrtim);
	CHECK_INTCTX_UNL();
	CHECK_OBJ(ovrinib.ovrhdr != NULL);
	CHECK_TSKID(tskid);
	CHECK_PAR(0U < ovrtim && ovrtim <= TMAX_OVRTIM);
	p_tcb = get_tcb(tskid);

	i_lock_cpu();
	p_tcb->leftotm = ovrtim;
	ercd = E_OK;
	i_unlock_cpu();

  error_exit:
	LOG_ISTA_OVR_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_ista_ovr */

/*
 *  �I�[�o�����n���h���̓����~
 */
#ifdef TOPPERS_stp_ovr

ER
stp_ovr(ID tskid)
{
	TCB		*p_tcb;
	ER		ercd;

	LOG_STP_OVR_ENTER(tskid);
	CHECK_TSKCTX_UNL();
	CHECK_OBJ(ovrinib.ovrhdr != NULL);
	CHECK_TSKID_SELF(tskid);
	p_tcb = get_tcb_self(tskid);

	t_lock_cpu();
	if (p_tcb->leftotm > 0U) {
		if (p_tcb == p_runtsk) {
			(void) target_ovrtimer_stop();
			ovrtimer_flag = false;
		}
		p_tcb->leftotm = 0U;
	}
	ercd = E_OK;
	t_unlock_cpu();

  error_exit:
	LOG_STP_OVR_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_stp_ovr */

/*
 *  �I�[�o�����n���h���̓����~�i��^�X�N�R���e�L�X�g�p�j
 */
#ifdef TOPPERS_istp_ovr

ER
istp_ovr(ID tskid)
{
	TCB		*p_tcb;
	ER		ercd;

	LOG_ISTP_OVR_ENTER(tskid);
	CHECK_INTCTX_UNL();
	CHECK_OBJ(ovrinib.ovrhdr != NULL);
	CHECK_TSKID(tskid);
	p_tcb = get_tcb(tskid);

	i_lock_cpu();
	p_tcb->leftotm = 0U;
	ercd = E_OK;
	i_unlock_cpu();

  error_exit:
	LOG_ISTP_OVR_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_istp_ovr */

/*
 *  �I�[�o�����n���h���̏�ԎQ��
 */
#ifdef TOPPERS_ref_ovr

ER
ref_ovr(ID tskid, T_ROVR *pk_rovr)
{
	TCB		*p_tcb;
	ER		ercd;
    
	LOG_REF_OVR_ENTER(tskid, pk_rovr);
	CHECK_TSKCTX_UNL();
	CHECK_OBJ(ovrinib.ovrhdr != NULL);
	CHECK_TSKID_SELF(tskid);
	p_tcb = get_tcb_self(tskid);

	t_lock_cpu();
	if (p_tcb->leftotm > 0U) {
		pk_rovr->ovrstat = TOVR_STA;
		if (p_tcb == p_runtsk) {
			pk_rovr->leftotm = target_ovrtimer_get_current();
		}
		else {
			pk_rovr->leftotm = p_tcb->leftotm;
		}
	}
	else {
		pk_rovr->ovrstat = TOVR_STP;
	}
	ercd = E_OK;
	t_unlock_cpu();

  error_exit:
	LOG_REF_OVR_LEAVE(ercd, pk_rovr);
	return(ercd);
}

#endif /* TOPPERS_ref_ovr */

/*
 *  �I�[�o�����n���h���N�����[�`��
 */
#ifdef TOPPERS_ovrcal

void
call_ovrhdr(void)
{
	PRI		saved_ipm;

	assert(sense_context());
	assert(!i_sense_lock());
	assert(ovrinib.ovrhdr != NULL);

	p_runtsk->leftotm = 0U;
	saved_ipm = i_get_ipm();

	LOG_OVR_ENTER(p_runtsk);
	(*((OVRHDR)(ovrinib.ovrhdr)))(TSKID(p_runtsk), p_runtsk->p_tinib->exinf);
	LOG_OVR_LEAVE(p_runtsk);

	if (i_sense_lock()) {
		i_unlock_cpu();
	}
	i_set_ipm(saved_ipm);
}

#endif /* TOPPERS_ovrcal */
#endif /* TOPPERS_SUPPORT_OVRHDR */
