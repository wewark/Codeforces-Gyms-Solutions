// 101630 - 2017-2018 ACM-ICPC Northern Eurasia (Northeastern European Regional) Contest (NEERC 17)
// 101630B

#include <bits/stdc++.h>

using namespace std;

bool check(int x, int y, int w ,int h)
{
    return (x<=w && y<=h) || (x<=h && y<=w);
}

bool solve1(int *a, int w, int h)
{
    int x1=a[2]+2*a[1], x2=a[0]+a[1]+a[2];
    int y1=2*a[0]+a[1]+a[2], y2=2*a[0]+2*a[1];

    return check(x1,y1,w,h) || check(x1,y2,w,h) || check(x2,y2,w,h) || check(x2,y1,w,h);
}

bool solve2(int *a, int w, int h)
{
    int x = a[2]+a[1];
    int y = 3*a[0]+a[1]+a[2];

    return check(x,y,w,h);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int a[3], w, h;

    cin >> a[0] >> a[1] >> a[2] >> w >> h;

    sort(a,a+3);

    do{
        if(solve1(a,w,h) || solve2(a, w, h))
            return cout << "Yes", 0;

    }while(next_permutation(a,a+3));

    cout << "No";

    return 0;
}
