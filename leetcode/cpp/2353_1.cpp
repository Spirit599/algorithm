class FoodRatings {
public:
	struct rating_name
	{
		int rating;
		string name;
	};
	struct info
	{
		int rating;
		string cuisine;
	};
	struct cmp
	{
		bool operator() (const rating_name& p1, const rating_name& p2) const
		{
			if(p1.rating != p2.rating)
				return p1.rating > p2.rating;
			else
				return p1.name < p2.name;
		}
	};
	unordered_map<string, info> old_rating;
	unordered_map<string, set<rating_name, cmp>> memo;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {

    	int n = foods.size();
    	for(int i = 0; i < n; ++i)
    	{
    		memo[cuisines[i]].insert({ratings[i], foods[i]});
    		old_rating[foods[i]] = {ratings[i], cuisines[i]};
    	}
    }
    
    void changeRating(string food, int newRating) {

    	auto it = old_rating.find(food);
    	memo[it->second.cuisine].erase({it->second.rating, food});
    	memo[it->second.cuisine].insert({newRating, food});
    	it->second.rating = newRating;


    }
    
    string highestRated(string cuisine) {

    	return (memo[cuisine].begin())->name;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */