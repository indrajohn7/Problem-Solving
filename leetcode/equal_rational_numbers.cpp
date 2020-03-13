 #include<bits/stdc++.h>

 using namespace std;
 
 int get_num(char* str, int len) 
    {
        int num = 0;
        for (int i = 0; i < len; i++) {
            num = (num * 10) + (str[i] - '0');
        }
        return num;
    }
    
    int gcd(int x, int y) 
    {
         return (x != 0) ? gcd(y % x, x) : y;   
    }
    
    bool isRationalEqual(string S, string T) {
        int nemo1, nemo2;
        nemo1 = nemo2 = 0;
        char* str1 = (char*)S.c_str();
        char* str2 = (char*)T.c_str();
        char* first = str1;
		char* second = str2;
		int len1, len2;
		len1 = strlen(str1);
		len2 = strlen(str2);

        char* ptr1 = NULL;
        char* ptr2 = NULL;
        if ((ptr1 = (char*)strchr(str1, '.')) != NULL) {
            nemo1 = get_num(str1, ptr1 - str1);
        } else {
			nemo1 = atoi(str1);
		}
        if ((ptr2 = (char*)strchr(str2, '.')) != NULL) {
            nemo2 = get_num(str2, ptr2 - str2);
        } else {
			nemo2 = atoi(str2);
		}
        
        if (ptr1 != NULL)
            str1 = ptr1 + 1;
        else
            str1 = NULL;
        
        if (ptr2 != NULL)
            str2 = ptr2 + 1;
        else
            str2 = NULL;
        
        int dec1, dec2, rec_dec1, rec_dec2, dec1_len, dec2_len, rec1_len, rec2_len;
        dec1 = dec2 = rec_dec1 = rec_dec2 = 0;
        dec1_len = dec2_len = rec1_len  = rec2_len = 0;
        if (str1 != NULL && (ptr1 = (char*)strchr(str1, '(')) != NULL) {
            dec1 = get_num(str1, ptr1 - str1);
            dec1_len = ptr1 - str1;
        } else if (str1 != NULL) {
			dec1 = get_num(str1, (first + len1 - str1));
			dec1_len = first + len1 - str1;
		}
        if (str2 != NULL && (ptr2 = (char*)strchr(str2, '(')) != NULL) {
            dec2 = get_num(str2, ptr2 - str2);
            dec2_len = ptr2 - str2;
        } else if (str2 != NULL) {
		
			dec2 = get_num(str2, (second + len2 - str2));
			dec2_len = second + len2 - str2;
		}
        
		if (ptr1 != NULL)
            str1 = ptr1 + 1;
        else
            str1 = NULL;
        
        if (ptr2 != NULL)
            str2 = ptr2 + 1;
        else
            str2 = NULL;
        
        if (str1 != NULL && (ptr1 = strchr(str1, ')')) != NULL) {
            rec_dec1 = get_num(str1, ptr1 - str1);
            rec1_len = ptr1 - str1;
        }
        if (str2 != NULL && (ptr2 = strchr(str2, ')')) != NULL) {
            rec_dec2 = get_num(str2, ptr2 - str2);
            rec2_len = ptr2 - str2;
        }
        
        int num1, deno1, num2, deno2, deno91, deno92;
        num1 = num2 = deno1 = deno2 = 1;
        
		deno91 = deno92 = 1;
		if (rec1_len != 0) {
			deno91 = 0;
		}
		if (rec2_len != 0) {
			deno92 = 0;
		}

        for (int i = 0; i < rec1_len; i++) {
            deno91 = (deno91 * 10) + 9;
        }
        for (int i = 0; i < rec2_len; i++) {
            deno92 = (deno92 * 10) + 9;
        }
        num1 = (dec1 * deno91) + rec_dec1;
        num2 = (dec2 * deno92) + rec_dec2;
        deno1 = (deno91 * pow(10, dec1_len));
        deno2 = (deno92 * pow(10, dec2_len));
        
        int gcd1, gcd2;
        gcd1 = gcd2 = 1;
        gcd1 = gcd(num1, deno1);
        gcd2 = gcd(num2, deno2);
        
        if (gcd1 != 0) {
			num1 /= gcd1;
        	deno1 /= gcd1;
		}
		if (gcd2 != 0) {
        	num2 /= gcd2;
        	deno2 /= gcd2;
		}
        
        float fl1, fl2;
		fl1 = fl2 = 0;
		if (num1 != 0 || deno1 != 0 )
        	fl1 = float(float(num1) / float(deno1));
		if (num2 != 0 || deno2 != 0)
        	fl2 = float(float(num2) / float(deno2));
        
        if ((nemo1 + fl1) == (nemo2 + fl2)) {
            return true;
        }
        
        return false;
    }

int main()
{
	int T;
	ifstream fin;
	fin.open("numbers.in");
	fin >> T;

	for (int t= 0; t < T; t++) {
		string num1, num2;
		fin >> num1 >> num2;
		bool ret = isRationalEqual(num1, num2);
		if (ret)
			cout << "True" << endl;
		else
			cout << "False" << endl;
	}

	return 0;
}
