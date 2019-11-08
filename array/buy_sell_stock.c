/* buy_sell_stock.c *  Created on: Apr 9, 2018 *      Author: hsahu */

/**
 * Given an array of prices,
 * find the max profit that can be found from a single buy and sell. */

#include <stdio.h>
#include <stdlib.h>
#include "array.h"

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int maxProfit(int* stock, int size) {
	if(size ==0)
		return 0;

    int min_value_so_far = INT_MAX;
	float max_profit = 0;
    int max_profit_if_sell_today;

	for(int price_at = 0; price_at < size; price_at++) {
		max_profit_if_sell_today = stock[price_at] - min_value_so_far;
		max_profit = MAX(max_profit, max_profit_if_sell_today);
		min_value_so_far = MIN(min_value_so_far, stock[price_at]);
    }

	printf("%s: Max_profit = %f\n", __FUNCTION__, max_profit);
	return max_profit;
}

/**
 * Design an algorithm to find the maximum profit. You may complete as many
 * transactions as you like (i.e., buy one and sell one share of the stock multiple times).
 * Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
 *
 * Determine the maximum profit that can be obtained by making the
 * transactions (no limit on the number of transactions done).
 *
 * For this we need to find out those sets of buying and selling prices
 *  which together lead to the maximization of profit.
 *
 */

int max_profit_many(int *price, int length) {
	int maxprofit = 0;
    for (int i = 1; i < length; i++) {
    	if (price[i] > price[i - 1])
    		maxprofit = maxprofit + (price[i] - price[i-1]);
    	}
    printf("%s: Max_profit_many = %d\n", __FUNCTION__, maxprofit);
    return maxprofit;
}
