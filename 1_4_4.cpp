// m=？
#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    int n, m;
    float a[105][105];
    cin >> n;
    cin >> m;

    float min = 1;
    float min_s = 2;
    vector<int> vc;
    vector<float> sum_v;
    sum_v.push_back(0);  //把0位占掉，则以后序号即是点的编号
    set<int> sc;
    for (register int i = 1; i <= n; ++i) sc.insert(i);
    int vx, vy;
    for (int i = 1; i <= n; i++) {
        float s = 0;
        for (register int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            s += a[i][j];
        }
        sum_v.push_back(s);
    }

    for (int i = 1; i <= n; ++i) {
        for (register int j = i + 1; j <= n; ++j) {
            if (a[i][j] <= min) {
                if (a[i][j] == min && (sum_v[i] + sum_v[j]) <= min_s)
                    ;  //因为这样一下选了两个点，所以求的是和的最小值
                else {
                    min_s = sum_v[i] + sum_v[j];
                    min = a[i][j];
                    vx = i;
                    vy = j;
                }
            }
        }
    }
    vc.push_back(vx);
    sc.erase(vx);
    vc.push_back(vy);
    sc.erase(vy);
    for (int i = 2; i < m; ++i) {
        float sum_min = i;
        int v_min;
        for (set<int>::iterator t = sc.begin(); t != sc.end(); t++) {
            float sum = 0;
            for (int j = 0; j < i; ++j) {
                sum += a[vc[j]][*t];
            }
            if (sum <= sum_min) {
                if (sum == sum_min && sum_v[v_min] <= sum_v[*t])
                    ;
                else {
                    sum_min = sum;
                    v_min = *t;
                }
            }
        }
        min += sum_min;
        vc.push_back(v_min);
        sc.erase(v_min);
    }

    cout << min << endl;

    return 0;
}