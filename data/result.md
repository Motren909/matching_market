## How to run?
Built by GNU v8.1.0
on Windows, simply run `./build/price.exe`
on Linux
```bash
cd build
rm -r *

cmake ..
make
./price
```

## Input Format
```c++
/*
Input Format:
Number of Buyers
Valuation Matrix
*/

//For example:
3
12 4 2
8 7 6
7 5 2
```
## Test Data
### Input
```c++
26
0 0 50 40 50 0 30 30 30 40 0 0 0 0 30 30 30 50 20 40 50 50 0 30 0 40
20 15 10 0 20 0 20 18 10 0 0 0 0 0 0 0 0 5 5 0 20 20 0 0 0 5
20 20 30 20 0 10 30 20 30 30 20 10 20 30 20 20 20 0 0 0 10 0 20 20 20 20
10 0 30 30 10 0 0 0 0 0 5 40 0 30 20 0 0 0 0 10 10 10 30 30 40 10
10 0 0 10 0 20 0 0 0 0 30 0 0 0 30 0 40 10 0 0 0 40 100 0 100 20
21 25 34 23 20 24 19 18 19 21 25 28 23 17 20 10 13 36 8 15 16 16 28 25 16 18
15 35 10 40 25 25 10 5 0 0 0 0 0 0 0 0 0 15 10 0 10 5 10 20 10 5
20 5 0 5 0 5 5 5 5 5 5 2 0 0 2 0 0 2 2 0 2 2 5 2 2 2
35 45 15 45 30 22 20 20 18 15 20 15 18 15 15 35 40 33 22 32 20 35 22 18 20 35
0 22 0 0 0 15 0 0 25 0 0 0 0 0 0 0 0 30 0 0 0 0 0 0 0 0
10 0 10 0 50 0 0 0 0 0 15 0 0 5 0 0 0 15 0 0 0 0 0 0 0 0
40 30 60 30 70 30 20 0 0 10 0 40 30 40 30 0 0 0 0 30 30 35 30 40 40 30
0 20 0 10 50 10 28 20 18 8 0 10 25 50 10 0 40 0 10 30 10 30 0 16 0 10
10 20 10 35 40 25 20 20 20 10 20 10 10 10 10 10 20 10 20 20 25 25 20 10 20 25
10 18 0 10 0 0 28 20 12 10 5 8 12 0 10 0 10 0 0 25 10 15 20 8 20 10
5 18 5 5 0 5 5 25 24 18 5 5 16 5 20 5 5 5 5 29 21 29 5 5 11 15
0 25 0 35 0 25 30 40 40 25 0 0 0 20 0 0 0 0 0 0 25 0 0 35 0 0
30 10 30 20 5 25 10 15 15 1 1 5 20 20 10 2 25 2 25 10 20 30 10 10 10 10
0 0 30 15 25 10 20 20 5 0 35 20 21 45 10 0 45 30 0 0 18 25 0 20 0 5
30 40 40 40 100 30 20 20 20 100 56 10 10 50 10 20 20 35 5 5 5 10 20 35 46 25
15 23 35 37 46 0 45 28 29 15 0 10 15 30 19 0 0 0 15 10 10 15 0 15 30 0
10 15 20 5 0 22 10 8 6 5 16 7 12 3 8 20 10 19 0 10 8 15 6 12 0 3
35 30 25 25 20 25 25 30 10 10 10 0 5 0 10 15 30 10 20 20 30 30 10 10 10 15
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

```
### Output
```c++
>>>Final Result:
Buyer 7 bought good 0 at price 11 with valuation 20
Buyer 8 bought good 1 at price 6 with valuation 45
Buyer 11 bought good 2 at price 9 with valuation 60
Buyer 6 bought good 3 at price 10 with valuation 40
Buyer 10 bought good 4 at price 19 with valuation 50
Buyer 21 bought good 5 at price 1 with valuation 22
Buyer 20 bought good 6 at price 11 with valuation 45
Buyer 22 bought good 7 at price 6 with valuation 30
Buyer 2 bought good 8 at price 6 with valuation 30
Buyer 19 bought good 9 at price 6 with valuation 100
Buyer 5 bought good 10 at price 0 with valuation 25
Buyer 3 bought good 11 at price 3 with valuation 40
Buyer 23 bought good 12 at price 0 with valuation 0
Buyer 12 bought good 13 at price 6 with valuation 50
Buyer 24 bought good 14 at price 0 with valuation 0
Buyer 25 bought good 15 at price 0 with valuation 0
Buyer 18 bought good 16 at price 6 with valuation 45
Buyer 9 bought good 17 at price 11 with valuation 30
Buyer 17 bought good 18 at price 0 with valuation 25
Buyer 15 bought good 19 at price 8 with valuation 29
Buyer 0 bought good 20 at price 8 with valuation 50
Buyer 1 bought good 21 at price 8 with valuation 20
Buyer 4 bought good 22 at price 3 with valuation 100
Buyer 16 bought good 23 at price 0 with valuation 35
Buyer 14 bought good 24 at price 3 with valuation 20
Buyer 13 bought good 25 at price 0 with valuation 25
VCG prices
11 6 9 10 19 1 11 6 6 6 0 3 0 6 0 0 6 11 0 8 8 8 3 0 3 0
Social Welfare:
936
```

