$ 
$  TOPPERS/ASP Kernel
$      Toyohashi Open Platform for Embedded Real-Time Systems/
$      Advanced Standard Profile Kernel
$ 
$  Copyright (C) 2008-2010 by Witz Corporation, JAPAN
$ 
$  ��L���쌠�҂́C�ȉ���(1)�`(4)�̏����𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F
$  �A�i�{�\�t�g�E�F�A�����ς������̂��܂ށD�ȉ������j���g�p�E�����E��
$  �ρE�Ĕz�z�i�ȉ��C���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
$  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
$      ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
$      �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
$  (2) �{�\�t�g�E�F�A���C���C�u�����`���ȂǁC���̃\�t�g�E�F�A�J���Ɏg
$      �p�ł���`�ōĔz�z����ꍇ�ɂ́C�Ĕz�z�ɔ����h�L�������g�i���p
$      �҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C���̗��p��������щ��L
$      �̖��ۏ؋K����f�ڂ��邱�ƁD
$  (3) �{�\�t�g�E�F�A���C�@��ɑg�ݍ��ނȂǁC���̃\�t�g�E�F�A�J���Ɏg
$      �p�ł��Ȃ��`�ōĔz�z����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂�����
$      �ƁD
$    (a) �Ĕz�z�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒�
$        �쌠�\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
$    (b) �Ĕz�z�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āCTOPPERS�v���W�F�N�g��
$        �񍐂��邱�ƁD
$  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
$      �Q������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD
$      �܂��C�{�\�t�g�E�F�A�̃��[�U�܂��̓G���h���[�U����̂����Ȃ闝
$      �R�Ɋ�Â�����������C��L���쌠�҂����TOPPERS�v���W�F�N�g��
$      �Ɛӂ��邱�ƁD
$ 
$  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
$  ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC����̎g�p�ړI
$  �ɑ΂���K�������܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F
$  �A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C��
$  �̐ӔC�𕉂�Ȃ��D
$ 
$ 

$ 
$  �A�[�L�e�N�`���ˑ��e���v���[�g�iRX610�p�j
$ 



$ 
$  ATT_ISR�Ŏg�p�ł��銄���ݔԍ��Ƃ���ɑΉ����銄���݃n���h���ԍ�
$ 

$INTNO_ATTISR_VALID = INTNO_VALID$
$INHNO_ATTISR_VALID = INHNO_VALID$


$ 
$  DEF_INT�^DEF_EXC�Ŏg�p�ł��銄���݃n���h���ԍ��^CPU��O�n���h���ԍ�
$ 

$INHNO_DEFINH_VALID = INHNO_VALID$
$EXCNO_DEFEXC_VALID = EXCNO_VALID$


$ 
$  CFG_INT�Ŏg�p�ł��銄���ݔԍ��Ɗ����ݗD��x
$ 

$INTNO_CFGINT_VALID = INHNO_VALID$
$INTPRI_CFGINT_VALID = { -7, -6,...,-1 }$


$ 
$  �^�[�Q�b�g��ˑ����Ɋ܂܂��W���̊����݊Ǘ��@�\/��O�Ǘ��@�\�̏������������g�p����
$ 

$OMIT_INITIALIZE_INTERRUPT = 0$
$OMIT_INITIALIZE_EXCEPTION = 0$


$ 
$  �X�^�b�N�T�C�Y�̃`�F�b�N���@�w��
$ 

$CHECK_STKSZ_ALIGN = 4$


$ 
$  �^�X�N�X�^�b�N�T�C�Y�̍ŏ��l
$ 
$  �^�X�N�N������4byte,
$  �����ݓ��������ɂ�48byte, CPU��O���������ɂ�84byte,
$  �ł��邽��, �ŏ��l��88byte�Ƃ���.
$ 

$TARGET_MIN_STKSZ = 88$


$ 
$  �萔��`
$ 

$TA_POSEDGE = TA_EDGE$


$ 
$ �^�[�Q�b�g�ˑ��̊����ݑ����̒�`
$ 

$TARGET_INTATR = TA_POSEDGE | TA_NEGEDGE | TA_BOTHEDGE | TA_LOWLEVEL$


$ 
$ �^�[�Q�b�g�ˑ��̊����݃n���h�������̒�`
$ 

$TARGET_INHATR = TA_NONKERNEL$


$ 
$ �J�[�l���Ǘ��O�����݃n���h���͌Œ肳���Ȃ�����,
$ INTNO_FIX_KERNEL
$ INHNO_FIX_KERNEL
$ INHNO_FIX_NONKERNEL
$ INHNO_FIX_NONKERNEL
$ ���`���Ȃ�.
$ 


$ 
$  �W���e���v���[�g�t�@�C���̃C���N���[�h
$ 
$INCLUDE "kernel.tf"$



$ 
$  CFG_INT�̃^�[�Q�b�g�ˑ��̃G���[�`�F�b�N
$ 

$FOREACH intno INT.ORDER_LIST$
$ IRQ�����ݔԍ����ǂ������`�F�b�N
	$IF ( LENGTH( FIND( INTNO_INT, INT.INTNO[intno] ) ) != 0 )$

$   TA_POSEDGE��TA_NEGEDGE�������ɐݒ肳��Ă���ꍇ
		$IF ((INT.INTATR[intno] & ( TA_POSEDGE | TA_NEGEDGE )) == ( TA_POSEDGE | TA_NEGEDGE ))$
			$ERROR$ INT.TEXT_LINE[intno]:$FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "intatr", INT.INTATR[intno], INT.INTNO[intno], "CFG_INT")$$END$
		$END$

$   TA_POSEDGE��TA_BOTHEDGE�������ɐݒ肳��Ă���ꍇ
		$IF ((INT.INTATR[intno] & ( TA_POSEDGE | TA_BOTHEDGE )) == ( TA_POSEDGE | TA_BOTHEDGE ))$
			$ERROR$ INT.TEXT_LINE[intno]:$FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "intatr", INT.INTATR[intno], INT.INTNO[intno], "CFG_INT")$$END$
		$END$

$   TA_NEGEDGE��TA_BOTHEDGE�������ɐݒ肳��Ă���ꍇ
		$IF ((INT.INTATR[intno] & ( TA_NEGEDGE | TA_BOTHEDGE )) == ( TA_NEGEDGE | TA_BOTHEDGE ))$
			$ERROR$ INT.TEXT_LINE[intno]:$FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "intatr", INT.INTATR[intno], INT.INTNO[intno], "CFG_INT")$$END$
		$END$

$   TA_POSEDGE��TA_NEGEDGE��TA_BOTHEDGE�������ɐݒ肳��Ă���ꍇ
		$IF ((INT.INTATR[intno] & ( TA_POSEDGE | TA_NEGEDGE | TA_BOTHEDGE )) == ( TA_POSEDGE | TA_NEGEDGE | TA_BOTHEDGE ))$
			$ERROR$ INT.TEXT_LINE[intno]:$FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "intatr", INT.INTATR[intno], INT.INTNO[intno], "CFG_INT")$$END$
		$END$

	$ELSE$

$   IRQ�����݈ȊO�̊����݂ɑ΂��Ċ����ݑ������w�肳��Ă���ꍇ
		$IF (INT.INTATR[intno] & (~( TA_ENAINT | TA_EDGE ))) != 0$
			$ERROR$ INT.TEXT_LINE[intno]: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "intatr", INT.INTATR[intno], INT.INTNO[intno], "CFG_INT")$$END$
		$END$

	$END$

$END$



$ 
$ �����ݔԍ����犄���ݗD��x�y�ё��������o���e�[�u��
$ 

/*$NL$
$SPC$*$SPC$$SPC$Interrupt Level and Attribute Table$NL$
$SPC$*/$NL$
const CFG_INT_INFO _kernel_cfg_int_table[$LENGTH(INTNO_RANGE)$] = {$NL$
$FOREACH intno INTNO_RANGE$
$ �����ݗD��x���擾
	$IF LENGTH(INT.INTNO[intno])$
		$intpri = -INT.INTPRI[intno]$
		$intatr = INT.INTATR[intno]$
	$ELSE$
		$intpri = "0"$
		$intatr = "0xFFFFFFFF"$
	$END$

$ �e�[�u���̒��g���o��
	$TAB$$FORMAT("{ %2d, %08x }, /* %02u */", intpri, intatr, +intno)$$NL$
$END$
};$NL$$NL$


$ 
$  �A�Z���u���o�̓t�@�C��
$ 

$FILE "kernel_cfg_asm.src"$

;$NL$
;  RX610�A�[�L�e�N�`���ˑ��o�̓t�@�C��$NL$
;$NL$
;  �����݃x�N�^�y�ъ����݃n���h����`$NL$
;$NL$
$NL$$NL$


$ 
$  �����ݓ�������
$ 

$ 
$  ���ʊ֐��̐錾
$ 

$TAB$.section P, CODE$NL$
$TAB$.glb$TAB$_kernel_interrupt$NL$
$TAB$.glb$TAB$__kernel_default_int_handler$NL$
$TAB$.glb$TAB$__kernel_default_exc_handler$NL$$NL$$NL$


$ 
$  �����݃n���h���̏o��
$ 

$FOREACH inhno INHNO_RANGE$
	$IF LENGTH(INH.INHNO[inhno])$
		$IF ((INH.INHATR[inhno] & TA_NONKERNEL) == 0)$
			$TAB$.glb	_$INH.INTHDR[inhno]$$NL$
			$TAB$.glb	__kernel_$INH.INTHDR[inhno]$_$+INH.INHNO[inhno]$_entry$NL$
			__kernel_$INH.INTHDR[inhno]$_$+INH.INHNO[inhno]$_entry:$NL$
			$TAB$pushm	r1-r5						; �X�N���b�`���W�X�^���^�X�N�X�^�b�N�֑ޔ� $NL$
			$TAB$mov.l	#$+INH.INHNO[inhno]$, r1	; �����݃n���h���ԍ���r1�� $NL$
			$TAB$mov.l	#_$INH.INTHDR[inhno]$, r2	; �n���h���̃A�h���X��r2�� $NL$
			$TAB$bra.a	_kernel_interrupt			; ���ʃ��[�`���� $NL$$NL$$NL$
		$END$
	$END$
$END$


$ ���o�^�����݃n���h����������
$TAB$.glb$TAB$__kernel_default_int_handler_entry$NL$
__kernel_default_int_handler_entry:$NL$
$TAB$pushm	r1-r5								; �X�N���b�`���W�X�^���^�X�N�X�^�b�N�֑ޔ� $NL$
$TAB$mov.l	#0FFFFFFFFH, r1						; �����݃n���h���ԍ���r1�� $NL$
$TAB$mov.l	#__kernel_default_int_handler, r2	; �n���h���̃A�h���X��r2�� $NL$
$TAB$bra.a	_kernel_interrupt					; ���ʃ��[�`���� $NL$$NL$$NL$


$ 
$  CPU��O�n���h����������
$ 

$TAB$.glb	_kernel_exception$NL$$NL$

$FOREACH excno EXCNO_RANGE$
	$IF LENGTH(EXC.EXCNO[excno])$
		$TAB$.glb	_$EXC.EXCHDR[excno]$$NL$
		$TAB$.glb	__kernel_$EXC.EXCHDR[excno]$_$+EXC.EXCNO[excno]$_entry$NL$
		__kernel_$EXC.EXCHDR[excno]$_$+EXC.EXCNO[excno]$_entry:$NL$
		$TAB$pushm	r1-r5						; �X�N���b�`���W�X�^���^�X�N�X�^�b�N�֑ޔ� $NL$
		$TAB$mov.l	#$+EXC.EXCNO[excno]$, r1	; CPU��O�n���h���ԍ���r1�� $NL$
		$TAB$mov.l	#_$EXC.EXCHDR[excno]$, r2	; �n���h���̃A�h���X��r2�� $NL$
		$TAB$bra.a	_kernel_exception			; ���ʃ��[�`���� $NL$$NL$$NL$
	$END$
$END$


$ ���o�^CPU��O�n���h����������
$TAB$.glb$TAB$__kernel_default_exc_handler_entry$NL$
__kernel_default_exc_handler_entry:$NL$
$TAB$pushm	r1-r5								; �X�N���b�`���W�X�^���^�X�N�X�^�b�N�֑ޔ� $NL$
$TAB$mov.l	#0FFFFFFFFH, r1						; CPU��O�n���h���ԍ���r1�� $NL$
$TAB$mov.l	#__kernel_default_exc_handler, r2	; �n���h���̃A�h���X��r2�� $NL$
$TAB$bra.a	_kernel_exception					; ���ʃ��[�`���� $NL$$NL$$NL$


$ 
$  �σx�N�^�e�[�u��
$ 

;$NL$
;  �σx�N�^�e�[�u��$NL$
;$NL$
$NL$

$TAB$.glb $TAB$ _start$NL$$NL$

$FOREACH inhno INH.ORDER_LIST$
	$IF ((INH.INHATR[inhno] & TA_NONKERNEL) != 0)$
		$TAB$.glb $TAB$ _$INH.INTHDR[inhno]$ $NL$
	$END$
$END$
$NL$

$TAB$.section C$$VECT, ROMDATA$NL$$NL$
vvector_table:$NL$
$FOREACH inhno INHNO_RANGE$
	$IF LENGTH(INH.INHNO[inhno])$
		$IF ((INH.INHATR[inhno] & TA_NONKERNEL) == 0)$
			$inhhdr = CONCAT(CONCAT("_kernel_" , CONCAT(INH.INTHDR[inhno] , "_")) , CONCAT(+INH.INHNO[inhno] , "_entry"))$
		$ELSE$
			$inhhdr = INH.INTHDR[inhno]$
		$END$
	$ELSE$
		$inhhdr = "_kernel_default_int_handler_entry"$
	$END$

	$TAB$.lword$TAB$_$inhhdr$ $TAB$ $TAB$ $FORMAT("; %02d" , inhno)$ $NL$
$END$


$ 
$  �Œ�x�N�^�e�[�u��
$ 
$FOREACH excno EXCNO_RANGE$
	$IF LENGTH(EXC.EXCNO[excno])$
		$EXCHDR[excno] = CONCAT(CONCAT("_kernel_" , CONCAT(EXC.EXCHDR[excno] , "_")) , CONCAT(+EXC.EXCNO[excno] , "_entry"))$
	$ELSE$
		$EXCHDR[excno] = "_kernel_default_exc_handler_entry"$
	$END$
$END$

$NL$
;$NL$
;  �Œ�x�N�^�e�[�u��$NL$
;$NL$
$NL$

$TAB$ .section FVECT, ROMDATA$NL$
$NL$
fvector_table:$NL$$NL$

$TAB$ .offset$TAB$ 020H$NL$
$TAB$ .lword$TAB$ 00000000 $TAB$ ; ����R�[�h, ID�R�[�h1 - 3$NL$
$TAB$ .lword$TAB$ 00000000 $TAB$ ; ID�R�[�h4 - 7$NL$
$TAB$ .lword$TAB$ 00000000 $TAB$ ; ID�R�[�h8 - 11$NL$
$TAB$ .lword$TAB$ 00000000 $TAB$ ; ID�R�[�h12 - 15$NL$$NL$

$TAB$ .offset$TAB$ 050H$NL$
$TAB$ .lword$TAB$ _$EXCHDR[20]$ $TAB$ $TAB$ ;$SPC$ 20:�������ߗ�O $SPC$$NL$
$TAB$ .offset$TAB$ 05CH$NL$
$TAB$ .lword$TAB$ _$EXCHDR[23]$ $TAB$ $TAB$ ;$SPC$ 23:����`���ߗ�O $SPC$$NL$
$TAB$ .offset$TAB$ 064H$NL$
$TAB$ .lword$TAB$ _$EXCHDR[25]$ $TAB$ $TAB$ ;$SPC$ 25:���������_��O $SPC$$NL$
$TAB$ .offset$TAB$ 078H$NL$
$TAB$ .lword$TAB$ _$EXCHDR[30]$ $TAB$ $TAB$ ;$SPC$ 30:�m���}�X�J�u����O $SPC$$NL$
$TAB$ .lword$TAB$ _start $TAB$ $TAB$ $TAB$ $TAB$ ;$SPC$ 31:���Z�b�g $SPC$$NL$

$NL$ $NL$

	$TAB$.end
$NL$
