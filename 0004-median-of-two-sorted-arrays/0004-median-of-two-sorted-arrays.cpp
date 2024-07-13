#include <algorithm>
double calc(vector<int>& resHolder) {
    int divisor = resHolder.size();
    double res = 0;
    for(auto itr: resHolder) {
        res += itr;
    }
    res /= divisor;
    return res;
}

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sizeN = nums1.size(), sizeM = nums2.size(), totalNum = sizeN + sizeM;
        bool isOdd = totalNum%2;
        vector<int>indexes, resHolder, indexesDup;
        if(isOdd) {
            indexes.push_back(totalNum/2);
        } else {
            indexes.push_back((totalNum-1)/2);
            indexes.push_back(totalNum/2);
        }
        indexesDup = indexes;
        
        // for(auto itr: indexes) {
        //     cout << itr << " ";
        // }
        // cout << endl;
        
        int l = 0, h = sizeN - 1, m, eleIndex, lbVal, ubVal; 
        for(auto itr: indexes) {
            // cout << "here" << endl;
            l = 0, h = sizeN - 1;
            while(l <= h) {
                m = l + (h - l)/2;
                eleIndex = m;
                auto lb = lower_bound(nums2.begin(), nums2.end(), nums1[m]);
                lbVal = lb == nums2.end() ? sizeM : lb - nums2.begin(); 
                auto ub = upper_bound(nums2.begin(), nums2.end(), nums1[m]);
                ubVal = ub == nums2.end() ? sizeM : ub - nums2.begin();
                // cout << lbVal << " = " << ubVal << endl;
                
                if(m + lbVal <= itr && m + ubVal >= itr) {
                    resHolder.push_back(nums1[m]);
                    indexes.erase(find(indexes.begin(), indexes.end(), itr));
                    break;
                } else if(m + lbVal > itr) {
                    // check left side
                    h = m - 1;
                } else {
                    // check right side
                    l = m + 1;
                }
            }
        }
        
        if(indexes.size() == 0) {
            // cout << "triggered" << endl;
            return calc(resHolder);
        }
        // cout << "============== " << indexes.size() << " =================="<< endl;
        for(auto itr: indexes) {
            l = 0, h = sizeM - 1;
            while(l <= h) {
                m = l + (h - l)/2;
                eleIndex = m;
                auto lb = lower_bound(nums1.begin(), nums1.end(), nums2[m]);
                lbVal = lb == nums1.end() ? sizeN : lb - nums1.begin(); 
                auto ub = upper_bound(nums1.begin(), nums1.end(), nums2[m]);
                ubVal = ub == nums1.end() ? sizeN : ub - nums1.begin();
                // cout << lbVal << " = " << ubVal << endl;
                
                if(m + lbVal <= itr && m + ubVal >= itr) {
                    resHolder.push_back(nums2[m]);
                    indexes.erase(find(indexes.begin(), indexes.end(), itr));
                    break;
                } else if(m + lbVal > itr) {
                    // check left side
                    h = m - 1;
                } else {
                    // check right side
                    l = m + 1;
                }
            }
        }
        
        if(indexes.size() == 0) {
            // cout << "triggered2" << endl;
            return calc(resHolder);
        }
        // cout << "+++++++++++++++++++" << endl;
        for(auto itr: resHolder) {
            cout << itr << endl;
        }
        return -100000001;
    }
};