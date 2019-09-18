// 38. Count and Say

class Solution {
public:
    string countAndSay(int n) {
        string str="1",temp="";
        if(n==1) return str;
        n--;
        int cnt=0,i=0;
        while(n--) {
            temp="";
            cnt=0;
            for(i=0;i<str.size()-1;i++) {
                if(str[i]==str[i+1]) {
                    cnt++;
                } else {
                    cnt++;
                    temp=temp+to_string(cnt)+str[i];
                    cnt=0;
                }
            }
            cnt++;
            if(i==str.size()-1) {
                temp=temp+to_string(cnt)+str[str.size()-1];
            }
            str=temp;
        }
        return str;
    }
};
