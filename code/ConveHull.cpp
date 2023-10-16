struct pt { // Kieu diem
  double x, y;
};

bool cmp (pt a, pt b) { // So sanh theo toa do x, trong truong hop bang nhau so sanh theo y
  return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool cw (pt a, pt b, pt c) { // a -> b -> c di theo thu tu xuoi chieu kim dong ho
  return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw (pt a, pt b, pt c) { // a -> b -> c di theo thu tu nguoc chieu kim dong ho
  return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convex_hull (vector<pt> & a) {
  if (a.size() == 1) { // chi co 1 diem
    return;
  }

  // Sap xep cac diem theo toa do x, neu bang nhau sap xep theo y
  sort (a.begin(), a.end(), &cmp);

  pt p1 = a[0],  p2 = a.back();

  vector<pt> up, down; // chuoi tren va chuoi duoi
  up.push_back (p1);
  down.push_back (p1);

  for (size_t i=1; i<a.size(); ++i) { // xet lan luot cac diem
    // Them vao chuoi tren
    if (i==a.size()-1 || cw (p1, a[i], p2)) {
      while (up.size()>=2 && !cw (up[up.size()-2], up[up.size()-1], a[i]))
        up.pop_back();
      up.push_back (a[i]);
    }

    // Them vao chuoi duoi
    if (i==a.size()-1 || ccw (p1, a[i], p2)) {
      while (down.size()>=2 && !ccw (down[down.size()-2], down[down.size()-1], a[i]))
        down.pop_back();
      down.push_back (a[i]);
    }
  }

  // Gap 2 chuoi tren va duoi de lay bao loi
  a.clear();
  for (size_t i=0; i<up.size(); ++i)
    a.push_back (up[i]);
  for (size_t i=down.size()-2; i>0; --i)
    a.push_back (down[i]);
}
