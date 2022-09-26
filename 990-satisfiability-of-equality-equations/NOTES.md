vector<vector<int>>val (26, vector<int>{0,0});
int size = e.size(), counter=1;
for(int i=0;i<size;i++){
int f = (int)e[i][0] - (int)'a', s = (int)e[i][3] - (int)'a';
bool eq = ;
if(val[f][1] == 1){     // first alloted
if(val[s][1] == 1){   // second alloted
}else{  // second not alloted
val[ f ][0] = val[ (int)e[i][3] - (int)'a' ][0];
val[ f ][1] = 1;
}
}else{      // first not alloted
if(val[ s ][1] == 1){   // second alloted
val[ f ][0] = val[ (int)e[i][3] - (int)'a' ][0];
val[ f ][1] = 1;
}else{  // second not alloted
val[f][0] = counter;
val[s][0] = counter;
val[f][1] = 1;
val[s][1] = 1;
}
}
}