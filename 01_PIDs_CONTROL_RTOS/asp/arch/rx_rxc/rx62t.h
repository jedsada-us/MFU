/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 *
 *  Copyright (C) 2008-2010 by Witz Corporation, JAPAN
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
 *  RX62Tに依存する定義
 */
#ifndef TOPPERS_RX62T_H
#define TOPPERS_RX62T_H

/*
 *  CPU例外ハンドラ番号の定義(固定ベクタテーブル)
 *
 *  番号の範囲は0 - 31
 */
#define INT_PRIVILEGED_INSTRUNCTION		20		/* 特権命令例外 */
#define INT_UNDEF_INSTRUNCTION			23		/* 未定義命令例外 */
#define INT_FLOATINGPOINT_INSTRUCTION	25		/* 浮動小数点例外 */
#define INT_NMI							30		/* ノンマスカブル割り込み */
#define INT_RESET						31		/* リセット */

/*
 *  割込み番号の定義(可変ベクタテーブル)
 */
#define INT_BUSERR			            16
#define INT_FCU_FCUERR		            21
#define INT_FCU_FRDYI		            23
#define INT_ICU_SWINT		            27
#define INT_CMT0_CMI		            28
#define INT_CMT1_CMI		            29
#define INT_CMT2_CMI		            30
#define INT_CMT3_CMI		            31
#define INT_IRQ0			            64
#define INT_IRQ1			            65
#define INT_IRQ2			            66
#define INT_IRQ3			            67
#define INT_IRQ4			            68
#define INT_IRQ5			            69
#define INT_IRQ6			            70
#define INT_IRQ7			            71
#define INT_WDT_WOVI		            96
#define INT_AD0_ADI0		            98
#define INT_S12AD0_S12ADI0	            102
#define INT_S12AD1_S12ADI1	            103
#define INT_TPU0_TGI0A		            114
#define INT_TPU0_TGI0B		            115
#define INT_TPU0_TGI0C		            116
#define INT_TPU0_TGI0D		            117
#define INT_TPU0_TCI0V		            118
#define INT_TPU0_TGI0E		            119
#define INT_TPU0_TGI0F		            120
#define INT_TPU1_TGI1A		            121
#define INT_TPU1_TGI1B		            122
#define INT_TPU1_TCI1V		            123
#define INT_TPU1_TCI1U		            124
#define INT_TPU2_TGI2A		            125
#define INT_TPU2_TGI2B		            126
#define INT_TPU2_TCI2V		            127
#define INT_TPU2_TCI2U		            128
#define INT_TPU3_TGI3A		            129
#define INT_TPU3_TGI3B		            130
#define INT_TPU3_TGI3C		            131
#define INT_TPU3_TGI3D		            132
#define INT_TPU3_TCI3V		            133
#define INT_TPU4_TGI4A		            134
#define INT_TPU4_TGI4B		            135
#define INT_TPU4_TGI4C		            136
#define INT_TPU4_TGI4D		            137
#define INT_TPU4_TCI4V		            138
#define INT_TPU5_TGI5U		            139
#define INT_TPU5_TGI5V		            140
#define INT_TPU5_TGI5W		            141
#define INT_TPU6_TGI6A		            142
#define INT_TPU6_TGI6B		            143
#define INT_TPU6_TGI6C		            144
#define INT_TPU6_TGI6D		            145
#define INT_TPU6_TCI6V		            146
#define INT_TPU7_TGI7A		            149
#define INT_TPU7_TGI7B		            150
#define INT_TPU7_TGI7C		            151
#define INT_TPU7_TGI7D		            152
#define INT_TPU7_TGI7V		            153
#define INT_SCI0_ERI		            214
#define INT_SCI0_RXI		            215
#define INT_SCI0_TXI		            216
#define INT_SCI0_TEI		            217
#define INT_SCI1_ERI		            218
#define INT_SCI1_RXI		            219
#define INT_SCI1_TXI		            220
#define INT_SCI1_TEI		            221
#define INT_SCI2_ERI		            222
#define INT_SCI2_RXI		            223
#define INT_SCI2_TXI		            224
#define INT_SCI2_TEI		            225
#define INT_RIIC0_EEI		            246
#define INT_RIIC0_RXI		            247
#define INT_RIIC0_TXI		            248
#define INT_RIIC0_TEI		            249

/*
 *  各モジュールのレジスタ及び設定ビット情報
 */
/*
 * モジュールストップコントロールレジスタA（MSTPCRA）
 */
#define SYSTEM_MSTPCRA_ADDR			    ( ( volatile uint32_t __evenaccess * )0x00080010 )
#define SYSTEM_MSTPCRA_MSTPA7_BIT	    ( 1UL << 7U )
#define SYSTEM_MSTPCRA_MSTPA9_BIT	    ( 1UL << 9U )
#define SYSTEM_MSTPCRA_MSTPA14_BIT	    ( 1UL << 14U )
#define SYSTEM_MSTPCRA_MSTPA15_BIT	    ( 1UL << 15U )
#define SYSTEM_MSTPCRA_MSTPA16_BIT	    ( 1UL << 16U )
#define SYSTEM_MSTPCRA_MSTPA17_BIT	    ( 1UL << 17U )
#define SYSTEM_MSTPCRA_MSTPA23_BIT	    ( 1UL << 23U )
#define SYSTEM_MSTPCRA_MSTPA24_BIT	    ( 1UL << 24U )
#define SYSTEM_MSTPCRA_MSTPA28_BIT	    ( 1UL << 28U )
#define SYSTEM_MSTPCRA_ACSE_BIT		    ( 1UL << 31U)

/*
 * モジュールストップコントロールレジスタB（MSTPCRB）
 */
#define SYSTEM_MSTPCRB_ADDR			    ( ( volatile uint32_t __evenaccess * )0x00080014 )
#define SYSTEM_MSTPCRB_MSTPB0_BIT	    ( 1UL << 0U )
#define SYSTEM_MSTPCRB_MSTPB7_BIT	    ( 1UL << 7U )
#define SYSTEM_MSTPCRB_MSTPB17_BIT	    ( 1UL << 17U )
#define SYSTEM_MSTPCRB_MSTPB21_BIT	    ( 1UL << 21U )
#define SYSTEM_MSTPCRB_MSTPB23_BIT	    ( 1UL << 23U )
#define SYSTEM_MSTPCRB_MSTPB29_BIT	    ( 1UL << 29U )
#define SYSTEM_MSTPCRB_MSTPB30_BIT	    ( 1UL << 30U )
#define SYSTEM_MSTPCRB_MSTPB31_BIT	    ( 1UL << 31U )

