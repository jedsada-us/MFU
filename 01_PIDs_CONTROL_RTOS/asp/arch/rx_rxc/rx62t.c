/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 *
 *  Copyright (C) 2010 by Witz Corporation, JAPAN
 *
 *  上記著作権者は，以下の(1)～(4)の条件を満たす場合に限り，本ソフトウェ
 *  ア（本ソフトウェアを改変したものを含む．以下同じ）を使用・複製・改
 *  変・再配布（以下，利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 *      また，本ソフトウェアのユーザまたはエンドユーザからのいかなる理
 *      由に基づく請求からも，上記著作権者およびTOPPERSプロジェクトを
 *      免責すること．
 *
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，特定の使用目的
 *  に対する適合性も含めて，いかなる保証も行わない．また，本ソフトウェ
 *  アの利用により直接的または間接的に生じたいかなる損害に関しても，そ
 *  の責任を負わない．
 *
 */

/*
 *		プロセッサ依存モジュール（RX62T用）
 */

#include "kernel_impl.h"


/*
 *  割込み要因プライオリティレジスタアドレステーブル
 */
volatile uint8_t __evenaccess * const ipr_reg_addr[ INHNO_MAX ] = {
	NULL, NULL, NULL, NULL, NULL,	/* No.0 - 4   予約 */
	NULL, NULL, NULL, NULL, NULL,	/* No.5 - 9   予約 */
	NULL, NULL, NULL, NULL, NULL,	/* No.10 - 14 予約 */
	NULL,							/* No.15  予約 */
	ICU_IPR00_ADDR,					/* No.16  バスエラー BUSERR */
	NULL, NULL, NULL, NULL,			/* No.17 - 20 予約 */
	ICU_IPR01_ADDR,					/* No.21  FCU FIFERR */
	NULL,							/* No.22  予約 */
	ICU_IPR02_ADDR,					/* No.23  FCU FRDYI */
	NULL, NULL, NULL, 				/* No.24 -26  予約 */
	ICU_IPR03_ADDR,					/* No.27  SWINT */
	ICU_IPR04_ADDR,					/* No.28  CMTユニット0 CMT0 */
	ICU_IPR05_ADDR,					/* No.29  CMTユニット0 CMT1 */
	ICU_IPR06_ADDR,					/* No.30  CMTユニット1 CMT2 */
	ICU_IPR07_ADDR,					/* No.31  CMTユニット1 CMT3 */
	NULL, NULL, NULL, NULL,			/* No.32 - 35 予約 */
	NULL, NULL, NULL, NULL,			/* No.36 - 39 予約 */
	NULL, NULL, NULL, NULL,			/* No.40 - 43 予約 */
	ICU_IPR14_ADDR,				 	/* No.44  SPEI0 */
	ICU_IPR14_ADDR,				 	/* No.45  SPRI0 */
	ICU_IPR14_ADDR,				 	/* No.46  SPTI0 */
	ICU_IPR14_ADDR,				 	/* No.47  SPII0 */
	NULL, NULL, NULL, NULL, 		/* No.48 - 51 予約 */
	NULL, NULL, NULL, NULL, 		/* No.52 - 55 予約 */
	ICU_IPR18_ADDR,				 	/* No.56 CAN0 ERS0 */
	ICU_IPR18_ADDR,				 	/* No.57 CAN0 RXF0 */
	ICU_IPR18_ADDR,				 	/* No.58 CAN0 TXF0 */
	ICU_IPR18_ADDR,				 	/* No.59 CAN0 RXM0 */
	ICU_IPR18_ADDR,				 	/* No.60 CAN0 TXM0 */
	NULL, NULL, NULL,        		/* No.61 - 63 予約 */
	ICU_IPR20_ADDR,					/* No.64  外部端子 IRQ0 */
	ICU_IPR21_ADDR,					/* No.65  外部端子 IRQ1 */
	ICU_IPR22_ADDR,					/* No.66  外部端子 IRQ2 */
	ICU_IPR23_ADDR,					/* No.67  外部端子 IRQ3 */
	ICU_IPR24_ADDR,					/* No.68  外部端子 IRQ4 */
	ICU_IPR25_ADDR,					/* No.69  外部端子 IRQ5 */
	ICU_IPR26_ADDR,					/* No.70  外部端子 IRQ6 */
	ICU_IPR27_ADDR,					/* No.71  外部端子 IRQ7 */
	NULL, NULL, NULL, NULL, 		/* No.72 - 75 予約 */
	NULL, NULL, NULL, NULL, 		/* No.76 - 79 予約 */
	NULL, NULL, NULL, NULL, NULL,	/* No.80 - 84 予約 */
	NULL, NULL, NULL, NULL, NULL,	/* No.85 - 89 予約 */
	NULL, NULL, NULL, NULL, NULL,	/* No.90 - 94 予約 */
	NULL,   			    		/* No.95 予約 */
	ICU_IPR40_ADDR,					/* No.96  WDT WOVI */
	NULL,   			    		/* No.97 予約 */
	ICU_IPR44_ADDR,					/* No.98  AD0 ADI0 */
	NULL, NULL, NULL,			    /* No.99 - 101 予約 */
	ICU_IPR48_ADDR,			    	/* No.102 S12AD0 */
	ICU_IPR48_ADDR,			    	/* No.103 S12AD1 */
	NULL, NULL,	        		    /* No.104 - 105 予約 */
	ICU_IPR49_ADDR,		    		/* No.106 CMPI */
	NULL, NULL, NULL, NULL, NULL,	/* No.107 - 111 予約 */
	NULL, NULL,         			/* No.112 - 113 予約 */
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
	NULL, NULL,      	            /* No.147 - 148 予約 */
	ICU_IPR5E_ADDR,		    		/* No.149 MTU7 TCIA7 */
	ICU_IPR5E_ADDR,		    		/* No.150 MTU7 TCIB7 */
	ICU_IPR5F_ADDR,		    		/* No.151 MTU7 TGIC7 */
	ICU_IPR5F_ADDR,		    		/* No.152 MTU7 TCID7 */
	ICU_IPR60_ADDR,		    		/* No.153 MTU7 TCIV7 */
	NULL, NULL, NULL, NULL, NULL,	/* No.154 - 158 予約 */
	NULL, NULL, NULL, NULL, NULL,	/* No.159 - 163 予約 */
	NULL, NULL, NULL, NULL, NULL,	/* No.164 - 168 予約 */
	NULL, 	                        /* No.169 予約 */
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
	NULL,                          	/* No.185 予約 */
	ICU_IPR6C_ADDR,	    			/* No.186 GPT2 GTCIA0 */
	ICU_IPR6C_ADDR,	    			/* No.187 GPT2 GTCIB0 */
	ICU_IPR6C_ADDR,	    			/* No.188 GPT2 GTCIC0 */
	ICU_IPR6D_ADDR,	    			/* No.189 GPT2 GTCIE0 */
	ICU_IPR6D_ADDR,	    			/* No.190 GPT2 GTCIV0 */
	NULL,                          	/* No.191 予約 */
	ICU_IPR6E_ADDR,		       		/* No.192 GPT3 GTCIA0 */
	ICU_IPR6E_ADDR,		       		/* No.193 GPT3 GTCIB0 */
	ICU_IPR6E_ADDR,		       		/* No.194 GPT3 GTCIC0 */
	ICU_IPR6F_ADDR,		       		/* No.195 GPT3 GTCIE0 */
	ICU_IPR6F_ADDR,		       		/* No.196 GPT3 GTCIV0 */
	NULL, NULL, NULL, NULL, NULL,	/* No.197 - 101 予約 */
    NULL, NULL, NULL, NULL, NULL,	/* No.102 - 106 予約 */
	NULL, NULL, NULL, NULL, NULL,	/* No.102 - 111 予約 */
	NULL, NULL,                   	/* No.112 - 113 予約 */
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
	NULL, NULL, NULL, NULL, NULL,	/* No.226 - 230 予約 */
	NULL, NULL, NULL, NULL, NULL,	/* No.231 - 235 予約 */
	NULL, NULL, NULL, NULL, NULL,	/* No.236 - 240 予約 */
	NULL, NULL, NULL, NULL, NULL,	/* No.241 - 245 予約 */
	ICU_IR88_ADDR,					/* No.246 RIIC0 ICEEI0 */
	ICU_IR89_ADDR,					/* No.247 RIIC0 ICRXI0 */
	ICU_IR8A_ADDR,					/* No.248 RIIC0 ICTXI0 */
	ICU_IR8B_ADDR,					/* No.249 RIIC0 ICTEI0 */
	NULL, NULL, NULL, NULL,     	/* No.250 - 253 予約 */
	ICU_IR90_ADDR,					/* No.254 LIN0 */
	NULL, 	    					/* No.255 予約 */
};


