#include <unistd.h>
#include <getopt.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>

#include "config.h"
#include "nouns.hh"
#include "adjectives.hh"

#define NO_ARG        0
#define REQUIRED_ARG  1
#define OPTIONAL_ARG  2

using namespace std;

random_device rd;
mt19937 mt(rd());
uniform_real_distribution<double> dist(1.0, 10.0);

void usage() {
  cout << endl;
  cout << "Usage:" << endl;
  cout << "  " << PROJECT_NAME << " [-spd] [-n <number>]" << endl;
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
  cout << PROJECT_NAME << " " << PROJECT_VERSION << endl;
}

string pick(vector<string> *vec) {
  // pick randomly
  random_device random_device;
  mt19937 engine{random_device()};
  uniform_int_distribution<int> dist(0, vec->size() - 1);
  // assign lowercase string
  string out = vec->at(dist(engine));
  // make uppercase
  //out.replace(0, 1, 1, toupper(out[0]));
  out[0] = toupper(out[0]);
  //transform(out.begin(), out.end(), out.begin(), ::toupper);
  return out;
}

int main(int argc, char *argv[]) {
  // getopt config
  int c;
  const struct option longopts[] = {
    {"version", NO_ARG, 0, 'v'},
    {"help",    NO_ARG, 0, 'h'},
    {0,         0,      0, 0},
  };
  // disable getopt errors
  opterr = 0;

  int iterations = 1;
  char mode = 'p';

  while ((c = getopt_long(argc, argv, "vhpsdn:", longopts, &c)) != -1) {
    switch (c) {
    case 'v':
      // print version and exit
      version();
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
    case 'h':
      usage();
      return 0;
    case '?':
      if (optopt == 'n') {
        // no arguments were passed to -n
        cerr << "Error:\n  option `-n' requires an argument" << endl;
      } else if (isprint(optopt)) {
        // error occurred and character is printable
        cerr << "Error:\n  invalid option: `-" << static_cast<char>
             (optopt) << "'" << endl;
      } else {
        cerr << "Error:\n  invalid option" << endl;
      }
      cerr << endl;
      cerr << "Type `" << PROJECT_NAME << " --help' for details\n" << endl;
      return 1;
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
