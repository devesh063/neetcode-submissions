class Solution {
public:

    string encode(vector<string>& strs) 
    {
        string encoded_string = "";
        for (const string& s : strs) {
            encoded_string += to_string(s.length()) + "#" + s;
        }
        return encoded_string;
    }

    vector<string> decode(string s) 
    {
        vector<string> aux;
        int i = 0;
        while (i < s.size()) {
            int hash_pos = s.find('#', i);
            int len = stoi(s.substr(i, hash_pos - i));
            aux.push_back(s.substr(hash_pos + 1, len));
            i = hash_pos + 1 + len;
        }
        return aux;
    }
};