---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A
  bundledCode: "#line 1 \"snow/geometry/tmp.hpp\"\n\nstruct Line : vector<Point> {\n\
    \    Line(Point a = Point(0.0, 0.0), Point b = Point(0.0, 0.0)){\n        this->push_back(a);\n\
    \        this->push_back(b);\n    }\n    friend ostream &operator<<(ostream &s,\
    \ const Line &l) { return s << '{' << l[0] << ',' << l[1] << '}'; }\n};\n\n/*\
    \ \u2220ABC */\ndouble degree(Point A, Point B, Point C){\n    if(B == C) return\
    \ 0;\n    return arg((A - B) / (C - B));\n}\n\n \n/* perpendicular bisector */\n\
    Line bisector(const Line& L){\n    Point X = L[0], Y = L[1];\n    Point C = (X\
    \ + Y) / ld(2.0);\n    Point D = C + (X - Y) * Point(0.0, 1.0);\n    return Line(C,\
    \ D);\n}\n\n/* \u4E8C\u76F4\u7DDA\u9593\u306E\u89D2\u5EA6, \u5E73\u884C, \u5782\
    \u76F4 */\n//VERIFIED : http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A\n\
    double lineAngle(const Line& L1, const Line& L2){\n    return degree(Point(L1[1]\
    \ - L1[0] ), Point(0.0, 0.0), Point(L2[1] - L2[0]));\n}\n\nbool isParallel(const\
    \ Line& L1, const Line& L2){\n    return abs(sin(lineAngle(L1, L2))) <= EPS;\n\
    }\n\nbool isOrthogonal(const Line& L1, const Line& L2){\n    return abs(cos(lineAngle(L1,\
    \ L2))) <= EPS;\n}\n\n/* cross point */\n/* \u4E8C\u76F4\u7DDA\u306E\u4EA4\u70B9\
    \ */\n// VERIFIED : http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C\n\
    Point crosspoint(const Line& L1, const Line& L2){\n    if(isParallel(L1, L2))\
    \ return Point(-INF, -INF);\n    Point A = L1[0], B = L1[1];\n    Point C = L2[0],\
    \ D = L2[1];\n    return A + (B - A) * (imag((A - C) * conj(C - D)) / imag((C\
    \ - D) * conj(B - A)));\n}\n\n/* Line Segment Crossed? */\n/* \u7DDA\u5206\u306E\
    \u4EA4\u5DEE\u5224\u5B9A */\n// VERIFIED : http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B\n\
    bool isSegmentCrossed(const Line& L1, const Line& L2){\n    Point A = L1[0], B\
    \ = L1[1];\n    Point C = L2[0], D = L2[1];\n\n    if(isParallel(L1, L2)){\n \
    \       if(ccw(A, B, C) == 2 or ccw(A, B, D) == 2 or ccw(C, D, A) == 2 or ccw(C,\
    \ D , B) == 2) return true;\n        return false;\n    }\n\n\n    double t =\
    \ imag((A - C) * conj(C - D)) / imag((C - D) * conj(B  - A));\n    double s =\
    \ imag((C - A) * conj(A - B)) / imag((A - B) * conj(D - C));\n    return t + EPS\
    \ >= 0 and t - EPS <= 1 and s + EPS >= 0 and s - EPS <= 1;\n}\n\n/* foot of a\
    \ perpendicular line\u3000*/\n/* \u5782\u7DDA\u306E\u8DB3 */\n//TODO : \u30D0\u30B0\
    \u3063\u3066\u308B\nPoint foot(const Point &A, const Line &L){\n    return (A\
    \ + L[0] + L[1] - (A * L[0] * conj(L[1]))) / ld(2.0);\n};\n\n//\u51F8\u5305\n\
    //VERIFIED : http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A\n\
    vector<Point> ConvexHull(vector<Point> X){\n    sort(ALL(X), [](Point A, Point\
    \ B){ return A.real() != B.real() ? A.real() < B.real() : A.imag() < B.imag();\
    \ });\n    int k = 0;\n    int n = X.size();\n    vector<Point> res(2 * n);\n\
    \    for(int i = 0; i < n; ++i){\n        while(k > 1 and ccw(res[k - 2], res[k\
    \ - 1], X[i]) == CW) --k;\n        res[k++] = X[i];\n    }\n    for(int i = n\
    \ - 2, t = k; i >= 0; --i){\n        while(k > t and ccw(res[k - 2], res[k - 1],\
    \ X[i]) == CW) --k;\n        res[k++] = X[i];\n    }\n    res.resize(k - 1);\n\
    \    return res;\n}\n"
  code: "\nstruct Line : vector<Point> {\n    Line(Point a = Point(0.0, 0.0), Point\
    \ b = Point(0.0, 0.0)){\n        this->push_back(a);\n        this->push_back(b);\n\
    \    }\n    friend ostream &operator<<(ostream &s, const Line &l) { return s <<\
    \ '{' << l[0] << ',' << l[1] << '}'; }\n};\n\n/* \u2220ABC */\ndouble degree(Point\
    \ A, Point B, Point C){\n    if(B == C) return 0;\n    return arg((A - B) / (C\
    \ - B));\n}\n\n \n/* perpendicular bisector */\nLine bisector(const Line& L){\n\
    \    Point X = L[0], Y = L[1];\n    Point C = (X + Y) / ld(2.0);\n    Point D\
    \ = C + (X - Y) * Point(0.0, 1.0);\n    return Line(C, D);\n}\n\n/* \u4E8C\u76F4\
    \u7DDA\u9593\u306E\u89D2\u5EA6, \u5E73\u884C, \u5782\u76F4 */\n//VERIFIED : http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A\n\
    double lineAngle(const Line& L1, const Line& L2){\n    return degree(Point(L1[1]\
    \ - L1[0] ), Point(0.0, 0.0), Point(L2[1] - L2[0]));\n}\n\nbool isParallel(const\
    \ Line& L1, const Line& L2){\n    return abs(sin(lineAngle(L1, L2))) <= EPS;\n\
    }\n\nbool isOrthogonal(const Line& L1, const Line& L2){\n    return abs(cos(lineAngle(L1,\
    \ L2))) <= EPS;\n}\n\n/* cross point */\n/* \u4E8C\u76F4\u7DDA\u306E\u4EA4\u70B9\
    \ */\n// VERIFIED : http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C\n\
    Point crosspoint(const Line& L1, const Line& L2){\n    if(isParallel(L1, L2))\
    \ return Point(-INF, -INF);\n    Point A = L1[0], B = L1[1];\n    Point C = L2[0],\
    \ D = L2[1];\n    return A + (B - A) * (imag((A - C) * conj(C - D)) / imag((C\
    \ - D) * conj(B - A)));\n}\n\n/* Line Segment Crossed? */\n/* \u7DDA\u5206\u306E\
    \u4EA4\u5DEE\u5224\u5B9A */\n// VERIFIED : http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B\n\
    bool isSegmentCrossed(const Line& L1, const Line& L2){\n    Point A = L1[0], B\
    \ = L1[1];\n    Point C = L2[0], D = L2[1];\n\n    if(isParallel(L1, L2)){\n \
    \       if(ccw(A, B, C) == 2 or ccw(A, B, D) == 2 or ccw(C, D, A) == 2 or ccw(C,\
    \ D , B) == 2) return true;\n        return false;\n    }\n\n\n    double t =\
    \ imag((A - C) * conj(C - D)) / imag((C - D) * conj(B  - A));\n    double s =\
    \ imag((C - A) * conj(A - B)) / imag((A - B) * conj(D - C));\n    return t + EPS\
    \ >= 0 and t - EPS <= 1 and s + EPS >= 0 and s - EPS <= 1;\n}\n\n/* foot of a\
    \ perpendicular line\u3000*/\n/* \u5782\u7DDA\u306E\u8DB3 */\n//TODO : \u30D0\u30B0\
    \u3063\u3066\u308B\nPoint foot(const Point &A, const Line &L){\n    return (A\
    \ + L[0] + L[1] - (A * L[0] * conj(L[1]))) / ld(2.0);\n};\n\n//\u51F8\u5305\n\
    //VERIFIED : http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A\n\
    vector<Point> ConvexHull(vector<Point> X){\n    sort(ALL(X), [](Point A, Point\
    \ B){ return A.real() != B.real() ? A.real() < B.real() : A.imag() < B.imag();\
    \ });\n    int k = 0;\n    int n = X.size();\n    vector<Point> res(2 * n);\n\
    \    for(int i = 0; i < n; ++i){\n        while(k > 1 and ccw(res[k - 2], res[k\
    \ - 1], X[i]) == CW) --k;\n        res[k++] = X[i];\n    }\n    for(int i = n\
    \ - 2, t = k; i >= 0; --i){\n        while(k > t and ccw(res[k - 2], res[k - 1],\
    \ X[i]) == CW) --k;\n        res[k++] = X[i];\n    }\n    res.resize(k - 1);\n\
    \    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: snow/geometry/tmp.hpp
  requiredBy: []
  timestamp: '2021-04-24 10:08:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snow/geometry/tmp.hpp
layout: document
redirect_from:
- /library/snow/geometry/tmp.hpp
- /library/snow/geometry/tmp.hpp.html
title: snow/geometry/tmp.hpp
---
