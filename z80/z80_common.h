#ifndef Z80_COMMON_H
#define Z80_COMMON_H

#include "stdafx.h"

union UZ80_Reg
{
 unsigned char R[21];//C, B, E, D, L, H, F, A, IXL, IXH, IYL, IYH, SPL, SPH, PCL, PCH, MEMPTRL, MEMPTRH, I, R, R7
 unsigned short	RP[9];//BC, DE, HL, AF, IX, IY, SP, PC, MEMPTR
};
  
union UZ80_A_Reg
{
 unsigned char R[8];//C, B, E, D, L, H, F, A
 unsigned short	RP[4];//BC, DE, HL, AF
};

union UZ80_SU
{
 unsigned char u;
 signed char s;
};

//регистры
#define Z80_A	uZ80_Reg.R[7]
#define Z80_F   uZ80_Reg.R[6]
#define Z80_AF  uZ80_Reg.RP[3]
 
#define Z80_B   uZ80_Reg.R[1]
#define Z80_C   uZ80_Reg.R[0]
#define Z80_BC  uZ80_Reg.RP[0]
 
#define Z80_D   uZ80_Reg.R[3]
#define Z80_E   uZ80_Reg.R[2]
#define Z80_DE  uZ80_Reg.RP[1]
 
#define Z80_H   uZ80_Reg.R[5]
#define Z80_L   uZ80_Reg.R[4]
#define Z80_HL  uZ80_Reg.RP[2]
 
#define Z80_IXH uZ80_Reg.R[9]
#define Z80_IXL uZ80_Reg.R[8]
#define Z80_IX  uZ80_Reg.RP[4]
 
#define Z80_IYH uZ80_Reg.R[11]
#define Z80_IYL uZ80_Reg.R[10]
#define Z80_IY  uZ80_Reg.RP[5]
 
#define Z80_SPH uZ80_Reg.R[13]
#define Z80_SPL uZ80_Reg.R[12]
#define Z80_SP  uZ80_Reg.RP[6]
 
#define Z80_PCH uZ80_Reg.R[15]
#define Z80_PCL uZ80_Reg.R[14]
#define Z80_PC  uZ80_Reg.RP[7]
 
#define Z80_MEMPTRH uZ80_Reg.R[17]
#define Z80_MEMPTRL uZ80_Reg.R[16]
#define Z80_MEMPTR uZ80_Reg.RP[8]
 
#define Z80_I  uZ80_Reg.R[18]
#define Z80_R  uZ80_Reg.R[19]
#define Z80_RR7 uZ80_Reg.R[20]
 
#define Z80_A_  uZ80_A_Reg.R[7]
#define Z80_F_  uZ80_A_Reg.R[6]
#define Z80_AF_ uZ80_A_Reg.RP[3]
 
#define Z80_B_  uZ80_A_Reg.R[1]
#define Z80_C_  uZ80_A_Reg.R[0]
#define Z80_BC_ uZ80_A_Reg.RP[0]
 
#define Z80_D_  uZ80_A_Reg.R[3]
#define Z80_E_  uZ80_A_Reg.R[2]
#define Z80_DE_ uZ80_A_Reg.RP[1]
 
#define Z80_H_  uZ80_A_Reg.R[5]
#define Z80_L_  uZ80_A_Reg.R[4]
#define Z80_HL_ uZ80_A_Reg.RP[2]
 
//флаги
#define Z80_FLAG_C	0x01
#define Z80_FLAG_N	0x02
#define Z80_FLAG_P	0x04
#define Z80_FLAG_V	Z80_FLAG_P
#define Z80_FLAG_3	0x08
#define Z80_FLAG_H	0x10
#define Z80_FLAG_5	0x20
#define Z80_FLAG_Z	0x40
#define Z80_FLAG_S	0x80

#define KB_CS		(00)
#define KB_Z		(01)
#define KB_X		(02)
#define KB_C		(03)
#define KB_V		(04)
#define KB_A		(05)
#define KB_S		(06)
#define KB_D		(07)
#define KB_F		(8)
#define KB_G		(9)
#define KB_Q		(10)
#define KB_W		(11)
#define KB_E		(12)
#define KB_R		(13)
#define KB_T		(14)
#define KB_1		(15)
#define KB_2		(16)
#define KB_3		(17)
#define KB_4		(18)
#define KB_5		(19)
#define KB_0		(20)
#define KB_9		(21)
#define KB_8		(22)
#define KB_7		(23)
#define KB_6		(24)
#define KB_P		(25)
#define KB_O		(26)
#define KB_I		(27)
#define KB_U		(28)
#define KB_Y		(29)
#define KB_ENT		(30)
#define KB_L		(31)
#define KB_K		(32)
#define KB_J		(33)
#define KB_H		(34)
#define KB_SP		(35)
#define KB_SS		(36)
#define KB_M		(37)
#define KB_N		(38)
#define KB_B		(39)


void Z80_SetKey(unsigned char code);
void Z80_ResetKey(unsigned char code);
unsigned char Z80_GetKey(unsigned char a);

extern inline void Z80_Poke8(unsigned short addr, unsigned char value);
extern inline unsigned char Z80_Peek8(unsigned short addr);
extern inline void Z80_Poke16(unsigned short addr, unsigned short value);
extern inline unsigned short Z80_Peek16(unsigned short addr);
 
