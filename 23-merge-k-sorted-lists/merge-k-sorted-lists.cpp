/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>nums;
        for(int i =0;i<lists.size();i++){
            while(lists[i]!=NULL){
                nums.push_back(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }
        if(nums.empty()) return NULL;
        sort(nums.begin(),nums.end());
        ListNode *dummy = new ListNode(nums[0]);
        ListNode* curr = dummy;
        for(int i =1;i<nums.size();i++){
            curr->next  = new ListNode(nums[i]);
            curr = curr->next;
        }
        return dummy;
    }
};