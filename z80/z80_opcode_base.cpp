#include "Z80_OpCode_base.h"
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

/*NOP*/
void op_0x00(void)
{
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_BC,@*/
void op_0x01(void)
{
 unsigned short nn=NEXT_WORD();
 LD16(Z80_BC,nn);
 T_WAIT_UNTIL(10);
 return;
}
 
/*LD (Z80_BC),Z80_A*/
void op_0x02(void)
{
 LD_A_TO_ADDR_MPTR(Z80_Temp8,Z80_A,(Z80_BC));
 WRITE_BYTE((Z80_BC),Z80_Temp8);
 T_WAIT_UNTIL(7);
 return;
}
 
/*INC Z80_BC*/
void op_0x03(void)
{
 INC16(Z80_BC);
 T_WAIT_UNTIL(6);
 return;
}
 
/*INC Z80_B*/
void op_0x04(void)
{
 INC(Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*DEC Z80_B*/
void op_0x05(void)
{
 DEC(Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_B,#*/
void op_0x06(void)
{
 unsigned char n=NEXT_BYTE();
 LD(Z80_B,n);
 T_WAIT_UNTIL(7);
 return;
}
 
/*RLCA*/
void op_0x07(void)
{
 RLCA();
 T_WAIT_UNTIL(4);
 return;
}
 
/*EX Z80_AF,Z80_AF'*/
void op_0x08(void)
{
 EX(Z80_AF,Z80_AF_);
 T_WAIT_UNTIL(4);
 return;
}
 
/*ADD Z80_HL,Z80_BC*/
void op_0x09(void)
{
 ADD16(Z80_HL,Z80_BC);
 T_WAIT_UNTIL(11);
 return;
}
 
/*LD Z80_A,(Z80_BC)*/
void op_0x0a(void)
{
 Z80_Temp8=READ_BYTE(Z80_BC);
 LD_A_FROM_ADDR_MPTR(Z80_A,Z80_Temp8,Z80_BC);
 T_WAIT_UNTIL(7);
 return;
}
 
/*DEC Z80_BC*/
void op_0x0b(void)
{
 DEC16(Z80_BC);
 T_WAIT_UNTIL(6);
 return;
}
 
/*INC Z80_C*/
void op_0x0c(void)
{
 INC(Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*DEC Z80_C*/
void op_0x0d(void)
{
 DEC(Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_C,#*/
void op_0x0e(void)
{
 unsigned char n=NEXT_BYTE();
 LD(Z80_C,n);
 T_WAIT_UNTIL(7);
 return;
}
 
/*RRCA*/
void op_0x0f(void)
{
 RRCA();
 T_WAIT_UNTIL(4);
 return;
}
 
/*DJNZ %*/
void op_0x10(void)
{
 uZ80_SU.u=NEXT_BYTE();
 Z80_B--;
 if(Z80_B)
 {
  JR(uZ80_SU.s);
  T_WAIT_UNTIL(13);
 }
 else
 {
  T_WAIT_UNTIL(8);
 }
 return;
}
 
/*LD Z80_DE,@*/
void op_0x11(void)
{
 unsigned short nn=NEXT_WORD();
 LD16(Z80_DE,nn);
 T_WAIT_UNTIL(10);
 return;
}
 
/*LD (Z80_DE),Z80_A*/
void op_0x12(void)
{
 LD_A_TO_ADDR_MPTR(Z80_Temp8,Z80_A,Z80_DE);
 WRITE_BYTE(Z80_DE,Z80_Temp8);
 T_WAIT_UNTIL(7);
 return;
}
 
/*INC Z80_DE*/
void op_0x13(void)
{
 INC16(Z80_DE);
 T_WAIT_UNTIL(6);
 return;
}
 
/*INC Z80_D*/
void op_0x14(void)
{
 INC(Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*DEC Z80_D*/
void op_0x15(void)
{
 DEC(Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_D,#*/
void op_0x16(void)
{
 unsigned char n=NEXT_BYTE();
 LD(Z80_D,n);
 T_WAIT_UNTIL(7);
 return;
}
 
/*RLA*/
void op_0x17(void)
{
 RLA();
 T_WAIT_UNTIL(4);
 return;
}
 
/*JR %*/
void op_0x18(void)
{
 uZ80_SU.u=NEXT_BYTE();
 JR(uZ80_SU.s);
 T_WAIT_UNTIL(12);
 return;
}
 
/*ADD Z80_HL,Z80_DE*/
void op_0x19(void)
{
 ADD16(Z80_HL,Z80_DE);
 T_WAIT_UNTIL(11);
 return;
}
 
/*LD Z80_A,(Z80_DE)*/
void op_0x1a(void)
{
 Z80_Temp8=READ_BYTE(Z80_DE);
 LD_A_FROM_ADDR_MPTR(Z80_A,Z80_Temp8,Z80_DE);
 T_WAIT_UNTIL(7);
 return;
}
 
/*DEC Z80_DE*/
void op_0x1b(void)
{
 DEC16(Z80_DE);
 T_WAIT_UNTIL(6);
 return;
}
 
/*INC Z80_E*/
void op_0x1c(void)
{
 INC(Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*DEC Z80_E*/
void op_0x1d(void)
{
 DEC(Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_E,#*/
void op_0x1e(void)
{
 unsigned char n=NEXT_BYTE();
 LD(Z80_E,n);
 T_WAIT_UNTIL(7);
 return;
}
 
/*RRA*/
void op_0x1f(void)
{
 RRA();
 T_WAIT_UNTIL(4);
 return;
}
 
/*JR NZ,%*/
void op_0x20(void)
{
 uZ80_SU.u=NEXT_BYTE();
 if(!(Z80_F&Z80_FLAG_Z))
 {
  JR(uZ80_SU.s);
  T_WAIT_UNTIL(12);
 }
 else
 {
  T_WAIT_UNTIL(7);
 }
 return;
}
 
/*LD Z80_HL,@*/
void op_0x21(void)
{
 unsigned short nn=NEXT_WORD();
 LD16(Z80_HL,nn);
 T_WAIT_UNTIL(10);
 return;
}
 
/*LD (@),Z80_HL*/
void op_0x22(void)
{
 unsigned short nn=NEXT_WORD();
 LD_RP_TO_ADDR_MPTR_16(Z80_Temp16,Z80_HL,nn);
 WRITE_WORD(nn,Z80_Temp16);
 T_WAIT_UNTIL(16);
 return;
}
 
/*INC Z80_HL*/
void op_0x23(void)
{
 INC16(Z80_HL);
 T_WAIT_UNTIL(6);
 return;
}
 
/*INC Z80_H*/
void op_0x24(void)
{
 INC(Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*DEC Z80_H*/
void op_0x25(void)
{
 DEC(Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_H,#*/
void op_0x26(void)
{
 unsigned char n=NEXT_BYTE();
 LD(Z80_H,n);
 T_WAIT_UNTIL(7);
 return;
}
 
/*DAA*/
void op_0x27(void)
{
 DAA();
 T_WAIT_UNTIL(4);
 return;
}
 
/*JR Z,%*/
void op_0x28(void)
{
 uZ80_SU.u=NEXT_BYTE();
 if(Z80_F&Z80_FLAG_Z)
 {
  JR(uZ80_SU.s);
  T_WAIT_UNTIL(12);
 }
 else
 {
  T_WAIT_UNTIL(7);
 }
 return;
}
 
/*ADD Z80_HL,Z80_HL*/
void op_0x29(void)
{
 ADD16(Z80_HL,Z80_HL);
 T_WAIT_UNTIL(11);
 return;
}
 
/*LD Z80_HL,(@)*/
void op_0x2a(void)
{
 unsigned short nn=NEXT_WORD();
 Z80_Temp16=READ_WORD(nn);
 LD_RP_FROM_ADDR_MPTR_16(Z80_HL,Z80_Temp16,nn);
 T_WAIT_UNTIL(16);
 return;
}
 
/*DEC Z80_HL*/
void op_0x2b(void)
{
 DEC16(Z80_HL);
 T_WAIT_UNTIL(6);
 return;
}
 
/*INC Z80_L*/
void op_0x2c(void)
{
 INC(Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*DEC Z80_L*/
void op_0x2d(void)
{
 DEC(Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_L,#*/
void op_0x2e(void)
{
 unsigned char n=NEXT_BYTE();
 LD(Z80_L,n);
 T_WAIT_UNTIL(7);
 return;
}
 
/*CPL*/
void op_0x2f(void)
{
 CPL();
 T_WAIT_UNTIL(4);
 return;
}
 
/*JR NC,%*/
void op_0x30(void)
{
 uZ80_SU.u=NEXT_BYTE();
 if(!(Z80_F&Z80_FLAG_C))
 {
  JR(uZ80_SU.s);
  T_WAIT_UNTIL(12);
 }
 else
 {
  T_WAIT_UNTIL(7);
 }
 return;
}
 
/*LD Z80_SP,@*/
void op_0x31(void)
{
 unsigned short nn=NEXT_WORD();
 LD16(Z80_SP,nn);
 T_WAIT_UNTIL(10);
 return;
}
 
/*LD (@),Z80_A*/
void op_0x32(void)
{
 unsigned short nn=NEXT_WORD();
 LD_A_TO_ADDR_MPTR(Z80_Temp8,Z80_A,nn);
 WRITE_BYTE(nn,Z80_Temp8);
 T_WAIT_UNTIL(13);
 return;
}
 
/*INC Z80_SP*/
void op_0x33(void)
{
 INC16(Z80_SP);
 T_WAIT_UNTIL(6);
 return;
}
 
/*INC (Z80_HL)*/
void op_0x34(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 INC(Z80_Temp8);
 WRITE_BYTE(Z80_HL,Z80_Temp8);
 T_WAIT_UNTIL(11);
 return;
}
 
/*DEC (Z80_HL)*/
void op_0x35(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 DEC(Z80_Temp8);
 WRITE_BYTE(Z80_HL,Z80_Temp8);
 T_WAIT_UNTIL(11);
 return;
}
 
/*LD (Z80_HL),#*/
void op_0x36(void)
{
 unsigned char n=NEXT_BYTE();
 LD(n,n);
 WRITE_BYTE(Z80_HL,n);
 T_WAIT_UNTIL(10);
 return;
}
 
/*SCF*/
void op_0x37(void)
{
 SCF();
 T_WAIT_UNTIL(4);
 return;
}
 
/*JR Z80_C,%*/
void op_0x38(void)
{
 uZ80_SU.u=NEXT_BYTE();
 if(Z80_F&Z80_FLAG_C)
 {
  JR(uZ80_SU.s);
  T_WAIT_UNTIL(12);
 }
 else
 {
  T_WAIT_UNTIL(7);
 }
 return;
}
 
/*ADD Z80_HL,Z80_SP*/
void op_0x39(void)
{
 ADD16(Z80_HL,Z80_SP);
 T_WAIT_UNTIL(11);
 return;
}
 
/*LD Z80_A,(@)*/
void op_0x3a(void)
{
 unsigned short nn=NEXT_WORD();
 Z80_Temp8=READ_BYTE(nn);
 LD_A_FROM_ADDR_MPTR(Z80_A,Z80_Temp8,nn);
 T_WAIT_UNTIL(13);
 return;
}
 
/*DEC Z80_SP*/
void op_0x3b(void)
{
 DEC16(Z80_SP);
 T_WAIT_UNTIL(6);
 return;
}
 
/*INC Z80_A*/
void op_0x3c(void)
{
 INC(Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*DEC Z80_A*/
void op_0x3d(void)
{
 DEC(Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_A,#*/
void op_0x3e(void)
{
 unsigned char n=NEXT_BYTE();
 LD(Z80_A,n);
 T_WAIT_UNTIL(7);
 return;
}
 
/*CCF*/
void op_0x3f(void)
{
 CCF();
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_B,Z80_B*/
void op_0x40(void)
{
 LD(Z80_B,Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_B,Z80_C*/
void op_0x41(void)
{
 LD(Z80_B,Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_B,Z80_D*/
void op_0x42(void)
{
 LD(Z80_B,Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_B,Z80_E*/
void op_0x43(void)
{
 LD(Z80_B,Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_B,Z80_H*/
void op_0x44(void)
{
 LD(Z80_B,Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_B,Z80_L*/
void op_0x45(void)
{
 LD(Z80_B,Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_B,(Z80_HL)*/
void op_0x46(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 LD(Z80_B,Z80_Temp8);
 T_WAIT_UNTIL(7);
 return;
}
 
/*LD Z80_B,Z80_A*/
void op_0x47(void)
{
 LD(Z80_B,Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_C,Z80_B*/
void op_0x48(void)
{
 LD(Z80_C,Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_C,Z80_C*/
void op_0x49(void)
{
 LD(Z80_C,Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_C,Z80_D*/
void op_0x4a(void)
{
 LD(Z80_C,Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_C,Z80_E*/
void op_0x4b(void)
{
 LD(Z80_C,Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_C,Z80_H*/
void op_0x4c(void)
{
 LD(Z80_C,Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_C,Z80_L*/
void op_0x4d(void)
{
 LD(Z80_C,Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_C,(Z80_HL)*/
void op_0x4e(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 LD(Z80_C,Z80_Temp8);
 T_WAIT_UNTIL(7);
 return;
}
 
/*LD Z80_C,Z80_A*/
void op_0x4f(void)
{
 LD(Z80_C,Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_D,Z80_B*/
void op_0x50(void)
{
 LD(Z80_D,Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_D,Z80_C*/
void op_0x51(void)
{
 LD(Z80_D,Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_D,Z80_D*/
void op_0x52(void)
{
 LD(Z80_D,Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_D,Z80_E*/
void op_0x53(void)
{
 LD(Z80_D,Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_D,Z80_H*/
void op_0x54(void)
{
 LD(Z80_D,Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_D,Z80_L*/
void op_0x55(void)
{
 LD(Z80_D,Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_D,(Z80_HL)*/
void op_0x56(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 LD(Z80_D,Z80_Temp8);
 T_WAIT_UNTIL(7);
 return;
}
 
/*LD Z80_D,Z80_A*/
void op_0x57(void)
{
 LD(Z80_D,Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_E,Z80_B*/
void op_0x58(void)
{
 LD(Z80_E,Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_E,Z80_C*/
void op_0x59(void)
{
 LD(Z80_E,Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_E,Z80_D*/
void op_0x5a(void)
{
 LD(Z80_E,Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_E,Z80_E*/
void op_0x5b(void)
{
 LD(Z80_E,Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_E,Z80_H*/
void op_0x5c(void)
{
 LD(Z80_E,Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_E,Z80_L*/
void op_0x5d(void)
{
 LD(Z80_E,Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_E,(Z80_HL)*/
void op_0x5e(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 LD(Z80_E,Z80_Temp8);
 T_WAIT_UNTIL(7);
 return;
}
 
/*LD Z80_E,Z80_A*/
void op_0x5f(void)
{
 LD(Z80_E,Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_H,Z80_B*/
void op_0x60(void)
{
 LD(Z80_H,Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_H,Z80_C*/
void op_0x61(void)
{
 LD(Z80_H,Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_H,Z80_D*/
void op_0x62(void)
{
 LD(Z80_H,Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_H,Z80_E*/
void op_0x63(void)
{
 LD(Z80_H,Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_H,Z80_H*/
void op_0x64(void)
{
 LD(Z80_H,Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_H,Z80_L*/
void op_0x65(void)
{
 LD(Z80_H,Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_H,(Z80_HL)*/
void op_0x66(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 LD(Z80_H,Z80_Temp8);
 T_WAIT_UNTIL(7);
 return;
}
 
/*LD Z80_H,Z80_A*/
void op_0x67(void)
{
 LD(Z80_H,Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_L,Z80_B*/
void op_0x68(void)
{
 LD(Z80_L,Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_L,Z80_C*/
void op_0x69(void)
{
 LD(Z80_L,Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_L,Z80_D*/
void op_0x6a(void)
{
 LD(Z80_L,Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_L,Z80_E*/
void op_0x6b(void)
{
 LD(Z80_L,Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_L,Z80_H*/
void op_0x6c(void)
{
 LD(Z80_L,Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_L,Z80_L*/
void op_0x6d(void)
{
 LD(Z80_L,Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_L,(Z80_HL)*/
void op_0x6e(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 LD(Z80_L,Z80_Temp8);
 T_WAIT_UNTIL(7);
 return;
}
 
/*LD Z80_L,Z80_A*/
void op_0x6f(void)
{
 LD(Z80_L,Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD (Z80_HL),Z80_B*/
void op_0x70(void)
{
 LD(Z80_Temp8,Z80_B);
 WRITE_BYTE((Z80_HL),Z80_Temp8);
 T_WAIT_UNTIL(7);
 return;
}
 
/*LD (Z80_HL),Z80_C*/
void op_0x71(void)
{
 LD(Z80_Temp8,Z80_C);
 WRITE_BYTE(Z80_HL,Z80_Temp8);
 T_WAIT_UNTIL(7);
 return;
}
 
/*LD (Z80_HL),Z80_D*/
void op_0x72(void)
{
 LD(Z80_Temp8,Z80_D);
 WRITE_BYTE(Z80_HL,Z80_Temp8);
 T_WAIT_UNTIL(7);
 return;
}
 
/*LD (Z80_HL),Z80_E*/
void op_0x73(void)
{
 LD(Z80_Temp8,Z80_E);
 WRITE_BYTE(Z80_HL,Z80_Temp8);
 T_WAIT_UNTIL(7);
 return;
}
 
/*LD (Z80_HL),Z80_H*/
void op_0x74(void)
{
 LD(Z80_Temp8,Z80_H);
 WRITE_BYTE(Z80_HL,Z80_Temp8);
 T_WAIT_UNTIL(7);
 return;
}
 
/*LD (Z80_HL),Z80_L*/
void op_0x75(void)
{
 LD(Z80_Temp8,Z80_L);
 WRITE_BYTE(Z80_HL,Z80_Temp8);
 T_WAIT_UNTIL(7);
 return;
}
 
/*HALT*/
void op_0x76(void)
{
 HALT();
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD (Z80_HL),Z80_A*/
void op_0x77(void)
{
 LD(Z80_Temp8,Z80_A);
 WRITE_BYTE(Z80_HL,Z80_Temp8);
 T_WAIT_UNTIL(7);
 return;
}
 
/*LD Z80_A,Z80_B*/
void op_0x78(void)
{
 LD(Z80_A,Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_A,Z80_C*/
void op_0x79(void)
{
 LD(Z80_A,Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_A,Z80_D*/
void op_0x7a(void)
{
 LD(Z80_A,Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_A,Z80_E*/
void op_0x7b(void)
{
 LD(Z80_A,Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_A,Z80_H*/
void op_0x7c(void)
{
 LD(Z80_A,Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_A,Z80_L*/
void op_0x7d(void)
{
 LD(Z80_A,Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_A,(Z80_HL)*/
void op_0x7e(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 LD(Z80_A,Z80_Temp8);
 T_WAIT_UNTIL(7);
 return;
}
 
/*LD Z80_A,Z80_A*/
void op_0x7f(void)
{
 LD(Z80_A,Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*ADD Z80_A,Z80_B*/
void op_0x80(void)
{
 ADD(Z80_A,Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*ADD Z80_A,Z80_C*/
void op_0x81(void)
{
 ADD(Z80_A,Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*ADD Z80_A,Z80_D*/
void op_0x82(void)
{
 ADD(Z80_A,Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*ADD Z80_A,Z80_E*/
void op_0x83(void)
{
 ADD(Z80_A,Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*ADD Z80_A,Z80_H*/
void op_0x84(void)
{
 ADD(Z80_A,Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*ADD Z80_A,Z80_L*/
void op_0x85(void)
{
 ADD(Z80_A,Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*ADD Z80_A,(Z80_HL)*/
void op_0x86(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 ADD(Z80_A,Z80_Temp8);
 T_WAIT_UNTIL(7);
 return;
}
 
/*ADD Z80_A,Z80_A*/
void op_0x87(void)
{
 ADD(Z80_A,Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*ADDC Z80_A,Z80_B*/
void op_0x88(void)
{
 ADDC(Z80_A,Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*ADDC Z80_A,Z80_C*/
void op_0x89(void)
{
 ADDC(Z80_A,Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*ADDC Z80_A,Z80_D*/
void op_0x8a(void)
{
 ADDC(Z80_A,Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*ADDC Z80_A,Z80_E*/
void op_0x8b(void)
{
 ADDC(Z80_A,Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*ADDC Z80_A,Z80_H*/
void op_0x8c(void)
{
 ADDC(Z80_A,Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*ADDC Z80_A,Z80_L*/
void op_0x8d(void)
{
 ADDC(Z80_A,Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*ADDC Z80_A,(Z80_HL)*/
void op_0x8e(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 ADDC(Z80_A,Z80_Temp8);
 T_WAIT_UNTIL(7);
 return;
}
 
/*ADDC Z80_A,Z80_A*/
void op_0x8f(void)
{
 ADDC(Z80_A,Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SUB Z80_B*/
void op_0x90(void)
{
 SUB(Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SUB Z80_C*/
void op_0x91(void)
{
 SUB(Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SUB Z80_D*/
void op_0x92(void)
{
 SUB(Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SUB Z80_E*/
void op_0x93(void)
{
 SUB(Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SUB Z80_H*/
void op_0x94(void)
{
 SUB(Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SUB Z80_L*/
void op_0x95(void)
{
 SUB(Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SUB (Z80_HL)*/
void op_0x96(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 SUB(Z80_Temp8);
 T_WAIT_UNTIL(7);
 return;
}
 
/*SUB Z80_A*/
void op_0x97(void)
{
 SUB(Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SUBC Z80_A,Z80_B*/
void op_0x98(void)
{
 SUBC(Z80_A,Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SUBC Z80_A,Z80_C*/
void op_0x99(void)
{
 SUBC(Z80_A,Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SUBC Z80_A,Z80_D*/
void op_0x9a(void)
{
 SUBC(Z80_A,Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SUBC Z80_A,Z80_E*/
void op_0x9b(void)
{
 SUBC(Z80_A,Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SUBC Z80_A,Z80_H*/
void op_0x9c(void)
{
 SUBC(Z80_A,Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SUBC Z80_A,Z80_L*/
void op_0x9d(void)
{
 SUBC(Z80_A,Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SUBC Z80_A,(Z80_HL)*/
void op_0x9e(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 SUBC(Z80_A,Z80_Temp8);
 T_WAIT_UNTIL(7);
 return;
}
 
/*SUBC Z80_A,Z80_A*/
void op_0x9f(void)
{
 SUBC(Z80_A,Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*AND Z80_B*/
void op_0xa0(void)
{
 AND(Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*AND Z80_C*/
void op_0xa1(void)
{
 AND(Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*AND Z80_D*/
void op_0xa2(void)
{
 AND(Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*AND Z80_E*/
void op_0xa3(void)
{
 AND(Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*AND Z80_H*/
void op_0xa4(void)
{
 AND(Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*AND Z80_L*/
void op_0xa5(void)
{
 AND(Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*AND (Z80_HL)*/
void op_0xa6(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 AND(Z80_Temp8);
 T_WAIT_UNTIL(7);
 return;
}
 
/*AND Z80_A*/
void op_0xa7(void)
{
 AND(Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*XOR Z80_B*/
void op_0xa8(void)
{
 XOR(Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*XOR Z80_C*/
void op_0xa9(void)
{
 XOR(Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*XOR Z80_D*/
void op_0xaa(void)
{
 XOR(Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*XOR Z80_E*/
void op_0xab(void)
{
 XOR(Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*XOR Z80_H*/
void op_0xac(void)
{
 XOR(Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*XOR Z80_L*/
void op_0xad(void)
{
 XOR(Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*XOR (Z80_HL)*/
void op_0xae(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 XOR(Z80_Temp8);
 T_WAIT_UNTIL(7);
 return;
}
 
/*XOR Z80_A*/
void op_0xaf(void)
{
 XOR(Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*OR Z80_B*/
void op_0xb0(void)
{
 OR(Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*OR Z80_C*/
void op_0xb1(void)
{
 OR(Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*OR Z80_D*/
void op_0xb2(void)
{
 OR(Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*OR Z80_E*/
void op_0xb3(void)
{
 OR(Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*OR Z80_H*/
void op_0xb4(void)
{
 OR(Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*OR Z80_L*/
void op_0xb5(void)
{
 OR(Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*OR (Z80_HL)*/
void op_0xb6(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 OR(Z80_Temp8);
 T_WAIT_UNTIL(7);
 return;
}
 
/*OR Z80_A*/
void op_0xb7(void)
{
 OR(Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*CP Z80_B*/
void op_0xb8(void)
{
 CP(Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*CP Z80_C*/
void op_0xb9(void)
{
 CP(Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*CP Z80_D*/
void op_0xba(void)
{
 CP(Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*CP Z80_E*/
void op_0xbb(void)
{
 CP(Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*CP Z80_H*/
void op_0xbc(void)
{
 CP(Z80_H);
 T_WAIT_UNTIL(4);
 return;
}
 
/*CP Z80_L*/
void op_0xbd(void)
{
 CP(Z80_L);
 T_WAIT_UNTIL(4);
 return;
}
 
/*CP (Z80_HL)*/
void op_0xbe(void)
{
 Z80_Temp8=READ_BYTE(Z80_HL);
 CP(Z80_Temp8);
 T_WAIT_UNTIL(7);
 return;
}
 
/*CP Z80_A*/
void op_0xbf(void)
{
 CP(Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RET NZ*/
void op_0xc0(void)
{
 if(!(Z80_F&Z80_FLAG_Z))
 {
  RET();
  T_WAIT_UNTIL(11);
 }
 else 
 {
  T_WAIT_UNTIL(5);
 }
 return;
}
 
/*POP Z80_BC*/
void op_0xc1(void)
{
 POP(Z80_BC);
 T_WAIT_UNTIL(10);
 return;
}
 
/*JP NZ,@*/
void op_0xc2(void)
{
 unsigned short nn=NEXT_WORD();
 if(!(Z80_F&Z80_FLAG_Z))
 {
  JP(nn);
  T_WAIT_UNTIL(10);
 }
 else
 {
  Z80_MEMPTR=nn;
  T_WAIT_UNTIL(10);
 }
 return;
}
 
/*JP @*/
void op_0xc3(void)
{
 unsigned short nn=NEXT_WORD();
 JP(nn);
 T_WAIT_UNTIL(10);
 return;
}
 
/*CALL NZ,@*/
void op_0xc4(void)
{
 unsigned short nn=NEXT_WORD();
 if(!(Z80_F&Z80_FLAG_Z))
 {
  CALL(nn);
  T_WAIT_UNTIL(17);
 }
 else
 {
  Z80_MEMPTR=nn;
  T_WAIT_UNTIL(10);
 }
 return;
}
 
/*PUSH Z80_BC*/
void op_0xc5(void)
{
 PUSH(Z80_BC);
 T_WAIT_UNTIL(11);
 return;
}
 
/*ADD Z80_A,#*/
void op_0xc6(void)
{
 unsigned char n=NEXT_BYTE();
 ADD(Z80_A,n);
 T_WAIT_UNTIL(7);
 return;
}
 
/*RST 0x00*/
void op_0xc7(void)
{
 RST(0x00);
 T_WAIT_UNTIL(11);
 return;
}
 
/*RET Z*/
void op_0xc8(void)
{
 if(Z80_F&Z80_FLAG_Z)
 {
  RET();
  T_WAIT_UNTIL(11);
 }
 else 
 {
  T_WAIT_UNTIL(5);
 }
 return;
}
 
/*RET*/
void op_0xc9(void)
{
 RET();
 T_WAIT_UNTIL(10);
 return;
}
 
/*JP Z,@*/
void op_0xca(void)
{
 unsigned short nn=NEXT_WORD();
 if(Z80_F&Z80_FLAG_Z)
 {
  JP(nn);
  T_WAIT_UNTIL(10);
 }
 else
 {
  Z80_MEMPTR=nn;
  T_WAIT_UNTIL(10);
 }
 return;
}
 
void op_0xcb(void)
{
 Z80_Prefix=0xCB;
 Z80_NoInterrupt=1;
 return;
}
 
/*CALL Z,@*/
void op_0xcc(void)
{
 unsigned short nn=NEXT_WORD();
 if(Z80_F&Z80_FLAG_Z)
 {
  CALL(nn);
  T_WAIT_UNTIL(17);
 }
 else
 {
  Z80_MEMPTR=nn;
  T_WAIT_UNTIL(10);
 }
 return;
}
 
/*CALL @*/
void op_0xcd(void)
{
 unsigned short nn=NEXT_WORD();
 CALL(nn);
 T_WAIT_UNTIL(17);
 return;
}
 
/*ADDC Z80_A,#*/
void op_0xce(void)
{
 unsigned char n=NEXT_BYTE();
 ADDC(Z80_A,n);
 T_WAIT_UNTIL(7);
 return;
}
 
/*RST 0x08*/
void op_0xcf(void)
{
 RST(0x08);
 T_WAIT_UNTIL(11);
 return;
}
 
/*RET NC*/
void op_0xd0(void)
{
 if(!(Z80_F&Z80_FLAG_C))
 {
  RET();
  T_WAIT_UNTIL(11);
 }
 else 
 {
  T_WAIT_UNTIL(5);
 }
 return;
}
 
/*POP Z80_DE*/
void op_0xd1(void)
{
 POP(Z80_DE);
 T_WAIT_UNTIL(10);
 return;
}
 
/*JP NC,@*/
void op_0xd2(void)
{
 unsigned short nn=NEXT_WORD();
 if(!(Z80_F&Z80_FLAG_C))
 {
  JP(nn);
  T_WAIT_UNTIL(10);
 }
 else
 {
  Z80_MEMPTR=nn;
  T_WAIT_UNTIL(10);
 }
 return;
}
 
/*OUT (#),Z80_A*/
void op_0xd3(void)
{
 unsigned char n=NEXT_BYTE();
 Z80_Temp16=(n+(Z80_A<<8));
 OUT_A(Z80_Temp16,Z80_A);
 T_WAIT_UNTIL(11);
 return;
}
 
/*CALL NC,@*/
void op_0xd4(void)
{
 unsigned short nn=NEXT_WORD();
 if(!(Z80_F&Z80_FLAG_C))
 {
  CALL(nn);
  T_WAIT_UNTIL(17);
 }
 else
 {
  Z80_MEMPTR=nn;
  T_WAIT_UNTIL(10);
 }
 return;
}
 
/*PUSH Z80_DE*/
void op_0xd5(void)
{
 PUSH(Z80_DE);
 T_WAIT_UNTIL(11);
 return;
}
 
/*SUB #*/
void op_0xd6(void)
{
 unsigned char n=NEXT_BYTE();
 SUB(n);
 T_WAIT_UNTIL(7);
 return;
}
 
/*RST 0x10*/
void op_0xd7(void)
{
 RST(0x10);
 T_WAIT_UNTIL(11);
 return;
}
 
/*RET Z80_C*/
void op_0xd8(void)
{
 if(Z80_F&Z80_FLAG_C)
 {
  RET();
  T_WAIT_UNTIL(11);
 }
 else 
 {
  T_WAIT_UNTIL(5);
 }
 return;
}
 
/*EXX*/
void op_0xd9(void)
{
 EXX();
 T_WAIT_UNTIL(4);
 return;
}
 
/*JP Z80_C,@*/
void op_0xda(void)
{
 unsigned short nn=NEXT_WORD();
 if(Z80_F&Z80_FLAG_C)
 {
  JP(nn);
  T_WAIT_UNTIL(10);
 }
 else
 {
  Z80_MEMPTR=nn;
  T_WAIT_UNTIL(10);
 }
 return;
}
 
/*IN Z80_A,(#)*/
void op_0xdb(void)
{
 unsigned char n=NEXT_BYTE();
 Z80_Temp16=(n+(Z80_A<<8));
 IN_A(Z80_A,Z80_Temp16);
 T_WAIT_UNTIL(11);
 return;
}
 
/*CALL Z80_C,@*/
void op_0xdc(void)
{
 unsigned short nn=NEXT_WORD();
 if(Z80_F&Z80_FLAG_C)
 {
  CALL(nn);
  T_WAIT_UNTIL(17);
 }
 else
 {
  Z80_MEMPTR=nn;
  T_WAIT_UNTIL(10);
 }
 return;
}
 
void op_0xdd(void)
{
 Z80_Prefix=0xDD;
 Z80_NoInterrupt=1;
 return;
}
 
/*SUBC Z80_A,#*/
void op_0xde(void)
{
 unsigned char n=NEXT_BYTE();
 SUBC(Z80_A,n);
 T_WAIT_UNTIL(7);
 return;
}
 
/*RST 0x18*/
void op_0xdf(void)
{
 RST(0x18);
 T_WAIT_UNTIL(11);
 return;
}
 
/*RET PO*/
void op_0xe0(void)
{
 if(!(Z80_F&Z80_FLAG_P))
 {
  RET();
  T_WAIT_UNTIL(11);
 }
 else 
 {
  T_WAIT_UNTIL(5);
 }
 return;
}
 
/*POP Z80_HL*/
void op_0xe1(void)
{
 POP(Z80_HL);
 T_WAIT_UNTIL(10);
 return;
}
 
/*JP PO,@*/
void op_0xe2(void)
{
 unsigned short nn=NEXT_WORD();
 if(!(Z80_F&Z80_FLAG_P))
 {
  JP(nn);
  T_WAIT_UNTIL(10);
 }
 else
 {
  Z80_MEMPTR=nn;
  T_WAIT_UNTIL(10);
 }
 return;
}
 
/*EX (Z80_SP),Z80_HL*/
void op_0xe3(void)
{
 Z80_Temp16=READ_WORD(Z80_SP);
 EX_MPTR(Z80_Temp16,Z80_HL);
 WRITE_WORD((Z80_SP),Z80_Temp16);
 T_WAIT_UNTIL(19);
 return;
}
 
/*CALL PO,@*/
void op_0xe4(void)
{
 unsigned short nn=NEXT_WORD();
 if(!(Z80_F&Z80_FLAG_P))
 {
  CALL(nn);
  T_WAIT_UNTIL(17);
 }
 else
 {
  Z80_MEMPTR=nn;
  T_WAIT_UNTIL(10);
 }
 return;
}
 
/*PUSH Z80_HL*/
void op_0xe5(void)
{
 PUSH(Z80_HL);
 T_WAIT_UNTIL(11);
 return;
}
 
/*AND #*/
void op_0xe6(void)
{
 unsigned char n=NEXT_BYTE();
 AND(n);
 T_WAIT_UNTIL(7);
 return;
}
 
/*RST 0x20*/
void op_0xe7(void)
{
 RST(0x20);
 T_WAIT_UNTIL(11);
 return;
}
 
/*RET PE*/
void op_0xe8(void)
{
 if(Z80_F&Z80_FLAG_P)
 {
  RET();
  T_WAIT_UNTIL(11);
 }
 else 
 {
  T_WAIT_UNTIL(5);
 }
 return;
}
 
/*JP Z80_HL*/
void op_0xe9(void)
{
 JP_NO_MPTR(Z80_HL);
 T_WAIT_UNTIL(4);
 return;
}
 
/*JP PE,@*/
void op_0xea(void)
{
 unsigned short nn=NEXT_WORD();
 if(Z80_F&Z80_FLAG_P)
 {
  JP(nn);
  T_WAIT_UNTIL(10);
 }
 else
 {
  Z80_MEMPTR=nn;
  T_WAIT_UNTIL(10);
 }
 return;
}
 
/*EX Z80_DE,Z80_HL*/
void op_0xeb(void)
{
 EX(Z80_DE,Z80_HL);
 T_WAIT_UNTIL(4);
 return;
}
 
/*CALL PE,@*/
void op_0xec(void)
{
 unsigned short nn=NEXT_WORD();
 if(Z80_F&Z80_FLAG_P)
 {
  CALL(nn);
  T_WAIT_UNTIL(17);
 }
 else
 {
  Z80_MEMPTR=nn;
  T_WAIT_UNTIL(10);
 }
 return;
}
 
void op_0xed(void)
{
 Z80_Prefix=0xED;
 Z80_NoInterrupt=1;
 return;
}
 
/*XOR #*/
void op_0xee(void)
{
 unsigned char n=NEXT_BYTE();
 XOR(n);
 T_WAIT_UNTIL(7);
 return;
}
 
/*RST 0x28*/
void op_0xef(void)
{
 RST(0x28);
 T_WAIT_UNTIL(11);
 return;
}
 
/*RET P*/
void op_0xf0(void)
{
 if(!(Z80_F&Z80_FLAG_S))
 {
  RET();
  T_WAIT_UNTIL(11);
 }
 else 
 {
  T_WAIT_UNTIL(5);
 }
 return;
}
 
/*POP Z80_AF*/
void op_0xf1(void)
{
 POP(Z80_AF);
 T_WAIT_UNTIL(10);
 return;
}
 
/*JP P,@*/
void op_0xf2(void)
{
 unsigned short nn=NEXT_WORD();
 if(!(Z80_F&Z80_FLAG_S))
 {
  JP(nn);
  T_WAIT_UNTIL(10);
 }
 else
 {
  Z80_MEMPTR=nn;
  T_WAIT_UNTIL(10);
 }
 return;
}
 
/*DI*/
void op_0xf3(void)
{
 DI();
 T_WAIT_UNTIL(4);
 return;
}
 
/*CALL P,@*/
void op_0xf4(void)
{
 unsigned short nn=NEXT_WORD();
 if(!(Z80_F&Z80_FLAG_S))
 {
  CALL(nn);
  T_WAIT_UNTIL(17);
 }
 else
 {
  Z80_MEMPTR=nn;
  T_WAIT_UNTIL(10);
 }
 return;
}
 
/*PUSH Z80_AF*/
void op_0xf5(void)
{
 PUSH(Z80_AF);
 T_WAIT_UNTIL(11);
 return;
}
 
/*OR #*/
void op_0xf6(void)
{
 unsigned char n=NEXT_BYTE();
 OR(n);
 T_WAIT_UNTIL(7);
 return;
}
 
/*RST 0x30*/
void op_0xf7(void)
{
 RST(0x30);
 T_WAIT_UNTIL(11);
 return;
}
 
/*RET M*/
void op_0xf8(void)
{
 if(Z80_F&Z80_FLAG_S)
 {
  RET();
  T_WAIT_UNTIL(11);
 }
 else 
 {
  T_WAIT_UNTIL(5);
 }
 return;
}
 
/*LD Z80_SP,Z80_HL*/
void op_0xf9(void)
{
 LD16(Z80_SP,Z80_HL);
 T_WAIT_UNTIL(6);
 return;
}
 
/*JP M,@*/
void op_0xfa(void)
{
 unsigned short nn=NEXT_WORD();
 if(Z80_F&Z80_FLAG_S)
 {
  JP(nn);
  T_WAIT_UNTIL(10);
 }
 else
 {
  Z80_MEMPTR=nn;
  T_WAIT_UNTIL(10);
 }
 return;
}
 
/*EI*/
void op_0xfb(void)
{
 EI();
 T_WAIT_UNTIL(4);
 return;
}
 
/*CALL M,@*/
void op_0xfc(void)
{
 unsigned short nn=NEXT_WORD();
 if(Z80_F&Z80_FLAG_S)
 {
  CALL(nn);
  T_WAIT_UNTIL(17);
 }
 else
 {
  Z80_MEMPTR=nn;
  T_WAIT_UNTIL(10);
 }
 return;
}
 
void op_0xfd(void)
{
 Z80_Prefix=0xFD;
 Z80_NoInterrupt=1;
 return;
}
 
/*CP #*/
void op_0xfe(void)
{
 unsigned char n=NEXT_BYTE();
 CP(n);
 T_WAIT_UNTIL(7);
 return;
}
 
/*RST 0x38*/
void op_0xff(void)
{
 RST(0x38);
 T_WAIT_UNTIL(11);
 return;
}

void (*Z80_OpCode_base [0x100])(void)=
{
 op_0x00,op_0x01,op_0x02,op_0x03,op_0x04,op_0x05,op_0x06,op_0x07,op_0x08,op_0x09,op_0x0a,op_0x0b,op_0x0c,op_0x0d,op_0x0e,op_0x0f,
 op_0x10,op_0x11,op_0x12,op_0x13,op_0x14,op_0x15,op_0x16,op_0x17,op_0x18,op_0x19,op_0x1a,op_0x1b,op_0x1c,op_0x1d,op_0x1e,op_0x1f,
 op_0x20,op_0x21,op_0x22,op_0x23,op_0x24,op_0x25,op_0x26,op_0x27,op_0x28,op_0x29,op_0x2a,op_0x2b,op_0x2c,op_0x2d,op_0x2e,op_0x2f,
 op_0x30,op_0x31,op_0x32,op_0x33,op_0x34,op_0x35,op_0x36,op_0x37,op_0x38,op_0x39,op_0x3a,op_0x3b,op_0x3c,op_0x3d,op_0x3e,op_0x3f,
 op_0x40,op_0x41,op_0x42,op_0x43,op_0x44,op_0x45,op_0x46,op_0x47,op_0x48,op_0x49,op_0x4a,op_0x4b,op_0x4c,op_0x4d,op_0x4e,op_0x4f,
 op_0x50,op_0x51,op_0x52,op_0x53,op_0x54,op_0x55,op_0x56,op_0x57,op_0x58,op_0x59,op_0x5a,op_0x5b,op_0x5c,op_0x5d,op_0x5e,op_0x5f,
 op_0x60,op_0x61,op_0x62,op_0x63,op_0x64,op_0x65,op_0x66,op_0x67,op_0x68,op_0x69,op_0x6a,op_0x6b,op_0x6c,op_0x6d,op_0x6e,op_0x6f,
 op_0x70,op_0x71,op_0x72,op_0x73,op_0x74,op_0x75,op_0x76,op_0x77,op_0x78,op_0x79,op_0x7a,op_0x7b,op_0x7c,op_0x7d,op_0x7e,op_0x7f,
 op_0x80,op_0x81,op_0x82,op_0x83,op_0x84,op_0x85,op_0x86,op_0x87,op_0x88,op_0x89,op_0x8a,op_0x8b,op_0x8c,op_0x8d,op_0x8e,op_0x8f,
 op_0x90,op_0x91,op_0x92,op_0x93,op_0x94,op_0x95,op_0x96,op_0x97,op_0x98,op_0x99,op_0x9a,op_0x9b,op_0x9c,op_0x9d,op_0x9e,op_0x9f,
 op_0xa0,op_0xa1,op_0xa2,op_0xa3,op_0xa4,op_0xa5,op_0xa6,op_0xa7,op_0xa8,op_0xa9,op_0xaa,op_0xab,op_0xac,op_0xad,op_0xae,op_0xaf,
 op_0xb0,op_0xb1,op_0xb2,op_0xb3,op_0xb4,op_0xb5,op_0xb6,op_0xb7,op_0xb8,op_0xb9,op_0xba,op_0xbb,op_0xbc,op_0xbd,op_0xbe,op_0xbf,
 op_0xc0,op_0xc1,op_0xc2,op_0xc3,op_0xc4,op_0xc5,op_0xc6,op_0xc7,op_0xc8,op_0xc9,op_0xca,op_0xcb,op_0xcc,op_0xcd,op_0xce,op_0xcf,
 op_0xd0,op_0xd1,op_0xd2,op_0xd3,op_0xd4,op_0xd5,op_0xd6,op_0xd7,op_0xd8,op_0xd9,op_0xda,op_0xdb,op_0xdc,op_0xdd,op_0xde,op_0xdf,
 op_0xe0,op_0xe1,op_0xe2,op_0xe3,op_0xe4,op_0xe5,op_0xe6,op_0xe7,op_0xe8,op_0xe9,op_0xea,op_0xeb,op_0xec,op_0xed,op_0xee,op_0xef,
 op_0xf0,op_0xf1,op_0xf2,op_0xf3,op_0xf4,op_0xf5,op_0xf6,op_0xf7,op_0xf8,op_0xf9,op_0xfa,op_0xfb,op_0xfc,op_0xfd,op_0xfe,op_0xff
};