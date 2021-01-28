#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
  ifstream in ("bledne.txt");
  int x;
  while ( in >> x) {
    vector < int > v(x);
    for (int i = 0; i < x; i++) {
      in >> v[i];
    }
    vector < int > roznica;
    for (int i = 1; i < x; i++) {
      roznica.push_back(v[i] - v[i - 1]);
    }
    sort(roznica.begin(), roznica.end());
    int ans = -1;
    for (int i = 1; i < roznica.size(); i++) {
      if (roznica[i] == roznica[i - 1]) {
        ans = roznica[i];
        break;
      }
    }
    bool ok = true;
    for (int i = 1; i < x - 1; i++) {
      if (v[i] - v[i - 1] != ans && v[i + 1] - v[i] != ans) {
        cout << v[i] << "\n";
        ok = false;
        break;
      }
    }
    if (ok) {
      if (v[1] - v[0] != ans)
        cout << v[0] << "\n";
      else if (v[x - 1] - v[x - 2] != ans)
        cout << v[x - 1] << "\n";
    }
  }
  return 0;
}
