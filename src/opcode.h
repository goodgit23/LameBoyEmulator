
// Opcode definitions for gameboy CPU
// (C) C. Kummer

#ifndef OPCODE_H
#define OPCODE_H

////////////////////////////////////////////////////////////////////////////////
// CONTROL, MISC INSTRUCTIONS //////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// NO-OP. Does nothing, no arguments
#define NOP 0x00
#define NOP_CYCLE_COUNT 4
#define NOP_ARGLEN 1

// HALT. Halts program execution until interrupt occurs
#define HALT 0x76
#define HALT_CYCLE_COUNT 4
#define HALT_ARGLEN 1

// CB: Seperate decoding
#define CB 0xcb

// DAA: Weird shit

#define DAA 0x27
#define DAA_CYCLES 4

// CPL: Complement A register
#define CPL 0x2f
#define CPL_CYCLES 4

// CCF: Complement carry flag
#define CCF 0x3f
#define CCF_CYCLES 4

// SCF: Set carry flag
#define SCF 0x37
#define SCF_CYCLES 4

#define MISC_CYCLES 4

#define STOP 0x10
#define STOP_ARGLEN 2
#define DI 0xf3
#define EI 0xfb

////////////////////////////////////////////////////////////////////////////////
// LOAD INSTRUCTIONS ///////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// 8-bit loads

////////////////////////////////////////////////////////////////////////////////
// Register-immediate loads/////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// Cycle count for these loads
#define LD_CYCLE_COUNT_REGISTER_IMMEDIATE_8 8
#define LD_REGISTER_IMMEDIATE_LEN 2

#define LD_B_d8 0x06
#define LD_D_d8 0x16
#define LD_H_d8 0x26
#define LD_C_d8 0x0e
#define LD_E_d8 0x1e
#define LD_L_d8 0x2e
#define LD_A_d8 0x3e

////////////////////////////////////////////////////////////////////////////////
// Register-register loads /////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#define LD_CYCLE_COUNT_REGISTER_REGISTER 4
#define LD_REGISTER_REGISTER_ARGLEN 1

// Load into A
#define LD_A_A 0x7f
#define LD_A_B 0x78
#define LD_A_C 0x79
#define LD_A_D 0x7a
#define LD_A_E 0x7b
#define LD_A_H 0x7c
#define LD_A_L 0x7d

// Load into B
#define LD_B_A 0x47
#define LD_B_B 0x40
#define LD_B_C 0x41
#define LD_B_D 0x42
#define LD_B_E 0x43
#define LD_B_H 0x44
#define LD_B_L 0x45

// Load into C
#define LD_C_A 0x4f
#define LD_C_B 0x48
#define LD_C_C 0x49
#define LD_C_D 0x4a
#define LD_C_E 0x4b
#define LD_C_H 0x4c
#define LD_C_L 0x4d

// Load into D
#define LD_D_A 0x57
#define LD_D_B 0x50
#define LD_D_C 0x51
#define LD_D_D 0x52
#define LD_D_E 0x53
#define LD_D_H 0x54
#define LD_D_L 0x55

// Load into E
#define LD_E_A 0x5f
#define LD_E_B 0x58
#define LD_E_C 0x59
#define LD_E_D 0x5a
#define LD_E_E 0x5b
#define LD_E_H 0x5c
#define LD_E_L 0x5d

// Load into H
#define LD_H_A 0x67
#define LD_H_B 0x60
#define LD_H_C 0x61
#define LD_H_D 0x62
#define LD_H_E 0x63
#define LD_H_H 0x64
#define LD_H_L 0x65

// Load into L
#define LD_L_A 0x6f
#define LD_L_B 0x68
#define LD_L_C 0x69
#define LD_L_D 0x6a
#define LD_L_E 0x6b
#define LD_L_H 0x6c
#define LD_L_L 0x6d

