#include <bits/stdc++.h>
using namespace std;

string code, q;
unordered_map<string, int> People;
int num_p = 0; // Tổng số người trong csdl
int Birthday_Before[1100000]; // Birthday_Before[i] là số người sinh trươcs ngày i
int Dad[100005], Mom[100005], Person[100005];

// Đổi date từ string sang int
int date_to_int(string date)
{
    return ((date[0] - 48) * 1000 + (date[1] - 48) * 100 + (date[2] - 48) * 10 + (date[3] - 48)) * 365 + ((date[5] - 48) * 10 + (date[6] - 48)) * 30 + (date[8] - 48) * 10 + (date[9] - 48);
}

// Đổi code từ string sang int
int code_to_int(string code)
{
    int tmp = 0;
    for (int i = 0; i < code.length(); ++i)
        tmp = tmp * 10 + (code[i] - '0');
    return tmp;
}

// Tính giá trị cho mảng Birthday_Before
void cal_Birthday_Before()
{
    for (int i = 1; i <= 1100000; ++i)
        Birthday_Before[i] += Birthday_Before[i - 1];
}

int MOST_ALIVE_ANCESTOR(int c)
{
    if (!c)
        return 0;
    int mom_ANCESTOR = MOST_ALIVE_ANCESTOR(Mom[c]);
    int dad_ANCESTOR = MOST_ALIVE_ANCESTOR(Dad[c]);
    return max(mom_ANCESTOR, dad_ANCESTOR) + 1;
}

int main()
{
    //freopen(".inp", "r", stdin);
    
    while (true)
    {
        cin >> code;
        if(code == "*")     break;

        string birth_day, f_code, m_code, r_code;
        char is_alive;
        cin >> birth_day >> f_code >> m_code >> is_alive >> r_code;

        num_p++;

        People[birth_day]++;

        Dad[code_to_int(code)] = code_to_int(f_code);
        Mom[code_to_int(code)] = code_to_int(m_code);
        Person[num_p] = code_to_int(code);

        Birthday_Before[date_to_int(birth_day)]++;
    }

    cal_Birthday_Before();

    while (q != "***")
    {
        cin >> q;
        if(q == "***")  break;

        if (q == "NUMBER_PEOPLE")
            cout << num_p;

        else if (q == "NUMBER_PEOPLE_BORN_AT")
        {
            string d;
            cin >> d;
            cout << People[d];
        }

        else if (q == "MOST_ALIVE_ANCESTOR")
        {
            string c;
            cin >> c;
            cout << MOST_ALIVE_ANCESTOR(code_to_int(c)) - 1;
        }

        else if (q == "NUMBER_PEOPLE_BORN_BETWEEN")
        {
            string f_date, t_date;
            cin >> f_date >> t_date;
            int tmp1 = date_to_int(f_date), tmp2 = date_to_int(t_date);
            cout << Birthday_Before[tmp2] - Birthday_Before[tmp1 - 1];
        }

        else if (q == "MAX_UNRELATED_PEOPLE")
        {
            int m = 0, n = 0;
            for (int e : Person)
            {
                if (e)
                {
                    if (MOST_ALIVE_ANCESTOR(e) % 2 == 0)    m++;
                    else    n++;
                }
            }
            cout << max(m, n);
        }

        cout << endl;
    }

    return 0;
}