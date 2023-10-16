S = sqrt(N);
bool cmp(Query A, Query B) // so sanh 2 truy van
{
  if (A.l / S != B.l / S) {
    return A.l / S < B.l / S;
  }
  return A.r < B.r;
}
