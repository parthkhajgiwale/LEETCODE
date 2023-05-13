# 557. Reverse String III
## Problem Statement
Given a string `s`, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
## Solution
This is a C++ implementation of a function named `reverseWords` that takes a string as input and returns a new string with the words in reverse order. Here is a line-by-line explanation of the code:

```c++
class Solution {
```
This code defines a class named `Solution` that contains the `reverseWords` function.

```c++
public:
  string reverseWords(string s) {
```
This line declares the `reverseWords` function as a public method of the `Solution` class that takes a string `s` as input and returns a string.

```c++
    int i = 0;
    int j = 0;
```
Two integer variables `i` and `j` are declared and initialized to 0.

```c++
    while (i < s.length()) {
```
This starts a `while` loop that iterates through the string `s` until the end of the string is reached.

```c++
      while (i < j || i < s.length() && s[i] == ' ')
        ++i;
```
This inner `while` loop increments the `i` variable until it points to the first character of a word in the string. It skips over any whitespace characters at the beginning of the string or between words.

```c++
      while (j < i || j < s.length() && s[j] != ' ')
        ++j;
```
This inner `while` loop increments the `j` variable until it points to the first non-word character after the word pointed to by `i`.

```c++
      reverse(begin(s) + i, begin(s) + j);
```
The `reverse` function is called with two iterators that define the range of characters to be reversed. In this case, the range is from the start of the word pointed to by `i` to the character immediately before the first non-word character pointed to by `j`.

```c++
    }
```
The outer `while` loop continues until the end of the string is reached.

```c++
    return s;
  }
};
```
The reversed string is returned.
