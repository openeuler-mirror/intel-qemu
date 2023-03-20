/*
 * Tiny Code Generator for QEMU
 *
 * Copyright (c) 2023 Loongarch Technology
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2 or later, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef LOONGARCH_TCG_TARGET_H
#define LOONGARCH_TCG_TARGET_H

/*
 * Loongson removed the (incomplete) 32-bit support from kernel and toolchain
 * for the initial upstreaming of this architecture, so don't bother and just
 * support the LP64* ABI for now.
 */

#if defined(__loongarch64)
#define TCG_TARGET_REG_BITS 64
#else
#error unsupported LoongArch register size
#endif

#define TCG_TARGET_INSN_UNIT_SIZE 4
#define TCG_TARGET_NB_REGS 32
#define MAX_CODE_GEN_BUFFER_SIZE SIZE_MAX

typedef enum {
    TCG_REG_ZERO,
    TCG_REG_RA,
    TCG_REG_TP,
    TCG_REG_SP,
    TCG_REG_A0,
    TCG_REG_A1,
    TCG_REG_A2,
    TCG_REG_A3,
    TCG_REG_A4,
    TCG_REG_A5,
    TCG_REG_A6,
    TCG_REG_A7,
    TCG_REG_T0,
    TCG_REG_T1,
    TCG_REG_T2,
    TCG_REG_T3,
    TCG_REG_T4,
    TCG_REG_T5,
    TCG_REG_T6,
    TCG_REG_T7,
    TCG_REG_T8,
    TCG_REG_RESERVED,
    TCG_REG_S9,
    TCG_REG_S0,
    TCG_REG_S1,
    TCG_REG_S2,
    TCG_REG_S3,
    TCG_REG_S4,
    TCG_REG_S5,
    TCG_REG_S6,
    TCG_REG_S7,
    TCG_REG_S8,

    /* aliases */
    TCG_AREG0 = TCG_REG_S0,
    TCG_REG_TMP0 = TCG_REG_T8,
    TCG_REG_TMP1 = TCG_REG_T7,
    TCG_REG_TMP2 = TCG_REG_T6,
} TCGReg;

/* used for function call generation */
#define TCG_REG_CALL_STACK TCG_REG_SP
#define TCG_TARGET_STACK_ALIGN 16
#define TCG_TARGET_CALL_ALIGN_ARGS 1
#define TCG_TARGET_CALL_STACK_OFFSET 0

/* optional instructions */
#define TCG_TARGET_HAS_movcond_i32 0
#define TCG_TARGET_HAS_div_i32 1
#define TCG_TARGET_HAS_rem_i32 1
#define TCG_TARGET_HAS_div2_i32 0
#define TCG_TARGET_HAS_rot_i32 1
#define TCG_TARGET_HAS_deposit_i32 1
#define TCG_TARGET_HAS_extract_i32 1
#define TCG_TARGET_HAS_sextract_i32 0
#define TCG_TARGET_HAS_extract2_i32 0
#define TCG_TARGET_HAS_add2_i32 0
#define TCG_TARGET_HAS_sub2_i32 0
#define TCG_TARGET_HAS_mulu2_i32 0
#define TCG_TARGET_HAS_muls2_i32 0
#define TCG_TARGET_HAS_muluh_i32 1
#define TCG_TARGET_HAS_mulsh_i32 1
#define TCG_TARGET_HAS_ext8s_i32 1
#define TCG_TARGET_HAS_ext16s_i32 1
#define TCG_TARGET_HAS_ext8u_i32 1
#define TCG_TARGET_HAS_ext16u_i32 1
#define TCG_TARGET_HAS_bswap16_i32 1
#define TCG_TARGET_HAS_bswap32_i32 1
#define TCG_TARGET_HAS_not_i32 1
#define TCG_TARGET_HAS_neg_i32 0
#define TCG_TARGET_HAS_andc_i32 1
#define TCG_TARGET_HAS_orc_i32 1
#define TCG_TARGET_HAS_eqv_i32 0
#define TCG_TARGET_HAS_nand_i32 0
#define TCG_TARGET_HAS_nor_i32 1
#define TCG_TARGET_HAS_clz_i32 1
#define TCG_TARGET_HAS_ctz_i32 1
#define TCG_TARGET_HAS_ctpop_i32 0
#define TCG_TARGET_HAS_direct_jump 0
#define TCG_TARGET_HAS_brcond2 0
#define TCG_TARGET_HAS_setcond2 0
#define TCG_TARGET_HAS_qemu_st8_i32 0

/* 64-bit operations */
#define TCG_TARGET_HAS_movcond_i64 0
#define TCG_TARGET_HAS_div_i64 1
#define TCG_TARGET_HAS_rem_i64 1
#define TCG_TARGET_HAS_div2_i64 0
#define TCG_TARGET_HAS_rot_i64 1
#define TCG_TARGET_HAS_deposit_i64 1
#define TCG_TARGET_HAS_extract_i64 1
#define TCG_TARGET_HAS_sextract_i64 0
#define TCG_TARGET_HAS_extract2_i64 0
#define TCG_TARGET_HAS_extrl_i64_i32 1
#define TCG_TARGET_HAS_extrh_i64_i32 1
#define TCG_TARGET_HAS_ext8s_i64 1
#define TCG_TARGET_HAS_ext16s_i64 1
#define TCG_TARGET_HAS_ext32s_i64 1
#define TCG_TARGET_HAS_ext8u_i64 1
#define TCG_TARGET_HAS_ext16u_i64 1
#define TCG_TARGET_HAS_ext32u_i64 1
#define TCG_TARGET_HAS_bswap16_i64 1
#define TCG_TARGET_HAS_bswap32_i64 1
#define TCG_TARGET_HAS_bswap64_i64 1
#define TCG_TARGET_HAS_not_i64 1
#define TCG_TARGET_HAS_neg_i64 0
#define TCG_TARGET_HAS_andc_i64 1
#define TCG_TARGET_HAS_orc_i64 1
#define TCG_TARGET_HAS_eqv_i64 0
#define TCG_TARGET_HAS_nand_i64 0
#define TCG_TARGET_HAS_nor_i64 1
#define TCG_TARGET_HAS_clz_i64 1
#define TCG_TARGET_HAS_ctz_i64 1
#define TCG_TARGET_HAS_ctpop_i64 0
#define TCG_TARGET_HAS_add2_i64 0
#define TCG_TARGET_HAS_sub2_i64 0
#define TCG_TARGET_HAS_mulu2_i64 0
#define TCG_TARGET_HAS_muls2_i64 0
#define TCG_TARGET_HAS_muluh_i64 1
#define TCG_TARGET_HAS_mulsh_i64 1

/* not defined -- call should be eliminated at compile time */
void tb_target_set_jmp_target(uintptr_t, uintptr_t, uintptr_t, uintptr_t);

#define TCG_TARGET_DEFAULT_MO (0)
#define TCG_TARGET_HAS_MEMORY_BSWAP 0
#define TCG_TARGET_NEED_LDST_LABELS

#endif /* LOONGARCH_TCG_TARGET_H */
