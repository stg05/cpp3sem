#include <vector>
#include <algorithm>

int numRabbits(std::vector<int> &answers)
{
    std::sort(answers.begin(), answers.end());
    auto it = answers.begin();
    int cnt = 0, rabbits = 0;
    for (auto it = answers.begin(); it != answers.end(); it++)
    {
        cnt++;
        if (((it + 1) == answers.end()))
        {
            int res = cnt / (*it + 1);
            if (cnt % (*it + 1) != 0)
                res++;
            rabbits += res * (*it + 1);
            cnt = 0;
            break;
        }
        if ((*(it + 1) != *it))
        {
            int res = cnt / (*it + 1);
            if (cnt % (*it + 1) != 0)
                res++;
            rabbits += res * (*it + 1);
            cnt = 0;
            continue;
        }
    }
    return rabbits;
}