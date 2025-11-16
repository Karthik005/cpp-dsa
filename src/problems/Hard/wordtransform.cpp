vector<string> generate_patterns(const string &str)
{
    vector<string> patterns;
    patterns.reserve(str.length());
    for (int i = 0; i < str.length(); ++i)
    {

        string cur_pattern;
        cur_pattern += str.substr(0, i);
        cur_pattern += '_';
        cur_pattern += str.substr(i + 1, str.length() - 1 - i);
        pattern.push_back(cur_pattern);
    }
    return patterns;
}

unordered_map<string, set<string>> generate_pattern_map(const vector<string> &
                                                            dict,
                                                        int length)
{
    unordered_map<string, set<string>> pattern_map;
    for (const string &str : dict)
    {
        if (str.length() == length)
        {
            vector<string> patterns = generate_patterns(str);
            for (const string &pat : patterns)
            {
                pattern_map[pat].insert(str);
            }
        }
    }

    return pattern_map;
}

void get_transformer(const string &start, const string &end, list &trans_list, set<string> &seen_strings, const unordered_map < string, set<string> &pattern_map)
{

    if (start == end)
    {
        trans_list.push_back(end);
        return;
    }
    if (seen_strings.find(start) != seen_strings.end())
    {
        return;
    }

    trans_list.push_back(start);
    int lst_size = trans_list.size();

    vector<string> pats = generate_patterns(start, freeze_pos);
    for (const string &pattern : pats)
    {
        for (const string &str : pattern_map[pattern])
        {
            get_transformer(str, end, trans_list, seen_strings, pattern_map);
            if (list.back() == end)
            {
                return;
            }
        }
    }
    trans_list.pop_back();
    return;
}
