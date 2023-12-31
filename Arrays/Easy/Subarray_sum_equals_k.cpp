int subarraySum(vector<int> &nums, int k)
{
    int pre[nums.size()];
    pre[0] = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        pre[i] = nums[i] + pre[i - 1];
    }

    unordered_map<int, int> mp;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (pre[i] == k)
        {
            ans++;
        }
        if (mp.find(pre[i] - k) != mp.end())
        {
            ans += mp[pre[i] - k];
        }
        mp[pre[i]]++;
    }
    return ans;
}