extern inline unsigned char Z80_In(unsigned short port);
extern inline void Z80_Out(unsigned short port, unsigned char value);


extern inline unsigned short NEXT_WORD(void);
extern inline unsigned char NEXT_BYTE(void);
extern inline unsigned short READ_WORD(unsigned short addr);
extern inline void WRITE_WORD(unsigned short addr,unsigned short value); 
extern inline unsigned char READ_BYTE(unsigned short addr); 
extern inline void WRITE_BYTE(unsigned short addr,unsigned char value); 

extern inline unsigned char READ_PORT(unsigned short port); 
extern inline void WRITE_PORT(unsigned short port,unsigned char value); 

extern inline void T_WAIT_UNTIL(unsigned char value); 

extern inline void LD(unsigned char& dst,unsigned char src); 
extern inline void LD16(unsigned short& dst, unsigned short src); 

extern inline void LD_A_FROM_ADDR_MPTR(unsigned char& dst,unsigned char src,unsigned short addr); 

extern inline void LD_A_TO_ADDR_MPTR(unsigned char& dst,unsigned char src,unsigned short addr); 

extern inline void LD_RP_FROM_ADDR_MPTR_16(unsigned short& dst,unsigned short src,unsigned short addr); 

extern inline void LD_RP_TO_ADDR_MPTR_16(unsigned short& dst,unsigned short src,unsigned short addr); 
extern inline void LD_A_I(void); 
extern inline void LD_A_R(void); 
extern inline void LD_R_A(void); 

extern inline void EXX(void); 
extern inline void EX(unsigned short& rp1,unsigned short& rp2); 
extern inline void EX_MPTR(unsigned short& rp1,unsigned short& rp2); 

extern inline void ADD(unsigned char a,unsigned char value); 
extern inline void SUB(unsigned char value); 
extern inline void ADD16(unsigned short& value1,unsigned short value2); 
extern inline void INC(unsigned char& value); 
extern inline void DEC(unsigned char& value); 
extern inline void INC16(unsigned short& value); 
extern inline void DEC16(unsigned short& value); 
extern inline void ADDC(unsigned char& a,unsigned char value); 
extern inline void ADDC16(unsigned short hl,unsigned short value); 
extern inline void SUBC(unsigned char& a,unsigned char value); 
extern inline void SUBC16(unsigned short hl, unsigned short value); 
extern inline void CP(unsigned char value); 
extern inline void AND(unsigned char value); 
extern inline void OR(unsigned char value); 
extern inline void XOR(unsigned char value); 

extern inline void JP(unsigned short addr); 
extern inline void JP_NO_MPTR(unsigned short addr); 
extern inline void JR(signed char offset); 

extern inline void PUSH(unsigned short rp); 
extern inline void POP(unsigned short& rp); 
extern inline void RST(unsigned short addr); 
extern inline void CALL(unsigned short addr); 
extern inline void RET(void); 

extern inline void LDI(void); 
extern inline void LDD(void); 
extern inline void LDIR(void); 
extern inline void LDDR(void); 

extern inline void CPI(void); 
extern inline void CPD(void); 
extern inline void CPIR(void); 
extern inline void CPDR(void); 

extern inline void IN_A(unsigned char& reg,unsigned short port); 
extern inline void IN_BASE(unsigned char& reg,unsigned short port); 
extern inline void IN_F(unsigned short port); 
extern inline void INI(void); 
extern inline void IND(void); 
extern inline void INIR(void); 
extern inline void INDR(void); 

extern inline void IN_BL(unsigned char pbyte, unsigned short c_add); 

extern inline void OUT_A(unsigned short port,unsigned char reg); 
extern inline void OUT_BASE(unsigned short port,unsigned char reg); 
extern inline void OUTI(void); 
extern inline void OUTD(void); 
extern inline void OTIR(void);
extern inline void OTDR(void); 

extern inline void OUT_BL(unsigned char pbyte); 

extern inline void DI(void); 
extern inline void EI(void); 
extern inline void IM_MODE(unsigned char value); 

extern inline void RETN(void); 
extern inline void RETI(void); 
extern inline void CPL(void); 
extern inline void NEG(void); 
extern inline void SCF(void); 
extern inline void CCF(void); 
extern inline void HALT(void); 
extern inline void DAA(void); 

extern inline void SRL(unsigned char& value); 
extern inline void SRA(unsigned char& value); 
extern inline void SLA(unsigned char& value); 
extern inline void SLL(unsigned char& value); 
extern inline void RL(unsigned char& value); 
extern inline void RR(unsigned char& value); 
extern inline void RLC(unsigned char& value); 
extern inline void RRC(unsigned char& value); 
extern inline void RLA(void); 
extern inline void RRA(void); 
extern inline void RLCA(void); 
extern inline void RRCA(void); 
extern inline void RRD(void); 
extern inline void RLD(void); 

extern inline void BIT(unsigned char bit,unsigned char value); 

extern inline void BIT_MPTR(unsigned char bit,unsigned char value); 
extern inline void SET(unsigned char bit,unsigned char& value); 
extern inline void RES(unsigned char bit,unsigned char& value); 

#endif 