////////////////////////////////////////////////////////////////////////////////
// Register-memory indirect loads //////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#define LD_REG_MEM_INDIRECT_CYCLE_COUNT 8
#define LD_REG_INDIRECT_REGISTER_ARGLEN 1

#define LD_A_HL 0x7e
#define LD_B_HL 0x46
#define LD_C_HL 0x4e
#define LD_D_HL 0x56
#define LD_E_HL 0x5e
#define LD_H_HL 0x66
#define LD_L_HL 0x6e

// Specific to register A
#define LD_A_BC 0x0a
#define LD_A_DE 0x1a

////////////////////////////////////////////////////////////////////////////////
// Memory-indirect-register loads //////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#define LD_MEM_INDIRECT_REGISTER_CYCLE_COUNT 8
#define LD_REGISTER_REG_MEM_INDIRECT_ARGLEN 1

#define LD_HL_A 0x77
#define LD_HL_B 0x70
#define LD_HL_C 0x71
#define LD_HL_D 0x72
#define LD_HL_E 0x73
#define LD_HL_H 0x74
#define LD_HL_L 0x75

// Specific to register A
#define LD_BC_A 0x02
#define LD_DE_A 0x12

////////////////////////////////////////////////////////////////////////////////
// Immediate to register-indirect load /////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#define LD_IMM_TO_INDIRECT_REGISTER_CYCLE_COUNT 12
#define LD_IMM_TO_INDIRECT_REGISTER_ARGLEN 2

#define LD_HL_d8 0x36

////////////////////////////////////////////////////////////////////////////////
// Dereferenced memory address to accumulator //////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#define LD_ADDR_TO_REG_CYCLE_COUNT 16
#define LD_ADDR_TO_REG_ARGLEN 3

#define LD_A_a16p 0xfa
#define LD_a16p_A 0xea

////////////////////////////////////////////////////////////////////////////////
// (C) to accumulator //////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#define LD_A_C_CYCLES 8
#define LD_A_C_ARGLEN 1

#define LD_A_C_INDIRECT 0xf2
#define LD_C_INDIRECT_A 0xe2

////////////////////////////////////////////////////////////////////////////////
// (HL) decrement to A /////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#define LD_DEC_A_CYCLES 8
#define LD_DEC_A_ARGLEN 1

#define LD_DEC_A 0x3a
#define LD_A_DEC 0x32

////////////////////////////////////////////////////////////////////////////////
// (HL) increment to A /////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#define LD_INC_A 0x2a
#define LD_A_INC 0x22

////////////////////////////////////////////////////////////////////////////////
// 8-bit direct adress to A ////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#define LD_A_a8p_CYCLES 12
#define LD_A_a8p_ARGLEN 2

#define LD_A_a8p 0xe0
#define LD_a8p_A 0xf0

////////////////////////////////////////////////////////////////////////////////
// 16-bit loads ////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Combined register immediate /////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#define LD_COMB_CYCLES 12
#define LD_COMB_ARGLEN 3

#define LD_BC_d16 0x01
#define LD_DE_d16 0x11
#define LD_HL_d16 0x21
#define LD_SP_d16 0x31

////////////////////////////////////////////////////////////////////////////////
// Register to stack pointer ///////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#define LD_REG_SP_CYCLES 8
#define LD_REG_SP_ARGLEN 1

#define LD_SP_HL 0xf9

////////////////////////////////////////////////////////////////////////////////
// Register to stack pointer with 8 bit immediate offset ///////////////////////
////////////////////////////////////////////////////////////////////////////////
// Flags: Z N H C 
#define LDHL_CYCLES 12
#define LDHL_ARGLEN 2

#define LD_HL_SP_N 0xf8

////////////////////////////////////////////////////////////////////////////////
/// Stack pointer to address nn ////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#define LD_d16_SP_CYCLES 20
#define LD_d16_SP_ARGLEN 3

#define LD_d16p_SP 0x08

////////////////////////////////////////////////////////////////////////////////
// Stack operations ////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// Push register pairs on stack

