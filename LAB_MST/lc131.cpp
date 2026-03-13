class Solution {
public:

    bool isPalindrome(string s, int left, int right){
    while(left < right){
        if(s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
    }

    void backtrack(int start, string s, vector<string>& current,  <vector<vector<string>>& result){
    if(start == s.length()){
        result.push_back(current);
        return;
    }
    for(int end=start;end<s.length();end++){
        if(isPalidrome(s,start,end)){
            current.push_back(s.substr(start,end-start+1));
            backtrack(end+1,s,current,result);
            current.pop_back();
        }
    }
}

    vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> current;
    backtrack(0, s, current, result);
    return result;
    }
};
