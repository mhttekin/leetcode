#include <vector>
using namespace std;

vector<int> getRow(int rowIndex) 
{
  vector<int> result {1};

  for(int i = 0; i < rowIndex; ++i)
  {
    vector<int> next(result.size()+1,0);
    for(int j = 0; j < result.size(); ++j)
    {
      next[j] += result[j];
      next[j+1] += result[j];
    }
    result = next;
  }
  return result;
}
