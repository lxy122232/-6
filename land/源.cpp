#include<iostream>
#include<vector>
#include <algorithm>
#include<queue>
using namespace std;
class Solution {
    int m, n;
    int k, x, y, x0, y0;
    vector<int> water;
    queue<vector<int>> q;
    vector<vector<int>> dir = { {1,0},{0,1},{0,-1},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1} };
public:
    vector<int> pondSizes(vector<vector<int>>& land) {
        m = land.size(), n = land[0].size();
        int i, j;
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (land[i][j] == 0)
                {
                    bfs(land, i, j, 0);
                }
            }
        }
        sort(water.begin(), water.end());
        return water;
    }

    void bfs(vector<vector<int>>& land, int i, int j, int count)
    {
        q.push({ i,j });
        land[i][j] = 1;//访问过了
        count++;
        while (!q.empty())
        {
            x0 = q.front()[0];
            y0 = q.front()[1];
            q.pop();
            for (k = 0; k < 8; ++k)
            {
                x = x0 + dir[k][0];
                y = y0 + dir[k][1];
                if (x >= 0 && x < m && y >= 0 && y < n && land[x][y] == 0)
                {
                    count++;
                    q.push({ x,y });
                    land[x][y] = 1;//访问过了
                }
            }
        }
        water.push_back(count);
    }
};
int main()
{
    Solution solution;
    vector<vector<int>> arr = {
        {0, 2, 1, 0} ,
            {0, 1, 0, 1},
            {1, 1, 0, 1},
            {0, 1, 0, 1}
    };
    //string word = "ABCESEEEFS";
    vector<int> temp = solution.pondSizes(arr);
    cout << "[";
    for (int i = 0; i < temp.size(); i++)
    {
        cout << temp[i];
        if (i == temp.size() - 1)
            break;
        cout << ",";
    }
    cout << "]" << endl;
    system("pause");
    return 0;
}