/*
 * モジュールストップコントロールレジスタC（MSTPCRC）
 */
#define SYSTEM_MSTPCRC_ADDR			    ( ( volatile uint32_t __evenaccess * )0x00080018 )
#define SYSTEM_MSTPCRC_MSTPC0_BIT	    ( 1UL << 0U )

/*
 * EXTAL clock SCKCR
 */
#define SYSTEM_SCKCR_ADDR			    ( ( volatile uint32_t __evenaccess * )0x00080020 )


/*
 * 割り込み要求レジスタ
 */
#define ICU_IR016_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087010 )
#define ICU_IR021_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087015 )
#define ICU_IR023_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087017 )
#define ICU_IR027_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008701B )
#define ICU_IR028_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008701C )
#define ICU_IR029_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008701D )
#define ICU_IR030_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008701E )
#define ICU_IR031_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008701F )
#define ICU_IR044_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008702C )
#define ICU_IR045_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008702D )
#define ICU_IR046_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008702E )
#define ICU_IR047_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008702F )
#define ICU_IR056_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087038 )
#define ICU_IR057_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087039 )
#define ICU_IR058_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008703A )
#define ICU_IR059_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008703B )
#define ICU_IR060_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008703C )
#define ICU_IR064_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087040 )
#define ICU_IR065_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087041 )
#define ICU_IR066_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087042 )
#define ICU_IR067_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087043 )
#define ICU_IR068_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087044 )
#define ICU_IR069_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087045 )
#define ICU_IR070_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087046 )
#define ICU_IR071_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087047 )
#define ICU_IR096_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087060 )
#define ICU_IR098_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087062 )
#define ICU_IR102_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087066 )
#define ICU_IR103_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087067 )
#define ICU_IR106_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008706A )
#define ICU_IR114_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087072 )
#define ICU_IR115_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087073 )
#define ICU_IR116_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087074 )
#define ICU_IR117_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087075 )
#define ICU_IR118_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087076 )
#define ICU_IR119_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087077 )
#define ICU_IR120_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087078 )
#define ICU_IR121_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087079 )
#define ICU_IR122_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008707A )
#define ICU_IR123_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008707B )
#define ICU_IR124_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008707C )
#define ICU_IR125_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008707D )
#define ICU_IR126_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008707E )
#define ICU_IR127_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008707F )
#define ICU_IR128_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087080 )
#define ICU_IR129_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087081 )
#define ICU_IR130_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087082 )
#define ICU_IR131_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087083 )
#define ICU_IR132_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087084 )
#define ICU_IR133_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087085 )
#define ICU_IR134_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087086 )
#define ICU_IR135_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087087 )
#define ICU_IR136_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087088 )
#define ICU_IR137_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087089 )
#define ICU_IR138_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008708A )
#define ICU_IR139_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008708B )
#define ICU_IR140_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008708C )
#define ICU_IR141_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008708D )
#define ICU_IR142_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008708E )
#define ICU_IR143_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008708F )
#define ICU_IR144_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087090 )
#define ICU_IR145_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087091 )
#define ICU_IR146_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087092 )
#define ICU_IR149_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087095 )
#define ICU_IR150_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087096 )
#define ICU_IR151_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087097 )
#define ICU_IR152_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087098 )
#define ICU_IR153_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087099 )
#define ICU_IR170_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000870AA )
#define ICU_IR171_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000870AB )
#define ICU_IR172_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000870AC )
#define ICU_IR173_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000870AD )
#define ICU_IR174_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000870AE )
#define ICU_IR175_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000870AF )
#define ICU_IR176_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000870B0 )
#define ICU_IR177_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000870B1 )
#define ICU_IR178_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000870B2 )
#define ICU_IR179_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000870B3 )
#define ICU_IR180_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000870B4 )
#define ICU_IR181_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000870B5 )
#define ICU_IR182_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000870B6 )
#define ICU_IR183_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000870B7 )
#define ICU_IR184_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000870B8 )
#define ICU_IR186_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000870BA )
#define ICU_IR187_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000870BB )
#define ICU_IR188_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000870BC )
#define ICU_IR189_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000870BD )
#define ICU_IR190_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000870BE )
#define ICU_IR192_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000870C0 )
#define ICU_IR193_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000870C1 )
#define ICU_IR194_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000870C2 )
#define ICU_IR195_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000870C3 )
#define ICU_IR196_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000870C4 )
#define ICU_IR214_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000870D6 )
#define ICU_IR215_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000870D7 )
#define ICU_IR216_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000870D8 )
#define ICU_IR217_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000870D9 )
#define ICU_IR218_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000870DA )
#define ICU_IR219_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000870DB )
#define ICU_IR220_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000870DC )
#define ICU_IR221_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000870DD )
#define ICU_IR222_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000870DE )
#define ICU_IR223_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000870DF )
#define ICU_IR224_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000870E0 )
#define ICU_IR225_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000870E1 )
#define ICU_IR246_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000870F6 )
#define ICU_IR247_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000870F7 )
#define ICU_IR248_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000870F8 )
#define ICU_IR249_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000870F9 )
#define ICU_IR254_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000870FE )
#define ICU_IR_BIT				        ( 1U << 0U )

/*
 * 割り込み要求先設定レジスタ
 */
