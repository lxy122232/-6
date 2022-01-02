#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <deque>
#include <stack>
#include <algorithm>
#include <map>
#include <assert.h>
#include <memory>
#include<queue>
#include<functional>

using namespace std;

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (board.empty() || board[0].empty() || word.empty())
			return false;

		//使用一维数组表示有没有走过
		bool* flag = new bool[board.size() * board[0].size()];
		memset(flag, false, board.size() * board[0].size());
		//很关键，以每个点为起点
		for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j < board[0].size(); ++j)
			{
				if (back_search(board, word, i, j, flag, 0))
					return true;
			}
		}
		return false;
	}
	bool back_search(vector<vector<char>>& board, string& word, int i, int j, bool* flag, int k)
	{
		//把二维坐标映射到一维坐标
		int index = i * board[0].size() + j;

		//边界条件,及不符合条件（很关键）
		if (i >= board.size() || i < 0 || j >= board[0].size() || j < 0 || word[k] != board[i][j] || flag[index] == true)
		{
			return false;
		}
		//结束条件（很关键，是下一个即k+1是结束符）
		if (word[k + 1] == '\0')
		{
			return true;
		}

		flag[index] = true;

		//all station
		if (back_search(board, word, i + 1, j, flag, k + 1) ||
			back_search(board, word, i - 1, j, flag, k + 1) ||
			back_search(board, word, i, j + 1, flag, k + 1) ||
			back_search(board, word, i, j - 1, flag, k + 1))
		{
			return true;
		}
		//记得回溯一下
		flag[index] = false;
		return false;//没有返回true就返回false
	}
};

int main()
{
	Solution solution;
	vector<vector<char>> arr = { { 'A', 'B', 'C', 'E' },
								{ 'S', 'F', 'E', 'S' },
								{ 'A', 'D', 'E', 'E' } };
	string word = "ABCESEEEFS";
	int temp=solution.exist(arr, word);
	if (temp == 1)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	system("pause");
	return 0;
}