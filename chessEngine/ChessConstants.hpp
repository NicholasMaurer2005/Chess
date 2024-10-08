#pragma once

#include <cstdint>
#include <string>
#include <array>
#include <string_view>
#include <cstddef>

using namespace std::literals::string_view_literals;

constexpr std::uint64_t single_bit = 1;
constexpr std::size_t RANK_MAX									 = 8;
constexpr std::size_t FILE_MAX									 = 8;
constexpr std::size_t MAX_BOARD_POSITIONS = FILE_MAX * RANK_MAX; //64
constexpr std::size_t WHITE_COLOR								 = 0;
constexpr std::size_t BLACK_COLOR								 = 1;
constexpr std::size_t MAX_COLORS								 = 2;
constexpr std::size_t MAGIC_ITERATION_COUNT						 = 1000000;
constexpr std::size_t MAX_BISHOP_ATTACKS						 = 512;
constexpr std::size_t MAX_ROOK_ATTACKS							 = 4096;
constexpr std::size_t PIECE_COUNT							     = 12;
constexpr std::size_t MAX_MOVELIST_COUNT                         = 256;
constexpr std::uint32_t MAX_MINIMAX_DEPTH                        = 5;

constexpr bool USING_PREGENERATED_MAGICS = true;
constexpr bool PRINT_GENERATED_MAGICS = false;

const std::string start_position_fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";
const std::string tricky_position_fen = "r3k2r/p11pqpb1/bn2pnp1/2pPN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R";

constexpr std::array<std::size_t, 128> create_char_to_piece()
{
	std::array< std::size_t, 128> table = { 0 };
	table['P'] = 0;
	table['N'] = 1;
	table['K'] = 2;
	table['B'] = 3;
	table['R'] = 4;
	table['Q'] = 5;
	table['p'] = 6;
	table['n'] = 7;
	table['k'] = 8;
	table['b'] = 9;
	table['r'] = 10;
	table['q'] = 11;
	return table;
}

constexpr std::array<std::size_t, 128> char_to_piece = create_char_to_piece();

constexpr std::array<char, PIECE_COUNT> piece_to_char = { 'P', 'N', 'K', 'B', 'R', 'Q', 'X', 'n', 'k', 'b', 'r', 'q' };

constexpr std::array<std::string_view, 64> index_to_rf = {
		"a8"sv, "b8"sv, "c8"sv, "d8"sv, "e8"sv, "f8"sv, "g8"sv, "h8"sv,
		"a7"sv, "b7"sv, "c7"sv, "d7"sv, "e7"sv, "f7"sv, "g7"sv, "h7"sv,
		"a6"sv, "b6"sv, "c6"sv, "d6"sv, "e6"sv, "f6"sv, "g6"sv, "h6"sv,
		"a5"sv, "b5"sv, "c5"sv, "d5"sv, "e5"sv, "f5"sv, "g5"sv, "h5"sv,
		"a4"sv, "b4"sv, "c4"sv, "d4"sv, "e4"sv, "f4"sv, "g4"sv, "h4"sv,
		"a3"sv, "b3"sv, "c3"sv, "d3"sv, "e3"sv, "f3"sv, "g3"sv, "h3"sv,
		"a2"sv, "b2"sv, "c2"sv, "d2"sv, "e2"sv, "f2"sv, "g2"sv, "h2"sv,
		"a1"sv, "b1"sv, "c1"sv, "d1"sv, "e1"sv, "f1"sv, "g1"sv, "h1"sv,
};

constexpr std::array<std::uint8_t, MAX_BOARD_POSITIONS> castling_rights = {
	 7, 15, 15, 15,  3, 15, 15, 11,
	15, 15, 15, 15, 15, 15, 15, 15,
	15, 15, 15, 15, 15, 15, 15, 15,
	15, 15, 15, 15, 15, 15, 15, 15,
	15, 15, 15, 15, 15, 15, 15, 15,
	15, 15, 15, 15, 15, 15, 15, 15,
	15, 15, 15, 15, 15, 15, 15, 15,
	13, 15, 15, 15, 12, 15, 15, 14
};

constexpr std::array<int, PIECE_COUNT> piece_value = {
	100, //white pawn
	300, //white knight
	0,   //white king
	300, //white bishop
	500, //white rook
	900, //white queen
	-100, //black pawn
	-300, //black knight
	-0,   //black king
	-300, //black bishop
	-500, //black rook
	-900, //black queen
};

enum Castle {
	WK = 0b0001,
	WQ = 0b0010, 
	BK = 0b0100,
	BQ = 0b1000
};

enum Color {
	WHITE = 0,
	BLACK = 1
};

enum Piece {
	PAWN = 0,
	KNIGHT = 1,
	KING = 2,
	BISHOP = 3,
	ROOK = 4,
	QUEEN = 5,
	BPAWN = 6,
	BKNIGHT = 7,
	BKING = 8,
	BBISHOP = 9,
	BROOK = 10,
	BQUEEN = 11
};

enum Occupancy {
	WHITEOCC = 0,
	BLACKOCC = 1,
	BOTH = 2,
};

enum RF {
	a8, b8, c8, d8, e8, f8, g8, h8,
	a7, b7, c7, d7, e7, f7, g7, h7,
	a6, b6, c6, d6, e6, f6, g6, h6,
	a5, b5, c5, d5, e5, f5, g5, h5,
	a4, b4, c4, d4, e4, f4, g4, h4,
	a3, b3, c3, d3, e3, f3, g3, h3,
	a2, b2, c2, d2, e2, f2, g2, h2,
	a1, b1, c1, d1, e1, f1, g1, h1, no_sqr
};

enum MoveType {
	QUIET,
	CAPTURE,
	QUIET_PROMOTE,
	PROMOTE,
	ENPASSANT,
	DOUBLE_PAWN
};