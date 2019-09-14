#include<bits/stdc++.h>
using namespace std;

#define MAX 1000005
int failure[MAX], ans;

void build_failure_function(string pattern, int m)
{
    failure[0] = 0;
    failure[1] = 0;
    for(int i = 2; i <= m; i++)
    {
        int j = failure[i - 1];
        while(true)
        {
            if(pattern[j] == pattern[i - 1])
            {
                failure[i] = j + 1;
                break;
            }
            if(j == 0)
            {
                failure[i] = 0;
                break;
            }
            j = failure[j];
        }
    }
}
int kmp(string text, string pattern)
{
    int n = text.size();
    int m = pattern.size();
    build_failure_function(pattern, m);
    int i = 0;
    int j = 0;
    while(true)
    {
        if(j == n)
        {
            return ans;
        }
        if(text[j] == pattern[i])
        {
            i++;
            j++;
            if(i == m)
            {
                i=failure[i];
                ans++;
            }
        }
        else
        {
            if (i == 0)
            {
                j++;
            }
            else
            {
                i = failure[i];
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s, s2;
    int t,n, m, q, i=1, j;
    cin >> t;
    while(t--)
    {
        cin >> s >> s2;
        ans=0;
        cout << "Case "<< i++ << ": " << kmp(s,s2) << endl;

    }
    return 0;
}
