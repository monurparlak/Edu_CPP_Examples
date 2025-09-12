/*
Question #75
Source: CPP GeeksforGeeks

Question:
Write a C++ program to generate all unique subsets of a given set of integers.

My Answer:
✅ Output: For {1, 2, 3}, the subsets are:
(), (1), (1 2), (1 2 3), (1 3), (2), (2 3), (3)

Reason:
- A subset can either include or exclude each element.
- Using recursion (backtracking), we explore both possibilities:
  1. Exclude the current element.
  2. Include the current element.
- To avoid duplicates, we store subsets in a `set<vector<int>>`.
- Finally, we transfer them into a vector of vectors for ordered output.

If Wrong:
- Ensure recursive base condition `if (i >= n)` inserts the current subset.
- Confirm that `sort(arr.begin(), arr.end())` is done before recursion to maintain order.
- If duplicates appear, verify that `set<vector<int>>` is properly used.
*/

#include <bits/stdc++.h>
using namespace std;

// Recursive helper function
void solve(vector<int>& arr, int n, set<vector<int>>& ans,
           vector<int> v, int i)
{
    if (i >= n) {
        ans.insert(v); // store current subset
        return;
    }

    // Exclude current element
    solve(arr, n, ans, v, i + 1);

    // Include current element
    v.push_back(arr[i]);
    solve(arr, n, ans, v, i + 1);
}

// Generate all subsets
vector<vector<int>> AllSubsets(vector<int> arr, int n)
{
    set<vector<int>> ans;
    sort(arr.begin(), arr.end());
    vector<int> v;
    solve(arr, n, ans, v, 0);

    // Move set into vector
    vector<vector<int>> res;
    for (auto& subset : ans) {
        res.push_back(subset);
    }
    return res;
}

// Print subsets
void print(int N, vector<int>& A)
{
    vector<vector<int>> result = AllSubsets(A, N);

    for (int i = 0; i < result.size(); i++) {
        cout << '(';
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j < result[i].size() - 1)
                cout << " ";
        }
        cout << "), ";
    }
    cout << "\n";
}

int main()
{
    int N = 3;
    vector<int> A = {1, 2, 3};

    print(N, A);
    return 0;
}
