#include <iostream>
#include <vector>

using namespace std;

class Bubble_sort_ex : public runtime_error
{
  public:

  explicit Bubble_sort_ex(const char *msg) : runtime_error(msg)
  {
  }

  explicit Bubble_sort_ex(string& msg) : runtime_error(msg)
  {
  }

  virtual ~Bubble_sort_ex()
  {
  }

  virtual const char* what() const noexcept
  {
    return runtime_error::what();
  }
};

template<class T>
class Bubble_sort
{
  public:

  Bubble_sort(vector<T>& in) : data_(in)
  {
  }

  virtual ~Bubble_sort()
  {
    cout << "~Bubble_sort\n";

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

  vector<T> Sort()
  {
    if (0 == data_.size())
    {
      cerr << "No data to sort!\n";
      //return false;
      throw Bubble_sort_ex("No data to sort");
    }

    size_t size_minus_1{ data_.size() - 1 };
    bool swapped { false };

    while (true)
    {
      for (size_t i{}; i < size_minus_1; ++i)
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

    //out = data_;

    return data_;
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
  do
  {
    vector<int> in { 64, 34, 25, 12, 22, 11, 90 };

    Bubble_sort<int> bs(in);

    vector<int> ret;

    cout << "Orig:   ";

    for (int i : in)
    {
      cout << i << ' ';
    }

    cout << endl;

    bool succ { bs.Sort(ret) };

    cout << "Sorted: ";

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
  }
  while (false);

  do
  {
    vector<int> in { 64, 34, 25, 12, 22, 11, 90 };

    Bubble_sort<int> bs(in);

    cout << "Orig:   ";

    for (int i : in)
    {
      cout << i << ' ';
    }

    cout << endl;

    cout << "Sorted: ";

    try
    {
      vector<int> ret = bs.Sort();

      for (int i : ret)
      {
        cout << i << ' ';
      }

      cout << endl;
    }
    catch (Bubble_sort_ex& ex)
    {
      cerr << "Exception: " << ex.what() << endl;
    }
  }
  while (false);

  cin.get();

  return 0;
}
