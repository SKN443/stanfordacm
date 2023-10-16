#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

const int N = 2e5;
const long long  INF = 3e18;

class point{
public:
    long long  x, y;
};

class cmp_x{
public:
    bool operator()(const point &A, const point &B) {
        return A.x < B.x;
    }
};

class cmp_y{
public:
    bool operator()(const point &A, const point &B) {
        return A.y < B.y;
    }
};

point set_of_points[N];

long long  distance_AB(const point &A, const point &B) {
    return (A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y);
}

long long  find_min_distance(int l, int r) {
    //Neu doan [l, r] chi co 1 phan tu
    if (r-l == 0) return INF;
    //Neu doan [l, r] co 2 phan tu
    if (r-l == 1) {
        if (set_of_points[l].y > set_of_points[r].y) swap(set_of_points[l], set_of_points[r]);
        return distance_AB(set_of_points[l], set_of_points[r]);
    }

    long long  result = INF;

    int mid = (l+r) >>1;
    point mid_point = set_of_points[mid];
    result = min(find_min_distance(l, mid), find_min_distance(mid+1, r));

    static point Tam[N];
    int d = -1;
    //Su dung Merge Sort de sap xep doan [l, r] tang dan theo tung do va cho vao mang Tam
    merge(set_of_points+l, set_of_points+mid+1, set_of_points+mid+1, set_of_points+r+1, Tam, cmp_y());
    //Sap xep lai doan [l, r] tren set_of_points bang cach dan mang Tam vao set_of_points
    copy(Tam, Tam+r-l+1, set_of_points+l);

    for(int i = l; i <= r; i++) if (abs(set_of_points[i].x - mid_point.x) < sqrt(result)) {
        for(int j = d; (j >= 0) && set_of_points[i].y < Tam[j].y + sqrt(result); j--)
            result = min(result, distance_AB(set_of_points[i], Tam[j]));
        Tam[++d] = set_of_points[i];
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    //Input
    int n;
    cin >>n;
    for(int i=0; i<n; i++) cin >>set_of_points[i].x >>set_of_points[i].y;

    //Solution
    sort(set_of_points, set_of_points+n, cmp_x());
    long long  min_distance = find_min_distance(0, n-1);

    //Output
    cout <<fixed <<setprecision(9) <<sqrt((long double) min_distance);
}
