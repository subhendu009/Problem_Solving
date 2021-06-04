/*
Q. The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and 
we need to calculate span of stock’s price for all n days. The span Si of the stock’s price on a given day i is 
defined as the maximum number of consecutive days just before the given day, for which the price of the stock on 
the current day is less than or equal to its price on the given day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for 
corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}

Ans. https://www.youtube.com/watch?v=SHIv9jNOWLE
     https://leetcode.com/problems/online-stock-span/
     https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1#
*/

// Time Complexity : O(n) where n is the length of the array.
// Extra Space : O(n) in worst case, where n is the length of the array.

// From geeksforgeeks:
std::vector<int> calculateSpan(int stockPriceList[], int n)
{
	std::vector<int> stockSpanList;
	
	if((nullptr == stockPriceList) || (n < 1))
	{
		return stockSpanList;
	}

	std::stack<int> priceIndexStack;
	priceIndexStack.push(0);
	
	stockSpanList.reserve(n);
	stockSpanList[0] = 1;
	
	for(int currentIndex = 1; currentIndex < n; ++currentIndex)
	{
		while((priceIndexStack.empty() == false) && 
		      (stockPriceList[priceIndexStack.top()] <= stockPriceList[currentIndex]))
		{
			priceIndexStack.pop();
		}
		
		if(priceIndexStack.empty())
		{
			stockSpanList[currentIndex] = currentIndex + 1;
		}
		else
		{
			stockSpanList[currentIndex] = currentIndex - priceIndexStack.top();
		}
		
		priceIndexStack.push(currentIndex);
	}

	return stockSpanList;
}

///////////////////////////////////////////////////////////////////////////////////////////

class StockSpanner 
{
private:
    std::stack<int> m_dayIndexStack;
    std::vector<int> m_stockPriceList;
    
public:
    StockSpanner() 
    {
        
    }
    
    int next(int price) 
    {   
        m_stockPriceList.push_back(price);
        int stockPriceListSize = m_stockPriceList.size();
        
        while((m_dayIndexStack.empty() == false) && (price >= m_stockPriceList[m_dayIndexStack.top()]))
        {
            m_dayIndexStack.pop();
        }
        
        int stockSpan = stockPriceListSize;
        
        if(m_dayIndexStack.empty() == false)
        {
            stockSpan -= 1 + m_dayIndexStack.top();
        }
        
        m_dayIndexStack.push(stockPriceListSize - 1); 
        return stockSpan;
    }
};

/*
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
*/

