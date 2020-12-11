#ifndef Z80_OPCODE_BASE_H
#define Z80_OPCODE_BASE_H

/*NOP*/
void op_0x00(void);
/*LD BC,@*/
void op_0x01(void);
/*LD (BC), A*/
void op_0x02(void);
/*INC BC*/
void op_0x03(void);
/*INC B*/
void op_0x04(void);
/*DEC B*/
void op_0x05(void);
/*LD B, #*/
void op_0x06(void);
/*RLCA*/
void op_0x07(void);
/*EX AF, AF'*/
void op_0x08(void);
/*ADD HL, BC*/
void op_0x09(void);
/*LD A, (BC)*/
void op_0x0a(void);
/*DEC BC*/
void op_0x0b(void);
/*INC C*/
void op_0x0c(void);
/*DEC C*/
void op_0x0d(void);
/*LD C, #*/
void op_0x0e(void);
/*RRCA*/
void op_0x0f(void);
/*DJNZ %*/
void op_0x10(void);
/*LD DE, @*/
void op_0x11(void);
/*LD (DE), A*/
void op_0x12(void);
/*INC DE*/
void op_0x13(void);
/*INC D*/
void op_0x14(void);
/*DEC D*/
void op_0x15(void);
/*LD D, #*/
void op_0x16(void);
/*RLA*/
void op_0x17(void);
/*JR %*/
void op_0x18(void);
/*ADD HL, DE*/
void op_0x19(void);
/*LD A,(DE);*/
void op_0x1a(void);
/*DEC DE*/
void op_0x1b(void);
/*INC E*/
void op_0x1c(void);
/*DEC E*/
void op_0x1d(void);
/*LD E, #*/
void op_0x1e(void);
/*RRA*/
void op_0x1f(void);
/*JR NZ, %*/
void op_0x20(void);
/*LD HL, @*/
void op_0x21(void);
/*LD (@);, HL*/
void op_0x22(void);
/*INC HL*/
void op_0x23(void);
/*INC H*/
void op_0x24(void);
/*DEC H*/
void op_0x25(void);
/*LD H, #*/
void op_0x26(void);
/*DAA*/
void op_0x27(void);
/*JR Z, %*/
void op_0x28(void);
/*ADD HL, HL*/
void op_0x29(void);
/*LD HL, (@);*/
void op_0x2a(void);
/*DEC HL*/
void op_0x2b(void);
/*INC L*/
void op_0x2c(void);
/*DEC L*/
void op_0x2d(void);
/*LD L, #*/
void op_0x2e(void);
/*CPL*/
void op_0x2f(void);
/*JR NC, %*/
void op_0x30(void);
/*LD SP, @*/
void op_0x31(void);
/*LD (@);, A*/
void op_0x32(void);
/*INC SP*/
void op_0x33(void);
/*INC (HL);*/
void op_0x34(void);
/*DEC (HL);*/
void op_0x35(void);
/*LD (HL);, #*/
void op_0x36(void);
/*SCF*/
void op_0x37(void);
/*JR C, %*/
void op_0x38(void);
/*ADD HL, SP*/
void op_0x39(void);
/*LD A, (@);*/
void op_0x3a(void);
/*DEC SP*/
void op_0x3b(void);
/*INC A*/
void op_0x3c(void);
/*DEC A*/
void op_0x3d(void);
/*LD A, #*/
void op_0x3e(void);
/*CCF*/
void op_0x3f(void);
/*LD B, B*/
void op_0x40(void);
/*LD B, C*/
void op_0x41(void);
/*LD B, D*/
void op_0x42(void);
/*LD B, E*/
void op_0x43(void);
/*LD B, H*/
void op_0x44(void);
/*LD B, L*/
void op_0x45(void);
/*LD B, (HL);*/
void op_0x46(void);
/*LD B, A*/
void op_0x47(void);
/*LD C, B*/
void op_0x48(void);
/*LD C, C*/
void op_0x49(void);
/*LD C, D*/
void op_0x4a(void);
/*LD C, E*/
void op_0x4b(void);
/*LD C, H*/
void op_0x4c(void);
/*LD C, L*/
void op_0x4d(void);
/*LD C, (HL);*/
void op_0x4e(void);
/*LD C, A*/
/*LD D, B*/
void op_0x50(void);
/*LD D, C*/
void op_0x51(void);
/*LD D, D*/
void op_0x52(void);
/*LD D, E*/
void op_0x53(void);
/*LD D, H*/
void op_0x54(void);
/*LD D, L*/
void op_0x55(void);
/*LD D, (HL);*/
void op_0x56(void);
/*LD D, A*/
void op_0x57(void);
/*LD E, B*/
void op_0x58(void);
/*LD E, C*/
void op_0x59(void);
/*LD E, D*/
void op_0x5a(void);
/*LD E, E*/
void op_0x5b(void);
/*LD E, H*/
void op_0x5c(void);
/*LD E, L*/
void op_0x5d(void);
/*LD E, (HL);*/
void op_0x5e(void);
/*LD E, A*/
void op_0x5f(void);
/*LD H, B*/
void op_0x60(void);
/*LD H, C*/
void op_0x61(void);
/*LD H, D*/
void op_0x62(void);
/*LD H, E*/
void op_0x63(void);
/*LD H, H*/
void op_0x64(void);
/*LD H, L*/
void op_0x65(void);
/*LD H, (HL);*/
void op_0x66(void);
/*LD H, A*/
void op_0x67(void);
/*LD L, B*/
void op_0x68(void);
/*LD L, C*/
void op_0x69(void);
/*LD L, D*/
void op_0x6a(void);
/*LD L, E*/
void op_0x6b(void);
/*LD L, H*/
void op_0x6c(void);
/*LD L, L*/
void op_0x6d(void);
/*LD L, (HL);*/
void op_0x6e(void);
/*LD L, A*/
void op_0x6f(void);
/*LD (HL);, B*/
void op_0x70(void);
/*LD (HL);, C*/
void op_0x71(void);
/*LD (HL);, D*/
void op_0x72(void);
/*LD (HL);, E*/
void op_0x73(void);
/*LD (HL);, H*/
void op_0x74(void);
/*LD (HL);, L*/
void op_0x75(void);
/*HALT*/
void op_0x76(void);
/*LD (HL);, A*/
void op_0x77(void);
/*LD A, B*/
void op_0x78(void);
/*LD A, C*/
void op_0x79(void);
/*LD A, D*/
void op_0x7a(void);
/*LD A, E*/
void op_0x7b(void);
/*LD A, H*/
void op_0x7c(void);
/*LD A, L*/
void op_0x7d(void);
/*LD A, (HL);*/
void op_0x7e(void);
/*LD A, A*/
void op_0x7f(void);
/*ADD A, B*/
void op_0x80(void);
/*ADD A, C*/
void op_0x81(void);
/*ADD A, D*/
void op_0x82(void);
/*ADD A, E*/
void op_0x83(void);
/*ADD A, H*/
void op_0x84(void);
/*ADD A, L*/
void op_0x85(void);
/*ADD A, (HL);*/
void op_0x86(void);
/*ADD A, A*/
void op_0x87(void);
/*ADDC A, B*/
void op_0x88(void);
/*ADDC A, C*/
void op_0x89(void);
/*ADDC A, D*/
void op_0x8a(void);
/*ADDC A, E*/
void op_0x8b(void);
/*ADDC A, H*/
void op_0x8c(void);
/*ADDC A, L*/
void op_0x8d(void);
/*ADDC A, (HL);*/
void op_0x8e(void);
/*ADDC A, A*/
void op_0x8f(void);
/*SUB B*/
void op_0x90(void);
/*SUB C*/
void op_0x91(void);
/*SUB D*/
void op_0x92(void);
/*SUB E*/
void op_0x93(void);
/*SUB H*/
void op_0x94(void);
/*SUB L*/
void op_0x95(void);
/*SUB (HL);*/
/*SUB A*/
void op_0x97(void);
/*SUBC A, B*/
void op_0x98(void);
/*SUBC A, C*/
void op_0x99(void);
/*SUBC A, D*/
void op_0x9a(void);
/*SUBC A, E*/
void op_0x9b(void);
/*SUBC A, H*/
void op_0x9c(void);
/*SUBC A, L*/
void op_0x9d(void);
/*SUBC A, (HL);*/
void op_0x9e(void);
/*SUBC A, A*/
void op_0x9f(void);
/*AND B*/
void op_0xa0(void);
/*AND C*/
void op_0xa1(void);
/*AND D*/
void op_0xa2(void);
/*AND E*/
void op_0xa3(void);
/*AND H*/
void op_0xa4(void);
/*AND L*/
void op_0xa5(void);
/*AND (HL);*/
void op_0xa6(void);
/*AND A*/
void op_0xa7(void);
/*XOR B*/
void op_0xa8(void);
/*XOR C*/
void op_0xa9(void);
/*XOR D*/
void op_0xaa(void);
/*XOR E*/
void op_0xab(void);
/*XOR H*/
void op_0xac(void);
/*XOR L*/
void op_0xad(void);
/*XOR (HL);*/
void op_0xae(void);
/*XOR A*/
void op_0xaf(void);
/*OR B*/
void op_0xb0(void);
/*OR C*/
void op_0xb1(void);
/*OR D*/
void op_0xb2(void);
/*OR E*/
void op_0xb3(void);
/*OR H*/
void op_0xb4(void);
/*OR L*/
void op_0xb5(void);
/*OR (HL);*/
void op_0xb6(void);
/*OR A*/
void op_0xb7(void);
/*CP B*/
void op_0xb8(void);
/*CP C*/
void op_0xb9(void);
/*CP D*/
void op_0xba(void);
/*CP E*/
void op_0xbb(void);
/*CP H*/
void op_0xbc(void);
/*CP L*/
void op_0xbd(void);
/*CP (HL);*/
void op_0xbe(void);
/*CP A*/
void op_0xbf(void);
/*RET NZ*/
void op_0xc0(void);
/*POP BC*/
void op_0xc1(void);
/*JP NZ, @*/
void op_0xc2(void);
/*JP @*/
void op_0xc3(void);
/*CALL NZ, @*/
void op_0xc4(void);
/*PUSH BC*/
void op_0xc5(void);
/*ADD A, #*/
void op_0xc6(void);
/*RST 0x00*/
void op_0xc7(void);
/*RET Z*/
void op_0xc8(void);
/*RET*/
void op_0xc9(void);
/*JP Z, @*/
void op_0xca(void);
void op_0xcb(void);
/*CALL Z, @*/
void op_0xcc(void);
/*CALL @*/
void op_0xcd(void);
/*ADDC A, #*/
void op_0xce(void);
/*RST 0x08*/
void op_0xcf(void);
/*RET NC*/
void op_0xd0(void);
/*POP DE*/
void op_0xd1(void);
/*JP NC, @*/
void op_0xd2(void);
/*OUT (#);, A*/
void op_0xd3(void);
/*CALL NC, @*/
void op_0xd4(void);
/*PUSH DE*/
void op_0xd5(void);
/*SUB #*/
void op_0xd6(void);
/*RST 0x10*/
void op_0xd7(void);
/*RET C*/
void op_0xd8(void);
/*EXX*/
void op_0xd9(void);
/*JP C, @*/
void op_0xda(void);
/*IN A,(#);*/
void op_0xdb(void);
/*CALL C, @*/
void op_0xdc(void);
void op_0xdd(void);
/*SUBC A, #*/
void op_0xde(void);
/*RST 0x18*/
void op_0xdf(void);
/*RET PO*/
void op_0xe0(void);
/*POP HL*/
void op_0xe1(void);
/*JP PO, @*/
void op_0xe2(void);
/*EX (SP);, HL*/
void op_0xe3(void);
/*CALL PO, @*/
void op_0xe4(void);
/*PUSH HL*/
void op_0xe5(void);
/*AND #*/
void op_0xe6(void);
/*RST 0x20*/
void op_0xe7(void);
/*RET PE*/
void op_0xe8(void);
/*JP HL*/
void op_0xe9(void);
/*JP PE, @*/
void op_0xea(void);
/*EX DE, HL*/
void op_0xeb(void);
/*CALL PE, @*/
void op_0xec(void);
void op_0xed(void);
/*XOR #*/
void op_0xee(void);
/*RST 0x28*/
void op_0xef(void);
/*RET P*/
void op_0xf0(void);
/*POP AF*/
void op_0xf1(void);
/*JP P, @*/
void op_0xf2(void);
/*DI*/
void op_0xf3(void);
/*CALL P, @*/
void op_0xf4(void);
/*PUSH AF*/
void op_0xf5(void);
/*OR #*/
void op_0xf6(void);
/*RST 0x30*/
void op_0xf7(void);
/*RET M*/
void op_0xf8(void);
/*LD SP, HL*/
void op_0xf9(void);
/*JP M, @*/
void op_0xfa(void);
/*EI*/
void op_0xfb(void);
/*CALL M, @*/
void op_0xfc(void);
void op_0xfd(void);
/*CP #*/
void op_0xfe(void);
/*RST 0x38*/
void op_0xff(void);

#endif
