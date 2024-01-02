@rem
@rem  kernel_cfg.c(.h) kernel_cfg_asm.src 生成のPASS2用バッチファイル
@rem
@rem  引数
@rem  %1 : TOPPERS/ASPのTOP階層
@rem  %2 : 生成したファイルのコピー先階層
@rem
%1\arch\rxc\gensyms.exe cfg.map
%1\cfg\cfg.exe --pass 2 --kernel asp --api-table %1\kernel\kernel_api.csv --cfg1-def-table %1\kernel\kernel_def.csv --cfg1-def-table %1\arch\rx_rxc\prc_def.csv --cfg1-def-table %1\target\kiss_rx62t\target_def.csv -I %1 -I %1\arch -I %1\include -I %1\kernel -I %1\target\kiss_rx62t --template-file %1\target\kiss_rx62t\target.tf %1\sample\sample1.cfg
copy kernel_cfg.c %2
copy kernel_cfg.h %2
copy kernel_cfg_asm.src %2
