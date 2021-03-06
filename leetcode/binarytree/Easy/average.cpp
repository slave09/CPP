/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>averages;
        
        queue<TreeNode*>q;
        stack<TreeNode*> stk;
        
        double firstAvg = root -> val;

        averages.push_back(firstAvg);
        q.push(root);
        
        do{
            double avg = 0.00;
            
            while(!q.empty()){
                TreeNode * node = q.front();
                if(node && node -> left) stk.push(node -> left);
                if(node && node -> right) stk.push(node -> right);
                q.pop();
            }

            if(st.empty()) return averages;
            
            double size = stk.size();
            
            while(!stk.empty()){
                TreeNode *top = stk.top();
                stk.pop();
                if(top){
                    avg += top -> val;
                    q.push(top);
                }
            }
            
            double avgVal = avg / size;
            averages.push_back(avgVal);
            
        }while(!q.empty());
        
        return averages;
        
    }
};

class Solution{
public:
  vector<double> averageOfLevels(TreeNode* root){
     if(!root) return {};

     queue<TreeNode*> queue;
     vector<double>averages;

     queue.push(root);

     while(!queue.empty()){

        double size = queue.size();

        double sum == 0.00;

        TreeNode *front = queue.front();

        for(int node = 0; node < size; ++node){
           
           TreeNode *front = queue.front();
           queue.pop();
           
           sum += front -> val;

           if(front -> left) queue.push(front -> left);
           if(front -> right) queue.push(front -> right);
       }

       averages.push(sum / size);
   }

   return averages;
}
};
