#include <iostream>
#include<unordered_set>
using namespace std;

void solution(string str)
{
    unordered_set<char> set;
    for(int i=0;i<str.length();i++)
    {
        set.insert(str[i]);
    }
    cout<<set.size()<<endl;
}

int main()
{
    string str;
    cin>>str;
    solution(str);
    return 0;
}