## G12_bid
### Input
```c++
31
0 0 0 20 0 0 0 0 0 0 20 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 20 0 0
10 30 20 20 61 0 61 40 40 0 0 0 0 30 0 0 0 0 0 0 0 0 0 0 0 0 0 10 20 0 40
25 60 25 50 120 25 90 40 90 25 30 40 0 50 30 60 0 0 50 30 25 25 25 0 0 25 25 25 0 0 40
30 60 30 40 50 25 60 50 60 60 50 55 40 30 40 25 39 50 30 80 40 39 35 30 100 40 30 40 35 35 70
19 20 10 35 55 21 60 35 40 40 30 35 20 45 10 20 20 10 30 83 15 17 15 15 55 8 15 28 20 20 25
0 30 0 0 90 18 0 25 50 0 0 0 0 0 15 0 0 0 0 0 30 0 0 30 0 0 50 0 0 0 0
0 0 35 50 0 35 0 0 0 0 0 0 35 0 0 0 0 0 0 40 0 0 0 35 40 35 0 0 0 35 0
10 0 0 0 20 0 0 0 10 0 0 0 0 30 20 0 0 0 0 30 0 0 0 0 0 0 0 0 0 0 20
0 0 0 43 50 0 70 0 0 0 0 0 0 0 0 0 0 0 0 80 0 0 0 0 0 0 0 0 0 0 40
30 40 30 60 40 30 40 40 40 50 60 30 0 50 50 0 0 20 30 20 30 60 30 20 30 0 30 20 0 0 40
20 20 21 25 25 0 35 22 30 0 0 24 0 28 0 0 26 0 0 28 0 0 0 0 31 0 0 0 0 0 30
0 40 28 0 0 0 0 0 0 0 0 0 0 0 29 30 0 0 0 0 0 0 0 0 0 0 0 0 0 0 45
0 35 10 0 0 0 40 30 70 30 0 0 0 0 0 0 0 20 0 0 0 0 0 0 0 0 0 0 12 0 0
40 45 20 100 50 40 80 20 80 30 40 25 25 20 30 30 30 30 40 30 30 40 30 30 30 20 30 20 30 30 50
0 10 0 0 0 0 40 50 10 0 0 0 0 0 9 0 0 0 0 0 0 0 0 0 0 0 0 0 0 20 20
20 20 20 20 20 20 20 20 20 20 20 40 20 20 20 20 20 20 25 20 20 20 20 20 28 20 20 20 20 20 20
30 40 25 30 45 20 28 20 38 30 40 25 25 36 45 36 28 34 40 35 28 39 28 36 28 20 36 39 28 36 25
1 20 1 0 15 15 20 20 10 10 10 1 0 0 0 1 0 10 10 10 0 15 0 0 0 0 0 0 0 0 15
0 50 0 30 30 0 60 20 30 0 40 0 0 0 0 30 0 0 0 0 0 0 30 0 50 0 0 0 0 20 30
0 0 0 0 45 0 48 20 45 0 0 20 20 0 0 0 0 0 20 50 0 20 0 0 25 15 0 0 0 0 0
0 40 30 50 40 0 30 0 0 0 0 0 0 0 0 0 0 30 0 0 0 0 0 0 0 0 0 0 0 0 40
0 0 0 0 0 0 0 28 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 10 0 0 0 0 0
35 40 30 60 35 20 40 40 30 0 25 20 0 0 25 20 25 0 50 20 40 0 30 30 0 25 50 35 25 0 50
5 5 0 5 5 5 15 15 0 0 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5
10 13 14 10 14 10 10 11 13 12 11 11 13 12 10 10 10 10 12 11 12 8 10 11 12 11 12 13 11 12 11
0 20 15 0 0 0 0 0 0 0 0 0 30 0 0 0 30 0 0 0 0 0 0 0 0 0 0 0 0 0 25
20 50 10 30 40 10 20 10 30 10 10 10 10 10 10 10 0 0 0 0 0 0 0 0 0 0 0 0 0 0 20
25 40 15 50 50 15 86 30 60 26 38 17 25 70 20 20 30 50 35 30 15 20 20 30 70 20 45 20 30 20 40
30 50 10 10 70 10 50 70 30 10 10 10 15 10 30 10 10 10 10 10 10 10 20 30 10 20 15 10 30 20 60
30 50 30 25 50 40 60 40 40 50 40 40 30 60 40 30 30 40 50 60 40 30 30 30 40 30 30 30 30 30 50
0 0 0 0 0 0 0 0 0 0 18 0 19 0 0 0 15 0 0 0 0 0 0 0 0 0 0 0 15 18 0
```
### Output
```c++
>>>Final Result:
Buyer 10 bought good 0 at price 0 with valuation 20
Buyer 26 bought good 1 at price 16 with valuation 50
Buyer 1 bought good 2 at price 2 with valuation 20
Buyer 13 bought good 3 at price 20 with valuation 100
Buyer 2 bought good 4 at price 50 with valuation 120
Buyer 17 bought good 5 at price 0 with valuation 15
Buyer 8 bought good 6 at price 43 with valuation 70
Buyer 14 bought good 7 at price 32 with valuation 50
Buyer 12 bought good 8 at price 31 with valuation 70
Buyer 29 bought good 9 at price 10 with valuation 50
Buyer 18 bought good 10 at price 6 with valuation 40
Buyer 15 bought good 11 at price 6 with valuation 40
Buyer 19 bought good 12 at price 6 with valuation 20
Buyer 27 bought good 13 at price 20 with valuation 70
Buyer 7 bought good 14 at price 7 with valuation 20
Buyer 11 bought good 15 at price 0 with valuation 30
Buyer 25 bought good 16 at price 6 with valuation 30
Buyer 20 bought good 17 at price 0 with valuation 30
Buyer 22 bought good 18 at price 10 with valuation 50
Buyer 4 bought good 19 at price 53 with valuation 83
Buyer 24 bought good 20 at price 0 with valuation 12
Buyer 9 bought good 21 at price 6 with valuation 60
Buyer 23 bought good 22 at price 0 with valuation 5
Buyer 6 bought good 23 at price 0 with valuation 35
Buyer 3 bought good 24 at price 25 with valuation 100
Buyer 21 bought good 25 at price 1 with valuation 10
Buyer 5 bought good 26 at price 10 with valuation 50
Buyer 16 bought good 27 at price 1 with valuation 39
Buyer 0 bought good 28 at price 2 with valuation 20
Buyer 30 bought good 29 at price 2 with valuation 18
Buyer 28 bought good 30 at price 22 with valuation 60
VCG prices
0 16 2 20 50 0 43 32 31 10 6 6 6 20 7 0 6 0 10 53 0 6 0 0 25 1 10 1 2 2 22
Social Welfare:
1387
```

