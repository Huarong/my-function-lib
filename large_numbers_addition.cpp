//Add two positive large numbers.
//The low-order number starts from the beginning of the vector.
vector<int> large_num_add(vector<int> &vec1, vector<int> &vec2)
{
    vector<int> vec_added;
    vector<int> &vec_long = vec1.size() >= vec2.size() ? vec1 : vec2;
    vector<int> &vec_short = vec1.size() >= vec2.size() ? vec2 : vec1;
    for (size_t i = 0; i != vec_short.size(); ++i)
    {
        vec_added.push_back(vec_short[i] + vec_long[i]);
    }
    vec_added.insert(vec_added.end(), vec_long.begin() + vec_short.size(), vec_long.end());
    for (vector<int>::iterator iter = vec_added.begin(); iter != vec_added.end() - 1; ++iter)
    {
        if (*iter > 9)
        {
            *(iter + 1) += *iter / 10;
            *iter = *iter % 10;
        }
    }
    if (vec_added.back() > 9)
    {
        vec_added.push_back(vec_added.back() / 10);
        *(vec_added.end() - 2) = *(vec_added.end() - 2) % 10;
    }
    return vec_added;
}
