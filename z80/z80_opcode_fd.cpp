#include "Z80_OpCode_fd.h"
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

extern void (*Z80_OpCode_base [0x100])(void);

extern UZ80_Reg uZ80_Reg;
extern UZ80_A_Reg uZ80_A_Reg;
extern UZ80_SU uZ80_SU;


/*ADD Z80_IY,Z80_BC*/
void op_FD_0x09(void)
{
 ADD16(Z80_IY,Z80_BC);
 T_WAIT_UNTIL(11);
 return;
}
 
/*ADD Z80_IY,Z80_DE*/
void op_FD_0x19(void)
{
 ADD16(Z80_IY,Z80_DE);
 T_WAIT_UNTIL(11);
 return;
}
 
/*LD Z80_IY,@*/
void op_FD_0x21(void)
{
 unsigned short nn=NEXT_WORD();
 LD16(Z80_IY,nn);
 T_WAIT_UNTIL(10);
 return;
}
 
/*LD (@),Z80_IY*/
void op_FD_0x22(void)
{
 unsigned short nn=NEXT_WORD();
 LD_RP_TO_ADDR_MPTR_16(Z80_Temp16,Z80_IY,nn);
 WRITE_WORD(nn,Z80_Temp16);
 T_WAIT_UNTIL(16);
 return;
}
 
/*INC Z80_IY*/
void op_FD_0x23(void)
{
 INC16(Z80_IY);
 T_WAIT_UNTIL(6);
 return;
}
 
/*INC Z80_IYH*/
void op_FD_0x24(void)
{
 INC(Z80_IYH);
 T_WAIT_UNTIL(4);
 return;
}
 
