//doan thang -> duong thang
pair<pld, ld> segtoline(pair<pld, pld> a){
    if (a.x.x == a.y.x) return {{1, 0}, a.x.x};
    if (a.x.y == a.y.y) return {{0, 1}, a.x.y};
    return {{(a.y.y-a.x.y)/(a.x.x-a.y.x),1},(a.y.y-a.x.y)/(a.x.x-a.y.x)*a.x.x+a.x.y};
}

//Tim duong thang phap tuyen
pair<pld, ld> vuong(pair<pld, ld> s, pld a){
    if (s.x.x == 0)
        return {{1, 0}, a.x};
    else return {{1, -s.x.x}, a.x - s.x.x * a.y};
}

//khoang cach tu diem den duong thang
ld point_seg(pld a, pair<pld, pld> b){
    if (b.x.x > b.y.x) swap(b.x, b.y);
    pair<pld, ld> s = segtoline(b);
    pair<pld, ld> v = vuong(s, a);
    pld giao = {(v.x.y*s.y - v.y)/(v.x.y*s.x.x - 1), (v.y - (v.x.y*s.y - v.y)/(v.x.y*s.x.x - 1)) / v.x.y};
    if ((b.x.x <= giao.x) && (giao.x <= b.y.x)) return point_point(a, giao);
    else return min(point_point(a, b.x), point_point(a, b.y));
}
