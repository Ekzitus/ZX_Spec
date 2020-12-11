#ifndef Z80_OPCODE_CB_H
#define Z80_OPCODE_CB_H

/*RLC B*/
void op_CB_0x00(void);
/*RLC C*/
void op_CB_0x01(void);
/*RLC D*/
void op_CB_0x02(void);
/*RLC E*/
void op_CB_0x03(void);
/*RLC H*/
void op_CB_0x04(void);
/*RLC L*/
void op_CB_0x05(void);
/*RLC (HL);*/
void op_CB_0x06(void);
/*RLC A*/
void op_CB_0x07(void);
/*RRC B*/
void op_CB_0x08(void);
/*RRC C*/
void op_CB_0x09(void);
/*RRC D*/
void op_CB_0x0a(void);
/*RRC E*/
void op_CB_0x0b(void);
/*RRC H*/
void op_CB_0x0c(void);
/*RRC L*/
void op_CB_0x0d(void);
/*RRC (HL);*/
void op_CB_0x0e(void);
/*RRC A*/
void op_CB_0x0f(void);
/*RL B*/
void op_CB_0x10(void);
/*RL C*/
void op_CB_0x11(void);
/*RL D*/
void op_CB_0x12(void);
/*RL E*/
void op_CB_0x13(void);
/*RL H*/
void op_CB_0x14(void);
/*RL L*/
void op_CB_0x15(void);
/*RL (HL);*/
void op_CB_0x16(void);
/*RL A*/
void op_CB_0x17(void);
/*RR B*/
void op_CB_0x18(void);
/*RR C*/
void op_CB_0x19(void);
/*RR D*/
void op_CB_0x1a(void);
/*RR E*/
void op_CB_0x1b(void);
/*RR H*/
void op_CB_0x1c(void);
/*RR L*/
void op_CB_0x1d(void);
/*RR (HL);*/
void op_CB_0x1e(void);
/*RR A*/
void op_CB_0x1f(void);
/*SLA B*/
void op_CB_0x20(void);
/*SLA C*/
void op_CB_0x21(void);
/*SLA D*/
void op_CB_0x22(void);
/*SLA E*/
void op_CB_0x23(void);
/*SLA H*/
void op_CB_0x24(void);
/*SLA L*/
void op_CB_0x25(void);
/*SLA (HL);*/
void op_CB_0x26(void);
/*SLA A*/
void op_CB_0x27(void);
/*SRA B*/
void op_CB_0x28(void);
/*SRA C*/
void op_CB_0x29(void);
/*SRA D*/
void op_CB_0x2a(void);
/*SRA E*/
void op_CB_0x2b(void);
/*SRA H*/
void op_CB_0x2c(void);
/*SRA L*/
void op_CB_0x2d(void);
/*SRA (HL);*/
void op_CB_0x2e(void);
/*SRA A*/
void op_CB_0x2f(void);
/*SLL B*/
void op_CB_0x30(void);
/*SLL C*/
void op_CB_0x31(void);
/*SLL D*/
void op_CB_0x32(void);
/*SLL E*/
void op_CB_0x33(void);
/*SLL H*/
void op_CB_0x34(void);
/*SLL L*/
void op_CB_0x35(void);
/*SLL (HL);*/
void op_CB_0x36(void);
/*SLL A*/
void op_CB_0x37(void);
/*SRL B*/
void op_CB_0x38(void);
/*SRL C*/
void op_CB_0x39(void);
/*SRL D*/
void op_CB_0x3a(void);
/*SRL E*/
void op_CB_0x3b(void);
/*SRL H*/
void op_CB_0x3c(void);
/*SRL L*/
void op_CB_0x3d(void);
/*SRL (HL);*/
void op_CB_0x3e(void);
/*SRL A*/
void op_CB_0x3f(void);
/*BIT 0, B*/
void op_CB_0x40(void);
/*BIT 0, C*/
void op_CB_0x41(void);
/*BIT 0, D*/
void op_CB_0x42(void);
/*BIT 0, E*/
void op_CB_0x43(void);
/*BIT 0, H*/
void op_CB_0x44(void);
/*BIT 0, L*/
void op_CB_0x45(void);
/*BIT 0, (HL);*/
void op_CB_0x46(void);
/*BIT 0, A*/
void op_CB_0x47(void);
/*BIT 1, B*/
void op_CB_0x48(void);
/*BIT 1, C*/
void op_CB_0x49(void);
/*BIT 1, D*/
void op_CB_0x4a(void);
/*BIT 1, E*/
void op_CB_0x4b(void);
/*BIT 1, H*/
void op_CB_0x4c(void);
/*BIT 1, L*/
void op_CB_0x4d(void);
/*BIT 1, (HL);*/
void op_CB_0x4e(void);
/*BIT 1, A*/
void op_CB_0x4f(void);
/*BIT 2, B*/
void op_CB_0x50(void);
/*BIT 2, C*/
void op_CB_0x51(void);
/*BIT 2, D*/
void op_CB_0x52(void);
/*BIT 2, E*/
void op_CB_0x53(void);
/*BIT 2, H*/
void op_CB_0x54(void);
/*BIT 2, L*/
void op_CB_0x55(void);
/*BIT 2, (HL);*/
void op_CB_0x56(void);
/*BIT 2, A*/
void op_CB_0x57(void);
/*BIT 3, B*/
void op_CB_0x58(void);
/*BIT 3, C*/
void op_CB_0x59(void);
/*BIT 3, D*/
void op_CB_0x5a(void);
/*BIT 3, E*/
void op_CB_0x5b(void);
/*BIT 3, H*/
void op_CB_0x5c(void);
/*BIT 3, L*/
void op_CB_0x5d(void);
/*BIT 3, (HL);*/
void op_CB_0x5e(void);
/*BIT 3, A*/
void op_CB_0x5f(void);
/*BIT 4, B*/
void op_CB_0x60(void);
/*BIT 4, C*/
void op_CB_0x61(void);
/*BIT 4, D*/
void op_CB_0x62(void);
/*BIT 4, E*/
void op_CB_0x63(void);
/*BIT 4, H*/
void op_CB_0x64(void);
/*BIT 4, L*/
void op_CB_0x65(void);
/*BIT 4, (HL);*/
void op_CB_0x66(void);
/*BIT 4, A*/
void op_CB_0x67(void);
/*BIT 5, B*/
void op_CB_0x68(void);
/*BIT 5, C*/
void op_CB_0x69(void);
/*BIT 5, D*/
void op_CB_0x6a(void);
/*BIT 5, E*/
void op_CB_0x6b(void);
/*BIT 5, H*/
void op_CB_0x6c(void);
/*BIT 5, L*/
void op_CB_0x6d(void);
/*BIT 5, (HL);*/
void op_CB_0x6e(void);
/*BIT 5, A*/
void op_CB_0x6f(void);
/*BIT 6, B*/
void op_CB_0x70(void);
/*BIT 6, C*/
void op_CB_0x71(void);
/*BIT 6, D*/
void op_CB_0x72(void);
/*BIT 6, E*/
void op_CB_0x73(void);
/*BIT 6, H*/
void op_CB_0x74(void);
/*BIT 6, L*/
void op_CB_0x75(void);
/*BIT 6, (HL);*/
void op_CB_0x76(void);
/*BIT 6, A*/
void op_CB_0x77(void);
/*BIT 7, B*/
void op_CB_0x78(void);
/*BIT 7, C*/
void op_CB_0x79(void);
/*BIT 7, D*/
void op_CB_0x7a(void);
/*BIT 7, E*/
void op_CB_0x7b(void);
/*BIT 7, H*/
void op_CB_0x7c(void);
/*BIT 7, L*/
void op_CB_0x7d(void);
/*BIT 7, (HL);*/
void op_CB_0x7e(void);
/*BIT 7, A*/
void op_CB_0x7f(void);
/*RES 0, B*/
void op_CB_0x80(void);
/*RES 0, C*/
void op_CB_0x81(void);
/*RES 0, D*/
void op_CB_0x82(void);
/*RES 0, E*/
void op_CB_0x83(void);
/*RES 0, H*/
void op_CB_0x84(void);
/*RES 0, L*/
void op_CB_0x85(void);
/*RES 0, (HL);*/
void op_CB_0x86(void);
/*RES 0, A*/
void op_CB_0x87(void);
/*RES 1, B*/
void op_CB_0x88(void);
/*RES 1, C*/
void op_CB_0x89(void);
/*RES 1, D*/
void op_CB_0x8a(void);
/*RES 1, E*/
void op_CB_0x8b(void);
/*RES 1, H*/
void op_CB_0x8c(void);
/*RES 1, L*/
void op_CB_0x8d(void);
/*RES 1, (HL);*/
void op_CB_0x8e(void);
/*RES 1, A*/
void op_CB_0x8f(void);
/*RES 2, B*/
void op_CB_0x90(void);
/*RES 2, C*/
void op_CB_0x91(void);
/*RES 2, D*/
void op_CB_0x92(void);
/*RES 2, E*/
void op_CB_0x93(void);
/*RES 2, H*/
void op_CB_0x94(void);
/*RES 2, L*/
void op_CB_0x95(void);
/*RES 2, (HL);*/
void op_CB_0x96(void);
/*RES 2, A*/
void op_CB_0x97(void);
/*RES 3, B*/
void op_CB_0x98(void);
/*RES 3, C*/
void op_CB_0x99(void);
/*RES 3, D*/
void op_CB_0x9a(void);
/*RES 3, E*/
void op_CB_0x9b(void);
/*RES 3, H*/
void op_CB_0x9c(void);
/*RES 3, L*/
void op_CB_0x9d(void);
/*RES 3, (HL);*/
void op_CB_0x9e(void);
/*RES 3, A*/
void op_CB_0x9f(void);
/*RES 4, B*/
void op_CB_0xa0(void);
/*RES 4, C*/
void op_CB_0xa1(void);
/*RES 4, D*/
void op_CB_0xa2(void);
/*RES 4, E*/
void op_CB_0xa3(void);
/*RES 4, H*/
void op_CB_0xa4(void);
/*RES 4, L*/
void op_CB_0xa5(void);
/*RES 4, (HL);*/
void op_CB_0xa6(void);
/*RES 4, A*/
void op_CB_0xa7(void);
/*RES 5, B*/
void op_CB_0xa8(void);
/*RES 5, C*/
void op_CB_0xa9(void);
/*RES 5, D*/
void op_CB_0xaa(void);
/*RES 5, E*/
void op_CB_0xab(void);
/*RES 5, H*/
void op_CB_0xac(void);
/*RES 5, L*/
void op_CB_0xad(void);
/*RES 5, (HL);*/
void op_CB_0xae(void);
/*RES 5, A*/
void op_CB_0xaf(void);
/*RES 6, B*/
void op_CB_0xb0(void);
/*RES 6, C*/
void op_CB_0xb1(void);
/*RES 6, D*/
void op_CB_0xb2(void);
/*RES 6, E*/
void op_CB_0xb3(void);
/*RES 6, H*/
void op_CB_0xb4(void);
/*RES 6, L*/
void op_CB_0xb5(void);
/*RES 6, (HL);*/
void op_CB_0xb6(void);
/*RES 6, A*/
void op_CB_0xb7(void);
/*RES 7, B*/
void op_CB_0xb8(void);
/*RES 7, C*/
void op_CB_0xb9(void);
/*RES 7, D*/
void op_CB_0xba(void);
/*RES 7, E*/
void op_CB_0xbb(void);
/*RES 7, H*/
void op_CB_0xbc(void);
/*RES 7, L*/
void op_CB_0xbd(void);
/*RES 7, (HL);*/
void op_CB_0xbe(void);
/*RES 7, A*/
void op_CB_0xbf(void);
/*SET 0, B*/
void op_CB_0xc0(void);
/*SET 0, C*/
void op_CB_0xc1(void);
/*SET 0, D*/
void op_CB_0xc2(void);
/*SET 0, E*/
void op_CB_0xc3(void);
/*SET 0, H*/
void op_CB_0xc4(void);
/*SET 0, L*/
void op_CB_0xc5(void);
/*SET 0, (HL);*/
void op_CB_0xc6(void);
/*SET 0, A*/
void op_CB_0xc7(void);
/*SET 1, B*/
void op_CB_0xc8(void);
/*SET 1, C*/
void op_CB_0xc9(void);
/*SET 1, D*/
void op_CB_0xca(void);
/*SET 1, E*/
void op_CB_0xcb(void);
/*SET 1, H*/
void op_CB_0xcc(void);
/*SET 1, L*/
void op_CB_0xcd(void);
/*SET 1, (HL);*/
void op_CB_0xce(void);
/*SET 1, A*/
void op_CB_0xcf(void);
/*SET 2, B*/
void op_CB_0xd0(void);
/*SET 2, C*/
void op_CB_0xd1(void);
/*SET 2, D*/
void op_CB_0xd2(void);
/*SET 2, E*/
void op_CB_0xd3(void);
/*SET 2, H*/
void op_CB_0xd4(void);
/*SET 2, L*/
void op_CB_0xd5(void);
/*SET 2, (HL);*/
void op_CB_0xd6(void);
/*SET 2, A*/
void op_CB_0xd7(void);
/*SET 3, B*/
void op_CB_0xd8(void);
/*SET 3, C*/
void op_CB_0xd9(void);
/*SET 3, D*/
void op_CB_0xda(void);
/*SET 3, E*/
void op_CB_0xdb(void);
/*SET 3, H*/
void op_CB_0xdc(void);
/*SET 3, L*/
void op_CB_0xdd(void);
/*SET 3, (HL);*/
void op_CB_0xde(void);
/*SET 3, A*/
void op_CB_0xdf(void);
/*SET 4, B*/
void op_CB_0xe0(void);
/*SET 4, C*/
void op_CB_0xe1(void);
/*SET 4, D*/
void op_CB_0xe2(void);
/*SET 4, E*/
void op_CB_0xe3(void);
/*SET 4, H*/
void op_CB_0xe4(void);
/*SET 4, L*/
void op_CB_0xe5(void);
/*SET 4, (HL);*/
void op_CB_0xe6(void);
/*SET 4, A*/
void op_CB_0xe7(void);
/*SET 5, B*/
void op_CB_0xe8(void);
/*SET 5, C*/
void op_CB_0xe9(void);
/*SET 5, D*/
void op_CB_0xea(void);
/*SET 5, E*/
void op_CB_0xeb(void);
/*SET 5, H*/
void op_CB_0xec(void);
/*SET 5, L*/
void op_CB_0xed(void);
/*SET 5, (HL);*/
void op_CB_0xee(void);
/*SET 5, A*/
void op_CB_0xef(void);
/*SET 6, B*/
void op_CB_0xf0(void);
/*SET 6, C*/
void op_CB_0xf1(void);
/*SET 6, D*/
void op_CB_0xf2(void);
/*SET 6, E*/
void op_CB_0xf3(void);
/*SET 6, H*/
void op_CB_0xf4(void);
/*SET 6, L*/
void op_CB_0xf5(void);
/*SET 6, (HL);*/
void op_CB_0xf6(void);
/*SET 6, A*/
void op_CB_0xf7(void);
/*SET 7, B*/
void op_CB_0xf8(void);
/*SET 7, C*/
void op_CB_0xf9(void);
/*SET 7, D*/
void op_CB_0xfa(void);
/*SET 7, E*/
void op_CB_0xfb(void);
/*SET 7, H*/
void op_CB_0xfc(void);
/*SET 7, L*/
void op_CB_0xfd(void);
/*SET 7, (HL);*/
void op_CB_0xfe(void);
/*SET 7, A*/
void op_CB_0xff(void);

#endif