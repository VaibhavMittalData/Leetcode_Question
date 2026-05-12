class Solution {
public:
    bool isPalindrome(int x) {
       if(x<0)return false;
       int n = x;
       int reverse_number =0;
       while(n>0){
       int rem = n%10;
       if (reverse_number > 214748364 || (reverse_number == 214748364 && rem > 7)) return 0;
       if (reverse_number < -214748364 || (reverse_number == -214748364 && rem < -8)) return 0;
       reverse_number = reverse_number*10+rem; 
       n = n/10;
       }
       if(reverse_number==x)return true;
       return false;
    }
};