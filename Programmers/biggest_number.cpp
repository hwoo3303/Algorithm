#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// ex) "9 + 90" > "90" + "9" ? true : false 
bool compare(string str1, string str2){
    return str1 + str2 > str2 + str1 ? true : false;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strNum;
    
    // string compare를 위한 to_string
    for(int i = 0; i < numbers.size(); i++){
        string tempStr = to_string(numbers[i]);
        strNum.push_back(tempStr);
    }
    
    // string sort
    sort(strNum.begin(), strNum.end(), compare);
    
    // 입력 데이터가 "0" 한 개만 있을 경우
    if(strNum[0] == "0"){
        return "0";
    }
    
    for(int i = 0; i < numbers.size(); i++){
        answer += strNum[i];
    }
    
    return answer;
}
