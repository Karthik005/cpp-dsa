#ifndef DSA_DS_HASHTABLE_H_
#define DSA_DS_HASHTABLE_H_

#include <tuple>
#include <vector>


template <class Key, class Val>
class HashTable{
    typedef unsigned uint;

    public:
      class HashFunction
      {
          public:
          typedef unsigned uint;
          virtual uint operator()(const Key &keyval) const = 0;
          virtual ~HashFunction(){};
      };

    private:
      std::vector<std::tuple<Key, Val>> *array_;
      const HashFunction *func_;
      uint size_;

    public:
      HashTable(const uint &size, const HashFunction &func) : func_{&func}, size_{size}, array_{new std::vector<std::tuple<Key, Val>>[size]} {}

      Val &operator[](const Key &key)
      {
          uint hash_val = (*func_)(key);
          cout << hash_val <<endl;
          for (auto &x : array_[hash_val])
          {
              if (get<0>(x) == key)
              {
                  return get<1>(x);
              }
          }

          std::tuple<Key, Val> new_tup;
          get<0>(new_tup) = key;
          std::vector<std::tuple<Key, Val>> &v_ref = array_[hash_val];
          v_ref.push_back(new_tup);
          return get<1>(v_ref[v_ref.size() - 1]); 
    }

    ~HashTable() {
        delete[] array_;
        delete func_;
    }
};

#endif // DSA_DS_HASHTABLE_H_