#define ICU_ISELR027_ADDR		        ( ( volatile uint8_t __evenaccess * )0x0008711B )
#define ICU_ISELR028_ADDR		        ( ( volatile uint8_t __evenaccess * )0x0008711C )
#define ICU_ISELR029_ADDR		        ( ( volatile uint8_t __evenaccess * )0x0008711D )
#define ICU_ISELR030_ADDR		        ( ( volatile uint8_t __evenaccess * )0x0008711E )
#define ICU_ISELR031_ADDR		        ( ( volatile uint8_t __evenaccess * )0x0008711F )
#define ICU_ISELR045_ADDR		        ( ( volatile uint8_t __evenaccess * )0x0008712D )
#define ICU_ISELR046_ADDR		        ( ( volatile uint8_t __evenaccess * )0x0008712E )
#define ICU_ISELR064_ADDR		        ( ( volatile uint8_t __evenaccess * )0x00087140 )
#define ICU_ISELR065_ADDR		        ( ( volatile uint8_t __evenaccess * )0x00087141 )
#define ICU_ISELR066_ADDR		        ( ( volatile uint8_t __evenaccess * )0x00087142 )
#define ICU_ISELR067_ADDR		        ( ( volatile uint8_t __evenaccess * )0x00087143 )
#define ICU_ISELR068_ADDR		        ( ( volatile uint8_t __evenaccess * )0x00087144 )
#define ICU_ISELR069_ADDR		        ( ( volatile uint8_t __evenaccess * )0x00087145 )
#define ICU_ISELR070_ADDR		        ( ( volatile uint8_t __evenaccess * )0x00087146 )
#define ICU_ISELR071_ADDR		        ( ( volatile uint8_t __evenaccess * )0x00087147 )
#define ICU_ISELR098_ADDR		        ( ( volatile uint8_t __evenaccess * )0x00087162 )
#define ICU_ISELR102_ADDR		        ( ( volatile uint8_t __evenaccess * )0x00087166 )
#define ICU_ISELR103_ADDR		        ( ( volatile uint8_t __evenaccess * )0x00087167 )
#define ICU_ISELR106_ADDR		        ( ( volatile uint8_t __evenaccess * )0x0008716A )
#define ICU_ISELR114_ADDR		        ( ( volatile uint8_t __evenaccess * )0x00087172 )
#define ICU_ISELR115_ADDR		        ( ( volatile uint8_t __evenaccess * )0x00087173 )
#define ICU_ISELR116_ADDR		        ( ( volatile uint8_t __evenaccess * )0x00087174 )
#define ICU_ISELR117_ADDR		        ( ( volatile uint8_t __evenaccess * )0x00087175 )
#define ICU_ISELR121_ADDR		        ( ( volatile uint8_t __evenaccess * )0x00087179 )
#define ICU_ISELR122_ADDR		        ( ( volatile uint8_t __evenaccess * )0x0008717A )
#define ICU_ISELR125_ADDR		        ( ( volatile uint8_t __evenaccess * )0x0008717D )
#define ICU_ISELR126_ADDR		        ( ( volatile uint8_t __evenaccess * )0x0008717E )
#define ICU_ISELR129_ADDR		        ( ( volatile uint8_t __evenaccess * )0x00087181 )
#define ICU_ISELR130_ADDR		        ( ( volatile uint8_t __evenaccess * )0x00087182 )
#define ICU_ISELR131_ADDR		        ( ( volatile uint8_t __evenaccess * )0x00087183 )
#define ICU_ISELR132_ADDR		        ( ( volatile uint8_t __evenaccess * )0x00087184 )
#define ICU_ISELR134_ADDR		        ( ( volatile uint8_t __evenaccess * )0x00087186 )
#define ICU_ISELR135_ADDR		        ( ( volatile uint8_t __evenaccess * )0x00087187 )
#define ICU_ISELR136_ADDR		        ( ( volatile uint8_t __evenaccess * )0x00087188 )
#define ICU_ISELR137_ADDR		        ( ( volatile uint8_t __evenaccess * )0x00087189 )
#define ICU_ISELR138_ADDR		        ( ( volatile uint8_t __evenaccess * )0x0008718A )
#define ICU_ISELR139_ADDR		        ( ( volatile uint8_t __evenaccess * )0x0008718B )
#define ICU_ISELR140_ADDR		        ( ( volatile uint8_t __evenaccess * )0x0008718C )
#define ICU_ISELR141_ADDR		        ( ( volatile uint8_t __evenaccess * )0x0008718D )
#define ICU_ISELR142_ADDR		        ( ( volatile uint8_t __evenaccess * )0x0008718E )
#define ICU_ISELR143_ADDR		        ( ( volatile uint8_t __evenaccess * )0x0008718F )
#define ICU_ISELR144_ADDR		        ( ( volatile uint8_t __evenaccess * )0x00087190 )
#define ICU_ISELR145_ADDR		        ( ( volatile uint8_t __evenaccess * )0x00087191 )
#define ICU_ISELR149_ADDR		        ( ( volatile uint8_t __evenaccess * )0x00087195 )
#define ICU_ISELR150_ADDR		        ( ( volatile uint8_t __evenaccess * )0x00087196 )
#define ICU_ISELR151_ADDR		        ( ( volatile uint8_t __evenaccess * )0x00087197 )
#define ICU_ISELR152_ADDR		        ( ( volatile uint8_t __evenaccess * )0x00087198 )
#define ICU_ISELR153_ADDR		        ( ( volatile uint8_t __evenaccess * )0x00087199 )
#define ICU_ISELR174_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000871AE )
#define ICU_ISELR175_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000871AF )
#define ICU_ISELR176_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000871B0 )
#define ICU_ISELR177_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000871B1 )
#define ICU_ISELR178_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000871B2 )
#define ICU_ISELR179_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000871B3 )
#define ICU_ISELR180_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000871B4 )
#define ICU_ISELR181_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000871B5 )
#define ICU_ISELR182_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000871B6 )
#define ICU_ISELR183_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000871B7 )
#define ICU_ISELR184_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000871B8 )
#define ICU_ISELR186_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000871BA )
#define ICU_ISELR187_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000871BB )
#define ICU_ISELR188_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000871BC )
#define ICU_ISELR189_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000871BD )
#define ICU_ISELR190_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000871BE )
#define ICU_ISELR192_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000871C0 )
#define ICU_ISELR193_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000871C1 )
#define ICU_ISELR194_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000871C2 )
#define ICU_ISELR195_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000871C3 )
#define ICU_ISELR196_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000871C4 )
#define ICU_ISELR215_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000871D7 )
#define ICU_ISELR216_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000871D8 )
#define ICU_ISELR219_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000871DB )
#define ICU_ISELR220_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000871DC )
#define ICU_ISELR223_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000871DF )
#define ICU_ISELR224_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000871E0 )
#define ICU_ISELR247_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000871F7 )
#define ICU_ISELR248_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000871F8 )
#define ICU_ISELR254_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000871FE )
#define ICU_ISEL_BIT			        ( 3U << 0U )