/*
 *  割込み要求許可レジスタアドレステーブル
 */
const IER_INFO ier_reg_addr[ INHNO_MAX ] = {
	{ NULL, INVALID_OFFSET },			/* No.0   予約 */
	{ NULL, INVALID_OFFSET },			/* No.1   予約 */
	{ NULL, INVALID_OFFSET },			/* No.2   予約 */
	{ NULL, INVALID_OFFSET },			/* No.3   予約 */
	{ NULL, INVALID_OFFSET },			/* No.4   予約 */
	{ NULL, INVALID_OFFSET },			/* No.5   予約 */
	{ NULL, INVALID_OFFSET },			/* No.6   予約 */
	{ NULL, INVALID_OFFSET },			/* No.7   予約 */
	{ NULL, INVALID_OFFSET },			/* No.8   予約 */
	{ NULL, INVALID_OFFSET },			/* No.9   予約 */
	{ NULL, INVALID_OFFSET },			/* No.10  予約 */
	{ NULL, INVALID_OFFSET },			/* No.11  予約 */
	{ NULL, INVALID_OFFSET },			/* No.12  予約 */
	{ NULL, INVALID_OFFSET },			/* No.13  予約 */
	{ NULL, INVALID_OFFSET },			/* No.14  予約 */
	{ NULL, INVALID_OFFSET },			/* No.15  予約 */
	{ ICU_IER02_ADDR, ICU_IEN0_BIT },	/* No.16  バスエラー BUSERR */
	{ NULL, INVALID_OFFSET },			/* No.17  予約 */
	{ NULL, INVALID_OFFSET },			/* No.18  予約 */
	{ NULL, INVALID_OFFSET },			/* No.19  予約 */
	{ NULL, INVALID_OFFSET },			/* No.20  予約 */
	{ ICU_IER02_ADDR, ICU_IEN5_BIT },	/* No.21  FCU FIFERR */
	{ NULL, INVALID_OFFSET },			/* No.22  予約 */
	{ ICU_IER02_ADDR, ICU_IEN7_BIT },	/* No.23  FCU FRDYI */
	{ NULL, INVALID_OFFSET },			/* No.24  予約 */
	{ NULL, INVALID_OFFSET },			/* No.25  予約 */
	{ NULL, INVALID_OFFSET },			/* No.26  予約 */
	{ ICU_IER03_ADDR, ICU_IEN3_BIT },	/* No.27  SWINT 予約 */
	{ ICU_IER03_ADDR, ICU_IEN4_BIT },	/* No.28  CMTユニット0 CMT0 */
	{ ICU_IER03_ADDR, ICU_IEN5_BIT },	/* No.29  CMTユニット0 CMT1 */
	{ ICU_IER03_ADDR, ICU_IEN6_BIT },	/* No.30  CMTユニット1 CMT2 */
	{ ICU_IER03_ADDR, ICU_IEN7_BIT },	/* No.31  CMTユニット1 CMT3 */
	{ NULL, INVALID_OFFSET },			/* No.32  予約 */
	{ NULL, INVALID_OFFSET },			/* No.33  予約 */
	{ NULL, INVALID_OFFSET },			/* No.34  予約 */
	{ NULL, INVALID_OFFSET },			/* No.35  予約 */
	{ NULL, INVALID_OFFSET },			/* No.36  予約 */
	{ NULL, INVALID_OFFSET },			/* No.37  予約 */
	{ NULL, INVALID_OFFSET },			/* No.38  予約 */
	{ NULL, INVALID_OFFSET },			/* No.39  予約 */
	{ NULL, INVALID_OFFSET },			/* No.40  予約 */
	{ NULL, INVALID_OFFSET },			/* No.41  予約 */
	{ NULL, INVALID_OFFSET },			/* No.42  予約 */
	{ NULL, INVALID_OFFSET },			/* No.43  予約 */
	{ ICU_IER05_ADDR, ICU_IEN4_BIT },	/* No.44  SPEI0 */
	{ ICU_IER05_ADDR, ICU_IEN5_BIT },	/* No.45  SPRI0 */
	{ ICU_IER05_ADDR, ICU_IEN6_BIT },	/* No.46  SPTI0 */
	{ ICU_IER05_ADDR, ICU_IEN7_BIT },	/* No.47  SPII0 */
	{ NULL, INVALID_OFFSET },			/* No.48  予約 */
	{ NULL, INVALID_OFFSET },			/* No.49  予約 */
	{ NULL, INVALID_OFFSET },			/* No.50  予約 */
	{ NULL, INVALID_OFFSET },			/* No.51  予約 */
	{ NULL, INVALID_OFFSET },			/* No.52  予約 */
	{ NULL, INVALID_OFFSET },			/* No.53  予約 */
	{ NULL, INVALID_OFFSET },			/* No.54  予約 */
	{ NULL, INVALID_OFFSET },			/* No.55  予約 */
	{ ICU_IER07_ADDR, ICU_IEN0_BIT },	/* No.56  CAN ERS0 */
	{ ICU_IER07_ADDR, ICU_IEN1_BIT },	/* No.57  CAN RXF0 */
	{ ICU_IER07_ADDR, ICU_IEN2_BIT },	/* No.58  CAN TXF0 */
	{ ICU_IER07_ADDR, ICU_IEN3_BIT },	/* No.59  CAN RXM0 */
	{ ICU_IER07_ADDR, ICU_IEN4_BIT },	/* No.60  CAN TXM0 */
	{ NULL, INVALID_OFFSET },			/* No.61  予約 */
	{ NULL, INVALID_OFFSET },			/* No.62  予約 */
	{ NULL, INVALID_OFFSET },			/* No.63  予約 */
	{ ICU_IER08_ADDR, ICU_IEN0_BIT },	/* No.64  外部端子 IRQ0 */
	{ ICU_IER08_ADDR, ICU_IEN1_BIT },	/* No.65  外部端子 IRQ1 */
	{ ICU_IER08_ADDR, ICU_IEN2_BIT },	/* No.66  外部端子 IRQ2 */
	{ ICU_IER08_ADDR, ICU_IEN3_BIT },	/* No.67  外部端子 IRQ3 */
	{ ICU_IER08_ADDR, ICU_IEN4_BIT },	/* No.68  外部端子 IRQ4 */
	{ ICU_IER08_ADDR, ICU_IEN5_BIT },	/* No.69  外部端子 IRQ5 */
	{ ICU_IER08_ADDR, ICU_IEN6_BIT },	/* No.70  外部端子 IRQ6 */
	{ ICU_IER08_ADDR, ICU_IEN7_BIT },	/* No.71  外部端子 IRQ7 */
	{ NULL, INVALID_OFFSET },			/* No.72  予約 */
	{ NULL, INVALID_OFFSET },			/* No.73  予約 */
	{ NULL, INVALID_OFFSET },			/* No.74  予約 */
	{ NULL, INVALID_OFFSET },			/* No.75  予約 */
	{ NULL, INVALID_OFFSET },			/* No.76  予約 */
	{ NULL, INVALID_OFFSET },			/* No.77  予約 */
	{ NULL, INVALID_OFFSET },			/* No.78  予約 */
	{ NULL, INVALID_OFFSET },			/* No.79  予約 */
	{ NULL, INVALID_OFFSET },			/* No.80  予約 */
	{ NULL, INVALID_OFFSET },			/* No.81  予約 */
	{ NULL, INVALID_OFFSET },			/* No.82  予約 */
	{ NULL, INVALID_OFFSET },			/* No.83  予約 */
	{ NULL, INVALID_OFFSET },			/* No.84  予約 */
	{ NULL, INVALID_OFFSET },			/* No.85  予約 */
	{ NULL, INVALID_OFFSET },			/* No.86  予約 */
	{ NULL, INVALID_OFFSET },			/* No.87  予約 */
	{ NULL, INVALID_OFFSET },			/* No.88  予約 */
	{ NULL, INVALID_OFFSET },			/* No.89  予約 */
	{ NULL, INVALID_OFFSET },			/* No.90  予約 */
	{ NULL, INVALID_OFFSET },			/* No.91  予約 */
	{ NULL, INVALID_OFFSET },			/* No.92  予約 */
	{ NULL, INVALID_OFFSET },			/* No.93  予約 */
	{ NULL, INVALID_OFFSET },			/* No.94  予約 */
	{ NULL, INVALID_OFFSET },			/* No.95  予約 */
	{ ICU_IER0C_ADDR, ICU_IEN0_BIT },	/* No.96  WDT WOVI */
	{ NULL, INVALID_OFFSET },			/* No.97  予約 */
	{ ICU_IER0C_ADDR, ICU_IEN2_BIT },	/* No.98  AD0 ADI0 */
	{ NULL, INVALID_OFFSET },			/* No.99 予約 */
	{ NULL, INVALID_OFFSET },			/* No.100 予約 */
	{ NULL, INVALID_OFFSET },			/* No.101 予約 */
	{ ICU_IER0C_ADDR, ICU_IEN6_BIT },	/* No.102 S12AD0 */
	{ ICU_IER0C_ADDR, ICU_IEN7_BIT },	/* No.103 S12AD0 */
	{ NULL, INVALID_OFFSET },			/* No.104 予約 */
	{ NULL, INVALID_OFFSET },			/* No.105 予約 */
	{ ICU_IER0D_ADDR, ICU_IEN2_BIT },	/* No.106 CMPI */
	{ NULL, INVALID_OFFSET },			/* No.107 予約 */
	{ NULL, INVALID_OFFSET },			/* No.108 予約 */
	{ NULL, INVALID_OFFSET },			/* No.109 予約 */
	{ NULL, INVALID_OFFSET },			/* No.110 予約 */
	{ NULL, INVALID_OFFSET },			/* No.111 予約 */
	{ NULL, INVALID_OFFSET },			/* No.112 予約 */
	{ NULL, INVALID_OFFSET },			/* No.113 予約 */
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
	{ NULL, INVALID_OFFSET },			/* No.147 予約 */
	{ NULL, INVALID_OFFSET },			/* No.148 予約 */
	{ ICU_IER12_ADDR, ICU_IEN5_BIT },	/* No.149 MTU7 TGIA7 */
	{ ICU_IER12_ADDR, ICU_IEN6_BIT },	/* No.150 MTU7 TGIB7 */
	{ ICU_IER12_ADDR, ICU_IEN7_BIT },	/* No.151 MTU7 TCIC7 */
	{ ICU_IER13_ADDR, ICU_IEN0_BIT },	/* No.152 MTU7 TCID7 */
	{ ICU_IER13_ADDR, ICU_IEN1_BIT },	/* No.153 MTU7 TCIV7 */
	{ NULL, INVALID_OFFSET },			/* No.154 予約 */
	{ NULL, INVALID_OFFSET },			/* No.155 予約 */
	{ NULL, INVALID_OFFSET },			/* No.156 予約 */
	{ NULL, INVALID_OFFSET },			/* No.157 予約 */
	{ NULL, INVALID_OFFSET },			/* No.158 予約 */
	{ NULL, INVALID_OFFSET },			/* No.159 予約 */
	{ NULL, INVALID_OFFSET },			/* No.160 予約 */
	{ NULL, INVALID_OFFSET },			/* No.161 予約 */
	{ NULL, INVALID_OFFSET },			/* No.162 予約 */
	{ NULL, INVALID_OFFSET },			/* No.163 予約 */
	{ NULL, INVALID_OFFSET },			/* No.164 予約 */
	{ NULL, INVALID_OFFSET },			/* No.165 予約 */
	{ NULL, INVALID_OFFSET },			/* No.166 予約 */
	{ NULL, INVALID_OFFSET },			/* No.167 予約 */
	{ NULL, INVALID_OFFSET },			/* No.168 予約 */
	{ NULL, INVALID_OFFSET },			/* No.169 予約 */
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
	{ NULL, INVALID_OFFSET },			/* No.185 予約 */
	{ ICU_IER17_ADDR, ICU_IEN2_BIT },	/* No.186 GPT2 GTCIA0 */
	{ ICU_IER17_ADDR, ICU_IEN3_BIT },	/* No.187 GPT2 GTCIB0 */
	{ ICU_IER17_ADDR, ICU_IEN4_BIT },	/* No.188 GPT2 GTCIC0 */
	{ ICU_IER17_ADDR, ICU_IEN5_BIT },	/* No.189 GPT2 GTCIE0 */
	{ ICU_IER17_ADDR, ICU_IEN6_BIT },	/* No.190 GPT2 GTCIV0 */
	{ NULL, INVALID_OFFSET },			/* No.191 予約 */
	{ ICU_IER17_ADDR, ICU_IEN7_BIT },	/* No.192 GPT3 GTCIA0 */
	{ ICU_IER18_ADDR, ICU_IEN0_BIT },	/* No.193 GPT3 GTCIB0 */
	{ ICU_IER18_ADDR, ICU_IEN1_BIT },	/* No.194 GPT3 GTCIC0 */
	{ ICU_IER18_ADDR, ICU_IEN2_BIT },	/* No.195 GPT3 GTCIE0 */
	{ ICU_IER18_ADDR, ICU_IEN3_BIT },	/* No.196 GPT3 GTCIV0 */
	{ NULL, INVALID_OFFSET },			/* No.197 予約 */
	{ NULL, INVALID_OFFSET },			/* No.198 予約 */
	{ NULL, INVALID_OFFSET },			/* No.199 予約 */
	{ NULL, INVALID_OFFSET },			/* No.200 予約 */
	{ NULL, INVALID_OFFSET },			/* No.201 予約 */
	{ NULL, INVALID_OFFSET },			/* No.202 予約 */
	{ NULL, INVALID_OFFSET },			/* No.203 予約 */
	{ NULL, INVALID_OFFSET },			/* No.204 予約 */
	{ NULL, INVALID_OFFSET },			/* No.205 予約 */
	{ NULL, INVALID_OFFSET },			/* No.206 予約 */
	{ NULL, INVALID_OFFSET },			/* No.207 予約 */
	{ NULL, INVALID_OFFSET },			/* No.208 予約 */
	{ NULL, INVALID_OFFSET },			/* No.209 予約 */
	{ NULL, INVALID_OFFSET },			/* No.210 予約 */
	{ NULL, INVALID_OFFSET },			/* No.211 予約 */
	{ NULL, INVALID_OFFSET },			/* No.212 予約 */
	{ NULL, INVALID_OFFSET },			/* No.213 予約 */
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
	{ NULL, INVALID_OFFSET },			/* No.226 予約 */
	{ NULL, INVALID_OFFSET },			/* No.227 予約 */
	{ NULL, INVALID_OFFSET },			/* No.228 予約 */
	{ NULL, INVALID_OFFSET },			/* No.229 予約 */
	{ NULL, INVALID_OFFSET },			/* No.230 予約 */
	{ NULL, INVALID_OFFSET },			/* No.231 予約 */
	{ NULL, INVALID_OFFSET },			/* No.232 予約 */
	{ NULL, INVALID_OFFSET },			/* No.233 予約 */
	{ NULL, INVALID_OFFSET },			/* No.234 予約 */
	{ NULL, INVALID_OFFSET },			/* No.235 予約 */
	{ NULL, INVALID_OFFSET },			/* No.236 予約 */
	{ NULL, INVALID_OFFSET },			/* No.237 予約 */
	{ NULL, INVALID_OFFSET },			/* No.238 予約 */
	{ NULL, INVALID_OFFSET },			/* No.239 予約 */
	{ NULL, INVALID_OFFSET },			/* No.240 予約 */
	{ NULL, INVALID_OFFSET },			/* No.241 予約 */
	{ NULL, INVALID_OFFSET },			/* No.242 予約 */
	{ NULL, INVALID_OFFSET },			/* No.242 予約 */
	{ NULL, INVALID_OFFSET },			/* No.243 予約 */
	{ NULL, INVALID_OFFSET },			/* No.244 予約 */
	{ NULL, INVALID_OFFSET },			/* No.245 予約 */
	{ ICU_IER1E_ADDR, ICU_IEN6_BIT },	/* No.246 RIIC0 ICEEI0 */
	{ ICU_IER1E_ADDR, ICU_IEN7_BIT },	/* No.247 RIIC0 ICRXI0 */
	{ ICU_IER1F_ADDR, ICU_IEN0_BIT },	/* No.248 RIIC0 ICTXI0 */
	{ ICU_IER1F_ADDR, ICU_IEN1_BIT },	/* No.249 RIIC0 ICTEI0 */
	{ NULL, INVALID_OFFSET },			/* No.250 予約 */
	{ NULL, INVALID_OFFSET },			/* No.251 予約 */
	{ NULL, INVALID_OFFSET },			/* No.252 予約 */
	{ NULL, INVALID_OFFSET },			/* No.253 予約 */
	{ ICU_IER1F_ADDR, ICU_IEN6_BIT },	/* No.254 LIN0 */
	{ NULL, INVALID_OFFSET },			/* No.255 予約 */
};


/*
 *  IRQコントロールレジスタアドレステーブル
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

