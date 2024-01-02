/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      High Reliable system Profile Kernel
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
 *  @(#) $Id: bit_mutex.c 762 2008-03-07 23:51:41Z hiro $
 */

/*
 *		�~���[�e�b�N�X�@�\�̐���������
 */

#include "kernel/kernel_impl.h"
#include "kernel/task.h"
#include "kernel/mutex.h"

/*
 *  �~���[�e�b�N�XID����~���[�e�b�N�X�Ǘ��u���b�N�����o�����߂̃}�N
 *  ���imutex.c���j
 */
#define INDEX_MTX(mtxid)	((uint_t)((mtxid) - TMIN_MTXID))
#define get_mtxcb(mtxid)	(&(mtxcb_table[INDEX_MTX(mtxid)]))

/*
 *  �~���[�e�b�N�X�Ǘ��u���b�N����mutex_queue�ւ̃|�C���^����C�~���[�e�b
 *  �N�X�Ǘ��u���b�N�ւ̃|�C���^�����o�����߂̃}�N���imutex.c���j
 */
#define MTXCB_QUEUE(p_queue) \
			((MTXCB *)(((char *) p_queue) - offsetof(MTXCB, mutex_queue)))

/*
 *  �~���[�e�b�N�X�̃v���g�R���𔻒f����}�N���imutex.c���j
 */
#define MTXPROTO_MASK			0x03U
#define MTXPROTO(p_mtxcb)		((p_mtxcb)->p_mtxinib->mtxatr & MTXPROTO_MASK)
#define MTX_CEILING(p_mtxcb)	(MTXPROTO(p_mtxcb) == TA_CEILING)

/*
 *   �G���[�R�[�h�̒�`
 */
#define E_SYS_LINENO	ERCD(E_SYS, -(__LINE__))

/*
 *  �Ǘ��u���b�N�̃A�h���X�̐������̃`�F�b�N
 */
#define VALID_TCB(p_tcb) \
		((((char *) p_tcb) - ((char *) tcb_table)) % sizeof(TCB) == 0 \
			&& TMIN_TSKID <= TSKID(p_tcb) && TSKID(p_tcb) <= tmax_tskid)

#define VALID_MTXCB(p_mtxcb) \
		((((char *) p_mtxcb) - ((char *) mtxcb_table)) % sizeof(MTXCB) == 0 \
			&& TMIN_MTXID <= MTXID(p_mtxcb) && MTXID(p_mtxcb) <= tmax_mtxid)
				
/*
 *  �L���[�̃`�F�b�N�̂��߂̊֐�
 *
 *  p_queue��p_entry���܂܂�Ă��邩�𒲂ׂ�D�܂܂�Ă����true�C�܂�
 *  ��Ă��Ȃ��ꍇ�ɂ�false��Ԃ��D�_�u�������N�̕s�����̏ꍇ�ɂ��C
 *  false��Ԃ��D
 */
static bool_t
in_queue(QUEUE *p_queue, QUEUE *p_entry)
{
	QUEUE	*p_current, *p_next;

	p_current = p_queue->p_next;
	if (p_current->p_prev != p_queue) {
		return(false);					/* �_�u�������N�̕s���� */
	}
	while (p_current != p_queue) {
		if (p_current == p_entry) {
			return(true);				/* p_entry���܂܂�Ă��� */
		}

		/*
		 *  �L���[�̎��̗v�f�ɐi��
		 */
		p_next = p_current->p_next;
		if (p_next->p_prev != p_current) {
			return(false);				 /* �_�u�������N�̕s���� */
		}
		p_current = p_next;
	}
	return(false);
}

/*
 *  �^�X�N���̌���
 */
static ER
bit_mutex_task(ID tskid)
{
	TCB			*p_tcb;
	MTXCB		*p_mtxcb;
	QUEUE		*p_queue, *p_next;
	uint_t		priority;

	if (!(TMIN_TSKID <= (tskid) && (tskid) <= tmax_tskid)) {
		return(E_ID);
	}
	p_tcb = get_tcb(tskid);
	priority = p_tcb->bpriority;

	/*
	 *  �^�X�N�����b�N���Ă���~���[�e�b�N�X�̃L���[�̌���
	 */
	p_queue = p_tcb->mutex_queue.p_next;
	if (p_queue->p_prev != &(p_tcb->mutex_queue)) {
		return(E_SYS_LINENO);
	}
	while (p_queue != &(p_tcb->mutex_queue)) {
		p_mtxcb = MTXCB_QUEUE(p_queue);
		if (!VALID_MTXCB(p_mtxcb)) {
			return(E_SYS_LINENO);
		}

		/*
		 *  �~���[�e�b�N�X�����b�N���Ă���^�X�N�̃`�F�b�N
		 */
		if (p_mtxcb->p_loctsk != p_tcb) {
			return(E_SYS_LINENO);
		}

		/*
		 *  ���ݗD��x�̌v�Z
		 */
		if (MTXPROTO(p_mtxcb)) {
			if (p_mtxcb->p_mtxinib->ceilpri < priority) {
				priority = p_mtxcb->p_mtxinib->ceilpri;
			}
		}

		/*
		 *  �L���[�̎��̗v�f�ɐi��
		 */
		p_next = p_queue->p_next;
		if (p_next->p_prev != p_queue) {
			return(E_SYS_LINENO);
		}
		p_queue = p_next;
	}

	/*
	 *  ���ݗD��x�̌���
	 */
	if (p_tcb->priority != p_tcb->priority) {
		return(E_SYS_LINENO);
	}

	/*
	 *  �^�X�N���҂��Ă���~���[�e�b�N�X�Ɋւ��錟��
	 */
	if (TSTAT_WAIT_MTX(p_tcb->tstat)) {
		p_mtxcb = ((WINFO_MTX *)(p_tcb->p_winfo))->p_mtxcb;
		if (!VALID_MTXCB(p_mtxcb)) {
			return(E_SYS_LINENO);
		}
		if (!in_queue(&(p_mtxcb->wait_queue), &(p_tcb->task_queue))) {
			return(E_SYS_LINENO);
		}
	}
	return(E_OK);
}

/*
 *  �~���[�e�b�N�X���̌���
 */
static ER
bit_mutex_mutex(ID mtxid)
{
	MTXCB		*p_mtxcb;
	TCB			*p_tcb;
	QUEUE		*p_queue, *p_next;
	uint_t		priority;

	if (!(TMIN_MTXID <= (mtxid) && (mtxid) <= tmax_mtxid)) {
		return(E_ID);
	}
	p_mtxcb = get_mtxcb(mtxid);

	/*
	 *  �������u���b�N�ւ̃|�C���^�̌���
	 */
	if (p_mtxcb->p_mtxinib != &(mtxinib_table[INDEX_MTX(mtxid)])) {
		return(E_SYS_LINENO);
	}

	/*
	 *  �~���[�e�b�N�X�҂��L���[�̌���
	 */
	p_queue = p_mtxcb->wait_queue.p_next;
	if (p_queue->p_prev != &(p_mtxcb->wait_queue)) {
		return(E_SYS_LINENO);
	}
	priority = TMIN_TPRI;
	while (p_queue != &(p_mtxcb->wait_queue)) {
		p_tcb = (TCB *) p_queue;
		if (!VALID_TCB(p_tcb)) {
			return(E_SYS_LINENO);
		}

		/*
		 *  �L���[���^�X�N�D��x���ɂȂ��Ă��邩�̌���
		 */
		if (MTXPROTO(p_mtxcb) != TA_NULL) {
			if (p_tcb->priority < priority) {
				return(E_SYS_LINENO);
			}
		}
		priority = p_tcb->priority;

		/*
		 *  �^�X�N��Ԃ̌���
		 *
		 *  �~���[�e�b�N�X�҂���Ԃ̃^�X�N�̌����́C�^�X�N���̌����ōs��
		 *  �Ă��邽�߁C�����ł͍s��Ȃ��D
		 */
		if (!TSTAT_WAIT_MTX(p_tcb->tstat)) {
			return(E_SYS_LINENO);
		}

		/*
		 *  �D��x����̌���
		 */
		if (MTXPROTO(p_mtxcb) == TA_CEILING) {
			if (p_tcb->bpriority < p_mtxcb->p_mtxinib->ceilpri) {
				return(E_SYS_LINENO);
			}
		}

		/*
		 *  �L���[�̎��̗v�f�ɐi��
		 */
		p_next = p_queue->p_next;
		if (p_next->p_prev != p_queue) {
			return(E_SYS_LINENO);
		}
		p_queue = p_next;
	}

	/*
	 *  �~���[�e�b�N�X�����b�N���Ă���^�X�N�̌���
	 */
	p_tcb = p_mtxcb->p_loctsk;
	if (p_tcb == NULL) {
		/*
		 *  �~���[�e�b�N�X�����b�N����Ă��Ȃ���
		 */
		if (!queue_empty(&(p_mtxcb->wait_queue))) {
			return(E_SYS_LINENO);
		}
	}
	else {
		/*
		 *  �~���[�e�b�N�X�����b�N����Ă��鎞
		 *
		 *  �~���[�e�b�N�X�����b�N���Ă���^�X�N�̌����́C�^�X�N���̌�
		 *  ���ōs���Ă��邽�߁C�����ł͍s��Ȃ��D
		 */
		if (!VALID_TCB(p_tcb)) {
			return(E_SYS_LINENO);
		}
		if (!in_queue(&(p_tcb->mutex_queue), &(p_mtxcb->mutex_queue))) {
			return(E_SYS_LINENO);
		}

		/*
		 *  �D��x����̌���
		 */
		if (MTXPROTO(p_mtxcb) == TA_CEILING) {
			if (p_tcb->bpriority < p_mtxcb->p_mtxinib->ceilpri) {
				return(E_SYS_LINENO);
			}
		}
	}
	return(E_OK);
}

/*
 *  �������������[�`���{��
 */
ER
bit_mutex(void)
{
	ID		tskid, mtxid;
	ER		ercd;

	/*
	 *  �^�X�N���̌���
	 */
	for (tskid = TMIN_TSKID; tskid <= tmax_tskid; tskid++) {
		ercd = bit_mutex_task(tskid);
		if (ercd != E_OK) {
			return(ercd);
		}
	}

	/*
	 *  �~���[�e�b�N�X���̌���
	 */
	for (mtxid = TMIN_MTXID; mtxid <= tmax_mtxid; mtxid++) {
		ercd = bit_mutex_mutex(mtxid);
		if (ercd != E_OK) {
			return(ercd);
		}
	}
	return(E_OK);
}
