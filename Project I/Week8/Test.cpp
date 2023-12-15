// Problem: Week 8 - Analyze Code Submission of a Programming Contest

#include <bits/stdc++.h>
using namespace std;

string UID, q;
unordered_map<string, int> total_point;
unordered_map<string, int> error_UserSubmit;
set<int> arr_time;
int num_Submit = 0, error_Submit = 0, Submit_in[90000];

// Đổi time từ string về đơn vị giây
int time_to_Second(string time)
{
    return ((time[0] - 48) * 10 + (time[1] - 48)) * 3600 + ((time[3] - 48) * 10 + (time[4] - 48)) * 60 + (time[6] - 48) * 10 + (time[7] - 48);
}

// Tính giá trị cho mảng Submit_in[]
void cal_Submit_in()
{
    int tmp = 0;
    for (int e : arr_time)
    {
        Submit_in[e] += tmp;
        tmp = Submit_in[e];
    }

    num_Submit = tmp;
    for (int i = 1; i <= 86400; ++i)
        if (!Submit_in[i]) Submit_in[i] = Submit_in[i - 1];
}

int main()
{
    //freopen(".inp", "r", stdin);

    while (true)
    {
        cin >> UID;
        if(UID == "#")  break;

        string PID, time, status;
        int point;
        cin >> PID >> time >> status >> point;

        if (status == "ERR")
        {
            error_Submit++;
            error_UserSubmit[UID]++;
        }
        else if (total_point[UID + PID] < point)
        {
            total_point[UID] += point - total_point[UID + PID];
            total_point[UID + PID] = point;
        }

        Submit_in[time_to_Second(time)]++;
        arr_time.insert(time_to_Second(time));
    }

    cal_Submit_in();
    int maxTime = *(--arr_time.end());

    while (q != "#")
    {
        cin >> q;
        if(q == "#")    break;

        if (q == "?total_number_submissions")
            cout << num_Submit;

        else if (q == "?number_error_submision")
            cout << error_Submit;

        else if (q == "?number_error_submision_of_user")
        {
            string uid;
            cin >> uid;
            cout << error_UserSubmit[uid];
        }

        else if (q == "?total_point_of_user")
        {
            string uid;
            cin >> uid;
            cout << total_point[uid];
        }

        else if (q == "?number_submission_period")
        {
            string from_time1, to_time2;
            cin >> from_time1 >> to_time2;
            int p1 = time_to_Second(from_time1), p2 = time_to_Second(to_time2);
            cout << Submit_in[p2] - Submit_in[p1 - 1];
        }

        cout << endl;
    }

    return 0;
}