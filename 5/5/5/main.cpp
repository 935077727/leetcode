#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <istream>
#include <sstream>
#include <assert.h>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		vector<string> vecPal;
		int index = 0;
		string checkStr;
		bool isPal = true;
		int maxlen = s.length();
		for (size_t i = 0; i <maxlen; i++)
		{
			index = maxlen;
			int j = 1;
			while (index<= maxlen&&index!=-1)
			{
				index = s.rfind(s[i],index-1 );
				if (index>=0)
				{
					checkStr = s.substr(i, index-i+1);
					isPal = true;
					int begin = 0, end = checkStr.length() - 1;
					while (begin < end) {
						if (checkStr[begin] == checkStr[end]) {
							begin++;
							end--;
						}
						else {
							isPal = false;
							break;
						}
					}
					if (isPal == true)
					{
						vecPal.push_back(checkStr);
					}
				}
				if (isPal==true)
				{
					isPal = false;
					break;
				}
				
			}
			
		}
		string stt;
		int maxLen=0;
		for (string st : vecPal)
		{
			if (st.length()>maxLen)
			{
				maxLen = st.length();
				stt = st;
			}
		}
		return stt;
	}
};

string stringToString(string input) {
	assert(input.length() >= 2);
	string result;
	for (int i = 1; i < input.length() - 1; i++) {
		char currentChar = input[i];
		if (input[i] == '\\') {
			char nextChar = input[i + 1];
			switch (nextChar) {
			case '\"': result.push_back('\"'); break;
			case '/': result.push_back('/'); break;
			case '\\': result.push_back('\\'); break;
			case 'b': result.push_back('\b'); break;
			case 'f': result.push_back('\f'); break;
			case 'r': result.push_back('\r'); break;
			case 'n': result.push_back('\n'); break;
			case 't': result.push_back('\t'); break;
			default: break;
			}
			i++;
		}
		else {
			result.push_back(currentChar);
		}
	}
	return result;
}

int main() {
	//string line;
	//while (getline(cin, line)) {
	string s = "nmngaowrbsssvihklwmuqshcddwlxrywrlwtennwfvrevgvhsvgeccfulmuvrcksdmgeqrblnlwoepefhcwhmgyvgcoyyygrmttyfycxwbqktpurlcfhzlakhmrddsydgygganpmaglaxyhfwjusukzcnakznygqplngnkhcowavxoiwrfycxwdkxqfcjqwyqutcpyedbnuogedwobsktgioqdczxhikjrbkmqspnxcpngfdwdaboscqbkwforihzqdcppxjksiujfvlpdjryewaxgmdgigvxdlstxwngtbdrrkfudjinzyxbdmkautclvvyguekuzwwetmsxittgtxbnvvrgasvnlogdiepltweaehubwelznidltzlbzdsrxmhjpkmylnwkdsxnpkplkdzywioluaqguowtbaoqzqgjfewphqcvlnwlojbxgomvxxkhwwykawegxubjiobizicuxzeafgautefsurgjlbhcfevqzsbhwxycrcaibdsgluczcuewzqupakbzmcvzsfodbmgtugnihyhqkvyeboqhqldifbxuaxqzxtyejoswikbzpsvzkxcndgeyvfnyrfbkhlalzpqjueibnodamgpnxlkvwvliouvejcpnakllfxepldfmdzszagkyhdgqqbkb";
		string ret = Solution().longestPalindrome(s);

		string out = (ret);
		cout << out << endl;
	//}
	return 0;
}