# Sliding Window

## Tip

[Here is a 10-line template that can solve most 'substring' problems](https://leetcode.com/problems/minimum-window-substring/discuss/26808/here-is-a-10-line-template-that-can-solve-most-substring-problems)

Template:
```cpp
int findSubstring(string s){
    vector<int> map(128,0);
    int counter; // check whether the substring is valid
    int begin=0, end=0; //two pointers, one point to tail and one  head
    int d; //the length of substring

    for() {
        /* initialize the hash map here */ 
    }

    while(end<s.size()) {
        if(map[s[end++]]-- /* ? */) {
            /* modify counter here */
        }
        while(/* counter condition */) { 
            /* update d here if finding minimum*/
            /* increase begin to make it invalid/valid again */
            if(map[s[begin++]]++ /* ? */) {
                /*modify counter here*/
            }
        }  
        /* update d here if finding maximum*/
    }
    return d;
}
```

When finding minimum, the counter condition should be `true` for **valid** window.

When finding maximum, the counter condition should be `true` for **invalid** window.

## Problems

Find Minimum
* [76. Minimum Window Substring (Hard)](https://leetcode.com/problems/minimum-window-substring/)

Find Maximum
* [159. Longest Substring with At Most Two Distinct Characters (Hard)](https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/)