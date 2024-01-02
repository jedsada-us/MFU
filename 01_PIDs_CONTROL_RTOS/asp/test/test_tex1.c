/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 * 
 *  Copyright (C) 2006-2009 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: test_tex1.c 1577 2009-05-31 14:30:51Z ertl-hiro $
 */

/* 
 *		�^�X�N��O�����Ɋւ���e�X�g(1)
 *
 * �y�e�X�g�̖ړI�z
 *
 *  �^�X�N����^�X�N��O�������[�`�����N�����鏈����ԗ��I�Ƀe�X�g����D
 *
 * �y�e�X�g���ځz
 *
 *	(A) ras_tex�Cref_tex�̃G���[���o
 *		(A-1) �Ώۃ^�X�N���x�~���
 *		(A-2) �Ώۃ^�X�N�̃^�X�N��O�������[�`������`����Ă��Ȃ�
 *	(B) dis_tex�Cena_tex�̃G���[���o
 *		(B-1) ���^�X�N�̃^�X�N��O�������[�`������`����Ă��Ȃ�
 *	(C) ras_tex�̐��폈��
 *		(C-1) �Ώۃ^�X�N�����^�X�N���^�X�N��O�������ŁC�����ɋN��
 *		(C-2) �Ώۃ^�X�N�����^�X�N�łȂ�
 *		(C-3) �Ώۃ^�X�N�����^�X�N�����^�X�N��O�����֎~
 *	(D) ena_tex�̐��폈��
 *		(D-1) �^�X�N��O�����v��������C�����ɋN��
 *		(D-2) �^�X�N��O�����v�����Ȃ�
 *	(E) �^�X�N�f�B�X�p�b�`���ɂ��N��
 *		(E-1) �f�B�X�p�b�`��̃^�X�N���^�X�N��O���Ń^�X�N��O�����v
 *			  ������
 *	(F) �^�X�N��O�������[�`������̃��^�[���ɂ��N���i�A���N���j
 *	(G) �^�X�N��O�������[�`������̖߂莞�ɂ���ԕ��A
 *		(G-1) �^�X�N�ɖ߂��Ă��鎞
 *		(G-2) �^�X�N��O�������[�`�����A���N������鎞
 *	(H) �^�X�N��O�������[�`���̑��d�N��
 *	(I) �^�X�N��O�������[�`������̖߂莞�̃^�X�N�؊���
 *
 * �y�g�p���\�[�X�z
 *
 *	TASK1: ���C���̃^�X�N�D���^�X�N�ɑ΂��ă^�X�N��O������v������
 *	TASK2: ���^�X�N�ɑ΂��ă^�X�N��O������v������Ώۃ^�X�N
 *	TASK3: �^�X�N��O�������[�`������`����Ă��Ȃ��^�X�N
 *	TASK4: �x�~��Ԃ̃^�X�N
 *
 * �y�e�X�g�V�[�P���X�z
 *
 *	== TASK1�i�D��x�F10�j==
 *	1:	������Ԃ̃`�F�b�N
 *		ref_tex(TSK_SELF, &rtex)
 *		ras_tex(TASK3, 0x0001)		... (A-2)
 *		ras_tex(TASK4, 0x0001)		... (A-1)
 *		ref_tex(TASK3, &rtex)		... (A-2)
 *		ref_tex(TASK4, &rtex)		... (A-1)
 *	2:	ena_tex()					... (D-2)
 *		ref_tex(TSK_SELF, &rtex)
 *	3:	ras_tex(TSK_SELF, 0x0001)	... (C-1)
 *	== TASK1�^�X�N��O�������[�`���i1��ځj==
 *	4:	������Ԃ̃`�F�b�N
 *	5:	dis_dsp() ... 4�̏�Ԃ����ꂼ��ω�������
 *		chg_ipm(TMAX_INTPRI)
 *		ena_tex()
 *		loc_cpu()
 *		���^�[��
 *	== TASK1�i�����j==
 *	6:	�߂��Ă�����Ԃ̃`�F�b�N	... (G-1)
 *	7:	dis_dsp() ... 3�̏�Ԃ����ꂼ��ω�������
 *		chg_ipm(TMIN_INTPRI)
 *		dis_tex()
 *	8:	ras_tex(TASK1, 0x0002)		... (C-3)
 *		ref_tex(TSK_SELF, &rtex)
 *	9:	ena_tex()					... (D-1)
 *	== TASK1�^�X�N��O�������[�`���i2��ځj==
 *	10:	������Ԃ̃`�F�b�N
 *	11:	ras_tex(TASK1, 0x0001)		... (C-3)
 *		ras_tex(TASK1, 0x0002)		... (C-3)
 *	12:	ena_dsp() ... 3�̏�Ԃ����ꂼ��ω�������
 *		chg_ipm(TMAX_INTPRI)
 *		loc_cpu()
 *		���^�[��					... (F)
 *	== TASK1�^�X�N��O�������[�`���i3��ځj==
 *	13:	������Ԃ̃`�F�b�N
 *	14:	ena_dsp() ... 3�̏�Ԃ����ꂼ��ω�������
 *		chg_ipm(TMAX_INTPRI)
 *		ena_tex()
 *	15: ras_tex(TSK_SELF, 0x0004)	... (H)
 *	== TASK1�^�X�N��O�������[�`���i4��ځj==
 *	16:	������Ԃ̃`�F�b�N
 *	17:	dis_dsp() ... 3�̏�Ԃ����ꂼ��ω�������
 *		chg_ipm(TIPM_ENAALL)
 *		loc_cpu()
 *		���^�[��
 *	== TASK1�^�X�N��O�������[�`���i3��ڑ����j==
 *	18:	�߂��Ă�����Ԃ̃`�F�b�N	... (G-2)
 *		���^�[��
 *	== TASK1�i�����j==
 *	19:	�߂��Ă�����Ԃ̃`�F�b�N	... (G-1)
 *	20: ena_dsp()
 *		chg_ipm(TIPM_ENAALL)
 *		rot_rdq(TPRI_SELF)
 *	== TASK2�i�D��x�F10�j	==
 *	21:	������Ԃ̃`�F�b�N
 *	22:	ena_tex()
 *		rot_rdq(TPRI_SELF)
 *	== TASK3�i�D��x�F10�j	==
 *	23:	������Ԃ̃`�F�b�N
 *	24:	ena_tex()
 *	25:	dis_tex()					... (B-1)
 *		ext_tsk()					... (B-1)
 *	== TASK1�i�����j==
 *	26: ras_tex(TASK2, 0x0001)		... (C-2)
 *		ref_tex(TASK2, &rtex)
 *	27:	rot_rdq(TPRI_SELF)			... (E-1)
 *	== TASK2�^�X�N��O�������[�`���i1��ځj==
 *	28:	������Ԃ̃`�F�b�N
 *		���^�[��
 *	== TASK2�i�����j==
 *	29: ras_tex(TSK_SELF, 0x0002)
 *	== TASK2�^�X�N��O�������[�`���i2��ځj==
 *	30:	������Ԃ̃`�F�b�N
 *	31:	dis_dsp
 *		rot_rdq(TPRI_SELF)
 *	32:	���^�[��					... (I)
 *	== TASK1�i�����j==
 *	33:	���^�[���i�^�X�N�I���j
 *	== TASK2�i�����j==
 *	34:	�e�X�g�I��
 */

