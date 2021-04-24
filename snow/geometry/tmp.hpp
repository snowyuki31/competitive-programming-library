
struct Line : vector<Point> {
    Line(Point a = Point(0.0, 0.0), Point b = Point(0.0, 0.0)){
        this->push_back(a);
        this->push_back(b);
    }
    friend ostream &operator<<(ostream &s, const Line &l) { return s << '{' << l[0] << ',' << l[1] << '}'; }
};

/* ∠ABC */
double degree(Point A, Point B, Point C){
    if(B == C) return 0;
    return arg((A - B) / (C - B));
}

 
/* perpendicular bisector */
Line bisector(const Line& L){
    Point X = L[0], Y = L[1];
    Point C = (X + Y) / ld(2.0);
    Point D = C + (X - Y) * Point(0.0, 1.0);
    return Line(C, D);
}

/* 二直線間の角度, 平行, 垂直 */
//VERIFIED : http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A
double lineAngle(const Line& L1, const Line& L2){
    return degree(Point(L1[1] - L1[0] ), Point(0.0, 0.0), Point(L2[1] - L2[0]));
}

bool isParallel(const Line& L1, const Line& L2){
    return abs(sin(lineAngle(L1, L2))) <= EPS;
}

bool isOrthogonal(const Line& L1, const Line& L2){
    return abs(cos(lineAngle(L1, L2))) <= EPS;
}

/* cross point */
/* 二直線の交点 */
// VERIFIED : http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C
Point crosspoint(const Line& L1, const Line& L2){
    if(isParallel(L1, L2)) return Point(-INF, -INF);
    Point A = L1[0], B = L1[1];
    Point C = L2[0], D = L2[1];
    return A + (B - A) * (imag((A - C) * conj(C - D)) / imag((C - D) * conj(B - A)));
}

/* Line Segment Crossed? */
/* 線分の交差判定 */
// VERIFIED : http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B
bool isSegmentCrossed(const Line& L1, const Line& L2){
    Point A = L1[0], B = L1[1];
    Point C = L2[0], D = L2[1];

    if(isParallel(L1, L2)){
        if(ccw(A, B, C) == 2 or ccw(A, B, D) == 2 or ccw(C, D, A) == 2 or ccw(C, D , B) == 2) return true;
        return false;
    }


    double t = imag((A - C) * conj(C - D)) / imag((C - D) * conj(B  - A));
    double s = imag((C - A) * conj(A - B)) / imag((A - B) * conj(D - C));
    return t + EPS >= 0 and t - EPS <= 1 and s + EPS >= 0 and s - EPS <= 1;
}

/* foot of a perpendicular line　*/
/* 垂線の足 */
//TODO : バグってる
Point foot(const Point &A, const Line &L){
    return (A + L[0] + L[1] - (A * L[0] * conj(L[1]))) / ld(2.0);
};

//凸包
//VERIFIED : http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A
vector<Point> ConvexHull(vector<Point> X){
    sort(ALL(X), [](Point A, Point B){ return A.real() != B.real() ? A.real() < B.real() : A.imag() < B.imag(); });
    int k = 0;
    int n = X.size();
    vector<Point> res(2 * n);
    for(int i = 0; i < n; ++i){
        while(k > 1 and ccw(res[k - 2], res[k - 1], X[i]) == CW) --k;
        res[k++] = X[i];
    }
    for(int i = n - 2, t = k; i >= 0; --i){
        while(k > t and ccw(res[k - 2], res[k - 1], X[i]) == CW) --k;
        res[k++] = X[i];
    }
    res.resize(k - 1);
    return res;
}