/*
 * 割り込み要求許可レジスタ
 */
#define ICU_IER02_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087202 )
#define ICU_IER03_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087203 )
#define ICU_IER05_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087205 )
#define ICU_IER07_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087207 )
#define ICU_IER08_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087208 )
#define ICU_IER0C_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008720C )
#define ICU_IER0D_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008720D )
#define ICU_IER0E_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008720E )
#define ICU_IER0F_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008720F )
#define ICU_IER10_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087210 )
#define ICU_IER11_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087211 )
#define ICU_IER12_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087212 )
#define ICU_IER13_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087213 )
#define ICU_IER15_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087215 )
#define ICU_IER16_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087216 )
#define ICU_IER17_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087217 )
#define ICU_IER18_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087218 )
#define ICU_IER1A_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008721A )
#define ICU_IER1B_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008721B )
#define ICU_IER1C_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008721C )
#define ICU_IER1E_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008721E )
#define ICU_IER1F_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008721F )
#define ICU_IEN0_BIT			        ( 1U << 0U )
#define ICU_IEN1_BIT			        ( 1U << 1U )
#define ICU_IEN2_BIT			        ( 1U << 2U )
#define ICU_IEN3_BIT			        ( 1U << 3U )
#define ICU_IEN4_BIT			        ( 1U << 4U )
#define ICU_IEN5_BIT			        ( 1U << 5U )
#define ICU_IEN6_BIT			        ( 1U << 6U )
#define ICU_IEN7_BIT			        ( 1U << 7U )

/*
 * 割り込み要因プライオリティレジスタi(i=00h～8Fh)の設定
 */
#define ICU_IPR00_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087300 )
#define ICU_IPR01_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087301 )
#define ICU_IPR02_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087302 )
#define ICU_IPR03_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087303 )
#define ICU_IPR04_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087304 )
#define ICU_IPR05_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087305 )
#define ICU_IPR06_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087306 )
#define ICU_IPR07_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087307 )
#define ICU_IPR14_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087314 )
#define ICU_IPR18_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087318 )
#define ICU_IPR20_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087320 )
#define ICU_IPR21_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087321 )
#define ICU_IPR22_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087322 )
#define ICU_IPR23_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087323 )
#define ICU_IPR24_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087324 )
#define ICU_IPR25_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087325 )
#define ICU_IPR26_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087326 )
#define ICU_IPR27_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087327 )
#define ICU_IPR40_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087340 )
#define ICU_IPR44_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087344 )
#define ICU_IPR48_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087348 )
#define ICU_IPR49_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087349 )
#define ICU_IPR51_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087351 )
#define ICU_IPR52_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087352 )
#define ICU_IPR53_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087353 )
#define ICU_IPR54_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087354 )
#define ICU_IPR55_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087355 )
#define ICU_IPR56_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087356 )
#define ICU_IPR57_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087357 )
#define ICU_IPR58_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087358 )
#define ICU_IPR59_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087359 )
#define ICU_IPR5A_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008735A )
#define ICU_IPR5B_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008735B )
#define ICU_IPR5C_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008735C )
#define ICU_IPR5D_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008735D )
#define ICU_IPR5E_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008735E )
#define ICU_IPR5F_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008735F )
#define ICU_IPR60_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087360 )
#define ICU_IPR67_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087367 )
#define ICU_IPR68_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087368 )
#define ICU_IPR69_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087369 )
#define ICU_IPR6A_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008736A )
#define ICU_IPR6B_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008736B )
#define ICU_IPR6C_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008736C )
#define ICU_IPR6D_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008736D )
#define ICU_IPR6E_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008736E )
#define ICU_IPR6F_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008736F )
#define ICU_IPR80_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087380 )
#define ICU_IPR81_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087381 )
#define ICU_IPR82_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087382 )
#define ICU_IPR88_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087388 )
#define ICU_IPR89_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087389 )
#define ICU_IPR8A_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008738A )
#define ICU_IPR8B_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008738B )
#define ICU_IPR90_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087390 )
#define ICU_IPR_BIT				        ( 7U << 0U )


/*
 *  IRQコントロールレジスタ
 */
#define ICU_IRQ0_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087500 )
#define ICU_IRQ1_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087501 )
#define ICU_IRQ2_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087502 )
#define ICU_IRQ3_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087503 )
#define ICU_IRQ4_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087504 )
#define ICU_IRQ5_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087505 )
#define ICU_IRQ6_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087506 )
#define ICU_IRQ7_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087507 )
#define ICU_IRQMD_BIT			        ( 3U << 2U )

/*
 *  Non-Maskable Interrupt Enable Register (NMIER)
 */
#define ICU_NMIER_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087581 )
#define ICU_NMIEN_BIT			        ( 1U << 0U )
#define ICU_LVDEN_BIT			        ( 1U << 1U )
#define ICU_OSTEN_BIT			        ( 1U << 2U )

/*
 *  Non-Maskable Interrupt Clear Register (NMICLR)
 */
#define ICU_NMICLR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087582 )
#define ICU_NMICLR_BIT			        ( 1U << 0U )
#define ICU_OSTCLR_BIT			        ( 1U << 2U )

/*
 *  Non-Maskable Interrupt Control Register (NMICR)
 */
#define ICU_NMICR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00087583 )
#define ICU_NMIMD_BIT			        ( 1U << 3U )


/*
 *  各チャンネルのレジスタ及び設定ビット情報
 */
