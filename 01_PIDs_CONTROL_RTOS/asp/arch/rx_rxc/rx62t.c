/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 *
 *  Copyright (C) 2010 by Witz Corporation, JAPAN
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
 */

#include "kernel_impl.h"


/*
 *  �����ݗv���v���C�I���e�B���W�X�^�A�h���X�e�[�u��
 */
volatile uint8_t __evenaccess * const ipr_reg_addr[ INHNO_MAX ] = {
	NULL, NULL, NULL, NULL, NULL,	/* No.0 - 4   �\�� */
	NULL, NULL, NULL, NULL, NULL,	/* No.5 - 9   �\�� */
	NULL, NULL, NULL, NULL, NULL,	/* No.10 - 14 �\�� */
	NULL,							/* No.15  �\�� */
	ICU_IPR00_ADDR,					/* No.16  �o�X�G���[ BUSERR */
	NULL, NULL, NULL, NULL,			/* No.17 - 20 �\�� */
	ICU_IPR01_ADDR,					/* No.21  FCU FIFERR */
	NULL,							/* No.22  �\�� */
	ICU_IPR02_ADDR,					/* No.23  FCU FRDYI */
	NULL, NULL, NULL, 				/* No.24 -26  �\�� */
	ICU_IPR03_ADDR,					/* No.27  SWINT */
	ICU_IPR04_ADDR,					/* No.28  CMT���j�b�g0 CMT0 */
	ICU_IPR05_ADDR,					/* No.29  CMT���j�b�g0 CMT1 */
	ICU_IPR06_ADDR,					/* No.30  CMT���j�b�g1 CMT2 */
	ICU_IPR07_ADDR,					/* No.31  CMT���j�b�g1 CMT3 */
	NULL, NULL, NULL, NULL,			/* No.32 - 35 �\�� */
	NULL, NULL, NULL, NULL,			/* No.36 - 39 �\�� */
	NULL, NULL, NULL, NULL,			/* No.40 - 43 �\�� */
	ICU_IPR14_ADDR,				 	/* No.44  SPEI0 */
	ICU_IPR14_ADDR,				 	/* No.45  SPRI0 */
	ICU_IPR14_ADDR,				 	/* No.46  SPTI0 */
	ICU_IPR14_ADDR,				 	/* No.47  SPII0 */
	NULL, NULL, NULL, NULL, 		/* No.48 - 51 �\�� */
	NULL, NULL, NULL, NULL, 		/* No.52 - 55 �\�� */
	ICU_IPR18_ADDR,				 	/* No.56 CAN0 ERS0 */
	ICU_IPR18_ADDR,				 	/* No.57 CAN0 RXF0 */
	ICU_IPR18_ADDR,				 	/* No.58 CAN0 TXF0 */
	ICU_IPR18_ADDR,				 	/* No.59 CAN0 RXM0 */
	ICU_IPR18_ADDR,				 	/* No.60 CAN0 TXM0 */
	NULL, NULL, NULL,        		/* No.61 - 63 �\�� */
	ICU_IPR20_ADDR,					/* No.64  �O���[�q IRQ0 */
	ICU_IPR21_ADDR,					/* No.65  �O���[�q IRQ1 */
	ICU_IPR22_ADDR,					/* No.66  �O���[�q IRQ2 */
	ICU_IPR23_ADDR,					/* No.67  �O���[�q IRQ3 */
	ICU_IPR24_ADDR,					/* No.68  �O���[�q IRQ4 */
	ICU_IPR25_ADDR,					/* No.69  �O���[�q IRQ5 */
	ICU_IPR26_ADDR,					/* No.70  �O���[�q IRQ6 */
	ICU_IPR27_ADDR,					/* No.71  �O���[�q IRQ7 */
	NULL, NULL, NULL, NULL, 		/* No.72 - 75 �\�� */
	NULL, NULL, NULL, NULL, 		/* No.76 - 79 �\�� */
	NULL, NULL, NULL, NULL, NULL,	/* No.80 - 84 �\�� */
	NULL, NULL, NULL, NULL, NULL,	/* No.85 - 89 �\�� */
	NULL, NULL, NULL, NULL, NULL,	/* No.90 - 94 �\�� */
	NULL,   			    		/* No.95 �\�� */
	ICU_IPR40_ADDR,					/* No.96  WDT WOVI */
	NULL,   			    		/* No.97 �\�� */
	ICU_IPR44_ADDR,					/* No.98  AD0 ADI0 */
	NULL, NULL, NULL,			    /* No.99 - 101 �\�� */
	ICU_IPR48_ADDR,			    	/* No.102 S12AD0 */
	ICU_IPR48_ADDR,			    	/* No.103 S12AD1 */
	NULL, NULL,	        		    /* No.104 - 105 �\�� */
	ICU_IPR49_ADDR,		    		/* No.106 CMPI */
	NULL, NULL, NULL, NULL, NULL,	/* No.107 - 111 �\�� */
	NULL, NULL,         			/* No.112 - 113 �\�� */
	ICU_IPR51_ADDR,		    		/* No.114 MTU0 TGIA0 */
	ICU_IPR51_ADDR,		    		/* No.115 MTU0 TGIB0 */
	ICU_IPR51_ADDR,		    		/* No.116 MTU0 TGIC0 */
	ICU_IPR51_ADDR,		    		/* No.117 MTU0 TGID0 */
	ICU_IPR52_ADDR,		    		/* No.118 MTU0 TGIV0 */
	ICU_IPR52_ADDR,		    		/* No.119 MTU0 TGIE0 */
	ICU_IPR52_ADDR,		    		/* No.120 MTU0 TGIF0 */
	ICU_IPR53_ADDR,			    	/* No.121 MTU1 TGIA1 */
	ICU_IPR53_ADDR,			    	/* No.122 MTU1 TGIA1 */
	ICU_IPR54_ADDR,			    	/* No.123 MTU1 TGIV1 */
	ICU_IPR54_ADDR,			    	/* No.124 MTU1 TGIU1 */
	ICU_IPR55_ADDR,	    			/* No.125 MTU2 TGIA2 */
	ICU_IPR55_ADDR,	    			/* No.126 MTU2 TGIB2 */
	ICU_IPR56_ADDR,	    			/* No.127 MTU2 TGIV2 */
	ICU_IPR56_ADDR,	    			/* No.128 MTU2 TGIU2 */
	ICU_IPR57_ADDR,	    			/* No.129 MTU3 TGIA3 */
	ICU_IPR57_ADDR,	    			/* No.130 MTU3 TGIB3 */
	ICU_IPR57_ADDR,	    			/* No.131 MTU3 TCIC3 */
	ICU_IPR57_ADDR,	    			/* No.132 MTU3 TCID3 */
	ICU_IPR58_ADDR,	    			/* No.133 MTU3 TCIDV */
    ICU_IPR59_ADDR,		    		/* No.134 MTU4 TGIA4 */
	ICU_IPR59_ADDR,		    		/* No.135 MTU4 TGIB4 */
	ICU_IPR59_ADDR,		    		/* No.136 MTU4 TCIC4 */
	ICU_IPR59_ADDR,		    		/* No.137 MTU4 TCID4 */
	ICU_IPR5A_ADDR,		    		/* No.138 MTU4 TCIV4 */
	ICU_IPR5B_ADDR,		    		/* No.139 MTU5 TGIU5 */
	ICU_IPR5B_ADDR,		    		/* No.140 MTU5 TCIV5 */
	ICU_IPR5B_ADDR,		    		/* No.141 MTU5 TCIW5 */
	ICU_IPR5C_ADDR,		    		/* No.142 MTU6 TCIA6 */
	ICU_IPR5C_ADDR,		    		/* No.143 MTU6 TGIB6 */
	ICU_IPR5C_ADDR,		    		/* No.144 MTU6 TCIC6 */
	ICU_IPR5C_ADDR,		    		/* No.145 MTU6 TCID6 */
	ICU_IPR5D_ADDR,		    		/* No.146 MTU6 TCIV6 */
	NULL, NULL,      	            /* No.147 - 148 �\�� */
	ICU_IPR5E_ADDR,		    		/* No.149 MTU7 TCIA7 */
	ICU_IPR5E_ADDR,		    		/* No.150 MTU7 TCIB7 */
	ICU_IPR5F_ADDR,		    		/* No.151 MTU7 TGIC7 */
	ICU_IPR5F_ADDR,		    		/* No.152 MTU7 TCID7 */
	ICU_IPR60_ADDR,		    		/* No.153 MTU7 TCIV7 */
	NULL, NULL, NULL, NULL, NULL,	/* No.154 - 158 �\�� */
	NULL, NULL, NULL, NULL, NULL,	/* No.159 - 163 �\�� */
	NULL, NULL, NULL, NULL, NULL,	/* No.164 - 168 �\�� */
	NULL, 	                        /* No.169 �\�� */
	ICU_IPR67_ADDR,	        		/* No.170 POE OEI1 */
	ICU_IPR67_ADDR,	        		/* No.171 POE OEI2 */
	ICU_IPR67_ADDR,	        		/* No.172 POE OEI3 */
	ICU_IPR67_ADDR,	        		/* No.173 POE OEI4 */
	ICU_IPR68_ADDR,		    		/* No.174 GPT0 GTCIA0 */
	ICU_IPR68_ADDR,		    		/* No.175 GPT0 GTCIB0 */
	ICU_IPR68_ADDR,		    		/* No.176 GPT0 GTCIC0 */
	ICU_IPR69_ADDR,		    		/* No.177 GPT0 GTCIE0 */
	ICU_IPR69_ADDR,		    		/* No.178 GPT0 GTCIV0 */
	ICU_IPR69_ADDR,		    		/* No.179 GPT0 LOCO1 */
	ICU_IPR6A_ADDR,		    		/* No.180 GPT1 GTCIA0 */
	ICU_IPR6A_ADDR,		    		/* No.181 GPT1 GTCIB0 */
	ICU_IPR6A_ADDR,		    		/* No.182 GPT1 GTCIC0 */
	ICU_IPR6B_ADDR,		    		/* No.183 GPT1 GTCIE0 */
	ICU_IPR6B_ADDR,		    		/* No.184 GPT1 GTCIV0 */
	NULL,                          	/* No.185 �\�� */
	ICU_IPR6C_ADDR,	    			/* No.186 GPT2 GTCIA0 */
	ICU_IPR6C_ADDR,	    			/* No.187 GPT2 GTCIB0 */
	ICU_IPR6C_ADDR,	    			/* No.188 GPT2 GTCIC0 */
	ICU_IPR6D_ADDR,	    			/* No.189 GPT2 GTCIE0 */
	ICU_IPR6D_ADDR,	    			/* No.190 GPT2 GTCIV0 */
	NULL,                          	/* No.191 �\�� */
	ICU_IPR6E_ADDR,		       		/* No.192 GPT3 GTCIA0 */
	ICU_IPR6E_ADDR,		       		/* No.193 GPT3 GTCIB0 */
	ICU_IPR6E_ADDR,		       		/* No.194 GPT3 GTCIC0 */
	ICU_IPR6F_ADDR,		       		/* No.195 GPT3 GTCIE0 */
	ICU_IPR6F_ADDR,		       		/* No.196 GPT3 GTCIV0 */
	NULL, NULL, NULL, NULL, NULL,	/* No.197 - 101 �\�� */
    NULL, NULL, NULL, NULL, NULL,	/* No.102 - 106 �\�� */
	NULL, NULL, NULL, NULL, NULL,	/* No.102 - 111 �\�� */
	NULL, NULL,                   	/* No.112 - 113 �\�� */
	ICU_IR80_ADDR,					/* No.214 SCI0 ERI0 */
	ICU_IR80_ADDR,					/* No.215 SCI0 RXI0 */
	ICU_IR80_ADDR,					/* No.216 SCI0 TXI0 */
	ICU_IR80_ADDR,					/* No.217 SCI0 TEI0 */
	ICU_IR81_ADDR,					/* No.218 SCI1 ERI1 */
	ICU_IR81_ADDR,					/* No.219 SCI1 RXI1 */
	ICU_IR81_ADDR,					/* No.220 SCI1 TXI1 */
	ICU_IR81_ADDR,					/* No.221 SCI1 TEI1 */
	ICU_IR82_ADDR,					/* No.222 SCI2 ERI2 */
	ICU_IR82_ADDR,					/* No.223 SCI2 RXI2 */
	ICU_IR82_ADDR,					/* No.224 SCI2 TXI2 */
	ICU_IR82_ADDR,					/* No.225 SCI2 TEI2 */
	NULL, NULL, NULL, NULL, NULL,	/* No.226 - 230 �\�� */
	NULL, NULL, NULL, NULL, NULL,	/* No.231 - 235 �\�� */
	NULL, NULL, NULL, NULL, NULL,	/* No.236 - 240 �\�� */
	NULL, NULL, NULL, NULL, NULL,	/* No.241 - 245 �\�� */
	ICU_IR88_ADDR,					/* No.246 RIIC0 ICEEI0 */
	ICU_IR89_ADDR,					/* No.247 RIIC0 ICRXI0 */
	ICU_IR8A_ADDR,					/* No.248 RIIC0 ICTXI0 */
	ICU_IR8B_ADDR,					/* No.249 RIIC0 ICTEI0 */
	NULL, NULL, NULL, NULL,     	/* No.250 - 253 �\�� */
	ICU_IR90_ADDR,					/* No.254 LIN0 */
	NULL, 	    					/* No.255 �\�� */
};


