class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {

        int available = numBottles;
        int drink = numBottles;
        int empty = drink;

        while(empty >= numExchange){

            available = empty / numExchange;

            drink += available;

            empty = available + (empty % numExchange);
        }

        return drink;
    }
};