#define CMT_CMSTR0_ADDR			        ( ( volatile uint16_t __evenaccess * )0x00088000 )
#define CMT_CMSTR0_STR0_BIT		        ( 1U << 0U )
#define CMT_CMSTR0_STR1_BIT		        ( 1U << 1U )
#define CMT_CMSTR1_ADDR			        ( ( volatile uint16_t __evenaccess * )0x00088010 )
#define CMT_CMSTR1_STR2_BIT		        ( 1U << 0U )
#define CMT_CMSTR1_STR3_BIT		        ( 1U << 1U )
#define CMT0_CMCR_ADDR			        ( ( volatile uint16_t __evenaccess * )0x00088002 )
#define CMT0_CMCR_CKS_BIT		        ( 3U )
#define CMT0_CMCR_CMIE_BIT		        ( 1U << 6U )
#define CMT1_CMCR_ADDR			        ( ( volatile uint16_t __evenaccess * )0x00088008 )
#define CMT1_CMCR_CKS_BIT		        ( 3U )
#define CMT1_CMCR_CMIE_BIT		        ( 1U << 6U )
#define CMT2_CMCR_ADDR			        ( ( volatile uint16_t __evenaccess * )0x00088012 )
#define CMT2_CMCR_CKS_BIT		        ( 3U)
#define CMT2_CMCR_CMIE_BIT		        ( 1U << 6U )
#define CMT3_CMCR_ADDR			        ( ( volatile uint16_t __evenaccess * )0x00088018 )
#define CMT3_CMCR_CKS_BIT		        ( 3U )
#define CMT3_CMCR_CMIE_BIT		        ( 1U << 6U )
#define CMT0_CMCNT_ADDR			        ( ( volatile uint16_t __evenaccess * )0x00088004 )
#define CMT1_CMCNT_ADDR			        ( ( volatile uint16_t __evenaccess * )0x0008800A )
#define CMT2_CMCNT_ADDR			        ( ( volatile uint16_t __evenaccess * )0x00088014 )
#define CMT3_CMCNT_ADDR			        ( ( volatile uint16_t __evenaccess * )0x0008801A )
#define CMT0_CMCOR_ADDR			        ( ( volatile uint16_t __evenaccess * )0x00088006 )
#define CMT1_CMCOR_ADDR			        ( ( volatile uint16_t __evenaccess * )0x0008800C )
#define CMT2_CMCOR_ADDR			        ( ( volatile uint16_t __evenaccess * )0x00088016 )
#define CMT3_CMCOR_ADDR			        ( ( volatile uint16_t __evenaccess * )0x0008801C )

/*
 * Registers of A/D Converter 10bits
 */
#define ADC_ADDRA_ADDR			        ( ( volatile uint16_t __evenaccess * )0x00088040 )
#define ADC_ADDRB_ADDR			        ( ( volatile uint16_t __evenaccess * )0x00088042 )
#define ADC_ADDRC_ADDR			        ( ( volatile uint16_t __evenaccess * )0x00088044 )
#define ADC_ADDRD_ADDR			        ( ( volatile uint16_t __evenaccess * )0x00088046 )
#define ADC_ADDRE_ADDR			        ( ( volatile uint16_t __evenaccess * )0x00088048 )
#define ADC_ADDRF_ADDR			        ( ( volatile uint16_t __evenaccess * )0x0008804A )
#define ADC_ADDRG_ADDR			        ( ( volatile uint16_t __evenaccess * )0x0008804C )
#define ADC_ADDRH_ADDR			        ( ( volatile uint16_t __evenaccess * )0x0008804E )
#define ADC_ADDRI_ADDR			        ( ( volatile uint16_t __evenaccess * )0x00088060 )
#define ADC_ADDRJ_ADDR			        ( ( volatile uint16_t __evenaccess * )0x00088062 )
#define ADC_ADDRK_ADDR			        ( ( volatile uint16_t __evenaccess * )0x00088064 )
#define ADC_ADDRL_ADDR			        ( ( volatile uint16_t __evenaccess * )0x00088066 )
#define ADC_ADCSR_ADDR			        ( ( volatile uint8_t __evenaccess *  )0x00088050 )
#define ADC_ADCR_ADDR			        ( ( volatile uint8_t __evenaccess *  )0x00088051 )
#define ADC_ADSSTR_ADDR			        ( ( volatile uint8_t __evenaccess *  )0x0008805B )
#define ADC_ADDIAGR_ADDR		        ( ( volatile uint8_t __evenaccess *  )0x0008805D )
#define ADC_ADSTRGR_ADDR		        ( ( volatile uint8_t __evenaccess *  )0x00088070 )
#define ADC_ADDPR_ADDR			        ( ( volatile uint8_t __evenaccess *  )0x00088072 )
#define ADC_ADST_BIT	                ( 1UL << 5U )

/*
 * Registers of Serial Communications Interface (SCIb)
 */
#define SCI0_SMR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00088240 )
#define SCI0_BRR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00088241 )
#define SCI0_SCR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00088242 )
#define SCI0_TDR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00088243 )
#define SCI0_SSR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00088244 )
#define SCI0_RDR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00088245 )
#define SCI0_SCMR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00088246 )
#define SCI0_SEMR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00088247 )
#define SCI1_SMR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00088248 )
#define SCI1_BRR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00088249 )
#define SCI1_SCR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008824A )
#define SCI1_TDR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008824B )
#define SCI1_SSR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008824C )
#define SCI1_RDR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008824D )
#define SCI1_SCMR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008824E )
#define SCI1_SEMR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008824F )
#define SCI2_SMR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00088250 )
#define SCI2_BRR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00088251 )
#define SCI2_SCR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00088252 )
#define SCI2_TDR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00088253 )
#define SCI2_SSR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00088254 )
#define SCI2_RDR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00088255 )
#define SCI2_SCMR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00088256 )
#define SCI2_SEMR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x00088257 )
#define SCI_SMR_CKS_BIT			        ( 3U << 0U )
#define SCI_SMR_STOP_BIT		        ( 1U << 3U )
#define SCI_SMR_PM_BIT			        ( 1U << 4U )
#define SCI_SMR_PE_BIT			        ( 1U << 5U )
#define SCI_SMR_CHR_BIT			        ( 1U << 6U )
#define SCI_SMR_CM_BIT			        ( 1U << 7U )
#define SCI_SCR_CKE_BIT			        ( 3U << 0U )
#define SCI_SCR_TEIE_BIT		        ( 1U << 2U )
#define SCI_SCR_RE_BIT			        ( 1U << 4U )
#define SCI_SCR_TE_BIT			        ( 1U << 5U )
#define SCI_SCR_RIE_BIT			        ( 1U << 6U )
#define SCI_SCR_TIE_BIT			        ( 1U << 7U )
#define SCI_SSR_TEND_BIT		        ( 1U << 2U )
#define SCI_SSR_PER_BIT			        ( 1U << 3U )
#define SCI_SSR_FER_BIT			        ( 1U << 4U )
#define SCI_SSR_ORER_BIT		        ( 1U << 5U )
#define SCI_SCMR_SMIF_BIT		        ( 1U << 0U )
#define SCI_SCMR_SINV_BIT		        ( 1U << 2U )
#define SCI_SCMR_SDIR_BIT		        ( 1U << 3U )
#define SCI_SCMR_BCP2_BIT		        ( 1U << 7U )
#define SCI_SEMR_ACS0_BIT		        ( 1U << 0U )
#define SCI_SEMR_ABCS_BIT		        ( 1U << 4U )

