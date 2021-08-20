package leecode;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

/*
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 
target  的那 两个 整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
你可以按任意顺序返回答案。
来源：力扣（LeetCode）
*/

/*
在计算机科学中，时间复杂性，又称时间复杂度，算法的时间复杂度是一个函数，
它定性描述该算法的运行时间。这是一个代表算法输入值的字符串的长度的函数。
时间复杂度常用大O符号表述，不包括这个函数的低阶项和首项系数。使用这种方式时，
时间复杂度可被称为是渐近的，亦即考察输入值大小趋近无穷时的情况。
 */

//三种解法 ：
// 1.暴力双重遍历,O(n²),61ms
class Solution1 {
    public int[] twoSum(int[] nums, int target) {
        for(int i=0;i<nums.length-1;i++)
            for(int j=i+1;j<nums.length;j++)
                if(nums[i]+nums[j]==target)
                    return new int[] {i,j};
        return new int[] {};
    }
}

//2.排序,然后转换为缩小窗口的问题,O(nlogn),4ms
class Solution2 {
    public int[] twoSum(int[] nums, int target) {
        int[]nums2= Arrays.copyOf(nums,nums.length);
        Arrays.sort(nums);
        int i=0,j=nums.length-1;
        while(nums[i]+nums[j]!=target) {
            if(nums[i]+nums[j]<target)
                i++;
            else if(nums[i]+nums[j]>target)
                j--;
        }
        int r1=0,r2=0;
        for(int k=0;k<nums2.length;k++)
            if(nums2[k]==nums[i]) {
                r1=k;
                break;
            }
        for(int k=nums2.length-1;k>=0;k--)
            if(nums2[k]==nums[j]) {
                r2=k;
                break;
            }
        return new int[] {r1,r2};
    }
}

//3.哈希表存储访问过的元素,每访问一次,判断哈希表是否有与其匹配的存储,O(n),2ms
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer>map=new HashMap<>();//元素值和元素位置的映射
        map.put(nums[0], 0);
        for(int i=1;i<nums.length;i++) {
            int matchedNum=target-nums[i];//nums[i]和matchedNum的索引即为所求
            if(map.containsKey(matchedNum)) {//map存储过matchedNum的映射
                int index1=i;
                int index2=map.get(matchedNum);
                return new int[] {index1,index2};
            }else//map未存储过
                map.put(nums[i], i);
        }

        return null;
    }
}

//4.O(n)1.7ms
class Solution4 {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer> map = new HashMap<>();
        for(int i = 0; i < nums.length; i++){
            if(map.containsKey(nums[i])){
                return new int[]{map.get(nums[i]), i};
            }
            map.put(target - nums[i], i);
        }
        return null;
    }
}