/*DEC Z80_IYH*/
void op_FD_0x25(void)
{
 DEC(Z80_IYH);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_IYH,#*/
void op_FD_0x26(void)
{
 unsigned char n=NEXT_BYTE();
 LD(Z80_IYH,n);
 T_WAIT_UNTIL(7);
 return;
}
 
/*ADD Z80_IY,Z80_IY*/
void op_FD_0x29(void)
{
 ADD16(Z80_IY,Z80_IY);
 T_WAIT_UNTIL(11);
 return;
}
 
/*LD Z80_IY,(@)*/
void op_FD_0x2a(void)
{
 unsigned short nn=NEXT_WORD();
 Z80_Temp16=READ_WORD(nn);
 LD_RP_FROM_ADDR_MPTR_16(Z80_IY,Z80_Temp16,nn);
 T_WAIT_UNTIL(16);
 return;
}
 
/*DEC Z80_IY*/
void op_FD_0x2b(void)
{
 DEC16(Z80_IY);
 T_WAIT_UNTIL(6);
 return;
}
 
/*INC Z80_IYL*/
void op_FD_0x2c(void)
{
 INC(Z80_IYL);
 T_WAIT_UNTIL(4);
 return;
}
 
/*DEC Z80_IYL*/
void op_FD_0x2d(void)
{
 DEC(Z80_IYL);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_IYL,#*/
void op_FD_0x2e(void)
{
 unsigned char n=NEXT_BYTE();
 LD(Z80_IYL,n);
 T_WAIT_UNTIL(7);
 return;
}
 
/*INC (Z80_IY+$)*/
void op_FD_0x34(void)
{
 uZ80_SU.u=NEXT_BYTE();
 Z80_MEMPTR=(Z80_IY+uZ80_SU.s);
 Z80_Temp8=READ_BYTE(Z80_IY+uZ80_SU.s);
 INC(Z80_Temp8);
 WRITE_BYTE(Z80_IY+uZ80_SU.s,Z80_Temp8);
 T_WAIT_UNTIL(19);
 return;
}
 
/*DEC (Z80_IY+$)*/
void op_FD_0x35(void)
{
 uZ80_SU.u=NEXT_BYTE();
 Z80_MEMPTR=(Z80_IY+uZ80_SU.s);
 Z80_Temp8=READ_BYTE(Z80_IY+uZ80_SU.s);
 DEC(Z80_Temp8);
 WRITE_BYTE(Z80_IY+uZ80_SU.s,Z80_Temp8);
 T_WAIT_UNTIL(19);
 return;
}
 
/*LD (Z80_IY+$),#*/
void op_FD_0x36(void)
{
 uZ80_SU.u=NEXT_BYTE();
 Z80_MEMPTR=(Z80_IY+uZ80_SU.s);
 unsigned char n=NEXT_BYTE();
 LD(n,n);
 WRITE_BYTE(Z80_IY+uZ80_SU.s,n);
 T_WAIT_UNTIL(15);
 return;
}
 
/*ADD Z80_IY,Z80_SP*/
void op_FD_0x39(void)
{
 ADD16(Z80_IY,Z80_SP);
 T_WAIT_UNTIL(11);
 return;
}
 
/*LD Z80_B,Z80_IYH*/
void op_FD_0x44(void)
{
 LD(Z80_B,Z80_IYH);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_B,Z80_IYL*/
void op_FD_0x45(void)
{
 LD(Z80_B,Z80_IYL);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_B,(Z80_IY+$)*/
void op_FD_0x46(void)
{
 uZ80_SU.u=NEXT_BYTE();
 Z80_MEMPTR=(Z80_IY+uZ80_SU.s);
 Z80_Temp8=READ_BYTE(Z80_IY+uZ80_SU.s);
 LD(Z80_B,Z80_Temp8);
 T_WAIT_UNTIL(15);
 return;
}
 
/*LD Z80_C,Z80_IYH*/
void op_FD_0x4c(void)
{
 LD(Z80_C,Z80_IYH);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_C,Z80_IYL*/
void op_FD_0x4d(void)
{
 LD(Z80_C,Z80_IYL);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_C,(Z80_IY+$)*/
void op_FD_0x4e(void)
{
 uZ80_SU.u=NEXT_BYTE();
 Z80_MEMPTR=(Z80_IY+uZ80_SU.s);
 Z80_Temp8=READ_BYTE(Z80_IY+uZ80_SU.s);
 LD(Z80_C,Z80_Temp8);
 T_WAIT_UNTIL(15);
 return;
}
 
/*LD Z80_D,Z80_IYH*/
void op_FD_0x54(void)
{
 LD(Z80_D,Z80_IYH);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_D,Z80_IYL*/
void op_FD_0x55(void)
{
 LD(Z80_D,Z80_IYL);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_D,(Z80_IY+$)*/
void op_FD_0x56(void)
{
 uZ80_SU.u=NEXT_BYTE();
 Z80_MEMPTR=(Z80_IY+uZ80_SU.s);
 Z80_Temp8=READ_BYTE(Z80_IY+uZ80_SU.s);
 LD(Z80_D,Z80_Temp8);
 T_WAIT_UNTIL(15);
 return;
}
 
/*LD Z80_E,Z80_IYH*/
void op_FD_0x5c(void)
{
 LD(Z80_E,Z80_IYH);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_E,Z80_IYL*/
void op_FD_0x5d(void)
{
 LD(Z80_E,Z80_IYL);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_E,(Z80_IY+$)*/
void op_FD_0x5e(void)
{
 uZ80_SU.u=NEXT_BYTE();
 Z80_MEMPTR=(Z80_IY+uZ80_SU.s);
 Z80_Temp8=READ_BYTE(Z80_IY+uZ80_SU.s);
 LD(Z80_E,Z80_Temp8);
 T_WAIT_UNTIL(15);
 return;
}
 
/*LD Z80_IYH,Z80_B*/
void op_FD_0x60(void)
{
 LD(Z80_IYH,Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_IYH,Z80_C*/
void op_FD_0x61(void)
{
 LD(Z80_IYH,Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_IYH,Z80_D*/
void op_FD_0x62(void)
{
 LD(Z80_IYH,Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_IYH,Z80_E*/
void op_FD_0x63(void)
{
 LD(Z80_IYH,Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_IYH,Z80_IYH*/
void op_FD_0x64(void)
{
 LD(Z80_IYH,Z80_IYH);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_IYH,Z80_IYL*/
void op_FD_0x65(void)
{
 LD(Z80_IYH,Z80_IYL);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_H,(Z80_IY+$)*/
void op_FD_0x66(void)
{
 uZ80_SU.u=NEXT_BYTE();
 Z80_MEMPTR=(Z80_IY+uZ80_SU.s);
 Z80_Temp8=READ_BYTE(Z80_IY+uZ80_SU.s);
 LD(Z80_H,Z80_Temp8);
 T_WAIT_UNTIL(15);
 return;
}
 
/*LD Z80_IYH,Z80_A*/
void op_FD_0x67(void)
{
 LD(Z80_IYH,Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_IYL,Z80_B*/
void op_FD_0x68(void)
{
 LD(Z80_IYL,Z80_B);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_IYL,Z80_C*/
void op_FD_0x69(void)
{
 LD(Z80_IYL,Z80_C);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_IYL,Z80_D*/
void op_FD_0x6a(void)
{
 LD(Z80_IYL,Z80_D);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_IYL,Z80_E*/
void op_FD_0x6b(void)
{
 LD(Z80_IYL,Z80_E);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_IYL,Z80_IYH*/
void op_FD_0x6c(void)
{
 LD(Z80_IYL,Z80_IYH);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_IYL,Z80_IYL*/
void op_FD_0x6d(void)
{
 LD(Z80_IYL,Z80_IYL);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_L,(Z80_IY+$)*/
void op_FD_0x6e(void)
{
 uZ80_SU.u=NEXT_BYTE();
 Z80_MEMPTR=(Z80_IY+uZ80_SU.s);
 Z80_Temp8=READ_BYTE(Z80_IY+uZ80_SU.s);
 LD(Z80_L,Z80_Temp8);
 T_WAIT_UNTIL(15);
 return;
}
 
/*LD Z80_IYL,Z80_A*/
void op_FD_0x6f(void)
{
 LD(Z80_IYL,Z80_A);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD (Z80_IY+$),Z80_B*/
void op_FD_0x70(void)
{
 uZ80_SU.u=NEXT_BYTE();
 Z80_MEMPTR=(Z80_IY+uZ80_SU.s);
 LD(Z80_Temp8,Z80_B);
 WRITE_BYTE(Z80_IY+uZ80_SU.s,Z80_Temp8);
 T_WAIT_UNTIL(15);
 return;
}
 
/*LD (Z80_IY+$),Z80_C*/
void op_FD_0x71(void)
{
 uZ80_SU.u=NEXT_BYTE();
 Z80_MEMPTR=(Z80_IY+uZ80_SU.s);
 LD(Z80_Temp8,Z80_C);
 WRITE_BYTE(Z80_IY+uZ80_SU.s,Z80_Temp8);
 T_WAIT_UNTIL(15);
 return;
}
 
/*LD (Z80_IY+$),Z80_D*/
void op_FD_0x72(void)
{
 uZ80_SU.u=NEXT_BYTE();
 Z80_MEMPTR=(Z80_IY+uZ80_SU.s);
 LD(Z80_Temp8,Z80_D);
 WRITE_BYTE(Z80_IY+uZ80_SU.s,Z80_Temp8);
 T_WAIT_UNTIL(15);
 return;
}
 
/*LD (Z80_IY+$),Z80_E*/
void op_FD_0x73(void)
{
 uZ80_SU.u=NEXT_BYTE();
 Z80_MEMPTR=(Z80_IY+uZ80_SU.s);
 LD(Z80_Temp8,Z80_E);
 WRITE_BYTE(Z80_IY+uZ80_SU.s,Z80_Temp8);
 T_WAIT_UNTIL(15);
 return;
}
 
/*LD (Z80_IY+$),Z80_H*/
void op_FD_0x74(void)
{
 uZ80_SU.u=NEXT_BYTE();
 Z80_MEMPTR=(Z80_IY+uZ80_SU.s);
 LD(Z80_Temp8,Z80_H);
 WRITE_BYTE(Z80_IY+uZ80_SU.s,Z80_Temp8);
 T_WAIT_UNTIL(15);
 return;
}
 
/*LD (Z80_IY+$),Z80_L*/
void op_FD_0x75(void)
{
 uZ80_SU.u=NEXT_BYTE();
 Z80_MEMPTR=(Z80_IY+uZ80_SU.s);
 LD(Z80_Temp8,Z80_L);
 WRITE_BYTE(Z80_IY+uZ80_SU.s,Z80_Temp8);
 T_WAIT_UNTIL(15);
 return;
}
 
/*LD (Z80_IY+$),Z80_A*/
void op_FD_0x77(void)
{
 uZ80_SU.u=NEXT_BYTE();
 Z80_MEMPTR=(Z80_IY+uZ80_SU.s);
 LD(Z80_Temp8,Z80_A);
 WRITE_BYTE(Z80_IY+uZ80_SU.s,Z80_Temp8);
 T_WAIT_UNTIL(15);
 return;
}
 
/*LD Z80_A,Z80_IYH*/
void op_FD_0x7c(void)
{
 LD(Z80_A,Z80_IYH);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_A,Z80_IYL*/
void op_FD_0x7d(void)
{
 LD(Z80_A,Z80_IYL);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_A,(Z80_IY+$)*/
void op_FD_0x7e(void)
{
 uZ80_SU.u=NEXT_BYTE();
 Z80_MEMPTR=(Z80_IY+uZ80_SU.s);
 Z80_Temp8=READ_BYTE(Z80_IY+uZ80_SU.s);
 LD(Z80_A,Z80_Temp8);
 T_WAIT_UNTIL(15);
 return;
}
 
/*ADD Z80_A,Z80_IYH*/
void op_FD_0x84(void)
{
 ADD(Z80_A,Z80_IYH);
 T_WAIT_UNTIL(4);
 return;
}
 
/*ADD Z80_A,Z80_IYL*/
void op_FD_0x85(void)
{
 ADD(Z80_A,Z80_IYL);
 T_WAIT_UNTIL(4);
 return;
}
 
/*ADD Z80_A,(Z80_IY+$)*/
void op_FD_0x86(void)
{
 uZ80_SU.u=NEXT_BYTE();
 Z80_MEMPTR=(Z80_IY+uZ80_SU.s);
 Z80_Temp8=READ_BYTE(Z80_IY+uZ80_SU.s);
 ADD(Z80_A,Z80_Temp8);
 T_WAIT_UNTIL(15);
 return;
}
 
/*ADDC Z80_A,Z80_IYH*/
void op_FD_0x8c(void)
{
 ADDC(Z80_A,Z80_IYH);
 T_WAIT_UNTIL(4);
 return;
}
 
/*ADDC Z80_A,Z80_IYL*/
void op_FD_0x8d(void)
{
 ADDC(Z80_A,Z80_IYL);
 T_WAIT_UNTIL(4);
 return;
}
 
/*ADDC Z80_A,(Z80_IY+$)*/
void op_FD_0x8e(void)
{
 uZ80_SU.u=NEXT_BYTE();
 Z80_MEMPTR=(Z80_IY+uZ80_SU.s);
 Z80_Temp8=READ_BYTE(Z80_IY+uZ80_SU.s);
 ADDC(Z80_A,Z80_Temp8);
 T_WAIT_UNTIL(15);
 return;
}
 
/*SUB Z80_IYH*/
void op_FD_0x94(void)
{
 SUB(Z80_IYH);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SUB Z80_IYL*/
void op_FD_0x95(void)
{
 SUB(Z80_IYL);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SUB (Z80_IY+$)*/
void op_FD_0x96(void)
{
 uZ80_SU.u=NEXT_BYTE();
 Z80_MEMPTR=(Z80_IY+uZ80_SU.s);
 Z80_Temp8=READ_BYTE(Z80_IY+uZ80_SU.s);
 SUB(Z80_Temp8);
 T_WAIT_UNTIL(15);
 return;
}
 
/*SUBC Z80_A,Z80_IYH*/
void op_FD_0x9c(void)
{
 SUBC(Z80_A,Z80_IYH);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SUBC Z80_A,Z80_IYL*/
void op_FD_0x9d(void)
{
 SUBC(Z80_A,Z80_IYL);
 T_WAIT_UNTIL(4);
 return;
}
 
/*SUBC Z80_A,(Z80_IY+$)*/
void op_FD_0x9e(void)
{
 uZ80_SU.u=NEXT_BYTE();
 Z80_MEMPTR=(Z80_IY+uZ80_SU.s);
 Z80_Temp8=READ_BYTE(Z80_IY+uZ80_SU.s);
 SUBC(Z80_A,Z80_Temp8);
 T_WAIT_UNTIL(15);
 return;
}
 
/*AND Z80_IYH*/
void op_FD_0xa4(void)
{
 AND(Z80_IYH);
 T_WAIT_UNTIL(4);
 return;
}
 
/*AND Z80_IYL*/
void op_FD_0xa5(void)
{
 AND(Z80_IYL);
 T_WAIT_UNTIL(4);
 return;
}
 
/*AND (Z80_IY+$)*/
void op_FD_0xa6(void)
{
 uZ80_SU.u=NEXT_BYTE();
 Z80_MEMPTR=(Z80_IY+uZ80_SU.s);
 Z80_Temp8=READ_BYTE(Z80_IY+uZ80_SU.s);
 AND(Z80_Temp8);
 T_WAIT_UNTIL(15);
 return;
}
 
/*XOR Z80_IYH*/
void op_FD_0xac(void)
{
 XOR(Z80_IYH);
 T_WAIT_UNTIL(4);
 return;
}
 
/*XOR Z80_IYL*/
void op_FD_0xad(void)
{
 XOR(Z80_IYL);
 T_WAIT_UNTIL(4);
 return;
}
 
/*XOR (Z80_IY+$)*/
void op_FD_0xae(void)
{
 uZ80_SU.u=NEXT_BYTE();
 Z80_MEMPTR=(Z80_IY+uZ80_SU.s);
 Z80_Temp8=READ_BYTE(Z80_IY+uZ80_SU.s);
 XOR(Z80_Temp8);
 T_WAIT_UNTIL(15);
 return;
}
 
/*OR Z80_IYH*/
void op_FD_0xb4(void)
{
 OR(Z80_IYH);
 T_WAIT_UNTIL(4);
 return;
}
 
/*OR Z80_IYL*/
void op_FD_0xb5(void)
{
 OR(Z80_IYL);
 T_WAIT_UNTIL(4);
 return;
}
 
/*OR (Z80_IY+$)*/
void op_FD_0xb6(void)
{
 uZ80_SU.u=NEXT_BYTE();
 Z80_MEMPTR=(Z80_IY+uZ80_SU.s);
 Z80_Temp8=READ_BYTE(Z80_IY+uZ80_SU.s);
 OR(Z80_Temp8);
 T_WAIT_UNTIL(15);
 return;
}
 
/*CP Z80_IYH*/
void op_FD_0xbc(void)
{
 CP(Z80_IYH);
 T_WAIT_UNTIL(4);
 return;
}
 
/*CP Z80_IYL*/
void op_FD_0xbd(void)
{
 CP(Z80_IYL);
 T_WAIT_UNTIL(4);
 return;
}
 
/*CP (Z80_IY+$)*/
void op_FD_0xbe(void)
{
 uZ80_SU.u=NEXT_BYTE();
 Z80_MEMPTR=(Z80_IY+uZ80_SU.s);
 Z80_Temp8=READ_BYTE(Z80_IY+uZ80_SU.s);
 CP(Z80_Temp8);
 T_WAIT_UNTIL(15);
 return;
}
 
 
/*POP Z80_IY*/
void op_FD_0xe1(void)
{
 POP(Z80_IY);
 T_WAIT_UNTIL(10);
 return;
}
 
/*EX (Z80_SP),Z80_IY*/
void op_FD_0xe3(void)
{
 Z80_Temp16=READ_WORD(Z80_SP);
 EX_MPTR(Z80_Temp16,Z80_IY);
 WRITE_WORD(Z80_SP,Z80_Temp16);
 T_WAIT_UNTIL(19);
 return;
}
 
/*PUSH Z80_IY*/
void op_FD_0xe5(void)
{
 PUSH(Z80_IY);
 T_WAIT_UNTIL(11);
 return;
}
 
/*JP Z80_IY*/
void op_FD_0xe9(void)
{
 JP_NO_MPTR(Z80_IY);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_SP,Z80_IY*/
void op_FD_0xf9(void)
{
 LD16(Z80_SP,Z80_IY);
 T_WAIT_UNTIL(6);
 return;
}
 
/*NONI*/
void non_FD (void)
{
 (*Z80_OpCode_base[Z80_OpCode])();
 return;
}
 
void (*Z80_OpCode_fd[0x100])(void)=
{
 non_FD,non_FD,non_FD,non_FD,non_FD,non_FD,non_FD,non_FD,non_FD,op_FD_0x09,non_FD,non_FD,non_FD,non_FD,non_FD,non_FD,
 non_FD,non_FD,non_FD,non_FD,non_FD,non_FD,non_FD,non_FD,non_FD,op_FD_0x19,non_FD,non_FD,non_FD,non_FD,non_FD,non_FD,
 non_FD,op_FD_0x21,op_FD_0x22,op_FD_0x23,op_FD_0x24,op_FD_0x25,op_FD_0x26,non_FD,non_FD,op_FD_0x29,op_FD_0x2a,op_FD_0x2b,op_FD_0x2c,op_FD_0x2d,op_FD_0x2e,non_FD,
 non_FD,non_FD,non_FD,non_FD,op_FD_0x34,op_FD_0x35,op_FD_0x36,non_FD,non_FD,op_FD_0x39,non_FD,non_FD,non_FD,non_FD,non_FD,non_FD,
 non_FD,non_FD,non_FD,non_FD,op_FD_0x44,op_FD_0x45,op_FD_0x46,non_FD,non_FD,non_FD,non_FD,non_FD,op_FD_0x4c,op_FD_0x4d,op_FD_0x4e,non_FD,
 non_FD,non_FD,non_FD,non_FD,op_FD_0x54,op_FD_0x55,op_FD_0x56,non_FD,non_FD,non_FD,non_FD,non_FD,op_FD_0x5c,op_FD_0x5d,op_FD_0x5e,non_FD,
 op_FD_0x60,op_FD_0x61,op_FD_0x62,op_FD_0x63,op_FD_0x64,op_FD_0x65,op_FD_0x66,op_FD_0x67,op_FD_0x68,op_FD_0x69,op_FD_0x6a,op_FD_0x6b,op_FD_0x6c,op_FD_0x6d,op_FD_0x6e,op_FD_0x6f,
 op_FD_0x70,op_FD_0x71,op_FD_0x72,op_FD_0x73,op_FD_0x74,op_FD_0x75,non_FD,op_FD_0x77,non_FD,non_FD,non_FD,non_FD,op_FD_0x7c,op_FD_0x7d,op_FD_0x7e,non_FD,
 non_FD,non_FD,non_FD,non_FD,op_FD_0x84,op_FD_0x85,op_FD_0x86,non_FD,non_FD,non_FD,non_FD,non_FD,op_FD_0x8c,op_FD_0x8d,op_FD_0x8e,non_FD,
 non_FD,non_FD,non_FD,non_FD,op_FD_0x94,op_FD_0x95,op_FD_0x96,non_FD,non_FD,non_FD,non_FD,non_FD,op_FD_0x9c,op_FD_0x9d,op_FD_0x9e,non_FD,
 non_FD,non_FD,non_FD,non_FD,op_FD_0xa4,op_FD_0xa5,op_FD_0xa6,non_FD,non_FD,non_FD,non_FD,non_FD,op_FD_0xac,op_FD_0xad,op_FD_0xae,non_FD,
 non_FD,non_FD,non_FD,non_FD,op_FD_0xb4,op_FD_0xb5,op_FD_0xb6,non_FD,non_FD,non_FD,non_FD,non_FD,op_FD_0xbc,op_FD_0xbd,op_FD_0xbe,non_FD,
 non_FD,non_FD,non_FD,non_FD,non_FD,non_FD,non_FD,non_FD,non_FD,non_FD,non_FD,non_FD,non_FD,non_FD,non_FD,non_FD,
 non_FD,non_FD,non_FD,non_FD,non_FD,non_FD,non_FD,non_FD,non_FD,non_FD,non_FD,non_FD,non_FD,non_FD,non_FD,non_FD,
 non_FD,op_FD_0xe1,non_FD,op_FD_0xe3,non_FD,op_FD_0xe5,non_FD,non_FD,non_FD,op_FD_0xe9,non_FD,non_FD,non_FD,non_FD,non_FD,non_FD,
 non_FD,non_FD,non_FD,non_FD,non_FD,non_FD,non_FD,non_FD,non_FD,op_FD_0xf9,non_FD,non_FD,non_FD,non_FD,non_FD,non_FD
};
