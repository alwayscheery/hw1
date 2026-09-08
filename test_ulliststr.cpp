#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cassert>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr list;
  assert(list.empty());
  assert(list.size() == 0);

  list.pop_front();
  list.pop_back();
  assert(list.empty());

  list.push_back("one");
  list.push_back("two");
  assert(list.front() == "one");
  assert(list.back() == "two");

  list.push_front("zero");

}
