class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        sort(asteroids.begin(), asteroids.end());
        long long currMass = mass;
        for(int asteroid : asteroids){
            if(currMass<asteroid){
                return false;
            }
            else{
                currMass+=asteroid;
            }


        }
        return true;
    }
};