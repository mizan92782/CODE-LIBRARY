


/*
1. **std::lexicographical_compare:**
   - Compares two ranges lexicographically.
   - Header: `<algorithm>`
   - Example:
     ```cpp
     ! bool result = std::lexicographical_compare(first1, last1, first2, last2);
     ```

2. **std::lexicographical_compare (C++20):**
   - Overloaded version that allows custom comparison.
   - Header: `<algorithm>`
   - Example:
     ```cpp
    !  bool result = std::lexicographical_compare(first1, last1, first2, last2, comp);
     ```

3. **std::next_permutation:**
   - Rearranges elements into the next lexicographically greater permutation.
   - Header: `<algorithm>`
   - Example:
     ```cpp
      ! std::next_permutation(first, last);
     ```

4. **std::prev_permutation:**
   - Rearranges elements into the next lexicographically smaller permutation.
   - Header: `<algorithm>`
   - Example:
     ```cpp
      ! std::prev_permutation(first, last);
     ```

5. **std::is_permutation:**
   - Checks if a range is a permutation of another range.
   - Header: `<algorithm>`
   - Example:
   
    !  bool result = std::is_permutation(first1, last1, first2, last2);
     ```

6. **std::lexicographical_compare_3way (C++14):**
   - Compares two ranges lexicographically and returns a three-way result.
   - Header: `<algorithm>`
   - Example:
     ```cpp
    !  auto result = std::lexicographical_compare_3way(first1, last1, first2, last2);
     ```

These functions are part of the C++ Standard Library's `<algorithm>` header. The examples provided are simplified, and you should refer to the C++ documentation for detailed information on each function and its usage. Additionally, note that some functions or features might be available starting from specific C++ versions (as indicated in the comments)./

*/