#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>
#include <queue>
#include <stack>
 
#define all(x) x.begin(), x.end()
 
using namespace std;
 
inline double calcLeftBase(double x, double y)  { return x-y; }
inline double calcRightBase(double x, double y) { return x+y; }
inline double calcArea(double y)                { return y*y; }
 
inline double getIntersectionX(double x_base, double x_top, double y_top) {
    return (x_top + y_top - 0 + x_base)/2;
}
inline double getIntersectionY(double x_is, double x_base) { return x_is - x_base; }
 
inline double isInsideBigTriangle(double x_baseTop, double x_is) {
    return (x_baseTop <= x_is);
}
 
int main() {
    ios_base::sync_with_stdio(true);
 
    double N, x, y, totArea = 0;
    vector<pair<double, pair<double, double>>> vector_points;
    stack<pair<double, pair<double, double>>> points;
    cin >> N;
 
    // Läsa in alla punkter, sorterat
    while(!(cin >> x >> y).eof()) {
        vector_points.push_back(make_pair(calcLeftBase(x, y), make_pair(x, y)));
    }
    
    sort(all(vector_points), greater<pair<double, pair<double, double>>>());
    for(auto x : vector_points) { points.push(x); }
 
    while(!points.empty()) {
        //---------------------------------------------
        // ::Min algorithm::
        //---------------------------------------------
        // Ta nästa punkt
        // Skapa triangels högra baspunkt
        //
        // Är punkten triangels högra punkt?
            // Ta arean för hela triangeln
        // Är det en triangel i den stora triangeln?
            // Radera den lilla triangeln då
            // Ta nästa punkt
        // Skär den i triangeln?
            // räkna ut arean för den stora
            // ta minus den lilla
        //---------------------------------------------
 
        double x_thisTop   = points.top().second.first;
        double y_thisTop   = points.top().second.second;
        double x_thisRight = calcRightBase(x_thisTop, y_thisTop);
        points.pop();
 
        do {
            if(points.empty()) {
                totArea += calcArea(y_thisTop);
                break;
            }
            
            double x_base    = points.top().first;
            double x_baseTop = points.top().second.first;
 
            // Är punkten triangels högra punkt?
            if(x_base >= x_thisRight) {
                totArea += calcArea(y_thisTop);
                break;
            }
 
            double x_is = getIntersectionX(x_base, x_thisTop, y_thisTop);
            double y_is = getIntersectionY(x_is, x_base);
 
            // Är det en triangel i den stora triangeln?
            if(isInsideBigTriangle(x_baseTop, x_is)) {
                points.pop();
            }
            else { // Skär i någon punkt
                totArea += calcArea(y_thisTop) - calcArea(y_is);
                break;
            }
        } while(true);
    }
 
    printf("%.3f", totArea);
}