fn_names = ["NOP", "LD_BC_d16", "LD_mBC_A", "INC_BC", "INC_B", "DEC_B", "LD_B_d8", "RLCA", "LD_ma16_SP", "ADD_HL_BC", "LD_A_mBC", "DEC_BC", "INC_C", "DEC_C", "LD_C_d8", "RRCA", "STOP_0", "LD_DE_d16", "LD_mDE_A", "INC_DE", "INC_D", "DEC_D", "LD_D_d8", "RLA", "JR_r8", "ADD_HL_DE", "LD_A_mDE", "DEC_DE", "INC_E", "DEC_E", "LD_E_d8", "RRA", "JR_NZ_r8", "LD_HL_d16", "LD_mHLI_A", "INC_HL", "INC_H", "DEC_H", "LD_H_d8", "DAA", "JR_Z_r8", "ADD_HL_HL", "LD_A_mHLI", "DEC_HL", "INC_L", "DEC_L", "LD_L_d8", "CPL", "JR_NC_r8", "LD_SP_d16", "LD_mHLD_A", "INC_SP", "INC_mHL", "DEC_mHL", "LD_mHL_d8", "SCF", "JR_C_r8", "ADD_HL_SP", "LD_A_mHLD", "DEC_SP", "INC_A", "DEC_A", "LD_A_d8", "CCF", "LD_B_B", "LD_B_C", "LD_B_D", "LD_B_E", "LD_B_H", "LD_B_L", "LD_B_mHL", "LD_B_A", "LD_C_B", "LD_C_C", "LD_C_D", "LD_C_E", "LD_C_H", "LD_C_L", "LD_C_mHL", "LD_C_A", "LD_D_B", "LD_D_C", "LD_D_D", "LD_D_E", "LD_D_H", "LD_D_L", "LD_D_mHL", "LD_D_A", "LD_E_B", "LD_E_C", "LD_E_D", "LD_E_E", "LD_E_H", "LD_E_L", "LD_E_mHL", "LD_E_A", "LD_H_B", "LD_H_C", "LD_H_D", "LD_H_E", "LD_H_H", "LD_H_L", "LD_H_mHL", "LD_H_A", "LD_L_B", "LD_L_C", "LD_L_D", "LD_L_E", "LD_L_H", "LD_L_L", "LD_L_mHL", "LD_L_A", "LD_mHL_B", "LD_mHL_C", "LD_mHL_D", "LD_mHL_E", "LD_mHL_H", "LD_mHL_L", "HALT", "LD_mHL_A", "LD_A_B", "LD_A_C", "LD_A_D", "LD_A_E", "LD_A_H", "LD_A_L", "LD_A_mHL", "LD_A_A", "ADD_A_B", "ADD_A_C", "ADD_A_D", "ADD_A_E", "ADD_A_H", "ADD_A_L", "ADD_A_mHL", "ADD_A_A", "ADC_A_B", "ADC_A_C", "ADC_A_D", "ADC_A_E", "ADC_A_H", "ADC_A_L", "ADC_A_mHL", "ADC_A_A", "SUB_B", "SUB_C", "SUB_D", "SUB_E", "SUB_H", "SUB_L", "SUB_mHL", "SUB_A", "SBC_A_B", "SBC_A_C", "SBC_A_D", "SBC_A_E", "SBC_A_H", "SBC_A_L", "SBC_A_mHL", "SBC_A_A", "AND_B", "AND_C", "AND_D", "AND_E", "AND_H", "AND_L", "AND_mHL", "AND_A", "XOR_B", "XOR_C", "XOR_D", "XOR_E", "XOR_H", "XOR_L", "XOR_mHL", "XOR_A", "OR_B", "OR_C", "OR_D", "OR_E", "OR_H", "OR_L", "OR_mHL", "OR_A", "CP_B", "CP_C", "CP_D", "CP_E", "CP_H", "CP_L", "CP_mHL", "CP_A", "RET_NZ", "POP_BC", "JP_NZ_a16", "JP_a16", "CALL_NZ_a16", "PUSH_BC", "ADD_A_d8", "RST_00H", "RET_Z", "RET", "JP_Z_a16", "PREFIX_CB", "CALL_Z_a16", "CALL_a16", "ADC_A_d8", "RST_08H", "RET_NC", "POP_DE", "JP_NC_a16", "CALL_NC_a16", "PUSH_DE", "SUB_d8", "RST_10H", "RET_C", "RETI", "JP_C_a16", "CALL_C_a16", "SBC_A_d8", "RST_18H", "LDH_ma8_A", "POP_HL", "LD_mC_A", "PUSH_HL", "AND_d8", "RST_20H", "ADD_SP_r8", "JP_mHL", "LD_ma16_A", "XOR_d8", "RST_28H", "LDH_A_ma8", "POP_AF", "LD_A_mC", "DI", "PUSH_AF", "OR_d8", "RST_30H", "LD_HL_SP_plus_r8", "LD_SP_HL", "LD_A_ma16", "EI", "CP_d8", "RST_38H", "RLC_B", "RLC_C", "RLC_D", "RLC_E", "RLC_H", "RLC_L", "RLC_mHL", "RLC_A", "RRC_B", "RRC_C", "RRC_D", "RRC_E", "RRC_H", "RRC_L", "RRC_mHL", "RRC_A", "RL_B", "RL_C", "RL_D", "RL_E", "RL_H", "RL_L", "RL_mHL", "RL_A", "RR_B", "RR_C", "RR_D", "RR_E", "RR_H", "RR_L", "RR_mHL", "RR_A", "SLA_B", "SLA_C", "SLA_D", "SLA_E", "SLA_H", "SLA_L", "SLA_mHL", "SLA_A", "SRA_B", "SRA_C", "SRA_D", "SRA_E", "SRA_H", "SRA_L", "SRA_mHL", "SRA_A", "SWAP_B", "SWAP_C", "SWAP_D", "SWAP_E", "SWAP_H", "SWAP_L", "SWAP_mHL", "SWAP_A", "SRL_B", "SRL_C", "SRL_D", "SRL_E", "SRL_H", "SRL_L", "SRL_mHL", "SRL_A", "BIT_0_B", "BIT_0_C", "BIT_0_D", "BIT_0_E", "BIT_0_H", "BIT_0_L", "BIT_0_mHL", "BIT_0_A", "BIT_1_B", "BIT_1_C", "BIT_1_D", "BIT_1_E", "BIT_1_H", "BIT_1_L", "BIT_1_mHL", "BIT_1_A", "BIT_2_B", "BIT_2_C", "BIT_2_D", "BIT_2_E", "BIT_2_H", "BIT_2_L", "BIT_2_mHL", "BIT_2_A", "BIT_3_B", "BIT_3_C", "BIT_3_D", "BIT_3_E", "BIT_3_H", "BIT_3_L", "BIT_3_mHL", "BIT_3_A", "BIT_4_B", "BIT_4_C", "BIT_4_D", "BIT_4_E", "BIT_4_H", "BIT_4_L", "BIT_4_mHL", "BIT_4_A", "BIT_5_B", "BIT_5_C", "BIT_5_D", "BIT_5_E", "BIT_5_H", "BIT_5_L", "BIT_5_mHL", "BIT_5_A", "BIT_6_B", "BIT_6_C", "BIT_6_D", "BIT_6_E", "BIT_6_H", "BIT_6_L", "BIT_6_mHL", "BIT_6_A", "BIT_7_B", "BIT_7_C", "BIT_7_D", "BIT_7_E", "BIT_7_H", "BIT_7_L", "BIT_7_mHL", "BIT_7_A", "RES_0_B", "RES_0_C", "RES_0_D", "RES_0_E", "RES_0_H", "RES_0_L", "RES_0_mHL", "RES_0_A", "RES_1_B", "RES_1_C", "RES_1_D", "RES_1_E", "RES_1_H", "RES_1_L", "RES_1_mHL", "RES_1_A", "RES_2_B", "RES_2_C", "RES_2_D", "RES_2_E", "RES_2_H", "RES_2_L", "RES_2_mHL", "RES_2_A", "RES_3_B", "RES_3_C", "RES_3_D", "RES_3_E", "RES_3_H", "RES_3_L", "RES_3_mHL", "RES_3_A", "RES_4_B", "RES_4_C", "RES_4_D", "RES_4_E", "RES_4_H", "RES_4_L", "RES_4_mHL", "RES_4_A", "RES_5_B", "RES_5_C", "RES_5_D", "RES_5_E", "RES_5_H", "RES_5_L", "RES_5_mHL", "RES_5_A", "RES_6_B", "RES_6_C", "RES_6_D", "RES_6_E", "RES_6_H", "RES_6_L", "RES_6_mHL", "RES_6_A", "RES_7_B", "RES_7_C", "RES_7_D", "RES_7_E", "RES_7_H", "RES_7_L", "RES_7_mHL", "RES_7_A", "SET_0_B", "SET_0_C", "SET_0_D", "SET_0_E", "SET_0_H", "SET_0_L", "SET_0_mHL", "SET_0_A", "SET_1_B", "SET_1_C", "SET_1_D", "SET_1_E", "SET_1_H", "SET_1_L", "SET_1_mHL", "SET_1_A", "SET_2_B", "SET_2_C", "SET_2_D", "SET_2_E", "SET_2_H", "SET_2_L", "SET_2_mHL", "SET_2_A", "SET_3_B", "SET_3_C", "SET_3_D", "SET_3_E", "SET_3_H", "SET_3_L", "SET_3_mHL", "SET_3_A", "SET_4_B", "SET_4_C", "SET_4_D", "SET_4_E", "SET_4_H", "SET_4_L", "SET_4_mHL", "SET_4_A", "SET_5_B", "SET_5_C", "SET_5_D", "SET_5_E", "SET_5_H", "SET_5_L", "SET_5_mHL", "SET_5_A", "SET_6_B", "SET_6_C", "SET_6_D", "SET_6_E", "SET_6_H", "SET_6_L", "SET_6_mHL", "SET_6_A", "SET_7_B", "SET_7_C", "SET_7_D", "SET_7_E", "SET_7_H", "SET_7_L", "SET_7_mHL", "SET_7_A"]

