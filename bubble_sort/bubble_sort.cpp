#include <iostream>
#include <vector>

using namespace std;

template<class T>
class Bubble_sort
{
  public:

  Bubble_sort(vector<T>& in) : data_(in)
  {

  }

  virtual ~Bubble_sort()
  {
    data_.clear();
    data_.shrink_to_fit();
  }

  bool Sort(vector<T>& out)
  {
    if (0 == data_.size())
    {
      cerr << "No data to sort!\n";
      return false;
    }

    size_t size_minus_1 { data_.size() - 1 };
    bool swapped { false };

    while (true)
    {
      for (size_t i {}; i < size_minus_1; ++i)
      {
        if (data_.at(i) > data_.at(i + 1))
        {
          Swap(i, i + 1);
          swapped = { true };
        }
      }

      if (false == swapped)
      {
        break;
      }

      swapped = { false };
    }

    out = data_;

    return true;
  }

  private:

  void Swap(size_t a, size_t b)
  {
    T tmp = data_.at(a);
    data_.at(a) = data_.at(b);
    data_.at(b) = tmp;
  }

  vector<T> data_;
};

int main()
{
  vector<int> in { 64, 34, 25, 12, 22, 11, 90 };

  Bubble_sort<int> bs(in);

  vector<int> ret;

  bool succ { bs.Sort(ret) };

  if (succ)
  {
    for (int i : ret)
    {
      cout << i << ' ';
    }

    cout << endl;
  }
  else
  {
    cerr << "Failed\n";
  }

  cin.get();

  return 0;
}
