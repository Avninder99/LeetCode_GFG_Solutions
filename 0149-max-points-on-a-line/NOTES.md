struct hash_pair {
template <class T1, class T2>
size_t operator()(const pair<T1, T2>& p) const
{
auto hash1 = hash<T1>{}(p.first);
auto hash2 = hash<T2>{}(p.second);
​
if (hash1 != hash2) {
return hash1 ^ hash2;
}
​
// If hash1 == hash2, their XOR is zero.
return hash1;
}
};
class Solution {
public:
unordered_map<pair<double, double>, int, hash_pair>m1; // for all line except lines parallel to x-axis
unordered_map<pair<double, double>, int, hash_pair>m2; // for line parallel to x-axis
void processor(vector<int>&p1, vector<int>&p2){
double m,c;
bool snd=false;
if(p2[1] == p1[1]){
snd = true;
cout << p2[1] << " $ " << p1[1] << endl;
}