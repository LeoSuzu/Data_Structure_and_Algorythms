# Postfix Calculator

Postfix Calculator is a straightforward command-line calculator that performs arithmetic operations using postfix notation. It supports basic arithmetic operations, exponentiation, square root, average calculation, and modulo operation.

## Table of Contents
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
  - [Interactive Mode](#interactive-mode)
  - [Command-Line Mode](#command-line-mode)
- [Supported Operations](#supported-operations)
- [Contributing](#contributing)
- [License](#license)

## Getting Started

### Prerequisites

- C++ compiler (e.g., g++)
- Standard C++ Library

### Installation

1. Clone the repository:
```bash
  git clone https://github.com/yourusername/postfix-calculator.git
  cd postfix-calculator
```

2. Compile the source code:
```bash
  g++ main.cpp Calc.cpp NumStack.cpp -o postfix-calculator
```

## Usage

### Interactive mode:
Run the following command:
```bash
./postfix-calculator -p
```
Enter numbers separated by spaces and specify the operation at the end. For example:
```bash
2 3 +
````
Output: 5

## Command-Line Mode
Addition:
```bash
./postfix-calculator 2 3 +
```
Output: 5


Subtraction:
```bash
./postfix-calculator 2 3 -
```
Output: -1


Multiplication:
```bash
./postfix-calculator 4 7 "*"
// USE "" around asterix
```
Output: 28


Division:
```bash
./postfix-calculator 9 3 /
```
Output: 3


Exponentiation:
```bash
./postfix-calculator 2 3 e
```
Output: 8

Summation:
```bash
./postfix-calculator 2 2 2 2 2 s
```
Output: 10

Square root:
```bash
./postfix-calculator 9 r
```
Output: 3

Average:
```bash
./postfix-calculator 2 4 8 a
```

Modulo:
```bash
./postfix-calculator 9 3 %
```
Output: 0

Swap top two elements:
```bash
./postfix-calculator 2 3 x -
```
Output: 1

## Supported Operations
Addition (+)
Subtraction (-)
Multiplication (*)
Division (/)
Exponentiation (e)
Summation (s)
Square root (r)
Average (a)
Modulo (%)
Swap top two elements (x)

## Contributing
If you would like to contribute to this project, feel free to fork the repository and submit pull requests.

## License
This project is licensed under the MIT License.

Feel free to copy and paste this into your README file. Customize it based on your project's details and structure.

Tampere University of applied Sciences
@LeoSuzu 2024 / 02 / 12
leona.suzuki@tuni.fi


