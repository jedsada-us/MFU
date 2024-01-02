/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 * 
 *  Copyright (C) 2007-2009 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: test_tex2.c 1577 2009-05-31 14:30:51Z ertl-hiro $
 */

/* 
 *		�^�X�N��O�����Ɋւ���e�X�g(2)
 *
 * �y�e�X�g�̖ړI�z
 *
 *  �����݃n���h���i�A���[���n���h���j�����CPU��O�n���h������^�X�N��
 *  �O�������[�`�����N�����鏈����ԗ��I�Ƀe�X�g����D
 *
 * �y�e�X�g���ځz
 *
 *	(A) iras_tex�̃G���[���o
 *		(A-1) �Ώۃ^�X�N���x�~���
 *		(A-2) �Ώۃ^�X�N�̃^�X�N��O�������[�`������`����Ă��Ȃ�
 *	(B) �����݃n���h������Ă΂ꂽiras_tex�̐��폈��
 *		(B-1) �Ώۃ^�X�N�����s��Ԃ̃^�X�N���^�X�N��O��������
 *		(B-2) �Ώۃ^�X�N�����s��Ԃ̃^�X�N�łȂ�
 *		(B-3) �Ώۃ^�X�N�����s��Ԃ̃^�X�N�����^�X�N��O�����֎~
 *	(C) CPU��O�n���h������Ă΂ꂽiras_tex�̐��폈��
 *		(C-1) �Ώۃ^�X�N�����s��Ԃ̃^�X�N���^�X�N��O��������
 *		(C-2) �Ώۃ^�X�N�����s��Ԃ̃^�X�N�łȂ�
 *		(C-3) �Ώۃ^�X�N�����s��Ԃ̃^�X�N�����^�X�N��O�����֎~
 *				�� ���{���Ȃ��i�^�[�Q�b�g��ˑ��Ɏ����ł��Ȃ��j
 *	(D) �����݃n���h���̏o�������ɂ��N��
 *		(D-1) �f�B�X�p�b�`��̃^�X�N���^�X�N��O���Ń^�X�N��O�����v
 *			  ������
 *	(E) CPU��O�n���h���̏o�������ɂ��N��
 *		(E-1) �f�B�X�p�b�`��̃^�X�N���^�X�N��O���Ń^�X�N��O�����v
 *			  ������
 *	(F) sns_tex�Ŏ��s��Ԃ̃^�X�N���Ȃ�
 *
 * �y�g�p���\�[�X�z
 *
 *	TASK1: ���C���̃^�X�N�D���s��Ԃ̃^�X�N�ɑ΂��ă^�X�N��O������v����
 *		   ��Ώۃ^�X�N
 *	TASK2: ���s��ԂłȂ��^�X�N�ɑ΂��ă^�X�N��O������v������Ώۃ^�X�N
 *	TASK3: �^�X�N��O�������[�`������`����Ă��Ȃ��^�X�N
 *	TASK4: �x�~��Ԃ̃^�X�N
 *	ALM1:  �A���[���n���h��1
 *	ALM2:  �A���[���n���h��2
 *	ALM3:  �A���[���n���h��3
 *	CPUEXC1: CPU��O�n���h��
 *
 * �y�e�X�g�V�[�P���X�z
 *
 *	== TASK1�i�D��x�F10�j==
 *	1:	������Ԃ̃`�F�b�N
 *		ref_tex(TSK_SELF, &rtex)
 *	2:	sta_alm(ALM1, 1U)
 *		�A���[���n���h��1�̎��s��҂�
 *	== ALM1 ==
 *	3:	������Ԃ̃`�F�b�N
 *		iras_tex(TASK3, 0x0001)		... (A-2)
 *		iras_tex(TASK4, 0x0001)		... (A-1)
 *		iras_tex(TASK2, 0x0001)		... (B-2)
 *		iras_tex(TASK1, 0x0001)		... (B-3)
 *		���^�[��
 *	== TASK1�i�����j==
 *	4:	ena_tex()
 *	== TASK1�^�X�N��O�������[�`���i1��ځj==
 *	5:	������Ԃ̃`�F�b�N
 *	6:	dis_dsp() ... 4�̏�Ԃ����ꂼ��ω�������
 *		chg_ipm(TMAX_INTPRI)
 *		ena_tex()
 *		loc_cpu()
 *		���^�[��
 *	== TASK1�i�����j==
 *	7:	�߂��Ă�����Ԃ̃`�F�b�N
 *		ref_tex(TSK_SELF, &rtex)
 *	8:	sta_alm(ALM2, 1U)
 *		�A���[���n���h��2�̎��s��҂�
 *	== ALM2 ==
 *	9:	������Ԃ̃`�F�b�N
 *		iras_tex(TASK1, 0x0002)		... (B-1)
 *		���^�[��					... (D-1)
 *	== TASK1�^�X�N��O�������[�`���i2��ځj==
 *	10:	������Ԃ̃`�F�b�N
 *		���^�[��
 *	== TASK1�i�����j==
 *	11:	sus_tsk(TASK2)
 *		sus_tsk(TASK3)
 *	12:	sta_alm(ALM3, 10U)
 *	13:	dly_tsk(50U)
 *	== ALM3 ==
 *	14:	������Ԃ̃`�F�b�N
 *		�msns_tex()���܂ށn			... (F)
 *		iget_tid(&tskid)
 *		iras_tex(TASK1, 0x0004)		... (B-2)
 *		���^�[��
 *	== TASK1�^�X�N��O�������[�`���i3��ځj==
 *	15:	������Ԃ̃`�F�b�N
 *		���^�[��
 *	== TASK1�i�����j==
 *	16:	rsm_tsk(TASK2)
 *		rsm_tsk(TASK3)
 *		dis_dsp()
 *	17:	RAISE_CPU_EXCEPTION
 *	== CPUEXC1 ==
 *	18:	������Ԃ̃`�F�b�N
 *		xsns_xpn(p_excinf)
 *		iras_tex(TASK3, 0x0010)		... (A-2)
 *		iras_tex(TASK4, 0x0010)		... (A-1)
 *		iras_tex(TASK2, 0x0010)		... (C-2)
 *		iras_tex(TASK1, 0x0010)		... (C-1)
 *		���^�[��					... (E-1)
 *	== TASK1�^�X�N��O�������[�`���i4��ځj==
 *	19:	������Ԃ̃`�F�b�N
 *	20:	ext_tsk()
 *	== TASK2�i�D��x�F10�j==
 *	21:	������Ԃ̃`�F�b�N
 *	22:	ena_tex()
 *	== TASK2�^�X�N��O�������[�`�� ==
 *	23:	������Ԃ̃`�F�b�N
 *		���^�[��
 *	== TASK2�i�����j==
 *	24:	sus_tsk(TASK3)
 *	25:	�e�X�g�I��
 */

