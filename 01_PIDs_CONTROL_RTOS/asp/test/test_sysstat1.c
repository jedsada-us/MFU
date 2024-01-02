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
 *  @(#) $Id: test_sysstat1.c 1652 2009-10-10 18:01:05Z ertl-hiro $
 */

/* 
 *		�V�X�e����ԂɊւ���e�X�g(1)
 *
 *  �e�X�g�V�[�P���X�F
 *
 *	== TASK1�i�D��x�F10�j==
 *	1:	������Ԃ̃`�F�b�N
 *	2:	loc_cpu() ... �V�X�e����Ԃ������_���ɕω�������
 *		chg_ipm(TMAX_INTPRI) -> E_CTX
 *	3:	unl_cpu()
 *	4:	chg_ipm(TMAX_INTPRI)
 *	5:	dis_dsp()
 *	6:	ena_tex()
 *	7:	chg_ipm(TIPM_ENAALL)
 *	8:	ena_dsp()
 *	9:	dis_tex()
 *	10:	dis_dsp() ... �^�X�N��O�������[�`�����Ăяo������
 *		chg_ipm(TMIN_INTPRI)
 *		ena_tex()
 *	11:	ras_tex(TSK_SELF, 0x0001)
 *	== TASK1�^�X�N��O�������[�`���i1��ځj==
 *	12:	������Ԃ̃`�F�b�N
 *	13:	ena_dsp() ... 3�̏�Ԃ�ω������C���^�[���Ō��ɂ��ǂ邩���ׂ�
 *		chg_ipm(TIPM_ENAALL)
 *		ena_tex()
 *		���^�[��
 *	== TASK1�i�����j==
 *	14:	�߂��Ă�����Ԃ̃`�F�b�N
 *	15:	loc_cpu() ... CPU���b�N��Ԃ̂܂܃^�X�N���I��������
 *	16:	���^�[���i���^�X�N�I���j
 *	== TASK2�i�D��x�F10�j	==
 *	17:	������Ԃ̃`�F�b�N
 *	18:	�I��
 */

#include <kernel.h>
#include <test_lib.h>
#include <t_syslog.h>
#include "kernel_cfg.h"
#include "test_sysstat1.h"

void
tex_task1(TEXPTN texptn, intptr_t exinf)
{
	ER		ercd;

	switch (texptn) {
	case 0x0001:
		check_point(12);
		check_state(false, false, TMIN_INTPRI, true, true, true);

		/*
		 *  �f�B�X�p�b�`���C�����ݗD��x�}�X�N�ύX�C�^�X�N��O��������
		 */
		check_point(13);
		ercd = ena_dsp();
		check_ercd(ercd, E_OK);
		ercd = chg_ipm(TIPM_ENAALL);
		check_ercd(ercd, E_OK);
		ercd = ena_tex();
		check_ercd(ercd, E_OK);
		check_state(false, false, TIPM_ENAALL, false, false, false);
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

	/*
	 *  ������Ԃ̃`�F�b�N
	 */
	check_point(1);
	check_state(false, false, TIPM_ENAALL, false, false, true);

	/*
	 *  CPU���b�N��Ԃ̃`�F�b�N
	 */
	check_point(2);
	ercd = loc_cpu();
	check_ercd(ercd, E_OK);
	check_state(false, true, TIPM_ENAALL, false, true, true);

	/*
	 *  �����ݗD��x�}�X�N�ύX�̃`�F�b�N
	 */
	ercd = chg_ipm(TMAX_INTPRI);
	check_ercd(ercd, E_CTX);
	check_state(false, true, TIPM_ENAALL, false, true, true);

	/*
	 *  CPU���b�N�����̃`�F�b�N
	 */
	check_point(3);
	ercd = unl_cpu();
	check_ercd(ercd, E_OK);
	check_state(false, false, TIPM_ENAALL, false, false, true);

	/*
	 *  �����ݗD��x�}�X�N�ύX�̃`�F�b�N
	 */
	check_point(4);
	ercd = chg_ipm(TMAX_INTPRI);
	check_ercd(ercd, E_OK);
	check_state(false, false, TMAX_INTPRI, false, true, true);

	/*
	 *  �f�B�X�p�b�`�֎~�̃`�F�b�N
	 */
	check_point(5);
	ercd = dis_dsp();
	check_ercd(ercd, E_OK);
	check_state(false, false, TMAX_INTPRI, true, true, true);

	/*
	 *  �^�X�N��O�������̃`�F�b�N
	 */
	check_point(6);
	ercd = ena_tex();
	check_ercd(ercd, E_OK);
	check_state(false, false, TMAX_INTPRI, true, true, false);

	/*
	 *  �����ݗD��x�}�X�N�S�����̃`�F�b�N
	 */
	check_point(7);
	ercd = chg_ipm(TIPM_ENAALL);
	check_ercd(ercd, E_OK);
	check_state(false, false, TIPM_ENAALL, true, true, false);

	/*
	 *  �f�B�X�p�b�`���̃`�F�b�N
	 */
	check_point(8);
	ercd = ena_dsp();
	check_ercd(ercd, E_OK);
	check_state(false, false, TIPM_ENAALL, false, false, false);

	/*
	 *  �^�X�N��O�����֎~�̃`�F�b�N
	 */
	check_point(9);
	ercd = dis_tex();
	check_ercd(ercd, E_OK);
	check_state(false, false, TIPM_ENAALL, false, false, true);

	/*
	 *  �f�B�X�p�b�`�֎~�C�����ݗD��x�}�X�N�ύX�C�^�X�N��O��������
	 */
	check_point(10);
	ercd = dis_dsp();
	check_ercd(ercd, E_OK);
	ercd = chg_ipm(TMIN_INTPRI);
	check_ercd(ercd, E_OK);
	ercd = ena_tex();
	check_ercd(ercd, E_OK);
	check_state(false, false, TMIN_INTPRI, true, true, false);

	/*
	 *  �^�X�N��O������v��
	 */
	check_point(11);
	ercd = ras_tex(TSK_SELF, 0x0001);
	/* �����Ń^�X�N��O�������[�`�������삷�� */
	check_ercd(ercd, E_OK);

	/*
	 *  �^�X�N��O��������̃��^�[���ɂ�茳�̏�Ԃɖ߂��Ă��邱�Ƃ�
	 *  �`�F�b�N
	 */
	check_point(14);
	check_state(false, false, TMIN_INTPRI, true, true, false);

	/*
	 *  CPU���b�N��Ԃ�
	 */
	check_point(15);
	ercd = loc_cpu();
	check_ercd(ercd, E_OK);

	/*
	 *  ���̂܂܃^�X�N�I��
	 */
	check_point(16);
}

void
task2(intptr_t exinf)
{
	/*
	 *  ������Ԃ̃`�F�b�N
	 */
	check_point(17);
	check_state(false, false, TIPM_ENAALL, false, false, true);

	check_finish(18);
}
