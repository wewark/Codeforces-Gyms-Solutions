// 101630 - 2017-2018 ACM-ICPC Northern Eurasia (Northeastern European Regional) Contest (NEERC 17)
// 101630E

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    cin >> n;

    int a, b[1001]={0};
    vector<int> ans;

    for(int i=0 ; i<n ; i++)
    {
        cin >> a;

        if(a<0)
        {
            if(b[-a]>0)
                b[-a]--;
            else if(b[0]>0)
                b[0]--, ans.push_back(-a);
            else
                return cout << "No", 0;
        } else
            b[a]++;
    }

    while(b[0]--)
    {
        ans.push_back(1);
    }

    cout << "Yes\n";

    for(int i: ans)
        cout << i << ' ';

    return 0;
}
