@rem
@rem  asm_config.inc ������PASS2�p�o�b�`�t�@�C��
@rem
@rem  asm_config.inc �̓J�[�l���̃A�Z���u���R�[�h����C���N���[�h�����.
@rem  asm_config.inc �ɒ�`����l��, C�w�b�_�t�@�C�����瓱�o����.
@rem
@rem  ����
@rem  %1 : TOPPERS/ASP��TOP�K�w
@rem  %2 : ���������t�@�C���̃R�s�[��K�w
@rem       �J�[�l�����C�u�����̃r���h�v���W�F�N�g�K�w��z��
@rem
%1\arch\rxc\gensyms.exe asm_config.map
%1\cfg\cfg.exe --pass 2 --kernel asp --api-table %1\kernel\kernel_api.csv --cfg1-def-table %1\kernel\kernel_def.csv --cfg1-def-table %1\arch\rx_rxc\prc_def.csv --cfg1-def-table %1\target\kiss_rx62t\target_def.csv -I %1 -I %1\arch -I %1\include -I %1\kernel -I %1\target\kiss_rx62t --template-file %1\target\kiss_rx62t\target_asm_config.tf %1\target\kiss_rx62t\asm_config.cfg
copy asm_config.inc %2