#define PUSH_REGS_CYCLES 16
#define PUSH_REGS_ARGLEN 1

#define PUSH_AF 0xf5
#define PUSH_BC 0xc5
#define PUSH_DE 0xd5
#define PUSH_HL 0xe5

// Pop two bytes off stack into register pair

#define POP_REGS_CYCLES 16
#define POP_REGS_ARGLEN 1

#define POP_AF 0xf1
#define POP_BC 0xc1
#define POP_DE 0xd1
#define POP_HL 0xe1

////////////////////////////////////////////////////////////////////////////////
// 8-bit ALU instructions //////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// ADD AND SUBTRACT ACCUMULATOR
// Affects Z N H C
// ADD: Addition
// ADD A, reg/imm/(HL)

// Registers
#define ALU_REG_CYCLES 4
#define ALU_REG_ARGLEN 1

#define ADD_AA 0x87
#define ADD_AB 0x80
#define ADD_AC 0x81
#define ADD_AD 0x82
#define ADD_AE 0x83
#define ADD_AH 0x84
#define ADD_AL 0x85

// Immediate/Indirect memory

#define ALU_OTHER_CYCLES 8
#define ALU_IMM_ARGLEN 2

#define ADD_A_IND 0x86
#define ADD_A_d8 0xc6

// ADC: ADD WITH CARRY BIT
// Affects Z N H C
// Same cycles, arglen as ADD
// Registers

#define ADC_AA 0x8f
#define ADC_AB 0x88
#define ADC_AC 0x89
#define ADC_AD 0x8a
#define ADC_AE 0x8b
#define ADC_AH 0x8c
#define ADC_AL 0x8d

// Immediate/Indirect

#define ADC_A_IND 0x8e
#define ADC_A_d8 0xce

// SUB Sub without carry

#define SUB_AA 0x97
#define SUB_AB 0x90
#define SUB_AC 0x91
#define SUB_AD 0x92
#define SUB_AE 0x93
#define SUB_AH 0x94
#define SUB_AL 0x95

#define SUB_A_IND 0x96
#define SUB_A_d8 0xd6

// SBC Sub with carry

#define SBC_AA 0x9f
#define SBC_AB 0x98
#define SBC_AC 0x99
#define SBC_AD 0x9a
#define SBC_AE 0x9b
#define SBC_AH 0x9c
#define SBC_AL 0x9d

#define SBC_A_IND 0x9e
#define SBC_A_d8 0xde

// AND Logical and

#define AND_AA 0xa7
#define AND_AB 0xa0
#define AND_AC 0xa1
#define AND_AD 0xa2
#define AND_AE 0xa3
#define AND_AH 0xa4
#define AND_AL 0xa5

#define AND_A_IND 0xa6
#define AND_A_d8 0xe6

// Logical OR

#define OR_AA 0xb7
#define OR_AB 0xb0
#define OR_AC 0xb1
#define OR_AD 0xb2
#define OR_AE 0xb3
#define OR_AH 0xb4
#define OR_AL 0xb5

#define OR_A_IND 0xb6
#define OR_A_d8 0xf6

// Logical XOR

#define XOR_AA 0xaf
#define XOR_AB 0xa8
#define XOR_AC 0xa9
#define XOR_AD 0xaa
#define XOR_AE 0xab
#define XOR_AH 0xac
#define XOR_AL 0xad

#define XOR_A_IND 0xae
#define XOR_A_d8 0xee

// Compare

#define CP_AA 0xbf
#define CP_AB 0xb8
#define CP_AC 0xb9
#define CP_AD 0xba
#define CP_AE 0xbb
#define CP_AH 0xbc
#define CP_AL 0xbd

#define CP_A_IND 0xbe
#define CP_A_d8 0xfe

// Increment/decrement

#define INC_DEC_HL_IND_CYCLES 8

#define INC_A 0x3c
#define INC_B 0x04
#define INC_C 0x0c
#define INC_D 0x14
#define INC_E 0x1c
#define INC_H 0x24
#define INC_L 0x2c

