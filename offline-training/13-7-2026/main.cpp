#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int INF = 1e9;
const int N = 3e6+1;
const double EPS = 1e-9;

template <class T> int sgn(T x) { return (x > EPS) - (x < -EPS); }

template <class T>
struct Point {
    typedef Point P;
    T x, y;
    vector<int>
    a(n);
    
    explicit Point(T x=0, T y=0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }
    bool operator==(P p) const { return sgn(x - p.x) == 0 && sgn(y - p.y) == 0; }
    P operator+(P p) const { return P(x+p.x, y+p.y); }
    P operator-(P p) const { return P(x-p.x, y-p.y); }
    P operator*(T d) const { return P(x*d, y*d); }
    P operator/(T d) const { return P(x/d, y/d); }
    T dot(P p) const { return x*p.x + y*p.y; }
    T cross(P p) const { return x*p.y - y*p.x; }
    T cross(P a, P b) const { return (a-*this).cross(b-*this); }
    T dist2() const { return x*x + y*y; }
    double dist() const { return sqrt((double)dist2()); }
};

// Vector Utilities
template <class T> Point<double> normalize(Point<T> p) { return p / p.dist(); }
Point<double> polar(double r, double ang) { return Point<double>(r * cos(ang), r * sin(ang)); }
template <class T> Point<double> rotate(Point<T> p, double ang) {
    return Point<double>(p.x * cos(ang) - p.y * sin(ang), p.x * sin(ang) + p.y * cos(ang));
}
template <class T> double angle(Point<T> a, Point<T> b) {
    return acos(max(-1.0, min(1.0, (double)a.dot(b) / a.dist() / b.dist())));
}

// 1: left (ccw), -1: right (cw), 0: collinear
template <class T> int ccw(Point<T> a, Point<T> b, Point<T> c) {return sgn(a.cross(b, c)); }

// Intersection point of infinite lines ab and cd. False if parallel.
template <class T> bool lineInter(Point<T> a, Point<T> b, Point<T> c, Point<T> d, Point<ld>& out) {
    T cp = (b - a).cross(d - c);
    if (abs(cp) < EPS) return false;
    ld t = (ld)(c - a).cross(d - c) / cp;
    out = Point<ld>(a.x, a.y) + Point<ld>(b.x - a.x, b.y - a.y) * t;
    return true;
}

template <class T> T polygonArea2(vector<Point<T>>& v) {
    T a = v.back().cross(v[0]);
    for (int i = 0; i < (int)v.size() - 1; i++) a += v[i].cross(v[i + 1]);
    return abs(a);
}

ll n;
ll idx(ll i) {
    return i % n;
}

#define point Point<ld>

void solve() {
    cout << "A7a";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