## Val4
### Input
```c++
14
30 0 0 15 25 5 0 30 5 0 5 5 10 10
20 30 20 20 35 25 20 20 45 32 50 36 43 43
10 8 10 0 8 0 10 5 8 5 8 8 8 5
0 30 0 40 40 0 0 45 0 50 0 0 0 40
5 3 15 2 7 0 15 0 2 5 3 4 3 10
3 10 5 0 0 0 0 0 8 0 12 5 15 15
35 35 35 35 70 20 5 50 40 50 70 30 65 55
30 20 20 0 0 0 40 20 30 20 50 10 50 10
0 10 0 0 0 0 10 10 30 0 0 0 5 30
10 15 10 10 5 35 20 40 18 26 22 18 10 20
0 20 0 0 15 0 20 0 0 20 0 0 0 0
45 45 60 0 0 10 0 50 30 50 60 10 75 50
0 10 0 0 0 0 0 20 20 40 10 5 5 10
5 20 0 0 20 5 0 20 10 20 5 30 10 10
```
### Output
```c++
>>>Final Result:
Buyer 2 bought good 0 at price 5 with valuation 10
Buyer 5 bought good 1 at price 5 with valuation 10
Buyer 4 bought good 2 at price 5 with valuation 15
Buyer 3 bought good 3 at price 0 with valuation 40
Buyer 6 bought good 4 at price 3 with valuation 70
Buyer 9 bought good 5 at price 0 with valuation 35
Buyer 10 bought good 6 at price 5 with valuation 20
Buyer 0 bought good 7 at price 5 with valuation 30
Buyer 1 bought good 8 at price 10 with valuation 45
Buyer 12 bought good 9 at price 10 with valuation 40
Buyer 7 bought good 10 at price 15 with valuation 50
Buyer 13 bought good 11 at price 3 with valuation 30
Buyer 11 bought good 12 at price 15 with valuation 75
Buyer 8 bought good 13 at price 10 with valuation 30
VCG prices
5 5 5 0 3 0 5 5 10 10 15 3 15 10
Social Welfare:
500

```