defs = []

def section(name, defs, &block)
	defs << "// =============================================="
	defs << "// #{name}"
	defs << "// ==============================================\n"
	block.call
end

section("This file is automatically generated. Don't look at it.", defs) {}

defs += [
	'#define op(name) void name(struct CPU *cpu, byte d8, ibyte r8, word d16)',
	'#define reg(name) (cpu->name)',
	'#define zero(bit) reg(F.Z) = (bit)',
	'#define subtract(bit) reg(F.S) = (bit)',
	'#define halfcarry(bit) reg(F.H) = (bit)',
	'#define carry(bit) reg(F.C) = (bit)',
	'#define ld(left, right, lexp, rexp) op(LD_##left##_##right) { (lexp) = (rexp); }',
]

def implement(fn_name, code_lines)
	"op(#{fn_name}) {\n\t" + code_lines.join("\n\t") + "\n}\n"
end

BYTE_REGISTERS = %w(B C D E H L A)
BYTE_REGISTERS_M = %w(B C D E H L M A)
WORD_REGISTERS_SP = %w(BC DE HL SP)
WORD_REGISTERS_AF = %w(BC DE HL AF)

# Generate defs

section('Miscellaneous', defs) do
	defs << implement('NOP', ['// :)'])
	defs << implement('EI', ['reg(interrupts) = true;'])
	defs << implement('DI', ['reg(interrupts) = false;'])
	defs << implement('HALT', ['reg(halted) = true;'])
	defs << implement('STOP_0', ['reg(halted) = true;'])
	defs << implement('RETI', ['reg(interrupts) = true; reg(PC) = gbPop16(cpu) - 1;'])
	defs << implement('PREFIX_CB', ["puts(\"0xCB was called directly!\");", "exit(1);"])

	# Fun!
	defs << implement('CCF', [
		"reg(F.C) = !reg(F.C);",
		"halfcarry(false);",
		"subtract(false);"
	])

	defs << implement('CPL', [
		"reg(A) = ~reg(A);",
		"halfcarry(true);",
		"subtract(true);"
	])

	defs << implement('SCF', [
		"carry(true);",
		"subtract(false);",
		"halfcarry(false);"
	])

