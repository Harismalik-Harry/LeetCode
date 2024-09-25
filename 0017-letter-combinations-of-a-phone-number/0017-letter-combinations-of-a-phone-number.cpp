class Solution {
public:
string a(char a)
{
    if(a=='2')
    {
        return "abc";
    }
     if(a=='3')
    {
        return "def";
    }
     if(a=='4')
    {
        return "ghi";
    }
     if(a=='5')
    {
        return "jkl";
    }
     if(a=='6')
    {
        return "mno";
    }
     if(a=='7')
    {
        return "pqrs";
    }
     if(a=='8')
    {
        return "tuv";
    }
     if(a=='9')
    {
        return "wxyz";
    }
return "";
}
void calculate(string &str,string &subset,int index, vector<string> &arr,string digit)
{
    if(subset.size()==digit.length())
    {
        arr.push_back(subset);
        return;
    }
    string no=a(digit[index]);
for(int i=0;i<no.length();i++)
{
    subset.push_back(no[i]);
    calculate(str,subset,index+1,arr,digit);
    subset.pop_back();
}
}
    vector<string> letterCombinations(string digits) {
         string sample="";
        // for(int i=0;i<digits.length();i++)
        // {
        //     sample=sample+a(digits[i]);
        // }
        if(digits.length()==0)
        {
            return {};
        }
        vector<string> arr;
        string subset;
        calculate(sample,subset,0,arr,digits);
        return arr;

    }
};