#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<vector<string>> groupByName(vector<string> &strs)
{
    vector<vector<string>> res{};
    while (!strs.empty())
    {
        vector<string> eq_class{};
        auto cur = strs.begin();
        string newstr = *cur;
        eq_class.emplace_back(newstr);
        strs.erase(cur);

        sort(newstr.begin(), newstr.end());

        auto i = strs.begin();
        while (i != strs.end())
        {
            string curstr = *i;
            string tosort = curstr;
            sort(tosort.begin(), tosort.end());
            if (newstr.compare(tosort) == 0)
            {
                eq_class.emplace_back(curstr);
                strs.erase(i);
            }
            else
            {
                i++;
            }
        }
        res.emplace_back(eq_class);
    }
    return res;
}