#include "TicTacToe.h"
#include <vector>
#include <iostream>

TicTacToe::TicTacToe():m_board(9), m_count(0), m_isCircle(true) {
	for (int i = 0; i < 9; ++i)
		m_board[i] = '1' + i;
}

void TicTacToe::drawBoard() {
	for (int row = 0; row < 3; ++row) {
		for (int col = 0; col < 3; ++col) {
			std::cout << m_board[3 * row + col] << " ";
		}
		std::cout << std::endl;
	}
	return;
}

bool TicTacToe::putPieces(const int pos) {
	if (pos <= 0 || pos > 9) {
		std::cout << "Invalid input!" << std::endl;
		return false;
	}
	if (m_board[pos - 1] == 'X' || m_board[pos - 1] == 'O') {
		std::cout << "This place is already placed!" << std::endl;
		return false;
	}
	m_board[pos - 1] = (m_isCircle ? 'O' : 'X');
	m_isCircle = !m_isCircle;
	++m_count;
	return isWin(pos-1);
}

void TicTacToe::reset() {
	for (int i = 0; i < 9; ++i)
		m_board[i] = '1' + i;
	m_count = 0;
	m_isCircle = true;
	return;
}

bool TicTacToe::isWin(const int idx) {
	switch (idx) {
	case 0: return (m_board[idx] == m_board[1] && m_board[idx] == m_board[2]) || (m_board[idx] == m_board[4] && m_board[idx] == m_board[8]) || (m_board[idx] == m_board[3] && m_board[idx] == m_board[6]);
	case 1: return (m_board[idx] == m_board[0] && m_board[idx] == m_board[2]) || (m_board[idx] == m_board[4] && m_board[idx] == m_board[7]);
	case 2: return (m_board[idx] == m_board[0] && m_board[idx] == m_board[1]) || (m_board[idx] == m_board[4] && m_board[idx] == m_board[6]) || (m_board[idx] == m_board[5] && m_board[idx] == m_board[8]);
	case 3: return (m_board[idx] == m_board[0] && m_board[idx] == m_board[6]) || (m_board[idx] == m_board[4] && m_board[idx] == m_board[5]);
	case 4: return (m_board[idx] == m_board[0] && m_board[idx] == m_board[8]) || (m_board[idx] == m_board[3] && m_board[idx] == m_board[5]) || (m_board[idx] == m_board[6] && m_board[idx] == m_board[2]) || (m_board[idx] == m_board[1] && m_board[idx] == m_board[7]);
	case 5: return (m_board[idx] == m_board[3] && m_board[idx] == m_board[4]) || (m_board[idx] == m_board[2] && m_board[idx] == m_board[8]);
	case 6: return (m_board[idx] == m_board[0] && m_board[idx] == m_board[3]) || (m_board[idx] == m_board[4] && m_board[idx] == m_board[2]) || (m_board[idx] == m_board[7] && m_board[idx] == m_board[8]);
	case 7: return (m_board[idx] == m_board[1] && m_board[idx] == m_board[4]) || (m_board[idx] == m_board[6] && m_board[idx] == m_board[8]);
	case 8: return (m_board[idx] == m_board[6] && m_board[idx] == m_board[7]) || (m_board[idx] == m_board[0] && m_board[idx] == m_board[4]) || (m_board[idx] == m_board[2] && m_board[idx] == m_board[5]);
	default: return false;
	}
	return false;
}

void TicTacToe::beginPlay() {
	while (1) {
		while (m_count < 9) {
			drawBoard();
			std::cout << "Player " << (m_isCircle ? "O" : "X") << "'s turn. Please enter where to place the pieces: ";
			int pos;
			std::cin >> pos;
			if (putPieces(pos)) {
				drawBoard();
				std::cout << "Player " << (m_isCircle ? "X" : "O") << " win!" << std::endl;
				break;
			}
			else if (m_count == 9) {
				drawBoard();
				std::cout << "Game draw!" << std::endl;
			}
		}
		std::cout << "One more round? Y/N: ";
		char c;
		std::cin >> c;
		if (c != 'y' && c != 'Y')
			break;
		reset();
	}
	return;
}

//void TicTacToe::test() {
//	drawBoard();
//}