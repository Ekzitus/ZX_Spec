#include "Z80_OpCode_ed.h"
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

/*IN Z80_B,(Z80_C)*/
void op_ED_0x40(void)
{
 IN_BASE(Z80_B,Z80_BC);
 T_WAIT_UNTIL(8);
 return;
}
 
/*OUT (Z80_C),Z80_B*/
void op_ED_0x41(void)
{
 OUT_BASE(Z80_BC,Z80_B);
 T_WAIT_UNTIL(8);
 return;
}
 
/*SUBC Z80_HL,Z80_BC*/
void op_ED_0x42(void)
{
 SUBC16(Z80_HL,Z80_BC);
 T_WAIT_UNTIL(11);
 return;
}
 
/*LD (@),Z80_BC*/
void op_ED_0x43(void)
{
 unsigned short nn=NEXT_WORD();
 LD_RP_TO_ADDR_MPTR_16(Z80_Temp16,Z80_BC,nn);
 WRITE_WORD(nn,Z80_Temp16);
 T_WAIT_UNTIL(16);
 return;
}
 
/*NEG*/
void op_ED_0x44(void)
{
 NEG();
 T_WAIT_UNTIL(4);
 return;
}
 
/*RETN*/
void op_ED_0x45(void)
{
 RETN();
 T_WAIT_UNTIL(10);
 return;
}
 