end

section('16-bit immediate load', defs) do
	WORD_REGISTERS_SP.each do |wr|
		defs << "ld(#{wr}, d16, reg(#{wr}), d16); // LD_#{wr}_d16"
	end

	defs << implement("LD_ma16_A", ["writeByte(d16, reg(A));"])
end

section('16-bit increment', defs) do
	[['INC', '++'], ['DEC', '--']].each do |(type, expr)|
		WORD_REGISTERS_SP.each do |wr|
			defs << implement("#{type}_#{wr}", ["reg(#{wr})#{expr};"])
		end
	end
end

section('8-bit increment', defs) do
	footer = lambda { |arg| ["zero(#{arg} == 0);"] }

	inc = lambda do |arg|
		[
			"halfcarry((((#{arg} & 0xF) + 1) & 0x10) != 0);",
			"#{arg}++;",
		]
	end

	dec = lambda do |arg|
		[
			"halfcarry((((#{arg} & 0xF) - 1) & 0x10) != 0);",
			"#{arg}--;",
		]
	end

	BYTE_REGISTERS.each do |br|
		defs << implement("INC_#{br}", ["subtract(false);"] + inc["reg(#{br})"] + footer["reg(#{br})"])
		defs << implement("DEC_#{br}", ["subtract(true);"] + dec["reg(#{br})"] + footer["reg(#{br})"])
	end

	defs << implement("INC_mHL",
		["subtract(false);"] +
		["halfcarry((readByte(((reg(HL)) & 0xF) + 1) & 0x10) != 0);",
			"writeByte(reg(HL), readByte(reg(HL)) + 1);"] +
		footer["readByte(reg(HL))"])

	defs << implement("DEC_mHL",
		["subtract(true);"] +
		["halfcarry((readByte(((reg(HL)) & 0xF) - 1) & 0x10) != 0);",
			"writeByte(reg(HL), readByte(reg(HL)) - 1);"] +
		footer["readByte(reg(HL))"])
