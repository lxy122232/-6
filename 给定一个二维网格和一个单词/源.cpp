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

		//ʹ��һά�����ʾ��û���߹�
		bool* flag = new bool[board.size() * board[0].size()];
		memset(flag, false, board.size() * board[0].size());
		//�ܹؼ�����ÿ����Ϊ���
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
		//�Ѷ�ά����ӳ�䵽һά����
		int index = i * board[0].size() + j;

		//�߽�����,���������������ܹؼ���
		if (i >= board.size() || i < 0 || j >= board[0].size() || j < 0 || word[k] != board[i][j] || flag[index] == true)
		{
			return false;
		}
		//�����������ܹؼ�������һ����k+1�ǽ�������
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
		//�ǵû���һ��
		flag[index] = false;
		return false;//û�з���true�ͷ���false
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