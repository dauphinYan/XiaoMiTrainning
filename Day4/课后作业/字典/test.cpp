#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, string> dictionnary = {
        {"abandon", "放弃"},
        {"boy", "男孩"},
        {"girl", "女孩"}};

    string tmp;
    cout << "请输入需要查询的单词：";
    cin >> tmp;

    auto it = dictionnary.find(tmp);
    if (it != dictionnary.end())
    {
        cout << "结果为：" << it->second << endl;
    }
    else 
    {
        cout << "未查询到" << endl;
    }

    return 0;
}
