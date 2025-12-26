#include <algorithm>
#include <cassert>
#include <numeric>
#include <random>
#include <vector>

std::pair<int, int> find_winning_strategies(const std::vector<int> &indices, int m)
{
  const auto n = (int)indices.size();
  auto index = indices[n - 1];
  const auto end = std::min(index + m, n);
  while (index > 0)
  {
    auto next_index = indices[index - 1];
    if (auto beg = next_index + m; beg <= index)
    {
      return std::pair{beg, end};
    }
    index = next_index;
  }
  return std::pair{0, end};
}

std::vector<double> estimate(int n, int m, int num_tests)
{
  std::vector<double> result(n);
  std::vector<int> permutation(n);
  std::iota(permutation.begin(), permutation.end(), 0);
  std::random_device rd;
  std::mt19937 g(rd());
  std::vector<int> indices(n);
  for (auto i = 0; i < num_tests; ++i)
  {
    std::shuffle(permutation.begin(), permutation.end(), g);
    int index = 0;
    indices[0] = 0;
    int max_value = permutation[0];
    for (auto j = 1; j < n; ++j)
    {
      if (permutation[j] > max_value)
      {
        index = j;
        max_value = permutation[j];
      }
      indices[j] = index;
    }
    const auto [beg, end] = find_winning_strategies(indices, m);
    for (auto j = beg; j < end; ++j)
    {
      ++result[j];
    }
  }
  for (auto i = 0; i < n; ++i)
  {
    result[i] /= num_tests;
  }
  return result;
}

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

PYBIND11_MODULE(cpp, m, py::mod_gil_not_used())
{
  m.def("estimate", &estimate);
}