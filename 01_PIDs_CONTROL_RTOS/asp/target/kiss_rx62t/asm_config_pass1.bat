@rem
@rem  asm_config.inc ������PASS1�p�o�b�`�t�@�C��
@rem
@rem  asm_config.inc �̓J�[�l���̃A�Z���u���R�[�h����C���N���[�h�����.
@rem  asm_config.inc �ɒ�`����l��, C�w�b�_�t�@�C�����瓱�o����.
@rem
@rem  ����
@rem  %1 : TOPPERS/ASP��TOP�K�w
@rem
%1\cfg\cfg.exe --pass 1 --kernel asp --api-table %1\kernel\kernel_api.csv --cfg1-def-table %1\kernel\kernel_def.csv --cfg1-def-table %1\arch\rx_rxc\prc_def.csv --cfg1-def-table %1\target\kiss_rx62t\target_def.csv -I %1 -I %1\arch -I %1\include -I %1\target\kiss_rx62t %1\target\kiss_rx62t\asm_config.cfg
