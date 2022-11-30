## C++filesystem and regex overview

```c++
#include <iostream>
#include<filesystem>
#include<regex>
int main() {
    using namespace std::filesystem;
    using namespace std;
    auto pics=path("C:\\Users\\jhc\\Downloads");
    auto pa=current_path();
    cout<<pa.filename()<<endl;
    if(!exists(pics))
        return 1;
    directory_entry aim_entry(pics);
    regex before("^v2-.*");
    if(aim_entry.status().type()==file_type::directory){
        directory_iterator list(pics);
        int index=1;
        for(auto i: list){
        if(i.status().type()==file_type::regular){
                cout<<"yes"<<endl;
                if(regex_match(i.path().filename().string(),before)){
//                    string name("p");
//                    name.append(to_string(index)+".jpg");
//                    auto father=pics;
//                    index++;
//                    rename(i.path(),father/=name);
                }
            }
        }
    }
    return 0;
}
```

### 标准库给的regex范例特别好

```c++
#include <iostream>
#include <iterator>
#include <string>
#include <regex>
int main()
{
    std::string s = "Some people, when confronted with a problem, think "
                    "\"I know, I'll use regular expressions.\" "
                    "Now they have two problems.";

    std::regex self_regex("REGULAR EXPRESSIONS",
                          std::regex_constants::ECMAScript | std::regex_constants::icase);
    if (std::regex_search(s, self_regex)) {
        std::cout << "Text contains the phrase 'regular expressions'\n";
    }

    std::regex word_regex("(\\w+)");
    auto words_begin =
            std::sregex_iterator(s.begin(), s.end(), word_regex);
    auto words_end = std::sregex_iterator();

    std::cout << "Found "
              << std::distance(words_begin, words_end)
              << " words\n";

    const int N = 6;
    std::cout << "Words longer than " << N << " characters:\n";
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        std::string match_str = match.str();
        if (match_str.size() > N) {
            std::cout << "  " << match_str << '\n';
        }
    }

    std::regex long_word_regex("(\\w{7,})");
    std::string new_s = std::regex_replace(s, long_word_regex, "[$&]");
    std::cout << new_s << '\n';
}
```

