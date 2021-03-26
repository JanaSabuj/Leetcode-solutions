class Solution {
    int cnt = 0;
    unordered_map<string,string> mp;
    string base = "http://tinyurl.com/";
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shot = base + to_string(cnt++);
        mp[shot] = longUrl;
        return shot;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
