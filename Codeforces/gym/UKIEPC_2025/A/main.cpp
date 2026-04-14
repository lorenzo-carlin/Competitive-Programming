#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// TODO: set this to false if it's unnecessary and the time limit might be tight.
// CHECK_OVERFLOW64 = true can run up to 2 times slower (particularly on CF).
const bool CHECK_OVERFLOW64 = true;

using dist_t = long double;

struct Point {
    long double x, y;

    Point() : x(0), y(0) {}

    Point(int64_t _x, int64_t _y) : x(_x), y(_y) {}

    Point& operator+=(const Point &other) { x += other.x; y += other.y; return *this; }
    Point& operator-=(const Point &other) { x -= other.x; y -= other.y; return *this; }
    Point& operator*=(int64_t mult) { x *= mult; y *= mult; return *this; }

    Point operator+(const Point &other) const { return Point(*this) += other; }
    Point operator-(const Point &other) const { return Point(*this) -= other; }
    Point operator*(int64_t mult) const { return Point(*this) *= mult; }

    bool operator==(const Point &other) const { return x == other.x && y == other.y; }
    bool operator!=(const Point &other) const { return !(*this == other); }

    Point operator-() const { return Point(-x, -y); }
    Point rotate90() const { return Point(-y, x); }

    int64_t norm() const {
        return (int64_t) x * x + (int64_t) y * y;
    }

    dist_t dist() const {
        return sqrt(dist_t(norm()));
    }

    bool top_half() const {
        return y > 0 || (y == 0 && x > 0);
    }

    friend ostream& operator<<(ostream &os, const Point &p) {
        return os << '(' << p.x << ", " << p.y << ')';
    }
};

int64_t cross(const Point &a, const Point &b) {
    return (int64_t) a.x * b.y - (int64_t) b.x * a.y;
}

int64_t dot(const Point &a, const Point &b) {
    return (int64_t) a.x * b.x + (int64_t) a.y * b.y;
}

int cross_sign(const Point &a, const Point &b) {
    if (CHECK_OVERFLOW64) {
        long double double_value = (long double) a.x * b.y - (long double) b.x * a.y;

        if (abs(double_value) > 1e18)
            return (double_value > 0) - (double_value < 0);
    }

    uint64_t uint64_value = (uint64_t) a.x * b.y - (uint64_t) b.x * a.y;
    int64_t actual = int64_t(uint64_value);
    return (actual > 0) - (actual < 0);
}

bool left_turn_strict(const Point &a, const Point &b, const Point &c) {
    return cross_sign(b - a, c - a) > 0;
}

bool left_turn_lenient(const Point &a, const Point &b, const Point &c) {
    return cross_sign(b - a, c - a) >= 0;
}

bool collinear(const Point &a, const Point &b, const Point &c) {
    return cross_sign(b - a, c - a) == 0;
}

// Returns twice the signed area formed by three Points in a triangle. Positive when a -> b -> c is a left turn.
int64_t area_signed_2x(const Point &a, const Point &b, const Point &c) {
    return cross(b - a, c - a);
}

dist_t distance_to_line(const Point &p, const Point &a, const Point &b) {
    assert(a != b);
    return dist_t(abs(area_signed_2x(p, a, b))) / (a - b).dist();
}

int64_t manhattan_dist(const Point &a, const Point &b) {
    return (int64_t) abs(a.x - b.x) + abs(a.y - b.y);
}

int64_t infinity_norm_dist(const Point &a, const Point &b) {
    return max(abs(a.x - b.x), abs(a.y - b.y));
}

// Sort in increasing order of y, with ties broken in increasing order of x.
bool yx_compare(const Point &a, const Point &b) {
    return make_pair(a.y, a.x) < make_pair(b.y, b.x);
}

// Sort in increasing order of angle to the x-axis.
bool angle_compare(const Point &a, const Point &b) {
    if (a.top_half() ^ b.top_half())
        return a.top_half();

    return cross_sign(a, b) > 0;
}

using db = long double;

struct line {
    db a, b, c;
};

line getLine(const Point &a, const Point &b) {
    line l;
    l.a = b.y - a.y;
    l.b = a.x - b.x;
    l.c = l.a * a.x + l.b * a.y;
    return l;
}

const db EPS = 1e-9;

db det(db a, db b, db c, db d) {
    return a*d - b*c;
}

bool intersect(line m, line n, Point &res) {
    db zn = det(m.a, m.b, n.a, n.b);
    if (abs(zn) < EPS)
        return false;
    res.x = -det(m.c, m.b, n.c, n.b) / zn;
    res.y = -det(m.a, m.c, n.a, n.c) / zn;
    return true;
}

bool parallel(line m, line n) {
    return abs(det(m.a, m.b, n.a, n.b)) < EPS;
}

bool equivalent(line m, line n) {
    return abs(det(m.a, m.b, n.a, n.b)) < EPS
        && abs(det(m.a, m.c, n.a, n.c)) < EPS
        && abs(det(m.b, m.c, n.b, n.c)) < EPS;
}

#include <iomanip>
#include <cmath>


db sq(db x) {
    return x * x;
}

db getDist(Point a, Point b) {
    return sq(b.x - a.x) + sq(b.y - a.y); 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << fixed << setprecision(10);

    int v, n;
    cin >> v >> n;
    vector<Point> pt(n);

    for (int i = 0; i < n; ++i) {
        db x, y;
        cin >> x >> y;
        pt[i] = {db(x), db(y)};

    }

    sort(pt.begin(), pt.end(), angle_compare);
    
    auto prv = [&](int i) {
        i -= 1;
        if (i < 0) {
            i += n;
        }
        return i;
    };

    auto nxt = [&](int i) {
        i += 1;
        if (i == n) {
            i -= n;
        }
        return i;
    };


    vector<line> lines(n);
    for (int i = 0; i < n; ++i) {
        Point a = pt[i];
        Point b = pt[prv(i)];
        Point c = pt[nxt(i)];

        db lenAB = sqrt(getDist(a, c));
        db lenAC = sqrt(getDist(a, c));
        db lenBC = sqrt(getDist(b, c));
        db L = lenAB + lenAC + lenBC;
        L *= 2;
        Point center = {
            (a.x + b.x + c.x) / L,
            (a.y + b.y + c.y) / L,
        };
        
        lines[i] = getLine(a, center);
    }

    db ans = 0;
    auto vmax = [&](db &x, db y) -> bool {
        if (y > x) {
            x = y;
            return true;
        }
        return false;
    };
    
    Point best;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            Point inter;
            if (i == j) {
                continue;
            }

            if (intersect(lines[i], lines[j], inter)) {
                if (vmax(ans, getDist(pt[i], inter))) {
                    best = inter;
                }
                if (vmax(ans, getDist(pt[j], inter))) {
                    best = inter;
                }
            }
        }
    }

    ans = sqrt(ans);
    cout << ans / db(v) << "\n";
    cout << best.x << " " << best.y << "\n";

    return 0;
}