end

section('16-bit push/pop', defs) do
	WORD_REGISTERS_AF.each do |wr|
		defs << implement("PUSH_#{wr}", ["gbPush16(cpu, reg(#{wr}));"])
	end

	WORD_REGISTERS_AF.each do |wr|
		defs << implement("POP_#{wr}", ["reg(#{wr}) = gbPop16(cpu);"])
	end
end

section('ADD', defs) do

	add = lambda do |reg, arg|
		[
			"carry((word)#{reg} + #{arg} > 0xFF);",
			"halfcarry((#{reg} & 0xF) + #{arg} > 0xF);",
			"subtract(false);",
			"#{reg} += #{arg};",
			"zero(#{reg} == 0);"
		]
	end

	BYTE_REGISTERS.each do |br|
		defs << implement("ADD_A_#{br}", add["reg(A)", "reg(#{br})"])
		defs << implement("ADC_A_#{br}", add["reg(A)", "(reg(#{br}) + (reg(F.C) ? 1 : 0))"])
	end

	defs << implement("ADD_A_d8", add["reg(A)", "d8"])
	defs << implement("ADC_A_d8", add["reg(A)", "(d8 + (reg(F.C) ? 1 : 0))"])
	defs << implement("ADD_A_mHL", add["reg(A)", "readByte(reg(HL))"])
	defs << implement("ADC_A_mHL", add["reg(A)", "(readByte(reg(HL)) + (reg(F.C) ? 1 : 0))"])
	defs << implement("ADD_SP_r8", add["reg(SP)", "(r8)"])
end

