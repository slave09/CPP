class Solution {
public:
	vector<string> commonChars(vector<string>& A) {
		
		vector<string> common_str;
		vector<int> frequency_lookup(26, INT_MAX);

		for(auto &str : A){
			vector<int>character_count(26, 0);
			for(auto s : str) character_count[s - 'a']++;

			for(int i = 0; i < 26; ++i)
				frequency_lookup[i] = min(frequency_lookup[i], character_count[i]);
		}

		for(int i = 0; i < 26; ++i){
			for(int j = 0; j < character_count[i]; ++j)
				common_str.push_back(string(1,i + 'a'));
		}

		return common_str;
	}
};