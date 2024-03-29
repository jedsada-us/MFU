/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 *
 *  Copyright (C) 2008-2010 by Witz Corporation, JAPAN
 *
 *  上記著作権者は，以下の(1)〜(4)の条件を満たす場合に限り，本ソフトウェ
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
 *  RX62T SERIAL用 簡易SIOドライバ
 */

#ifndef TOPPERS_RX600_SERIAL_H
#define TOPPERS_RX600_SERIAL_H

/* 指定可能なクロックソース */
#define CLK_F1    UINT_C(0x00)
#define CLK_F4    UINT_C(0x01)
#define CLK_F16   UINT_C(0x02)
#define CLK_F64   UINT_C(0x03)

#ifndef TOPPERS_MACRO_ONLY

/*
 *  シリアルI/Oポート管理ブロックの定義
 */
typedef struct sio_port_control_block SIOPCB;

/*
 *  コールバックルーチンの識別番号
 */
#define SIO_RDY_SND   (1U) /* 送信可能コールバック */
#define SIO_RDY_RCV   (2U) /* 受信通知コールバック */

/*
 *  SIOドライバの初期化ルーチン
 */
extern void rx600_serial_initialize(void);

/*
 * カーネル起動時のバナー出力用の初期化
 */
extern void rx600_serial_init(ID siopid, uint8_t baud, uint8_t clksrc);

/*
 *  シリアルI/Oポートへのポーリングでの出力
 */
extern void rx600_serial_pol_putc(char_t c, ID siopid);

/*
 *  シリアルI/Oポートのオープン
 */
extern SIOPCB* rx600_serial_opn_por(ID siopid, intptr_t exinf, uint8_t baud, uint8_t clksrc);

/*
 *  シリアルI/Oポートのクローズ
 */
extern void rx600_serial_cls_por(SIOPCB* p_siopcb);

/*
 *  シリアルI/Oポートへの文字送信
 */
extern bool_t rx600_serial_snd_chr(SIOPCB* p_siopcb, char_t c);

/*
 *  シリアルI/Oポートからの文字受信
 */
extern int_t rx600_serial_rcv_chr(SIOPCB* p_siopcb);

/*
 *  シリアルI/Oポートからのコールバックの許可
 */
extern void rx600_serial_ena_cbr(SIOPCB* p_siopcb, uint_t cbrtn);

/*
 *  シリアルI/Oポートからのコールバックの禁止
 */
extern void rx600_serial_dis_cbr(SIOPCB* p_siopcb, uint_t cbrtn);

/*
 *  SIOの割込みサービスルーチン
 */
extern void rx600_serial_tx_isr(ID siopid);
extern void rx600_serial_rx_isr(ID siopid);

/*
 *  シリアルI/Oポートからの送信可能コールバック
 */
extern void rx600_serial_irdy_snd(intptr_t exinf);

/*
 *  シリアルI/Oポートからの受信通知コールバック
 */
extern void rx600_serial_irdy_rcv(intptr_t exinf);

#endif /* TOPPERS_MACRO_ONLY */
#endif /* TOPPERS_RX600_SERIAL_H */