/*
 *  I/Oポートのレジスタ及び設定ビット情報
 */
#define PORT1_DDR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C001 )
#define PORT2_DDR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C002 )
#define PORT3_DDR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C003 )
#define PORT7_DDR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C007 )
#define PORT8_DDR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C008 )
#define PORT9_DDR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C009 )
#define PORTA_DDR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C00A )
#define PORTB_DDR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C00B )
#define PORTD_DDR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C00D )
#define PORTE_DDR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C00E )
#define PORTG_DDR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C010 )
#define PORT_DDR_B0_BIT			        ( 1U << 0U )
#define PORT_DDR_B1_BIT			        ( 1U << 1U )
#define PORT_DDR_B2_BIT			        ( 1U << 2U )
#define PORT_DDR_B3_BIT			        ( 1U << 3U )
#define PORT_DDR_B4_BIT			        ( 1U << 4U )
#define PORT_DDR_B5_BIT			        ( 1U << 5U )
#define PORT_DDR_B6_BIT			        ( 1U << 6U )
#define PORT_DDR_B7_BIT			        ( 1U << 7U )
#define PORT1_DR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C021 )
#define PORT2_DR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C022 )
#define PORT3_DR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C023 )
#define PORT7_DR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C027 )
#define PORT8_DR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C028 )
#define PORT9_DR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C029 )
#define PORTA_DR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C02A )
#define PORTB_DR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C02B )
#define PORTD_DR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C02D )
#define PORTE_DR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C02E )
#define PORTG_DR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C030 )
#define PORT_DR_B0_BIT			        ( 1U << 0U )
#define PORT_DR_B1_BIT			        ( 1U << 1U )
#define PORT_DR_B2_BIT			        ( 1U << 2U )
#define PORT_DR_B3_BIT			        ( 1U << 3U )
#define PORT_DR_B4_BIT			        ( 1U << 4U )
#define PORT_DR_B5_BIT			        ( 1U << 5U )
#define PORT_DR_B6_BIT			        ( 1U << 6U )
#define PORT_DR_B7_BIT			        ( 1U << 7U )
#define PORT1_PORT_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C041 )
#define PORT2_PORT_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C042 )
#define PORT3_PORT_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C043 )
#define PORT4_PORT_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C044 )
#define PORT5_PORT_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C045 )
#define PORT6_PORT_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C046 )
#define PORT7_PORT_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C047 )
#define PORT8_PORT_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C048 )
#define PORT9_PORT_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C049 )
#define PORTA_PORT_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C04A )
#define PORTB_PORT_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C04B )
#define PORTD_PORT_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C04D )
#define PORTE_PORT_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C04E )
#define PORTG_PORT_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C050 )
#define PORT_PORT_B0_BIT	            ( 1U << 0U )
#define PORT_PORT_B1_BIT	            ( 1U << 1U )
#define PORT_PORT_B2_BIT	            ( 1U << 2U )
#define PORT_PORT_B3_BIT	            ( 1U << 3U )
#define PORT_PORT_B4_BIT	            ( 1U << 4U )
#define PORT_PORT_B5_BIT	            ( 1U << 5U )
#define PORT_PORT_B6_BIT	            ( 1U << 6U )
#define PORT_PORT_B7_BIT	            ( 1U << 7U )
#define PORT1_ICR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C061 )
#define PORT2_ICR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C062 )
#define PORT3_ICR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C063 )
#define PORT4_ICR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C064 )
#define PORT5_ICR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C065 )
#define PORT6_ICR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C066 )
#define PORT7_ICR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C067 )
#define PORT8_ICR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C068 )
#define PORT9_ICR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C069 )
#define PORTA_ICR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C06A )
#define PORTB_ICR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C06B )
#define PORTD_ICR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C06D )
#define PORTE_ICR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C06E )
#define PORTG_ICR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x0008C070 )
#define PORT_ICR_B0_BIT			        ( 1U << 0U )
#define PORT_ICR_B1_BIT			        ( 1U << 1U )
#define PORT_ICR_B2_BIT			        ( 1U << 2U )
#define PORT_ICR_B3_BIT			        ( 1U << 3U )
#define PORT_ICR_B4_BIT			        ( 1U << 4U )
#define PORT_ICR_B5_BIT			        ( 1U << 5U )
#define PORT_ICR_B6_BIT			        ( 1U << 6U )
#define PORT_ICR_B7_BIT			        ( 1U << 7U )
#define IOPORT_PF8IRQ_ADDR		        ( ( volatile uint8_t __evenaccess * )0x0008C108 )
#define IOPORT_PF9IRQ_ADDR		        ( ( volatile uint8_t __evenaccess * )0x0008C109 )
#define IOPORT_PFAADC_ADDR		        ( ( volatile uint8_t __evenaccess * )0x0008C10A )
#define IOPORT_PFCMTU_ADDR		        ( ( volatile uint8_t __evenaccess * )0x0008C10C )
#define IOPORT_PFDGPT_ADDR		        ( ( volatile uint8_t __evenaccess * )0x0008C10D )
#define IOPORT_PFFSCI_ADDR		        ( ( volatile uint8_t __evenaccess * )0x0008C10F )
#define IOPORT_PFGSPI_ADDR		        ( ( volatile uint8_t __evenaccess * )0x0008C110 )
#define IOPORT_PFHSPI_ADDR		        ( ( volatile uint8_t __evenaccess * )0x0008C111 )
#define IOPORT_PFJCAN_ADDR		        ( ( volatile uint8_t __evenaccess * )0x0008C113 )
#define IOPORT_PFKLIN_ADDR		        ( ( volatile uint8_t __evenaccess * )0x0008C114 )
#define IOPORT_PFMPOE_ADDR		        ( ( volatile uint8_t __evenaccess * )0x0008C116 )
#define IOPORT_PFNPOE_ADDR		        ( ( volatile uint8_t __evenaccess * )0x0008C117 )
#define PORT_IOPORT_B0_BIT		        ( 1U << 0U )
#define PORT_IOPORT_B1_BIT		        ( 1U << 1U )
#define PORT_IOPORT_B2_BIT		        ( 1U << 2U )
#define PORT_IOPORT_B3_BIT		        ( 1U << 3U )
#define PORT_IOPORT_B4_BIT		        ( 1U << 4U )
#define PORT_IOPORT_B5_BIT		        ( 1U << 5U )
#define PORT_IOPORT_B6_BIT		        ( 1U << 6U )
#define PORT_IOPORT_B7_BIT		        ( 1U << 7U )

