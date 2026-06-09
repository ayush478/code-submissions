class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0,r=heights.size()-1;
        int maxArea=0;
        while(l<r){
            int width=r-l;
            int height=min(heights[l],heights[r]);
            maxArea=max(maxArea,height*width);
            if(heights[l]<heights[r]){
                l++;
            }
            else r--;
        }   
        return maxArea;
    }
};
