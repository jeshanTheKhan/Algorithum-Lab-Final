#include <bits/stdc++.h>
using namespace std;

struct LabFinal
{
    int value;
    int time;

    bool operator<(const LabFinal &other) const
    {
        return time > other.time;
    }
};

int main()
{
    int n;

    cout << "Input the number of tasks: ";
    cin >> n;

    vector<LabFinal> tasks(n);
    for (int i = 0; i < n; ++i)
    {
        cout << "Task " << i + 1 << ": ";
        cin >> tasks[i].value >> tasks[i].time;
    }

    priority_queue<LabFinal> pq;

    for (const LabFinal &task : tasks)
    {
        pq.push(task);
    }

    cout << "Tasks processed according to their time durations:"<<endl;
    while (!pq.empty())
    {
        LabFinal currentTask = pq.top();
        pq.pop();
        cout << "Task " << currentTask.value << ": (" << currentTask.value << ", " << currentTask.time << ")"<<endl;
    }

    return 0;
}
