#include <numeric>
#include <iostream>
#include <vector>

using namespace std;

class RandomVector{
  std::vector<double> vect;
  
  public:
    RandomVector(unsigned int size, double max_val = 1) {
  // TODO: Write your code here
  vect = vector<double>(size);
  for (int i = 0; i < size; ++i) {
    vect[i] = rand() * max_val / RAND_MAX;
  }
}

void print(){
  // TODO: Write your code here
  for (unsigned int i = 0; i < vect.size(); ++i) {
    std::cout << vect[i] << "  ";
  }
  std::cout << endl;
}

double mean(){
  // TODO: Write your code here
  if (vect.empty()) {
    return 0;
  }
  return std::accumulate(vect.begin(), vect.end(), 0.0)/vect.size();
}

double max(){
  // TODO: Write your code here
  double max_element = vect[0];
  for (unsigned int i = 1; i < vect.size(); ++i){
  	if (vect[i] > max_element) {
  		max_element = vect[i];
  	}
  }
  return max_element;
}

double min(){
  //TODO:  Write your code here
  double min_element = vect[0];
  for (unsigned int i = 1; i < vect.size(); ++i){
  	if (vect[i] < min_element) {
  		min_element = vect[i];
  	}
  }
  return min_element;
}

void printHistogram(int bins){
  // TODO: Write your code here
  double min = this->min();
  double range = max() - min;
  double bin_size = range / bins;
  vector<int> bins_counter = std::vector<int>(bins, 0);
  for (unsigned int i = 0; i < vect.size(); ++i) {
    double data = vect[i];
    int index = (data - min) / bin_size;
    bins_counter[index]++;
  }
  int max_count = -1;
  int max_idx = -1;
  for (unsigned int i = 0; i < bins; ++i) {
    if (bins_counter[i] >= max_count) {
      max_count = bins_counter[i];
      max_idx = i;
    }
  }
  for (unsigned int i = max_count; i > 0; --i) {
    for (unsigned int j = 0; j < max_idx; ++j) {
      if (bins_counter[j] >= i) {
        cout << "*** ";
      } else {
        cout << "    ";
      }
    }
    cout << "***";
    for (unsigned int j = max_idx + 1; j < bins; ++j) {
      int temp_count = 0;
      if (bins_counter[j] < i) temp_count++;
      else {
        for (unsigned int k = 0; k < temp_count; ++k) {
          cout << "    ";
        }
        cout << " ***";
        max_idx += temp_count + 1;
        temp_count = 0;
      }
    }
    cout << "\n";
  }
}

};


// TODO: add any include you might require

