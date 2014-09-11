/*
Given a two-dimensional graph with points on it, find a line 
which passes the most number of points.
*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Point{
    double x, y;
    Point(double a, double b): x(a), y(b) {}
    Point(): x(0.0), y(0.0) {}
    
};
class Line{
public:
    double epsilon, slope, intercept;
public:
    Line(double s, double i): slope(s), intercept(i), epsilon(0.0001) {
    }
    
    Line(Point p, Point q){
        epsilon = 0.0001;
        if(abs(p.x - q.x) > epsilon){
            slope = (p.y-q.y) / (p.x-q.x);
            intercept = p.y - slope * p.x;
        }
        else{
            slope = INT_MAX;
            intercept = p.x;
        }
    }
    void print(){
        cout<<"y = " << slope <<"x + " << intercept << endl;
    }
};

int getBestLine(vector<Point> &Points){
    int num = Points.size();
    int resMaxPoints = 0;
    double eps = 0.0001;
//    double slopeMaxPoints = 0.0, interceptMaxPoints = 0.0;
    unordered_map<int, int> counts;
    for (int i = 0; i < num; ++i) {
        int duplicates = 1;
        counts.clear();
        for (int j = 0; j < num; ++j) {
            if (j == i) {
                continue;
            }
            if (abs(Points[i].x - Points[j].x) < eps) {
                if ((Points[i].y - Points[j].y) < eps) {
                    ++duplicates;
                } else {
                    counts[INT_MAX]++;
                }
            } else {
                double slope = (Points[i].y - Points[j].y) / (Points[j].x - Points[j].x);
                int key = (int) slope * 10000;
                counts[key]++;
            }
        }
        int maxPoints = 0;
        for (unordered_map<int, int>::iterator it = counts.begin(); it != counts.end(); ++it) {
            if (it->second > maxPoints) {
                maxPoints = it->second;
//                if (((double)(it->first / 10000 - INT_MAX)) < eps) {
//                     slopeMaxPoints = INT_MAX;
//                 } else {
//                     slopeMaxPoints = (double)(it->first / 10000);
//                 }
            }
        }
        if (maxPoints + duplicates > resMaxPoints) {
            resMaxPoints = maxPoints + duplicates;
//            if ((slopeMaxPoints - INT_MAX) < eps) {
//                 interceptMaxPoints = Points[i].y - slopeMaxPoints * Points[i].x;
//            } else {
//                 interceptMaxPoints = Points[i].x;
//            }
        }
    }
//   return Line(slopeMaxPoints, interceptMaxPoints);
    return resMaxPoints;
}

int main(){
    srand((unsigned)time(0));
    int graph_size = 100;
    int Point_num = 500;
    vector<Point>  pvec;
    pvec.push_back(Point(0, 0));
    pvec.push_back(Point(-1, -1));
    pvec.push_back(Point(2, 2));
//    for(int i = 0; i < Point_num; ++i){
//        double x = rand()/double(RAND_MAX) * graph_size;
//        double y = rand()/double(RAND_MAX) * graph_size;
//        pvec.push_back(Point(x, y));
//        //cout<<p[i].x<<" "<<p[i].y<<endl;
//    }
//    Line l = getBestLine(pvec);
//    l.print();
    int num = getBestLine(pvec);
    cout << num << endl;
    return 0;
}