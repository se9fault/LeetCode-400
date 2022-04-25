# 01-Array
Note: Click on the number to go to the source code; click on the name to go to the LeetCode website.

- [x] [277](277_Find_the_Celebrity.cpp) [Find the Celebrity](https://leetcode.com/problems/find-the-celebrity/description/) Premium

    All the nodes points to the celebrity, so use a celebrity candidate and validate the candidate through 3 passes of the array.

- [x] [041](041_First_Missing_Positive.cpp) [First Missing Positive](https://leetcode.com/problems/first-missing-positive/description/)

    Swap the numbers by the rule "x should be at `nums[x-1]`". Search again, and the first misplaced location is the answer.

- [x] [134](134_Gas_Station.cpp) [Gas Station](https://leetcode.com/problems/gas-station/description/)

    If out of gas at station `i`, start at `i+1`, but record current deficit. When all stations are finished, check if tank can cover all the deficit.

- [x] [118](118_Pascal's_Triangle.cpp) [Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/description/) Infrequent

- [x] [119](119_Pascal's_Triangle_II.cpp) [Pascal's Triangle II](https://leetcode.com/problems/pascals-triangle-ii/description/) Infrequent

    Use O(N) space by calculating from right to left.

- [x] [274](274_H-Index.cpp) [H-Index](https://leetcode.com/problems/h-index/description/)

    First sort the array in ascending order. Then if the i-th citation ≥ N-i, the remaining N-i citations must all be ≥ N-i, hence the H-index is N-i.

- [x] [275](275_H-Index_II.cpp) [H-Index II](https://leetcode.com/problems/h-index-ii/description/) Co-listed with 08

    The given citation is already in ascending order, therefore we use binary search.

- [x] [243](243_Shortest_Word_Distance.cpp) [Shortest Word Distance](https://leetcode.com/problems/shortest-word-distance/description/) Premium

    Use an variable `idx` to store the idx of either words' last apperance in the vector, and calculate and compare diff when another word appears.

- [x] [244](244_Shortest_Word_Distance_II.cpp) [Shortest Word Distance II](https://leetcode.com/problems/shortest-word-distance-ii/description/) Premium

    As the method will be called multiple times, we use a hash table of `<words, vector<index where the word appears>>`, and check the two vectors of the two words upon each call to see the shortest distance. In implementation we use one while loop, and only increase one of the loop variables in each iteration.

- [x] [245](245_Shortest_Word_Distance_III.cpp) [Shortest Word Distance III](https://leetcode.com/problems/shortest-word-distance-iii/description/) Premium

    The same as [243](243_Shortest_Word_Distance.cpp) except that `word1` may be the same with `word2`. The original solution still works with a small modification.

- [x] [217](217_Contains_Duplicate.cpp) [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/description/)

    One solution would be sort it and check. Another is to put all the elements into an unordered_set, and check whether the element is already in during the process.

- [x] [219](219_Contains_Duplicate_II.cpp) [Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii/description/) Infrequent

    Use an unordered_map to store the last location of an element, and when the element exists check whether `distance ≤ k`.

- [x] [220](220_Contains_Duplicate_III.cpp) [Contains Duplicate III](https://leetcode.com/problems/contains-duplicate-iii/description/) Infrequent, Co-listed with 09

    Use bucket sort

- [x] [011](011_Container_With_Most_Water.cpp) [Container With Most Water](https://leetcode.com/problems/container-with-most-water/description/)

    Use two pointers on both sides moving towards middle, criteria being always finding a longer side for the shorter pointer.

- [x] [128](128_Longest_Consecutive_Sequence.cpp) [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/description/)

- [x] [164](164_Maximum_Gap.cpp) [Maximum Gap](https://leetcode.com/problems/maximum-gap/description/)

- [x] [287](287_Find_the_Duplicate_Number.cpp) [Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/description/) loop in linked list

- [x] [330](330_Patching_Array.cpp) [Patching Array](https://leetcode.com/problems/patching-array/description/) Infrequent


## In-place Deletion

- [x] [027](027_Remove_Element.cpp) [Remove Element](https://leetcode.com/problems/remove-element/)

- [x] [026](026_Remove_Duplicates_from_Sorted_Array.cpp) [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/)

- [x] [080](080_Remove_Duplicates_from_Sorted_Array_II.cpp) [Remove Duplicates from Sorted Array II](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/)

    The solutions are essentially "double pointer": the fast pointer (iterator n) access all the elements, and the slow pointer (i) records the location of stored `nums` which satisfy the condition.

    Only when the fast pointer's element satisfy the condition will it be stored into the location of the slow pointer (`nums[i++] = n`, [027](027_Remove_Element.cpp) & [080](080_Remove_Duplicates_from_Sorted_Array_II.cpp)), or the next location of the slow pointer (`nums[++i] = n`, [026](026_Remove_Duplicates_from_Sorted_Array.cpp))。


## Boyer-Moore majority vote algorithm

- [x] [169](169_Majority_Element.cpp) [Majority Element](https://leetcode.com/problems/majority-element/description/) Infrequent

    To log the element appears more than `⌊n/2⌋` times, record 1 candidate and its count.

- [X] [229](229_Majority_Element_II.cpp) [Majority Element II](https://leetcode.com/problems/majority-element-ii/description/) Infrequent

    To log the elements appear more than `⌊n/3⌋` times, record 2 candidates and their count. Count the array again to see if they truly appears more than `⌊n/3⌋` times.

- [x] [299](299_Bulls_and_Cows.cpp) [Bulls and Cows](https://leetcode.com/problems/bulls-and-cows/) Similar counting technique

    Use an array of 10 digits (0~9) to count the secret(+) and guess(-). When the count reaches 0, they cancelled out and that's a cow.


## Left to Right, Right to Left

- [x] [042](042_Trapping_Rain_Water.cpp) [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/description/)

- [x] [135](135_Candy.cpp) [Candy](https://leetcode.com/problems/candy/description/)


## Rotate Array

- [x] [189](189_Rotate_Array.cpp) [Rotate Array](https://leetcode.com/problems/rotate-array/description/)

    Move array by k = flip the array 3 times.

- [x] [033](../08-Searching/033_Search_in_Rotated_Sorted_Array.cpp) [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/description/) Co-listed with 08

- [ ] [081](../08-Searching/081_Search_in_Rotated_Sorted_Array_II.cpp) [Search in Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/)

- [ ] [153](../08-Searching/153_Find_Minimum_in_Rotated_Sorted_Array.cpp) [Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/)

- [ ] [154](../08-Searching/154_Find_Minimum_in_Rotated_Sorted_Array_II.cpp) [Find Minimum in Rotated Sorted Array II](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/)


## Longest Increasing Subsequence

- [x] [334](334_Increasing_Triplet_Subsequence.cpp) [Increasing Triplet Subsequence](https://leetcode.com/problems/increasing-triplet-subsequence/description/)


## Advanced

- [ ] [004](004_Median_of_Two_Sorted_Arrays.cpp) [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/description/) Binary Search

- [ ] [321](321_Create_Maximum_Number.cpp) [Create Maximum Number](https://leetcode.com/problems/create-maximum-number/description/) Infrequent

- [ ] [327](327_Count_of_Range_Sum.cpp) [Count of Range Sum](https://leetcode.com/problems/count-of-range-sum/description/)


## Interval

- [x] [056](056_Merge_Intervals.cpp) [Merge Intervals](https://leetcode.com/problems/merge-intervals/description/)

- [x] [057](057_Insert_Interval.cpp) [Insert Interval](https://leetcode.com/problems/insert-interval/description/) simplified 056

- [x] [252](252_Meeting_Rooms.cpp) [Meeting Rooms](https://leetcode.com/problems/meeting-rooms/description/) Premium

- [x] [253](253_Meeting_Rooms_II.cpp) [Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/description/) Premium

- [ ] [352](352_Data_Stream_as_Disjoint_Intervals.cpp) [Data Stream as Disjoint Intervals](https://leetcode.com/problems/data-stream-as-disjoint-intervals/description/)


## Counter

- [x] [239](239_Sliding_Window_Maximum.cpp) [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/description/) monotonic queue

- [ ] [295](295_Find_Median_from_Data_Stream.cpp) [Find Median from Data Stream](https://leetcode.com/problems/find-median-from-data-stream/description/)

- [x] [053](053_Maximum_Subarray.cpp) [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/description/) dp

- [x] [325](325_Maximum_Size_Subarray_Sum_Equals_k.cpp) [Maximum Size Subarray Sum Equals k](https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/) Premium

- [ ] [209](209_Minimum_Size_Subarray_Sum.cpp) [Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/description/)

- [ ] [238](238_Product_of_Array_Except_Self.cpp) [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/description/)

- [ ] [152](152_Maximum_Product_Subarray.cpp) [Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/description/)

- [ ] [228](228_Summary_Ranges.cpp) [Summary Ranges](https://leetcode.com/problems/summary-ranges/description/)

- [ ] [163](163_Missing_Ranges.cpp) [Missing Ranges](https://leetcode.com/problems/missing-ranges/description/) Premium


## Counter

- [x] [075](075_Sort_Colors.cpp) [Sort Colors](https://leetcode.com/problems/sort-colors/description/) Dutch flag

- [x] [283](283_Move_Zeroes.cpp) [Move Zeroes](https://leetcode.com/problems/move-zeroes/description/)

- [ ] [376](376_Wiggle_Subsequence.cpp) [Wiggle Subsequence](https://leetcode.com/problems/wiggle-subsequence/description/)

- [ ] [280](280_Wiggle_Sort.cpp) [Wiggle Sort](https://leetcode.com/problems/wiggle-sort/description/) Premium

- [ ] [324](324_Wiggle_Sort_II.cpp) [Wiggle Sort II](https://leetcode.com/problems/wiggle-sort-ii/description/)


## Matrix

- [x] [048](048_Rotate_Image.cpp) [Rotate Image](https://leetcode.com/problems/rotate-image/description/)

- [x] [054](054_Spiral_Matrix.cpp) [Spiral Matrix](https://leetcode.com/problems/spiral-matrix/description/)

- [x] [059](059_Spiral_Matrix_II.cpp) [Spiral Matrix II](https://leetcode.com/problems/spiral-matrix-ii/description/)


## Matrix

- [x] [073](073_Set_Matrix_Zeroes.cpp) [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/description/)

- [x] [289](289_Game_of_Life.cpp) [Game of Life](https://leetcode.com/problems/game-of-life/description/)

- [ ] [311](311_Sparse_Matrix_Multiplication.cpp) [Sparse Matrix Multiplication](https://leetcode.com/problems/sparse-matrix-multiplication/description/) Premium

- [ ] [378](378_Kth_Smallest_Element_in_a_Sorted_Matrix.cpp) [Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/)

- [x] [240](240_Search_a_2D_Matrix_II.cpp) [Search a 2D Matrix II](https://leetcode.com/problems/search-a-2d-matrix-ii/description/)
- [ ] [370](370_Range_Addition.cpp) [Range Addition](https://leetcode.com/problems/range-addition/description/) Premium

- [ ] [296](296_Best_Meeting_Point.cpp) [Best Meeting Point](https://leetcode.com/problems/best-meeting-point/description/) Premium

- [ ] [361](361_Bomb_Enemy.cpp) [Bomb Enemy](https://leetcode.com/problems/bomb-enemy/description/) Premium

- [ ] [317](317_Shortest_Distance_from_All_Buildings.cpp) [Shortest Distance from All Buildings](https://leetcode.com/problems/shortest-distance-from-all-buildings/description/) Premium

- [ ] [302](302_Smallest_Rectangle_Enclosing_Black_Pixels.cpp) [Smallest Rectangle Enclosing Black Pixels](https://leetcode.com/problems/smallest-rectangle-enclosing-black-pixels/description/) Premium

- [x] [036](036_Valid_Sudoku.cpp) [Valid Sudoku](https://leetcode.com/problems/valid-sudoku/description/)

- [ ] [037](037_Sudoku_Solver.cpp) [Sudoku Solver](https://leetcode.com/problems/sudoku-solver/description/)
