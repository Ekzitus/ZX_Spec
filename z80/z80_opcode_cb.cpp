#include "Z80_OpCode_cb.h"
#include "z80_common.h"

extern unsigned char Z80_HalfcarryAddTable[8]; 
extern unsigned char Z80_HalfcarrySubTable[8]; 
extern unsigned char Z80_OverflowAddTable[8]; 
extern unsigned char Z80_OverflowSubTable[8];
/*the S,Z,5 and 3 bits of the index*/
extern unsigned char Z80_SZ53Table[0x100]; 
/*OR the above two tables together*/
extern unsigned char Z80_SZ53pTable[0x100]; 
/*the parity of the lookup value*/
extern unsigned char Z80_ParityTable[0x100]; 
/*table for daa,contains af*/
extern unsigned char Z80_DAATab[0x1000];

extern unsigned char IFF1;
extern unsigned char IFF2;
extern unsigned char IM;
extern unsigned char Z80_Halt;
 
extern unsigned char Z80_Temp8;
extern unsigned short Z80_Temp16;
 
extern unsigned char Z80_OpCode;
extern unsigned char Z80_Prefix;
extern unsigned char Z80_NoInterrupt;
extern unsigned char Z80_MachineCycle;

extern UZ80_Reg uZ80_Reg;
extern UZ80_A_Reg uZ80_A_Reg;
extern UZ80_SU uZ80_SU;