/*IM 0*/
void op_ED_0x46(void)
{
 IM_MODE(0);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_I,Z80_A*/
void op_ED_0x47(void)
{
 LD(Z80_I,Z80_A);
 T_WAIT_UNTIL(5);
 return;
}
 
/*IN Z80_C,(Z80_C)*/
void op_ED_0x48(void)
{
 IN_BASE(Z80_C,Z80_BC);
 T_WAIT_UNTIL(8);
 return;
}
 
/*OUT (Z80_C),Z80_C*/
void op_ED_0x49(void)
{
 OUT_BASE(Z80_BC,Z80_C);
 T_WAIT_UNTIL(8);
 return;
}
 
/*ADDC Z80_HL,Z80_BC*/
void op_ED_0x4a(void)
{
 ADDC16(Z80_HL,Z80_BC);
 T_WAIT_UNTIL(11);
 return;
}
 
/*LD Z80_BC,(@)*/
void op_ED_0x4b(void)
{
 unsigned short nn=NEXT_WORD();
 Z80_Temp16=READ_WORD(nn);
 LD_RP_FROM_ADDR_MPTR_16(Z80_BC,Z80_Temp16,nn);
 T_WAIT_UNTIL(16);
 return;
}
 
/*NEG*/
void op_ED_0x4c(void)
{
 NEG();
 T_WAIT_UNTIL(4);
 return;
}
 
/*RETI*/
void op_ED_0x4d(void)
{
 RETI();
 T_WAIT_UNTIL(10);
 return;
}
 
/*IM 0*/
void op_ED_0x4e(void)
{
 IM_MODE(0);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD R,Z80_A*/
void op_ED_0x4f(void)
{
 LD_R_A();
 T_WAIT_UNTIL(5);
 return;
}
 
/*IN Z80_D,(Z80_C)*/
void op_ED_0x50(void)
{
 IN_BASE(Z80_D,Z80_BC);
 T_WAIT_UNTIL(8);
 return;
}
 
/*OUT (Z80_C),Z80_D*/
void op_ED_0x51(void)
{
 OUT_BASE(Z80_BC,Z80_D);
 T_WAIT_UNTIL(8);
 return;
}
 
/*SUBC Z80_HL,Z80_DE*/
void op_ED_0x52(void)
{
 SUBC16(Z80_HL,Z80_DE);
 T_WAIT_UNTIL(11);
 return;
}
 
/*LD (@),Z80_DE*/
void op_ED_0x53(void)
{
 unsigned short nn=NEXT_WORD();
 LD_RP_TO_ADDR_MPTR_16(Z80_Temp16,Z80_DE,nn);
 WRITE_WORD(nn,Z80_Temp16);
 T_WAIT_UNTIL(16);
 return;
}
 
/*NEG*/
void op_ED_0x54(void)
{
 NEG();
 T_WAIT_UNTIL(4);
 return;
}
 
/*RETN*/
void op_ED_0x55(void)
{
 RETN();
 T_WAIT_UNTIL(10);
 return;
}
 
/*IM 1*/
void op_ED_0x56(void)
{
 IM_MODE(1);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_A,Z80_I*/
void op_ED_0x57(void)
{
 LD_A_I();
 T_WAIT_UNTIL(5);
 return;
}
 
/*IN Z80_E,(Z80_C)*/
void op_ED_0x58(void)
{
 IN_BASE(Z80_E,Z80_BC);
 T_WAIT_UNTIL(8);
 return;
}
 
/*OUT (Z80_C),Z80_E*/
void op_ED_0x59(void)
{
 OUT_BASE(Z80_BC,Z80_E);
 T_WAIT_UNTIL(8);
 return;
}
 
/*ADDC Z80_HL,Z80_DE*/
void op_ED_0x5a(void)
{
 ADDC16(Z80_HL,Z80_DE);
 T_WAIT_UNTIL(11);
 return;
}
 
/*LD Z80_DE,(@)*/
void op_ED_0x5b(void)
{
 unsigned short nn=NEXT_WORD();
 Z80_Temp16=READ_WORD(nn);
 LD_RP_FROM_ADDR_MPTR_16(Z80_DE,Z80_Temp16,nn);
 T_WAIT_UNTIL(16);
 return;
}
 
/*NEG*/
void op_ED_0x5c(void)
{
 NEG();
 T_WAIT_UNTIL(4);
 return;
}
 
/*RETI*/
void op_ED_0x5d(void)
{
 RETI();
 T_WAIT_UNTIL(10);
 return;
}
 
/*IM 2*/
void op_ED_0x5e(void)
{
 IM_MODE(2);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LD Z80_A,R*/
void op_ED_0x5f(void)
{
 LD_A_R();
 T_WAIT_UNTIL(5);
 return;
}
 
/*IN Z80_H,(Z80_C)*/
void op_ED_0x60(void)
{
 IN_BASE(Z80_H,Z80_BC);
 T_WAIT_UNTIL(8);
 return;
}
 
/*OUT (Z80_C),Z80_H*/
void op_ED_0x61(void)
{
 OUT_BASE(Z80_BC,Z80_H);
 T_WAIT_UNTIL(8);
 return;
}
 
/*SUBC Z80_HL,Z80_HL*/
void op_ED_0x62(void)
{
 SUBC16(Z80_HL,Z80_HL);
 T_WAIT_UNTIL(11);
 return;
}
 
/*LD (@),Z80_HL*/
void op_ED_0x63(void)
{
 unsigned short nn=NEXT_WORD();
 LD_RP_TO_ADDR_MPTR_16(Z80_Temp16,Z80_HL,nn);
 WRITE_WORD(nn,Z80_Temp16);
 T_WAIT_UNTIL(16);
 return;
}
 
/*NEG*/
void op_ED_0x64(void)
{
 NEG();
 T_WAIT_UNTIL(4);
 return;
}
 
/*RETN*/
void op_ED_0x65(void)
{
 RETN();
 T_WAIT_UNTIL(10);
 return;
}
 
/*IM 0*/
void op_ED_0x66(void)
{
 IM_MODE(0);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RRD*/
void op_ED_0x67(void)
{
 RRD();
 T_WAIT_UNTIL(14);
 return;
}
 
/*IN Z80_L,(Z80_C)*/
void op_ED_0x68(void)
{
 IN_BASE(Z80_L,Z80_BC);
 T_WAIT_UNTIL(8);
 return;
}
 
/*OUT (Z80_C),Z80_L*/
void op_ED_0x69(void)
{
 OUT_BASE(Z80_BC,Z80_L);
 T_WAIT_UNTIL(8);
 return;
}
 
/*ADDC Z80_HL,Z80_HL*/
void op_ED_0x6a(void)
{
 ADDC16(Z80_HL,Z80_HL);
 T_WAIT_UNTIL(11);
 return;
}
 
/*LD Z80_HL,(@)*/
void op_ED_0x6b(void)
{
 unsigned short nn=NEXT_WORD();
 Z80_Temp16=READ_WORD(nn);
 LD_RP_FROM_ADDR_MPTR_16(Z80_HL,Z80_Temp16,nn);
 T_WAIT_UNTIL(16);
 return;
}
 
/*NEG*/
void op_ED_0x6c(void)
{
 NEG();
 T_WAIT_UNTIL(4);
 return;
}
 
/*RETI*/
void op_ED_0x6d(void)
{
 RETI();
 T_WAIT_UNTIL(10);
 return;
}
 
/*IM 0*/
void op_ED_0x6e(void)
{
 IM_MODE(0);
 T_WAIT_UNTIL(4);
 return;
}
 
/*RLD*/
void op_ED_0x6f(void)
{
 RLD();
 T_WAIT_UNTIL(14);
 return;
}
 
/*IN_F (Z80_C)*/
void op_ED_0x70(void)
{
 IN_F(Z80_BC);
 T_WAIT_UNTIL(8);
 return;
}
 
/*OUT (Z80_C),0*/
void op_ED_0x71(void)
{
 OUT_BASE(Z80_BC,0);
 T_WAIT_UNTIL(8);
 return;
}
 
/*SUBC Z80_HL,Z80_SP*/
void op_ED_0x72(void)
{
 SUBC16(Z80_HL,Z80_SP);
 T_WAIT_UNTIL(11);
 return;
}
 
/*LD (@),Z80_SP*/
void op_ED_0x73(void)
{
 unsigned short nn=NEXT_WORD();
 LD_RP_TO_ADDR_MPTR_16(Z80_Temp16,Z80_SP,nn);
 WRITE_WORD(nn,Z80_Temp16);
 T_WAIT_UNTIL(16);
 return;
}
 
/*NEG*/
void op_ED_0x74(void)
{
 NEG();
 T_WAIT_UNTIL(4);
 return;
}
 
/*RETN*/
void op_ED_0x75(void)
{
 RETN();
 T_WAIT_UNTIL(10);
 return;
}
 
/*IM 1*/
void op_ED_0x76(void)
{
 IM_MODE(1);
 T_WAIT_UNTIL(4);
 return;
}
 
/*IN Z80_A,(Z80_C)*/
void op_ED_0x78(void)
{
 IN_BASE(Z80_A,Z80_BC);
 T_WAIT_UNTIL(8);
 return;
}
 
/*OUT (Z80_C),Z80_A*/
void op_ED_0x79(void)
{
 OUT_BASE(Z80_BC,Z80_A);
 T_WAIT_UNTIL(8);
 return;
}
 
/*ADDC Z80_HL,Z80_SP*/
void op_ED_0x7a(void)
{
 ADDC16(Z80_HL,Z80_SP);
 T_WAIT_UNTIL(11);
 return;
}
 
/*LD Z80_SP,(@)*/
void op_ED_0x7b(void)
{
 unsigned short nn=NEXT_WORD();
 Z80_Temp16=READ_WORD(nn);
 LD_RP_FROM_ADDR_MPTR_16(Z80_SP,Z80_Temp16,nn);
 T_WAIT_UNTIL(16);
 return;
}
 
/*NEG*/
void op_ED_0x7c(void)
{
 NEG();
 T_WAIT_UNTIL(4);
 return;
}
 
/*RETI*/
void op_ED_0x7d(void)
{
 RETI();
 T_WAIT_UNTIL(10);
 return;
}
 
/*IM 2*/
void op_ED_0x7e(void)
{
 IM_MODE(2);
 T_WAIT_UNTIL(4);
 return;
}
 
/*LDI*/
void op_ED_0xa0(void)
{
 LDI();
 T_WAIT_UNTIL(12);
 return;
}
 
/*CPI*/
void op_ED_0xa1(void)
{
 CPI();
 T_WAIT_UNTIL(12);
 return;
}
 
/*INI*/
void op_ED_0xa2(void)
{
 INI();
 T_WAIT_UNTIL(12);
 return;
}
 
/*OUTI*/
void op_ED_0xa3(void)
{
 OUTI();
 T_WAIT_UNTIL(12);
 return;
}
 
/*LDD*/
void op_ED_0xa8(void)
{
 LDD();
 T_WAIT_UNTIL(12);
 return;
}
 
/*CPD*/
void op_ED_0xa9(void)
{
 CPD();
 T_WAIT_UNTIL(12);
 return;
}
 
/*IND*/
void op_ED_0xaa(void)
{
 IND();
 T_WAIT_UNTIL(12);
 return;
}
 
/*OUTD*/
void op_ED_0xab(void)
{
 OUTD();
 T_WAIT_UNTIL(12);
 return;
}
 
/*LDIR*/
void op_ED_0xb0(void)
{
 LDIR();
 return;
}
 
/*CPIR*/
void op_ED_0xb1(void)
{
 CPIR();
 return;
}
 
/*INIR*/
void op_ED_0xb2(void)
{
 INIR();
 return;
}
 
/*OTIR*/
void op_ED_0xb3(void)
{
 OTIR();
 return;
}
 
/*LDDR*/
void op_ED_0xb8(void)
{
 LDDR();
 return;
}
 
/*CPDR*/
void op_ED_0xb9(void)
{
 CPDR();
 return;
}
 
/*INDR*/
void op_ED_0xba(void)
{
 INDR();
 return;
}
 
/*OTDR*/
void op_ED_0xbb(void)
{
 OTDR();
 return;
}
 
/*NONI*/
void noni_ED(void)
{
 T_WAIT_UNTIL(4);
 return;
}
 
void (*Z80_OpCode_ed [0x100])(void)=
{
 noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,
 noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,
 noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,
 noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,
 op_ED_0x40,op_ED_0x41,op_ED_0x42,op_ED_0x43,op_ED_0x44,op_ED_0x45,op_ED_0x46,op_ED_0x47,op_ED_0x48,op_ED_0x49,op_ED_0x4a,op_ED_0x4b,op_ED_0x4c,op_ED_0x4d,op_ED_0x4e,op_ED_0x4f,
 op_ED_0x50,op_ED_0x51,op_ED_0x52,op_ED_0x53,op_ED_0x54,op_ED_0x55,op_ED_0x56,op_ED_0x57,op_ED_0x58,op_ED_0x59,op_ED_0x5a,op_ED_0x5b,op_ED_0x5c,op_ED_0x5d,op_ED_0x5e,op_ED_0x5f,
 op_ED_0x60,op_ED_0x61,op_ED_0x62,op_ED_0x63,op_ED_0x64,op_ED_0x65,op_ED_0x66,op_ED_0x67,op_ED_0x68,op_ED_0x69,op_ED_0x6a,op_ED_0x6b,op_ED_0x6c,op_ED_0x6d,op_ED_0x6e,op_ED_0x6f,
 op_ED_0x70,op_ED_0x71,op_ED_0x72,op_ED_0x73,op_ED_0x74,op_ED_0x75,op_ED_0x76,noni_ED,op_ED_0x78,op_ED_0x79,op_ED_0x7a,op_ED_0x7b,op_ED_0x7c,op_ED_0x7d,op_ED_0x7e,noni_ED,
 noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,
 noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,
 op_ED_0xa0,op_ED_0xa1,op_ED_0xa2,op_ED_0xa3,noni_ED,noni_ED,noni_ED,noni_ED,op_ED_0xa8,op_ED_0xa9,op_ED_0xaa,op_ED_0xab,noni_ED,noni_ED,noni_ED,noni_ED,
 op_ED_0xb0,op_ED_0xb1,op_ED_0xb2,op_ED_0xb3,noni_ED,noni_ED,noni_ED,noni_ED,op_ED_0xb8,op_ED_0xb9,op_ED_0xba,op_ED_0xbb,noni_ED,noni_ED,noni_ED,noni_ED,
 noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,
 noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,
 noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,
 noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED,noni_ED
};
