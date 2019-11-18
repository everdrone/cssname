# CSSNAME

NSA/CSS Program name generator

### Building

```sh
g++ main.cc -std=c++11
```

### Usage

```
% cssname -p
SPOTLESSMISSION

% cssname -s
GROUND

% cssnamee -d
MAINCHARGE

% cssname -d -n 3
CHEMICALFUEL
TEAMPOSSESSION
CONTEXTBURN
```

- `-p` prints adjective/noun pair (**default**)
- `-s` prints a single noun
- `-d` prints two nouns
- `-n` specifies how many names to output
