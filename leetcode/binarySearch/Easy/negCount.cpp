class Solution
{
public:
  int countNegatives(vector<vector<int>> &grid)
  {
    int neg_count = 0;
    for (auto &gr : grid)
    {
      int low = 0, high = gr.size() - 1;
      while (low <= high)
      {
        int mid = low + (high - low) / 2;
        if (gr[mid] >= 0)
          low = mid + 1;
        else
        {
          neg_count = neg_count + high - mid + 1;
          high = mid - 1;
        }
      }
    }
    return neg_count;
  }
};