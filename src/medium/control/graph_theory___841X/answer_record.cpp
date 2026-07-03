#include "common.h"

// 递归解法
class Solution {
public:
    vector<int> vis;
    int num;

    void dfs(vector<vector<int>>& rooms, int x) {
        vis[x] = true;
        num++;
        for (auto& it : rooms[x]) {
            if (!vis[it]) {
                dfs(rooms, it);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        num = 0;
        vis.resize(n);
        dfs(rooms, 0);
        return num == n;
    }
};
/**
思路与算法
我们可以使用深度优先搜索的方式遍历整张图，统计可以到达的节点个数，并利用数组 vis 标记当前节点是否访问过，以防止重复访问。
*/


/**
// 广度优先搜索解法
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size(), num = 0;
        vector<int> vis(n);
        queue<int> que;
        vis[0] = true;
        que.emplace(0);
        while (!que.empty()) {
            int x = que.front();
            que.pop();
            num++;
            for (auto& it : rooms[x]) {
                if (!vis[it]) {
                    vis[it] = true;
                    que.emplace(it);
                }
            }
        }
        return num == n;
    }
};
*/

/**
思路与算法
我们也可以使用广度优先搜索的方式遍历整张图，统计可以到达的节点个数，并利用数组 vis 标记当前节点是否访问过，以防止重复访问。
*/


int main() {

}

/*
* 
题目：迷宫中离入口最近的出口
有 n 个房间，房间按从 0 到 n - 1 编号。
最初，除 0 号房间外的其余所有房间都被锁住。你的目标是进入所有的房间。
然而，你不能在没有获得钥匙的时候进入锁住的房间。

当你进入一个房间，你可能会在里面找到一套 不同的钥匙，每把钥匙上都有对应的房间号，即表示钥匙可以打开的房间。
你可以拿上所有钥匙去解锁其他房间。

给你一个数组 rooms 其中 rooms[i] 是你进入 i 号房间可以获得的钥匙集合。
如果能进入 所有 房间返回 true，否则返回 false。
*
*/