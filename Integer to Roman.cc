const vector<int> num = {10, 5, 1};
class Solution {
public:
    string intToRoman(int num) {
        return Cal(num / 1000, {'M', 'M', 'M'}) + Cal(num / 100 % 10, {'M', 'D', 'C'}) +
            Cal(num / 10 % 10, {'C', 'L', 'X'}) + Cal(num % 10, {'X', 'V', 'I'});        
    }
private:
    string Cal(int val, vector<char> letter) {
        string res;
        if (val == 4 || val == 9) {
            res.push_back(letter[2]);
            val++;            
        }
        for (int i = 0; i < num.size(); i++)
            for (; val >= num[i]; val -= num[i])
                res.push_back(letter[i]);
        return res;
    }
};