/*
 * Registers of General Timer (MTU/MTUa)
 */
#define MTU_TSTRA_ADDR			        ( ( volatile uint8_t __evenaccess  * )0x000C1280 )
#define MTU_TSYRA_ADDR			        ( ( volatile uint8_t __evenaccess  * )0x000C1281 )
#define MTU_TCSYSTR_ADDR		        ( ( volatile uint8_t __evenaccess  * )0x000C1282 )
#define MTU_TRWERA_ADDR		            ( ( volatile uint8_t __evenaccess  * )0x000C1284 )
#define MTU0_TCR_ADDR    	            ( ( volatile uint8_t __evenaccess  * )0x000C1300 )
#define MTU0_TMDR1_ADDR    	            ( ( volatile uint8_t __evenaccess  * )0x000C1301 )
#define MTU0_TIORH_ADDR    	            ( ( volatile uint8_t __evenaccess  * )0x000C1302 )
#define MTU0_TIORL_ADDR    	            ( ( volatile uint8_t __evenaccess  * )0x000C1303 )
#define MTU0_TIER_ADDR    	            ( ( volatile uint8_t __evenaccess  * )0x000C1304 )
#define MTU0_TSR_ADDR    	            ( ( volatile uint8_t __evenaccess  * )0x000C1305 )
#define MTU0_TCNT_ADDR    	            ( ( volatile uint16_t __evenaccess * )0x000C1306 )
#define MTU0_TGRA_ADDR    	            ( ( volatile uint16_t __evenaccess * )0x000C1308 )
#define MTU0_TGRB_ADDR    	            ( ( volatile uint16_t __evenaccess * )0x000C130A )
#define MTU0_TGRC_ADDR    	            ( ( volatile uint16_t __evenaccess * )0x000C130C )
#define MTU0_TGRD_ADDR    	            ( ( volatile uint16_t __evenaccess * )0x000C130E )
#define MTU0_TGRE_ADDR    	            ( ( volatile uint16_t __evenaccess * )0x000C1320 )
#define MTU0_TGRF_ADDR    	            ( ( volatile uint16_t __evenaccess * )0x000C1322 )
#define MTU0_TIER2_ADDR    	            ( ( volatile uint8_t __evenaccess  * )0x000C1324 )
#define MTU0_TSR2_ADDR    	            ( ( volatile uint8_t __evenaccess  * )0x000C1325 )
#define MTU0_TBTM_ADDR    	            ( ( volatile uint8_t __evenaccess  * )0x000C1326 )

/*
 * Registers of General PWM Timer (GPT/GPTa)
 */
