class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0) return true;
        int last = -1;
        for(int i = 0; i < flowerbed.size(); ++i){
            if(flowerbed[i] == 1){
                if(i == flowerbed.size()-1) return n == 0;
                i++;
                last = flowerbed[i];
            }
            else{
                if(i == flowerbed.size() - 1 && last == -1) return --n == 0;
                if(i == flowerbed.size() - 1 && last == 0) return --n == 0;
                if(last == 0 && flowerbed[i+1] == 0 || last == -1 && flowerbed[i+1] == 0) flowerbed[i]++, n--;
                if(n == 0) return true;
                last = flowerbed[i];
            }
        }
        return n == 0;
    }
};