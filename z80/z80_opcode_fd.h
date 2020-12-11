#ifndef Z80_OPCODE_FD_H
#define Z80_OPCODE_FD_H

/*ADD IY, BC*/
void op_FD_0x09(void);
/*ADD IY, DE*/
void op_FD_0x19(void);
/*LD IY, @*/
void op_FD_0x21(void);
/*LD (@);, IY*/
void op_FD_0x22(void);
/*INC IY*/
void op_FD_0x23(void);
/*INC IYH*/
void op_FD_0x24(void);
/*DEC IYH*/
void op_FD_0x25(void);
/*LD IYH, #*/
void op_FD_0x26(void);
/*ADD IY, IY*/
void op_FD_0x29(void);
/*LD IY, (@);*/
void op_FD_0x2a(void);
/*DEC IY*/
void op_FD_0x2b(void);
/*INC IYL*/
void op_FD_0x2c(void);
/*DEC IYL*/
void op_FD_0x2d(void);
/*LD IYL, #*/
void op_FD_0x2e(void);
/*INC (IY+$);*/
void op_FD_0x34(void);
/*DEC (IY+$);*/
void op_FD_0x35(void);
/*LD (IY+$);, #*/
void op_FD_0x36(void);
/*ADD IY, SP*/
void op_FD_0x39(void);
/*LD B, IYH*/
void op_FD_0x44(void);
/*LD B, IYL*/
void op_FD_0x45(void);
/*LD B, (IY+$);*/
void op_FD_0x46(void);
/*LD C, IYH*/
void op_FD_0x4c(void);
/*LD C, IYL*/
void op_FD_0x4d(void);
/*LD C, (IY+$);*/
void op_FD_0x4e(void);
/*LD D, IYH*/
void op_FD_0x54(void);
/*LD D, IYL*/
void op_FD_0x55(void);
/*LD D, (IY+$);*/
void op_FD_0x56(void);
/*LD E, IYH*/
void op_FD_0x5c(void);
/*LD E, IYL*/
void op_FD_0x5d(void);
/*LD E, (IY+$);*/
void op_FD_0x5e(void);
/*LD IYH, B*/
void op_FD_0x60(void);
/*LD IYH, C*/
void op_FD_0x61(void);
/*LD IYH, D*/
void op_FD_0x62(void);
/*LD IYH, E*/
void op_FD_0x63(void);
/*LD IYH, IYH*/
void op_FD_0x64(void);
/*LD IYH, IYL*/
void op_FD_0x65(void);
/*LD H, (IY+$);*/
void op_FD_0x66(void);
/*LD IYH, A*/
void op_FD_0x67(void);
/*LD IYL, B*/
void op_FD_0x68(void);
/*LD IYL, C*/
void op_FD_0x69(void);
/*LD IYL, D*/
void op_FD_0x6a(void);
/*LD IYL, E*/
void op_FD_0x6b(void);
/*LD IYL, IYH*/
void op_FD_0x6c(void);
/*LD IYL, IYL*/
void op_FD_0x6d(void);
/*LD L, (IY+$);*/
void op_FD_0x6e(void);
/*LD IYL, A*/
void op_FD_0x6f(void);
/*LD (IY+$);, B*/
void op_FD_0x70(void);
/*LD (IY+$);, C*/
void op_FD_0x71(void);
/*LD (IY+$);, D*/
void op_FD_0x72(void);
/*LD (IY+$);, E*/
void op_FD_0x73(void);
/*LD (IY+$);, H*/
void op_FD_0x74(void);
/*LD (IY+$);, L*/
void op_FD_0x75(void);
/*LD (IY+$);, A*/
void op_FD_0x77(void);
/*LD A, IYH*/
void op_FD_0x7c(void);
/*LD A, IYL*/
void op_FD_0x7d(void);
/*LD A, (IY+$);*/
void op_FD_0x7e(void);
/*ADD A, IYH*/
void op_FD_0x84(void);
/*ADD A, IYL*/
void op_FD_0x85(void);
/*ADD A, (IY+$);*/
void op_FD_0x86(void);
/*ADDC A, IYH*/
void op_FD_0x8c(void);
/*ADDC A, IYL*/
void op_FD_0x8d(void);
/*ADDC A, (IY+$);*/
void op_FD_0x8e(void);
/*SUB IYH*/
void op_FD_0x94(void);
/*SUB IYL*/
void op_FD_0x95(void);
/*SUB (IY+$);*/
void op_FD_0x96(void);
/*SUBC A, IYH*/
void op_FD_0x9c(void);
/*SUBC A, IYL*/
void op_FD_0x9d(void);
/*SUBC A, (IY+$);*/
void op_FD_0x9e(void);
/*AND IYH*/
void op_FD_0xa4(void);
/*AND IYL*/
void op_FD_0xa5(void);
/*AND (IY+$);*/
void op_FD_0xa6(void);
/*XOR IYH*/
void op_FD_0xac(void);
/*XOR IYL*/
void op_FD_0xad(void);
/*XOR (IY+$);*/
void op_FD_0xae(void);
/*OR IYH*/
void op_FD_0xb4(void);
/*OR IYL*/
void op_FD_0xb5(void);
/*OR (IY+$);*/
void op_FD_0xb6(void);
/*CP IYH*/
void op_FD_0xbc(void);
/*CP IYL*/
void op_FD_0xbd(void);
/*CP (IY+$);*/
void op_FD_0xbe(void);
/*POP IY*/
void op_FD_0xe1(void);
/*EX (SP);, IY*/
void op_FD_0xe3(void);
/*PUSH IY*/
void op_FD_0xe5(void);
/*JP IY*/
void op_FD_0xe9(void);
/*LD SP, IY*/
void op_FD_0xf9(void);
/*NONI*/
void non_FD (void);

#endif