#include <kernel.h>
#include <test_lib.h>
#include <t_syslog.h>
#include "kernel_cfg.h"
#include "test_tex1.h"

void
tex_task1(TEXPTN texptn, intptr_t exinf)
{
	ER		ercd;

	switch (texptn) {
	case 0x0001:
		check_point(4);
		check_state(false, false, TIPM_ENAALL, false, false, true);

		/*
		 *  �f�B�X�p�b�`�֎~�C�����ݗD��x�}�X�N�ύX�C�^�X�N��O��������
		 */
		check_point(5);
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
		check_state(false, false, TMIN_INTPRI, true, true, true);

		/*
		 *  �^�X�N��O������v��
		 */
		check_point(11);
		ercd = ras_tex(TSK_SELF, 0x0001);
		check_ercd(ercd, E_OK);
		ercd = ras_tex(TSK_SELF, 0x0002);
		check_ercd(ercd, E_OK);

		/*
		 *  �f�B�X�p�b�`���C�����ݗD��x�}�X�N�ύX�CCPU���b�N
		 */
		check_point(12);
		ercd = ena_dsp();
		check_ercd(ercd, E_OK);
		ercd = chg_ipm(TMAX_INTPRI);
		check_ercd(ercd, E_OK);
		ercd = loc_cpu();
		check_ercd(ercd, E_OK);
		check_state(false, true, TMAX_INTPRI, false, true, true);
		break;

	case 0x0003:
		check_point(13);
		check_state(false, false, TMIN_INTPRI, true, true, true);

		/*
		 *  �f�B�X�p�b�`���C�����ݗD��x�}�X�N�ύX�C�^�X�N��O����
		 */
		check_point(14);
		ercd = ena_dsp();
		check_ercd(ercd, E_OK);
		ercd = chg_ipm(TMAX_INTPRI);
		check_ercd(ercd, E_OK);
		ercd = ena_tex();
		check_ercd(ercd, E_OK);
		check_state(false, false, TMAX_INTPRI, false, true, false);

		/*
		 *  �^�X�N��O������v��
		 */
		check_point(15);
		ercd = ras_tex(TSK_SELF, 0x0004);
		/* �����Ń^�X�N��O�������[�`�������삷�� */
		check_ercd(ercd, E_OK);

		/*
		 *  �^�X�N��O��������̃��^�[���ɂ�茳�̏�Ԃɖ߂��Ă��邱��
		 *  ���`�F�b�N
		 */
		check_point(18);
		check_state(false, false, TMAX_INTPRI, false, true, false);
		break;

	case 0x0004:
		check_point(16);
		check_state(false, false, TMAX_INTPRI, false, true, true);

		/*
		 *  �f�B�X�p�b�`�֎~�C�����ݗD��x�}�X�N�ύX�CCPU���b�N
		 */
		check_point(17);
		ercd = dis_dsp();
		check_ercd(ercd, E_OK);
		ercd = chg_ipm(TIPM_ENAALL);
		check_ercd(ercd, E_OK);
		ercd = loc_cpu();
		check_ercd(ercd, E_OK);
		check_state(false, true, TIPM_ENAALL, true, true, true);
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
	 *  ras_tex�̃G���[���o
	 */
	ercd = ras_tex(TASK3, 0x0001);
	check_ercd(ercd, E_OBJ);
	ercd = ras_tex(TASK4, 0x0001);
	check_ercd(ercd, E_OBJ);

	/*
	 *  ref_tex�̃G���[���o
	 */
	ercd = ref_tex(TASK3, &rtex);
	check_ercd(ercd, E_OBJ);
	ercd = ref_tex(TASK4, &rtex);
	check_ercd(ercd, E_OBJ);

	/*
	 *  �^�X�N��O�����̋���
	 */
	check_point(2);
	ercd = ena_tex();
	check_ercd(ercd, E_OK);
	check_state(false, false, TIPM_ENAALL, false, false, false);
	ercd = ref_tex(TSK_SELF, &rtex);
	check_ercd(ercd, E_OK);
	check_assert((rtex.texstat & TTEX_ENA) != 0);
	check_assert(rtex.pndptn == 0);

	/*
	 *  �^�X�N��O������v��
	 */
	check_point(3);
	ercd = ras_tex(TSK_SELF, 0x0001);
	/* �����Ń^�X�N��O�������[�`�������삷�� */
	check_ercd(ercd, E_OK);

	/*
	 *  �^�X�N��O��������̃��^�[���ɂ�茳�̏�Ԃɖ߂��Ă��邱�Ƃ�
	 *  �`�F�b�N
	 */
	check_point(6);
	check_state(false, false, TIPM_ENAALL, false, false, false);

	/*
	 *  �f�B�X�p�b�`�֎~�C�����ݗD��x�}�X�N�ύX�C�^�X�N��O�����֎~
	 */
	check_point(7);
	ercd = dis_dsp();
	check_ercd(ercd, E_OK);
	ercd = chg_ipm(TMIN_INTPRI);
	check_ercd(ercd, E_OK);
	ercd = dis_tex();
	check_ercd(ercd, E_OK);
	check_state(false, false, TMIN_INTPRI, true, true, true);

	/*
	 *  �^�X�N��O������v��
	 */
	check_point(8);
	ercd = ras_tex(TASK1, 0x0002);
	check_ercd(ercd, E_OK);
	ercd = ref_tex(TSK_SELF, &rtex);
	check_ercd(ercd, E_OK);
	check_assert((rtex.texstat & TTEX_DIS) != 0);
	check_assert(rtex.pndptn == 0x0002);

	/*
	 *  �^�X�N��O����������
	 */
	check_point(9);
	ercd = ena_tex();
	/* �����Ń^�X�N��O�������[�`�������삷�� */
	check_ercd(ercd, E_OK);

	/*
	 *  �^�X�N��O��������̃��^�[���ɂ�茳�̏�Ԃɖ߂��Ă��邱�Ƃ�
	 *  �`�F�b�N
	 */
	check_point(19);
	check_state(false, false, TMIN_INTPRI, true, true, false);

	/*
	 *  �^�X�N2�ɐ؂芷����
	 */
	check_point(20);
	ercd = ena_dsp();
	check_ercd(ercd, E_OK);
	ercd = chg_ipm(TIPM_ENAALL);
	check_ercd(ercd, E_OK);
	ercd = rot_rdq(TPRI_SELF);
	/* �����ő��̃^�X�N�����삷�� */
	check_ercd(ercd, E_OK);

	/*
	 *  �^�X�N2�ɑ΂��ă^�X�N��O������v��
	 */
	check_point(26);
	ercd = ras_tex(TASK2, 0x0001);
	check_ercd(ercd, E_OK);
	ercd = ref_tex(TASK2, &rtex);
	check_ercd(ercd, E_OK);
	check_assert((rtex.texstat & TTEX_ENA) != 0);
	check_assert(rtex.pndptn == 0x0001);

	/*
	 *  �^�X�N2�ɐ؂芷����
	 */
	check_point(27);
	ercd = rot_rdq(TPRI_SELF);
	/* �����ő��̃^�X�N�����삷�� */
	check_ercd(ercd, E_OK);

	/*
	 *  �^�X�N�I��
	 */
	check_point(33);
}

void
tex_task2(TEXPTN texptn, intptr_t exinf)
{
	ER		ercd;

	switch (texptn) {
	case 0x0001:
		check_point(28);
		check_state(false, false, TIPM_ENAALL, false, false, true);
		break;

	case 0x0002:
		check_point(30);
		check_state(false, false, TIPM_ENAALL, false, false, true);

		/*
		 *  �f�B�X�p�b�`���֎~���āC�^�X�N�؊�����v������D
		 */
		check_point(31);
		ercd = dis_dsp();
		check_ercd(ercd, E_OK);
		ercd = rot_rdq(TPRI_SELF);
		check_ercd(ercd, E_OK);

		/*
		 *  �^�X�N��O�������[�`������̃��^�[���ŁC�^�X�N�؊���������
		 *  ����D
		 */
		check_point(32);
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
	 *  �^�X�N��O�����̋���
	 */
	check_point(22);
	ercd = ena_tex();
	check_ercd(ercd, E_OK);
	check_state(false, false, TIPM_ENAALL, false, false, false);

	/*
	 *  �^�X�N3�ɐ؂芷����
	 */
	ercd = rot_rdq(TPRI_SELF);
	/* �����ő��̃^�X�N�����삷�� */
	check_ercd(ercd, E_OK);

	/*
	 *  �^�X�N��O������v��
	 */
	check_point(29);
	ercd = ras_tex(TSK_SELF, 0x0002);
	/* �����Ń^�X�N��O�������[�`�������삷�� */
	check_ercd(ercd, E_OK);

	/*
	 *  �e�X�g�I��
	 */
	check_finish(34);
}

void
task3(intptr_t exinf)
{
	ER		ercd;

	/*
	 *  ������Ԃ̃`�F�b�N
	 */
	check_point(23);
	check_state(false, false, TIPM_ENAALL, false, false, true);

	/*
	 *  �^�X�N��O�����̋���
	 */
	check_point(24);
	ercd = ena_tex();
	check_ercd(ercd, E_OBJ);
	check_state(false, false, TIPM_ENAALL, false, false, true);

	/*
	 *  �^�X�N��O�����̋֎~
	 */
	check_point(25);
	ercd = dis_tex();
	check_ercd(ercd, E_OBJ);
	check_state(false, false, TIPM_ENAALL, false, false, true);

	/*
	 *  �^�X�N�I��
	 */
	ercd = ext_tsk();
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
