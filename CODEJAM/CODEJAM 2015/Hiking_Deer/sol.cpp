#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

double x[N], v[N];

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    int cnt;
    scanf("%d", &cnt);
    vector < pair <int, int> > a;
    while (cnt--) {
      int d, h, m;
      scanf("%d %d %d", &d, &h, &m);
      for (int i = 0; i < h; i++) {
        a.push_back(make_pair(d, -m));
        m++;
      }
    }
    sort(a.begin(), a.end());
    int n = a.size();
    for (int i = 0; i < n; i++) {
      a[i].second = -a[i].second;
    }
    if (n == 2) {
      for (int i = 0; i < n; i++) {
        x[i] = a[i].first / 360.0;
        v[i] = 1.0 / a[i].second;
      }
      double t = min((1.0 - x[1]) / v[1], (1.0 - x[0]) / v[0]);
      for (int i = 0; i < n; i++) {
        x[i] += t * v[i];
      }
      if (x[0] < x[1]) {
        swap(x[0], x[1]);
        swap(v[0], v[1]);
      }
      x[0] = 0.0;
      int ans = 0;
      double t0 = (1.0 - x[0]) / v[0];
      double t1 = (1.0 - x[1]) / v[1];
      if (t0 - 1e-9 < t1) {
        ans++;
      }
      printf("%d\n", ans);
      continue;
    }
    int ans = n;
    for (int i = 0; i < n; i++) {
      int cnt = i;
      for (int j = 0; j < n; j++) {
        if (i == j || a[i].second == a[j].second) {
          continue;
        }
        double coeff = 360.0 / a[i].second - 360.0 / a[j].second;
        double r = a[j].first - a[i].first;
//        0 <= x < a[i].second
//        a[i].first + x / a[i].second * 360 == a[j].first + x / a[j].second * 360 + 360 * k
//        x * (360 / a[i].second - 360 / a[j].second) == a[j].first - a[i].first + 360 * k
//        x * coeff == r + 360 * k
        r /= coeff;
        double u = fabs(360.0 / coeff);
//        x == r + u * k
        if (r < 0) {
          int k = (int)(-r / u);
          r += u * k;
          while (r < 0) r += u;
        }
        if (fabs(r) < 1e-11 && a[i].first == a[j].first) {
          r += u;
        }
        double right_bound = a[i].second * (360 - a[i].first) / 360.0;
//        cerr << qq << " " << i << " " << j << " " << r << " " << u << " " << right_bound << endl;
        if (r <= right_bound + 1e-11) {
          cnt++;
          cnt += (int)((right_bound - r) / u + 1e-11);
        }
      }
      ans = min(ans, cnt);
    }
    printf("%d\n", ans);
  }
  return 0;
}