#define INC_HL_IND 0x34

#define DEC_A 0x3d
#define DEC_B 0x05
#define DEC_C 0x0d
#define DEC_D 0x15
#define DEC_E 0x1d
#define DEC_H 0x25
#define DEC_L 0x2d

#define DEC_HL_IND 0x35

////////////////////////////////////////////////////////////////////////////////
// 16-bit ALU //////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#define ALU_16_REG_CYCLES 8
#define ALU_16_REG_ARGLEN 1
#define ALU_16_IMM_CYCLES 16
#define ALU_16_IMM_ARGLEN 2

// Adds
#define ADD_BC 0x09
#define ADD_DE 0x19
#define ADD_HL 0x29
#define ADD_SP 0x39

// Add to SP
#define ADD_SP_d8 0xe8

// Incs
#define INC_BC 0x03
#define INC_DE 0x13
#define INC_HL 0x23
#define INC_SP 0x33

// Decs

#define DEC_BC 0x0b
#define DEC_DE 0x1b
#define DEC_HL 0x2b
#define DEC_SP 0x3b

#define RLCA 0x07
#define RLCA_CYCLES 4

#define RLA 0x17
#define RLA_CYCLES 4

#define RRCA 0x0f
#define RRCA_CYCLES 4

#define RRA 0x1f
#define RRA_CYCLES 4

////////////////////////////////////////////////////////////////////////////////
// CB Opcodes //////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#define CB_ARGLEN 1

#define SWAP_CYCLES_REG 8
#define SWAP_CYCLES_ADDR 16

#define SWAP_UPPER 0x37
#define SWAP_LOWER 0x30
#define SWAP_INDIR 0x36

#define CB_CYCLES_REG 8
#define CB_CYCLES_ADDR 16

#define RLC_LOWER 0x00
#define RLC_UPPER 0x07
#define RLC_INDIR 0x06

#define RL_LOWER 0x10
#define RL_UPPER 0x17
#define RL_INDIR 0x16

#define RRC_LOWER 0x08
#define RRC_UPPER 0x0f
#define RRC_INDIR 0x0e

#define RR_LOWER 0x18
#define RR_UPPER 0x1f
#define RR_INDIR 0x1e

#define SLA_LOWER 0x20
#define SLA_UPPER 0x27
#define SLA_INDIR 0x26

#define SRA_LOWER 0x28
#define SRA_UPPER 0x2f
#define SRA_INDIR 0x2e

#define SRL_LOWER 0x38
#define SRL_UPPER 0x3f
#define SRL_INDIR 0x3e

#define BIT_LOWER 0x40
#define BIT_UPPER 0x7f

#define SET_LOWER 0xc0
#define SET_UPPER 0xff

#define RES_LOWER 0x80
#define RES_UPPER 0xbf

#define JP_CYCLES 16

#define JP 0xc3
#define JPNZ 0xc2
#define JPZ 0xca
#define JPNC 0xd2
#define JPC 0xda

#define JPHL_CYCLES 4

#define JPHL 0xe9

#define JR_CYCLES 8

#define JR 0x18

#define JRNZ 0x20
#define JRZ 0x28
#define JRNC 0x30
#define JRC 0x38

#define CALL_CYCLES 12

#define CALL 0xcd
#define CALLNZ 0xc4
#define CALLZ 0xcc
#define CALLNC 0xd4
#define CALLC 0xdc

#define RST_CYCLES 32

#define RST_0 0xc7
#define RST_8 0xcf
#define RST_10 0xd7
#define RST_18 0xdf
#define RST_20 0xe7
#define RST_28 0xef
#define RST_30 0xf7
#define RST_38 0xff

#define RET_CYCLES 8

#define RET 0xc9
#define RETNZ 0xc0
#define RETZ 0xc8
#define RETNC 0xd0
#define RETC 0xd8

#define RETI 0xd9

#endif // OPCODE_H