#include <kernel.h>
#include <test_lib.h>
#include <t_syslog.h>
#include "kernel_cfg.h"
#include "test_tex2.h"

volatile bool_t	alm1_flag = false;
volatile bool_t	alm2_flag = false;
volatile bool_t	alm3_flag = false;

void
tex_task1(TEXPTN texptn, intptr_t exinf)
{
	ER		ercd;

	switch (texptn) {
	case 0x0001:
		check_point(5);
		check_state(false, false, TIPM_ENAALL, false, false, true);

		/*
		 *  �f�B�X�p�b�`�֎~�C�����ݗD��x�}�X�N�ύX�C�^�X�N��O�������C
		 *  CPU���b�N
		 */
		check_point(6);
		ercd = dis_dsp();
		check_ercd(ercd, E_OK);
		ercd = chg_ipm(TMAX_INTPRI);
		check_ercd(ercd, E_OK);
		ercd = ena_tex();
		check_ercd(ercd, E_OK);
		ercd = loc_cpu();
		check_ercd(ercd, E_OK);
		check_state(false, true, TMAX_INTPRI, true, true, false);
		break;

	case 0x0002:
		check_point(10);
		check_state(false, false, TIPM_ENAALL, false, false, true);
		break;

	case 0x0004:
		check_point(15);
		check_state(false, false, TIPM_ENAALL, false, false, true);
		break;

	case 0x0010:
		check_point(19);
		check_state(false, false, TIPM_ENAALL, true, true, true);

		/*
		 *  �^�X�N�I��
		 */
		check_point(20);
		ercd = ext_tsk();
		check_point(0);
		break;

	default:
		check_point(0);
		break;
	}
}

void
task1(intptr_t exinf)
{
	ER		ercd;
	T_RTEX	rtex;

	/*
	 *  ������Ԃ̃`�F�b�N
	 */
	check_point(1);
	check_state(false, false, TIPM_ENAALL, false, false, true);
	ercd = ref_tex(TSK_SELF, &rtex);
	check_ercd(ercd, E_OK);
	check_assert((rtex.texstat & TTEX_DIS) != 0);
	check_assert(rtex.pndptn == 0);

	/*
	 *  �A���[���n���h��1�̓���J�n
	 */
	check_point(2);
	ercd = sta_alm(ALM1, 1U);
	check_ercd(ercd, E_OK);

	/*
	 *  �A���[���n���h��1�̎��s��҂�
	 */
	while (!(alm1_flag));

	/*
	 *  �^�X�N��O����������
	 */
	check_point(4);
	ercd = ena_tex();
	/* �����Ń^�X�N��O�������[�`�������삷�� */
	check_ercd(ercd, E_OK);

	/*
	 *  �^�X�N��O��������̃��^�[���ɂ�茳�̏�Ԃɖ߂��Ă��邱�Ƃ�
	 *  �`�F�b�N
	 */
	check_point(7);
	check_state(false, false, TIPM_ENAALL, false, false, false);
	ercd = ref_tex(TSK_SELF, &rtex);
	check_ercd(ercd, E_OK);
	check_assert((rtex.texstat & TTEX_ENA) != 0);
	check_assert(rtex.pndptn == 0);

	/*
	 *  �A���[���n���h��2�̓���J�n
	 */
	check_point(8);
	ercd = sta_alm(ALM2, 1U);
	check_ercd(ercd, E_OK);

	/*
	 *  �A���[���n���h��2�̎��s��҂�
	 */
	while (!(alm2_flag));

	/*
	 *  TASK2��TASK3���~�߂�D
	 */
	check_point(11);
	ercd = sus_tsk(TASK2);
	check_ercd(ercd, E_OK);
	ercd = sus_tsk(TASK3);
	check_ercd(ercd, E_OK);

	/*
	 *  �A���[���n���h��3�̓���J�n
	 */
	check_point(12);
	ercd = sta_alm(ALM3, 10U);
	check_ercd(ercd, E_OK);

	/*
	 *  ���s�x��
	 */
	check_point(13);
	ercd = dly_tsk(50U);
	/* �A���[���n���h��3�����삷�� */
	check_ercd(ercd, E_OK);

	/*
	 *  TASK2��TASK3���ĊJ����D
	 */
	check_point(16);
	ercd = rsm_tsk(TASK2);
	check_ercd(ercd, E_OK);
	ercd = rsm_tsk(TASK3);
	check_ercd(ercd, E_OK);

	/*
	 *  �f�B�X�p�b�`�֎~
	 */
	ercd = dis_dsp();
	check_ercd(ercd, E_OK);

	/*
	 *  CPU��O�𔭐�������
	 */
	check_point(17);
	RAISE_CPU_EXCEPTION;

	check_point(0);
}

