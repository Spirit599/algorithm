int balancedStringSplit(char * s){

	int i = 0;
	int L_num = 0;
	int R_num = 0;
	int ret = 0;
	int str_len = strlen(s);
	while(i < str_len)
	{
		//printf("%d\n", i);
		if(s[i] == 'L')
			L_num++;
		else if(s[i] == 'R')
			R_num++;

		if(L_num == R_num)
			ret++;

		i++;
	}

	 return ret;
}