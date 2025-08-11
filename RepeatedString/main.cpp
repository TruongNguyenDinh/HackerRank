long repeatedString(string s, long n) {
    long ra = 0;
    for(auto x:s){
        if(x == 'a') ra+=1;
    }
    ra *= n/s.size();
    for(int i =0;i< n  - n/s.size() * s.size();i++){
        if(s[i]=='a') ra+=1;
    }
    return ra;
}