# Leetcode-Pratice

1. [DP](#dp)
2. [Graph](#graph)
3. [Data Structure](#data-structure)
3. [Binary Search](#binary-search)
3. [STL](#STL)
4. [Other](#other)
5. [Two Pointers](#two-pointers)
6. [Monotonic Stack/Queue](#monotonic-stackqueue)

## Binary Search

### Medium

- 33\. Search in Rotated Sorted Array
  - rotated sorted array

- 34\. Find First and Last Position of Element in Sorted Array

- 1201\. Ugly Number III
  - gcd, lcm

### Hard
- 1095\. Find in Mountain Array
  - binary search
  - mountain array

## DP

### Hard

- 72\. Edit Distance
  - text-edit-distance
  - classic

- 85\. Maximal Rectangle
  - monotonic stack
  - maximal rectangle

- 87\. Scramble String
  - $O(n^4)$

- 135\. Candy

- 174\. Dungeon Game
  - min initial health

- 312\. Burst Balloons
  - 區間 DP

- 403\. Frog Jump
  - $O(n^2*log(n))$
  - unordered_map

- 639\. Decode Ways II
  - memorize
  - count combination


### Medium

- 22\. Generate Parentheses
  - generate all legal parentheses permutation
  - dfs

- 45\. Jump Game II
  - Least step from left to right
  - $O(n)$

- 62\. Unique Paths

- 63\. Unique Paths II
  - pretty simple
  - compute unique path to right bottom

- 91\. Decode Ways
    - memorization

- 300\. Longest Increasing Subsequence
    - LIS
    - $O(nlog(n))$

- 334\. Increasing Triplet Subsequence
  - LIS length

- 377\. Combination Sum IV
  - 0/1 Knapsack
  - Unbounded Knapsack

- 518\. Coin Change II
  - 0/1 Knapsack
  - Unbounded Knapsack

- 647\. Palindromic Substrings
  - palindrome
  - 用 for loop 順序滾掉一維

- 718\. Maximum Length of Repeated Subarray
    - longest common substring

- 740\. Delete and Earn

- 1218\. Longest Arithmetic Subsequence of Given Difference
  - hash

- 1626\. Best Team With No Conflicts
  - sorting


- 1277\. Count Square Submatrices with All Ones
  - get total square number in matrix

- 2483\. Minimum Penalty for a Shop
    - prefix sum

- 2707\. Extra Characters in a String


## Graph

### Hard



- 51\. N-Queens
  - dfs
  - backtracking

- 332\. Reconstruct Itinerary
  - Euler Path
  - Greedy

- 778\. Swim in Rising Water
  - dijkstra

- 980\. Unique Paths III
  - find unique path in grid world
  - dfs

- 1203\. Sort Items by Groups Respecting Dependencies
  - bfs
  - topological sort

- 2462\. Design Graph With Shortest Path Calculator
  - floyd warshall
  - dynamic add edge


### Medium
- 98\. Validate Binary Search Tree
  - dfs
  - binary search tree

- 113\. Path Sum II
  - dfs

- 207\. Course Schedule
  - topological sort
  - bfs

- 210\. Course Schedule II
  - topological sort
  - dfs
  - check cycle

- 230\. Kth Smallest Element in a BST
  - dfs

- 236\. Lowest Common Ancestor of a Binary Tree
  - dfs
  - lowest common ancestor
  - binary tree
  - special case

- 842\. Split Array into Fibonacci Sequence
  - dfs

- 1448\. Count Good Nodes in Binary Tree
  - dfs

## Data Structure

### Medium

- 92\. Reverse Linked List II
  - linked list

- 547\. Number of Provinces
  - dsu

- 721\. Accounts Merge
  - dsu

- 725\. Split Linked List in Parts
  - linked list

- 973\. K Closest Points to Origin
  - priority queue

- 1268\. Search Suggestions System
  - trie

- 2497\. Maximum Star Sum of a Graph
  - heap

### Hard
- 295\. Find Median from Data Stream
    - heap
    - medium

## Monotonic Stack/Queue


### Hard

- 42\. Trapping Rain Water
  - monotonic stack

- 84\. Largest Rectangle in Histogram
  - monotonic stack

- 239\. Sliding Window Maximum
    - monotonic queue

- 2398\. Maximum Number of Robots Within Budget
  - deque

## STL

### Hard

- 85\. Maximal Rectangle
  - Classic
  - stack

### Medium
- 215\. Kth Largest Element in an Array
  - priority queue

- 621\. Task Scheduler
  - priority queue

- 729\. My Calendar I
  - map
  - upper_bound

## Two Pointers

### Hard
- 76\. Minimum Window Substring
  - 同向

### Medium

- 3\. Longest Substring Without Repeating Characters
  - 同向

- 11\. Container With Most Water
  - 相向

- 16\. 3Sum Closest
  - 相向

- 167\. Two Sum II - Input Array Is Sorted
  - 相向

- 395\. Longest Substring with At Least K Repeating Characters
  - 同向

- 424\. Longest Repeating Character Replacement
  - 同向

- 904\. Fruit Into Baskets
  - 同向

- 948\. Bag of Tokens
  - 相向

- 2271\. Maximum White Tiles Covered by a Carpet
  - 同向

### Easy

- 2485\. Find the Pivot Integer
  - 相向

## Other

### Hard

- 149\. Max Points on a Line
  - gcd
  - slope
  - $O(n^2*log(n))$

- 1326\. Minimum Number of Taps to Open to Water a Garden
    - greedy

- 2366\. Minimum Replacements to Sort the Array
    - greedy

### Medium

- 54\. Spiral Matrix

- 138\. Copy List with Random Pointer
  - linked list

- 148\. Sort List
  - merge sort
  - linked list
  - in-place

- 151\. Reverse Words in a String
  - stringstream

- 189\. Rotate Array
  - divide and conquer

- 240\. Search a 2D Matrix II
  - 2D Ascending Matrix search target
  - O(n+m)

- 1423\. Maximum Points You Can Obtain from Cards
  - Prefix Sum

- 1545\. Find Kth Bit in Nth Binary String
  - divide and conquer

- 1647\. Minimum Deletions to Make Character Frequencies Unique
  - greedy

- 2414\. Length of the Longest Alphabetical Continuous Substring


