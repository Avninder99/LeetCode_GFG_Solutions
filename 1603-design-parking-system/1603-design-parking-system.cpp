class ParkingSystem {
private:
    int arr[3] = {0,0,0};
public:
    ParkingSystem(int b, int m, int s) {
        arr[0]=b, arr[1]=m, arr[2]=s;
    }
    
    bool addCar(int ct) {
        if(arr[ct-1] > 0){
            arr[ct-1]--;
            return true;
        }
        return false;
    }
};