#include "common.h"

class StockSpanner {
public:
    StockSpanner() {

    }
    int next(int price) {
		m_vPrice.push_back(price);
		int curPriceIndex = m_vPrice.size() - 1;

		while (!m_msIndex.empty() && price >= m_vPrice[m_msIndex.top()])
		{
			m_msIndex.pop();
		}

		int stackTopIndex = m_msIndex.empty() ? -1 : m_msIndex.top();
		m_msIndex.push(curPriceIndex);
		return curPriceIndex - stackTopIndex;
    }
public:
	stack<int> m_msIndex;//单调栈存储索引
	vector<int> m_vPrice;//存储价格，实际不必要存储所有价格，用pair保持就行。
};



int main() {
    StockSpanner* obj = new StockSpanner();

	cout << "param_1: " << obj->next(100) << endl;
	cout << "param_2: " << obj->next(80) << endl;
	cout << "param_3: " << obj->next(60) << endl;
	cout << "param_4: " << obj->next(70) << endl;
	cout << "param_5: " << obj->next(60) << endl;
	cout << "param_6: " << obj->next(75) << endl;
	cout << "param_7: " << obj->next(80) << endl;

}
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

/*
* 
* 
设计一个算法收集某些股票的每日报价，并返回该股票当日价格的 跨度 。
当日股票价格的 跨度 被定义为股票价格小于或等于今天价格的最大连续日数（从今天开始往回数，包括今天）。
例如，如果未来 7 天股票的价格是 [100,80,60,70,60,75,85]，那么股票跨度将是 [1,1,1,2,1,4,6] 。

实现 StockSpanner 类：
StockSpanner() 初始化类对象。
int next(int price) 给出今天的股价 price ，返回该股票当日价格的 跨度 。

示例：
输入：
["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
[[], [100], [80], [60], [70], [60], [75], [85]]

输出：
[null, 1, 1, 1, 2, 1, 4, 6]

解释：
StockSpanner stockSpanner = new StockSpanner();
stockSpanner.next(100); // 返回 1
stockSpanner.next(80);  // 返回 1
stockSpanner.next(60);  // 返回 1
stockSpanner.next(70);  // 返回 2
stockSpanner.next(60);  // 返回 1
stockSpanner.next(75);  // 返回 4 ，因为截至今天的最后 4 个股价 (包括今天的股价 75) 都小于或等于今天的股价。
stockSpanner.next(85);  // 返回 6
* 
*/


/*
* 作者：力扣官方题解
class StockSpanner {
public:
    StockSpanner() {
        this->stk.emplace(-1, INT_MAX);
        this->idx = -1;
    }

    int next(int price) {
        idx++;
        while (price >= stk.top().second) {
            stk.pop();
        }
        int ret = idx - stk.top().first;
        stk.emplace(idx, price);
        return ret;
    }

private:
    stack<pair<int, int>> stk;
    int idx;
};
    }
*/