# CSSNAME

NSA/CSS Program name generator

## Building

```sh
% mkdir build && cd build
% cmake ..
% make
% make install
```

## Usage

```
% cssname -p
SPOTLESSMISSION
```

```
% cssname -s
GROUND
```

```
% cssnamee -d
MAINCHARGE
```

```
% cssname -dn 3
CHEMICALFUEL
TEAMPOSSESSION
CONTEXTBURN
```

### Options

- `-p` prints adjective/noun pair (**default**)
- `-s` prints a single noun
- `-d` prints two nouns
- `-n` specifies how many names to output