/*
 *  �����ݗv�������W�X�^�A�h���X�e�[�u��
 */
const IER_INFO ier_reg_addr[ INHNO_MAX ] = {
	{ NULL, INVALID_OFFSET },			/* No.0   �\�� */
	{ NULL, INVALID_OFFSET },			/* No.1   �\�� */
	{ NULL, INVALID_OFFSET },			/* No.2   �\�� */
	{ NULL, INVALID_OFFSET },			/* No.3   �\�� */
	{ NULL, INVALID_OFFSET },			/* No.4   �\�� */
	{ NULL, INVALID_OFFSET },			/* No.5   �\�� */
	{ NULL, INVALID_OFFSET },			/* No.6   �\�� */
	{ NULL, INVALID_OFFSET },			/* No.7   �\�� */
	{ NULL, INVALID_OFFSET },			/* No.8   �\�� */
	{ NULL, INVALID_OFFSET },			/* No.9   �\�� */
	{ NULL, INVALID_OFFSET },			/* No.10  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.11  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.12  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.13  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.14  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.15  �\�� */
	{ ICU_IER02_ADDR, ICU_IEN0_BIT },	/* No.16  �o�X�G���[ BUSERR */
	{ NULL, INVALID_OFFSET },			/* No.17  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.18  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.19  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.20  �\�� */
	{ ICU_IER02_ADDR, ICU_IEN5_BIT },	/* No.21  FCU FIFERR */
	{ NULL, INVALID_OFFSET },			/* No.22  �\�� */
	{ ICU_IER02_ADDR, ICU_IEN7_BIT },	/* No.23  FCU FRDYI */
	{ NULL, INVALID_OFFSET },			/* No.24  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.25  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.26  �\�� */
	{ ICU_IER03_ADDR, ICU_IEN3_BIT },	/* No.27  SWINT �\�� */
	{ ICU_IER03_ADDR, ICU_IEN4_BIT },	/* No.28  CMT���j�b�g0 CMT0 */
	{ ICU_IER03_ADDR, ICU_IEN5_BIT },	/* No.29  CMT���j�b�g0 CMT1 */
	{ ICU_IER03_ADDR, ICU_IEN6_BIT },	/* No.30  CMT���j�b�g1 CMT2 */
	{ ICU_IER03_ADDR, ICU_IEN7_BIT },	/* No.31  CMT���j�b�g1 CMT3 */
	{ NULL, INVALID_OFFSET },			/* No.32  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.33  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.34  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.35  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.36  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.37  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.38  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.39  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.40  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.41  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.42  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.43  �\�� */
	{ ICU_IER05_ADDR, ICU_IEN4_BIT },	/* No.44  SPEI0 */
	{ ICU_IER05_ADDR, ICU_IEN5_BIT },	/* No.45  SPRI0 */
	{ ICU_IER05_ADDR, ICU_IEN6_BIT },	/* No.46  SPTI0 */
	{ ICU_IER05_ADDR, ICU_IEN7_BIT },	/* No.47  SPII0 */
	{ NULL, INVALID_OFFSET },			/* No.48  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.49  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.50  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.51  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.52  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.53  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.54  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.55  �\�� */
	{ ICU_IER07_ADDR, ICU_IEN0_BIT },	/* No.56  CAN ERS0 */
	{ ICU_IER07_ADDR, ICU_IEN1_BIT },	/* No.57  CAN RXF0 */
	{ ICU_IER07_ADDR, ICU_IEN2_BIT },	/* No.58  CAN TXF0 */
	{ ICU_IER07_ADDR, ICU_IEN3_BIT },	/* No.59  CAN RXM0 */
	{ ICU_IER07_ADDR, ICU_IEN4_BIT },	/* No.60  CAN TXM0 */
	{ NULL, INVALID_OFFSET },			/* No.61  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.62  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.63  �\�� */
	{ ICU_IER08_ADDR, ICU_IEN0_BIT },	/* No.64  �O���[�q IRQ0 */
	{ ICU_IER08_ADDR, ICU_IEN1_BIT },	/* No.65  �O���[�q IRQ1 */
	{ ICU_IER08_ADDR, ICU_IEN2_BIT },	/* No.66  �O���[�q IRQ2 */
	{ ICU_IER08_ADDR, ICU_IEN3_BIT },	/* No.67  �O���[�q IRQ3 */
	{ ICU_IER08_ADDR, ICU_IEN4_BIT },	/* No.68  �O���[�q IRQ4 */
	{ ICU_IER08_ADDR, ICU_IEN5_BIT },	/* No.69  �O���[�q IRQ5 */
	{ ICU_IER08_ADDR, ICU_IEN6_BIT },	/* No.70  �O���[�q IRQ6 */
	{ ICU_IER08_ADDR, ICU_IEN7_BIT },	/* No.71  �O���[�q IRQ7 */
	{ NULL, INVALID_OFFSET },			/* No.72  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.73  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.74  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.75  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.76  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.77  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.78  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.79  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.80  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.81  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.82  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.83  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.84  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.85  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.86  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.87  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.88  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.89  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.90  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.91  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.92  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.93  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.94  �\�� */
	{ NULL, INVALID_OFFSET },			/* No.95  �\�� */
	{ ICU_IER0C_ADDR, ICU_IEN0_BIT },	/* No.96  WDT WOVI */
	{ NULL, INVALID_OFFSET },			/* No.97  �\�� */
	{ ICU_IER0C_ADDR, ICU_IEN2_BIT },	/* No.98  AD0 ADI0 */
	{ NULL, INVALID_OFFSET },			/* No.99 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.100 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.101 �\�� */
	{ ICU_IER0C_ADDR, ICU_IEN6_BIT },	/* No.102 S12AD0 */
	{ ICU_IER0C_ADDR, ICU_IEN7_BIT },	/* No.103 S12AD0 */
	{ NULL, INVALID_OFFSET },			/* No.104 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.105 �\�� */
	{ ICU_IER0D_ADDR, ICU_IEN2_BIT },	/* No.106 CMPI */
	{ NULL, INVALID_OFFSET },			/* No.107 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.108 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.109 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.110 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.111 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.112 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.113 �\�� */
	{ ICU_IER0E_ADDR, ICU_IEN2_BIT },	/* No.114 MTU0 TGIA0 */
	{ ICU_IER0E_ADDR, ICU_IEN3_BIT },	/* No.115 MTU0 TGIB0 */
	{ ICU_IER0E_ADDR, ICU_IEN4_BIT },	/* No.116 MTU0 TGIC0 */
	{ ICU_IER0E_ADDR, ICU_IEN5_BIT },	/* No.117 MTU0 TGID0 */
	{ ICU_IER0E_ADDR, ICU_IEN6_BIT },	/* No.118 MTU0 TCIV0 */
	{ ICU_IER0E_ADDR, ICU_IEN7_BIT },	/* No.119 MTU0 TCIE0 */
	{ ICU_IER0F_ADDR, ICU_IEN0_BIT },	/* No.120 MTU0 TCIF0 */
	{ ICU_IER0F_ADDR, ICU_IEN1_BIT },	/* No.121 MTU1 TGIA1 */
	{ ICU_IER0F_ADDR, ICU_IEN2_BIT },	/* No.122 MTU1 TGIB1 */
	{ ICU_IER0F_ADDR, ICU_IEN3_BIT },	/* No.123 MTU1 TCIV1 */
	{ ICU_IER0F_ADDR, ICU_IEN4_BIT },	/* No.124 MTU1 TCIU1 */
	{ ICU_IER0F_ADDR, ICU_IEN5_BIT },	/* No.125 MTU2 TGIA2 */
	{ ICU_IER0F_ADDR, ICU_IEN6_BIT },	/* No.126 MTU2 TGIB2 */
	{ ICU_IER0F_ADDR, ICU_IEN7_BIT },	/* No.127 MTU2 TCIV2 */
	{ ICU_IER10_ADDR, ICU_IEN0_BIT },	/* No.128 MTU2 TCIU2 */
	{ ICU_IER10_ADDR, ICU_IEN1_BIT },	/* No.129 MTU3 TGIA3 */
	{ ICU_IER10_ADDR, ICU_IEN2_BIT },	/* No.130 MTU3 TGIB3 */
	{ ICU_IER10_ADDR, ICU_IEN3_BIT },	/* No.131 MTU3 TCIC3 */
	{ ICU_IER10_ADDR, ICU_IEN4_BIT },	/* No.132 MTU3 TCID3 */
	{ ICU_IER10_ADDR, ICU_IEN5_BIT },	/* No.133 MTU3 TCIV3 */
	{ ICU_IER10_ADDR, ICU_IEN6_BIT },	/* No.134 MTU4 TGIA4 */
	{ ICU_IER10_ADDR, ICU_IEN7_BIT },	/* No.135 MTU4 TGIB4 */
	{ ICU_IER11_ADDR, ICU_IEN0_BIT },	/* No.136 MTU4 TCIC4 */
	{ ICU_IER11_ADDR, ICU_IEN1_BIT },	/* No.137 MTU4 TCID4 */
	{ ICU_IER11_ADDR, ICU_IEN2_BIT },	/* No.138 MTU4 TCIV4 */
	{ ICU_IER11_ADDR, ICU_IEN3_BIT },	/* No.139 MTU5 TCIU5 */
	{ ICU_IER11_ADDR, ICU_IEN4_BIT },	/* No.140 MTU5 TCIV5 */
	{ ICU_IER11_ADDR, ICU_IEN5_BIT },	/* No.141 MTU5 TCIW5 */
	{ ICU_IER11_ADDR, ICU_IEN6_BIT },	/* No.142 MTU6 TGIA6 */
	{ ICU_IER11_ADDR, ICU_IEN7_BIT },	/* No.143 MTU6 TGIB6 */
	{ ICU_IER12_ADDR, ICU_IEN0_BIT },	/* No.144 MTU6 TGIC6 */
	{ ICU_IER12_ADDR, ICU_IEN1_BIT },	/* No.145 MTU6 TGID6 */
	{ ICU_IER12_ADDR, ICU_IEN2_BIT },	/* No.146 MTU6 TCIV6 */
	{ NULL, INVALID_OFFSET },			/* No.147 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.148 �\�� */
	{ ICU_IER12_ADDR, ICU_IEN5_BIT },	/* No.149 MTU7 TGIA7 */
	{ ICU_IER12_ADDR, ICU_IEN6_BIT },	/* No.150 MTU7 TGIB7 */
	{ ICU_IER12_ADDR, ICU_IEN7_BIT },	/* No.151 MTU7 TCIC7 */
	{ ICU_IER13_ADDR, ICU_IEN0_BIT },	/* No.152 MTU7 TCID7 */
	{ ICU_IER13_ADDR, ICU_IEN1_BIT },	/* No.153 MTU7 TCIV7 */
	{ NULL, INVALID_OFFSET },			/* No.154 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.155 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.156 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.157 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.158 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.159 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.160 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.161 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.162 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.163 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.164 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.165 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.166 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.167 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.168 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.169 �\�� */
	{ ICU_IER15_ADDR, ICU_IEN2_BIT },	/* No.170 POE OEI1 */
	{ ICU_IER15_ADDR, ICU_IEN3_BIT },	/* No.171 POE OEI2 */
	{ ICU_IER15_ADDR, ICU_IEN4_BIT },	/* No.172 POE OEI3 */
	{ ICU_IER15_ADDR, ICU_IEN5_BIT },	/* No.173 POE OEI4 */
	{ ICU_IER15_ADDR, ICU_IEN6_BIT },	/* No.174 GPT0 GTCIA0 */
	{ ICU_IER15_ADDR, ICU_IEN7_BIT },	/* No.175 GPT0 GTCIB0 */
	{ ICU_IER16_ADDR, ICU_IEN0_BIT },	/* No.176 GPT0 GTCIC0 */
	{ ICU_IER16_ADDR, ICU_IEN1_BIT },	/* No.177 GPT0 GTCIE0 */
	{ ICU_IER16_ADDR, ICU_IEN2_BIT },	/* No.178 GPT0 GTCIV0 */
	{ ICU_IER16_ADDR, ICU_IEN3_BIT },	/* No.179 GPT0 LOCO1 */
	{ ICU_IER16_ADDR, ICU_IEN4_BIT },	/* No.180 GPT1 GTCIA0 */
	{ ICU_IER16_ADDR, ICU_IEN5_BIT },	/* No.181 GPT1 GTCIB0 */
	{ ICU_IER16_ADDR, ICU_IEN6_BIT },	/* No.182 GPT1 GTCIC0 */
	{ ICU_IER16_ADDR, ICU_IEN7_BIT },	/* No.183 GPT1 GTCIE0 */
	{ ICU_IER17_ADDR, ICU_IEN1_BIT },	/* No.184 GPT1 GTCIV0 */
	{ NULL, INVALID_OFFSET },			/* No.185 �\�� */
	{ ICU_IER17_ADDR, ICU_IEN2_BIT },	/* No.186 GPT2 GTCIA0 */
	{ ICU_IER17_ADDR, ICU_IEN3_BIT },	/* No.187 GPT2 GTCIB0 */
	{ ICU_IER17_ADDR, ICU_IEN4_BIT },	/* No.188 GPT2 GTCIC0 */
	{ ICU_IER17_ADDR, ICU_IEN5_BIT },	/* No.189 GPT2 GTCIE0 */
	{ ICU_IER17_ADDR, ICU_IEN6_BIT },	/* No.190 GPT2 GTCIV0 */
	{ NULL, INVALID_OFFSET },			/* No.191 �\�� */
	{ ICU_IER17_ADDR, ICU_IEN7_BIT },	/* No.192 GPT3 GTCIA0 */
	{ ICU_IER18_ADDR, ICU_IEN0_BIT },	/* No.193 GPT3 GTCIB0 */
	{ ICU_IER18_ADDR, ICU_IEN1_BIT },	/* No.194 GPT3 GTCIC0 */
	{ ICU_IER18_ADDR, ICU_IEN2_BIT },	/* No.195 GPT3 GTCIE0 */
	{ ICU_IER18_ADDR, ICU_IEN3_BIT },	/* No.196 GPT3 GTCIV0 */
	{ NULL, INVALID_OFFSET },			/* No.197 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.198 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.199 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.200 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.201 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.202 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.203 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.204 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.205 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.206 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.207 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.208 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.209 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.210 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.211 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.212 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.213 �\�� */
	{ ICU_IER1A_ADDR, ICU_IEN6_BIT },	/* No.214 SCI0 ERI0 */
	{ ICU_IER1A_ADDR, ICU_IEN7_BIT },	/* No.215 SCI0 RXI0 */
	{ ICU_IER1B_ADDR, ICU_IEN0_BIT },	/* No.216 SCI0 TXI0 */
	{ ICU_IER1B_ADDR, ICU_IEN1_BIT },	/* No.217 SCI0 TEI0 */
	{ ICU_IER1B_ADDR, ICU_IEN2_BIT },	/* No.218 SCI1 ERI1 */
	{ ICU_IER1B_ADDR, ICU_IEN3_BIT },	/* No.219 SCI1 RXI1 */
	{ ICU_IER1B_ADDR, ICU_IEN4_BIT },	/* No.220 SCI1 TXI1 */
	{ ICU_IER1B_ADDR, ICU_IEN5_BIT },	/* No.221 SCI1 TEI1 */
	{ ICU_IER1B_ADDR, ICU_IEN6_BIT },	/* No.222 SCI2 ERI2 */
	{ ICU_IER1B_ADDR, ICU_IEN7_BIT },	/* No.223 SCI2 RXI2 */
	{ ICU_IER1C_ADDR, ICU_IEN0_BIT },	/* No.224 SCI2 TXI2 */
	{ ICU_IER1C_ADDR, ICU_IEN1_BIT },	/* No.225 SCI2 TEI2 */
	{ NULL, INVALID_OFFSET },			/* No.226 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.227 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.228 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.229 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.230 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.231 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.232 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.233 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.234 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.235 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.236 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.237 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.238 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.239 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.240 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.241 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.242 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.242 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.243 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.244 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.245 �\�� */
	{ ICU_IER1E_ADDR, ICU_IEN6_BIT },	/* No.246 RIIC0 ICEEI0 */
	{ ICU_IER1E_ADDR, ICU_IEN7_BIT },	/* No.247 RIIC0 ICRXI0 */
	{ ICU_IER1F_ADDR, ICU_IEN0_BIT },	/* No.248 RIIC0 ICTXI0 */
	{ ICU_IER1F_ADDR, ICU_IEN1_BIT },	/* No.249 RIIC0 ICTEI0 */
	{ NULL, INVALID_OFFSET },			/* No.250 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.251 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.252 �\�� */
	{ NULL, INVALID_OFFSET },			/* No.253 �\�� */
	{ ICU_IER1F_ADDR, ICU_IEN6_BIT },	/* No.254 LIN0 */
	{ NULL, INVALID_OFFSET },			/* No.255 �\�� */
};


/*
 *  IRQ�R���g���[�����W�X�^�A�h���X�e�[�u��
 */
volatile uint8_t __evenaccess * const irqcr_reg_addr[ IRQ_MAX ] = {
	ICU_IRQ0_ADDR,
	ICU_IRQ1_ADDR,
	ICU_IRQ2_ADDR,
	ICU_IRQ3_ADDR,
	ICU_IRQ4_ADDR,
	ICU_IRQ5_ADDR,
	ICU_IRQ6_ADDR,
	ICU_IRQ7_ADDR,
};

