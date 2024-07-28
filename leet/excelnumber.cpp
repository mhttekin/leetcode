#include <string>
using namespace std;

int titleToNumber(string columnTitle) {
  int result = 0, index = 0;
  while(columnTitle.length() > 0)
  {
    int length = columnTitle.length() - 1;
    int i = columnTitle[length] - 'A' + 1;
    if(index != 0) i *= 26;
    ++index;
    result += i;
    columnTitle.pop_back();
  }
  return result;
}
