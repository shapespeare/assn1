#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;

int main(int argv, char **argc) {
  map<string, int> words;
  ifstream fin(argc[1]);
  string nextword;
  
  while (fin >> nextword) {
    bool found = false;
    for (auto &[word, occurrence] : words) {
      if (word == nextword) {
        ++occurrence;
        found = true;
        break;
      }
    }
    if (!found)
      words.emplace_back(nextword, 1);
  }

  if (words.empty()) {
    cout << "Input is empty" << endl;
    return 0;
  }

  auto answer = max_element(words.begin(), words.end(),
    // Define a comparator
    [](auto &elem1, auto &elem2) {
      // Compare the occurrence first.
      return tie(elem1.second, elem1.first) < tie(elem2.second, elem2.first);
    }
  );

  cout << "Word '" << answer->first << "' appeared " << answer->second
       << " times." << endl;
  return 0;
}
