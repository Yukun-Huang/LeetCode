class Solution {
public:

    // _sortStringHash
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> m;
        int cnt = 0;
        for(string str : strs)
        {
            string str_cp = str;
            sort(str_cp.begin(), str_cp.end());
            if (m.count(str_cp)){
                res[m[str_cp]].push_back(str);
            }
            else{
                m[str_cp] = cnt++;
                res.push_back({str});
            }
        }
        return res;
    }

    // _freqStringHash
    vector<vector<string>> groupAnagrams_freqStringHash(vector<string>& strs) {
        vector<vector<string>> output;
        unordered_map<string, int> hm;
        int cnt = 0;
        int freq_arr[26];
        string spilt_char = "#";

        for (string str : strs){
            memset(freq_arr, 0, sizeof(freq_arr));
            for (char c : str){
                freq_arr[c-'a']++;
            }
            string key;
            for (int i=0; i<26; ++i){
                key += spilt_char + to_string(freq_arr[i]);
            }
            if (hm.find(key) == hm.end()){
                hm[key] = cnt++;
                // hm.insert(make_pair(key, cnt++));  too slow!
                output.push_back({str});
            }
            else{
                output[hm[key]].push_back(str);
            }
        }
        return output;
    }

    // _freqArrayHash 未完成
//    struct ArrayHashFunc
//    {
//        const int SEED = 13331;
//        size_t operator()(const int arr[26]) const
//        {
//            size_t ret = 17;
//            for (int i=0; i<26; ++i){
//                ret = SEED * ret + hash<int>()(arr[i]);
//            }
//            return ret;
//        }
//    };
//
//    vector<vector<string>> groupAnagrams_freqArrayHash(vector<string>& strs) {
//        vector<vector<string>> output;
//        unordered_map<int[26], int, ArrayHashFunc> hm;
//        int cnt = 0;
//        int freq_arr[26];
//        for (const string& str : strs){
//            memset(freq_arr, 0, sizeof(freq_arr));
//            for (char c : str){
//                freq_arr[c-'a']++;
//            }
//            if (hm.find(freq_arr) == hm.end()){
//                hm[freq_arr] = cnt++;
////                hm.insert(make_pair<int[26], int>(freq_arr, cnt++));
//                output.push_back({str});
//            }
//            else{
//                output[hm[freq_arr]].push_back(str);
//            }
//        }
//        return output;
//    }

};

