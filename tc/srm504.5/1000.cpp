#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream> #include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

double ans[11];;
int global_k;
void print(vector<int> t){
    for(int i=0; i<t.size(); i++){
        cout<<t[i]+1<<"    ";
    }cout<<endl;
}

void dfs(vector<int> cur, int depth, long double prob){
    int sz = cur.size();
    if(sz==0)return;
    if(depth>=global_k ){
            ans[cur[0]] += prob; 
        return;
    }
        
    ans[cur[0]] += prob*1/6;
    cout<<"under ";
    print(cur);
    cout<<"prob for "<<cur[0]+1<<"at depth "<<depth<<"  is  "<<prob*1/6<<endl;

    vector<int> t1 = cur;
    int t = t1[0];
    t1.erase( t1.begin() );
    
    dfs(t1, depth+1, prob*1.0/3);
    if(sz==1){
        ans[cur[0]] += prob*1/3;
    }

    t1.insert(t1.end(), t);

    dfs(t1, depth+1, prob*1.0/2);
}


class TheTicketsDivTwo {
    public:
        double find(int n, int m, int k) {
            vector<int> init;
            memset(ans,0,sizeof(ans));
            for(int i=0; i<n; i++){
                init.push_back(i);
            }
            global_k=k;
            dfs(init, 0, 1.0);
            return ans[m-1];
        }
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, bool hasAnswer, double p3) {
    cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2;
    cout << "]" << endl;
    TheTicketsDivTwo *obj;
    double answer;
    obj = new TheTicketsDivTwo();
    clock_t startTime = clock();
    answer = obj->find(p0, p1, p2);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << p3 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer) {
        res = fabs(p3 - answer) <= 1e-9 * max(1.0, fabs(p3));
    }
    if (!res) {
        cout << "DOESN'T MATCH!!!!" << endl;
    } else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
        cout << "FAIL the timeout" << endl;
        res = false;
    } else if (hasAnswer) {
        cout << "Match :-)" << endl;
    } else {
        cout << "OK, but is it right?" << endl;
    }
    cout << "" << endl;
    return res;
}
int main() {
    bool all_right;
    all_right = true;

    int p0;
    int p1;
    int p2;
    double p3;

    {
        // ----- test 0 -----
        p0 = 2;
        p1 = 1;
        p2 = 1;
        p3 = 0.16666666666666666;
          all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        p0 = 2;
        p1 = 1;
        p2 = 2;
        p3 = 0.5833333333333334;
        all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }
    {
        // ----- test 2 -----
        p0 = 7;
        p1 = 7;
        p2 = 4;
        p3 = 0.0;
        all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        p0 = 4;
        p1 = 2;
        p2 = 10;
        p3 = 0.25264033564814814;
        all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    if (all_right) {
        cout << "You're a stud (at least on the example cases)!" << endl;
    } else {
        cout << "Some of the test cases had errors." << endl;
    }
    return 0;
}
// END KAWIGIEDIT TESTING
