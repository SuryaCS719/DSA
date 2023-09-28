class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {

        int pickUpTimeM = 0, pickUpTimeP = 0, pickUpTimeG = 0;
        int travelTimeM = 0, travelTimeP = 0, travelTimeG = 0;
        int lastHouseM = 0, lastHouseP = 0, lastHouseG = 0;

        
        // Calculate pickup time and travel time
        for(int i=0; i < garbage.size(); i++){
            string current = garbage[i];

            for(auto ch: current){
            // for(int j=0; j < current.length(); j++){
            //     char ch = current[j];

                if(ch == 'M'){
                    pickUpTimeM++;
                    lastHouseM = i;
                }

                else if(ch == 'P'){
                    pickUpTimeP++;
                    lastHouseP = i;
                }

                else if(ch == 'G'){
                    pickUpTimeG++;
                    lastHouseG = i;
                }
            }
        }

        //calc travel time
        for(int i=0; i < lastHouseM; i++){
            travelTimeM += travel[i];
        }

        for(int i=0; i < lastHouseP; i++){
            travelTimeP += travel[i];
        }

        for(int i=0; i < lastHouseG; i++){
            travelTimeG += travel[i];
        }

        // To get the final answer:
        int totalTime = (pickUpTimeM + travelTimeM) + (pickUpTimeP + travelTimeP) + (pickUpTimeG + travelTimeG);

        return totalTime;
    }
};
