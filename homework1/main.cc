// Convert this program to C++
// * change to C++ io
// * change to one line comments
// * change defines of constants to const
// * change array to vector<>
// * inline any short function

#include <iostream>
#include <vector>

using namespace std;

inline int sum(const vector<int>& data, int sum = 0)
{
  for (vector<int>::const_iterator it = data.begin(); it < data.end(); ++it)
    sum += *it;
  return sum;
}

int main()
{
  const int N = 40; 
  std::vector<int> data(N);
  for (int i = 0; i < N; ++i)
    data[i] = i;

  cout << "sum is " << sum(data) << endl;
  return 0;
}