section('SUB', defs) do
  sub = lambda do |reg, arg|
    [
      "carry(#{reg} < #{arg});",
      "halfcarry((#{reg} & 0xF) < (#{arg} & 0xF));",
      "subtract(true);",
			"#{reg} -= #{arg};",
			"zero(#{reg} == 0);"
    ]
  end

  BYTE_REGISTERS.each do |br|
    defs << implement("SUB_#{br}", sub["reg(A)", "reg(#{br})"])
  end

  defs << implement('SUB_d8', sub['reg(A)', 'd8'])
  defs << implement('SUB_mHL', ["byte br = readByte(reg(HL));"] + sub["reg(A)", "br"])
end

section('XOR and OR', defs) do

	footer = ['zero(reg(A) == 0);', 'subtract(false);', 'halfcarry(false);', 'carry(false);']

	[['XOR', '^'], ['OR', '|']].each do |(fn, symbol)|
		BYTE_REGISTERS.each do |br|
			defs << implement("#{fn}_#{br}", ["reg(A) #{symbol}= reg(#{br});"] + footer)
		end
	end

	defs << implement('XOR_d8', ['reg(A) ^= d8;'] + footer)
	defs << implement('OR_d8', ['reg(A) |= d8;'] + footer)
	defs << implement('XOR_mHL', ['reg(A) ^= readByte(reg(HL));'] + footer)
	defs << implement('OR_mHL', ['reg(A) |= readByte(reg(HL));'] + footer)
end

section('AND', defs) do

	footer = ['zero(reg(A) == 0);', 'subtract(false);', 'halfcarry(true);', 'carry(false);']

	BYTE_REGISTERS.each do |br|
		defs << implement("AND_#{br}", ["reg(A) &= reg(#{br});"] + footer)
	end

	defs << implement('AND_d8', ['reg(A) &= d8;'] + footer)
	defs << implement('AND_mHL', ['reg(A) &= readByte(reg(HL));'] + footer)
end

section('store A, indirect', defs) do
	%w(BC DE).each do |wr|
		defs << implement("LD_m#{wr}_A", ["writeByte(reg(#{wr}), reg(A));"])
	end

	defs << implement("LD_mHLD_A", ["writeByte(reg(HL)--, reg(A));"])
	defs << implement("LD_mHLI_A", ["writeByte(reg(HL)++, reg(A));"])
end

section('8-bit load', defs) do
	BYTE_REGISTERS_M.each do |l|
		BYTE_REGISTERS_M.each do |r|
			if l == r && l == 'M'
				next
			elsif l == 'M'
				defs << implement("LD_mHL_#{r}", ["writeByte(reg(HL), reg(#{r}));"])
			elsif r == 'M'
				defs << implement("LD_#{l}_mHL", ["reg(#{l}) = readByte(reg(HL));"])
			else
				defs << implement("LD_#{l}_#{r}", ["reg(#{l}) = reg(#{r});"])
			end
		end
	end

	defs << implement("LD_mC_A", ["writeByte(0xFF00 + reg(C), reg(A));"])
	defs << implement("LDH_ma8_A", ["writeByte(0xFF00 + d8, reg(A));"])
	defs << implement("LDH_A_ma8", ["reg(A) = readByte(0xFF00 + d8);"])
	defs << implement("LD_A_mDE", ["reg(A) = readByte(reg(DE));"])
end

section('RL', defs) do

	rl = lambda do |br|
		[
			"halfcarry(false); subtract(false);",
			"byte newCarry = reg(#{br}) >> 7;",
			"reg(#{br}) <<= 1;",
			"zero((reg(#{br})) == 0);",
			"carry(newCarry == 1);"
		]
	end

	BYTE_REGISTERS.each do |br|
		defs << implement("RL_#{br}", rl[br])
	end

	defs << implement("RLA", [
		"halfcarry(false); subtract(false); zero(false);",
		"byte newCarry = reg(A) >> 7;",
		"reg(A) <<= 1;",
		"carry(newCarry == 1);"
	])

	defs << implement("RL_mHL", [
		"byte br = readByte(reg(HL));",
		"halfcarry(false); subtract(false);",
		"byte newCarry = br >> 7;",
		"br <<= 1;",
		"zero(br == 0);",
		"carry(newCarry == 1);",
		"writeByte(reg(HL), br);"
	])
end

