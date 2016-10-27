/*************************************************************************
	> File Name: 353_DesignSnakeGame.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Oct 27 00:16:34 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        n = height;
        m = width;
        snake.push_back(pair<int, int>({0, 0}));
        foodSeries = food;
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        if(direction == "U")
            if(snake[0].first == 0)
                return -1;
            else{
                snake.insert(snake.begin(), 1, pair<int, int>({snake[0].first - 1, snake[0].second}));
                if(countFood < foodSeries.size() && snake[0].first == foodSeries[countFood].first && snake[0].second == foodSeries[countFood].second){
                    countFood++;
                } else {
                    snake.erase(prev(snake.end())); 
                }
                if(bitSelf())
                    return -1;
                return countFood;
            }
        if(direction == "R")
            if(snake[0].second == m - 1)
                return -1;
            else{
                snake.insert(snake.begin(), 1, pair<int, int>({snake[0].first, snake[0].second + 1}));
                if(countFood < foodSeries.size() && snake[0].first == foodSeries[countFood].first && snake[0].second == foodSeries[countFood].second){
                    countFood++;
                } else {
                    snake.erase(prev(snake.end()));   
                }
                if(bitSelf())
                    return -1;
                return countFood;
            }
        if(direction == "D")
            if(snake[0].first == n - 1)
                return -1;
            else{
                snake.insert(snake.begin(), 1, pair<int, int>({snake[0].first + 1, snake[0].second}));
                if(countFood < foodSeries.size() && snake[0].first == foodSeries[countFood].first && snake[0].second == foodSeries[countFood].second){
                    countFood++;
                } else {
                    snake.erase(prev(snake.end()));   
                }
                if(bitSelf())
                    return -1;
                return countFood;
            }
        if(direction == "L")
            if(snake[0].second == 0)
                return -1;
            else{
                snake.insert(snake.begin(), 1, pair<int, int>({snake[0].first, snake[0].second - 1}));
                if(countFood < foodSeries.size() && snake[0].first == foodSeries[countFood].first && snake[0].second == foodSeries[countFood].second){
                    countFood++;
                } else {
                    snake.erase(prev(snake.end()));   
                }
                if(bitSelf())
                    return -1;
                return countFood;
            }
        return countFood;
    }
private:
    vector<pair<int, int>> snake;
    vector<vector<bool>> isFood;
    int n, m;
    int countFood = 0;
    vector<pair<int, int>> foodSeries;
    
    bool bitSelf(){
        for(int i = 1; i < snake.size(); i++)  
            if(snake[i].first == snake[0].first && snake[i].second == snake[0].second)
                return true;
        return false;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */
