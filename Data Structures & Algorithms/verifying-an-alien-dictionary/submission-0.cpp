class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order)
    {
    map<char,int> mp;
    for(int i=0;i<order.size();i++){
        mp[order[i]]=i;
    }   
    int mi=words[0].size();  
    for(int i=0;i<words.size();i++){
        mi=min(mi,(int)words[i].size());
    }
    for(int i=0;i<words.size()-1;i++){
        int cnt=0;
        for(int j=0;j<min((int)words[i].size(),(int)words[i+1].size());j++){
          if(mp[words[i][j]]>mp[words[i+1][j]]){
            return false;
          }else  if(mp[words[i][j]]<mp[words[i+1][j]]){
            break;
          }else{
            cnt++;
          }
        }
        if(cnt==min(words[i].size(),words[i+1].size())){
            if(words[i].size()>words[i+1].size()){
              return false;
            }
        }
    }
    return true;
    }
};