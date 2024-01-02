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
 *  @(#) $Id: test_mutex4.c 1696 2010-01-01 16:01:25Z ertl-hiro $
 */

/* 
 *		�~���[�e�b�N�X�̃e�X�g(4)
 *
 * �y�e�X�g�̖ړI�z
 *
 *  �D��x����~���[�e�b�N�X�ɑ΂��āCloc_mtx��unl_mtx�ɔ����D��x�̕�
 *  �X������ԗ��I�Ƀe�X�g����D�������Cchange_priority��
 *  mutex_calc_priority�̓��e�ɂ͓��ݍ��܂Ȃ��D
 *
 * �y�e�X�g���ځz
 *
 *	(A) �~���[�e�b�N�X�̃��b�N�����iloc_mtx�j�ɔ����D��x�ύX
 *		(A-1) ���b�N�����~���[�e�b�N�X�̗D��x��������^�X�N�̌��ݗD��
 *			  �x���������ꍇ�ɁC���^�X�N�̗D��x�����̗D��x����܂�
 *			  �オ�邱�ƁD�܂��C�����D��x���ł̗D�揇�ʂ��ō��ɂȂ邱
 *			  ��
 *		(A-2) ���b�N�����~���[�e�b�N�X�̗D��x��������^�X�N�̌��ݗD��
 *			  �x�Ɠ����ꍇ�ɁC���^�X�N�̗D��x���ς��Ȃ����ƁD�܂��C
 *			  �����D��x���ł̗D�揇�ʂ��ς��Ȃ�����
 *		(A-3) ���b�N�����~���[�e�b�N�X�̗D��x��������^�X�N�̌��ݗD��
 *			  �x�����Ⴂ�ꍇ�ɁC���^�X�N�̗D��x���ς��Ȃ����ƁD��
 *			  ���C�����D��x���ł̗D�揇�ʂ��ς��Ȃ�����
 *	(B) �~���[�e�b�N�X�̃��b�N���������iunl_mtx�j�ɔ������b�N��������
 * 		�^�X�N�̗D��x�ύX
 *		(B-1) ���b�N���������~���[�e�b�N�X�̏���D��x�����^�X�N�̌���
 *			  �D��x�Ɠ����ŁC�~���[�e�b�N�X�̃��b�N�����ŗD��x������
 *			  ��ׂ��ꍇ�ɁC���^�X�N�̗D��x���K�؂ɉ������邱�ƁD��
 *			  ���C�����D��x���ł̗D�揇�ʂ��ō��ɂȂ邱��
 *		(B-2) ���b�N���������~���[�e�b�N�X�̏���D��x�����^�X�N�̌���
 *			  �D��x�Ɠ����ŁC�~���[�e�b�N�X�̃��b�N�����ŗD��x���ς�
 *			  ��ׂ��łȂ��ꍇ�ɁC���^�X�N�̗D��x���ς��Ȃ����ƁD��
 *			  ���C�����D��x���ł̗D�揇�ʂ��ς��Ȃ�����
 *		(B-3) ���b�N���������~���[�e�b�N�X�̏���D��x�����^�X�N�̌���
 *			  �D��x�����Ⴂ�ꍇ�ɁC���^�X�N�̗D��x���ς��Ȃ����ƁD
 *			  �܂��C�����D��x���ł̗D�揇�ʂ��ς��Ȃ�����
 *	(C) �~���[�e�b�N�X�̃��b�N���������iunl_mtx�j�ɔ����~���[�e�b�N�X��
 *		���b�N�����^�X�N�̗D��x�ύX
 *		(C-1) �~���[�e�b�N�X�̗D��x������V���Ƀ~���[�e�b�N�X�����b�N
 *			  �����^�X�N�̌��ݗD��x���������ꍇ�ɁC���Y�^�X�N�̗D��
 *			  �x�����̗D��x����܂ŏオ�邱�ƁD�܂��C�����D��x���ł�
 *			  �D�揇�ʂ��Œ�ɂȂ邱��
 *		(C-2) �~���[�e�b�N�X�̗D��x������V���Ƀ~���[�e�b�N�X�����b�N
 *			  �����^�X�N�̌��ݗD��x�Ɠ����ꍇ�ɁC���Y�^�X�N�̗D��x��
 *			  �ς��Ȃ����ƁD�܂��C�����D��x���ł̗D�揇�ʂ��Œ�ɂ�
 *			  �邱��
 *		(C-3) �~���[�e�b�N�X�̗D��x������V���Ƀ~���[�e�b�N�X�����b�N
 *			  �����^�X�N�̌��ݗD��x�����Ⴂ�ꍇ�ɁC���Y�^�X�N�̗D��
 *			  �x���ς��Ȃ����ƁD�܂��C�����D��x���ł̗D�揇�ʂ��Œ�
 *			  �ɂȂ邱��
 *	(D) �~���[�e�b�N�X�̃��b�N�����iloc_mtx�j��E_ILUSE�G���[
 *		(D-1) ���^�X�N�̃x�[�X�D��x���C���b�N���悤�Ƃ����~���[�e�b�N
 *			  �X�̏���D��x�����������CE_ILUSE�G���[�ɂȂ邱��
 *		(D-2) ���^�X�N�̃x�[�X�D��x���C���b�N���悤�Ƃ����~���[�e�b�N
 *			  �X�̏���D��x�Ɠ�����������Ⴏ��΁C���^�X�N�̌��ݗD
 *			  ��x�������荂���Ă��CE_ILUSE�G���[�ɂȂ�Ȃ�����
 *
 * �y�e�X�g���ڂ̎������@�z
 *
 *	(A-1)
 *		���D��x�^�X�N�iTASK1�j�ɁC���D��x����~���[�e�b�N�X�iMTX2�j��
 *		���b�N�����C���D��x�ɂȂ邱�Ƃ��m�F����D�܂��C���s�\��Ԃ�
 *		���D��x�^�X�N�iTASK4�j�����C�D�揇�ʂ������Ȃ邱�Ƃ��m�F����D
 *		�f�B�X�p�b�`�֎~��ԂŎ��{����D
 *	(A-2)
 *		���D��x�^�X�N�iTASK1�j�ɁC���D��x����~���[�e�b�N�X�iMTX1�j��
 *		���b�N�����C�D��x���ς��Ȃ����Ƃ��m�F����D�܂��C���s�\��
 *		�Ԃ̒��D��x�^�X�N��2�iTASK2�CTASK3�j��p�ӂ��Ă����C�D�揇��
 *		���ς��Ȃ����Ƃ��m�F����D�f�B�X�p�b�`�֎~��ԂŎ��{����D
 *	(A-3)
 *		���D��x�^�X�N�iTASK1�j�����D��x����~���[�e�b�N�X�iMTX2�j�����b
 *		�N���č��D��x�ɂȂ��Ă����ԂŁC���D��x����~���[�e�b�N�X
 *		�iMTX1�j�����b�N�����C�D��x���ς��Ȃ����Ƃ��m�F����D�܂��C
 *		���s�\��Ԃ̍��D��x�^�X�N��2�iTASK4�CTASK5�j��p�ӂ��Ă����C
 *		�D�揇�ʂ��ς��Ȃ����Ƃ��m�F����D�f�B�X�p�b�`�֎~��ԂŎ��{
 *		����D
 *	(B-1)
 *		���D��x�^�X�N�iTASK1�j�ɍ��D��x����~���[�e�b�N�X�iMTX2�j�̂�
 *		�����b�N�����Ă����ԂŁC��������b�N���������C���D��x�ɂȂ�
 *		���Ƃ��m�F����D�܂��C���s�\��Ԃ̒��D��x�^�X�N�iTASK2�j���
 *		���C�D�揇�ʂ������Ȃ邱�Ƃ��m�F����D
 *	(B-2)
 *		���D��x�^�X�N�iTASK1�j�ɒ��D��x����~���[�e�b�N�X�iMTX1�j�̂�
 *		�����b�N�����Ă����ԂŁC��������b�N���������C�D��x���ς��
 *		�Ȃ����Ƃ��m�F����D�܂��C���s�\��Ԃ̒��D��x�^�X�N��2��
 *		�iTASK2�CTASK3�j��p�ӂ��Ă����C�D�揇�ʂ��ς��Ȃ����Ƃ��m�F
 *		����D�f�B�X�p�b�`�֎~��ԂŎ��{����D
 *	(B-3)
 *		���D��x�^�X�N�iTASK1�j�ɍ��D��x����~���[�e�b�N�X�iMTX2�j�ƒ�
 *		�D��x����~���[�e�b�N�X�iMTX1�j�����b�N�����Ă����ԂŁC���D
 *		��x����~���[�e�b�N�X�iMTX1�j�����b�N���������C�D��x���ς��
 *		�Ȃ����Ƃ��m�F����D�܂��C���s�\��Ԃ̍��D��x�^�X�N��2��
 *		�iTASK4�CTASK5�j��p�ӂ��Ă����C�D�揇�ʂ��ς��Ȃ����Ƃ��m�F
 *		����D�f�B�X�p�b�`�֎~��ԂŎ��{����D
 *	(C-1)
 *		���D��x�^�X�N�iTASK1�j�ɍ��D��x����~���[�e�b�N�X��2�iMTX2�C
 *		MTX3�j���b�N�����C�ʂ̒��D��x�^�X�N�iTASK2�j��MTX2��҂��Ă���
 *		��ԂŁCTASK1��MTX2�����b�N���������CTASK2�̗D��x�����D��x��
 *		�Ȃ邱�Ƃ��m�F����D�܂��CTASK2�̗D�揇�ʂ��CTASK1�����Ⴍ��
 *		�邱�Ƃ��m�F����D
 *	(C-2)
 *		���D��x�^�X�N�iTASK2�j�ɒ��D��x����~���[�e�b�N�X�iMTX1�j�����b
 *		�N�����C�ʂ̒��D��x�^�X�N�iTASK1�j��MTX1��҂��Ă����ԂŁC
 *		TASK2��MTX1�����b�N���������CTASK1�̗D��x�����D��x�̂܂ܕω�
 *		���Ȃ����Ƃ��m�F����D�܂��C���s�\��Ԃ̒��D��x�^�X�N������
 *		1�iTASK3�j�p�ӂ��Ă����CTASK1�̗D�揇�ʂ�TASK3�����Ⴍ�Ȃ�
 *		���Ƃ��m�F����D
 *	(C-3)
 *		���D��x�^�X�N�iTASK1�j�ɒ��D��x����~���[�e�b�N�X�iMTX1�j�ƍ�
 *		�D��x����~���[�e�b�N�X�iMTX3�j�����b�N�����C�ʂ̒��D��x�^�X
 *		�N�iTASK2�j���ʂ̍��D��x����~���[�e�b�N�X�iMTX2�j�����b�N����
 *		MTX1��҂��Ă����ԂŁCTASK1��MTX1�����b�N���������CTASK2�̗D
 *		��x�����D��x�̂܂ܕω����Ȃ����Ƃ��m�F����D�܂��CTASK2�̗D��
 *		���ʂ��CTASK1�����Ⴍ�Ȃ邱�Ƃ��m�F����D
 *	(D-1)
 *		���D��x�^�X�N�iTASK4�j�ɁC���D��x����~���[�e�b�N�X�iMTX1�j��
 *		���b�N�����CE_ILUSE�G���[�ɂȂ邱�Ƃ��m�F����D
 *	(D-2)
 *		���D��x�^�X�N�iTASK1�j�����D��x����~���[�e�b�N�X�iMTX2�j�����b
 *		�N���č��D��x�ɂȂ��Ă����ԂŁC���D��x����~���[�e�b�N�X
 *		�iMTX1�j�����b�N�����CE_ILUSE�G���[�ɂȂ�Ȃ����Ƃ��m�F����D
 *
 * �y�g�p���\�[�X�z
 *
 *	TASK1: ���D��x�^�X�N�C���C���^�X�N�C�ŏ�����N��
 *	TASK2: ���D��x�^�X�N
 *	TASK3: ���D��x�^�X�N
 *	TASK4: ���D��x�^�X�N
 *	TASK5: ���D��x�^�X�N
 *	MTX1: �~���[�e�b�N�X�iTA_CEILING�����C����͒��D��x�j
 *	MTX2: �~���[�e�b�N�X�iTA_CEILING�����C����͍��D��x�j
 *	MTX3: �~���[�e�b�N�X�iTA_CEILING�����C����͍��D��x�j
 *
 * �y�e�X�g�V�[�P���X�z
 *
 *	== TASK1�i�D��x�F���j==
 *		call(set_bit_func(bit_mutex))
 *	1:	dis_dsp()
 *	2:	act_tsk(TASK2)
 *		act_tsk(TASK4)
 *	//		���FTASK4�C���FTASK1��TASK2
 *	3:	ploc_mtx(MTX2)								... (A-1)
 *	//		���FTASK1��TASK4�C���FTASK2�CMTX2�FTASK1
 *		get_pri(TSK_SELF, &tskpri)
 *		assert(tskpri == HIGH_PRIORITY)
 *	4:	ena_dsp()
 *	5:	unl_mtx(MTX2)								... (B-1)
 *	//		���FTASK4�C���FTASK1��TASK2
 *	== TASK4�i�D��x�F���j==
 *	6:	loc_mtx(MTX1) -> E_ILUSE					... (D-1)
 *	7:	slp_tsk()
 *	//		���FTASK1��TASK2
 *	== TASK1�i�����j==
 *	8:	get_pri(TSK_SELF, &tskpri)
 *		assert(tskpri == MID_PRIORITY)
 *
 *	9:	dis_dsp()
 *	10:	rot_rdq(MID_PRIORITY)
 *	//		���FTASK2��TASK1
 *	11:	act_tsk(TASK3)
 *	//		���FTASK2��TASK1��TASK3
 *	12:	ploc_mtx(MTX1)								... (A-2)
 *	//		���FTASK2��TASK1��TASK3�CMTX1�FTASK1
 *		get_pri(TSK_SELF, &tskpri)
 *		assert(tskpri == MID_PRIORITY)
 *	13:	ena_dsp()
 *	== TASK2�i�D��x�F���j==
 *	14:	slp_tsk()
 *	//		���FTASK1��TASK3�CMTX1�FTASK1
 *	== TASK1�i�����j==
 *	15:	slp_tsk()
 *	//		���FTASK3�CMTX1�FTASK1
 *	== TASK3�i�D��x�F���j==
 *	16:	wup_tsk(TASK1)
 *	//		���FTASK3��TASK1�CMTX1�FTASK1
 *	17:	slp_tsk()
 *	//		���FTASK1�CMTX1�FTASK1
 *
 *	== TASK1�i�����j==
 *	18:	wup_tsk(TASK2)
 *	//		���FTASK1��TASK2�CMTX1�FTASK1
 *	19:	dis_dsp()
 *	20:	rot_rdq(MID_PRIORITY)
 *	//		���FTASK2��TASK1�CMTX1�FTASK1
 *	21:	wup_tsk(TASK3)
 *	//		���FTASK2��TASK1��TASK3�CMTX1�FTASK1
 *	22:	unl_mtx(MTX1)								... (B-2)
 *	//		���FTASK2��TASK1��TASK3
 *		get_pri(TSK_SELF, &tskpri)
 *		assert(tskpri == MID_PRIORITY)
 *	23:	ena_dsp()
 *	== TASK2�i�D��x�F���j==
 *	24:	slp_tsk()
 *	//		���FTASK1��TASK3
 *	== TASK1�i�����j==
 *	25:	slp_tsk()
 *	//		���FTASK3
 *	== TASK3�i�D��x�F���j==
 *	26:	wup_tsk(TASK1)
 *	//		���FTASK3��TASK1
 *	27:	slp_tsk()
 *	//		���FTASK1
 *
 *	== TASK1�i�����j==
 *	28:	dis_dsp()
 *	29:	wup_tsk(TASK4)
 *	//		���FTASK4�C���FTASK1
 *	30:	ploc_mtx(MTX2)
 *	//		���FTASK1��TASK4�CMTX2�FTASK1
 *	31:	rot_rdq(HIGH_PRIORITY)
 *	//		���FTASK4��TASK1�CMTX2�FTASK1
 *	32:	act_tsk(TASK5)
 *	//		���FTASK4��TASK1��TASK5�CMTX2�FTASK1
 *	33:	ploc_mtx(MTX1)								... (A-3)(D-2)
 *	//		���FTASK4��TASK1��TASK5�CMTX2�FTASK1�CMTX1�FTASK1
 *		get_pri(TSK_SELF, &tskpri)
 *		assert(tskpri == HIGH_PRIORITY)
 *	34:	ena_dsp()
 *	== TASK4�i�����j==
 *	35:	slp_tsk()
 *	//		���FTASK1��TASK5�CMTX2�FTASK1�CMTX1�FTASK1
 *	== TASK1�i�����j==
 *	36:	slp_tsk()
 *	//		���FTASK5�CMTX2�FTASK1�CMTX1�FTASK1
 *	== TASK5�i�D��x�F���j==
 *	37:	wup_tsk(TASK1)
 *	//		���FTASK5��TASK1�CMTX2�FTASK1�CMTX1�FTASK1
 *	38:	slp_tsk()
 *	//		���FTASK1�CMTX2�FTASK1�CMTX1�FTASK1
 *
 *	== TASK1�i�����j==
 *	39:	dis_dsp()
 *	40:	wup_tsk(TASK4)
 *	//		���FTASK1��TASK4�CMTX2�FTASK1�CMTX1�FTASK1
 *	41:	rot_rdq(HIGH_PRIORITY)
 *	//		���FTASK4��TASK1�CMTX2�FTASK1�CMTX1�FTASK1
 *	42:	wup_tsk(TASK5)
 *	//		���FTASK4��TASK1��TASK5�CMTX2�FTASK1�CMTX1�FTASK1
 *	43:	unl_mtx(MTX1)								... (B-3)
 *	//		���FTASK4��TASK1��TASK5�CMTX2�FTASK1
 *		get_pri(TSK_SELF, &tskpri)
 *		assert(tskpri == HIGH_PRIORITY)
 *	44:	ena_dsp()
 *	== TASK4�i�����j==
 *	45:	slp_tsk()
 *	//		���FTASK1��TASK5�CMTX2�FTASK1
 *	== TASK1�i�����j==
 *	46:	slp_tsk()
 *	//		���FTASK5�CMTX2�FTASK1
 *	== TASK5�i�����j==
 *	47:	wup_tsk(TASK1)
 *	//		���FTASK5��TASK1�CMTX2�FTASK1
 *	48:	slp_tsk()
 *	//		���FTASK1�CMTX2�FTASK1
 *
 *	== TASK1�i�����j==
 *	49:	wup_tsk(TASK2)
 *		wup_tsk(TASK3)
 *		slp_tsk()
 *	//		���FTASK2��TASK3�CMTX2�FTASK1
 *	== TASK2�i�����j==
 *	50:	loc_mtx(MTX2)
 *	//		���FTASK3�CMTX2�FTASK1��TASK2
 *	== TASK3�i�����j==
 *	51:	wup_tsk(TASK1)
 *	//		���FTASK1�C���FTASK3�CMTX2�FTASK1��TASK2
 *	== TASK1�i�����j==
 *	52:	loc_mtx(MTX3)
 *	//		���FTASK1�C���FTASK3�CMTX2�FTASK1��TASK2�CMTX3�FTASK1
 *	53:	unl_mtx(MTX2)								... (C-1)
 *	//		���FTASK1��TASK2�C���FTASK3�CMTX2�FTASK2�CMTX3�FTASK1
 *		get_pri(TASK2, &tskpri)
 *		assert(tskpri == HIGH_PRIORITY)
 *	54:	loc_mtx(MTX1)
 *	//		���FTASK1��TASK2�C���FTASK3�CMTX1�FTASK1�CMTX2�FTASK2�CMTX3�FTASK1
 *	55:	slp_tsk()
 *	//		���FTASK2�C���FTASK3�CMTX1�FTASK1�CMTX2�FTASK2�CMTX3�FTASK1
 *
 *	== TASK2�i�����j==
 *	56:	wup_tsk(TASK1)
 *	//		���FTASK2��TASK1�C���FTASK3�CMTX1�FTASK1�CMTX2�FTASK2�CMTX3�FTASK1
 *	57:	loc_mtx(MTX1)
 *	//		���FTASK1�C���FTASK3�CMTX1�FTASK1��TASK2�CMTX2�FTASK2�CMTX3�FTASK1
 *	== TASK1�i�����j==
 *	58:	unl_mtx(MTX1)								... (C-3)
 *	//		���FTASK1��TASK2�C���FTASK3�CMTX1�FTASK2�CMTX2�FTASK2�CMTX3�FTASK1
 *		get_pri(TASK2, &tskpri)
 *		assert(tskpri == HIGH_PRIORITY)
 *	59:	unl_mtx(MTX3)
 *	//		���FTASK2�C���FTASK1��TASK3�CMTX1�FTASK2�CMTX2�FTASK2
 *	== TASK2�i�����j==
 *	60:	unl_mtx(MTX2)
 *	//		���FTASK2��TASK1��TASK3�CMTX1�FTASK2
 *
 *	61:	rot_rdq(MID_PRIORITY)
 *	//		���FTASK1��TASK3��TASK2�CMTX1�FTASK2
 *	== TASK1�i�����j==
 *	62:	loc_mtx(MTX1)
 *	//		���FTASK3��TASK2�CMTX1�FTASK2��TASK1
 *	== TASK3�i�����j==
 *	63:	rot_rdq(MID_PRIORITY)
 *	//		���FTASK2��TASK3�CMTX1�FTASK2��TASK1
 *	== TASK2�i�����j==
 *	64:	unl_mtx(MTX1)								... (C-2)
 *	//		���FTASK2��TASK3��TASK1�CMTX1�FTASK1
 *		get_pri(TASK1, &tskpri)
 *		assert(tskpri == MID_PRIORITY)
 *	== TASK2�i�����j==
 *	65:	ext_tsk() -> noreturn
 *	//		���FTASK3��TASK1�CMTX1�FTASK1
 *	== TASK3�i�����j==
 *	66:	ext_tsk() -> noreturn
 *	//		���FTASK1�CMTX1�FTASK1
 *	== TASK1�i�����j==
 *	67:	END
 */

#include <kernel.h>
#include <t_syslog.h>
#include "syssvc/logtask.h"
#include "kernel_cfg.h"
#include "test_lib.h"
#include "test_mutex4.h"

extern ER	bit_mutex(void);

void
task1(intptr_t exinf)
{
	ER		ercd;
	PRI		tskpri;

	set_bit_func(bit_mutex);

	check_point(1);
	ercd = dis_dsp();
	check_ercd(ercd, E_OK);

	check_point(2);
	ercd = act_tsk(TASK2);
	check_ercd(ercd, E_OK);

	ercd = act_tsk(TASK4);
	check_ercd(ercd, E_OK);

	check_point(3);
	ercd = ploc_mtx(MTX2);
	check_ercd(ercd, E_OK);

	ercd = get_pri(TSK_SELF, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == HIGH_PRIORITY);

	check_point(4);
	ercd = ena_dsp();
	check_ercd(ercd, E_OK);

	check_point(5);
	ercd = unl_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(8);
	ercd = get_pri(TSK_SELF, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == MID_PRIORITY);

	check_point(9);
	ercd = dis_dsp();
	check_ercd(ercd, E_OK);

	check_point(10);
	ercd = rot_rdq(MID_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(11);
	ercd = act_tsk(TASK3);
	check_ercd(ercd, E_OK);

	check_point(12);
	ercd = ploc_mtx(MTX1);
	check_ercd(ercd, E_OK);

	ercd = get_pri(TSK_SELF, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == MID_PRIORITY);

	check_point(13);
	ercd = ena_dsp();
	check_ercd(ercd, E_OK);

	check_point(15);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(18);
	ercd = wup_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(19);
	ercd = dis_dsp();
	check_ercd(ercd, E_OK);

	check_point(20);
	ercd = rot_rdq(MID_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(21);
	ercd = wup_tsk(TASK3);
	check_ercd(ercd, E_OK);

	check_point(22);
	ercd = unl_mtx(MTX1);
	check_ercd(ercd, E_OK);

	ercd = get_pri(TSK_SELF, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == MID_PRIORITY);

	check_point(23);
	ercd = ena_dsp();
	check_ercd(ercd, E_OK);

	check_point(25);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(28);
	ercd = dis_dsp();
	check_ercd(ercd, E_OK);

	check_point(29);
	ercd = wup_tsk(TASK4);
	check_ercd(ercd, E_OK);

	check_point(30);
	ercd = ploc_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(31);
	ercd = rot_rdq(HIGH_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(32);
	ercd = act_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(33);
	ercd = ploc_mtx(MTX1);
	check_ercd(ercd, E_OK);

	ercd = get_pri(TSK_SELF, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == HIGH_PRIORITY);

	check_point(34);
	ercd = ena_dsp();
	check_ercd(ercd, E_OK);

	check_point(36);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(39);
	ercd = dis_dsp();
	check_ercd(ercd, E_OK);

	check_point(40);
	ercd = wup_tsk(TASK4);
	check_ercd(ercd, E_OK);

	check_point(41);
	ercd = rot_rdq(HIGH_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(42);
	ercd = wup_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(43);
	ercd = unl_mtx(MTX1);
	check_ercd(ercd, E_OK);

	ercd = get_pri(TSK_SELF, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == HIGH_PRIORITY);

	check_point(44);
	ercd = ena_dsp();
	check_ercd(ercd, E_OK);

	check_point(46);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(49);
	ercd = wup_tsk(TASK2);
	check_ercd(ercd, E_OK);

	ercd = wup_tsk(TASK3);
	check_ercd(ercd, E_OK);

	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(52);
	ercd = loc_mtx(MTX3);
	check_ercd(ercd, E_OK);

	check_point(53);
	ercd = unl_mtx(MTX2);
	check_ercd(ercd, E_OK);

	ercd = get_pri(TASK2, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == HIGH_PRIORITY);

	check_point(54);
	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(55);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(58);
	ercd = unl_mtx(MTX1);
	check_ercd(ercd, E_OK);

	ercd = get_pri(TASK2, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == HIGH_PRIORITY);

	check_point(59);
	ercd = unl_mtx(MTX3);
	check_ercd(ercd, E_OK);

	check_point(62);
	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_finish(67);

	check_point(0);
}

void
task2(intptr_t exinf)
{
	ER		ercd;
	PRI		tskpri;

	check_point(14);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(24);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(50);
	ercd = loc_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(56);
	ercd = wup_tsk(TASK1);
	check_ercd(ercd, E_OK);

	check_point(57);
	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(60);
	ercd = unl_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(61);
	ercd = rot_rdq(MID_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(64);
	ercd = unl_mtx(MTX1);
	check_ercd(ercd, E_OK);

	ercd = get_pri(TASK1, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == MID_PRIORITY);

	check_point(65);
	ercd = ext_tsk();

	check_point(0);
}

void
task3(intptr_t exinf)
{
	ER		ercd;

	check_point(16);
	ercd = wup_tsk(TASK1);
	check_ercd(ercd, E_OK);

	check_point(17);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(26);
	ercd = wup_tsk(TASK1);
	check_ercd(ercd, E_OK);

	check_point(27);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(51);
	ercd = wup_tsk(TASK1);
	check_ercd(ercd, E_OK);

	check_point(63);
	ercd = rot_rdq(MID_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(66);
	ercd = ext_tsk();

	check_point(0);
}

void
task4(intptr_t exinf)
{
	ER		ercd;

	check_point(6);
	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_ILUSE);

	check_point(7);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(35);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(45);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(0);
}

void
task5(intptr_t exinf)
{
	ER		ercd;

	check_point(37);
	ercd = wup_tsk(TASK1);
	check_ercd(ercd, E_OK);

	check_point(38);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(47);
	ercd = wup_tsk(TASK1);
	check_ercd(ercd, E_OK);

	check_point(48);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(0);
}
