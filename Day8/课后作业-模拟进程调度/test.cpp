#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Process
{
private:
    int id;          // 进程id
    int arrivalTime; // 到达时间
    int burstTime;   // 执行时间
    // int finishTime;  // 完成时间

public:
    Process(int id, int arrivalTime, int burstTime) : id(id), arrivalTime(arrivalTime), burstTime(burstTime) {}

    int getId()
    {
        return id;
    }

    int getArrivalTime()
    {
        return arrivalTime;
    }

    int getBurstTime()
    {
        return burstTime;
    }
};

// 比较抵达时间
bool compareArrival(Process &a, Process &b)
{
    return a.getArrivalTime() < b.getArrivalTime() ? true : false;
}

// 比较执行时间
bool compareBurst(Process &a, Process &b)
{
    return a.getBurstTime() < b.getBurstTime() ? true : false;
}

// 计算平均周转时间
double calculateTime(int time, int num)
{
    return time / num;
}

// 先来先服务
void FCFS(vector<Process> &process)
{
    sort(process.begin(), process.end(), compareArrival);
    int currentTime = 0;
    int turnoverTime = 0;
    for (auto &i : process)
    {

        if (currentTime < i.getArrivalTime())
            currentTime = i.getArrivalTime();
        currentTime += i.getBurstTime();
        cout << "进程ID:" << i.getId() << "  完成时间：" << currentTime << "\n";
        turnoverTime += (currentTime - i.getArrivalTime());
    }
    cout << "平均调度时间：" << calculateTime(turnoverTime, process.size()) << "\n";
}

// 短作业优先
void SJF(vector<Process> &process)
{
    // sort(process.begin(), process.end(), compareBurst);
    // int currentTime = 0;
    // int turnoverTime = 0;
    // for (auto &i : process)
    // {
    //     if (currentTime < i.getArrivalTime())
    //         currentTime = i.getArrivalTime();
    //     currentTime += i.getBurstTime();
    //     cout << "进程ID:" << i.getId() << "  完成时间：" << currentTime << "\n";
    //     turnoverTime += (currentTime - i.getArrivalTime());
    // }
    // cout << "平均调度时间：" << calculateTime(turnoverTime, process.size()) << "\n";

    sort(process.begin(), process.end(), compareArrival);
    int currentTime = 0;
    int turnoverTime = 0;
    vector<Process> tmpProcess = process;

    while (!tmpProcess.empty())
    {
        int index = -1;
        for (int i = 0; i < tmpProcess.size(); ++i)
        {
            if (tmpProcess[i].getArrivalTime() <= currentTime && (index == -1 || tmpProcess[i].getBurstTime() < tmpProcess[index].getBurstTime()))
            {
                index = i;
            }
        }

        if (index == -1)
        {
            currentTime = tmpProcess[0].getArrivalTime();
            continue;
        }

        Process &shortestProcess = tmpProcess[index];
        currentTime += shortestProcess.getBurstTime();
        cout << "进程ID:" << shortestProcess.getId() << "  完成时间：" << currentTime << "\n";
        turnoverTime += (currentTime - shortestProcess.getArrivalTime());

        tmpProcess.erase(tmpProcess.begin() + index);
    }
    cout << "平均调度时间：" << calculateTime(turnoverTime, process.size()) << "\n";
}

int main()
{
    vector<Process> process;
    process.push_back(Process(1, 0, 10));
    process.push_back(Process(2, 20, 20));
    process.push_back(Process(3, 30, 10));
    process.push_back(Process(4, 20, 5));

    cout << "FCFS"
         << "\n";
    FCFS(process);

    cout << "SJF:"
         << "\n";
    SJF(process);
}