/*RLC Z80_B*/
void op_CB_0x00(void)
{
 RLC(Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RLC Z80_C*/
void op_CB_0x01(void)
{
 RLC(Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RLC Z80_D*/
void op_CB_0x02(void)
{
 RLC(Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RLC Z80_E*/
void op_CB_0x03(void)
{
 RLC(Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RLC Z80_H*/
void op_CB_0x04(void)
{
 RLC(Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RLC Z80_L*/
void op_CB_0x05(void)
{
 RLC(Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RLC (Z80_HL)*/
void op_CB_0x06(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 RLC(Z80_Temp8);
 WRITE_BYTE(Z80_HL,Z80_Temp8);
 T_WAIT_UNTIL(11);
 return;
}
 
/*RLC Z80_A*/
void op_CB_0x07(void)
{
 RLC(Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RRC Z80_B*/
void op_CB_0x08(void)
{
 RRC(Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RRC Z80_C*/
void op_CB_0x09(void)
{
 RRC(Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RRC Z80_D*/
void op_CB_0x0a(void)
{
 RRC(Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RRC Z80_E*/
void op_CB_0x0b(void)
{
 RRC(Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RRC Z80_H*/
void op_CB_0x0c(void)
{
 RRC(Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RRC Z80_L*/
void op_CB_0x0d(void)
{
 RRC(Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RRC (Z80_HL)*/
void op_CB_0x0e(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 RRC(Z80_Temp8);
 WRITE_BYTE(Z80_HL,Z80_Temp8);
 T_WAIT_UNTIL(11);
 return;
}
 
/*RRC Z80_A*/
void op_CB_0x0f(void)
{
 RRC(Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RL Z80_B*/
void op_CB_0x10(void)
{
 RL(Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RL Z80_C*/
void op_CB_0x11(void)
{
 RL(Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RL Z80_D*/
void op_CB_0x12(void)
{
 RL(Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RL Z80_E*/
void op_CB_0x13(void)
{
 RL(Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RL Z80_H*/
void op_CB_0x14(void)
{
 RL(Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RL Z80_L*/
void op_CB_0x15(void)
{
 RL(Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RL (Z80_HL)*/
void op_CB_0x16(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 RL(Z80_Temp8);
 WRITE_BYTE(Z80_HL,Z80_Temp8);
 T_WAIT_UNTIL(11);
 return;
}
 
/*RL Z80_A*/
void op_CB_0x17(void)
{
 RL(Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RR Z80_B*/
void op_CB_0x18(void)
{
 RR(Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RR Z80_C*/
void op_CB_0x19(void)
{
 RR(Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RR Z80_D*/
void op_CB_0x1a(void)
{
 RR(Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RR Z80_E*/
void op_CB_0x1b(void)
{
 RR(Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RR Z80_H*/
void op_CB_0x1c(void)
{
 RR(Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RR Z80_L*/
void op_CB_0x1d(void)
{
 RR(Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RR (Z80_HL)*/
void op_CB_0x1e(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 RR(Z80_Temp8);
 WRITE_BYTE(Z80_HL,Z80_Temp8);
 T_WAIT_UNTIL(11);
 return;
}
 
/*RR Z80_A*/
void op_CB_0x1f(void)
{
 RR(Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SLA Z80_B*/
void op_CB_0x20(void)
{
 SLA(Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SLA Z80_C*/
void op_CB_0x21(void)
{
 SLA(Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SLA Z80_D*/
void op_CB_0x22(void)
{
 SLA(Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SLA Z80_E*/
void op_CB_0x23(void)
{
 SLA(Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SLA Z80_H*/
void op_CB_0x24(void)
{
 SLA(Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SLA Z80_L*/
void op_CB_0x25(void)
{
 SLA(Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SLA (Z80_HL)*/
void op_CB_0x26(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 SLA(Z80_Temp8);
 WRITE_BYTE(Z80_HL,Z80_Temp8);
 T_WAIT_UNTIL(11);
 return;
}
 
/*SLA Z80_A*/
void op_CB_0x27(void)
{
 SLA(Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SRA Z80_B*/
void op_CB_0x28(void)
{
 SRA(Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SRA Z80_C*/
void op_CB_0x29(void)
{
 SRA(Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SRA Z80_D*/
void op_CB_0x2a(void)
{
 SRA(Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SRA Z80_E*/
void op_CB_0x2b(void)
{
 SRA(Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SRA Z80_H*/
void op_CB_0x2c(void)
{
 SRA(Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SRA Z80_L*/
void op_CB_0x2d(void)
{
 SRA(Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SRA (Z80_HL)*/
void op_CB_0x2e(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 SRA(Z80_Temp8);
 WRITE_BYTE(Z80_HL,Z80_Temp8);
 T_WAIT_UNTIL(11);
 return;
}
 
/*SRA Z80_A*/
void op_CB_0x2f(void)
{
 SRA(Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SLL Z80_B*/
void op_CB_0x30(void)
{
 SLL(Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SLL Z80_C*/
void op_CB_0x31(void)
{
 SLL(Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SLL Z80_D*/
void op_CB_0x32(void)
{
 SLL(Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SLL Z80_E*/
void op_CB_0x33(void)
{
 SLL(Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SLL Z80_H*/
void op_CB_0x34(void)
{
 SLL(Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SLL Z80_L*/
void op_CB_0x35(void)
{
 SLL(Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SLL (Z80_HL)*/
void op_CB_0x36(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 SLL(Z80_Temp8);
 WRITE_BYTE(Z80_HL,Z80_Temp8);
 T_WAIT_UNTIL(11);
 return;
}
 
/*SLL Z80_A*/
void op_CB_0x37(void)
{
 SLL(Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SRL Z80_B*/
void op_CB_0x38(void)
{
 SRL(Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SRL Z80_C*/
void op_CB_0x39(void)
{
 SRL(Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SRL Z80_D*/
void op_CB_0x3a(void)
{
 SRL(Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SRL Z80_E*/
void op_CB_0x3b(void)
{
 SRL(Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SRL Z80_H*/
void op_CB_0x3c(void)
{
 SRL(Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SRL Z80_L*/
void op_CB_0x3d(void)
{
 SRL(Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SRL (Z80_HL)*/
void op_CB_0x3e(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 SRL(Z80_Temp8);
 WRITE_BYTE(Z80_HL,Z80_Temp8);
 T_WAIT_UNTIL(11);
 return;
}
 
/*SRL Z80_A*/
void op_CB_0x3f(void)
{
 SRL(Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 0,Z80_B*/
void op_CB_0x40(void)
{
 BIT(0,Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 0,Z80_C*/
void op_CB_0x41(void)
{
 BIT(0,Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 0,Z80_D*/
void op_CB_0x42(void)
{
 BIT(0,Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 0,Z80_E*/
void op_CB_0x43(void)
{
 BIT(0,Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 0,Z80_H*/
void op_CB_0x44(void)
{
 BIT(0,Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 0,Z80_L*/
void op_CB_0x45(void)
{
 BIT(0,Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 0,(Z80_HL)*/
void op_CB_0x46(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 BIT_MPTR(0,Z80_Temp8);
 T_WAIT_UNTIL(8);
 return;
}
 
/*BIT 0,Z80_A*/
void op_CB_0x47(void)
{
 BIT(0,Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 1,Z80_B*/
void op_CB_0x48(void)
{
 BIT(1,Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 1,Z80_C*/
void op_CB_0x49(void)
{
 BIT(1,Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 1,Z80_D*/
void op_CB_0x4a(void)
{
 BIT(1,Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 1,Z80_E*/
void op_CB_0x4b(void)
{
 BIT(1,Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 1,Z80_H*/
void op_CB_0x4c(void)
{
 BIT(1,Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 1,Z80_L*/
void op_CB_0x4d(void)
{
 BIT(1,Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 1,(Z80_HL)*/
void op_CB_0x4e(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 BIT_MPTR(1,Z80_Temp8);
 T_WAIT_UNTIL(8);
 return;
}
 
/*BIT 1,Z80_A*/
void op_CB_0x4f(void)
{
 BIT(1,Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 2,Z80_B*/
void op_CB_0x50(void)
{
 BIT(2,Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 2,Z80_C*/
void op_CB_0x51(void)
{
 BIT(2,Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 2,Z80_D*/
void op_CB_0x52(void)
{
 BIT(2,Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 2,Z80_E*/
void op_CB_0x53(void)
{
 BIT(2,Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 2,Z80_H*/
void op_CB_0x54(void)
{
 BIT(2,Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 2,Z80_L*/
void op_CB_0x55(void)
{
 BIT(2,Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 2,(Z80_HL)*/
void op_CB_0x56(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 BIT_MPTR(2,Z80_Temp8);
 T_WAIT_UNTIL(8);
 return;
}
 
/*BIT 2,Z80_A*/
void op_CB_0x57(void)
{
 BIT(2,Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 3,Z80_B*/
void op_CB_0x58(void)
{
 BIT(3,Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 3,Z80_C*/
void op_CB_0x59(void)
{
 BIT(3,Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 3,Z80_D*/
void op_CB_0x5a(void)
{
 BIT(3,Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 3,Z80_E*/
void op_CB_0x5b(void)
{
 BIT(3,Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 3,Z80_H*/
void op_CB_0x5c(void)
{
 BIT(3,Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 3,Z80_L*/
void op_CB_0x5d(void)
{
 BIT(3,Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 3,(Z80_HL)*/
void op_CB_0x5e(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 BIT_MPTR(3,Z80_Temp8);
 T_WAIT_UNTIL(8);
 return;
}
 
/*BIT 3,Z80_A*/
void op_CB_0x5f(void)
{
 BIT(3,Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 4,Z80_B*/
void op_CB_0x60(void)
{
 BIT(4,Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 4,Z80_C*/
void op_CB_0x61(void)
{
 BIT(4,Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 4,Z80_D*/
void op_CB_0x62(void)
{
 BIT(4,Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 4,Z80_E*/
void op_CB_0x63(void)
{
 BIT(4,Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 4,Z80_H*/
void op_CB_0x64(void)
{
 BIT(4,Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 4,Z80_L*/
void op_CB_0x65(void)
{
 BIT(4,Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 4,(Z80_HL)*/
void op_CB_0x66(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 BIT_MPTR(4,Z80_Temp8);
 T_WAIT_UNTIL(8);
 return;
}
 
/*BIT 4,Z80_A*/
void op_CB_0x67(void)
{
 BIT(4,Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 5,Z80_B*/
void op_CB_0x68(void)
{
 BIT(5,Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 5,Z80_C*/
void op_CB_0x69(void)
{
 BIT(5,Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 5,Z80_D*/
void op_CB_0x6a(void)
{
 BIT(5,Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 5,Z80_E*/
void op_CB_0x6b(void)
{
 BIT(5,Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 5,Z80_H*/
void op_CB_0x6c(void)
{
 BIT(5,Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 5,Z80_L*/
void op_CB_0x6d(void)
{
 BIT(5,Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 5,(Z80_HL)*/
void op_CB_0x6e(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 BIT_MPTR(5,Z80_Temp8);
 T_WAIT_UNTIL(8);
 return;
}
 
/*BIT 5,Z80_A*/
void op_CB_0x6f(void)
{
 BIT(5,Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 6,Z80_B*/
void op_CB_0x70(void)
{
 BIT(6,Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 6,Z80_C*/
void op_CB_0x71(void)
{
 BIT(6,Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 6,Z80_D*/
void op_CB_0x72(void)
{
 BIT(6,Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 6,Z80_E*/
void op_CB_0x73(void)
{
 BIT(6,Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 6,Z80_H*/
void op_CB_0x74(void)
{
 BIT(6,Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 6,Z80_L*/
void op_CB_0x75(void)
{
 BIT(6,Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 6,(Z80_HL)*/
void op_CB_0x76(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 BIT_MPTR(6,Z80_Temp8);
 T_WAIT_UNTIL(8);
 return;
}
 
/*BIT 6,Z80_A*/
void op_CB_0x77(void)
{
 BIT(6,Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 7,Z80_B*/
void op_CB_0x78(void)
{
 BIT(7,Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 7,Z80_C*/
void op_CB_0x79(void)
{
 BIT(7,Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 7,Z80_D*/
void op_CB_0x7a(void)
{
 BIT(7,Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 7,Z80_E*/
void op_CB_0x7b(void)
{
 BIT(7,Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 7,Z80_H*/
void op_CB_0x7c(void)
{
 BIT(7,Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 7,Z80_L*/
void op_CB_0x7d(void)
{
 BIT(7,Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*BIT 7,(Z80_HL)*/
void op_CB_0x7e(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 BIT_MPTR(7,Z80_Temp8);
 T_WAIT_UNTIL(8);
 return;
}
 
/*BIT 7,Z80_A*/
void op_CB_0x7f(void)
{
 BIT(7,Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 0,Z80_B*/
void op_CB_0x80(void)
{
 RES(0,Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 0,Z80_C*/
void op_CB_0x81(void)
{
 RES(0,Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 0,Z80_D*/
void op_CB_0x82(void)
{
 RES(0,Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 0,Z80_E*/
void op_CB_0x83(void)
{
 RES(0,Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 0,Z80_H*/
void op_CB_0x84(void)
{
 RES(0,Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 0,Z80_L*/
void op_CB_0x85(void)
{
 RES(0,Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 0,(Z80_HL)*/
void op_CB_0x86(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 RES(0,Z80_Temp8);
 WRITE_BYTE(Z80_HL,Z80_Temp8);
 T_WAIT_UNTIL(11);
 return;
}
 
/*RES 0,Z80_A*/
void op_CB_0x87(void)
{
 RES(0,Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 1,Z80_B*/
void op_CB_0x88(void)
{
 RES(1,Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 1,Z80_C*/
void op_CB_0x89(void)
{
 RES(1,Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 1,Z80_D*/
void op_CB_0x8a(void)
{
 RES(1,Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 1,Z80_E*/
void op_CB_0x8b(void)
{
 RES(1,Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 1,Z80_H*/
void op_CB_0x8c(void)
{
 RES(1,Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 1,Z80_L*/
void op_CB_0x8d(void)
{
 RES(1,Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 1,(Z80_HL)*/
void op_CB_0x8e(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 RES(1,Z80_Temp8);
 WRITE_BYTE(Z80_HL,Z80_Temp8);
 T_WAIT_UNTIL(11);
 return;
}
 
/*RES 1,Z80_A*/
void op_CB_0x8f(void)
{
 RES(1,Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 2,Z80_B*/
void op_CB_0x90(void)
{
 RES(2,Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 2,Z80_C*/
void op_CB_0x91(void)
{
 RES(2,Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 2,Z80_D*/
void op_CB_0x92(void)
{
 RES(2,Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 2,Z80_E*/
void op_CB_0x93(void)
{
 RES(2,Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 2,Z80_H*/
void op_CB_0x94(void)
{
 RES(2,Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 2,Z80_L*/
void op_CB_0x95(void)
{
 RES(2,Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 2,(Z80_HL)*/
void op_CB_0x96(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 RES(2,Z80_Temp8);
 WRITE_BYTE(Z80_HL,Z80_Temp8);
 T_WAIT_UNTIL(11);
 return;
}
 
/*RES 2,Z80_A*/
void op_CB_0x97(void)
{
 RES(2,Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 3,Z80_B*/
void op_CB_0x98(void)
{
 RES(3,Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 3,Z80_C*/
void op_CB_0x99(void)
{
 RES(3,Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 3,Z80_D*/
void op_CB_0x9a(void)
{
 RES(3,Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 3,Z80_E*/
void op_CB_0x9b(void)
{
 RES(3,Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 3,Z80_H*/
void op_CB_0x9c(void)
{
 RES(3,Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 3,Z80_L*/
void op_CB_0x9d(void)
{
 RES(3,Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 3,(Z80_HL)*/
void op_CB_0x9e(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 RES(3,Z80_Temp8);
 WRITE_BYTE(Z80_HL,Z80_Temp8);
 T_WAIT_UNTIL(11);
 return;
}
 
/*RES 3,Z80_A*/
void op_CB_0x9f(void)
{
 RES(3,Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 4,Z80_B*/
void op_CB_0xa0(void)
{
 RES(4,Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 4,Z80_C*/
void op_CB_0xa1(void)
{
 RES(4,Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 4,Z80_D*/
void op_CB_0xa2(void)
{
 RES(4,Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 4,Z80_E*/
void op_CB_0xa3(void)
{
 RES(4,Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 4,Z80_H*/
void op_CB_0xa4(void)
{
 RES(4,Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 4,Z80_L*/
void op_CB_0xa5(void)
{
 RES(4,Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 4,(Z80_HL)*/
void op_CB_0xa6(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 RES(4,Z80_Temp8);
 WRITE_BYTE(Z80_HL,Z80_Temp8);
 T_WAIT_UNTIL(11);
 return;
}
 
/*RES 4,Z80_A*/
void op_CB_0xa7(void)
{
 RES(4,Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 5,Z80_B*/
void op_CB_0xa8(void)
{
 RES(5,Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 5,Z80_C*/
void op_CB_0xa9(void)
{
 RES(5,Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 5,Z80_D*/
void op_CB_0xaa(void)
{
 RES(5,Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 5,Z80_E*/
void op_CB_0xab(void)
{
 RES(5,Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 5,Z80_H*/
void op_CB_0xac(void)
{
 RES(5,Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 5,Z80_L*/
void op_CB_0xad(void)
{
 RES(5,Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 5,(Z80_HL)*/
void op_CB_0xae(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 RES(5,Z80_Temp8);
 WRITE_BYTE(Z80_HL,Z80_Temp8);
 T_WAIT_UNTIL(11);
 return;
}
 
/*RES 5,Z80_A*/
void op_CB_0xaf(void)
{
 RES(5,Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 6,Z80_B*/
void op_CB_0xb0(void)
{
 RES(6,Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 6,Z80_C*/
void op_CB_0xb1(void)
{
 RES(6,Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 6,Z80_D*/
void op_CB_0xb2(void)
{
 RES(6,Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 6,Z80_E*/
void op_CB_0xb3(void)
{
 RES(6,Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 6,Z80_H*/
void op_CB_0xb4(void)
{
 RES(6,Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 6,Z80_L*/
void op_CB_0xb5(void)
{
 RES(6,Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 6,(Z80_HL)*/
void op_CB_0xb6(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 RES(6,Z80_Temp8);
 WRITE_BYTE(Z80_HL,Z80_Temp8);
 T_WAIT_UNTIL(11);
 return;
}
 
/*RES 6,Z80_A*/
void op_CB_0xb7(void)
{
 RES(6,Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 7,Z80_B*/
void op_CB_0xb8(void)
{
 RES(7,Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 7,Z80_C*/
void op_CB_0xb9(void)
{
 RES(7,Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 7,Z80_D*/
void op_CB_0xba(void)
{
 RES(7,Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 7,Z80_E*/
void op_CB_0xbb(void)
{
 RES(7,Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 7,Z80_H*/
void op_CB_0xbc(void)
{
 RES(7,Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 7,Z80_L*/
void op_CB_0xbd(void)
{
 RES(7,Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RES 7,(Z80_HL)*/
void op_CB_0xbe(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 RES(7,Z80_Temp8);
 WRITE_BYTE(Z80_HL,Z80_Temp8);
 T_WAIT_UNTIL(11);
 return;
}
 
/*RES 7,Z80_A*/
void op_CB_0xbf(void)
{
 RES(7,Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 0,Z80_B*/
void op_CB_0xc0(void)
{
 SET(0,Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 0,Z80_C*/
void op_CB_0xc1(void)
{
 SET(0,Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 0,Z80_D*/
void op_CB_0xc2(void)
{
 SET(0,Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 0,Z80_E*/
void op_CB_0xc3(void)
{
 SET(0,Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 0,Z80_H*/
void op_CB_0xc4(void)
{
 SET(0,Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 0,Z80_L*/
void op_CB_0xc5(void)
{
 SET(0,Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 0,(Z80_HL)*/
void op_CB_0xc6(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 SET(0,Z80_Temp8);
 WRITE_BYTE(Z80_HL,Z80_Temp8);
 T_WAIT_UNTIL(11);
 return;
}
 
/*SET 0,Z80_A*/
void op_CB_0xc7(void)
{
 SET(0,Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 1,Z80_B*/
void op_CB_0xc8(void)
{
 SET(1,Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 1,Z80_C*/
void op_CB_0xc9(void)
{
 SET(1,Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 1,Z80_D*/
void op_CB_0xca(void)
{
 SET(1,Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 1,Z80_E*/
void op_CB_0xcb(void)
{
 SET(1,Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 1,Z80_H*/
void op_CB_0xcc(void)
{
 SET(1,Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 1,Z80_L*/
void op_CB_0xcd(void)
{
 SET(1,Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 1,(Z80_HL)*/
void op_CB_0xce(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 SET(1,Z80_Temp8);
 WRITE_BYTE(Z80_HL,Z80_Temp8);
 T_WAIT_UNTIL(11);
 return;
}
 
/*SET 1,Z80_A*/
void op_CB_0xcf(void)
{
 SET(1,Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 2,Z80_B*/
void op_CB_0xd0(void)
{
 SET(2,Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 2,Z80_C*/
void op_CB_0xd1(void)
{
 SET(2,Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 2,Z80_D*/
void op_CB_0xd2(void)
{
 SET(2,Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 2,Z80_E*/
void op_CB_0xd3(void)
{
 SET(2,Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 2,Z80_H*/
void op_CB_0xd4(void)
{
 SET(2,Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 2,Z80_L*/
void op_CB_0xd5(void)
{
 SET(2,Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 2,(Z80_HL)*/
void op_CB_0xd6(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 SET(2,Z80_Temp8);
 WRITE_BYTE(Z80_HL,Z80_Temp8);
 T_WAIT_UNTIL(11);
 return;
}
 
/*SET 2,Z80_A*/
void op_CB_0xd7(void)
{
 SET(2,Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 3,Z80_B*/
void op_CB_0xd8(void)
{
 SET(3,Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 3,Z80_C*/
void op_CB_0xd9(void)
{
 SET(3,Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 3,Z80_D*/
void op_CB_0xda(void)
{
 SET(3,Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 3,Z80_E*/
void op_CB_0xdb(void)
{
 SET(3,Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 3,Z80_H*/
void op_CB_0xdc(void)
{
 SET(3,Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 3,Z80_L*/
void op_CB_0xdd(void)
{
 SET(3,Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 3,(Z80_HL)*/
void op_CB_0xde(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 SET(3,Z80_Temp8);
 WRITE_BYTE(Z80_HL,Z80_Temp8);
 T_WAIT_UNTIL(11);
 return;
}
 
/*SET 3,Z80_A*/
void op_CB_0xdf(void)
{
 SET(3,Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 4,Z80_B*/
void op_CB_0xe0(void)
{
 SET(4,Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 4,Z80_C*/
void op_CB_0xe1(void)
{
 SET(4,Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 4,Z80_D*/
void op_CB_0xe2(void)
{
 SET(4,Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 4,Z80_E*/
void op_CB_0xe3(void)
{
 SET(4,Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 4,Z80_H*/
void op_CB_0xe4(void)
{
 SET(4,Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 4,Z80_L*/
void op_CB_0xe5(void)
{
 SET(4,Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 4,(Z80_HL)*/
void op_CB_0xe6(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 SET(4,Z80_Temp8);
 WRITE_BYTE(Z80_HL,Z80_Temp8);
 T_WAIT_UNTIL(11);
 return;
}
 
/*SET 4,Z80_A*/
void op_CB_0xe7(void)
{
 SET(4,Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 5,Z80_B*/
void op_CB_0xe8(void)
{
 SET(5,Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 5,Z80_C*/
void op_CB_0xe9(void)
{
 SET(5,Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 5,Z80_D*/
void op_CB_0xea(void)
{
 SET(5,Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 5,Z80_E*/
void op_CB_0xeb(void)
{
 SET(5,Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 5,Z80_H*/
void op_CB_0xec(void)
{
 SET(5,Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 5,Z80_L*/
void op_CB_0xed(void)
{
 SET(5,Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 5,(Z80_HL)*/
void op_CB_0xee(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 SET(5,Z80_Temp8);
 WRITE_BYTE(Z80_HL,Z80_Temp8);
 T_WAIT_UNTIL(11);
 return;
}
 
/*SET 5,Z80_A*/
void op_CB_0xef(void)
{
 SET(5,Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 6,Z80_B*/
void op_CB_0xf0(void)
{
 SET(6,Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 6,Z80_C*/
void op_CB_0xf1(void)
{
 SET(6,Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 6,Z80_D*/
void op_CB_0xf2(void)
{
 SET(6,Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 6,Z80_E*/
void op_CB_0xf3(void)
{
 SET(6,Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 6,Z80_H*/
void op_CB_0xf4(void)
{
 SET(6,Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 6,Z80_L*/
void op_CB_0xf5(void)
{
 SET(6,Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 6,(Z80_HL)*/
void op_CB_0xf6(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 SET(6,Z80_Temp8);
 WRITE_BYTE(Z80_HL,Z80_Temp8);
 T_WAIT_UNTIL(11);
 return;
}
 
/*SET 6,Z80_A*/
void op_CB_0xf7(void)
{
 SET(6,Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 7,Z80_B*/
void op_CB_0xf8(void)
{
 SET(7,Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 7,Z80_C*/
void op_CB_0xf9(void)
{
 SET(7,Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 7,Z80_D*/
void op_CB_0xfa(void)
{
 SET(7,Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 7,Z80_E*/
void op_CB_0xfb(void)
{
 SET(7,Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 7,Z80_H*/
void op_CB_0xfc(void)
{
 SET(7,Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 7,Z80_L*/
void op_CB_0xfd(void)
{
 SET(7,Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SET 7,(Z80_HL)*/
void op_CB_0xfe(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 SET(7,Z80_Temp8);
 WRITE_BYTE(Z80_HL,Z80_Temp8);
 T_WAIT_UNTIL(11);
 return;
}
 
/*SET 7,Z80_A*/
void op_CB_0xff(void)
{
 SET(7,Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
void (*Z80_OpCode_cb[0x100])(void)=
{
 op_CB_0x00,op_CB_0x01,op_CB_0x02,op_CB_0x03,op_CB_0x04,op_CB_0x05,op_CB_0x06,op_CB_0x07,op_CB_0x08,op_CB_0x09,op_CB_0x0a,op_CB_0x0b,op_CB_0x0c,op_CB_0x0d,op_CB_0x0e,op_CB_0x0f,
 op_CB_0x10,op_CB_0x11,op_CB_0x12,op_CB_0x13,op_CB_0x14,op_CB_0x15,op_CB_0x16,op_CB_0x17,op_CB_0x18,op_CB_0x19,op_CB_0x1a,op_CB_0x1b,op_CB_0x1c,op_CB_0x1d,op_CB_0x1e,op_CB_0x1f,
 op_CB_0x20,op_CB_0x21,op_CB_0x22,op_CB_0x23,op_CB_0x24,op_CB_0x25,op_CB_0x26,op_CB_0x27,op_CB_0x28,op_CB_0x29,op_CB_0x2a,op_CB_0x2b,op_CB_0x2c,op_CB_0x2d,op_CB_0x2e,op_CB_0x2f,
 op_CB_0x30,op_CB_0x31,op_CB_0x32,op_CB_0x33,op_CB_0x34,op_CB_0x35,op_CB_0x36,op_CB_0x37,op_CB_0x38,op_CB_0x39,op_CB_0x3a,op_CB_0x3b,op_CB_0x3c,op_CB_0x3d,op_CB_0x3e,op_CB_0x3f,
 op_CB_0x40,op_CB_0x41,op_CB_0x42,op_CB_0x43,op_CB_0x44,op_CB_0x45,op_CB_0x46,op_CB_0x47,op_CB_0x48,op_CB_0x49,op_CB_0x4a,op_CB_0x4b,op_CB_0x4c,op_CB_0x4d,op_CB_0x4e,op_CB_0x4f,
 op_CB_0x50,op_CB_0x51,op_CB_0x52,op_CB_0x53,op_CB_0x54,op_CB_0x55,op_CB_0x56,op_CB_0x57,op_CB_0x58,op_CB_0x59,op_CB_0x5a,op_CB_0x5b,op_CB_0x5c,op_CB_0x5d,op_CB_0x5e,op_CB_0x5f,
 op_CB_0x60,op_CB_0x61,op_CB_0x62,op_CB_0x63,op_CB_0x64,op_CB_0x65,op_CB_0x66,op_CB_0x67,op_CB_0x68,op_CB_0x69,op_CB_0x6a,op_CB_0x6b,op_CB_0x6c,op_CB_0x6d,op_CB_0x6e,op_CB_0x6f,
 op_CB_0x70,op_CB_0x71,op_CB_0x72,op_CB_0x73,op_CB_0x74,op_CB_0x75,op_CB_0x76,op_CB_0x77,op_CB_0x78,op_CB_0x79,op_CB_0x7a,op_CB_0x7b,op_CB_0x7c,op_CB_0x7d,op_CB_0x7e,op_CB_0x7f,
 op_CB_0x80,op_CB_0x81,op_CB_0x82,op_CB_0x83,op_CB_0x84,op_CB_0x85,op_CB_0x86,op_CB_0x87,op_CB_0x88,op_CB_0x89,op_CB_0x8a,op_CB_0x8b,op_CB_0x8c,op_CB_0x8d,op_CB_0x8e,op_CB_0x8f,
 op_CB_0x90,op_CB_0x91,op_CB_0x92,op_CB_0x93,op_CB_0x94,op_CB_0x95,op_CB_0x96,op_CB_0x97,op_CB_0x98,op_CB_0x99,op_CB_0x9a,op_CB_0x9b,op_CB_0x9c,op_CB_0x9d,op_CB_0x9e,op_CB_0x9f,
 op_CB_0xa0,op_CB_0xa1,op_CB_0xa2,op_CB_0xa3,op_CB_0xa4,op_CB_0xa5,op_CB_0xa6,op_CB_0xa7,op_CB_0xa8,op_CB_0xa9,op_CB_0xaa,op_CB_0xab,op_CB_0xac,op_CB_0xad,op_CB_0xae,op_CB_0xaf,
 op_CB_0xb0,op_CB_0xb1,op_CB_0xb2,op_CB_0xb3,op_CB_0xb4,op_CB_0xb5,op_CB_0xb6,op_CB_0xb7,op_CB_0xb8,op_CB_0xb9,op_CB_0xba,op_CB_0xbb,op_CB_0xbc,op_CB_0xbd,op_CB_0xbe,op_CB_0xbf,
 op_CB_0xc0,op_CB_0xc1,op_CB_0xc2,op_CB_0xc3,op_CB_0xc4,op_CB_0xc5,op_CB_0xc6,op_CB_0xc7,op_CB_0xc8,op_CB_0xc9,op_CB_0xca,op_CB_0xcb,op_CB_0xcc,op_CB_0xcd,op_CB_0xce,op_CB_0xcf,
 op_CB_0xd0,op_CB_0xd1,op_CB_0xd2,op_CB_0xd3,op_CB_0xd4,op_CB_0xd5,op_CB_0xd6,op_CB_0xd7,op_CB_0xd8,op_CB_0xd9,op_CB_0xda,op_CB_0xdb,op_CB_0xdc,op_CB_0xdd,op_CB_0xde,op_CB_0xdf,
 op_CB_0xe0,op_CB_0xe1,op_CB_0xe2,op_CB_0xe3,op_CB_0xe4,op_CB_0xe5,op_CB_0xe6,op_CB_0xe7,op_CB_0xe8,op_CB_0xe9,op_CB_0xea,op_CB_0xeb,op_CB_0xec,op_CB_0xed,op_CB_0xee,op_CB_0xef,
 op_CB_0xf0,op_CB_0xf1,op_CB_0xf2,op_CB_0xf3,op_CB_0xf4,op_CB_0xf5,op_CB_0xf6,op_CB_0xf7,op_CB_0xf8,op_CB_0xf9,op_CB_0xfa,op_CB_0xfb,op_CB_0xfc,op_CB_0xfd,op_CB_0xfe,op_CB_0xff
};
