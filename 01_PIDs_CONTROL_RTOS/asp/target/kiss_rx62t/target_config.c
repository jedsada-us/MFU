/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005-2007 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2008-2010 by Witz Corporation, JAPAN
 *
 *  ��L���쌠�҂́CFree Software Foundation �ɂ���Č��\����Ă���
 *  GNU General Public License �� Version 2 �ɋL�q����Ă���������C��
 *  ����(1)�`(4)�̏����𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F�A�i�{�\�t�g�E�F
 *  �A�����ς������̂��܂ށD�ȉ������j���g�p�E�����E���ρE�Ĕz�z�i�ȉ��C
 *  ���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
 *  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
 *      ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
 *      �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
 *  (2) �{�\�t�g�E�F�A���ė��p�\�ȃo�C�i���R�[�h�i�����P�[�^�u���I�u
 *      �W�F�N�g�t�@�C���⃉�C�u�����Ȃǁj�̌`�ŗ��p����ꍇ�ɂ́C���p
 *      �ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C
 *      ���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *  (3) �{�\�t�g�E�F�A���ė��p�s�\�ȃo�C�i���R�[�h�̌`�܂��͋@��ɑg
 *      �ݍ��񂾌`�ŗ��p����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂������ƁD
 *    (a) ���p�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒���
 *        ���\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *    (b) ���p�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āC��L���쌠�҂ɕ񍐂���
 *        ���ƁD
 *  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
 *      �Q������C��L���쌠�҂�Ɛӂ��邱�ƁD
 *
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂́C
 *  �{�\�t�g�E�F�A�Ɋւ��āC���̓K�p�\�����܂߂āC�����Ȃ�ۏ؂��s��
 *  �Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ�������
 *  ���Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC�𕉂�Ȃ��D
 *
 */

/*
 *	�^�[�Q�b�g�V�X�e���ˑ����W���[���iStarter Kit�p�j
 */

#include "kernel_impl.h"
#include <sil.h>
#include "kiss_rx62t_config.h"
#include "rx600/rx600_serial.h"

/*
 *  �^�[�Q�b�g�V�X�e���ˑ� ���������[�`��
 */
void
target_initialize( void )
{
	/*
	 *  �v���Z�b�T�ˑ��̏�����
	 */
	prc_initialize();

	/*
	 *  �|�[�g�̐ݒ�
	 */
	rx600_serial_init( TARGET_PUTC_PORTID, SERIAL_BAUDRATE, SERIAL_CLKSRC );

	/* �|�[�gPB2��TxD0, �|�[�gPB1��RxD0�� */
	/* �f�[�^�f�B���N�V�������W�X�^(DDR)�̐ݒ� PB1(RxD0)����̓|�[�g�ɂ��� */
	sil_wrb_mem((void *)(PORTB_DDR_ADDR) ,
					sil_reb_mem((void *)(PORTB_DDR_ADDR)) & ~PORT_DDR_B1_BIT);
	/* ICR���W�X�^�̑Ή�����r�b�g��L���ɂ��� */
	sil_wrb_mem((void *)(PORTB_ICR_ADDR) ,
					sil_reb_mem((void *)(PORTB_ICR_ADDR)) | PORT_ICR_B1_BIT);

	/* �f�[�^�f�B���N�V�������W�X�^(DDR)�̐ݒ� PB2(TxD0)���o�̓|�[�g�ɂ��� */
	sil_wrb_mem((void *)(PORTB_DDR_ADDR) ,
					sil_reb_mem((void *)(PORTB_DDR_ADDR)) | PORT_DDR_B2_BIT);

	/* Externeal interrupt IRQ2 */
	/* ICR IRQ2 PE3 input buffer */
	sil_wrb_mem((void *)(PORTE_ICR_ADDR),
					sil_reb_mem((void *)(PORTE_ICR_ADDR)) | PORT_ICR_B3_BIT);

	/* ICR IRQ2 PE3 direction control */
	sil_wrb_mem((void *)(PORTE_DDR_ADDR) ,
					sil_reb_mem((void *)(PORTE_DDR_ADDR)) & ~PORT_DDR_B3_BIT);
}


/*
 *  �^�[�Q�b�g�V�X�e���̏I�����[�`��
 */
void
target_exit( void )
{
	/*
	 *	�v���Z�b�T�ˑ��̏I������
	 */
	prc_terminate();

	while ( 1 );
}


/*
 *  �V�X�e�����O�̒჌�x���o�͂̂��߂̕����o��
 */
void
target_fput_log( char_t c )
{
	if( c == '\n' ){
	   rx600_serial_pol_putc( '\r' , TARGET_PUTC_PORTID );
	}

    rx600_serial_pol_putc( c , TARGET_PUTC_PORTID );
}


