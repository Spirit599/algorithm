int chalkReplacer(int* chalk, int chalkSize, int k){

	long long sum = 0;
	for (int i = 0; i < chalkSize; ++i)
	{
		sum = sum + chalk[i];
	}

	long long remain = k % sum;

	int i = 0;
	while(remain >= chalk[i])
	{
		remain = remain - chalk[i];
		i++;
		i = i % chalkSize;
	}

	return i;

}


