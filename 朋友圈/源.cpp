#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        vector<int> visited(M.size(), 0);
        int count = 0;
        for (int i = 0; i < M.size(); i++)
        {
            if (visited[i] == 0)
            {
                visited[i] = 1;
                findFreinds(M, visited, i);
                count += 1;
            }
        }
        return count;
    }
    void findFreinds(vector<vector<int>>& M, vector<int>& visited, int index)
    {
        for (int i = 0; i < M.size(); i++)
        {
            if (visited[i] == 1 || M[index][i] == 0)
                continue;
            //freinds.insert(i);
            visited[i] = 1;
            findFreinds(M, visited, i);
        }
    }
};
int main()
{
    Solution solution;
    vector<vector<int>> arr = { {1, 1, 0} ,{1, 1, 0},{0, 0, 1} };
    //string word = "ABCESEEEFS";
    int temp = solution.findCircleNum(arr);
    cout << temp << endl;
    system("pause");
    return 0;
}