#define GPT_GTSTR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C2000 )
#define GPT_GTHSCR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C2004 )
#define GPT_GTHCCR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C2006 )
#define GPT_GTHSSR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C2008 )
#define GPT_GTHPSR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C200A )
#define GPT_GTWP_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C200C )
#define GPT_GTSYNC_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C200E )
#define GPT_GTETINT_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C2010 )
#define GPT_GTBDR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C2014 )
#define GPT_GTSWP_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C2018 )
#define GPT_LCCR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C2080 )
#define GPT_LCST_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C2082 )
#define GPT_LCNT_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C2084 )
#define GPT_LCNTA_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C2086 )
#define GPT_LCNT00_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C2088 )
#define GPT_LCNT01_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C208A )
#define GPT_LCNT02_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C208C )
#define GPT_LCNT03_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C208E )
#define GPT_LCNT04_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C2090 )
#define GPT_LCNT05_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C2092 )
#define GPT_LCNT06_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C2094 )
#define GPT_LCNT07_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C2096 )
#define GPT_LCNT08_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C2098 )
#define GPT_LCNT09_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C209A )
#define GPT_LCNT10_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C209C )
#define GPT_LCNT11_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C209E )
#define GPT_LCNT12_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C20A0 )
#define GPT_LCNT13_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C20A2 )
#define GPT_LCNT14_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C20A4 )
#define GPT_LCNT15_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C20A6 )
#define GPT_LCNTDU_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C20A8 )
#define GPT_LCNTDL_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C20AA )
#define GPT0_GTIOR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C2100 )
#define GPT0_GTINTAD_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C2102 )
#define GPT0_GTCR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C2104 )
#define GPT0_GTBER_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C2106 )
#define GPT0_GTUDC_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C2108 )
#define GPT0_GTITC_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C210A )
#define GPT0_GTST_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C210C )
#define GPT0_GTCNT_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C210E )
#define GPT0_GTCCRA_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C2110 )
#define GPT0_GTCCRB_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C2112 )
#define GPT0_GTCCRC_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C2114 )
#define GPT0_GTCCRD_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C2116 )
#define GPT0_GTCCRE_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C2118 )
#define GPT0_GTCCRF_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C211A )
#define GPT0_GTPR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C211C )
#define GPT0_GTPBR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C211E )
#define GPT0_GTPDBR_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C2120 )
#define GPT0_GTADTRA_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C2124 )
#define GPT0_GTADTBRA_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C2126 )
#define GPT0_GTADTDBRA_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C2128 )
#define GPT0_GTADTRB_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C212C )
#define GPT0_GTADTBRB_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C212E )
#define GPT0_GTADTDBRB_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C2130 )
#define GPT0_GTONCR_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C2134 )
#define GPT0_GTDTCR_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C2136 )
#define GPT0_GTDVU_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C2138 )
#define GPT0_GTDVD_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C213A )
#define GPT0_GTDBU_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C213C )
#define GPT0_GTDBD_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C213E )
#define GPT0_GTSOS_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C2140 )
#define GPT0_GTSOTR_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C2142 )
#define GPT1_GTIOR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C2180 )
#define GPT1_GTINTAD_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C2182 )
#define GPT1_GTCR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C2184 )
#define GPT1_GTBER_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C2186 )
#define GPT1_GTUDC_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C2188 )
#define GPT1_GTITC_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C218A )
#define GPT1_GTST_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C218C )
#define GPT1_GTCNT_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C218E )
#define GPT1_GTCCRA_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C2190 )
#define GPT1_GTCCRB_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C2192 )
#define GPT1_GTCCRC_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C2194 )
#define GPT1_GTCCRD_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C2196 )
#define GPT1_GTCCRE_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C2198 )
#define GPT1_GTCCRF_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C219A )
#define GPT1_GTPR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C219C )
#define GPT1_GTPBR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C219E )
#define GPT1_GTPDBR_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C21A0 )
#define GPT1_GTADTRA_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C21A4 )
#define GPT1_GTADTBRA_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C21A6 )
#define GPT1_GTADTDBRA_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C21A8 )
#define GPT1_GTADTRB_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C21AC )
#define GPT1_GTADTBRB_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C21AE )
#define GPT1_GTADTDBRB_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C21B0 )
#define GPT1_GTONCR_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C21B4 )
#define GPT1_GTDTCR_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C21B6 )
#define GPT1_GTDVU_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C21B8 )
#define GPT1_GTDVD_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C21BA )
#define GPT1_GTDBU_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C21BC )
#define GPT1_GTDBD_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C21BE )
#define GPT1_GTSOS_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C21C0 )
#define GPT1_GTSOTR_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C21C2 )
#define GPT2_GTIOR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C2200 )
#define GPT2_GTINTAD_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C2202 )
#define GPT2_GTCR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C2204 )
#define GPT2_GTBER_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C2206 )
#define GPT2_GTUDC_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C2208 )
#define GPT2_GTITC_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C220A )
#define GPT2_GTST_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C220C )
#define GPT2_GTCNT_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C220E )
#define GPT2_GTCCRA_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C2210 )
#define GPT2_GTCCRB_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C2212 )
#define GPT2_GTCCRC_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C2214 )
#define GPT2_GTCCRD_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C2216 )
#define GPT2_GTCCRE_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C2218 )
#define GPT2_GTCCRF_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C221A )
#define GPT2_GTPR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C221C )
#define GPT2_GTPBR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C221E )
#define GPT2_GTPDBR_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C2220 )
#define GPT2_GTADTRA_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C2224 )
#define GPT2_GTADTBRA_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C2226 )
#define GPT2_GTADTDBRA_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C2228 )
#define GPT2_GTADTRB_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C222C )
#define GPT2_GTADTBRB_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C222E )
#define GPT2_GTADTDBRB_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C2230 )
#define GPT2_GTONCR_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C2234 )
#define GPT2_GTDTCR_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C2236 )
#define GPT2_GTDVU_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C2238 )
#define GPT2_GTDVD_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C223A )
#define GPT2_GTDBU_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C223C )
#define GPT2_GTDBD_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C223E )
#define GPT2_GTSOS_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C2240 )
#define GPT2_GTSOTR_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C2242 )
#define GPT3_GTIOR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C2280 )
#define GPT3_GTINTAD_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C2282 )
#define GPT3_GTCR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C2284 )
#define GPT3_GTBER_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C2286 )
#define GPT3_GTUDC_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C2288 )
#define GPT3_GTITC_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C228A )
#define GPT3_GTST_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C228C )
#define GPT3_GTCNT_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C228E )
#define GPT3_GTCCRA_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C2290 )
#define GPT3_GTCCRB_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C2292 )
#define GPT3_GTCCRC_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C2294 )
#define GPT3_GTCCRD_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C2296 )
#define GPT3_GTCCRE_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C2298 )
#define GPT3_GTCCRF_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C229A )
#define GPT3_GTPR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C229C )
#define GPT3_GTPBR_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C229E )
#define GPT3_GTPDBR_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C22A0 )
#define GPT3_GTADTRA_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C22A4 )
#define GPT3_GTADTBRA_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C22A6 )
#define GPT3_GTADTDBRA_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C22A8 )
#define GPT3_GTADTRB_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C22AC )
#define GPT3_GTADTBRB_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C22AE )
#define GPT3_GTADTDBRB_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C22B0 )
#define GPT3_GTONCR_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C22B4 )
#define GPT3_GTDTCR_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C22B6 )
#define GPT3_GTDVU_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C22B8 )
#define GPT3_GTDVD_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C22BA )
#define GPT3_GTDBU_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C22BC )
#define GPT3_GTDBD_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C22BE )
#define GPT3_GTSOS_ADDR			        ( ( volatile uint8_t __evenaccess * )0x000C22C0 )
#define GPT3_GTSOTR_ADDR		        ( ( volatile uint8_t __evenaccess * )0x000C22C2 )


/*
 *  SERIAL関連の定義
 *
 *  pdicのrx600/rx600_serial.cで使用する．
 */
/*
 *  シリアルI/Oの個数
 */
#define TNUM_SIOP	(1)
#define TNUM_GIOP   (4) /* Number of GPIO port */
#define TNUM_AIOP   (1)  /* Number of ADC port */
#define TNUM_PIOP   (1)  /* Number of PWM port */

#endif	/* TOPPERS_RX62T_H */
