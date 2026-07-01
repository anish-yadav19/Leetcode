/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void preorder(TreeNode* root,string &s){

        if(root==NULL){
            s+="N,";
            return;
        }

        s+=to_string(root->val)+",";

        preorder(root->left,s);
        preorder(root->right,s);
    }

    string serialize(TreeNode* root) {

        string s="";

        preorder(root,s);

        return s;
    }

    TreeNode* build(vector<string>&v,int &i){

        if(v[i]=="N"){
            i++;
            return NULL;
        }

        TreeNode* root=new TreeNode(stoi(v[i]));
        i++;

        root->left=build(v,i);
        root->right=build(v,i);

        return root;
    }

    TreeNode* deserialize(string data) {

        vector<string> v;
        string temp="";

        for(char c:data){

            if(c==','){
                v.push_back(temp);
                temp="";
            }
            else
                temp+=c;
        }

        int i=0;

        return build(v,i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));