/*
 * TwoSum.cpp
 *
 *  Created on: Apr 20, 2021
 *      Author: satish.vodapally
 */


/*
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * You can return the answer in any order.
 *
 * Example 1:
 *
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Output: Because nums[0] + nums[1] == 9, we return [0, 1].
 *
 * Example 2:
 *
 * Input: nums = [3,2,4], target = 6
 * Output: [1,2]
 *
 * Example 3:
 *
 * Input: nums = [3,3], target = 6
 * Output: [0,1]
 *
 * Constraints:
 * 2 <= nums.length <= 103
 * -109 <= nums[i] <= 109
 * -109 <= target <= 109
 * Only one valid answer exists.
 *
 */

#include <vector>
#include <map>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> res;
        vector<int>::iterator it, it1;
        map<int, int> my_map;

        //Insert the array element and its index into map
        for(it = nums.begin(); it != nums.end(); it++)
        {
        	cout << *it << " - " <<(it - nums.begin()) << endl;
            my_map.insert(pair<int, int>(*it, (it-nums.begin())) );
        }

        for(it = nums.begin(); it != nums.end(); it++)
        {
            int complement = target - *it;
            cout << "Complement " << complement << endl;

            //check for complement correctness
           if((complement < 0) || (complement > target))
            {
                continue;
            }

            map<int, int>::iterator mit;
            mit = my_map.find(complement);

            if(mit != my_map.end() && (mit->second != (it-nums.begin())))
            {
                cout << "Result res [ " << (it-nums.begin()) << ", " << mit->second << "]" << endl;
                res.push_back(it-nums.begin());
                res.push_back(mit->second);
                break;
            }
        }
        return res;
    }
};


int main(void)
{
	vector<int> result;
	vector<int> nums = {2, 11, 7, 15};
	int tgt = 26;

	vector<int> nums2 = {3, 2, 4};
    int tgt2 = 7;

	vector<int> nums3 = {3, 3};
    int tgt3 = 6;
    
    Solution sol;

	result = sol.twoSum(nums, tgt);
    cout << "------------------" << endl;
    result = sol.twoSum(nums2, tgt2);
    cout << "------------------" << endl;
    result = sol.twoSum(nums3, tgt3);

	return 0;

}