void
tex_task2(TEXPTN texptn, intptr_t exinf)
{
	switch (texptn) {
	case 0x0011:
		check_point(23);
		check_state(false, false, TIPM_ENAALL, false, false, true);
		break;

	default:
		check_point(0);
		break;
	}
}

void
task2(intptr_t exinf)
{
	ER		ercd;

	/*
	 *  ������Ԃ̃`�F�b�N
	 */
	check_point(21);
	check_state(false, false, TIPM_ENAALL, false, false, true);

	/*
	 *  �^�X�N��O����������
	 */
	check_point(22);
	ercd = ena_tex();
	/* �����Ń^�X�N��O�������[�`�������삷�� */
	check_ercd(ercd, E_OK);

	/*
	 *  TASK3���~�߂�D
	 */
	check_point(24);
	ercd = sus_tsk(TASK3);
	check_ercd(ercd, E_OK);

	/*
	 *  �e�X�g�I��
	 */
	check_finish(25);
}

void
task3(intptr_t exinf)
{
	check_point(0);
}

void
task4(intptr_t exinf)
{
	check_point(0);
}

void
tex_task4(TEXPTN texptn, intptr_t exinf)
{
	check_point(0);
}

void
alarm1_handler(intptr_t exinf)
{
	ER		ercd;

	/*
	 *  ������Ԃ̃`�F�b�N
	 */
	check_point(3);
	check_state_i(true, false, false, true, true);

	/*
	 *  iras_tex�̃G���[���o
	 */
	ercd = iras_tex(TASK3, 0x0001);
	check_ercd(ercd, E_OBJ);
	ercd = iras_tex(TASK4, 0x0001);
	check_ercd(ercd, E_OBJ);

	/*
	 *  �^�X�N��O������v��
	 */
	ercd = iras_tex(TASK2, 0x0001);
	check_ercd(ercd, E_OK);
	ercd = iras_tex(TASK1, 0x0001);
	check_ercd(ercd, E_OK);

	alm1_flag = true;
}

void
alarm2_handler(intptr_t exinf)
{
	ER		ercd;

	/*
	 *  ������Ԃ̃`�F�b�N
	 */
	check_point(9);
	check_state_i(true, false, false, true, false);

	/*
	 *  �^�X�N��O������v��
	 */
	ercd = iras_tex(TASK1, 0x0002);
	check_ercd(ercd, E_OK);

	alm2_flag = true;
}

void
alarm3_handler(intptr_t exinf)
{
	ER		ercd;
	ID		tskid;

	check_point(14);
	check_state_i(true, false, false, true, true);
	ercd = iget_tid(&tskid);
	check_ercd(ercd, E_OK);
	check_assert(tskid == TSK_NONE);

	/*
	 *  �^�X�N��O������v��
	 */
	ercd = iras_tex(TASK1, 0x0004);
	check_ercd(ercd, E_OK);

	alm3_flag = true;
}

void
cpuexc_handler(void *p_excinf)
{
	ER		ercd;

	/*
	 *  ������Ԃ̃`�F�b�N
	 */
	check_point(18);
	check_state_i(true, false, true, true, false);
	check_assert(xsns_xpn(p_excinf) == false);

	/*
	 *  iras_tex�̃G���[���o
	 */
	ercd = iras_tex(TASK3, 0x0010);
	check_ercd(ercd, E_OBJ);
	ercd = iras_tex(TASK4, 0x0010);
	check_ercd(ercd, E_OBJ);

	/*
	 *  �^�X�N��O������v��
	 */
	ercd = iras_tex(TASK2, 0x0010);
	check_ercd(ercd, E_OK);
	ercd = iras_tex(TASK1, 0x0010);
	check_ercd(ercd, E_OK);
}
