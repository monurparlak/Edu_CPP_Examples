/*
================================================================================
HackerRank C++ Challenge: HRML Attribute Parser
================================================================================

Objective:
----------
- Learn how to parse a custom XML-like language (HRML) using C++.
- Retrieve attribute values from nested tags efficiently.

--------------------------------------------------------------------------------
Concepts Covered:
--------------------------------------------------------------------------------
1. Parsing strings with stringstream
2. Using vectors as a stack to track tag nesting
3. Using maps to store tag paths and attributes
4. Handling queries for nested tag attributes

--------------------------------------------------------------------------------
Input Format:
--------------------------------------------------------------------------------
- The first line contains two integers: N (number of HRML lines) and Q (number of queries)
- Next N lines contain HRML source code (opening or closing tags)
- Following Q lines contain queries in the form:
    tag1~attribute
    tag1.tag2~attribute

Example Input:
4 3
<tag1 value = "HelloWorld">
<tag2 name = "Name1">
</tag2>
</tag1>
tag1.tag2~name
tag1~name
tag1~value

Expected Output:
Name1
Not Found!
HelloWorld
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    cin.ignore(); // ignore the newline after integers

    map<string, string> attributes; // stores full path to attribute value
    vector<string> tag_path;        // keeps track of current tag nesting

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);

        if (line.substr(0, 2) == "</") {
            // closing tag, pop from path
            tag_path.pop_back();
        } else {
            // remove '<' and '>'
            line = line.substr(1, line.size() - 2);

            stringstream ss(line);
            string tag;
            ss >> tag; // get tag name

            // add current tag to path stack
            tag_path.push_back(tag);
            string prefix;
            for (int k = 0; k < (int)tag_path.size(); k++) {
                if (k) prefix += ".";
                prefix += tag_path[k];
            }

            // read attributes
            string attr, eq, val;
            while (ss >> attr >> eq >> val) {
                // remove quotes around value
                val = val.substr(1, val.size() - 2);
                attributes[prefix + "~" + attr] = val;
            }
        }
    }

    // answer queries
    for (int i = 0; i < q; i++) {
        string query;
        cin >> query;
        if (attributes.find(query) != attributes.end()) {
            cout << attributes[query] << endl;
        } else {
            cout << "Not Found!" << endl;
        }
    }

    return 0;
}

/*
================================================================================
Notes and Tips:
--------------------------------------------------------------------------------
1. Use vector<string> as a stack to keep track of the nested tag path.
2. Use map<string, string> to store full path keys with their attribute values.
3. stringstream helps parse both tag names and attributes easily.
4. Always handle quotes when reading attribute values.
5. This approach works for any depth of nested tags.
================================================================================
*/
