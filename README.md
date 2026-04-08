# Exhaustive Verification for Triangle Packing Inequalities

This repository contains the C++ code used to verify, by exhaustive search, a key inequality appearing in our paper on triangle packings.

## 📌 Purpose

We verify that for all integer parameters
[
1 \le \ell, m \le 10,\quad 0 \le x_\ell < \ell,\quad 0 \le x_m < m,
]
satisfying
[
\ell + x_m \le m + x_\ell, \quad \ell - x_\ell \le x_\ell + x_m,
]
at least one of the quantities
[
f_i(\ell, m, x_\ell, x_m) = 6|P_i| - 3|T_2|, \quad i = 1,\dots,8,
]
is greater than (-3).

## 🧠 Mathematical Background

* The functions (P_{13}, \dots, P_{17}) correspond to triangle packings defined in the paper.
* The function (T_2) is a triangle hitting set defined in the paper
* The packing functions are implemented using Propositions 4 and 5 of the paper.

## ⚙️ How to Compile and Run

Compile with:

```bash
g++ -O2 -std=c++17 main.cpp -o verify
```

Run:

```bash
./verify
```

## ✅ Output

* Any printed tuple ((\ell, m, x_\ell, x_m)) corresponds to a counterexample.


## 🔍 Reproducibility

This code is provided to ensure that the computational verification in the paper can be independently checked and reproduced.

## 👨‍💻 Authors

Luis Chahua, Juan Gutiérrez

