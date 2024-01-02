/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
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
 *  @(#) $Id: task_refer.c 1016 2008-05-10 08:42:16Z ertl-hiro $
 */

/*
 *		�^�X�N�̏�ԎQ�Ƌ@�\
 */

#include "kernel_impl.h"
#include "check.h"
#include "task.h"
#include "wait.h"
#include "semaphore.h"
#include "eventflag.h"
#include "dataqueue.h"
#include "pridataq.h"
#include "mailbox.h"
#include "mempfix.h"
#include "time_event.h"

/*
 *  �g���[�X���O�}�N���̃f�t�H���g��`
 */
#ifndef LOG_REF_TSK_ENTER
#define LOG_REF_TSK_ENTER(tskid, pk_rtsk)
#endif /* LOG_REF_TSK_ENTER */

#ifndef LOG_REF_TSK_LEAVE
#define LOG_REF_TSK_LEAVE(ercd, pk_rtsk)
#endif /* LOG_REF_TSK_LEAVE */

/*
 *  �^�X�N�̏�ԎQ��
 */
#ifdef TOPPERS_ref_tsk

ER
ref_tsk(ID tskid, T_RTSK *pk_rtsk)
{
	TCB		*p_tcb;
	uint_t	tstat;
	ER		ercd;

	LOG_REF_TSK_ENTER(tskid, pk_rtsk);
	CHECK_TSKCTX_UNL();
	CHECK_TSKID_SELF(tskid);
	p_tcb = get_tcb_self(tskid);

	t_lock_cpu();
	tstat = p_tcb->tstat;
	if (TSTAT_DORMANT(tstat)) {
		/*
 		 *  �Ώۃ^�X�N���x�~��Ԃ̏ꍇ
		 */
		pk_rtsk->tskstat = TTS_DMT;
	}
	else {
		/*
 		 *  �^�X�N��Ԃ̎�o��
		 */
		if (TSTAT_SUSPENDED(tstat)) {
			if (TSTAT_WAITING(tstat)) {
				pk_rtsk->tskstat = TTS_WAS;
			}
			else {
				pk_rtsk->tskstat = TTS_SUS;
			}
		}
		else if (TSTAT_WAITING(tstat)) {
			pk_rtsk->tskstat = TTS_WAI;
		}
		else if (p_tcb == p_runtsk) {
			pk_rtsk->tskstat = TTS_RUN;
		}
		else {
			pk_rtsk->tskstat = TTS_RDY;
		}

		/*
 		 *  ���ݗD��x�ƃx�[�X�D��x�̎�o��
		 */
		pk_rtsk->tskpri = EXT_TSKPRI(p_tcb->priority);
		pk_rtsk->tskbpri = EXT_TSKPRI(p_tcb->priority);

		if (TSTAT_WAITING(tstat)) {
			/*
	 		 *  �҂��v���Ƒ҂��Ώۂ̃I�u�W�F�N�g��ID�̎�o��
			 */
			switch (tstat & TS_WAIT_MASK) {
			case TS_WAIT_SLP:
				pk_rtsk->tskwait = TTW_SLP;
				break;
			case TS_WAIT_DLY:
				pk_rtsk->tskwait = TTW_DLY;
				break;
			case TS_WAIT_SEM:
				pk_rtsk->tskwait = TTW_SEM;
				pk_rtsk->wobjid = SEMID(((WINFO_SEM *)(p_tcb->p_winfo))
																->p_semcb);
				break;
			case TS_WAIT_FLG:
				pk_rtsk->tskwait = TTW_FLG;
				pk_rtsk->wobjid = FLGID(((WINFO_FLG *)(p_tcb->p_winfo))
																->p_flgcb);
				break;
			case TS_WAIT_SDTQ:
				pk_rtsk->tskwait = TTW_SDTQ;
				pk_rtsk->wobjid = DTQID(((WINFO_DTQ *)(p_tcb->p_winfo))
																->p_dtqcb);
				break;
			case TS_WAIT_RDTQ:
				pk_rtsk->tskwait = TTW_RDTQ;
				pk_rtsk->wobjid = DTQID(((WINFO_DTQ *)(p_tcb->p_winfo))
																->p_dtqcb);
				break;
			case TS_WAIT_SPDQ:
				pk_rtsk->tskwait = TTW_SPDQ;
				pk_rtsk->wobjid = PDQID(((WINFO_PDQ *)(p_tcb->p_winfo))
																->p_pdqcb);
				break;
			case TS_WAIT_RPDQ:
				pk_rtsk->tskwait = TTW_RPDQ;
				pk_rtsk->wobjid = PDQID(((WINFO_PDQ *)(p_tcb->p_winfo))
																->p_pdqcb);
				break;
			case TS_WAIT_MBX:
				pk_rtsk->tskwait = TTW_MBX;
				pk_rtsk->wobjid = MBXID(((WINFO_MBX *)(p_tcb->p_winfo))
																->p_mbxcb);
				break;
			case TS_WAIT_MPF:
				pk_rtsk->tskwait = TTW_MPF;
				pk_rtsk->wobjid = MPFID(((WINFO_MPF *)(p_tcb->p_winfo))
																->p_mpfcb);
				break;
			}

			/*
	 		 *  �^�C���A�E�g����܂ł̎��Ԃ̎�o��
			 */
			if (p_tcb->p_winfo->p_tmevtb != NULL) {
				pk_rtsk->lefttmo
						= (TMO) tmevt_lefttim(p_tcb->p_winfo->p_tmevtb);
			}
			else {
				pk_rtsk->lefttmo = TMO_FEVR;
			}
		}

		/*
 		 *  �N���v���L���[�C���O���̎�o��
		 */
		pk_rtsk->wupcnt = p_tcb->wupque ? 1U : 0U;
	}

	/*
	 *  �N���v���L���[�C���O���̎�o��
	 */
	pk_rtsk->actcnt = p_tcb->actque ? 1U : 0U;
	ercd = E_OK;
	t_unlock_cpu();

  error_exit:
	LOG_REF_TSK_LEAVE(ercd, pk_rtsk);
	return(ercd);
}

#endif /* TOPPERS_ref_tsk */
