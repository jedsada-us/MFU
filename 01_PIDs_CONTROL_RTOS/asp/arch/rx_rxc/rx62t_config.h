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
 *		�v���Z�b�T�ˑ����W���[���iRX62T�p�j
 *
 *  ���̃C���N���[�h�t�@�C���́Ctarget_config.h�i�܂��́C��������C���N
 *  ���[�h�����t�@�C���j�݂̂���C���N���[�h�����D���̃t�@�C������
 *  ���ڃC���N���[�h���Ă͂Ȃ�Ȃ��D
 */


#ifndef TOPPERS_RX62T_CONFIG_H
#define TOPPERS_RX62T_CONFIG_H


/*
 *  �����ݗv����
 */
#define	INHNO_MAX	UINT_C( 256 )


/*
 *  �����ݐ���p�^��`
 */
typedef struct ier_info {
	volatile uint8_t __evenaccess	*addr;
			 uint8_t				offset;
} IER_INFO;


/*
 *  �����ݐ���p��`
 */
#define	INVALID_OFFSET				( 0xFFU )
#define	INTNO_IRQ( intno )			( ( 64U <= ( intno ) ) && ( ( intno ) <= 79U ) )
#define	INTNO_IRQ_OFFSET( intno )	( ( intno ) - 64U )
#define	IRQ_MAX						UINT_C( 8 )

#define IR_TOP						(0x00087010)
#define IR_REG( intno )				((volatile uint8_t __evenaccess * )(IR_TOP + (intno)))

/*
 *  �����ݐ���p�e�[�u��
 */

/* �����ݗv���v���C�I���e�B���W�X�^�A�h���X */
extern volatile uint8_t __evenaccess * const ipr_reg_addr[];
/* �����ݗv�������W�X�^�A�h���X */
extern const IER_INFO ier_reg_addr[];
/* �����ݗv�����W�X�^�A�h���X */
extern volatile uint8_t __evenaccess * const ir_reg_addr[];
/* IRQ�R���g���[�����W�X�^�A�h���X */
extern volatile uint8_t __evenaccess * const irqcr_reg_addr[];


/*
 *  �v���Z�b�T�ˑ����W���[���iRX�p�j
 */
#include "rx_rxc/prc_config.h"

#endif	/* TOPPERS_RX62T_CONFIG_H */