section('8-bit load immediate', defs) do
	BYTE_REGISTERS.each { |br| defs << implement("LD_#{br}_d8", ["reg(#{br}) = d8;"])}
	defs << implement("LD_mHL_d8", ["writeByte(reg(HL), d8);"])
end

section('call', defs) do
	defs << implement('CALL_a16', ['gbPush16(cpu, reg(PC) + 3);', 'reg(PC) = d16 - 3;'])

	%w(Z C).each do |condition|
		defs << implement("CALL_#{condition}_a16", [
			"if (reg(F.#{condition})) {",
			"\treg(clock) += 12;",
			"\tgbPush16(cpu, reg(PC) + 3);",
			"\treg(PC) = d16 - 3;",
			"}"
		])

		defs << implement("CALL_N#{condition}_a16", [
			"if (!reg(F.#{condition})) {",
			"\treg(clock) += 12;",
			"\tgbPush16(cpu, reg(PC) + 3);",
			"\treg(PC) = d16 - 3;",
			"}"
		])
	end
end

section('swap', defs) do
	defs << implement('SWAP_mHL', ['writeByte(reg(HL), ~readByte(reg(HL)));'])

	BYTE_REGISTERS.each do |br|
		defs << implement("SWAP_#{br}", ["reg(#{br}) = ~reg(#{br});"])
	end
end

section('jump', defs) do
	defs << implement('JP_a16', ['reg(PC) = d16 - 3;'])
	defs << implement('JP_mHL', ['reg(PC) = readByte(reg(HL)) - 1;'])

	%w(Z C).each do |condition|
		defs << implement("JP_#{condition}_a16", [
			"if (reg(F.#{condition})) {",
			"\treg(clock) += 4;",
			"\treg(PC) = d16 - 3;",
			"}"
		])

		defs << implement("JP_N#{condition}_a16", [
			"if (!reg(F.#{condition})) {",
			"\treg(clock) += 4;",
			"\treg(PC) = d16 - 3;",
			"}"
		])
	end
end

section('jump relative', defs) do
	defs << implement('JR_r8', ['reg(PC) += r8;'])

	%w(Z C).each do |condition|
		defs << implement("JR_#{condition}_r8", [
			"if (reg(F.#{condition})) {",
			"\treg(clock) += 4;",
			"\treg(PC) += r8;",
			"}"
		])

		defs << implement("JR_N#{condition}_r8", [
			"if (!reg(F.#{condition})) {",
			"\treg(clock) += 4;",
			"\treg(PC) += r8;",
			"}"
		])
	end
end

section('return', defs) do
	defs << implement('RET', ['reg(PC) = gbPop16(cpu) - 1;'])

	%w(Z C).each do |condition|
		defs << implement("RET_#{condition}", [
			"if (reg(F.#{condition})) {",
			"\treg(clock) += 12;",
			"\treg(PC) = gbPop16(cpu) - 1;",
			"}"
		])

		defs << implement("RET_N#{condition}", [
			"if (!reg(F.#{condition})) {",
			"\treg(clock) += 12;",
			"\treg(PC) = gbPop16(cpu) - 1;",
			"}"
		])
	end
end

section('CP', defs) do
	cp = lambda do |arg|
		[
			"zero(reg(A) == #{arg});",
			"subtract(true);",
			"carry(reg(A) < #{arg});",
			"halfcarry((((reg(A) & 0xF) - (#{arg} & 0xF)) & 0x10) != 0);"
		]
	end

	BYTE_REGISTERS.each { |br| defs << implement("CP_#{br}", cp["reg(#{br})"]) }
	defs << implement("CP_d8", cp["d8"])
	defs << implement("CP_mHL", cp["readByte(reg(HL))"])
end

