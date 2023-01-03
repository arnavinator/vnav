#include "random_vector.h"

RandomVector::RandomVector(int size, double max_val) { 
  for (int i=0; i < size; i++) {
  	vect.push_back((double) rand()/RAND_MAX * max_val);
  }
}

void RandomVector::print(){
	for (auto &elem : vect) {
		std::cout << elem << ' ';
	}  
	std::cout << std::endl;
}

double RandomVector::mean(){
	  double mean {};
	  for (auto &elem : vect) {
		mean += elem;
	  }
	  return mean/vect.size();
}

double RandomVector::max(){
	  double max {vect[0]};
	  for (auto &elem : vect) {
		if (max < elem) {
			max = elem;
		}
	  }
	  return max;
}

double RandomVector::min(){
	  double min {vect[0]};
	  for (auto &elem : vect) {
		if (min < elem) {
			min = elem;
		}
	  }
	  return min;
}

void RandomVector::printHistogram(int bins){
  std::vector<int> hist_bins (bins, 0); // create vector of bins entries with 0s
  double bin_width {RandomVector::max()/bins+0.0001};
  for (auto &elem : vect) {
    hist_bins[(int)(elem/bin_width)]++; // increment the bin to which it belongs
  }
  
  // print pattern from hist_bins
  // find max of hist_bins so we know height of figure
  int max_val {0};
  for (auto &elem : hist_bins) {
    if (elem > max_val) {
      max_val = elem;
    }
  }
  // print the stars
  std::string stars;
  for (int i=max_val; i>0; i--) {
    for (auto &elem : hist_bins) {
      if (elem == i) {
        stars += "*** ";
        elem--;
      } else {
        stars += "    ";
      }
    }
    stars += '\n';
  }
  std::cout << stars << '\n';

}

