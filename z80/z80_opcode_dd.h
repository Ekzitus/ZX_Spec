#ifndef Z80_OPCODE_DD_H
#define Z80_OPCODE_DD_H

/*ADD IX, BC*/
void op_DD_0x09(void);
/*ADD IX, DE*/
void op_DD_0x19(void);
/*LD IX, @*/
void op_DD_0x21(void);
/*LD (@);, IX*/
void op_DD_0x22(void);
/*INC IX*/
void op_DD_0x23(void);
/*INC IXH*/
void op_DD_0x24(void);
/*DEC IXH*/
void op_DD_0x25(void);
/*LD IXH, #*/
void op_DD_0x26(void);
/*ADD IX, IX*/
void op_DD_0x29(void);
/*LD IX, (@);*/
void op_DD_0x2a(void);
/*DEC IX*/
void op_DD_0x2b(void);
/*INC IXL*/
void op_DD_0x2c(void);
/*DEC IXL*/
void op_DD_0x2d(void);
/*LD IXL, #*/
void op_DD_0x2e(void);
/*INC (IX+$);*/
void op_DD_0x34(void);
/*DEC (IX+$);*/
void op_DD_0x35(void);
/*LD (IX+$);, #*/
void op_DD_0x36(void);
/*ADD IX, SP*/
void op_DD_0x39(void);
/*LD B, IXH*/
void op_DD_0x44(void);
/*LD B, IXL*/
void op_DD_0x45(void);
/*LD B, (IX+$);*/
void op_DD_0x46(void);
/*LD C, IXH*/
void op_DD_0x4c(void);
/*LD C, IXL*/
void op_DD_0x4d(void);
/*LD C, (IX+$);*/
void op_DD_0x4e(void);
/*LD D, IXH*/
void op_DD_0x54(void);
/*LD D, IXL*/
void op_DD_0x55(void);
/*LD D, (IX+$);*/
void op_DD_0x56(void);
/*LD E, IXH*/
void op_DD_0x5c(void);
/*LD E, IXL*/
void op_DD_0x5d(void);
/*LD E, (IX+$);*/
void op_DD_0x5e(void);
/*LD IXH, B*/
void op_DD_0x60(void);
/*LD IXH, C*/
void op_DD_0x61(void);
/*LD IXH, D*/
void op_DD_0x62(void);
/*LD IXH, E*/
void op_DD_0x63(void);
/*LD IXH, IXH*/
void op_DD_0x64(void);
/*LD IXH, IXL*/
void op_DD_0x65(void);
/*LD H, (IX+$);*/
void op_DD_0x66(void);
/*LD IXH, A*/
void op_DD_0x67(void);
/*LD IXL, B*/
void op_DD_0x68(void);
/*LD IXL, C*/
void op_DD_0x69(void);
/*LD IXL, D*/
void op_DD_0x6a(void);
/*LD IXL, E*/
void op_DD_0x6b(void);
/*LD IXL, IXH*/
void op_DD_0x6c(void);
/*LD IXL, IXL*/
void op_DD_0x6d(void);
/*LD L, (IX+$);*/
void op_DD_0x6e(void);
/*LD IXL, A*/
void op_DD_0x6f(void);
/*LD (IX+$);, B*/
void op_DD_0x70(void);
/*LD (IX+$);, C*/
void op_DD_0x71(void);
/*LD (IX+$);, D*/
void op_DD_0x72(void);
/*LD (IX+$);, E*/
void op_DD_0x73(void);
/*LD (IX+$);, H*/
void op_DD_0x74(void);
/*LD (IX+$);, L*/
void op_DD_0x75(void);
/*LD (IX+$);, A*/
void op_DD_0x77(void);
/*LD A, IXH*/
void op_DD_0x7c(void);
/*LD A, IXL*/
void op_DD_0x7d(void);
/*LD A, (IX+$);*/
void op_DD_0x7e(void);
/*ADD A, IXH*/
void op_DD_0x84(void);
/*ADD A, IXL*/
void op_DD_0x85(void);
/*ADD A, (IX+$);*/
void op_DD_0x86(void);
/*ADDC A, IXH*/
void op_DD_0x8c(void);
/*ADDC A, IXL*/
void op_DD_0x8d(void);
/*ADDC A, (IX+$);*/
void op_DD_0x8e(void);
/*SUB IXH*/
void op_DD_0x94(void);
/*SUB IXL*/
void op_DD_0x95(void);
/*SUB (IX+$);*/
void op_DD_0x96(void);
/*SUBC A, IXH*/
void op_DD_0x9c(void);
/*SUBC A, IXL*/
void op_DD_0x9d(void);
/*SUBC A, (IX+$);*/
void op_DD_0x9e(void);
/*AND IXH*/
void op_DD_0xa4(void);
/*AND IXL*/
void op_DD_0xa5(void);
/*AND (IX+$);*/
void op_DD_0xa6(void);
/*XOR IXH*/
void op_DD_0xac(void);
/*XOR IXL*/
void op_DD_0xad(void);
/*XOR (IX+$);*/
void op_DD_0xae(void);
/*OR IXH*/
void op_DD_0xb4(void);
/*OR IXL*/
void op_DD_0xb5(void);
/*OR (IX+$);*/
void op_DD_0xb6(void);
/*CP IXH*/
void op_DD_0xbc(void);
/*CP IXL*/
void op_DD_0xbd(void);
/*CP (IX+$);*/
void op_DD_0xbe(void);
/*POP IX*/
void op_DD_0xe1(void);
/*EX (SP);, IX*/
void op_DD_0xe3(void);
/*PUSH IX*/
void op_DD_0xe5(void);
/*JP IX*/
void op_DD_0xe9(void);
/*LD SP, IX*/
void op_DD_0xf9(void);
/*NONI*/
void non_DD (void);

#endif