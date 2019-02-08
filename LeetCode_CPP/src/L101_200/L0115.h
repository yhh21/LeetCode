
#pragma once

#include "../Head.h"

namespace L0115
{


/// https://leetcode.com/problems/distinct-subsequences/
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        const int Length_s = s.size();
        if (0 == Length_s)
        {
            return 0;
        }
        const int Length_t = t.size();
        vector<unsigned int> dp(Length_t + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < Length_s; ++i)
        {
            for (int j = Length_t - 1; j >= 0; --j)
            {
                if (s[i] == t[j])
                {
                    dp[j + 1] += dp[j];
                }
            }
        }

        return (int)dp[Length_t];
    }

#ifdef DEBUG
    void Test()
    {
        Print(numDistinct("xslledayhxhadmctrliaxqpokyezcfhzaskeykchkmhpyjipxtsuljkwkovmvelvwxzwieeuqnjozrfwmzsylcwvsthnxujvrkszqwtglewkycikdaiocglwzukwovsghkhyidevhbgffoqkpabthmqihcfxxzdejletqjoxmwftlxfcxgxgvpperwbqvhxgsbbkmphyomtbjzdjhcrcsggleiczpbfjcgtpycpmrjnckslrwduqlccqmgrdhxolfjafmsrfdghnatexyanldrdpxvvgujsztuffoymrfteholgonuaqndinadtumnuhkboyzaqguwqijwxxszngextfcozpetyownmyneehdwqmtpjloztswmzzdzqhuoxrblppqvyvsqhnhryvqsqogpnlqfulurexdtovqpqkfxxnqykgscxaskmksivoazlducanrqxynxlgvwonalpsyddqmaemcrrwvrjmjjnygyebwtqxehrclwsxzylbqexnxjcgspeynlbmetlkacnnbhmaizbadynajpibepbuacggxrqavfnwpcwxbzxfymhjcslghmajrirqzjqxpgtgisfjreqrqabssobbadmtmdknmakdigjqyqcruujlwmfoagrckdwyiglviyyrekjealvvigiesnvuumxgsveadrxlpwetioxibtdjblowblqvzpbrmhupyrdophjxvhgzclidzybajuxllacyhyphssvhcffxonysahvzhzbttyeeyiefhunbokiqrpqfcoxdxvefugapeevdoakxwzykmhbdytjbhigffkmbqmqxsoaiomgmmgwapzdosorcxxhejvgajyzdmzlcntqbapbpofdjtulstuzdrffafedufqwsknumcxbschdybosxkrabyfdejgyozwillcxpcaiehlelczioskqtptzaczobvyojdlyflilvwqgyrqmjaeepydrcchfyftjighntqzoo",
            "rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys"));
    }
#endif /// DEBUG
};


}