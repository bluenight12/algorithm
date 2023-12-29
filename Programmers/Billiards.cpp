#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <limits.h>
using namespace std;

#define min(x,y) x > y ? y : x;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    for(auto ball : balls){
        int destX = ball[0];
        int destY = ball[1];
        
        int sumX = startX + destX;
        int sumY = startY + destY;
        int result = INT_MAX - 1;
        if(startX != destX){
            if(sumY >= n){
                result = pow(startX-destX,2) + pow((n-startY) + (n-destY),2);
            }
            else{
                result = pow(startX-destX,2) + pow(startY + destY,2);
            }
        }
        else{
            if(destY > startY){
                result = min(pow(destY + startY,2) , result);
            }else{
                result = min(pow(n-destY + n-startY,2),result);
            }
        }
        if(startY != destY){
            if(sumX >= m){
                result = min(pow((m-startX) +(m-destX),2) + pow(startY-destY,2),result);
            }
            else{
                result = min(pow(startX+destX,2) + pow(startY-destY,2),result);
            }
        }else{
            if(destX > startX){
                result = min(pow(destX + startX,2), result);
            }else{
                result = min(pow(m-destX + m-startX,2), result);
            }
        }
        
        
        answer.push_back(result);
    }
    return answer;
}