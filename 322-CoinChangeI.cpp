class Solution
{
public:
  int coinChange(vector<int> &coins, int x)
  {
    queue<int> q;
    q.push(x);
    int lvl = 0;
    set<int> vis;
    while (!q.empty())
    {
      int size = q.size();
      while (size--)
      {
        auto f = q.front();
        if (f == 0)
        {
          return lvl;
        }
        q.pop();
        for (auto y : coins)
        {
          if (f - y >= 0)
          {
            if (vis.find(f - y) == vis.end())
            {
              vis.insert(f - y);
              q.push(f - y);
            }
          }
        }
      }
      lvl++;
    }

    return -1;
  }
};