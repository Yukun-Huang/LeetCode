/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
二叉树的序列化与反序列化！记住最简单的实现方式是用递归的DFS！其它方法实现起来都很复杂！
*/

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> strs;
        _serialize(root, strs);
        // translate strs to res
        string res = "[";
        for (auto s : strs) res += s + ",";
        res.pop_back(), res += "]";
        return res;
    }
    
    void _serialize(TreeNode* root, vector<string>& strs) {
        if (!root){
            strs.push_back("null");
            return;
        }
        strs.push_back(to_string(root->val));
        _serialize(root->left, strs);
        _serialize(root->right, strs);
    }
    
    
    vector<string> split(const string &str, char delim) {
        vector<string> elems;
        istringstream iss(str);
        for (string item; getline(iss, item, delim); ){
            elems.push_back(item);
        }
        return elems;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> strs = split(data.substr(1, data.length()-2), ',');
        int idx = 0;
        return _deserialize(strs, idx);
    }
    
    TreeNode* _deserialize(vector<string>& strs, int& idx) {
        if (strs[idx] == "null"){
            idx++;
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(strs[idx++]));
        root->left = _deserialize(strs, idx);
        root->right = _deserialize(strs, idx);
        return root;
    }
};


// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));


//---------------------------------------- BFS待实现代码 ----------------------------------------//
// class Codec_BFS {
// public:
//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) {
//         if (!root) return "[null]";
//         queue<TreeNode*> q;
//         vector<string> res;
//         q.push(root);
//         while (!q.empty()){
//             TreeNode* tmp = q.front();
//             q.pop();
//             if (!tmp) {
//                 res.push_back("null");
//                 continue;
//             }
//             else
//                 res.push_back(to_string(tmp->val));

//             q.push(tmp->left), q.push(tmp->right);
//         }
//         // 去掉末尾的null
//         int idx = res.size();
//         while (res[--idx] == "null"){
//             res.pop_back();
//         }
//         // 格式化输出
//         string out = "[";
//         for (auto word : res)
//             out += word + ",";
//         out.pop_back();
//         return out + "]";
//     }
    
//     vector<string> split(const string &str, char delim, bool skip_empty) {
//         vector<string> elems;
//         istringstream iss(str);
//         for (string item; getline(iss, item, delim); ){
//             if (skip_empty && item == "null")
//                 continue;
//             else
//                 elems.push_back(item);
//         }
//         return elems;
//     }
    
//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {
//         vector<string> elems = split(data.substr(1, data.size()-2), ',', false);
//         if (elems[0] == "null") return NULL;
//         queue<TreeNode*> q;
//         TreeNode* head = createNode(elems[0]);
//         q.push(head);
//         int rootIndex = 0;
//         int valueIndex = 1;
//         while (rootIndex < q.size()){
//             string tmp = q.front();
//             q.pop();
            
//         }
//         while (rootIndex < q.size()) {
//             TreeNode* root = q.get(rootIndex++);
//             if (valueIndex < values.length){
//                 root.left = createNode(values[valueIndex++]);
//                 root.right = createNode(values[valueIndex++]);
//             }                
//             if (root.left != null)
//                 list.add(root.left);
//             if (root.right != null)
//                 list.add(root.right);
//         }
//         return head;
//     }
    
//     TreeNode* createNode(string str) {
//         if (str == "null")
//             return NULL;
//         else
//             return new TreeNode(stoi(elems[0]));
//     }
// };
