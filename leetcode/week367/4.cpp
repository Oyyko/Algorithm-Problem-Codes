#include "../base.hpp"

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
        if(n<indexDifference){
            vector<int> tmp;
            tmp.push_back(-1);
            tmp.push_back(-1);
            return tmp;
        }
        vector<int> leftLess(n, 0), rightMore(n, 0), leftLessIndex(n, 0), rightMoreIndex(n, 0),leftMoreIndex(n, 0), rightLessIndex(n, 0), leftMore(n, 0), rightLess(n, 0);
        int min_value = INT_MAX, min_index = 0, max_value = INT_MIN, max_index = 0;
        for(int i = 0; i<n; i++){
            if(min_value > nums[i]){
                min_value = nums[i];
                min_index = i;
            }
            if(max_value < nums[i]){
                max_value = nums[i];
                max_index = i;
            }
            leftLess[i] = min_value;
            leftMore[i] = max_value;
            leftLessIndex[i] = min_index;
            leftMoreIndex[i] = max_index;
        }
        // cout << "Left Less  ";
        // print_vec(leftLess);
        // cout << "left index ";
        // print_vec(leftLessIndex);
        min_index = n-1;
        max_index = n-1;
        min_value = INT_MAX;
        max_value = INT_MIN;
        for(int i = n - 1; i>-1; i--){
            if(min_value > nums[i]){
                min_value = nums[i];
                min_index = i;
            }
            if(max_value < nums[i]){
                max_value = nums[i];
                max_index = i;
            }
            rightMore[i] = max_value;
            rightLess[i] = min_value;
            rightLessIndex[i] = min_index;
            rightMoreIndex[i] = max_index;
        }
        
        for(int i = 0; i< n-indexDifference; i++){
            if(abs(leftLess[i]- rightMore[i+indexDifference]) >= valueDifference){
                vector<int> sxsxs;
                sxsxs.push_back(leftLessIndex[i]);
                sxsxs.push_back(rightMoreIndex[i+indexDifference]);
                return sxsxs;
            }
            if(abs(leftMore[i]- rightLess[i+indexDifference]) >= valueDifference){
                vector<int> asdsd;
                asdsd.push_back(leftMoreIndex[i]);
                asdsd.push_back(rightLessIndex[i+indexDifference]);
                return asdsd;
            }
        }
        vector<int> tmp;
        tmp.push_back(-1);
        tmp.push_back(-1);
        return tmp;
    }
};

int main() {}