#include "../../Utils/headers.hpp"
#include <unordered_set>

using namespace std;
typedef pair<int, int> int_pair;

struct node
{
    int ind;
    node *prev;
    node *next;
};

bool delete_node(node* &begin, node* &end, node *del_node)
{
    bool ret_val = (del_node->prev == nullptr);
    if (del_node->next != nullptr)
    {
        del_node->next->prev = del_node->prev;
    }
    else
    {
        end = del_node->prev;
    }
    if (del_node->prev != nullptr)
    {
        del_node->prev->next = del_node->next;
    }
    else
    {
        begin = del_node->next;
    }
    
    delete del_node;
    return ret_val;
}

void print_list(node * begin) {
    node * iter = begin;
    while (iter != nullptr) {
        iter = iter -> next;
    }
}

int_pair get_shortest_subarr(const vector<int> &to_search, const vector<int> &in_arr)
{
    int_pair ret_pair{-1, -1};
    unordered_map<int, node *> lmap;
    unordered_set<int> search_elems;
    node *begin, *end;
    begin = end = nullptr;
    for (const int &value : to_search)
    {
        search_elems.insert(value);
    }

    for (int i = 0; i < in_arr.size(); i++)
    {
        int cur_num = in_arr[i];
        bool is_begin = false;
        if (search_elems.find(cur_num) != search_elems.end())
        {
            if (lmap.find(cur_num) != lmap.end())
            {
                is_begin = delete_node(begin, end, lmap[cur_num]);
            }
            node * created =  new node{i, end, nullptr};
            if (end != nullptr)
            {
                end->next = created;
            }
            end = created;
            lmap[cur_num] = end;
            if (begin == nullptr)
            {
                begin = created;
                is_begin = true;
            }
            print_list(begin);
            if (search_elems.size() == lmap.size())
            {
                if (ret_pair.first < 0)
                {
                    ret_pair = int_pair{begin->ind, end->ind};
                }
                if (is_begin && (end->ind - begin->ind) < (ret_pair.second - ret_pair.first))
                {
                    ret_pair = int_pair{begin->ind, end->ind};
                }
            }
        }
    }

    while (end != nullptr) {
        node * temp = end;
        end = end->prev;
        delete temp;
    }

    return ret_pair;
}

int main() {
    vector<int> a{1, 5, 9}, b { 7, 5, 9, 0, 2, 1, 3, 1, 7, 9, 1, 1, 5, 8, 8, 9, 7 };
    print_pair<int,int>(get_shortest_subarr(a, b));
}
