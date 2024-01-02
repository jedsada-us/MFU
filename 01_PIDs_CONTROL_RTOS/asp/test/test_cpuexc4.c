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
 *  @(#) $Id: test_cpuexc4.c 1577 2009-05-31 14:30:51Z ertl-hiro $
 */

/* 
 *		CPU��O�����̃e�X�g(4)
 *
 * �y�e�X�g�̖ړI�z
 *
 *  �^�X�N�R���e�L�X�g�C�������b�N��ԂŔ�������CPU��O�ɂ�����V�X�e��
 *  ��Ԃ̃e�X�g�D�����ݗD��x�}�X�N��TIPM_ENAALL�C�f�B�X�p�b�`�֎~��ԁC
 *  �^�X�N��O����ԂŃe�X�g����D
 *
 * �y�e�X�g���ځz
 *
 *  ��������C�^�X�N�R���e�L�X�g�C�������b�N��ԂŔ�������CPU��O�ɂ���
 *  �āC
 *
 *	(A) CPU��O�n���h�����s�J�n����CPU���b�N�t���O���ω����Ȃ�����
 *		�I�����݃��b�N��ԂŔ�������CPU��O�ł́C�V�X�e����Ԃ𐳂�����
 *		�߂邱�Ƃ��ۏ؂���Ȃ����߁C�e�X�g�ł��Ȃ��D
 *	(B) CPU��O�n���h�����s�J�n���Ɋ����ݗD��x�}�X�N���ω����Ȃ�����
 *		�I�����݃��b�N��ԂŔ�������CPU��O�ł́C�V�X�e����Ԃ𐳂�����
 *		�߂邱�Ƃ��ۏ؂���Ȃ����߁C�e�X�g�ł��Ȃ��D
 *	(C) CPU��O�n���h�����s�J�n���Ƀf�B�X�p�b�`�֎~�t���O���ω����Ȃ�����
 *		�I�����݃��b�N��ԂŔ�������CPU��O�ł́C�V�X�e����Ԃ𐳂�����
 *		�߂邱�Ƃ��ۏ؂���Ȃ����߁C�e�X�g�ł��Ȃ��D
 *	(D) CPU��O�n���h�����s�J�n���Ƀ^�X�N��O�����֎~�t���O���ω����Ȃ�����
 *		�I�����݃��b�N��ԂŔ�������CPU��O�ł́C�V�X�e����Ԃ𐳂�����
 *		�߂邱�Ƃ��ۏ؂���Ȃ����߁C�e�X�g�ł��Ȃ��D
 *	(E) CPU��O�n���h�����^�[������CPU���b�N�t���O�����ɖ߂邱��
 *		�ICPU��O�n���h�����烊�^�[���ł���ꍇ�̂݃e�X�g����D
 *	(F) CPU��O�n���h�����^�[�����Ɋ����ݗD��x�}�X�N�����ɖ߂邱��
 *		�ICPU��O�n���h�����烊�^�[���ł���ꍇ�̂݃e�X�g����D
 *	(G) CPU��O�n���h�����^�[�����Ƀf�B�X�p�b�`�֎~�t���O���ω����Ȃ�����
 *		�ICPU��O�n���h�����烊�^�[���ł���ꍇ�̂݃e�X�g����D
 *	(H) CPU��O�n���h�����^�[�����Ƀ^�X�N��O�����֎~�t���O���ω����Ȃ�����
 *		�ICPU��O�n���h�����烊�^�[���ł���ꍇ�̂݃e�X�g����D
 *	(I) xsns_xpn��true��Ԃ�����
 *	(J) xsns_dpn��true��Ԃ�����
 *
 * �y�g�p���\�[�X�z
 *
 *	TASK1: TA_ACT�C���D��x�C�^�X�N��O�������[�`���o�^
 *	CPUEXC1: TA_NULL
 *
 * �y�e�X�g�V�[�P���X�z
 *
 *	== TASK1�i���D��x�j==
 *	1:	��Ԃ̃`�F�b�N
 *		dis_dsp()
 *		ena_tex()
 *	2:	��Ԃ̃`�F�b�N
 *		SIL_LOC_INT()
 *		RAISE_CPU_EXCEPTION
 *	== CPUEXC1 ==
 *	3:	xsns_xpn() == true			... (I)
 *		xsns_dpn() == true			... (J)
 *	4:	CPU��O�n���h�����烊�^�[���ł��Ȃ��ꍇ�́C�����ŏI��
 *	4:	���^�[��
 *	== TASK1�i�����j==
 *	5:	SIL_UNL_LOC()
 *	6:	��Ԃ̃`�F�b�N				... (E)(F)(G)(H)
 *	7:	�e�X�g�I��
 */

#include <sil.h>
#include <kernel.h>
#include <test_lib.h>
#include <t_syslog.h>
#include "kernel_cfg.h"
#include "test_cpuexc.h"

void
task1(intptr_t exinf)
{
	ER		ercd;
	SIL_PRE_LOC;

	check_point(1);
	check_state(false, false, TIPM_ENAALL, false, false, true);
	ercd = dis_dsp();
	check_ercd(ercd, E_OK);
	ercd = ena_tex();
	check_ercd(ercd, E_OK);

	check_point(2);
	check_state(false, false, TIPM_ENAALL, true, true, false);
	SIL_LOC_INT();
	RAISE_CPU_EXCEPTION;

	check_point(5);
	SIL_UNL_INT();

	check_point(6);
	check_state(false, false, TIPM_ENAALL, true, true, false);

	check_finish(7);
}

void
tex_task1(TEXPTN texptn, intptr_t exinf)
{
	check_point(0);
}

void
task2(intptr_t exinf)
{
	check_point(0);
}

void
alarm1_handler(intptr_t exinf)
{
	check_point(0);
}

void
cpuexc_handler(void *p_excinf)
{
	check_point(3);
	check_assert(xsns_xpn(p_excinf) == true);
	check_assert(xsns_dpn(p_excinf) == true);

#ifdef CANNOT_RETURN_CPUEXC
	check_finish(4);
#endif /* CANNOT_RETURN_CPUEXC */

	check_point(4);
}
