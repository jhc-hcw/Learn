
#include <cstddef>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>

using namespace std;
void fcombine(vector<vector<int>> &res, vector<int> &temp, int n, int k) {
  int last = temp.back();
  for (int i = last + 1; i <= n; i++) {
    vector<int> t(temp);
    t.push_back(i);
    if (t.size() == k) {
      res.push_back(t);
    } else {
      fcombine(res, t, n, k);
    }
  }
}
void fc2(vector<vector<int>> &result, vector<int> &temp, int n, int rest) {
  int last =0;
  if(!temp.empty()){
    last=temp.back();
  }
  for (int i = last + 1; i <= n; i++) {
    temp.push_back(i);
    if (rest == 1) {
      result.push_back(temp);
      temp.pop_back();
      continue;
    }
    fc2(result, temp, n, rest - 1);
    temp.pop_back();
  }
}
vector<vector<int>> combine(int n, int k) {
  vector<vector<int>> res;
  vector<int> temp;
  fc2(res, temp, n, k);
  return res;
}
