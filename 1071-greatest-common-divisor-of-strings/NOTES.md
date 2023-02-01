if(s1[ptr1] != s2[ptr2]){
return "";
}
ptr1++;
ptr2 = (++ptr2) % l2;
}
return s2;
​
// what  if smallest string that devides s1 & s2 was asked
// IN PROGRESS (wrong answer)
// Now we know that both s1 and s2 can be made from same substring
if(l1 != l2 && l1 - l2 < l2){
s2 = s1.substr(l2, l1-l2);
}
cout << s2 << endl;
s2 += s2;
// doubled to be on safe side and check if end part of s2 is
// just repetition of substring or part of substring
l2 = s2.length();
// s2 is now in it's smallest form and must contain the substring in it
ptr2 = 1, tptr = 0;
string t1 = "", t2 = "";
t1 += s2[0];
while(ptr2 < l2){
if(s2[ptr2] == t1[tptr]){
tptr++;
t2 += s2[ptr2++];
}else{
t1 += t2;
if(tptr == 0){
t1 += s2[ptr2++];
}else{
tptr = 0;
}
}
}
return t1;
}
};