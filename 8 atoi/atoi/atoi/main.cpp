#include <ctype.h>
#include <string>
#include <math.h>
#include <string>
#include <thread>
using namespace std;
int my_atio(string   str)
{
	const char * s = str.c_str();

	int64_t base = 0; 
	int sign = 1;

	int i = 0 ;
	while (s[i] == ' ') {
		i++;
	}
	if (s[i]=='+'|| s[i]=='-')
	{
		if (s[i]=='-')
		{
			sign = -1;
		}
		i++;

	}
	while (s[i] >= '0'&& s[i] <= '9')
	{
		if (base >2147483647 /10 ||((base == 2147483647 /10) && (s[i]>'7')))
		{
			if (sign==1)
			{
				return 2147483647;
			}
			else
			{
				return 2147483647;
			}
			
		}


		base = base * 10 + (s[i] - '0');


		i++;
	}

	return base * sign;



}

int main()
{
	const char * str = "-2147483647";


	int y = atoi(str);
	int t =  my_atio(str);
	return 0;
}