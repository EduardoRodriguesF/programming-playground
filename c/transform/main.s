	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 13, 0	sdk_version 13, 3
	.globl	_to_lowercase                   ; -- Begin function to_lowercase
	.p2align	2
_to_lowercase:                          ; @to_lowercase
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #112
	.cfi_def_cfa_offset 112
	stp	x29, x30, [sp, #96]             ; 16-byte Folded Spill
	add	x29, sp, #96
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	stur	x8, [x29, #-8]
	str	x0, [sp, #48]
	ldr	x0, [sp, #48]
	bl	_strlen
	bl	_malloc
	str	x0, [sp, #40]
	adrp	x8, l___const.to_lowercase.lower@PAGE
	add	x8, x8, l___const.to_lowercase.lower@PAGEOFF
	ldr	x10, [x8]
	sub	x9, x29, #24
	stur	x10, [x29, #-24]
	ldur	x8, [x8, #5]
	stur	x8, [x9, #5]
	adrp	x8, l___const.to_lowercase.upper@PAGE
	add	x8, x8, l___const.to_lowercase.upper@PAGEOFF
	ldr	x10, [x8]
	sub	x9, x29, #40
	stur	x10, [x29, #-40]
	ldur	x8, [x8, #5]
	stur	x8, [x9, #5]
	str	wzr, [sp, #36]
	b	LBB0_1
LBB0_1:                                 ; =>This Loop Header: Depth=1
                                        ;     Child Loop BB0_6 Depth 2
	ldrsw	x8, [sp, #36]
	str	x8, [sp, #16]                   ; 8-byte Folded Spill
	ldr	x0, [sp, #48]
	bl	_strlen
	ldr	x8, [sp, #16]                   ; 8-byte Folded Reload
	subs	x8, x8, x0
	cset	w8, hs
	tbnz	w8, #0, LBB0_16
	b	LBB0_2
LBB0_2:                                 ;   in Loop: Header=BB0_1 Depth=1
	ldr	x8, [sp, #48]
	ldrsw	x9, [sp, #36]
	ldrsb	w8, [x8, x9]
	subs	w8, w8, #65
	cset	w8, lt
	tbnz	w8, #0, LBB0_5
	b	LBB0_3
LBB0_3:                                 ;   in Loop: Header=BB0_1 Depth=1
	ldr	x8, [sp, #48]
	ldrsw	x9, [sp, #36]
	ldrsb	w8, [x8, x9]
	subs	w8, w8, #90
	cset	w8, gt
	tbnz	w8, #0, LBB0_5
	b	LBB0_4
LBB0_4:                                 ;   in Loop: Header=BB0_1 Depth=1
	ldr	x8, [sp, #48]
	ldrsw	x9, [sp, #36]
	ldrsb	w8, [x8, x9]
	add	w8, w8, #32
	ldr	x9, [sp, #40]
	ldrsw	x10, [sp, #36]
	strb	w8, [x9, x10]
	b	LBB0_14
LBB0_5:                                 ;   in Loop: Header=BB0_1 Depth=1
	str	wzr, [sp, #32]
	str	wzr, [sp, #28]
	b	LBB0_6
LBB0_6:                                 ;   Parent Loop BB0_1 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	ldrsw	x8, [sp, #28]
	str	x8, [sp, #8]                    ; 8-byte Folded Spill
	sub	x0, x29, #40
	bl	_strlen
	ldr	x8, [sp, #8]                    ; 8-byte Folded Reload
	subs	x8, x8, x0
	cset	w8, hs
	tbnz	w8, #0, LBB0_11
	b	LBB0_7
LBB0_7:                                 ;   in Loop: Header=BB0_6 Depth=2
	ldrsw	x9, [sp, #28]
	sub	x8, x29, #40
	ldrsb	w8, [x8, x9]
	ldr	x9, [sp, #48]
	ldrsw	x10, [sp, #36]
	ldrsb	w9, [x9, x10]
	subs	w8, w8, w9
	cset	w8, ne
	tbnz	w8, #0, LBB0_9
	b	LBB0_8
LBB0_8:                                 ;   in Loop: Header=BB0_1 Depth=1
	ldrsw	x9, [sp, #28]
	sub	x8, x29, #24
	add	x8, x8, x9
	ldrb	w8, [x8]
	ldr	x9, [sp, #40]
	ldrsw	x10, [sp, #36]
	add	x9, x9, x10
	strb	w8, [x9]
	mov	w8, #1
	str	w8, [sp, #32]
	b	LBB0_11
LBB0_9:                                 ;   in Loop: Header=BB0_6 Depth=2
	b	LBB0_10
LBB0_10:                                ;   in Loop: Header=BB0_6 Depth=2
	ldr	w8, [sp, #28]
	add	w8, w8, #1
	str	w8, [sp, #28]
	b	LBB0_6
LBB0_11:                                ;   in Loop: Header=BB0_1 Depth=1
	ldr	w8, [sp, #32]
	subs	w8, w8, #0
	cset	w8, ne
	tbnz	w8, #0, LBB0_13
	b	LBB0_12
LBB0_12:                                ;   in Loop: Header=BB0_1 Depth=1
	ldr	x8, [sp, #48]
	ldrsw	x9, [sp, #36]
	add	x8, x8, x9
	ldrb	w8, [x8]
	ldr	x9, [sp, #40]
	ldrsw	x10, [sp, #36]
	add	x9, x9, x10
	strb	w8, [x9]
	b	LBB0_13
LBB0_13:                                ;   in Loop: Header=BB0_1 Depth=1
	b	LBB0_14
LBB0_14:                                ;   in Loop: Header=BB0_1 Depth=1
	b	LBB0_15
LBB0_15:                                ;   in Loop: Header=BB0_1 Depth=1
	ldr	w8, [sp, #36]
	add	w8, w8, #1
	str	w8, [sp, #36]
	b	LBB0_1
LBB0_16:
	ldr	x8, [sp, #40]
	str	x8, [sp]                        ; 8-byte Folded Spill
	ldur	x9, [x29, #-8]
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	subs	x8, x8, x9
	cset	w8, eq
	tbnz	w8, #0, LBB0_18
	b	LBB0_17
LBB0_17:
	bl	___stack_chk_fail
LBB0_18:
	ldr	x0, [sp]                        ; 8-byte Folded Reload
	ldp	x29, x30, [sp, #96]             ; 16-byte Folded Reload
	add	sp, sp, #112
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	.cfi_def_cfa_offset 32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	mov	x9, sp
	mov	x8, #195
	str	x8, [x9]
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	mov	w0, #0
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l___const.to_lowercase.lower:           ; @__const.to_lowercase.lower
	.asciz	"\303\240\303\241\303\242\303\244\303\243\303\247"

l___const.to_lowercase.upper:           ; @__const.to_lowercase.upper
	.asciz	"\303\200\303\201\303\202\303\204\303\203\303\207"

l_.str:                                 ; @.str
	.asciz	"%c\n"

.subsections_via_symbols
