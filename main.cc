#include <unistd.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>

using namespace std;

random_device rd;
mt19937 mt(rd());
uniform_real_distribution<double> dist(1.0, 10.0);

const char bin_version[] = "1.0.0";

// TODO(everdrone): specify options in usage
void usage() {
  cout << endl;
  cout << "Usage:\n  cssname cssname [-spd] [-n COUNT]" << endl;
  cout << endl;
  cout << "Options:" << endl;
  cout << "  -s               single noun" << endl;
  cout << "  -d               double noun pair" << endl;
  cout << "  -p               adjective-noun pair" << endl;
  cout << "  -n NUM           repeat NUM times" << endl;
  cout << "  -v, --version    print version information and quit" << endl;
  cout << "  -h, --help       print this message and quit" << endl;
  cout << endl;
}

void version() {
  cout << "cssname " << bin_version << endl;
}

vector<string> read_file(string fname) {
  ifstream file;
  file.open(fname);

  // check if we have a file
  if (!file) {
    cout << "Error opening " << fname << endl;
    exit(1);
  }

  // read the file into a vector
  istream_iterator<string> start(file), end;
  vector<string> words(start, end);
  return words;
}

string pick(vector<string> *vec) {
  // pick randomly
  random_device random_device;
  mt19937 engine{random_device()};
  uniform_int_distribution<int> dist(0, vec->size() - 1);
  // assign lowercase string
  string out = vec->at(dist(engine));
  // make uppercase
  transform(out.begin(), out.end(), out.begin(), ::toupper);
  return out;
}

// TODO(everdrone): add help option
int main(int argc, char *argv[]) {
  vector<string> nouns, adjectives;
  nouns = read_file("nouns.txt");
  adjectives = read_file("adjectives.txt");

  int c;

  int iterations = 1;
  char mode = 'p';

  while ((c = getopt(argc, argv, "vhpsdn:")) != -1) {
    switch (c) {
    case 'v':
      // print version and exit
      version();
      return 0;
      break;
    case 'h':
      // print version and exit
      usage();
      return 0;
      break;
    case 's':
      mode = 's';
      break;
    case 'd':
      mode = 'd';
      break;
    case 'p':
      mode = 'p';
      break;
    case 'n':
      // number of iterations
      if (optarg) iterations = atoi(optarg);
      break;
    }
  }

  for (int i = 0; i < iterations; ++i) {
    switch (mode) {
    case 's':
      cout << pick(&nouns) << endl;
      break;
    case 'd':
      cout << pick(&nouns) << pick(&nouns) << endl;
      /* code */
      break;
    case 'p':
      cout << pick(&adjectives) << pick(&nouns) << endl;
      /* code */
      break;
    }
  }

  return 0;
}