section('Bit-based ops', defs) do
	%w(BIT RES SET).each do |op|
		(0..7).each do |bit|
			BYTE_REGISTERS.each do |br|
				case op
				when 'BIT'
					defs << implement("#{op}_#{bit}_#{br}", [
							"zero(((reg(#{br}) >> #{bit}) & 1) == 0);",
							"subtract(false);",
							"halfcarry(false);"
						])
				when 'RES'
					defs << implement("#{op}_#{bit}_#{br}", ["reg(#{br}) &= ~(1 << #{bit});"])
				when 'SET'
					defs << implement("#{op}_#{bit}_#{br}", ["reg(#{br}) |= (1 << #{bit});"])
				end
			end

			case op
			when 'BIT'
				defs << implement("#{op}_#{bit}_mHL", [
						"zero(((readByte(reg(HL)) >> #{bit}) & 1) == 0);",
						"subtract(false);",
						"halfcarry(false);"
					])
			when 'RES'
				defs << implement("#{op}_#{bit}_mHL", ["writeByte(reg(HL), readByte(reg(HL)) & ~(1 << #{bit}));"])
			when 'SET'
				defs << implement("#{op}_#{bit}_mHL", ["writeByte(reg(HL), readByte(reg(HL)) | (1 << #{bit}));"])
			end

		end
	end
end

section('LD from a word register pointer', defs ) do
	defs << implement("LD_A_mBC", ["reg(A) = readByte(reg(BC));"])
	defs << implement("LD_A_mC", ["reg(A) = readByte(0xFF00 + reg(C));"])
	defs << implement("LD_A_mHLI", ["reg(A) = readByte(reg(HL)++);"])
	defs << implement("LD_A_mHLD", ["reg(A) = readByte(reg(HL)--);"])
	defs << implement("LD_A_ma16", ["reg(A) = readByte(d16);"])
	defs << implement('LD_SP_HL', ["reg(SP) = reg(HL);"])
	defs << implement('LD_ma16_SP', ["writeWord(d16, reg(SP));"])
	defs << implement('LD_HL_SP_plus_r8', [
		'#warning LD HL,(SP+r8) may not set flags correctly',
		"reg(HL) = reg(SP)+r8;",
		"if (r8 > 0) {",
			"halfcarry((((reg(SP) & 0xF) + 1) & 0x10) != 0);",
			"carry(reg(SP) + r8 > 0xFF);",
		"} else if (r8 < 0) {",
			"halfcarry((((reg(SP) & 0xF) - 1) & 0x10) != 0);",
			"carry(reg(SP) < r8);",
		"} else {",
		"	 carry(false); halfcarry(false);",
		"}"
	])
end

section('SBC A', defs) do
	BYTE_REGISTERS.each do |br|
	end

	# mHL, d8
end

section('CP', defs) do
	BYTE_REGISTERS.each do |br|
	end
end

section('SLA', defs) do
	BYTE_REGISTERS_M.each do |br|
	end
end

section('SRA', defs) do
	BYTE_REGISTERS_M.each do |br|
	end
end

section('SRL', defs) do
	BYTE_REGISTERS_M.each do |br|
	end
end

section('RLC', defs) do

	# defs << implement('RLCA', )

	BYTE_REGISTERS_M.each do |br|
	end
end

section('RRC', defs) do

	# defs << implement('RRCA', )

	BYTE_REGISTERS_M.each do |br|
	end
end

section('RR', defs) do

	# defs << implement('RRA', )

	BYTE_REGISTERS_M.each do |br|
	end
end

section('RST', defs) do

  %w(00 08 10 18 20 28 30 38 40 48 50 58 60).each do |isr|
    defs << implement("RST_#{isr}H", [
      'reg(interrupts) = false;',
      'gbPush16(cpu, cpu->PC + 1);',
      "reg(PC) = 0x00#{isr} - 1;"
    ])
  end

end

section('ADD a word register to HL', defs) do
	WORD_REGISTERS_SP.each do |reg|
		defs << implement("ADD_HL_#{reg}",
			["reg(HL) += reg(#{reg});"])
	end
end

section('Stop procrastinating and implement these ops!', defs) do
	source_code = defs.join('')
	fn_names.reject do |f|
		source_code.include? f
	end.sort.each do |f|
		defs << "op(#{f}) { puts(\"Undefined op \\\"#{f}\\\".\"); exit(1); }"
	end
end

#
File.write('opcodes.h', defs.join("\n"))
