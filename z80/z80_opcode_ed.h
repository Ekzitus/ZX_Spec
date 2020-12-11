#ifndef Z80_OPCODE_ED_H
#define Z80_OPCODE_ED_H

/*IN B, (C);*/
void op_ED_0x40(void);
/*OUT (C);, B*/
void op_ED_0x41(void);
/*SUBC HL, BC*/
void op_ED_0x42(void);
/*LD (@);, BC*/
void op_ED_0x43(void);
/*NEG*/
void op_ED_0x44(void);
/*RETN*/
void op_ED_0x45(void);
/*IM 0*/
void op_ED_0x46(void);
/*LD I, A*/
void op_ED_0x47(void);
/*IN C, (C);*/
void op_ED_0x48(void);
/*OUT (C);, C*/
void op_ED_0x49(void);
/*ADDC HL, BC*/
void op_ED_0x4a(void);
/*LD BC, (@);*/
void op_ED_0x4b(void);
/*NEG*/
void op_ED_0x4c(void);
/*RETI*/
void op_ED_0x4d(void);
/*IM 0*/
void op_ED_0x4e(void);
/*LD R, A*/
void op_ED_0x4f(void);
/*IN D, (C);*/
void op_ED_0x50(void);
/*OUT (C);, D*/
void op_ED_0x51(void);
/*SUBC HL, DE*/
void op_ED_0x52(void);
/*LD (@);, DE*/
void op_ED_0x53(void);
/*NEG*/
void op_ED_0x54(void);
/*RETN*/
void op_ED_0x55(void);
/*IM 1*/
void op_ED_0x56(void);
/*LD A, I*/
void op_ED_0x57(void);
/*IN E, (C);*/
void op_ED_0x58(void);
/*OUT (C);, E*/
void op_ED_0x59(void);
/*ADDC HL, DE*/
void op_ED_0x5a(void);
/*LD DE, (@);*/
void op_ED_0x5b(void);
/*NEG*/
void op_ED_0x5c(void);
/*RETI*/
void op_ED_0x5d(void);
/*IM 2*/
void op_ED_0x5e(void);
/*LD A, R*/
void op_ED_0x5f(void);
/*IN H, (C);*/
void op_ED_0x60(void);
/*OUT (C);, H*/
void op_ED_0x61(void);
/*SUBC HL, HL*/
void op_ED_0x62(void);
/*LD (@);, HL*/
void op_ED_0x63(void);
/*NEG*/
void op_ED_0x64(void);
/*RETN*/
void op_ED_0x65(void);
/*IM 0*/
void op_ED_0x66(void);
/*RRD*/
void op_ED_0x67(void);
/*IN L, (C);*/
void op_ED_0x68(void);
/*OUT (C);, L*/
void op_ED_0x69(void);
/*ADDC HL, HL*/
void op_ED_0x6a(void);
/*LD HL, (@);*/
void op_ED_0x6b(void);
/*NEG*/
void op_ED_0x6c(void);
/*RETI*/
void op_ED_0x6d(void);
/*IM 0*/
void op_ED_0x6e(void);
/*RLD*/
void op_ED_0x6f(void);
/*IN_F (C);*/
void op_ED_0x70(void);
/*OUT (C);, 0*/
void op_ED_0x71(void);
/*SUBC HL, SP*/
void op_ED_0x72(void);
/*LD (@);, SP*/
void op_ED_0x73(void);
/*NEG*/
void op_ED_0x74(void);
/*RETN*/
void op_ED_0x75(void);
/*IM 1*/
void op_ED_0x76(void);
/*IN A, (C);*/
void op_ED_0x78(void);
/*OUT (C);, A*/
void op_ED_0x79(void);
/*ADDC HL, SP*/
void op_ED_0x7a(void);
/*LD SP, (@);*/
void op_ED_0x7b(void);
/*NEG*/
void op_ED_0x7c(void);
/*RETI*/
void op_ED_0x7d(void);
/*IM 2*/
void op_ED_0x7e(void);
/*LDI*/
void op_ED_0xa0(void);
/*CPI*/
void op_ED_0xa1(void);
/*INI*/
void op_ED_0xa2(void);
/*OUTI*/
void op_ED_0xa3(void);
/*LDD*/
void op_ED_0xa8(void);
/*CPD*/
void op_ED_0xa9(void);
/*IND*/
void op_ED_0xaa(void);
/*OUTD*/
void op_ED_0xab(void);
/*LDIR*/
void op_ED_0xb0(void);
/*CPIR*/
void op_ED_0xb1(void);
/*INIR*/
void op_ED_0xb2(void);
/*OTIR*/
void op_ED_0xb3(void);
/*LDDR*/
void op_ED_0xb8(void);
/*CPDR*/
void op_ED_0xb9(void);
/*INDR*/
void op_ED_0xba(void);
/*OTDR*/
void op_ED_0xbb(void);
/*NONI*/
void noni_ED(void);

#endif