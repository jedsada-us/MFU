/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2008-2010 by Witz Corporation, JAPAN
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
 */

/*
 *		kernel.h�̃v���Z�b�T�ˑ����iRX610�p�j
 *
 *  ���̃C���N���[�h�t�@�C���́Ctarget_kernel.h�i�܂��́C��������C���N
 *  ���[�h�����t�@�C���j�݂̂���C���N���[�h�����D���̃t�@�C������
 *  ���ڃC���N���[�h���Ă͂Ȃ�Ȃ��D
 */

#ifndef TOPPERS_PRC_KERNEL_H
#define TOPPERS_PRC_KERNEL_H

/*
 *  �J�[�l���{�̂��R���p�C�����邽�߂̃}�N����`
 *
 *  �{���ł�1�֐���1�I�u�W�F�N�g�t�@�C���ɃR���p�C�����邱�Ƃ��ł��Ȃ����߁C
 *  ALLFUNC�}�N�����`����D
 */
#define ALLFUNC


/*
 *  �T�|�[�g����@�\�̒�`
 */
#define TOPPERS_TARGET_SUPPORT_DIS_INT		/* dis_int���T�|�[�g���� */
#define TOPPERS_TARGET_SUPPORT_ENA_INT		/* ena_int���T�|�[�g���� */


/*
 *  �J�[�l���Ǘ��̊����ݗD��x�͈̔�
 *
 *  TMIN_INTPRI�̒�`��ύX���邱�ƂŁC�ǂ̃��x���������������ݗD��x
 *  �������̂��J�[�l���Ǘ��O�̊����݂Ƃ��邩��ύX�ł���D
 *
 *  TMIN_INTPRI�ɐݒ�ł���l�́C-7�`-1�͈̔͂ł���D�Ⴆ��TMIN_INTPRI
 *  ��-6�ɐݒ肷��ƁCNMI�ɉ����ă��x��7�̊����݂��J�[�l���Ǘ��O�ƂȂ�D
 *  TMIN_INTPRI��-7�ɐݒ肷��ƁCNMI�ȊO�ɃJ�[�l���Ǘ��O�̊����݂�
 *  �݂��Ȃ����ƂɂȂ�D
 */
#ifndef TMIN_INTPRI
#define TMIN_INTPRI		( -7 )		/* �����ݗD��x�̍ŏ��l�i�ō��l�j*/
#endif /* TMIN_INTPRI */
#define TMAX_INTPRI		( -1 )		/* �����ݗD��x�̍ő�l�i�Œ�l�j */


/*
 *  �����ݑ����̒�`
 */
#define	TA_POSEDGE		TA_EDGE			/* �|�W�e�B�u�G�b�W�g���K */
#define	TA_NEGEDGE		UINT_C( 0x04 )	/* �l�K�e�B�u�G�b�W�g���K */
#define	TA_BOTHEDGE		UINT_C( 0x08 )	/* ���G�b�W�g���K */

#define	TA_LOWLEVEL		UINT_C( 0x10 )	/* L���x�� */


/*
 *  �f�t�H���g�̊�����/��O�n���h���̗L��
 */
/*#define	OMIT_DEFAULT_INT_HANDLER*/
/*#define	OMIT_DEFAULT_EXC_HANDLER*/


#endif /* TOPPERS_PRC_KERNEL_H */
