/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 * 
 *  Copyright (C) 2010 by Embedded and Real-Time Systems Laboratory
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
 *  $Id: test_rstr2.c 1887 2010-08-06 06:15:19Z ertl-hiro $
 */

/* 
 *		����^�X�N�̃e�X�g(2)
 *
 * �y�e�X�g�̖ړI�z
 *
 *  ras_pri�T�[�r�X�R�[���̓�����e�X�g����D
 *
 * �y�e�X�g���ځz
 *
 *	(A) ����^�X�N����ras_pri���Ăяo���C�D��x���グ��
 *		(A-1) �f�B�X�p�b�`����ԂŌĂяo�����ꍇ
 *		(A-2) �f�B�X�p�b�`�֎~��ԂŁC�ō��D�揇�ʃ^�X�N�����s��Ԃł�
 *		      ���ꍇ�ɌĂяo�����ꍇ
 *	(B) �D��x���オ��������^�X�N����ras_pri(TPRI_INI)���Ăяo���C�N��
 *      ���D��x�ɖ߂�
 *		(B-1) �N�����D��x���������D��x�̃^�X�N�����s�\�̏ꍇ�ɁC
 *		      �^�X�N�؊������N���邱�Ƃ��m�F����
 *		(B-2) �N�����D��x�Ɠ����D��x�̃^�X�N�����s�\�̏ꍇ�ɁC�^�X
 *		      �N�؊������N����Ȃ����Ƃ��m�F����
 *		(B-3) �N�����D��x�����Ⴂ�D��x�̃^�X�N�����s�\�̏ꍇ�ɁC
 *		      �^�X�N�؊������N����Ȃ����Ƃ��m�F����
 *	(C) ����^�X�N����ras_pri���Ăяo���C�N�����D��x�����Ⴂ�D��x��
 *	    �ύX���悤�Ƃ���ƁCE_ILUSE�ɂȂ邱�Ƃ��m�F����
 *
 * �y�g�p���\�[�X�z
 *
 *	TASK1: ���D��x�^�X�N�C���C���^�X�N�C�ŏ�����N��
 *	TASK2: ���D��x�^�X�N�C����^�X�N
 *	TASK3: ���D��x�^�X�N
 *
 * �y�e�X�g�V�[�P���X�z
 *
 *	== TASK1�i�D��x�F���j==
 *	1:	act_tsk(TASK2)
 *	2:	slp_tsk()
 *	== TASK2�i�D��x�F���j==
 *	3:	get_pri(TSK_SELF, &tskpri)
 *		assert(tskpri == MID_PRIORITY)
 *	4:	ras_pri(HIGH_PRIORITY)
 *	5:	get_pri(TSK_SELF, &tskpri)
 *		assert(tskpri == HIGH_PRIORITY)
 *	6:	act_tsk(TASK3)
 *	7:	ras_pri(LOW_PRIORITY) -> E_ILUSE			... (C)
 *	8:	ras_pri(TPRI_INI)							... (B-1)
 *	== TASK3�i�D��x�F���j==
 *	9:	get_pri(TASK2, &tskpri)
 *		assert(tskpri == MID_PRIORITY)
 *	10:	slp_tsk()
 *	== TASK2�i�����j==
 *	11:	dis_dsp()
 *	12:	wup_tsk(TASK3)
 *	13:	ras_pri(HIGH_PRIORITY)						... (A-2)
 *	14:	ena_dsp()
 *	15:	ras_pri(TPRI_INI)							... (B-3)
 *	== TASK3�i�����j==
 *	16:	chg_pri(TSK_SELF, LOW_PRIORITY)
 *	== TASK2�i�����j==
 *	17:	ras_pri(HIGH_PRIORITY)
 *	18:	wup_tsk(TASK1)
 *	19:	ras_pri(TPRI_INI)							... (B-2)
 *	20:	ext_tsk()
 *	== TASK1�i�����j==
 *	21: END
 */

#include <kernel.h>
#include <test_lib.h>
#include <t_syslog.h>
#include "kernel_cfg.h"
#include "test_rstr1.h"

void
task1(intptr_t exinf)
{
	ER		ercd;

	check_point(1);
	ercd = act_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(2);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_finish(21);

	check_point(0);
}

void
task2(intptr_t exinf)
{
	ER		ercd;
	PRI		tskpri;

	check_point(3);
	ercd = get_pri(TSK_SELF, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == MID_PRIORITY);

	check_point(4);
	ercd = ras_pri(HIGH_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(5);
	ercd = get_pri(TSK_SELF, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == HIGH_PRIORITY);

	check_point(6);
	ercd = act_tsk(TASK3);
	check_ercd(ercd, E_OK);

	check_point(7);
	ercd = ras_pri(LOW_PRIORITY);
	check_ercd(ercd, E_ILUSE);

	check_point(8);
	ercd = ras_pri(TPRI_INI);
	check_ercd(ercd, E_OK);

	check_point(11);
	ercd = dis_dsp();
	check_ercd(ercd, E_OK);

	check_point(12);
	ercd = wup_tsk(TASK3);
	check_ercd(ercd, E_OK);

	check_point(13);
	ercd = ras_pri(HIGH_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(14);
	ercd = ena_dsp();
	check_ercd(ercd, E_OK);

	check_point(15);
	ercd = ras_pri(TPRI_INI);
	check_ercd(ercd, E_OK);

	check_point(17);
	ercd = ras_pri(HIGH_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(18);
	ercd = wup_tsk(TASK1);
	check_ercd(ercd, E_OK);

	check_point(19);
	ercd = ras_pri(TPRI_INI);
	check_ercd(ercd, E_OK);

	check_point(20);
	ercd = ext_tsk();
	check_ercd(ercd, E_OK);

	check_point(0);
}

void
task3(intptr_t exinf)
{
	ER		ercd;
	PRI		tskpri;

	check_point(9);
	ercd = get_pri(TASK2, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == MID_PRIORITY);

	check_point(10);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(16);
	ercd = chg_pri(TSK_SELF, LOW_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(0);
}
