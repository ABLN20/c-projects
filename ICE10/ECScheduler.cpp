// implement a task scheduler based on the Singleton pattern

#include <iostream>
#include <set>
using namespace std;

class ECScheduler
{
public:
  static ECScheduler& Instance() 
  {
    static ECScheduler instance;
    return instance;
  }

  void StartTask(int id) 
  {
    runningTasks.insert(id);
  }

  void StopTask(int id) 
  {
    runningTasks.erase(id);
  }

  int GetNumRunTasks() const 
  {
    return runningTasks.size();
  }
  
private:
  ECScheduler() {}
  ~ECScheduler() {}

  ECScheduler(const ECScheduler&) = delete;
  ECScheduler& operator=(const ECScheduler&) = delete;

  set<int> runningTasks;
};
