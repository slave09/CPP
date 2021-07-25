class Solution {
public:
	int maxProfit(vector<int>& prices) {

		int curr_buying_price = prices.front();
		int last_price = curr_buying_price;
		int profit = 0;

		for(int day = 1; day < prices.size(); day++){
			if(prices[day] > last_price){
				last_price = prices[day];
				if(curr_buying_price > last_price)
					curr_buying_price = last_price;
				if(day == prices.size() - 1) 
					profit += (last_price - curr_buying_price);
			}

			else{
				if(last_price)
					profit += (last_price - curr_buying_price);
				curr_buying_price = prices[day];
				last_price = 0;
			}
		}

		return profit;
	}
};

// one pass simple one

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int profit = 0;
		
		for(int day = 1; day < prices.size(); ++day){
			if(prices[day - 1] < prices[day])
				profit += (prices[day] - prices[day -1]);
		}
		
		return profit;
	}
};