# 443. String Compression
## Problem Statement
Given an array of characters `chars`, compress it using the following algorithm:
Begin with an empty string `s`. For each group of consecutive repeating characters in `chars`:
If the group's length is 1, append the character to `s`.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in `chars`.
After you are done modifying the input array, return the new length of the array.
You must write an algorithm that uses only constant extra space.
## Solution
The given code is a C++ implementation of a function called "compress" that takes a vector of characters as input and returns an integer. The purpose of this function is to compress the input vector by replacing consecutive repeated characters with the character followed by the count of repetitions.

Let's go through the code step by step to understand its functionality:

```cpp
class Solution {
public:
  int compress(vector<char>& chars) {
    int ans = 0;
```

- The code starts with the declaration of a class named "Solution" and a member function "compress" which takes a reference to a vector of characters (`vector<char>& chars`) as input. The function returns an integer.
- Inside the "compress" function, an integer variable `ans` is declared and initialized to 0. This variable will be used to track the final length of the compressed vector.

```cpp
    for (int i = 0; i < chars.size();) {
      const char letter = chars[i];
      int count = 0;
      while (i < chars.size() && chars[i] == letter) {
        ++count;
        ++i;
      }
```

- The code then enters a for loop that iterates over the characters in the input vector `chars`.
- Inside the loop, a constant character variable `letter` is assigned the value of the current character at index `i`.
- An integer variable `count` is declared and initialized to 0. This variable will keep track of the count of consecutive occurrences of the character `letter`.
- A nested while loop is used to count the number of consecutive occurrences of `letter` in the vector.
- The while loop condition ensures that we don't go out of bounds while iterating over the vector and that the current character is the same as `letter`. If both conditions are satisfied, `count` is incremented, and `i` is also incremented to move to the next character.

```cpp
      chars[ans++] = letter;
      if (count > 1)
        for (const char c : to_string(count))
          chars[ans++] = c;
    }
```

- After counting the consecutive occurrences of `letter`, the code assigns `letter` to the `ans`-th position in the vector `chars` and increments `ans`.
- If the count is greater than 1 (indicating repeated characters), the code converts the count to a string using the `to_string` function.
- Then, using a range-based for loop, each character in the count string is assigned to the `ans`-th position in the vector `chars`, and `ans` is incremented.

```cpp
    return ans;
  }
};
```

- Once the loop iterates over all the characters in the input vector, the function returns the final value of `ans`, which represents the length of the compressed vector.

In summary, the function compresses the input vector by replacing repeated characters with the character followed by the count of repetitions. The function returns the length of the compressed vector.
