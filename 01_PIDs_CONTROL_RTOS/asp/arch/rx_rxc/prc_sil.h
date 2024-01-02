/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
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
 *		sil.h�̃v���Z�b�T�ˑ����iRX�p�j
 */

#ifndef TOPPERS_PRC_SIL_H
#define TOPPERS_PRC_SIL_H


#ifndef TOPPERS_MACRO_ONLY
#include "prc_insn.h"


/*
 *  �S�����݋֎~
 */
Inline uint32_t
TOPPERS_disint( void )
{
	volatile uint32_t	TOPPERS_psw;

	TOPPERS_psw = current_psw();
	disint();

	return( TOPPERS_psw );
}


/*
 *  �S�����݋���
 */
Inline void
TOPPERS_enaint( uint32_t TOPPERS_psw )
{
	if( TOPPERS_psw & PSW_I_MASK ){
		enaint();
	}
}


/*
 *  �S�����݃��b�N��Ԃ̐���
 */
#define SIL_PRE_LOC		uint32_t TOPPERS_i_psw;
#define SIL_LOC_INT()	( ( void )( TOPPERS_i_psw = TOPPERS_disint() ) )
#define SIL_UNL_INT()	( TOPPERS_enaint( TOPPERS_i_psw ) )


/*
 *  �G���f�B�A���̔��]
 *
 *  �{�J�����ł̓G���f�B�A���ϊ����߂����݂��邽��,
 *  �A�[�L�e�N�`���ˑ����ɂă}�N�����㏑������.
 */
#define TOPPERS_SIL_REV_ENDIAN_UINT16( data )	\
 								rev_endian_uint16( data )
#define TOPPERS_SIL_REV_ENDIAN_UINT32( data )	\
 								rev_endian_uint32( data )


/*
 *  �������ԑ҂�
 */
extern void sil_dly_nse( ulong_t dlytim );

#endif /* TOPPERS_MACRO_ONLY */


/*
 *  �v���Z�b�T�̃G���f�B�A��
 */
#define SIL_ENDIAN_LITTLE			/* ���g���G���f�B�A�� */


#endif /* TOPPERS_PRC_SIL_H */
