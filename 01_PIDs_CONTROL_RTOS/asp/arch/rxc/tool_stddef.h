/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004-2006 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2007-2010 by Witz Corporation, JAPAN
 * 
 *  ��L���쌠�҂́C�ȉ��� (1)�`(4) �̏������CFree Software Foundation 
 *  �ɂ���Č��\����Ă��� GNU General Public License �� Version 2 �ɋL
 *  �q����Ă�������𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F�A�i�{�\�t�g�E�F�A
 *  �����ς������̂��܂ށD�ȉ������j���g�p�E�����E���ρE�Ĕz�z�i�ȉ��C
 *  ���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
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
 * 
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
 *  ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC���̓K�p�\����
 *  �܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p�ɂ�蒼
 *  �ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC�𕉂�Ȃ��D
 * 
 */

/*
 *  t_stddef.h�̊J�����ˑ����i���l�T�X RX�c�[���`�F�C���p�j
 *
 *  ���̃C���N���[�h�t�@�C���́Ct_stddef.h �̐擪�ŃC���N���[�h�����D
 *  ���̃t�@�C������͒��ڃC���N���[�h���邱�Ƃ͂Ȃ��D���̃C���N���[�h
 *  �t�@�C���ɐ旧���ď�������邽�߁C���̃C���N���[�h�t�@�C���Ɉˑ���
 *  �Ă͂Ȃ�Ȃ��D
 */

#if !defined( TOPPERS_TOOL_STDDEF_H )
#define TOPPERS_TOOL_STDDEF_H

/*
 *  �R���p�C���̊g���@�\�̂��߂̃}�N����`
 */
/*
 *  inline ���ʎq�͊O����`�𐶐����Ȃ�.
 */
#define	Inline		static inline

/*
 *  �C�����C���A�Z���u���͖{�R���p�C���ł�
 *  #pragma inline_asm�݂̂̃T�|�[�g�ƂȂ邽��,
 *  asm/Asm��`�͍s��Ȃ�.
 */

/*
 *  NoReturn / alignof�͖{�R���p�C���ł̓T�|�[�g����Ȃ�.
 *  offsetof��stddef.h�̒�`�𗘗p����.
 */
#define	NoReturn


/*
 *  �J�����̕W���C���N���[�h�t�@�C���̗��p
 *
 *  NULL�̒�`��stddef.h����CINT_MAX�CINT_MIN�CUINT_MAX�CLONG_MAX�C
 *  LONG_MIN�CULONG_MAX�CCHAR_BIT�̒�`��limits.h�����荞�ށD
 *
 *  C++/EC++�ł́C�W���d�l��͂����̃C���N���[�h�t�@�C�����p�ӂ����
 *  ����Ƃ͌���Ȃ��̂Œ��ӂ��K�v�ł���i�قƂ�ǂ̊J�����ŗp�ӂ���
 *  �Ă���j�D
 */
#ifndef TOPPERS_MACRO_ONLY
#include <stddef.h>
#include <limits.h>
#endif /* TOPPERS_MACRO_ONLY */


/*
 *  �R���p�C���ˑ��̃f�[�^�^�̒�`
 *
 *  stdint.h���C���N���[�h����
 */
#ifndef TOPPERS_MACRO_ONLY
#include <stdint.h>
#endif /* TOPPERS_MACRO_ONLY */


/*
 *  ���������_�^�Ɋւ����`
 *
 *  ���L�̒�`��dbl_size = 8�I�v�V�������w�肵���ꍇ�̂ݗL���Ƃ��邱��.
 */
#ifndef TOPPERS_MACRO_ONLY
typedef float		float32_t;			/* IEEE754�����̒P���x���������_�� */
typedef double		double64_t;			/* IEEE754�����̔{���x���������_�� */
#endif /* TOPPERS_MACRO_ONLY */

#define FLOAT32_MIN		( 1.4012984643248171e-45F )
#define FLOAT32_MAX		( 3.4028234663852886e+38F )
#define DOUBLE64_MIN	( 4.9406564584124654e-324 )
#define DOUBLE64_MAX	( 1.7976931348623157e+308 )


/*
 *  �󃉃x���̒�`
 *
 *  �{�R���p�C���ł͑傫���[���̔z��̓R���p�C���G���[�ɂȂ邽��,
 *  �T�C�Y1�ɂĒ�`����.
 */
#define TOPPERS_EMPTY_LABEL( type, symbol )		type symbol[ 1 ]


#endif /* TOPPERS_TOOL_STDDEF_H */

