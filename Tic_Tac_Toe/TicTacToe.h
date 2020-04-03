#ifndef TICTACTOE
#define TICTACTOE

#include <vector>


class TicTacToe {
private:
	std::vector<char> m_board;
	int m_count;
	bool m_isCircle;

	bool isWin(const int idx);
	void reset();
	bool putPieces(const int pos);
	void drawBoard();
public:
	TicTacToe();
	void beginPlay();
	//void test();
};

#endif // !

